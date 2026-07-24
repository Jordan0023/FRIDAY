/*
 * Guest-side reproduction of rcl_ippCfgObject's CMS_MSG_START_APP request.
 * The request is addressed to SMD (EID 20); wordData selects IPPD (EID 45),
 * and the body carries the optional launch argument.
 */
typedef unsigned int u32;

extern int cmsMsg_initWithFlags(u32 eid, u32 flags, void **handle);
extern int cmsMsg_send(void *handle, const void *message);
extern void cmsMsg_cleanup(void **handle);

struct cms_message {
    u32 type;
    u32 src;
    u32 dst;
    u32 flags_and_sequence;
    u32 sequence;
    u32 next;
    u32 word_data;
    u32 data_length;
    char data[32];
};

static struct cms_message message;
static void *handle;
static const char config_path[] = "/var/printers.ini";

static void copy_path(char *destination)
{
    unsigned int index;
    for (index = 0; index < sizeof(config_path); index++)
        destination[index] = config_path[index];
}

void _start(void)
{
    int result;

    result = cmsMsg_initWithFlags(20, 0, &handle);
    if (result == 0) {
        message.type = 0x10000809;
        message.src = 20;
        message.dst = 20;
        message.flags_and_sequence = 2; /* request */
        message.word_data = 45;
        message.data_length = sizeof(config_path);
        copy_path(message.data);
        result = cmsMsg_send(handle, &message);
        cmsMsg_cleanup(&handle);
    }

    __asm__ volatile(
        "mov r7, #1\n"
        "mov r0, %0\n"
        "svc #0\n"
        :
        : "r" (result)
        : "r0", "r7", "memory"
    );
    __builtin_unreachable();
}
