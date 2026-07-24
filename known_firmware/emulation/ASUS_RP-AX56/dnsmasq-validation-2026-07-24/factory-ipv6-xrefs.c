STRING 000157e7 get_ipv6_service
STRING 000158dd get_ipv6_service_by_unit
STRING 00126888 ra-param=%s,%d,%d
enable-ra
quiet-ra

REF 00045e40 owner=FUN_00045468
STRING 001268cc dhcp-range=lan,::%04x,::%04x,constructor:%s,%d

REF 00045eb8 owner=FUN_00045468
STRING 001268fc dhcp-range=lan,::,constructor:%s,ra-stateless,%d,%d

REF 00045ef4 owner=FUN_00045468
CALLER_REF target=FUN_00045468 from=00062f18 owner=FUN_00062ed0
CALLER_REF target=FUN_00045468 from=00034828 owner=FUN_000346ac
CALLER_REF target=FUN_00045468 from=0004e5d4 owner=FUN_0004d890
CALLER_REF target=FUN_00045468 from=0004e720 owner=FUN_0004d890
CALLER_REF target=FUN_00045468 from=0004ec70 owner=FUN_0004d890
CALLER_REF target=FUN_00045468 from=0004f660 owner=FUN_0004d890
CALLER_REF target=FUN_00045468 from=000500d8 owner=FUN_0004d890
CALLER_REF target=FUN_00045468 from=0004d310 owner=FUN_0004d2c8

===== FUN_00045468 @ 00045468 =====

void FUN_00045468(void)

{
  bool bVar1;
  __pid_t _Var2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  FILE *pFVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  byte *pbVar10;
  in_addr_t iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  uint uVar17;
  char *local_80;
  char *local_7c;
  char acStack_78 [24];
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  ushort local_52;
  
  _Var2 = getpid();
  psname(_Var2,&uStack_60,0x10);
  uVar3 = uptime();
  cprintf(DAT_000460f0 + 0x454ac,_Var2,&uStack_60,DAT_000460ec + 0x454a0,uVar3);
  _Var2 = getpid();
  iVar5 = DAT_000460f8;
  if (_Var2 != 1) {
    notify_rc(DAT_000460f4 + 0x454c4);
    return;
  }
  FUN_00042f44();
  iVar4 = f_exists((char *)(iVar5 + 0x454d8));
  if (iVar4 != 0) {
    unlink((char *)(iVar5 + 0x454d8));
  }
  uVar3 = FUN_0004179c(DAT_000460fc + 0x454f8);
  iVar5 = FUN_000417bc();
  if (((((iVar5 == 0) && (iVar5 = FUN_00041c10(), iVar5 == 0)) &&
       (iVar5 = FUN_000417f8(), iVar5 == 0)) &&
      (((iVar5 = FUN_00041900(), iVar5 == 0 && (iVar5 = FUN_00041c7c(), iVar5 == 0)) ||
       (iVar5 = nvram_get_int(DAT_00046104 + 0x45550), iVar5 != 0)))) ||
     ((iVar5 = nvram_get_int(DAT_00046100 + 0x45514), iVar5 == 2 ||
      (iVar5 = FUN_00041850(DAT_0004610c + 0x45580,DAT_00046108 + 0x4557c), iVar5 != 0)))) {
    pcVar6 = (char *)FUN_0004179c(DAT_00046114 + 0x455a4);
  }
  else {
    pcVar6 = (char *)nvram_default_get(DAT_00046110 + 0x45594);
  }
  pcVar16 = (char *)(DAT_00046118 + 0x455b8);
  pFVar7 = fopen(pcVar16,(char *)(DAT_0004611c + 0x455bc));
  iVar5 = DAT_00046124;
  if (pFVar7 == (FILE *)0x0) {
    perror(pcVar16);
  }
  else {
    fputs((char *)(DAT_00046120 + 0x455dc),pFVar7);
    pcVar16 = (char *)(iVar5 + 0x455e4);
    uVar8 = get_lan_hostname();
    uVar9 = FUN_0004179c(DAT_00046128 + 0x455f4);
    fprintf(pFVar7,(char *)(DAT_0004612c + 0x45608),pcVar6,uVar8,uVar9,uVar8);
    fprintf(pFVar7,(char *)(DAT_00046130 + 0x45624),pcVar6,uVar8);
    fprintf(pFVar7,pcVar16,pcVar6,DAT_00046134 + 0x4563c);
    fprintf(pFVar7,pcVar16,pcVar6,DAT_00046138 + 0x45654);
    fprintf(pFVar7,pcVar16,pcVar6,DAT_0004613c + 0x4566c);
    iVar5 = is_dpsta_repeater();
    if ((iVar5 != 0) && (iVar5 = nvram_get_int(DAT_00046140 + 0x45688), iVar5 == 0)) {
      fprintf(pFVar7,pcVar16,pcVar6,DAT_00046144 + 0x456a8);
    }
    iVar5 = get_ipv6_service();
    if (iVar5 != 0) {
      fputs((char *)(DAT_00046148 + 0x456c4),pFVar7);
      fputs((char *)(DAT_0004614c + 0x456d4),pFVar7);
      pcVar16 = (char *)ipv6_router_address(0);
      if (*pcVar16 != '\0') {
        uVar9 = FUN_0004179c(DAT_00046150 + 0x456f8);
        fprintf(pFVar7,(char *)(DAT_00046154 + 0x4570c),pcVar16,uVar8,uVar9,uVar8);
        fprintf(pFVar7,(char *)(DAT_00046158 + 0x45728),pcVar16,uVar8);
      }
    }
    fclose(pFVar7);
  }
  iVar4 = DAT_0004615c + 0x4574c;
  iVar5 = nvram_get(iVar4);
  if ((((iVar5 != 0) && (iVar5 = nvram_get_int(iVar4), iVar5 != 1)) &&
      ((iVar5 = nvram_get(iVar4), iVar5 == 0 || (iVar5 = nvram_get_int(iVar4), iVar5 != 4)))) &&
     (((iVar5 = FUN_000417bc(), iVar5 == 0 && (iVar5 = FUN_00041c10(), iVar5 == 0)) &&
      (iVar5 = FUN_000417f8(), iVar5 == 0)))) {
    iVar5 = FUN_00041900();
    if ((iVar5 == 0) && (iVar5 = FUN_00041c7c(), iVar5 == 0)) {
      return;
    }
    iVar5 = nvram_get_int(DAT_00046168 + 0x457ec);
    if (iVar5 != 0) {
      return;
    }
  }
  pFVar7 = fopen((char *)(DAT_00046164 + 0x4576c),(char *)(DAT_00046160 + 0x45768));
  iVar5 = DAT_00046170;
  if (pFVar7 == (FILE *)0x0) {
    return;
  }
  fputs((char *)(DAT_0004616c + 0x4581c),pFVar7);
  iVar5 = iVar5 + 0x45828;
  fprintf(pFVar7,(char *)(DAT_00046174 + 0x45830),uVar3);
  iVar4 = nvram_get(iVar5);
  if (((iVar4 == 0) || (iVar4 = nvram_get_int(iVar5), iVar4 == 1)) ||
     ((iVar4 = nvram_get(iVar5), iVar4 != 0 && (iVar5 = nvram_get_int(iVar5), iVar5 == 4)))) {
    fprintf(pFVar7,(char *)(DAT_0004617c + 0x4585c),DAT_00046178 + 0x45858);
  }
  iVar4 = DAT_00046180 + 0x458a0;
  iVar5 = nvram_get(iVar4);
  if (((iVar5 == 0) || (iVar5 = nvram_get_int(iVar4), iVar5 == 1)) ||
     ((iVar5 = nvram_get(iVar4), iVar5 != 0 && (iVar5 = nvram_get_int(iVar4), iVar5 == 4)))) {
    pcVar16 = (char *)(DAT_00046188 + 0x458f4);
  }
  else {
    pcVar16 = (char *)(DAT_00046184 + 0x458d8);
  }
  fprintf(pFVar7,pcVar16,DAT_0004618c + 0x45900);
  iVar5 = nvram_get_int(DAT_00046190 + 0x4590c);
  if (iVar5 == 0) {
    iVar5 = 0x1000;
  }
  fprintf(pFVar7,(char *)(DAT_00046198 + 0x45924),DAT_00046194 + 0x45920,0x5dc,iVar5);
  iVar4 = nvram_get_int(DAT_0004619c + 0x45940);
  if (iVar4 != 0) {
    fprintf(pFVar7,(char *)(DAT_000461a0 + 0x45970));
  }
  pbVar10 = (byte *)FUN_0004179c(DAT_000461a4 + 0x4597c);
  if (*pbVar10 != 0) {
    fprintf(pFVar7,(char *)(DAT_000461a8 + 0x4599c),pbVar10,(uint)*pbVar10,iVar5);
  }
  iVar4 = DAT_000461ac + 0x459a8;
  iVar5 = nvram_get(iVar4);
  if (((((iVar5 == 0) || (iVar5 = nvram_get_int(iVar4), iVar5 == 1)) ||
       ((iVar5 = nvram_get(iVar4), iVar5 != 0 && (iVar5 = nvram_get_int(iVar4), iVar5 == 4)))) &&
      (iVar5 = nvram_get_int(DAT_000461b0 + 0x459c0), iVar5 != 0)) ||
     (((((iVar5 = FUN_000417bc(), iVar5 != 0 || (iVar5 = FUN_00041c10(), iVar5 != 0)) ||
        (iVar5 = FUN_000417f8(), iVar5 != 0)) ||
       (((iVar5 = FUN_00041900(), iVar5 != 0 || (iVar5 = FUN_00041c7c(), iVar5 != 0)) &&
        (iVar5 = nvram_get_int(DAT_000461bc + 0x45a7c), iVar5 == 0)))) &&
      (iVar5 = nvram_get_int(DAT_000461b4 + 0x45a28), iVar5 != 2)))) {
    FUN_00042cf8(&local_80,&local_7c,&uStack_60);
    iVar5 = nvram_get_int(DAT_000461b8 + 0x45a4c);
    if ((iVar5 == 2) ||
       (((iVar5 = FUN_000417bc(), iVar5 == 0 && (iVar5 = FUN_00041c10(), iVar5 == 0)) &&
        ((iVar5 = FUN_000417f8(), iVar5 == 0 &&
         (((iVar5 = FUN_00041900(), iVar5 == 0 && (iVar5 = FUN_00041c7c(), iVar5 == 0)) ||
          (iVar5 = nvram_get_int(DAT_000461c4 + 0x45aec), iVar5 != 0)))))))) {
      iVar5 = nvram_get_int(DAT_000461c8 + 0x45b10);
    }
    else {
      pcVar16 = (char *)nvram_default_get(DAT_000461c0 + 0x45ab4);
      iVar5 = atoi(pcVar16);
    }
    if (iVar5 < 1) {
      iVar5 = DAT_000461cc;
    }
    if ((*local_80 == '\0') || (*local_7c == '\0')) {
      iVar4 = nvram_get_int(DAT_000461d8 + 0x45b7c);
      iVar13 = nvram_get_int(DAT_000461dc + 0x45b8c);
      strlcpy(acStack_78,pcVar6,0x18);
      pcVar16 = strrchr(acStack_78,0x2e);
      if (pcVar16 != (char *)0x0) {
        pcVar16[1] = '\0';
      }
      uVar8 = FUN_0004179c(DAT_000461e0 + 0x45bc4);
      fprintf(pFVar7,(char *)(DAT_000461e4 + 0x45bec),acStack_78,iVar4,acStack_78,
              iVar4 + iVar13 + -1,uVar8,iVar5);
    }
    else {
      uVar8 = FUN_0004179c(DAT_000461d0 + 0x45b4c);
      fprintf(pFVar7,(char *)(DAT_000461d4 + 0x45b60),local_80,local_7c,uVar8,iVar5);
    }
    pcVar16 = (char *)FUN_0004179c(DAT_000461e8 + 0x45c00);
    if ((*pcVar16 != '\0') && (iVar11 = inet_addr(pcVar16), iVar11 != 0)) {
      pcVar6 = pcVar16;
    }
    fprintf(pFVar7,(char *)(DAT_000461ec + 0x45c30),pcVar6);
    pcVar6 = (char *)FUN_0004179c(DAT_000461f0 + 0x45c3c);
    pcVar16 = (char *)FUN_0004179c(DAT_000461f4 + 0x45c4c);
    if (((*pcVar6 != '\0') && (iVar11 = inet_addr(pcVar6), iVar11 != 0)) ||
       ((*pcVar16 != '\0' && (iVar11 = inet_addr(pcVar16), iVar11 != 0)))) {
      if ((*pcVar6 == '\0') || (iVar11 = inet_addr(pcVar6), iVar11 == 0)) {
        pcVar6 = (char *)(DAT_000461f8 + 0x45cbc);
      }
      if ((*pcVar16 == '\0') || (iVar11 = inet_addr(pcVar16), iVar11 == 0)) {
        pcVar16 = (char *)(DAT_000461fc + 0x45ce4);
      }
      fprintf(pFVar7,(char *)(DAT_00046200 + 0x45cf4),pcVar6,pcVar16);
    }
    pcVar6 = (char *)FUN_0004179c(DAT_00046204 + 0x45d00);
    if (*pcVar6 != '\0') {
      fprintf(pFVar7,(char *)(DAT_00046208 + 0x45d20),pcVar6);
    }
    pcVar6 = (char *)FUN_0004179c(DAT_0004620c + 0x45d2c);
    if ((*pcVar6 != '\0') && (iVar11 = inet_addr(pcVar6), iVar11 != 0)) {
      fprintf(pFVar7,(char *)(DAT_00046210 + 0x45d5c),pcVar6);
    }
    uVar17 = 1;
  }
  else {
    uVar17 = 0;
  }
  iVar5 = get_ipv6_service();
  if (iVar5 == 0) goto LAB_00045f40;
  iVar4 = DAT_00046214 + 0x45d78;
  iVar5 = nvram_get(iVar4);
  if (((iVar5 != 0) && (iVar5 = nvram_get_int(iVar4), iVar5 != 1)) &&
     ((iVar5 = nvram_get(iVar4), iVar5 == 0 || (iVar5 = nvram_get_int(iVar4), iVar5 != 4))))
  goto LAB_00045f40;
  uVar12 = get_ipv6_service();
  if ((uVar12 & 0xfffffffb) == 1) {
    ipv6_nvname(DAT_00046218 + 0x45da0);
    iVar5 = nvram_get_int();
LAB_00045df0:
    ipv6_nvname(DAT_0004621c + 0x45dfc);
    iVar4 = nvram_get_int();
    bVar1 = false;
    if (iVar4 != 0) {
      bVar1 = true;
    }
  }
  else {
    iVar5 = 0;
    if (uVar12 != 6) goto LAB_00045df0;
    bVar1 = false;
  }
  iVar4 = DAT_000461cc;
  ipv6_nvname(DAT_00046220 + 0x45e18);
  iVar13 = nvram_get_int();
  if (0 < iVar13) {
    iVar4 = iVar13;
  }
  if (bVar1) {
    fprintf(pFVar7,(char *)(DAT_00046224 + 0x45e48),uVar3,10,600);
    if (iVar5 == 0) {
      fprintf(pFVar7,(char *)(DAT_00046234 + 0x45efc),uVar3,0x40,600);
    }
    else {
LAB_00045e54:
      ipv6_nvname(DAT_00046228 + 0x45e60);
      pcVar6 = (char *)FUN_0004179c();
      iVar5 = inet_pton(10,pcVar6,&uStack_60);
      uVar12 = (local_52 & 0xff) << 8 | (uint)(local_52 >> 8);
      if (iVar5 < 1) {
        uVar12 = 0x1000;
      }
      ipv6_nvname(DAT_0004622c + 0x45e90);
      pcVar6 = (char *)FUN_0004179c();
      iVar5 = inet_pton(10,pcVar6,&uStack_60);
      uVar14 = (local_52 & 0xff) << 8 | (uint)(local_52 >> 8);
      if (iVar5 < 1) {
        uVar14 = 0x2000;
      }
      uVar15 = uVar12;
      if (uVar14 <= uVar12) {
        uVar15 = uVar14;
        uVar14 = uVar12;
      }
      fprintf(pFVar7,(char *)(DAT_00046230 + 0x45ec0),uVar15,uVar14,uVar3,iVar4);
    }
    uVar17 = uVar17 | 2;
  }
  else if (iVar5 != 0) goto LAB_00045e54;
  fputs((char *)(DAT_00046238 + 0x45f14),pFVar7);
  pcVar6 = (char *)FUN_0004179c(DAT_0004623c + 0x45f20);
  if (*pcVar6 != '\0') {
    fprintf(pFVar7,(char *)(DAT_00046240 + 0x45f40),pcVar6);
  }
LAB_00045f40:
  if (uVar17 == 0) {
    fprintf(pFVar7,(char *)(DAT_00046264 + 0x45fe4),uVar3);
  }
  else {
    iVar5 = nvram_get_int(DAT_00046244 + 0x45f54);
    if (-1 < iVar5) {
      fputs((char *)(DAT_00046248 + 0x45f6c),pFVar7);
    }
    iVar5 = nvram_get_int(DAT_0004624c + 0x45f78);
    if ((6 < iVar5) &&
       (iVar5 = FUN_00041850(DAT_00046254 + 0x45f94,DAT_00046250 + 0x45f90), iVar5 != 0)) {
      fputs((char *)(DAT_00046258 + 0x45fac),pFVar7);
      fputs((char *)(DAT_0004625c + 0x45fbc),pFVar7);
      fputs((char *)(DAT_00046260 + 0x45fcc),pFVar7);
    }
  }
  FUN_000e9b4c(pFVar7);
  iVar5 = FUN_00041850(DAT_0004626c + 0x46000,DAT_00046268 + 0x45ffc);
  if (iVar5 != 0) {
    FUN_000451ac(pFVar7);
  }
  fputs((char *)(DAT_00046270 + 0x46020),pFVar7);
  fputs((char *)(DAT_00046274 + 0x46030),pFVar7);
  fclose(pFVar7);
  f_write(DAT_00046278 + 0x46058,0,0,1,0x1b6);
  f_write(DAT_0004627c + 0x46074,0,0,1,0x1b6);
  uStack_60 = *(undefined4 *)((int)&DAT_00046150 + DAT_00046280);
  uStack_5c = *(undefined4 *)((int)&DAT_00046154 + DAT_00046280);
  uStack_58 = *(undefined4 *)((int)&DAT_00046158 + DAT_00046280);
  _eval(&uStack_60,0,0);
  _Var2 = getpid();
  psname(_Var2,&uStack_60,0x10);
  uVar3 = uptime();
  cprintf(DAT_00046288 + 0x460d4,_Var2,&uStack_60,DAT_00046284 + 0x460c8,uVar3);
  return;
}



