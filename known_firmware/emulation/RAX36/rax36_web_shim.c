/*
 * Configuration-only substitutions for the isolated RAX36 web lab.
 * Request parsing, authentication, dispatch, and sinks remain in net-cgi.
 */
static int same(const char *a, const char *b)
{
    if (!a || !b) return 0;
    while (*a && *a == *b) {
        ++a;
        ++b;
    }
    return *a == *b;
}

char *config_get(const char *name)
{
    static char empty[] = "";
    static char zero[] = "0";
    static char one[] = "1";
    static char admin[] = "admin";
    static char password[] = "FRIDAY-LAB-NOT-A-REAL-PASSWORD";
    static char answer1[] = "friday-answer-one";
    static char answer2[] = "friday-answer-two";
    static char question1[] = "1";
    static char question2[] = "2";
    static char lan_ifname[] = "br0";
    static char lan_ipaddr[] = "10.0.2.15";
    static char lan_netmask[] = "255.255.255.0";

    if (same(name, "http_loginname")) return admin;
    if (same(name, "http_passwd")) return password;
    if (same(name, "lan_ifname")) return lan_ifname;
    if (same(name, "lan_ipaddr")) return lan_ipaddr;
    if (same(name, "lan_netmask")) return lan_netmask;
    if (same(name, "config_state")) return one;
    if (same(name, "enable_password_recovery")) return one;
    if (same(name, "security_answer1")) return answer1;
    if (same(name, "security_answer2")) return answer2;
    if (same(name, "PWD_question1")) return question1;
    if (same(name, "PWD_question2")) return question2;
    if (same(name, "PWD_answer1")) return answer1;
    if (same(name, "PWD_answer2")) return answer2;
    if (same(name, "endis_remote")) return zero;
    if (same(name, "factory_mode")) return zero;
    if (same(name, "https_enable")) return zero;
    if (same(name, "remote_mg_enable")) return zero;
    return empty;
}

int config_match(const char *name, const char *value)
{
    return same(config_get(name), value);
}

int config_invmatch(const char *name, const char *value)
{
    return !config_match(name, value);
}

int config_set(const char *name, const char *value)
{
    (void)name;
    (void)value;
    return 0;
}

int config_unset(const char *name)
{
    (void)name;
    return 0;
}

int config_commit(void)
{
    return 0;
}

unsigned int bcmImg_getRealConfigFlashSize(void)
{
    return 128U * 1024U;
}

unsigned int bcmImg_getConfigFlashSize(void)
{
    return bcmImg_getRealConfigFlashSize();
}

/*
 * lighttpd opens NETGEAR's encrypted configuration partition before serving.
 * The disposable lab has no flash device, so acknowledge only that storage
 * lifecycle. net-cgi's request parsing, authentication, and dispatch remain
 * the firmware implementations.
 */
int ntgrcrypt_open(void)
{
    return 0;
}

int ntgrcrypt_close(void)
{
    return 0;
}
