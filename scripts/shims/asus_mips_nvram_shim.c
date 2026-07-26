/*
 * Minimal, allocation-free NVRAM shim for isolated ASUSWRT/MIPS component
 * emulation. This is intentionally a startup scaffold, not a router model.
 */

typedef unsigned long size_t;

struct nvpair {
    const char *name;
    const char *value;
};

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

static const struct nvpair defaults[] = {
    {"productid", "RT-AC1300G_PLUS_V3"},
    {"odmpid", ""},
    {"firmver", "3.0.0.4"},
    {"buildno", "386"},
    {"extendno", "51312"},
    {"lan_ifname", "lo"},
    {"lan_ifnames", "lo"},
    {"lan_ipaddr", "127.0.0.1"},
    {"lan_netmask", "255.0.0.0"},
    {"lan_hwaddr", "02:46:52:49:44:41"},
    {"et0macaddr", "02:46:52:49:44:41"},
    {"http_lanport", "28080"},
    {"http_enable", "0"},
    {"https_lanport", "28443"},
    {"x_Setting", "0"},
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
    while (item->name) {
        if (streq(name, item->name))
            return (char *)item->value;
        item++;
    }
    return "";
}

char *nvram_default_get(const char *name)
{
    return nvram_get(name);
}

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
    (void)name;
    (void)value;
    return 0;
}

int nvram_unset(const char *name)
{
    (void)name;
    return 0;
}

int nvram_commit(void)
{
    return 0;
}

int nvram_match(const char *name, const char *match)
{
    return streq(nvram_get(name), match);
}

int nvram_invmatch(const char *name, const char *match)
{
    return !nvram_match(name, match);
}

char *nvram_safe_get(const char *name)
{
    return nvram_get(name);
}

int nvram_getall(char *buf, int count)
{
    if (buf && count > 0)
        *buf = '\0';
    return 0;
}

int nvram_init(void)
{
    return 0;
}