===== FUN_00062ed0 @ 00062ed0 =====

void FUN_00062ed0(void)

{
  int iVar1;
  __pid_t _Var2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_20 [20];
  
  iVar1 = nvram_get_int(DAT_00062fc4 + 0x62ee0);
  if (iVar1 != 1) {
    iVar4 = DAT_00062fc8 + 0x62ef8;
    iVar1 = nvram_get(iVar4);
    if (((iVar1 != 0) && (iVar1 = nvram_get_int(iVar4), iVar1 != 1)) &&
       ((iVar1 = nvram_get(iVar4), iVar1 == 0 || (iVar1 = nvram_get_int(iVar4), iVar1 != 4)))) {
      iVar4 = DAT_00062fd8 + 0x62f88;
      iVar1 = nvram_get(iVar4);
      if (iVar1 == 0) {
        return;
      }
      iVar1 = nvram_get_int(iVar4);
      if (iVar1 != 2) {
        return;
      }
    }
    iVar1 = pids(DAT_00062fcc + 0x62f10);
    if (iVar1 == 0) {
      FUN_00045468();
      _Var2 = getpid();
      psname(_Var2,auStack_20,0x10);
      uVar3 = uptime();
      cprintf(DAT_00062fd4 + 0x62f58,_Var2,auStack_20,DAT_00062fd0 + 0x62f4c,uVar3);
    }
  }
  return;
}



===== FUN_000346ac @ 000346ac =====

void FUN_000346ac(undefined4 param_1)

{
  int iVar1;
  char *pcVar2;
  char *__s1;
  undefined4 uVar3;
  int iVar4;
  in_addr_t iVar5;
  char *__s2;
  char *__delim;
  char *__format;
  in_addr local_78;
  char *local_74;
  undefined1 auStack_70 [4];
  int local_6c;
  in_addr_t local_68;
  undefined2 uStack_64;
  undefined1 local_62;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  cprintf(DAT_00034ad0 + 0x346d0,DAT_00034acc + 0x346cc,param_1);
  iVar1 = FUN_000309b0();
  if (((((iVar1 != 0) || (iVar1 = FUN_00030dfc(), iVar1 != 0)) ||
       (iVar1 = FUN_00030cb8(), iVar1 != 0)) || (iVar1 = FUN_00030ed8(), iVar1 != 0)) &&
     (pcVar2 = (char *)FUN_000ee320(), pcVar2 != (char *)0x0)) {
    __s2 = (char *)(DAT_00034ad4 + 0x346fc);
    __delim = (char *)(DAT_00034ad8 + 0x34704);
    __format = (char *)(DAT_00034adc + 0x3470c);
    iVar1 = DAT_00034ae0 + 0x34714;
    local_74 = pcVar2;
    while (pcVar2 = strsep(&local_74,__delim), pcVar2 != (char *)0x0) {
      do {
        __s1 = pcVar2;
        pcVar2 = __s1 + 1;
      } while (*__s1 == ' ');
      if (*__s1 == '\0') break;
      iVar4 = strncmp(__s1,__s2,4);
      if (((iVar4 != 0) && (iVar4 = FUN_000309ec(__s1), iVar4 != 0)) &&
         (iVar4 = get_ifname_unit(__s1,auStack_70,&local_6c), iVar4 == 0)) {
        snprintf((char *)&uStack_60,0x27,__format,__s1);
        if ((0 < local_6c) && (iVar4 = nvram_get_int(&uStack_60), iVar4 != 0)) {
          local_68 = 0;
          uStack_64 = 0;
          local_62 = (undefined1)local_6c;
          pcVar2 = (char *)FUN_000308b4(iVar1);
          inet_aton(pcVar2,&local_78);
          local_68 = local_78.s_addr;
          wl_iovar_set(__s1,DAT_00034ae4 + 0x34820,&local_68,7);
        }
      }
    }
  }
  FUN_00045468();
  FUN_00034320();
  iVar1 = FUN_0003095c();
  if (((iVar1 != 0) ||
      (((((iVar1 = FUN_000309b0(), iVar1 != 0 || (iVar1 = FUN_00030dfc(), iVar1 != 0)) ||
         (iVar1 = FUN_00030904(), iVar1 != 0)) ||
        (((iVar1 = FUN_00030cb8(), iVar1 != 0 || (iVar1 = FUN_00030e68(), iVar1 != 0)) &&
         (iVar1 = nvram_get_int(DAT_00034af4 + 0x348c0), iVar1 == 0)))) &&
       (iVar1 = nvram_get_int(DAT_00034af0 + 0x34884), iVar1 == 2)))) ||
     (iVar1 = nvram_get_int(DAT_00034af8 + 0x348e4), iVar1 == 1)) {
    uVar3 = FUN_000308b4(DAT_00034ae8 + 0x34848);
    FUN_00030418(param_1,0,DAT_00034aec + 0x34858,uVar3,DAT_00034aec + 0x34858);
    FUN_00049354();
  }
  iVar1 = DAT_00034afc;
  FUN_00047058();
  FUN_0004500c();
  FUN_0004501c(0);
  FUN_00031638(2,0);
  iVar4 = nvram_get(iVar1 + 0x34904);
  if (((iVar4 != 0) && (iVar1 = nvram_get_int(iVar1 + 0x34904), iVar1 == 2)) &&
     (iVar4 = nvram_get_int(DAT_00034b00 + 0x34940), iVar1 = DAT_00034b04, iVar4 == 1)) {
    FUN_00052304();
    nvram_set_int(iVar1 + 0x3495c,2);
    logmessage_normal(DAT_00034b0c + 0x34974,DAT_00034b08 + 0x34970);
    uVar3 = nvram_get_int(iVar1 + 0x3495c);
    cprintf(DAT_00034b14 + 0x34994,DAT_00034b10 + 0x34988,uVar3);
    kill_pidfile_s(DAT_00034b18 + 0x349a4,10);
  }
  iVar1 = get_model();
  if (iVar1 == 0x2b) {
    iVar4 = DAT_00034b1c + 0x349bc;
    iVar1 = nvram_get(iVar4);
    if ((iVar1 != 0) && (iVar1 = nvram_get_int(iVar4), iVar1 == 3)) {
      FUN_00052304();
      iVar1 = DAT_00034b20;
      uStack_60 = *(undefined4 *)(DAT_00034b20 + 0x34a40);
      uStack_5c = *(undefined4 *)(DAT_00034b20 + 0x34a44);
      uStack_58 = *(undefined4 *)(DAT_00034b20 + 0x34a48);
      uStack_54 = *(undefined4 *)(DAT_00034b20 + 0x34a4c);
      local_50 = *(undefined4 *)(DAT_00034b20 + 0x34a50);
      _eval(&uStack_60,0,0);
      uStack_60 = *(undefined4 *)(iVar1 + 0x34a9c);
      uStack_5c = *(undefined4 *)(iVar1 + 0x34aa0);
      uStack_58 = *(undefined4 *)(iVar1 + 0x34aa4);
      uStack_54 = *(undefined4 *)(iVar1 + 0x34aa8);
      local_50 = *(undefined4 *)(iVar1 + 0x34aac);
      _eval(&uStack_60,0,0);
      uStack_60 = *(undefined4 *)(iVar1 + 0x34ab0);
      uStack_5c = *(undefined4 *)(iVar1 + 0x34ab4);
      uStack_58 = *(undefined4 *)(iVar1 + 0x34ab8);
      uStack_54 = *(undefined4 *)(iVar1 + 0x34abc);
      local_50 = *(undefined4 *)(iVar1 + 0x34ac0);
      uStack_4c = *(undefined4 *)(iVar1 + 0x34ac4);
      uStack_48 = *(undefined4 *)(iVar1 + 0x34ac8);
      uStack_44 = *(undefined4 *)((int)&DAT_00034acc + iVar1);
      uStack_40 = *(undefined4 *)((int)&DAT_00034ad0 + iVar1);
      uStack_3c = *(undefined4 *)((int)&DAT_00034ad4 + iVar1);
      uStack_38 = *(undefined4 *)((int)&DAT_00034ad8 + iVar1);
      uStack_34 = *(undefined4 *)((int)&DAT_00034adc + iVar1);
      _eval(&uStack_60,0,0);
      pcVar2 = (char *)FUN_000308b4(DAT_00034b24 + 0x34a84);
      iVar5 = inet_addr(pcVar2);
      sprintf((char *)&uStack_60,(char *)(DAT_00034b2c + 0x34a9c),iVar5,DAT_00034b28 + 0x34a98);
      f_write_string(DAT_00034b30 + 0x34abc,&uStack_60,0);
      FUN_0004bfc4();
    }
  }
  FUN_0004cc24();
  return;
}



