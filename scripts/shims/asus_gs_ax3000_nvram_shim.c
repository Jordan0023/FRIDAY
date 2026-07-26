/*
 * Minimal NVRAM shim for isolated GS-AX3000 ARM component emulation.
 * Values are selected at compile time so the shim has no host dependencies.
 */

struct nvpair {
    const char *name;
    const char *value;
};

extern int open(const char *path, int flags, ...);
extern int close(int fd);
extern int write(int fd, const void *buffer, unsigned count);

static unsigned text_length(const char *text)
{
    unsigned length = 0;
    if (!text)
        return 0;
    while (text[length])
        length++;
    return length;
}

static void log_set(const char *name, const char *value)
{
    /* O_WRONLY | O_CREAT | O_APPEND, mode 0600 */
    int fd = open("/tmp/gsax3000-nvram-set.log", 1 | 64 | 1024, 0600);
    if (fd < 0)
        return;
    write(fd, name, text_length(name));
    write(fd, "=", 1);
    write(fd, value, text_length(value));
    write(fd, "\n", 1);
    close(fd);
}

static int streq(const char *left, const char *right)
{
    if (!left || !right)
        return 0;
    while (*left && *left == *right) {
        left++;
        right++;
    }
    return *left == *right;
}

static char upload_server_ovpn_cert_temp[16] = "";

static const struct nvpair defaults[] = {
    {"productid", "GS-AX3000"},
    {"odmpid", "ROG STRIX GS-AX3000"},
    {"firmver", "3.0.0.4"},
    {"buildno", "388"},
    {"extendno", "23169"},
    {"lan_ifname", "lo"},
    {"lan_ifnames", "lo"},
    {"lan_ipaddr", "127.0.0.1"},
    {"lan_netmask", "255.0.0.0"},
    {"lan_hwaddr", "02:46:52:49:44:41"},
    {"et0macaddr", "02:46:52:49:44:41"},
    {"http_lanport", "28080"},
    {"http_enable", "0"},
    {"https_lanport", "28443"},
#ifdef GSAX_CONFIGURED
    {"x_Setting", "1"},
#else
    {"x_Setting", "0"},
#endif
    {"p_Setting", "0"},
    {"sw_mode", "1"},
    {"w_Setting", "0"},
    {"restore_defaults", "1"},
    {"login_ip", "0"},
    {"preferred_lang", "EN"},
    {"territory_code", "US/01"},
    {"secret_code", "12345670"},
    {"wl0_ssid", "ASUS_FRIDAY_2G"},
    {"wl1_ssid", "ASUS_FRIDAY_5G"},
    {"wl0_auth_mode_x", "open"},
    {"wl1_auth_mode_x", "open"},
    {"ipv6_service", "disabled"},
    {"ateCommand_flag", "0"},
    {0, 0},
};

char *nvram_get(const char *name)
{
    const struct nvpair *item = defaults;
    if (streq(name, "upload_server_ovpn_cert_temp"))
        return upload_server_ovpn_cert_temp;
    while (item->name) {
        if (streq(name, item->name))
            return (char *)item->value;
        item++;
    }
    return "";
}

char *nvram_safe_get(const char *name) { return nvram_get(name); }
char *nvram_default_get(const char *name) { return nvram_get(name); }

int nvram_get_int(const char *name)
{
    const char *value = nvram_get(name);
    int result = 0;
    int negative = 0;
    if (*value == '-') {
        negative = 1;
        value++;
    }
    while (*value >= '0' && *value <= '9') {
        result = result * 10 + (*value - '0');
        value++;
    }
    return negative ? -result : result;
}

int nvram_set(const char *name, const char *value)
{
    if (streq(name, "upload_server_ovpn_cert_temp")) {
        unsigned index = 0;
        while (value && value[index] &&
               index + 1 < sizeof(upload_server_ovpn_cert_temp)) {
            upload_server_ovpn_cert_temp[index] = value[index];
            index++;
        }
        upload_server_ovpn_cert_temp[index] = '\0';
    }
    log_set(name, value);
    return 0;
}

int nvram_set_int(const char *name, int value)
{
    char digits[16];
    unsigned index = sizeof(digits);
    unsigned number = value < 0 ? (unsigned)-value : (unsigned)value;
    digits[--index] = '\0';
    do {
        digits[--index] = '0' + number % 10;
        number /= 10;
    } while (number && index);
    if (value < 0 && index)
        digits[--index] = '-';
    log_set(name, digits + index);
    (void)value;
    return 0;
}

int nvram_unset(const char *name)
{
    if (streq(name, "upload_server_ovpn_cert_temp"))
        upload_server_ovpn_cert_temp[0] = '\0';
    log_set(name, "<UNSET>");
    return 0;
}

int nvram_commit(void) { return 0; }
int nvram_init(void) { return 0; }

int nvram_match(const char *name, const char *match)
{
    return streq(nvram_get(name), match);
}

int nvram_invmatch(const char *name, const char *match)
{
    return !nvram_match(name, match);
}

int nvram_getall(char *buf, int count)
{
    if (buf && count > 0)
        *buf = '\0';
    return 0;
}
