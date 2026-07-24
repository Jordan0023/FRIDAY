/*
 * Narrow hardware substitutions for the isolated BE17000 full-system web lab.
 * Request parsing, authentication, CGI dispatch, and process execution remain
 * in the original firmware binaries.
 */
unsigned int bcmImg_getRealConfigFlashSize(void)
{
    return 128U * 1024U;
}

unsigned int bcmImg_getConfigFlashSize(void)
{
    return bcmImg_getRealConfigFlashSize();
}

static int shim_streq(const char *left, const char *right)
{
    if (left == 0 || right == 0) {
        return 0;
    }
    while (*left != '\0' && *left == *right) {
        ++left;
        ++right;
    }
    return *left == *right;
}

/*
 * The firmware archive does not contain the router's writable datalib/MTD
 * configuration partition. Model a configured router with remote management
 * disabled. The real net-cgi still performs its normal URI/authentication
 * checks using these values.
 */
char *config_get(const char *name)
{
    static char empty[] = "";
    static char zero[] = "0";
    static char one[] = "1";
    static char admin[] = "admin";
    static char password[] = "FRIDAY-LAB-NOT-A-REAL-PASSWORD";
    static char lan_ifname[] = "br0";
    static char lan_ipaddr[] = "10.0.2.15";
    static char lan_netmask[] = "255.255.255.0";

    if (shim_streq(name, "http_loginname")) return admin;
    if (shim_streq(name, "http_passwd")) return password;
    if (shim_streq(name, "lan_ifname")) return lan_ifname;
    if (shim_streq(name, "lan_ipaddr")) return lan_ipaddr;
    if (shim_streq(name, "lan_netmask")) return lan_netmask;
    if (shim_streq(name, "config_state")) return one;
    if (shim_streq(name, "endis_remote")) return zero;
    if (shim_streq(name, "factory_mode")) return zero;
    if (shim_streq(name, "https_enable")) return zero;
    if (shim_streq(name, "remote_mg_enable")) return zero;
    return empty;
}

int config_match(const char *name, const char *value)
{
    return shim_streq(config_get(name), value);
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