===== FUN_0004d890 @ 0004d890 =====

void FUN_0004d890(void)

{
  char cVar1;
  undefined2 uVar2;
  int **ppiVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  __pid_t _Var7;
  FILE *pFVar8;
  byte *__s;
  size_t sVar9;
  char *pcVar10;
  undefined4 uVar11;
  char *__s2;
  in_addr_t iVar12;
  int *piVar13;
  int iVar14;
  int *piVar15;
  int **ppiVar16;
  char *__delim;
  char *__delim_00;
  int iVar17;
  char *__s2_00;
  int *piVar18;
  int *piVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  char *local_11d4;
  char *local_11d0;
  undefined1 auStack_11cc [4];
  in_addr local_11c8;
  undefined4 local_11c4;
  char acStack_11c0 [32];
  char *local_11a0 [8];
  int *local_1180 [3];
  int *local_1174;
  int local_1170;
  undefined4 local_116c;
  char local_1120 [256];
  int local_1020;
  char *pcStack_101c;
  int local_1018;
  undefined2 local_1014;
  char local_1012 [4082];
  
  uVar4 = FUN_0004179c(DAT_0004e7c0 + 0x4d8a8);
  iVar27 = DAT_0004e7c4 + 0x4d8c0;
  strlcpy(local_1120,uVar4,0x100);
  uVar22 = 0;
  __delim = (char *)(DAT_0004e7c8 + 0x4d8dc);
  __delim_00 = (char *)(DAT_0004e7cc + 0x4d8e8);
  iVar17 = DAT_0004e7d0 + 0x4d8f4;
  __s2_00 = (char *)(DAT_0004e7d4 + 0x4d900);
  local_11d0 = local_1120;
  do {
    local_11d4 = strsep(&local_11d0,__delim);
    memset(local_11a0,0,0x20);
    for (iVar24 = 0; iVar24 != 8; iVar24 = iVar24 + 1) {
      pcVar5 = local_11d4;
      if (iVar24 != 0) {
        pcVar5 = (char *)0x0;
      }
      pcVar5 = strtok_r(pcVar5,__delim_00,&local_11d4);
      if (pcVar5 == (char *)0x0) {
        if (iVar24 == 0) {
          nvram_set(DAT_0004e7dc + 0x4d988,DAT_0004e7d8 + 0x4d984);
          return;
        }
        break;
      }
      cprintf(iVar17,iVar24,pcVar5);
      local_11a0[iVar24] = pcVar5;
    }
    pcVar5 = local_11a0[0];
    iVar6 = strncmp(local_11a0[0],__s2_00,6);
    if (iVar6 == 0) {
      uVar22 = uVar22 | 2;
      pcVar5 = pcVar5 + 6;
    }
    else {
      iVar6 = strncmp(pcVar5,(char *)(DAT_0004e7e0 + 0x4d9c4),5);
      if (iVar6 == 0) {
        uVar22 = uVar22 | 1;
        pcVar5 = pcVar5 + 5;
      }
      else {
        iVar6 = strncmp(pcVar5,(char *)(DAT_0004e7e4 + 0x4d9e8),8);
        if (iVar6 == 0) {
          pcVar5 = pcVar5 + 8;
          uVar22 = 3;
        }
        else {
          uVar22 = 0;
        }
      }
    }
    _Var7 = getpid();
    psname(_Var7,&local_1020,0x10);
    uVar4 = uptime();
    cprintf(DAT_0004e7ec + 0x4da30,_Var7,&local_1020,DAT_0004e7e8 + 0x4da24,uVar4,uVar22,pcVar5);
    iVar6 = strcmp(pcVar5,(char *)(DAT_0004e7f0 + 0x4da40));
    if ((iVar6 == 0) || (iVar6 = strcmp(pcVar5,(char *)(DAT_0004e7f4 + 0x4da58)), iVar6 == 0)) {
      iVar25 = 1;
      iVar14 = DAT_0004e7fc + 0x4da7c;
      iVar6 = DAT_0004e800 + 0x4da80;
      **(undefined4 **)(iVar27 + DAT_0004e7f8) = 1;
      f_write_string(iVar6,iVar14,0);
      nvram_set_int(DAT_0004e804 + 0x4da9c,0);
      FUN_0003ebb4();
      uVar4 = FUN_0004179c(DAT_0004e808 + 0x4daac);
      snprintf((char *)&local_1020,0x1000,(char *)(DAT_0004e80c + 0x4dabc),uVar4);
      local_1180[0] = (int *)(DAT_0004e810 + 0x4dad8);
      local_1180[1] = (int *)(DAT_0004e814 + 0x4dae4);
      local_1180[2] = (int *)(DAT_0004e818 + 0x4daf0);
      local_1170 = 0;
      local_1174 = &local_1020;
      _eval(local_1180,0,0);
      iVar6 = strcmp(pcVar5,(char *)(DAT_0004e81c + 0x4db14));
      if (iVar6 == 0) {
        for (; iVar25 < iVar24; iVar25 = iVar25 + 1) {
          if (local_11a0[iVar25] != (char *)0x0) {
            FUN_0002d05c();
          }
        }
      }
    }
    else {
      iVar6 = strcmp(pcVar5,(char *)(DAT_0004e820 + 0x4db4c));
      if (iVar6 == 0) {
        local_1020 = *(int *)(DAT_0004e824 + 0x4dd3c);
        pcStack_101c = *(char **)(DAT_0004e824 + 0x4dd40);
        local_1018 = *(int *)(DAT_0004e824 + 0x4dd44);
        _eval(&local_1020,0,0);
        FUN_000a6b54();
        FUN_0004a95c();
      }
      else {
        iVar6 = strcmp(pcVar5,(char *)(DAT_0004e828 + 0x4db94));
        if (iVar6 == 0) {
          FUN_0004a95c();
        }
        else {
          iVar6 = strcmp(pcVar5,(char *)(DAT_0004e82c + 0x4dbb4));
          if (iVar6 == 0) {
            if ((uVar22 & 1) == 0) {
              if ((uVar22 & 2) != 0) {
                FUN_0004a4e0();
              }
            }
            else {
              FUN_0004a51c();
            }
          }
          else {
            iVar6 = strcmp(pcVar5,(char *)(DAT_0004e830 + 0x4dbec));
            if (iVar6 == 0) {
              sleep(2);
              FUN_00039098();
              FUN_00038ffc(6);
              kill(1,0xf);
            }
            else {
              iVar6 = strcmp(pcVar5,(char *)(DAT_0004e834 + 0x4dc28));
              if (iVar6 == 0) {
                piVar13 = &local_1020;
                piVar18 = (int *)(DAT_0004e838 + 0x4dc40);
                do {
                  piVar19 = piVar18;
                  piVar15 = piVar13;
                  piVar18 = piVar19 + 2;
                  iVar24 = piVar19[1];
                  *piVar15 = *piVar19;
                  piVar15[1] = iVar24;
                  piVar13 = piVar15 + 2;
                } while (piVar18 != (int *)(DAT_0004e838 + 0x4dc48));
                iVar24 = piVar19[3];
                cVar1 = *(char *)((int)piVar19 + 0xe);
                iVar6 = DAT_0004e83c + 0x4dc7c;
                piVar15[2] = *piVar18;
                *(short *)(piVar15 + 3) = (short)iVar24;
                *(char *)((int)piVar15 + 0xe) = cVar1;
                memset(local_1012 + 1,0,0x31);
                iVar24 = nvram_get_int(iVar6);
                if (iVar24 == 0) {
                  nvram_set(iVar6,DAT_0004e840 + 0x4dcb0);
                  wait_action_idle(10);
                }
                iVar14 = 1;
                iVar25 = DAT_0004e848 + 0x4dcd4;
                iVar6 = DAT_0004e84c + 0x4dcd8;
                **(undefined4 **)(iVar27 + DAT_0004e844) = 1;
                f_write_string(iVar6,iVar25,0);
                if (local_11a0[1] != (char *)0x0) {
                  iVar14 = atoi(local_11a0[1]);
                }
                iVar6 = 0;
                if (local_11a0[2] != (char *)0x0) {
                  iVar6 = atoi(local_11a0[2]);
                }
                cprintf(DAT_0004e850 + 0x4dd20,iVar14,iVar6);
                iVar25 = FUN_000a4900();
                if (iVar25 == 0) {
                  uVar4 = ATE_UPGRADE_MODE_STR();
                  iVar25 = FUN_00041850(uVar4,DAT_0004e854 + 0x4dd3c);
                  if (iVar25 == 0) {
                    cprintf(DAT_0004e858 + 0x4dd50);
                    pFVar8 = fopen((char *)(DAT_0004e860 + 0x4dd64),(char *)(DAT_0004e85c + 0x4dd60)
                                  );
                    if (pFVar8 == (FILE *)0x0) {
                      cprintf(DAT_0004e868 + 0x4dd94);
                    }
                    else {
                      fputs((char *)(DAT_0004e864 + 0x4dd7c),pFVar8);
                      fclose(pFVar8);
                    }
                    iVar24 = f_exists(&local_1020);
                    if (iVar24 != 0) {
                      unlink((char *)&local_1020);
                    }
                    goto LAB_000509c8;
                  }
                }
                if ((uVar22 & 1) != 0) {
                  pFVar8 = fopen((char *)(DAT_0004e870 + 0x4ddcc),(char *)(DAT_0004e86c + 0x4ddc8));
                  if (pFVar8 == (FILE *)0x0) {
                    cprintf(DAT_0004e878 + 0x4ddfc);
                  }
                  else {
                    fputs((char *)(DAT_0004e874 + 0x4dde4),pFVar8);
                    fclose(pFVar8);
                  }
                  iVar26 = DAT_0004e87c + 0x4de08;
                  iVar25 = nvram_get(iVar26);
                  if ((iVar25 != 0) && (iVar25 = nvram_get_int(iVar26), iVar25 == 2)) {
                    FUN_0004ab80();
                  }
                  FUN_00047220();
                  FUN_000491dc();
                  FUN_00049cf0();
                  FUN_0005e944();
                  FUN_0006e11c(0xffffffff);
                  FUN_0006e948();
                  FUN_0006e6c8();
                  FUN_000b26dc(1);
                  FUN_00045078();
                  FUN_0004500c();
                  FUN_0004ce88();
                  FUN_0004cbc4();
                  FUN_0004a724();
                  FUN_0004a89c();
                }
                if ((uVar22 & 2) != 0) {
                  pFVar8 = fopen((char *)(DAT_0004e884 + 0x4de84),(char *)(DAT_0004e880 + 0x4de80));
                  if (pFVar8 == (FILE *)0x0) {
                    cprintf(DAT_0004e88c + 0x4deb4);
                  }
                  else {
                    fputs((char *)(DAT_0004e888 + 0x4de9c),pFVar8);
                    fclose(pFVar8);
                  }
                  FUN_0002b6c4(0x5a);
                  iVar25 = f_exists(&local_1020);
                  if (iVar25 == 0) {
                    pFVar8 = fopen((char *)(DAT_0004e8cc + 0x4dffc),(char *)(DAT_0004e8c8 + 0x4dff8)
                                  );
                    if (pFVar8 == (FILE *)0x0) {
                      cprintf(DAT_0004e8d4 + 0x4e02c);
                    }
                    else {
                      fputs((char *)(DAT_0004e8d0 + 0x4e014),pFVar8);
                      fclose(pFVar8);
                    }
                    cprintf(DAT_0004e8d8 + 0x4e038);
                  }
                  else {
                    iVar25 = nvram_contains_word(DAT_0004e894 + 0x4dee0,DAT_0004e890 + 0x4dedc);
                    if (iVar25 == 0) {
                      local_1180[0] = (int *)(DAT_0004e89c + 0x4df18);
                      local_1180[1] = (int *)(DAT_0004e8a0 + 0x4df28);
                      local_1174 = (int *)(DAT_0004e8a4 + 0x4df34);
                      local_1170 = DAT_0004e8a8 + 0x4df40;
                      local_116c = 0;
                      local_1180[2] = &local_1020;
                    }
                    else {
                      local_1180[0] = (int *)(DAT_0004e898 + 0x4defc);
                      local_1180[2] = (int *)0x0;
                      local_1180[1] = &local_1020;
                    }
                    _eval(local_1180,0,0);
                    pFVar8 = fopen((char *)(DAT_0004e8b0 + 0x4df60),(char *)(DAT_0004e8ac + 0x4df5c)
                                  );
                    if (pFVar8 == (FILE *)0x0) {
                      cprintf(DAT_0004e8b8 + 0x4df90);
                    }
                    else {
                      fputs((char *)(DAT_0004e8b4 + 0x4df78),pFVar8);
                      fclose(pFVar8);
                    }
                    unlink((char *)&local_1020);
                    if (iVar6 != 0) {
                      cprintf(DAT_0004e8bc + 0x4dfac);
                      FUN_00095848();
                    }
                    if (iVar14 != 0) {
                      cprintf(DAT_0004e8c0 + 0x4dfc4);
                      kill(1,0xf);
                    }
                    if (iVar24 == 0) {
                      nvram_unset(DAT_0004e8c4 + 0x4dfe4);
                    }
                  }
                }
              }
              else {
                iVar14 = strcmp(pcVar5,(char *)(DAT_0004e8dc + 0x4e04c));
                iVar6 = DAT_0004e8e0;
                if (iVar14 == 0) {
                  FUN_0004a930();
                  iVar24 = nvram_get_int(iVar6 + 0x4e064);
                  if (iVar24 == 0) {
                    nvram_set(iVar6 + 0x4e064,DAT_0004e8e4 + 0x4e080);
                    wait_action_idle(10);
                  }
                  iVar6 = DAT_0004e8f0;
                  if ((uVar22 & 1) != 0) {
                    iVar25 = DAT_0004e8e8 + 0x4e0ac;
                    iVar14 = DAT_0004e8ec + 0x4e0b0;
                    **(undefined4 **)(iVar27 + DAT_0004e844) = 1;
                    f_write_string(iVar14,iVar25,0);
                    nvram_set_int(DAT_0004e8f4 + 0x4e0d4,0);
                    iVar14 = nvram_get(iVar6 + 0x4e0c4);
                    if ((iVar14 != 0) && (iVar6 = nvram_get_int(iVar6 + 0x4e0c4), iVar6 == 2)) {
                      FUN_0004ab80();
                    }
                    iVar6 = FUN_00041850(DAT_0004e8fc + 0x4e10c,DAT_0004e8f8 + 0x4e108);
                    if ((iVar6 == 0) ||
                       (iVar6 = FUN_00041850(DAT_0004e904 + 0x4e130,DAT_0004e900 + 0x4e12c),
                       iVar6 == 0)) {
                      FUN_0004a5f0();
                    }
                    FUN_0005e944();
                    FUN_0006e11c(0xffffffff);
                    FUN_0006e948();
                    FUN_0006e6c8();
                    FUN_000b26dc(1);
                    FUN_0004d4c0();
                    FUN_0004a51c();
                  }
                  if ((uVar22 & 2) != 0) {
                    piVar13 = &local_1020;
                    piVar18 = (int *)(DAT_0004e908 + 0x4e174);
                    do {
                      piVar19 = piVar18;
                      piVar15 = piVar13;
                      piVar18 = piVar19 + 2;
                      iVar6 = piVar19[1];
                      *piVar15 = *piVar19;
                      piVar15[1] = iVar6;
                      piVar13 = piVar15 + 2;
                    } while (piVar18 != (int *)(DAT_0004e908 + 0x4e17c));
                    iVar6 = piVar19[3];
                    cVar1 = *(char *)((int)piVar19 + 0xe);
                    piVar15[2] = *piVar18;
                    *(short *)(piVar15 + 3) = (short)iVar6;
                    *(char *)((int)piVar15 + 0xe) = cVar1;
                    memset(local_1012 + 1,0,0x31);
                    __s = (byte *)FUN_0004179c(DAT_0004e90c + 0x4e1c8);
                    FUN_0002b6c4(0x5a);
                    iVar6 = f_exists(&local_1020);
                    if ((iVar6 == 0) && (sVar9 = strlen((char *)__s), 5 < sVar9)) {
                      uVar4 = FUN_0004179c(DAT_0004e910 + 320000);
                      snprintf((char *)&local_1020,0x40,(char *)(DAT_0004e914 + 0x4e220),uVar4,
                               (uint)*__s,(uint)__s[1],(uint)__s[2],(uint)__s[3],__s + 5);
                      cprintf(DAT_0004e918 + 0x4e250,&local_1020);
                    }
                    iVar6 = f_exists(&local_1020);
                    if (iVar6 != 0) {
                      iVar6 = nvram_contains_word(DAT_0004e920 + 0x4e274,DAT_0004e91c + 0x4e270);
                      if (iVar6 == 0) {
                        local_1180[0] = (int *)(DAT_0004e928 + 0x4e2ac);
                        local_1180[1] = (int *)(DAT_0004e92c + 0x4e2bc);
                        local_1174 = (int *)(DAT_0004e930 + 0x4e2c8);
                        local_1170 = DAT_0004e934 + 0x4e2d4;
                        local_116c = 0;
                        local_1180[2] = &local_1020;
                      }
                      else {
                        local_1180[0] = (int *)(DAT_0004e924 + 0x4e290);
                        local_1180[2] = (int *)0x0;
                        local_1180[1] = &local_1020;
                      }
                      _eval(local_1180,0,0);
                      unlink((char *)&local_1020);
                    }
                    kill(1,0xf);
                  }
                  if (iVar24 == 0) {
                    nvram_unset(DAT_0004e938 + 0x4e308);
                  }
                }
                else {
                  iVar6 = strcmp(pcVar5,(char *)(DAT_0004e93c + 0x4e31c));
                  if (iVar6 == 0) {
                    nvram_set(DAT_0004e944 + 0x4e338,DAT_0004e940 + 0x4e334);
                    FUN_0004d7a0();
                  }
                  else {
                    iVar6 = strcmp(pcVar5,(char *)(DAT_0004e948 + 0x4e350));
                    if (iVar6 == 0) {
                      nvram_set(DAT_0004e950 + 0x4e36c,DAT_0004e94c + 0x4e368);
                      FUN_0004a614();
                      FUN_0004a604();
                      FUN_00045160();
                      FUN_0004d7a0();
                    }
                    else {
                      iVar6 = strcmp(pcVar5,(char *)(DAT_0004e954 + 0x4e390));
                      if (iVar6 == 0) {
                        nvram_set(DAT_0004e95c + 0x4e3ac,DAT_0004e958 + 0x4e3a8);
                        FUN_0004a614();
                        FUN_0004a604();
                        FUN_00045160();
                        FUN_0004d7a0();
                        modprobe_r(DAT_0004e960 + 0x4e3c8);
                        modprobe_r(DAT_0004e964 + 0x4e3d4);
                        modprobe_r(DAT_0004e968 + 0x4e3e0);
                        modprobe_r(DAT_0004e96c + 0x4e3ec);
                        modprobe_r(DAT_0004e970 + 0x4e3f8);
                        modprobe_r(DAT_0004e974 + 0x4e404);
                        modprobe_r(DAT_0004e978 + 0x4e410);
                        modprobe_r(DAT_0004e97c + 0x4e41c);
                        modprobe_r(DAT_0004e980 + 0x4e428);
                        modprobe_r(DAT_0004e984 + 0x4e434);
                        modprobe_r(DAT_0004e988 + 0x4e440);
                        modprobe_r(DAT_0004e98c + 0x4e44c);
                        modprobe_r(DAT_0004e990 + 0x4e458);
                        modprobe_r(DAT_0004e994 + 0x4e464);
                        modprobe_r(DAT_0004e998 + 0x4e470);
                        modprobe_r(DAT_0004e99c + 0x4e47c);
                        modprobe_r(DAT_0004e9a0 + 0x4e488);
                        modprobe_r(DAT_0004e9a4 + 0x4e494);
                        modprobe_r(DAT_0004e9a8 + 0x4e4a0);
                        modprobe_r(DAT_0004e9ac + 0x4e4ac);
                        modprobe_r(DAT_0004e9b0 + 0x4e4b8);
                        modprobe_r(DAT_0004e9b4 + 0x4e4c4);
                        modprobe_r(DAT_0004e9b8 + 0x4e4d0);
                        modprobe_r(DAT_0004e9bc + 0x4e4dc);
                        modprobe_r(DAT_0004e9c0 + 0x4e4e8);
                        modprobe_r(DAT_0004e9c4 + 0x4e4f4);
                        modprobe_r(DAT_0004e9c8 + 0x4e500);
                        modprobe_r(DAT_0004e9cc + 0x4e50c);
                        modprobe_r(DAT_0004e9d0 + 0x4e518);
                        modprobe_r(DAT_0004e9d4 + 0x4e524);
                      }
                      else {
                        iVar6 = strcmp(pcVar5,(char *)(DAT_0004e9d8 + 0x4e538));
                        if (iVar6 == 0) {
                          if ((uVar22 & 1) != 0) {
                            sleep(2);
                            FUN_00045078();
                            FUN_0004500c();
                            FUN_00048718();
                            FUN_00048408();
                            FUN_000b2ec8();
                            FUN_00042f44();
                            FUN_00049cf0();
                            FUN_000491dc();
                            FUN_00049488();
                            FUN_00031f0c();
                            FUN_0004c2ac();
                            FUN_00048090();
                            FUN_00044f94();
                            FUN_0004d090();
                            FUN_0004c1b4();
                            FUN_0004725c();
                            FUN_00044e60();
                            FUN_00044ecc();
                            FUN_0004d41c();
                            FUN_0003a14c();
                            FUN_00044fa4();
                            FUN_0003ebb4();
                            FUN_0003343c();
                            FUN_00030858();
                            FUN_0004ce88();
                            FUN_0004cbc4();
                          }
                          iVar24 = DAT_0004e9dc;
                          if ((uVar22 & 2) != 0) {
                            FUN_00034b34();
                            FUN_000320f4();
                            FUN_00038dbc();
                            FUN_00045468();
                            FUN_00049ae4();
                            FUN_000305b8();
                            FUN_0003fbdc();
                            iVar6 = nvram_get(iVar24 + 0x4e5d4);
                            if ((iVar6 == 0) ||
                               (iVar24 = nvram_get_int(iVar24 + 0x4e5d4), iVar24 == 1)) {
                              FUN_00047294();
                            }
                            FUN_00044fb4();
                            FUN_0003a190();
                            FUN_0004d0d4();
                            FUN_00044edc();
                            FUN_00044e70();
                            FUN_00048058();
                            FUN_0004c1c4();
                            FUN_0004d034();
                            FUN_00044f38();
                            FUN_000480f0();
                            FUN_0004c218();
                            FUN_00031f1c();
                            FUN_0004940c();
                            FUN_00038ffc(0);
                            FUN_00048904();
                            FUN_00048454();
                            FUN_00048400();
                            FUN_000b2890();
                            FUN_000450a4();
                            FUN_0004501c(0);
                            FUN_0004cc24();
                            FUN_0004ceb4();
                            FUN_000d0b0c();
                            FUN_000398b8();
                          }
                        }
                        else {
                          iVar6 = strcmp(pcVar5,(char *)(DAT_0004e9e0 + 0x4e688));
                          if (iVar6 == 0) {
                            if ((uVar22 & 1) != 0) {
                              sleep(2);
                              FUN_00045078();
                              FUN_0004500c();
                              FUN_00048718();
                              FUN_00048408();
                              FUN_000b2ec8();
                              FUN_00042f44();
                              FUN_00049cf0();
                              FUN_000491dc();
                              FUN_00049488();
                              FUN_00031f0c();
                              FUN_0004c2ac();
                              FUN_00048090();
                              FUN_00044f94();
                              FUN_0004d090();
                              FUN_0004c1b4();
                              FUN_0004725c();
                              FUN_00044e60();
                              FUN_00044ecc();
                              FUN_0004d41c();
                              FUN_0003a14c();
                              FUN_00044fa4();
                              FUN_0004ce88();
                              FUN_0004cbc4();
                              FUN_0003ebb4();
                              FUN_0003343c();
                            }
                            iVar24 = DAT_0004e9e4;
                            if ((uVar22 & 2) != 0) {
                              FUN_00034b34();
                              FUN_000320f4();
                              FUN_00038dbc();
                              FUN_00045468();
                              FUN_00049ae4();
                              FUN_0003fbdc();
                              iVar6 = nvram_get(iVar24 + 0x4e720);
                              if ((iVar6 == 0) ||
                                 (iVar24 = nvram_get_int(iVar24 + 0x4e720), iVar24 == 1)) {
                                FUN_00047294();
                              }
                              FUN_00044fb4();
                              FUN_0003a190();
                              FUN_0004d0d4();
                              FUN_00044edc();
                              FUN_00044e70();
                              FUN_00048058();
                              FUN_0004c1c4();
                              FUN_0004d034();
                              FUN_00044f38();
                              FUN_000480f0();
                              FUN_0004c218();
                              FUN_00031f1c();
                              FUN_0004940c();
                              FUN_00038ffc(0);
                              FUN_00048904();
                              FUN_00048454();
                              FUN_00048400();
                              FUN_000b2890();
                              FUN_000450a4();
                              FUN_0004501c(0);
                              FUN_0004cc24();
                              FUN_0004ceb4();
                              FUN_000d0b0c();
                              FUN_000398b8();
                            }
                          }
                          else {
                            iVar6 = strcmp(pcVar5,(char *)(DAT_0004e9e8 + 0x4ebd0));
                            if (iVar6 == 0) {
LAB_0004ebd8:
                              if ((uVar22 & 1) != 0) {
                                sleep(2);
                                FUN_00045078();
                                FUN_0004500c();
                                FUN_00048718();
                                FUN_00048408();
                                FUN_000b2ec8();
                                FUN_00042f44();
                                FUN_00049cf0();
                                FUN_000491dc();
                                FUN_00049488();
                                FUN_00031f0c();
                                FUN_0004c2ac();
                                FUN_00048090();
                                FUN_00044f94();
                                FUN_0004d090();
                                FUN_0004c1b4();
                                FUN_0004725c();
                                FUN_00044e60();
                                FUN_00044ecc();
                                FUN_0004d41c();
                                FUN_0003a14c();
                                FUN_00044fa4();
                                FUN_0004ce88();
                                FUN_0004cbc4();
                                FUN_000d0af8();
                                FUN_0003ebb4();
                                FUN_0003343c();
                                FUN_00039098();
                              }
                              iVar24 = DAT_0004e9ec;
                              if ((uVar22 & 2) != 0) {
                                FUN_00034b34();
                                FUN_000320f4();
                                FUN_00038dbc();
                                FUN_00045468();
                                FUN_00049ae4();
                                FUN_0003fbdc();
                                iVar6 = nvram_get(iVar24 + 0x4ec70);
                                if ((iVar6 == 0) ||
                                   (iVar24 = nvram_get_int(iVar24 + 0x4ec70), iVar24 == 1)) {
                                  FUN_00047294();
                                }
                                FUN_00044fb4();
                                FUN_0003a190();
                                FUN_0004d0d4();
                                FUN_00044edc();
                                FUN_00044e70();
                                FUN_00048058();
                                FUN_0004c1c4();
                                FUN_0004d034();
                                FUN_00044f38();
                                FUN_000480f0();
                                FUN_0004c218();
                                FUN_00031f1c();
                                FUN_0004940c();
                                FUN_00038ffc(6);
                                FUN_00048904();
                                FUN_00048454();
                                FUN_00048400();
                                FUN_000b2890();
                                FUN_000450a4();
                                FUN_0004501c(0);
                                FUN_0004cc24();
                                FUN_0004ceb4();
                                FUN_000d0b0c();
                                FUN_000398b8();
                              }
                            }
                            else {
                              iVar6 = strcmp(pcVar5,(char *)(DAT_0004e9f0 + 0x4ed20));
                              if (iVar6 == 0) {
                                pcVar5 = (char *)FUN_0004179c(DAT_0004e9f4 + 0x4ed38);
                                pcVar10 = (char *)FUN_0004179c(DAT_0004e9f8 + 0x4ed48);
                                iVar24 = FUN_00041850(DAT_0004ea00 + 0x4ed60,DAT_0004e9fc + 0x4ed54)
                                ;
                                if (iVar24 == 0) {
                                  iVar24 = wan_primary_ifunit();
                                  if (iVar24 < 0) goto LAB_000509c8;
                                  snprintf((char *)local_1180,0xf,(char *)(DAT_0004ea2c + 0x4eed4));
                                  FUN_000418d4(local_1180,DAT_0004ea30 + 0x4eeec,&local_1020);
                                  uVar4 = FUN_0004179c();
                                  FUN_000418d4(local_1180,DAT_0004ea34 + 0x4ef00,&local_1020);
                                  uVar11 = FUN_0004179c();
                                  iVar24 = inet_deconflict(pcVar5,pcVar10,uVar4,uVar11,&local_11c8);
                                }
                                else {
                                  snprintf((char *)local_1180,0xf,(char *)(DAT_0004ea04 + 0x4ed80),0
                                          );
                                  FUN_000418d4(local_1180,DAT_0004ea08 + 0x4ed98,&local_1020);
                                  uVar4 = FUN_0004179c();
                                  FUN_000418d4(local_1180,DAT_0004ea0c + 0x4edb0,&local_1020);
                                  uVar11 = FUN_0004179c();
                                  iVar24 = inet_deconflict(pcVar5,pcVar10,uVar4,uVar11,&local_11c8);
                                  if (iVar24 != 0) {
                                    pcVar5 = inet_ntoa(local_11c8);
                                  }
                                  __s2 = (char *)FUN_0004179c(DAT_0004ea10 + 0x4edf4);
                                  iVar24 = strcmp(pcVar5,__s2);
                                }
                                if (iVar24 != 0) {
                                  pcVar5 = inet_ntoa(local_11c8);
                                  nvram_set(DAT_0004ea14 + 0x4ee20,pcVar5);
                                  pcVar5 = inet_ntoa(local_11c8);
                                  nvram_set(DAT_0004ea18 + 0x4ee38,pcVar5);
                                  uVar23 = local_11c8.s_addr << 0x18 |
                                           (local_11c8.s_addr >> 8 & 0xff) << 0x10 |
                                           (local_11c8.s_addr >> 0x10 & 0xff) << 8 |
                                           local_11c8.s_addr >> 0x18;
                                  uVar22 = uVar23 + 1;
                                  local_11c8.s_addr =
                                       uVar22 * 0x1000000 | (uVar22 >> 8 & 0xff) << 0x10 |
                                       (uVar22 >> 0x10 & 0xff) << 8 | uVar22 >> 0x18;
                                  pcVar5 = inet_ntoa(local_11c8);
                                  nvram_set(DAT_0004ea1c + 0x4ee60,pcVar5);
                                  iVar12 = inet_network(pcVar10);
                                  uVar23 = ~iVar12 | uVar23;
                                  uVar22 = 3;
                                  local_11c8.s_addr =
                                       (uVar23 & 0xfe) << 0x18 | (uVar23 >> 8 & 0xff) << 0x10 |
                                       (uVar23 >> 0x10 & 0xff) << 8 | uVar23 >> 0x18;
                                  pcVar5 = inet_ntoa(local_11c8);
                                  nvram_set(DAT_0004ea20 + 0x4ee94,pcVar5);
                                  nvram_commit();
                                  nvram_set(DAT_0004ea28 + 0x4eeac,DAT_0004ea24 + 0x4eea8);
                                  goto LAB_0004ebd8;
                                }
                              }
                              else {
                                iVar6 = strcmp(pcVar5,(char *)(DAT_0004ea38 + 0x4ef38));
                                if (iVar6 == 0) {
                                  nvram_set(DAT_0004ea40 + 0x4ef54,DAT_0004ea3c + 0x4ef50);
                                  if ((uVar22 & 1) != 0) {
                                    FUN_0004ab80();
                                    kill_pidfile_s(DAT_0004ea44 + 0x4ef70,10);
                                    FUN_0004500c();
                                  }
                                  if (uVar22 == 3) {
                                    FUN_00039998();
                                  }
                                  if ((uVar22 & 2) != 0) {
                                    FUN_0004501c(0);
                                    FUN_0004c928();
                                    FUN_0004aadc();
                                  }
                                  nvram_set(DAT_0004ea4c + 0x4efac,DAT_0004ea48 + 0x4efa8);
                                }
                                else {
                                  pcVar10 = (char *)(DAT_0004ea50 + 0x4efc0);
                                  iVar6 = strcmp(pcVar5,pcVar10);
                                  if (iVar6 == 0) {
                                    uVar4 = FUN_0004179c(pcVar10);
                                    dbg(DAT_0004ea58 + 0x4eff0,DAT_0004ea54 + 0x4efe4,0x32ba,uVar4);
                                    pcVar5 = (char *)FUN_0004179c(pcVar10);
                                    pcVar10 = strchr(pcVar5,0x2c);
                                    if (pcVar10 == (char *)0x0) {
                                      iVar6 = atoi(pcVar5);
                                      iVar24 = 0;
                                    }
                                    else {
                                      local_1180[0] = &local_1020;
                                      strncpy((char *)&local_1020,pcVar5,100);
                                      pcVar5 = strsep((char **)local_1180,
                                                      (char *)(DAT_0004ea5c + 0x4f030));
                                      iVar6 = atoi(pcVar5);
                                      iVar24 = atoi((char *)local_1180[0]);
                                    }
                                    iVar14 = 0;
                                    do {
                                      iVar25 = *(int *)(DAT_0004ea60 + 0x4f064 + iVar14 * 4);
                                      if (iVar6 == iVar25) goto LAB_0004f07c;
                                      iVar14 = iVar14 + 1;
                                    } while (iVar14 != 6);
                                    iVar25 = 800;
LAB_0004f07c:
                                    iVar6 = 0;
                                    do {
                                      if (iVar24 == *(int *)(DAT_0004ea64 + 0x4f08c + iVar6 * 4)) {
                                        if (iVar25 == 0) goto LAB_0004f0c4;
                                        goto LAB_0004f0ac;
                                      }
                                      iVar6 = iVar6 + 1;
                                    } while (iVar6 != 7);
                                    iVar24 = 0x215;
                                    if (iVar25 == 0) {
LAB_0004f0cc:
                                      dbg(DAT_0004ea74 + 0x4f0e8,DAT_0004ea70 + 0x4f0e4,0x32dc,
                                          iVar24);
                                    }
                                    else {
LAB_0004f0ac:
                                      dbg(DAT_0004ea6c + 0x4f0c4,DAT_0004ea68 + 0x4f0c0,0x32db);
LAB_0004f0c4:
                                      if (iVar24 != 0) goto LAB_0004f0cc;
                                    }
                                    nvram_unset(DAT_0004ea78 + 0x4f0f4);
                                    nvram_commit();
                                  }
                                  else {
                                    iVar6 = strcmp(pcVar5,(char *)(DAT_0004ea7c + 0x4f10c));
                                    if (iVar6 == 0) {
                                      iVar24 = nvram_contains_word(DAT_0004ea84 + 0x4f128,
                                                                   DAT_0004ea80 + 0x4f124);
                                      if (iVar24 == 0) {
                                        dbg(DAT_0004ea8c + 0x4f148,DAT_0004ea88 + 0x4f144,0x32e5);
                                      }
                                      else {
                                        FUN_000e6580();
                                      }
                                    }
                                    else {
                                      iVar6 = strcmp(pcVar5,(char *)(DAT_0004ea90 + 0x4f164));
                                      if (iVar6 == 0) {
                                        if ((uVar22 & 1) != 0) {
                                          FUN_000491dc();
                                          FUN_0003ebb4();
                                        }
                                        iVar24 = DAT_0004ea94;
                                        if ((uVar22 & 2) != 0) {
                                          FUN_0003fbdc();
                                          iVar6 = nvram_get(iVar24 + 0x4f194);
                                          if ((iVar6 == 0) ||
                                             (iVar24 = nvram_get_int(iVar24 + 0x4f194), iVar24 == 1)
                                             ) {
                                            FUN_00047294();
                                          }
                                          FUN_00048904();
                                        }
                                      }
                                      else {
                                        iVar6 = strcmp(pcVar5,(char *)(DAT_0004ea98 + 0x4f1d0));
                                        if (iVar6 == 0) {
                                          if (local_11a0[1] != (char *)0x0) {
                                            cprintf(DAT_0004eaa0 + 0x4f1f8,DAT_0004ea9c + 0x4f1f4);
                                            iVar24 = atoi(local_11a0[1]);
                                            iVar6 = wan_primary_ifunit_ipv6();
                                            if ((uVar22 & 1) != 0) {
                                              atoi(local_11a0[1]);
                                              FUN_0003be58();
                                              if (iVar24 == iVar6) {
                                                FUN_00032f48();
                                              }
                                            }
                                            if ((uVar22 & 2) != 0) {
                                              if (iVar24 == iVar6) {
                                                FUN_00032e84();
                                              }
                                              atoi(local_11a0[1]);
                                              FUN_0003ef34();
                                            }
                                          }
                                        }
                                        else {
                                          iVar6 = strcmp(pcVar5,(char *)(DAT_0004eaa4 + 0x4f260));
                                          if (iVar6 == 0) {
                                            if ((uVar22 & 1) != 0) {
                                              FUN_000b943c();
                                            }
                                            if ((uVar22 & 2) != 0) {
                                              FUN_000b93cc(1);
                                            }
                                          }
                                          else {
                                            iVar6 = strcmp(pcVar5,(char *)(DAT_0004eaa8 + 0x4f298));
                                            if (iVar6 == 0) {
                                              if ((uVar22 & 1) != 0) {
                                                FUN_00048210();
                                              }
                                              if ((uVar22 & 2) != 0) {
                                                FUN_0004823c();
                                              }
                                            }
                                            else {
                                              iVar6 = strcmp(pcVar5,(char *)(DAT_0004eaac + 0x4f2cc)
                                                            );
                                              if (iVar6 == 0) {
                                                cprintf(DAT_0004eab4 + 0x4f2ec,
                                                        DAT_0004eab0 + 0x4f2e8,local_11a0[1]);
                                                if (local_11a0[1] != (char *)0x0) {
                                                  atoi(local_11a0[1]);
                                                  get_wan_ifname();
                                                  FUN_0003dd40();
                                                }
                                              }
                                              else {
                                                iVar6 = strcmp(pcVar5,(char *)(DAT_0004eab8 +
                                                                              0x4f318));
                                                if (iVar6 == 0) {
                                                  if ((uVar22 & 1) != 0) {
                                                    FUN_0003a14c();
                                                  }
                                                  if ((uVar22 & 2) != 0) {
                                                    FUN_000320f4();
                                                    FUN_00038dbc();
                                                    FUN_00044fb4();
                                                    FUN_0003a190();
                                                    FUN_0004d0d4();
                                                    FUN_00044edc();
                                                    FUN_00044e70();
                                                    FUN_00048058();
                                                    FUN_0004c1c4();
                                                    FUN_0004d034();
                                                    FUN_00044f38();
                                                    FUN_000480f0();
                                                    FUN_0004c218();
                                                    FUN_000398b8();
                                                  }
                                                }
                                                else {
                                                  iVar6 = strncmp(pcVar5,(char *)(DAT_0004eabc +
                                                                                 0x4f384),5);
                                                  if ((iVar6 == 0) ||
                                                     (iVar6 = strncmp(pcVar5,(char *)(DAT_0004eac0 +
                                                                                     0x4f3a0),5),
                                                     iVar6 == 0)) {
                                                    if ((uVar22 & 2) != 0) {
                                                      pcVar10 = (char *)FUN_0004179c(DAT_0004eac4 +
                                                                                     0x4f3c0);
                                                      if (*pcVar10 == '\0') {
                                                        sprintf(acStack_11c0,
                                                                (char *)(DAT_0004eacc + 0x4f3fc),
                                                                pcVar5);
                                                      }
                                                      else {
                                                        sprintf(acStack_11c0,
                                                                (char *)(DAT_0004eac8 + 0x4f3e4),
                                                                pcVar10,pcVar5);
                                                      }
                                                      local_11a0[0] = acStack_11c0;
                                                      FUN_0004a934(iVar24,local_11a0);
                                                    }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_0004ead0 +
                                                                                  0x4f420));
                                                    if (iVar6 == 0) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_00046438();
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_000463c0();
                                                      }
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_0004ead4 +
                                                                                    0x4f454));
                                                      if (iVar6 == 0) {
                                                        FUN_00046518();
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_0004ead8
                                                                                      + 0x4f474));
                                                        if (iVar6 == 0) {
                                                          FUN_00046518(1);
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar5,(char *)(
                                                  DAT_0004eadc + 0x4f498));
                                                  if (iVar6 == 0) {
                                                    FUN_000469f8();
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_0004eae0 +
                                                                                  0x4f4b8));
                                                    if (iVar6 == 0) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_00048718();
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_00048454();
                                                      }
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_0004eae4 +
                                                                                    0x4f4ec));
                                                      if (iVar6 == 0) {
                                                        if ((uVar22 & 1) != 0) {
                                                          FUN_00048408();
                                                        }
                                                        if ((uVar22 & 2) != 0) {
                                                          FUN_00048400();
                                                        }
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_0004eae8
                                                                                      + 0x4f520));
                                                        if (iVar6 == 0) {
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_000b2ec8();
                                                          }
                                                          if ((uVar22 & 2) != 0) {
                                                            FUN_000b2890();
                                                          }
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar5,(char *)(
                                                  DAT_0004eaec + 0x4f554));
                                                  if (iVar6 == 0) {
                                                    if ((uVar22 & 1) != 0) {
                                                      FUN_00043e18();
                                                    }
                                                    if ((uVar22 & 2) != 0) {
                                                      FUN_00043b04();
                                                    }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_0004eaf0 +
                                                                                  0x4f588));
                                                    if (iVar6 == 0) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_0006e6c8();
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_0006e6d8();
                                                      }
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_0004eaf4 +
                                                                                    0x4f5bc));
                                                      if (iVar6 == 0) {
                                                        if ((uVar22 & 1) != 0) {
                                                          FUN_0003d704();
                                                          FUN_00043e18();
                                                        }
                                                        if ((uVar22 & 2) != 0) {
                                                          FUN_00043b04();
                                                          iVar24 = update_6rd_info();
                                                          if (iVar24 == 0) {
                                                            wan_primary_ifunit_ipv6();
                                                            FUN_0003be58();
                                                            wan_primary_ifunit_ipv6();
                                                            FUN_0003ef34();
                                                          }
                                                          else {
                                                            wan_primary_ifunit_ipv6();
                                                            FUN_0003d674();
                                                          }
                                                        }
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_0004eaf8
                                                                                      + 0x4f61c));
                                                        if (iVar6 == 0) {
                                                          if ((uVar22 & 2) != 0) {
                                                            FUN_00043004();
                                                          }
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar5,(char *)(
                                                  DAT_0004eafc + 0x4f644));
                                                  if (iVar6 == 0) {
                                                    if ((uVar22 & 1) != 0) {
                                                      FUN_00042f44();
                                                    }
                                                    if ((uVar22 & 2) != 0) {
                                                      FUN_00045468();
                                                    }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_0004eb00 +
                                                                                  0x4f678));
                                                    if (iVar6 == 0) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_000491dc();
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_00048904();
                                                      }
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_0004eb04 +
                                                                                    0x4f6ac));
                                                      if (iVar6 == 0) {
                                                        nvram_set(DAT_0004eb0c + 0x4f6c8,
                                                                  DAT_0004eb08 + 0x4f6c4);
                                                        if ((uVar22 & 1) != 0) {
                                                          FUN_0006ad4c();
                                                          FUN_00068600();
                                                        }
                                                        if ((uVar22 & 2) != 0) {
                                                          FUN_0008c1bc(0);
                                                          iVar24 = FUN_00041850(DAT_0004eb14 +
                                                                                0x4f6fc,DAT_0004eb10
                                                                                        + 0x4f6f8);
                                                          if (((iVar24 != 0) &&
                                                              (iVar24 = FUN_00041850(DAT_0004eb1c +
                                                                                     0x4f718,
                                                  DAT_0004eb18 + 0x4f714), iVar24 == 0)) ||
                                                  (iVar24 = FUN_00041850(DAT_0004eb24 + 0x4f73c,
                                                                         DAT_0004eb20 + 0x4f738),
                                                  iVar24 != 0)) {
                                                    FUN_0006b250();
                                                  }
                                                  wan_primary_ifunit();
                                                  get_wan_ifname();
                                                  FUN_0006ad94();
                                                  FUN_0006aea0();
                                                  }
                                                  nvram_set(DAT_0004eb2c + 0x4f768,
                                                            DAT_0004eb28 + 0x4f764);
                                                  }
                                                  else {
                                                    piVar13 = (int *)strcmp(pcVar5,(char *)(
                                                  DAT_0004eb30 + 0x4f77c));
                                                  if (piVar13 == (int *)0x0) {
                                                    snprintf((char *)&local_1020,0x20,
                                                             (char *)(DAT_0004eb34 + 0x4f79c),0xf002
                                                            );
                                                    local_1180[0] = (int *)(DAT_0004eb38 + 0x4f7b4);
                                                    local_1180[2] = (int *)(DAT_0004eb3c + 0x4f7c8);
                                                    local_1180[1] = &local_1020;
                                                    local_1174 = piVar13;
                                                    _eval(local_1180,0,0,0);
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_0004eb40 +
                                                                                  0x4f7e8));
                                                    if (iVar6 == 0) {
                                                      FUN_000d1104();
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_0004eb44 +
                                                                                    0x4f808));
                                                      if (iVar6 == 0) {
                                                        FUN_000d12d4();
                                                        iVar24 = f_read_string(DAT_0004eb48 +
                                                                               0x4f82c,&local_1020,8
                                                                              );
                                                        if (0 < iVar24) {
                                                          iVar24 = atoi((char *)&local_1020);
                                                          kill(iVar24,0xc);
                                                        }
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_0004eb4c
                                                                                      + 0x4f858));
                                                        if (iVar6 == 0) {
                                                          FUN_0004a47c();
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar5,(char *)(
                                                  DAT_0004eb50 + 0x4f878));
                                                  if (iVar6 == 0) {
                                                    FUN_000ab2dc();
                                                    memcpy(local_1180,
                                                           (void *)(DAT_0004eb54 + 0x4f8d8),0x57);
                                                    memset(&local_1020,0,0x85);
                                                    snprintf((char *)&local_1020,0x84,
                                                             (char *)(DAT_0004eb58 + 0x4f8c8),6,
                                                             local_1180);
                                                    send_cfgmnt_event(&local_1020);
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_0004eb5c +
                                                                                  0x4f8ec));
                                                    if (iVar6 == 0) {
                                                      FUN_000ab360();
                                                      memcpy(local_1180,
                                                             (void *)(DAT_0004eb60 + 0x4f9a3),0x5d);
                                                      memset(&local_1020,0,0x85);
                                                      snprintf((char *)&local_1020,0x84,
                                                               (char *)(DAT_0004eb64 + 0x4f93c),6,
                                                               local_1180);
                                                      send_cfgmnt_event(&local_1020);
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_0004eb68 +
                                                                                    0x4f960));
                                                      if (iVar6 == 0) {
                                                        FUN_000ab5f8();
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_0004eb6c
                                                                                      + 0x4f980));
                                                        if (iVar6 == 0) {
                                                          FUN_000ab3e4();
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar5,(char *)(
                                                  DAT_0004eb70 + 0x4f9a0));
                                                  if (iVar6 == 0) {
                                                    if ((uVar22 & 1) != 0) {
                                                      FUN_00047220();
                                                    }
                                                    if ((uVar22 & 2) != 0) {
                                                      FUN_00047154();
                                                    }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_0004eb74 +
                                                                                  0x4f9d4));
                                                    if (iVar6 == 0) {
                                                      if (iVar24 == 1) {
                                                        iVar6 = wan_primary_ifunit();
LAB_0004fa08:
                                                        iVar24 = 0;
                                                      }
                                                      else {
                                                        iVar6 = atoi(local_11a0[1]);
                                                        if (iVar24 == 2) goto LAB_0004fa08;
                                                        iVar24 = atoi(local_11a0[2]);
                                                      }
                                                      nvram_set(DAT_0004eb7c + 0x4fa30,
                                                                DAT_0004eb78 + 0x4fa2c);
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_0005675c(iVar24);
                                                        FUN_0004c834();
                                                        killall(DAT_0004eb80 + 0x4fa54,10);
                                                        FUN_0005bf54(iVar6,iVar24);
                                                      }
                                                      nvram_set(DAT_0004eb88 + 0x4fa74,
                                                                DAT_0004eb84 + 0x4fa70);
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_0004eb8c +
                                                                                    0x4fa88));
                                                      if (iVar6 == 0) {
                                                        cprintf(DAT_0004eb94 + 0x4faac,
                                                                DAT_0004eb90 + 0x4faa8,local_11a0[1]
                                                               );
                                                        if ((local_11a0[1] != (char *)0x0) &&
                                                           ((uVar22 & 2) != 0)) {
                                                          local_1020 = DAT_0004eb98 + 0x4fad4;
                                                          pcStack_101c = local_11a0[1];
                                                          local_1018 = iVar6;
                                                          uVar4 = _eval(&local_1020,0,0,0);
                                                          FUN_00056690(DAT_0004eb9c + 0x4faf8,0x3824
                                                                       ,local_11a0[1],uVar4);
                                                        }
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_0004eba0
                                                                                      + 0x4fb0c));
                                                        if (iVar6 == 0) {
                                                          uVar4 = wan_primary_ifunit();
                                                          nvram_get_int(DAT_0004eba4 + 0x4fb28);
                                                          FUN_00041850(DAT_0004ebac + 0x4fb3c,
                                                                       DAT_0004eba8 + 0x4fb38);
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_00041148();
                                                          }
                                                          if ((uVar22 & 2) != 0) {
                                                            get_wanx_ifname(uVar4);
                                                            FUN_00041064();
                                                          }
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar5,(char *)(
                                                  DAT_0004ebb0 + 0x4fb70));
                                                  if (iVar6 == 0) {
                                                    if ((uVar22 & 1) != 0) {
                                                      FUN_00049328();
                                                    }
                                                    if ((uVar22 & 2) != 0) {
                                                      FUN_000492dc();
                                                    }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_0004ebb4 +
                                                                                  0x4fba4));
                                                    if (iVar6 == 0) {
                                                      fputs((char *)(DAT_0004ebbc + 0x4fbc0),
                                                            (FILE *)**(undefined4 **)
                                                                      (iVar27 + DAT_0004ebb8));
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_00050a4c +
                                                                                    0x4fbd8));
                                                      if (iVar6 == 0) {
                                                        if ((uVar22 & 1) != 0) {
                                                          FUN_00048408();
                                                          FUN_000b2ec8();
                                                          FUN_00047220();
                                                        }
                                                        if ((uVar22 & 2) != 0) {
                                                          FUN_0005f3b0();
                                                          nvram_set(DAT_00050a54 + 0x4fc14,
                                                                    DAT_00050a50 + 0x4fc10);
                                                          FUN_00049354();
                                                          FUN_00047154();
                                                          FUN_00048400();
                                                          FUN_000b2890();
                                                          uVar4 = wan_primary_ifunit();
                                                          FUN_0005bf54(uVar4,0);
                                                        }
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_00050a58
                                                                                      + 0x4fc44));
                                                        if (iVar6 == 0) {
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_00093900();
                                                            iVar24 = FUN_00041850(DAT_00050a60 +
                                                                                  0x4fc6c,
                                                  DAT_00050a5c + 0x4fc68);
                                                  if (iVar24 == 0) {
                                                    kill_pidfile_s(DAT_00050a64 + 0x4fc84,0xc);
                                                  }
                                                  }
                                                  if ((uVar22 & 2) != 0) {
                                                    iVar6 = DAT_00050a68 + 0x4fc98;
                                                    nvram_get_int(iVar6);
                                                    iVar24 = FUN_000446a8();
                                                    if (iVar24 == 0) {
                                                      nvram_get_int(iVar6);
                                                      iVar24 = FUN_000448d8();
                                                      if (iVar24 == 0) {
                                                        FUN_000931a4();
                                                        iVar24 = FUN_00041850(DAT_00050a70 + 0x4fcd4
                                                                              ,DAT_00050a6c +
                                                                               0x4fcd0);
                                                        if (iVar24 == 0) {
                                                          uVar4 = 10;
                                                          iVar24 = DAT_00050a74 + 0x4fce8;
                                                        }
                                                        else {
                                                          uVar4 = 0x14;
                                                          iVar24 = DAT_00050a78 + 0x4fcf4;
                                                        }
                                                        kill_pidfile_s(iVar24,uVar4);
                                                      }
                                                    }
                                                    nvram_unset(DAT_00050a7c + 0x4fd00);
                                                  }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_00050a80 +
                                                                                  0x4fd14));
                                                    if (iVar6 == 0) {
                                                      iVar6 = DAT_00050a84 + 0x4fd28;
                                                      iVar24 = nvram_get(iVar6);
                                                      if ((((iVar24 == 0) ||
                                                           (iVar24 = nvram_get_int(iVar6),
                                                           iVar24 == 1)) ||
                                                          (((iVar24 = FUN_00041900(), iVar24 != 0 ||
                                                            (iVar24 = FUN_00041c7c(), iVar24 != 0))
                                                           && (iVar24 = nvram_get_int(DAT_00050a98 +
                                                                                      0x4fd98),
                                                              iVar24 == 0)))) ||
                                                         ((iVar24 = FUN_00041850(DAT_00050aa0 +
                                                                                 0x4fdc4,
                                                  DAT_00050a9c + 0x4fdc0), iVar24 != 0 &&
                                                  (iVar24 = nvram_get_int(DAT_00050aa4 + 0x4fdd8),
                                                  iVar24 == 0)))) {
                                                    nvram_set_int(DAT_00050a88 + 0x4fd44,1);
                                                    iVar24 = FUN_00041850(DAT_00050a90 + 0x4fd58,
                                                                          DAT_00050a8c + 0x4fd54);
                                                    if (iVar24 == 0) {
                                                      nvram_unset(DAT_00050a94 + 0x4fd6c);
                                                    }
                                                    iVar24 = FUN_00041850(DAT_00050aac + 0x4fdf8,
                                                                          DAT_00050aa8 + 0x4fdf4);
                                                    if (iVar24 != 0) {
                                                      nvram_set_int(DAT_00050ab0 + 0x4fe10,1);
                                                      FUN_00048090();
                                                      FUN_0004d41c();
                                                      FUN_0003a14c();
                                                      FUN_00036908();
                                                      FUN_00036f54();
                                                      FUN_000383e0();
                                                      FUN_00038dbc();
                                                      FUN_0003a190();
                                                      FUN_0004d0d4();
                                                      FUN_000398b8();
                                                    }
                                                    FUN_00093900();
                                                    iVar6 = 4;
                                                    iVar24 = DAT_00050ab4 + 0x4fe4c;
                                                    do {
                                                      FUN_00093d40();
                                                      sleep(1);
                                                      iVar14 = nvram_get_int(iVar24);
                                                      if (iVar14 != 0) break;
                                                      iVar6 = iVar6 + -1;
                                                    } while (iVar6 != 0);
                                                    kill_pidfile_s(DAT_00050ab8 + 0x4fe7c,0x14);
                                                    nvram_unset(DAT_00050abc + 0x4fe88);
                                                  }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_00050ac0 +
                                                                                  0x4fe9c));
                                                    if (iVar6 == 0) {
                                                      FUN_0004d474();
                                                      kill_pidfile_s(DAT_00050ac4 + 0x4feb8,0xc);
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_00050ac8 +
                                                                                    0x4fecc));
                                                      if (iVar6 == 0) {
                                                        if ((uVar22 & 1) != 0) {
                                                          FUN_0004d41c();
                                                        }
                                                        if ((uVar22 & 2) != 0) {
                                                          FUN_0004d0d4();
                                                        }
                                                        kill_pidfile_s(DAT_00050acc + 0x4fefc,0xc);
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_00050ad0
                                                                                      + 0x4ff10));
                                                        if (iVar6 == 0) {
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_0004be74();
                                                          }
                                                          if ((uVar22 & 2) != 0) {
                                                            FUN_0004bdf8();
                                                          }
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar5,(char *)(
                                                  DAT_00050ad4 + 0x4ff44));
                                                  if (iVar6 == 0) {
                                                    if ((uVar22 & 1) != 0) {
                                                      FUN_0004aaa0();
                                                    }
                                                    if ((uVar22 & 2) != 0) {
                                                      FUN_0004aa58();
                                                    }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_00050ad8 +
                                                                                  0x4ff78));
                                                    if (iVar6 == 0) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_0004ab80();
                                                      }
                                                      uVar4 = nvram_get_int(DAT_00050adc + 0x4ff98);
                                                      cprintf(DAT_00050ae4 + 0x4ffb0,
                                                              DAT_00050ae0 + 0x4ffa4,uVar4);
                                                      kill_pidfile_s(DAT_00050ae8 + 0x4ffc0,10);
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_00039998();
                                                        sleep(1);
                                                        FUN_0004aca4();
                                                        FUN_0004ad8c();
                                                        FUN_0004ae74();
                                                        FUN_0004abbc();
                                                        FUN_0004af7c();
                                                        FUN_0004aadc();
                                                      }
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_00050aec +
                                                                                    0x50004));
                                                      if (iVar6 == 0) {
                                                        if (local_11a0[1] != (char *)0x0) {
                                                          iVar24 = atoi(local_11a0[1]);
                                                          iVar14 = DAT_00050af0 + 0x50028;
                                                          iVar6 = nvram_get_int(iVar14);
                                                          if (iVar24 != iVar6) {
                                                            iVar24 = atoi(local_11a0[1]);
                                                            nvram_set_int(iVar14,iVar24);
                                                            iVar24 = FUN_00041850(DAT_00050af8 +
                                                                                  0x50060,
                                                  DAT_00050af4 + 0x5005c);
                                                  if ((iVar24 != 0) &&
                                                     (iVar24 = atoi(local_11a0[1]), iVar24 == 0)) {
                                                    iVar24 = DAT_00050afc + 0x50084;
                                                    uVar4 = nvram_default_get(iVar24);
                                                    nvram_set(iVar24,uVar4);
                                                  }
                                                  FUN_00045078();
                                                  FUN_0004500c();
                                                  FUN_00048718();
                                                  FUN_00048408();
                                                  FUN_000b2ec8();
                                                  FUN_0004c8b8();
                                                  FUN_0004ce88();
                                                  FUN_0004cbc4();
                                                  FUN_000d0af8();
                                                  FUN_00042f44();
                                                  FUN_00039800();
                                                  FUN_00039098();
                                                  FUN_000393a0();
                                                  FUN_000390dc();
                                                  FUN_00038ffc(8);
                                                  FUN_00039660();
                                                  FUN_00045468();
                                                  FUN_00048454();
                                                  FUN_00048400();
                                                  FUN_0004c8e4();
                                                  FUN_000b2890();
                                                  FUN_000450a4();
                                                  FUN_0004501c(0);
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_00050b00 +
                                                                                  0x5010c));
                                                    if (iVar6 == 0) {
                                                      if (local_11a0[1] != (char *)0x0) {
                                                        FUN_0002d05c();
                                                      }
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_00050b04 +
                                                                                    0x50138));
                                                      if (iVar6 == 0) {
                                                        thunk_FUN_000428c0();
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_00050b08
                                                                                      + 0x50158));
                                                        if (iVar6 == 0) {
                                                          logmessage_normal(DAT_00050b10 + 0x50174,
                                                                            DAT_00050b0c + 0x50170);
                                                          FUN_000491dc();
                                                          FUN_0003ebb4();
                                                        }
                                                        else {
                                                          iVar14 = strcmp(pcVar5,(char *)(
                                                  DAT_00050b14 + 0x50190));
                                                  iVar6 = DAT_00050b20;
                                                  if (iVar14 == 0) {
                                                    logmessage_normal(DAT_00050b1c + 0x501b0,
                                                                      DAT_00050b18 + 0x501a8);
                                                    rename((char *)(DAT_00050b28 + 0x501c8),
                                                           (char *)(DAT_00050b24 + 0x501c4));
                                                    FUN_0003fbdc();
                                                    iVar24 = nvram_get(iVar6 + 0x501c0);
                                                    if ((iVar24 == 0) ||
                                                       (iVar24 = nvram_get_int(iVar6 + 0x501c0),
                                                       iVar24 == 1)) {
                                                      FUN_00047294();
                                                    }
                                                    FUN_00048904();
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_00050b2c +
                                                                                  0x5020c));
                                                    if ((iVar6 == 0) ||
                                                       (iVar6 = strcmp(pcVar5,(char *)(DAT_00050b30
                                                                                      + 0x50224)),
                                                       iVar6 == 0)) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_000b3dec();
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_000b30bc();
                                                        uVar4 = wan_primary_ifunit();
                                                        FUN_0005bf54(uVar4,0);
                                                      }
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_00050b34 +
                                                                                    0x50264));
                                                      if (iVar6 == 0) {
                                                        if ((uVar22 & 1) != 0) {
                                                          FUN_00049cf0();
                                                        }
                                                        if ((uVar22 & 2) != 0) {
                                                          FUN_00049ae4();
                                                        }
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_00050b38
                                                                                      + 0x50298));
                                                        if (iVar6 == 0) {
                                                          FUN_000b9744();
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar5,(char *)(
                                                  DAT_00050b3c + 0x502b8));
                                                  if (iVar6 == 0) {
                                                    if (local_11a0[1] == (char *)0x0) {
                                                      puts((char *)(DAT_00050b40 + 0x502e0));
                                                    }
                                                    else {
                                                      FUN_000b8480();
                                                    }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_00050b44 +
                                                                                  0x502f4));
                                                    if (iVar6 == 0) {
                                                      cprintf(DAT_00050b4c + 0x50314,
                                                              DAT_00050b48 + 0x50310,local_11a0[1]);
                                                      if (local_11a0[1] != (char *)0x0) {
                                                        system(local_11a0[1]);
                                                      }
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_00050b50 +
                                                                                    0x50338));
                                                      if (iVar6 != 0) {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_00050b54
                                                                                      + 0x50350));
                                                        if (iVar6 == 0) {
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_00049488();
                                                          }
                                                          if ((uVar22 & 2) != 0) {
                                                            FUN_0004940c();
                                                          }
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar5,(char *)(
                                                  DAT_00050b58 + 0x50384));
                                                  if (iVar6 == 0) {
                                                    if ((uVar22 & 2) != 0) {
                                                      FUN_000450a4();
                                                    }
                                                  }
                                                  else {
                                                    iVar6 = strcmp(pcVar5,(char *)(DAT_00050b5c +
                                                                                  0x503ac));
                                                    if (iVar6 == 0) {
                                                      ppiVar3 = local_1180;
                                                      puVar21 = (undefined4 *)
                                                                (DAT_00050b60 + 0x503c4);
                                                      do {
                                                        puVar20 = puVar21;
                                                        ppiVar16 = ppiVar3;
                                                        puVar21 = puVar20 + 2;
                                                        piVar13 = (int *)puVar20[1];
                                                        *ppiVar16 = (int *)*puVar20;
                                                        ppiVar16[1] = piVar13;
                                                        ppiVar3 = ppiVar16 + 2;
                                                      } while (puVar21 !=
                                                               (undefined4 *)
                                                               (DAT_00050b60 + 0x503cc));
                                                      uVar2 = *(undefined2 *)(puVar20 + 3);
                                                      ppiVar16[2] = (int *)*puVar21;
                                                      *(undefined2 *)(ppiVar16 + 3) = uVar2;
                                                      iVar24 = atoi(local_11a0[1]);
                                                      local_11c8.s_addr = DAT_00050b64 + 0x50414;
                                                      local_11c4 = 0;
                                                      snprintf((char *)local_1180,0xe,
                                                               (char *)(DAT_00050b68 + 0x5041c),
                                                               iVar24);
                                                      if ((uVar22 & 1) != 0) {
                                                        uVar4 = FUN_000418d4(local_1180,
                                                                             DAT_00050b6c + 0x50448,
                                                                             &local_1020);
                                                        nvram_set(uVar4,DAT_00050b70 + 0x50454);
                                                        uVar4 = FUN_000418d4(local_1180,
                                                                             DAT_00050b74 + 0x50468,
                                                                             &local_1020);
                                                        nvram_set(uVar4,DAT_00050b78 + 0x50474);
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        _eval(&local_11c8,DAT_00050b7c + 0x50494,0,
                                                              auStack_11cc);
                                                      }
                                                    }
                                                    else {
                                                      iVar6 = strcmp(pcVar5,(char *)(DAT_00050b80 +
                                                                                    0x504a8));
                                                      if (iVar6 == 0) {
                                                        FUN_0004c928();
                                                      }
                                                      else {
                                                        iVar6 = strcmp(pcVar5,(char *)(DAT_00050b84
                                                                                      + 0x504c8));
                                                        if (iVar6 == 0) {
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_0004cbc4();
                                                          }
                                                          if ((uVar22 & 2) != 0) {
                                                            FUN_0004cc24();
                                                          }
                                                        }
                                                        else {
                                                          iVar6 = strcmp(pcVar5,(char *)(
                                                  DAT_00050b88 + 0x504fc));
                                                  if (iVar6 == 0) {
                                                    local_11a0[0] =
                                                         strcpy(acStack_11c0,
                                                                (char *)(DAT_00050b8c + 0x50518));
                                                    FUN_0004a934(iVar24,local_11a0);
                                                  }
                                                  else {
                                                    iVar24 = strcmp(pcVar5,(char *)(DAT_00050b90 +
                                                                                   0x50540));
                                                    if (iVar24 == 0) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_0004ae38();
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_0004ad8c();
                                                      }
                                                    }
                                                    else {
                                                      iVar24 = strcmp(pcVar5,(char *)(DAT_00050b94 +
                                                                                     0x50574));
                                                      if (iVar24 == 0) {
                                                        if ((uVar22 & 1) != 0) {
                                                          FUN_0004af40();
                                                        }
                                                        if ((uVar22 & 2) != 0) {
                                                          FUN_0004ae74();
                                                        }
                                                      }
                                                      else {
                                                        iVar24 = strcmp(pcVar5,(char *)(DAT_00050b98
                                                                                       + 0x505a8));
                                                        if (iVar24 == 0) {
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_0004ad50();
                                                          }
                                                          if ((uVar22 & 2) != 0) {
                                                            FUN_0004aca4();
                                                          }
                                                        }
                                                        else {
                                                          iVar24 = strcmp(pcVar5,(char *)(
                                                  DAT_00050b9c + 0x505dc));
                                                  if (iVar24 == 0) {
                                                    trigger_opt();
                                                  }
                                                  else {
                                                    iVar24 = strcmp(pcVar5,(char *)(DAT_00050ba0 +
                                                                                   0x505fc));
                                                    if (iVar24 == 0) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_0004ae38();
                                                        FUN_0004b028();
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_0004ad8c();
                                                        FUN_0004af7c();
                                                      }
                                                    }
                                                    else {
                                                      iVar24 = strcmp(pcVar5,(char *)(DAT_00050ba4 +
                                                                                     0x50638));
                                                      if (iVar24 == 0) {
                                                        if ((uVar22 & 1) != 0) {
                                                          FUN_0004ac68();
                                                        }
                                                        if ((uVar22 & 2) != 0) {
                                                          FUN_0004abbc();
                                                        }
                                                      }
                                                      else {
                                                        iVar24 = strcmp(pcVar5,(char *)(DAT_00050ba8
                                                                                       + 0x5066c));
                                                        if (iVar24 == 0) {
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_0004b10c();
                                                          }
                                                          if ((uVar22 & 2) != 0) {
                                                            FUN_0004b064();
                                                          }
                                                        }
                                                        else {
                                                          iVar24 = strcmp(pcVar5,(char *)(
                                                  DAT_00050bac + 0x506a0));
                                                  if (iVar24 == 0) {
                                                    if ((uVar22 & 1) != 0) {
                                                      FUN_0004b818();
                                                    }
                                                    if ((uVar22 & 2) != 0) {
                                                      FUN_0004b888();
                                                    }
                                                  }
                                                  else {
                                                    iVar24 = strcmp(pcVar5,(char *)(DAT_00050bb0 +
                                                                                   0x506d4));
                                                    if (iVar24 == 0) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_0004a724();
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        start_obd();
                                                      }
                                                    }
                                                    else {
                                                      iVar24 = strcmp(pcVar5,(char *)(DAT_00050bb4 +
                                                                                     0x50708));
                                                      if (iVar24 == 0) {
                                                        if ((uVar22 & 1) != 0) {
                                                          FUN_0004a860();
                                                        }
                                                        if ((uVar22 & 2) != 0) {
                                                          FUN_0004a7f8();
                                                        }
                                                      }
                                                      else {
                                                        iVar24 = strcmp(pcVar5,(char *)(DAT_00050bb8
                                                                                       + 0x5073c));
                                                        if (iVar24 == 0) {
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_0004c8b8();
                                                          }
                                                          if ((uVar22 & 2) != 0) {
                                                            FUN_0004c8e4();
                                                          }
                                                        }
                                                        else {
                                                          iVar24 = strcmp(pcVar5,(char *)(
                                                  DAT_00050bbc + 0x50770));
                                                  if (iVar24 == 0) {
                                                    if ((uVar22 & 1) != 0) {
                                                      FUN_0004ce88();
                                                    }
                                                    if ((uVar22 & 2) != 0) {
                                                      FUN_0004ceb4();
                                                    }
                                                  }
                                                  else {
                                                    iVar24 = strcmp(pcVar5,(char *)(DAT_00050bc0 +
                                                                                   0x507a4));
                                                    if (iVar24 == 0) {
                                                      FUN_000ceed0(0,0);
                                                    }
                                                    else {
                                                      iVar24 = strcmp(pcVar5,(char *)(DAT_00050bc4 +
                                                                                     0x507c8));
                                                      if (iVar24 == 0) {
                                                        update_sta_binding_list();
                                                      }
                                                      else {
                                                        iVar24 = strcmp(pcVar5,(char *)(DAT_00050bc8
                                                                                       + 0x507e8));
                                                        if (iVar24 == 0) {
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_0004d024();
                                                          }
                                                          if ((uVar22 & 2) != 0) {
                                                            FUN_0004cef0();
                                                          }
                                                        }
                                                        else {
                                                          iVar24 = strcmp(pcVar5,(char *)(
                                                  DAT_00050bcc + 0x5081c));
                                                  if (iVar24 != 0) {
                                                    iVar24 = strcmp(pcVar5,(char *)(DAT_00050bd0 +
                                                                                   0x50834));
                                                    if (iVar24 == 0) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_0004c1b4();
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_0004c1c4();
                                                      }
                                                    }
                                                    else {
                                                      iVar24 = strcmp(pcVar5,(char *)(DAT_00050bd4 +
                                                                                     0x50868));
                                                      if (iVar24 == 0) {
                                                        remove((char *)(DAT_00050bd8 + 0x5087c));
                                                      }
                                                      else {
                                                        iVar24 = strcmp(pcVar5,(char *)(DAT_00050bdc
                                                                                       + 0x50890));
                                                        if (iVar24 == 0) {
                                                          remove((char *)(DAT_00050be0 + 0x508a4));
                                                        }
                                                        else {
                                                          iVar24 = strcmp(pcVar5,(char *)(
                                                  DAT_00050be4 + 0x508b8));
                                                  if (iVar24 != 0) {
                                                    iVar24 = strcmp(pcVar5,(char *)(DAT_00050be8 +
                                                                                   0x508d0));
                                                    if (iVar24 == 0) {
                                                      if ((uVar22 & 1) != 0) {
                                                        FUN_00049dbc();
                                                        nvram_set(DAT_00050bf0 + 0x508f8,
                                                                  DAT_00050bec + 0x508f4);
                                                      }
                                                      if ((uVar22 & 2) != 0) {
                                                        FUN_00049de8();
                                                        nvram_set(DAT_00050bf8 + 0x50918,
                                                                  DAT_00050bf4 + 0x50914);
                                                      }
                                                    }
                                                    else {
                                                      iVar24 = strcmp(pcVar5,(char *)(DAT_00050bfc +
                                                                                     0x5092c));
                                                      if (iVar24 == 0) {
                                                        if ((uVar22 & 1) != 0) {
                                                          FUN_00049dbc();
                                                          nvram_set(DAT_00050c04 + 0x50954,
                                                                    DAT_00050c00 + 0x50950);
                                                        }
                                                        if ((uVar22 & 2) != 0) {
                                                          FUN_00049e68();
                                                          nvram_set(DAT_00050c0c + 0x50974,
                                                                    DAT_00050c08 + 0x50970);
                                                        }
                                                      }
                                                      else {
                                                        iVar24 = strcmp(pcVar5,(char *)(DAT_00050c10
                                                                                       + 0x50988));
                                                        if (iVar24 == 0) {
                                                          if ((uVar22 & 1) != 0) {
                                                            FUN_0004a604();
                                                          }
                                                          if ((uVar22 & 2) != 0) {
                                                            FUN_0004a624();
                                                          }
                                                        }
                                                        else {
                                                          fprintf((FILE *)**(undefined4 **)
                                                                            (iVar27 + DAT_00050c14),
                                                                  (char *)(DAT_00050c18 + 0x509c4),
                                                                  pcVar5);
                                                        }
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_000509c8:
    if ((local_11d0 == (char *)0x0) || (*local_11d0 == '\0')) {
      iVar17 = DAT_00050c20 + 0x50a08;
      nvram_set(DAT_00050c24 + 0x50a0c,iVar17);
      nvram_set(DAT_00050c28 + 0x50a20,iVar17);
      cprintf(DAT_00050c2c + 0x50a2c);
      return;
    }
    _Var7 = getpid();
    cprintf(DAT_00050c1c + 0x509f4,_Var7);
  } while( true );
}



===== FUN_0004d2c8 @ 0004d2c8 =====

undefined4 FUN_0004d2c8(void)

{
  int iVar1;
  
  FUN_0004a4e0();
  FUN_0004828c();
  FUN_0004a3e8();
  FUN_0004a49c();
  FUN_00048400();
  FUN_00044fb4();
  FUN_0003a190();
  FUN_0004d0d4();
  FUN_00044e24();
  FUN_00044edc();
  FUN_00044e70();
  FUN_00048058();
  FUN_0004c1c4();
  FUN_0004d034();
  FUN_00044f38();
  FUN_000480f0();
  FUN_0004c218();
  FUN_00045468();
  FUN_00049ae4();
  FUN_00038ffc(0);
  FUN_00048454();
  FUN_00045170();
  FUN_00048854();
  FUN_000481f0();
  FUN_0004823c();
  FUN_0004a624();
  FUN_0004a658();
  iVar1 = nvram_get_int(DAT_0004d3f4 + 0x4d348);
  if (iVar1 == 1) {
    FUN_0004aca4();
    FUN_0004ad8c();
    FUN_0004ae74();
    FUN_0004abbc();
    FUN_0004af7c();
    FUN_0004b064();
  }
  FUN_0004a6bc();
  start_obd();
  start_eth_obd();
  FUN_00031f1c();
  FUN_0004940c();
  FUN_000450a4();
  FUN_0004501c(1);
  FUN_000b30bc();
  iVar1 = f_exists(DAT_0004d3f8 + 0x4d398);
  if (iVar1 != 0) {
    system((char *)(DAT_0004d3fc + 0x4d3ac));
  }
  FUN_00042ec8();
  FUN_0004c834();
  FUN_0004c8e4();
  FUN_0004c928();
  FUN_00048904();
  FUN_00042880();
  FUN_0004cc24();
  FUN_0004ceb4();
  FUN_000f0498();
  FUN_0004cef0();
  FUN_0004b888();
  FUN_000b93cc(0);
  FUN_000d0b0c();
  FUN_000398b8();
  FUN_000b2890();
  return 0;
}


