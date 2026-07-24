
===== ENTRY 00033818 =====
===== FUNCTION FUN_00033818 @ 00033818 =====

void FUN_00033818(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  undefined2 uVar13;
  bool bVar14;
  in_addr iVar15;
  in_addr iVar16;
  char *pcVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  undefined4 uVar23;
  SSL_METHOD *meth;
  SSL_CTX *pSVar24;
  int iVar25;
  SSL *s;
  size_t sVar26;
  void *pvVar27;
  char *pcVar28;
  undefined4 uVar29;
  in_addr_t iVar30;
  FILE *pFVar31;
  sockaddr *__addr;
  bool bVar32;
  uint *puVar33;
  uint uVar34;
  uint *puVar35;
  uint *puVar36;
  uint *puVar37;
  uint uVar38;
  uint *puVar39;
  uint *puVar40;
  int *piVar41;
  int iVar42;
  uint uVar43;
  uint *puVar44;
  int *piVar45;
  char *pcVar46;
  char *pcVar47;
  char *pcVar48;
  __fd_mask *p_Var49;
  int iVar50;
  bool bVar51;
  undefined4 *puVar52;
  char *pcVar53;
  int iVar54;
  uint *puVar55;
  int iVar56;
  size_t sVar57;
  uint *puVar58;
  int iVar59;
  char *pcVar60;
  uint *puVar61;
  bool bVar62;
  uint *puVar63;
  uint *puVar64;
  bool bVar65;
  char *pcStack_20bb0;
  int iStack_20bac;
  char *pcStack_20ba8;
  undefined1 *puStack_20ba4;
  int iStack_20ba0;
  FILE *pFStack_20b80;
  char *pcStack_20b74;
  char *pcStack_20b6c;
  socklen_t sStack_20b00;
  uint *puStack_20afc;
  undefined4 uStack_20af8;
  int iStack_20af4;
  uint uStack_20af0;
  timeval tStack_20aec;
  timeval tStack_20ae4;
  uint uStack_20adc;
  uint uStack_20ad8;
  int iStack_20ad4;
  int iStack_20ad0;
  int iStack_20acc;
  undefined1 auStack_20ac8 [4];
  in_addr aiStack_20ac4 [3];
  undefined1 auStack_20ab8 [8];
  undefined1 auStack_20ab0 [4];
  undefined1 auStack_20aac [4];
  uint auStack_20aa8 [5];
  undefined1 auStack_20a94 [12];
  undefined4 auStack_20a88 [4];
  sockaddr sStack_20a78;
  undefined4 uStack_20a68;
  undefined4 uStack_20a64;
  int aiStack_20a5c [4];
  in_addr iStack_20a4c;
  uint uStack_20a48;
  char acStack_20a44 [4];
  undefined4 uStack_20a40;
  undefined4 uStack_20a3c;
  fd_set fStack_20a38;
  fd_set fStack_209b8;
  char acStack_20938 [31];
  undefined1 uStack_20919;
  char acStack_20918 [31];
  undefined1 uStack_208f9;
  char acStack_208f8 [31];
  undefined1 uStack_208d9;
  char acStack_208d8 [31];
  undefined1 uStack_208b9;
  char acStack_208b8 [31];
  undefined1 uStack_20899;
  char acStack_20898 [31];
  undefined1 uStack_20879;
  char acStack_20878 [45];
  undefined1 uStack_2084b;
  undefined1 uStack_2084a;
  char acStack_20848 [255];
  undefined1 uStack_20749;
  char acStack_20748 [284];
  undefined4 uStack_2062c;
  undefined1 auStack_20628 [508];
  char acStack_2042c [512];
  char acStack_2022c [9];
  char acStack_20223 [502];
  undefined1 uStack_2002d;
  uint auStack_2002c [4];
  uint auStack_2001c [16381];
  char acStack_10028 [7];
  char acStack_10021 [3];
  char acStack_1001e [21];
  undefined1 uStack_10009;
  undefined1 local_ffff;
  undefined1 local_fe29;
  int local_24;
  
  iVar50 = DAT_00034730 + 0x33838;
  local_24 = **(int **)(iVar50 + DAT_00034734);
  FUN_0003d7b4();
  pcVar17 = (char *)acosNvramConfig_get(DAT_00034738 + 0x33860);
  iVar18 = strcmp(pcVar17,(char *)(DAT_0003473c + 0x3386c));
  **(uint **)(iVar50 + DAT_00034740) = (uint)(iVar18 == 0);
  FUN_000585ac();
  FUN_00058cc8();
  uStack_20af0 = 1;
  tStack_20aec.tv_sec = 1;
  uVar19 = socket(2,1,0);
  puVar35 = *(uint **)(iVar50 + DAT_00034744);
  if (uVar19 == 0xffffffff) {
    pcVar17 = (char *)(DAT_0003474c + 0x338e0);
    pFVar31 = (FILE *)**(undefined4 **)(iVar50 + DAT_00034748);
LAB_00033a5c:
    fputs(pcVar17,pFVar31);
  }
  else {
    iVar18 = setsockopt(uVar19,1,2,&tStack_20aec,4);
    if (iVar18 < 0) {
      fputs((char *)(DAT_00034750 + 0x33918),(FILE *)**(undefined4 **)(iVar50 + DAT_00034748));
    }
    memset((sockaddr *)&fStack_20a38,0,0x10);
    fStack_20a38.fds_bits[0]._0_2_ = 2;
    uVar13 = (undefined2)DAT_00034754;
    fStack_20a38.fds_bits[0]._2_2_ = uVar13;
    pcVar17 = (char *)nvram_get(DAT_00034758 + 0x33944);
    if (pcVar17 == (char *)0x0) {
LAB_00033968:
      pcVar17 = (char *)acosNvramConfig_get(DAT_00034760 + 0x33974);
      fStack_20a38.fds_bits[1] = inet_addr(pcVar17);
    }
    else {
      iVar18 = strcmp(pcVar17,(char *)(DAT_0003475c + 0x33960));
      fStack_20a38.fds_bits[1] = 0;
      if (iVar18 != 0) goto LAB_00033968;
    }
    iVar18 = bind(uVar19,(sockaddr *)&fStack_20a38,0x10);
    if (iVar18 == -1) {
      puVar52 = *(undefined4 **)(iVar50 + DAT_00034748);
      pFVar31 = (FILE *)*puVar52;
      pcVar17 = inet_ntoa((in_addr)fStack_20a38.fds_bits[1]);
      fprintf(pFVar31,(char *)(DAT_00034764 + 0x339b8),pcVar17,0x24e3);
      pFVar31 = (FILE *)*puVar52;
      piVar41 = __errno_location();
      pcVar17 = strerror(*piVar41);
      fprintf(pFVar31,(char *)(DAT_00034768 + 0x339dc),pcVar17);
    }
    else {
      pcVar17 = inet_ntoa((in_addr)fStack_20a38.fds_bits[1]);
      printf((char *)(DAT_00038130 + 0x37f08),pcVar17,0x24e3);
    }
    if (0 < (int)uVar19) {
      uVar21 = fcntl(uVar19,1);
      fcntl(uVar19,2,uVar21 | 1);
    }
    iVar18 = acosNvramConfig_match(DAT_00034770 + 0x33a1c,DAT_0003476c + 0x33a18);
    if (iVar18 == 0) {
      iVar20 = DAT_00034778 + 0x33a74;
      iVar18 = acosNvramConfig_match(iVar20,DAT_0003477c + 0x33a78);
      if (((iVar18 == 0) &&
          (iVar18 = acosNvramConfig_match(iVar20,DAT_00038134 + 0x37f1c), iVar18 == 0)) &&
         (pcVar17 = (char *)acosNvramConfig_get(DAT_00038138 + 0x37f30), *pcVar17 != '\0'))
      goto LAB_00033a24;
    }
    else {
LAB_00033a24:
      tStack_20ae4.tv_sec = 1;
      uVar21 = socket(10,1,0);
      if (uVar21 == 0xffffffff) {
        pcVar17 = (char *)(DAT_00034774 + 0x33a5c);
        pFVar31 = (FILE *)**(undefined4 **)(iVar50 + DAT_00034748);
        goto LAB_00033a5c;
      }
      iVar18 = setsockopt(uVar21,1,2,&tStack_20ae4,4);
      if (iVar18 < 0) {
        fputs((char *)(DAT_00038140 + 0x37f74),(FILE *)**(undefined4 **)(iVar50 + DAT_0003813c));
      }
      uStack_20adc = 1;
      iVar18 = setsockopt(uVar21,0x29,0x1a,&uStack_20adc,4);
      if (iVar18 == -1) {
        fputs((char *)(DAT_00038144 + 0x37fb8),(FILE *)**(undefined4 **)(iVar50 + DAT_0003813c));
      }
      else {
        printf((char *)(DAT_00038148 + 0x37fcc));
      }
      memset((sockaddr *)&fStack_209b8,0,0x1c);
      fStack_209b8.fds_bits[0] = CONCAT22(uVar13,10);
      p_Var49 = *(__fd_mask **)(iVar50 + DAT_0003814c);
      fStack_209b8.fds_bits[2] = *p_Var49;
      fStack_209b8.fds_bits[3] = p_Var49[1];
      fStack_209b8.fds_bits[4] = p_Var49[2];
      fStack_209b8.fds_bits[5] = p_Var49[3];
      iVar18 = bind(uVar21,(sockaddr *)&fStack_209b8,0x1c);
      if (iVar18 == -1) {
        puVar52 = *(undefined4 **)(iVar50 + DAT_0003813c);
        fprintf((FILE *)*puVar52,(char *)(DAT_00038150 + 0x3802c),0x24e3);
        pFVar31 = (FILE *)*puVar52;
        piVar41 = __errno_location();
        pcVar17 = strerror(*piVar41);
        fprintf(pFVar31,(char *)(DAT_00038154 + 0x3804c),pcVar17);
        close(uVar21);
      }
      else {
        printf((char *)(DAT_00038158 + 0x38074),0x39d,0x24e3);
        if (0 < (int)uVar21) {
          uVar38 = fcntl(uVar21,1);
          fcntl(uVar21,2,uVar38 | 1);
          *puVar35 = uVar21;
        }
      }
    }
  }
  puVar63 = *(uint **)(iVar50 + DAT_00034a18);
  *puVar63 = uVar19;
  uVar19 = FUN_0002a580(0x50);
  iVar20 = DAT_00034964;
  iVar18 = DAT_00034780;
  puVar58 = *(uint **)(iVar50 + DAT_0003492c);
  *puVar58 = 0xffffffff;
  puVar55 = *(uint **)(iVar50 + iVar20);
  *puVar55 = 0xffffffff;
  pcVar17 = (char *)acosNvramConfig_get(iVar18 + 0x33ac0);
  iVar18 = strcmp(pcVar17,(char *)(DAT_00034784 + 0x33ad0));
  if (iVar18 == 0) {
    pcVar17 = (char *)acosNvramConfig_get(DAT_00034788 + 0x33af4);
    iVar18 = atoi(pcVar17);
    if (iVar18 == 0x50) {
      *puVar58 = 0xffffffff;
    }
    else {
      pcVar17 = (char *)acosNvramConfig_get(DAT_0003478c + 0x33b18);
      iVar20 = strcmp(pcVar17,(char *)(DAT_00034790 + 0x33b24));
      if (iVar20 != 0) {
        uVar21 = FUN_0002a760(iVar18);
        *puVar58 = uVar21;
        iVar20 = listen(uVar21,10);
        if (iVar20 == -1) {
          fputs((char *)(DAT_00034794 + 0x33b60),(FILE *)**(undefined4 **)(iVar50 + DAT_00034748));
        }
        agApi_setDeviceListenPort(2,iVar18,1);
      }
    }
    iVar59 = DAT_00034798 + 0x33b84;
    iVar20 = acosNvramConfig_match(iVar59,DAT_0003479c + 0x33b88);
    if ((iVar20 == 0) &&
       (iVar20 = acosNvramConfig_match(iVar59,DAT_000347a0 + 0x33ba4), iVar20 == 0)) {
      uVar21 = FUN_0002a580(iVar18);
      *puVar55 = uVar21;
      iVar20 = listen(uVar21,5);
      if (iVar20 == -1) {
        fputs((char *)(DAT_000347a4 + 0x33be0),(FILE *)**(undefined4 **)(iVar50 + DAT_00034748));
      }
      agApi_setDeviceListenPort(2,iVar18,1);
      agApi_ipv6_set_listen_port(1,0,6,iVar18);
    }
  }
  else {
    iVar18 = 0;
  }
  pcVar17 = (char *)acosNvramConfig_get(DAT_000347a8 + 0x33c18);
  iVar20 = strcmp(pcVar17,(char *)(DAT_000347ac + 0x33c24));
  puVar36 = *(uint **)(iVar50 + DAT_00034a14);
  if (((iVar20 == 0) && (iVar20 = is_russian_case(), iVar20 != 0)) && (iVar18 != 0x50)) {
    uVar21 = FUN_0002a760(iVar18 + 0x10000);
    *puVar36 = uVar21;
    iVar18 = listen(uVar21,10);
    if (iVar18 == -1) {
      fputs((char *)(DAT_000347b0 + 0x33c80),(FILE *)**(undefined4 **)(iVar50 + DAT_00034748));
    }
  }
  else {
    *puVar36 = 0xffffffff;
  }
  setsockopt(uVar19,1,2,&uStack_20af0,4);
  iVar18 = listen(uVar19,10);
  if (iVar18 == -1) {
    fputs((char *)(DAT_000347b4 + 0x33cd8),(FILE *)**(undefined4 **)(iVar50 + DAT_00034748));
LAB_00034234:
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if ((*puVar63 != 0xffffffff) && (iVar18 = listen(*puVar63,10), iVar18 == -1)) {
    fputs((char *)(DAT_000347b8 + 0x33d14),(FILE *)**(undefined4 **)(iVar50 + DAT_00034748));
  }
  if ((*puVar35 != 0xffffffff) && (iVar18 = listen(*puVar35,10), iVar18 == -1)) {
    fputs((char *)(DAT_000347bc + 0x33d4c),(FILE *)**(undefined4 **)(iVar50 + DAT_00034748));
  }
  pcVar17 = (char *)acosNvramConfig_get(DAT_000347c0 + 0x33d5c);
  iVar18 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000347c4 + 0x33d70);
  iVar20 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000347c8 + 0x33d84);
  iVar59 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000347cc + 0x33d98);
  iVar22 = atoi(pcVar17);
  puVar37 = *(uint **)(iVar50 + DAT_00034a1c);
  if ((iVar18 == 0x50) || (iVar59 == 0 || iVar20 != 0 && iVar18 == iVar22)) {
    *puVar37 = 0xffffffff;
  }
  else {
    pcVar17 = (char *)acosNvramConfig_get(DAT_000347d0 + 0x33de0);
    iVar20 = strcmp(pcVar17,(char *)(DAT_000347d4 + 0x33dec));
    if (iVar20 != 0) {
      uVar21 = FUN_0002a760(iVar18);
      *puVar37 = uVar21;
      iVar20 = listen(uVar21,10);
      if (iVar20 == -1) {
        fputs((char *)(DAT_000347d8 + 0x33e28),(FILE *)**(undefined4 **)(iVar50 + DAT_00034748));
      }
    }
  }
  iVar20 = acosNvramConfig_match(DAT_000347e0 + 0x33e50,DAT_000347dc + 0x33e4c);
  agApi_setDeviceListenPort(6,iVar18,iVar20 != 0);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000347e4 + 0x33e70);
  iVar20 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000347e8 + 0x33e84);
  iVar18 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000347ec + 0x33e98);
  iVar59 = atoi(pcVar17);
  iVar22 = acosNvramConfig_match(DAT_000347f4 + 0x33eb4,DAT_000347f0 + 0x33ea8);
  if (iVar22 == 0) {
    agApi_setDeviceListenPort(7,iVar20,0);
    agApi_setDeviceListenPort(8,iVar18,0);
  }
  else {
    agApi_setDeviceListenPort(8,iVar18,0);
    agApi_setDeviceListenPort(7,iVar20,1);
    if (iVar20 <= iVar59 && iVar18 <= iVar20) {
      iVar59 = iVar59 - iVar18;
      iVar18 = iVar20 + 1;
      iVar59 = iVar59 + iVar18;
    }
    agApi_setDeviceListenPortRange(8,iVar18,iVar59);
  }
  iVar20 = DAT_00034800;
  iVar18 = DAT_000347fc;
  uVar23 = acosNvramConfig_get(DAT_000347f8 + 0x33f4c);
  strlcpy(acStack_10028,uVar23,0x28);
  agApi_natSetReadyshareName(acStack_10028);
  FUN_00111ab8(acStack_10028);
  iVar22 = DAT_00034808 + 0x33f98;
  iVar59 = DAT_0003480c + 0x33f9c;
  **(uint **)(iVar50 + DAT_00034804) = uVar19;
  acosNvramConfig_set(iVar59,iVar22);
  pcVar17 = (char *)acosNvramConfig_get(DAT_00034810 + 0x33fac);
  strncpy(acStack_20938,pcVar17,0x1f);
  uStack_20919 = 0;
  strncpy(acStack_20918,acStack_20938,0x1f);
  uStack_208f9 = 0;
  iVar59 = acosNvramConfig_match(iVar20 + 0x33f60,(char *)(iVar18 + 0x33f5c));
  if (iVar59 == 0) {
    pcVar17 = (char *)(DAT_00034814 + 0x34028);
    iVar18 = acosNvramConfig_match(iVar20 + 0x33f60,pcVar17);
    if (iVar18 == 0) {
      pcVar17 = (char *)acosNvramConfig_get(DAT_00034818 + 0x34058);
      strncpy(acStack_20878,pcVar17,0x2d);
      uStack_2084b = 0;
    }
    else {
      strncpy(acStack_20878,pcVar17,0x2e);
      uStack_2084a = 0;
    }
  }
  else {
    strncpy(acStack_20878,(char *)(iVar18 + 0x33f5c),0x2e);
    uStack_2084a = 0;
  }
  iVar18 = is_russian_case();
  if (iVar18 != 0) {
    iVar20 = DAT_0003481c + 0x34088;
    iVar18 = acosNvramConfig_match(iVar20,DAT_00034820 + 0x3408c);
    if (((iVar18 != 0) ||
        (iVar18 = acosNvramConfig_match(iVar20,DAT_00034830 + 0x340e0), iVar18 != 0)) ||
       (iVar18 = acosNvramConfig_match(iVar20,DAT_00034834 + 0x340f8), iVar18 != 0)) {
      iVar20 = DAT_00034824 + 0x340ac;
      iVar18 = acosNvramConfig_match(iVar20,DAT_00034828 + 0x340b0);
      if (iVar18 == 0) {
        iVar18 = acosNvramConfig_match(iVar20,DAT_00034838 + 0x34114);
        if (iVar18 == 0) {
          iVar18 = DAT_00034840 + 0x34134;
        }
        else {
          iVar18 = DAT_0003483c + 0x3412c;
        }
      }
      else {
        iVar18 = DAT_0003482c + 0x340d0;
      }
      acosNvramConfig_read(iVar18,acStack_208f8,0x20);
      strncpy(acStack_208d8,acStack_208f8,0x1f);
      uStack_208b9 = 0;
    }
  }
  iVar18 = DAT_00034844;
  OPENSSL_init_ssl(0,0,0);
  OPENSSL_init_ssl(DAT_00034848,0,0);
  OPENSSL_init_ssl(0,0,0);
  meth = (SSL_METHOD *)TLS_server_method();
  pSVar24 = SSL_CTX_new(meth);
  *(SSL_CTX **)(iVar18 + 0x34e4c) = pSVar24;
  SSL_CTX_set_options(pSVar24,0x2000000);
  FUN_0003d7b4();
  if (**(char **)(iVar18 + 0x34e50) != '\0') {
    iVar18 = SSL_CTX_use_certificate_file
                       (*(SSL_CTX **)(iVar18 + 0x34e4c),*(char **)(iVar18 + 0x34e50),1);
    if (iVar18 == 0) {
      puts((char *)(DAT_0003484c + 0x341cc));
    }
    iVar18 = SSL_CTX_use_PrivateKey_file
                       (*(SSL_CTX **)(DAT_00034850 + 0x34ea0),*(char **)(DAT_00034850 + 0x34ea8),1);
    if (iVar18 == 0) {
      puts((char *)(DAT_00034854 + 0x341f8));
    }
    FUN_00148fc4();
    FUN_00148f60();
    iVar18 = SSL_CTX_check_private_key(*(SSL_CTX **)(DAT_00034858 + 0x34ed0));
    if (iVar18 == 0) {
      ERR_print_errors_fp((FILE *)**(undefined4 **)(iVar50 + DAT_00034748));
      puts((char *)(DAT_0003485c + 0x34234));
      goto LAB_00034234;
    }
  }
  iVar18 = DAT_00034860;
  SSL_CTX_ctrl(*(SSL_CTX **)(DAT_00034860 + 0x34f18),0x21,2,(void *)0x0);
  SSL_CTX_set_cipher_list(*(SSL_CTX **)(iVar18 + 0x34f18),(char *)(DAT_00034864 + 0x3426c));
  pcVar17 = (char *)acosNvramConfig_get(DAT_00034868 + 0x34278);
  strncpy(acStack_208b8,pcVar17,0x1f);
  uStack_20899 = 0;
  strncpy(acStack_20898,acStack_208b8,0x1f);
  uStack_20879 = 0;
  pFVar31 = fopen64((char *)(DAT_00034870 + 0x342c4),(char *)(DAT_0003486c + 0x342bc));
  if (pFVar31 != (FILE *)0x0) {
    fread(*(void **)(iVar50 + DAT_00034874),4,1,pFVar31);
    fread(*(void **)(iVar50 + DAT_00034878),4,1,pFVar31);
    fclose(pFVar31);
  }
  iVar20 = DAT_00034884;
  iVar18 = DAT_0003487c;
  puts((char *)(DAT_00034880 + 0x34334));
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x34330);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x34334);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34338);
  fStack_209b8.fds_bits[3] = *(__fd_mask *)(iVar18 + 0x3433c);
  iVar20 = iVar20 + 0x34344;
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x34340);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x34344);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34348);
  fStack_209b8.fds_bits[3] = *(__fd_mask *)(iVar18 + 0x3434c);
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x34350);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x34354);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34358);
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x3435c);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x34360);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34364);
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  system((char *)(DAT_00034888 + 0x343d4));
  FUN_0003d7b4();
  uVar21 = uVar19 + 0x1f;
  if (-1 < (int)uVar19) {
    uVar21 = uVar19;
  }
  iVar18 = (int)uVar21 >> 5;
  uVar21 = uVar19 & 0x8000001f;
  if ((int)uVar21 < 0) {
    uVar21 = ~(~((uVar21 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  uVar21 = 1 << (uVar21 & 0xff);
  iVar20 = DAT_0003488c + 0x34420;
  iVar59 = DAT_00034890 + 0x345d2;
  iVar22 = DAT_00034894 + 0x345e6;
LAB_00034448:
  do {
    do {
      while( true ) {
        uVar38 = *puVar58;
        if ((int)*puVar58 < (int)*puVar55) {
          uVar38 = *puVar55;
        }
        if ((int)uVar38 < (int)*puVar63) {
          uVar38 = *puVar63;
        }
        if ((int)uVar38 < (int)*puVar35) {
          uVar38 = *puVar35;
        }
        uVar43 = *puVar36;
        if ((int)*puVar36 <= (int)uVar38) {
          uVar43 = uVar38;
        }
        pcVar17 = (char *)acosNvramConfig_get(iVar20);
        strncpy(acStack_20918,pcVar17,0x1f);
        uStack_208f9 = 0;
        iVar25 = strcmp(acStack_20918,acStack_20938);
        if ((iVar25 == 0) ||
           (iVar25 = strcmp(acStack_20918,(char *)(DAT_00034898 + 0x344d8)), iVar25 == 0)) {
          bVar65 = false;
        }
        else {
          bVar65 = true;
          strncpy(acStack_20938,acStack_20918,0x1f);
          uStack_20919 = 0;
        }
        iVar56 = DAT_0003489c + 0x34510;
        iVar25 = acosNvramConfig_match(iVar56,DAT_000348a0 + 0x34514);
        if ((iVar25 == 0) &&
           (iVar25 = acosNvramConfig_match(iVar56,DAT_000348a8 + 0x34570), iVar25 == 0)) {
          iVar56 = DAT_000348ac + 0x34588;
          iVar25 = acosNvramConfig_match(iVar56,acStack_20878);
          if (iVar25 == 0) {
            bVar65 = true;
            pcVar17 = (char *)acosNvramConfig_get(iVar56);
            strncpy(acStack_20878,pcVar17,0x2e);
            uStack_2084a = 0;
          }
          iVar25 = acosNvramConfig_match(DAT_000348b4 + 0x345c8,DAT_000348b0 + 0x345c4);
          if (((iVar25 != 0) &&
              (iVar25 = acosNvramConfig_match(DAT_000348bc + 0x345e4,DAT_000348b8 + 0x345e0),
              iVar25 == 0)) && (*puVar55 == 0xffffffff)) {
            bVar65 = true;
          }
        }
        else {
          iVar56 = DAT_000348a4 + 0x34530;
          iVar25 = acosNvramConfig_match(iVar56,acStack_20878);
          if (iVar25 == 0) {
            bVar65 = true;
            pcVar17 = (char *)acosNvramConfig_get(iVar56);
            strncpy(acStack_20878,pcVar17,0x2e);
            uStack_2084a = 0;
          }
        }
        iVar25 = acosNvramConfig_match(DAT_000348c4 + 0x34610,DAT_000348c0 + 0x3460c);
        if (iVar25 != 0) {
          pcVar17 = (char *)acosNvramConfig_get(DAT_000348c8 + 0x3462c);
          strncpy(acStack_20898,pcVar17,0x1f);
          uStack_20879 = 0;
          iVar25 = strcmp(acStack_208b8,acStack_20898);
          if (iVar25 != 0) {
            bVar65 = true;
            strncpy(acStack_208b8,acStack_20898,0x1f);
            uStack_20899 = 0;
          }
        }
        iVar25 = is_russian_case();
        if (iVar25 != 0) {
          iVar56 = DAT_000348cc + 0x34688;
          iVar25 = acosNvramConfig_match(iVar56,DAT_000348d0 + 0x3468c);
          if (((iVar25 != 0) ||
              (iVar25 = acosNvramConfig_match(iVar56,DAT_000348e0 + 0x346e0), iVar25 != 0)) ||
             (iVar25 = acosNvramConfig_match(iVar56,DAT_000348e4 + 0x346f8), iVar25 != 0)) {
            iVar56 = DAT_000348d4 + 0x346ac;
            iVar25 = acosNvramConfig_match(iVar56,DAT_000348d8 + 0x346b0);
            if (iVar25 == 0) {
              iVar25 = acosNvramConfig_match(iVar56,DAT_000348e8 + 0x34714);
              if (iVar25 == 0) {
                iVar25 = DAT_000348f0 + 0x34a48;
              }
              else {
                iVar25 = (int)&DAT_00034730 + DAT_000348ec;
              }
            }
            else {
              iVar25 = DAT_000348dc + 0x346d0;
            }
            acosNvramConfig_read(iVar25,acStack_208d8,0x20);
            iVar25 = strcmp(acStack_208d8,acStack_208f8);
            if ((iVar25 != 0) &&
               (iVar25 = strcmp(acStack_208d8,(char *)(DAT_000348f4 + 0x34a70)), iVar25 != 0)) {
              bVar65 = true;
              strncpy(acStack_208f8,acStack_208d8,0x1f);
              uStack_208d9 = 0;
            }
          }
        }
        iVar25 = FUN_0010ff68();
        if (iVar25 != 0) {
          FUN_0002aa68();
        }
        if (bVar65) {
          FUN_0002aa68();
          FUN_0002ac04();
          FUN_00119e20(2);
        }
        if ((int)uVar43 < (int)*puVar37) {
          uVar43 = *puVar37;
        }
        if ((int)uVar43 <= (int)uVar19) {
          uVar43 = uVar19;
        }
        iVar25 = acosNvramConfig_match(DAT_000348fc + 0x34ad8,DAT_000348f8 + 0x34ad4);
        if (iVar25 != 0) {
          FUN_0011b1e4();
        }
        tStack_20aec.tv_sec = 1;
        iVar25 = 0;
        tStack_20aec.tv_usec = 0;
        puVar33 = *(uint **)(iVar50 + DAT_00034900);
        *puVar33 = 0;
        do {
          pcVar17 = ((sockaddr *)&fStack_20a38)->sa_data + iVar25 * 4 + -2;
          pcVar17[0] = '\0';
          pcVar17[1] = '\0';
          pcVar17[2] = '\0';
          pcVar17[3] = '\0';
          iVar25 = iVar25 + 1;
        } while (iVar25 != 0x20);
        fStack_20a38.fds_bits[iVar18] = fStack_20a38.fds_bits[iVar18] | uVar21;
        uVar34 = *puVar63;
        uVar38 = uVar34 + 0x1f;
        if (-1 < (int)uVar34) {
          uVar38 = uVar34;
        }
        uVar34 = uVar34 & 0x8000001f;
        if ((int)uVar34 < 0) {
          uVar34 = ~(~((uVar34 - 1) * 0x8000000) >> 0x1b) + 1;
        }
        fStack_20a38.fds_bits[(int)uVar38 >> 5] =
             fStack_20a38.fds_bits[(int)uVar38 >> 5] | 1 << (uVar34 & 0xff);
        uVar38 = *puVar35;
        if (uVar38 != 0xffffffff) {
          uVar34 = uVar38 + 0x1f;
          if (-1 < (int)uVar38) {
            uVar34 = uVar38;
          }
          uVar38 = uVar38 & 0x8000001f;
          bVar65 = (int)uVar38 < 0;
          if (bVar65) {
            uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b);
          }
          if (bVar65) {
            uVar38 = uVar38 + 1;
          }
          fStack_20a38.fds_bits[(int)uVar34 >> 5] =
               fStack_20a38.fds_bits[(int)uVar34 >> 5] | 1 << (uVar38 & 0xff);
        }
        if (**(int **)(iVar50 + DAT_00034904) == 1) {
          FUN_0002ac04();
        }
        uVar38 = *puVar58;
        if (uVar38 != 0xffffffff) {
          uVar34 = uVar38 + 0x1f;
          if (-1 < (int)uVar38) {
            uVar34 = uVar38;
          }
          uVar38 = uVar38 & 0x8000001f;
          bVar65 = (int)uVar38 < 0;
          if (bVar65) {
            uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b);
          }
          if (bVar65) {
            uVar38 = uVar38 + 1;
          }
          fStack_20a38.fds_bits[(int)uVar34 >> 5] =
               fStack_20a38.fds_bits[(int)uVar34 >> 5] | 1 << (uVar38 & 0xff);
        }
        uVar38 = *puVar36;
        if (uVar38 != 0xffffffff) {
          uVar34 = uVar38 + 0x1f;
          if (-1 < (int)uVar38) {
            uVar34 = uVar38;
          }
          uVar38 = uVar38 & 0x8000001f;
          bVar65 = (int)uVar38 < 0;
          if (bVar65) {
            uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b);
          }
          if (bVar65) {
            uVar38 = uVar38 + 1;
          }
          fStack_20a38.fds_bits[(int)uVar34 >> 5] =
               fStack_20a38.fds_bits[(int)uVar34 >> 5] | 1 << (uVar38 & 0xff);
        }
        uVar38 = *puVar55;
        if (uVar38 != 0xffffffff) {
          uVar34 = uVar38 + 0x1f;
          if (-1 < (int)uVar38) {
            uVar34 = uVar38;
          }
          uVar38 = uVar38 & 0x8000001f;
          bVar65 = (int)uVar38 < 0;
          if (bVar65) {
            uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b);
          }
          if (bVar65) {
            uVar38 = uVar38 + 1;
          }
          fStack_20a38.fds_bits[(int)uVar34 >> 5] =
               fStack_20a38.fds_bits[(int)uVar34 >> 5] | 1 << (uVar38 & 0xff);
        }
        uVar38 = *puVar37;
        if (uVar38 != 0xffffffff) {
          uVar34 = uVar38 + 0x1f;
          if (-1 < (int)uVar38) {
            uVar34 = uVar38;
          }
          uVar38 = uVar38 & 0x8000001f;
          bVar65 = (int)uVar38 < 0;
          if (bVar65) {
            uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b);
          }
          if (bVar65) {
            uVar38 = uVar38 + 1;
          }
          fStack_20a38.fds_bits[(int)uVar34 >> 5] =
               fStack_20a38.fds_bits[(int)uVar34 >> 5] | 1 << (uVar38 & 0xff);
        }
        iVar25 = select(uVar43 + 1,&fStack_20a38,(fd_set *)0x0,(fd_set *)0x0,&tStack_20aec);
        if (iVar25 != -1) break;
        pcVar17 = *(char **)(iVar50 + DAT_000349ec);
        snprintf(pcVar17,0x400,(char *)(DAT_00034910 + 0x34df4),iVar59);
        FUN_0002b2a8(0,pcVar17);
      }
      if (iVar25 != 0) {
        pcVar17 = *(char **)(iVar50 + DAT_000349ec);
        snprintf(pcVar17,0x400,(char *)(DAT_00034908 + 0x34dac),DAT_0003490c + 0x34f6a);
        FUN_0002b2a8(0,pcVar17);
      }
      if (((**(int **)(iVar50 + DAT_00034914) != 0) ||
          (iVar25 = acosNvramConfig_match(DAT_0003491c + 0x34e5c,DAT_00034918 + 0x34e58),
          iVar25 != 0)) && (**(int **)(iVar50 + DAT_00034984) == 0)) {
        FUN_0002b518();
      }
      if (**(int **)(iVar50 + DAT_00034920) != 0) {
        **(int **)(iVar50 + DAT_00034920) = 0;
        iVar56 = **(int **)(iVar50 + DAT_00034924);
        iVar25 = iVar56;
        if (iVar56 != 1) {
          iVar25 = iVar56 + -3;
        }
        if (iVar25 != 0 && (iVar56 != 1 && iVar56 + -3 != 1)) {
          if (iVar56 == 2) {
            FUN_0012cbe0();
          }
        }
        else if (**(int **)(iVar50 + DAT_00034928) == 1) {
          FUN_000c8f2c();
        }
        else {
          FUN_000c7350();
        }
      }
      puVar39 = *(uint **)(iVar50 + DAT_0003492c);
      if ((uVar21 & fStack_20a38.fds_bits[iVar18]) != 0) {
        pcVar17 = *(char **)(iVar50 + DAT_000349ec);
        snprintf(pcVar17,0x400,(char *)(DAT_00034930 + 0x34f0c),DAT_00034934 + 0x350ca);
        FUN_0002b2a8(0,pcVar17);
        **(uint **)(iVar50 + DAT_000349e8) = uVar19;
        bVar65 = false;
        **(undefined4 **)(iVar50 + DAT_00034978) = 0;
        **(undefined4 **)(iVar50 + DAT_00034a04) = 0;
        goto LAB_00035614;
      }
      uVar38 = **(uint **)(iVar50 + DAT_00034a18);
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar34 = uVar38 & 0x8000001f;
        bVar65 = (int)uVar34 < 0;
        if (bVar65) {
          uVar34 = uVar34 - 1;
        }
        if (bVar65) {
          uVar34 = ~(~(uVar34 << 0x1b) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar34 & 0xff)) == 0)
        goto LAB_00034fb4;
LAB_00035004:
        **(uint **)(iVar50 + DAT_000349e8) = uVar38;
        bVar65 = false;
        **(undefined4 **)(iVar50 + DAT_00034978) = 0;
        **(undefined4 **)(iVar50 + DAT_00034a04) = 1;
        goto LAB_00035614;
      }
LAB_00034fb4:
      uVar38 = **(uint **)(iVar50 + DAT_00034938);
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar34 = uVar38 & 0x8000001f;
        bVar65 = (int)uVar34 < 0;
        if (bVar65) {
          uVar34 = uVar34 - 1;
        }
        if (bVar65) {
          uVar34 = ~(~(uVar34 << 0x1b) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar34 & 0xff)) != 0)
        goto LAB_00035004;
      }
      uVar38 = *puVar39;
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar38 = uVar38 & 0x8000001f;
        if ((int)uVar38 < 0) {
          uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar38 & 0xff)) == 0)
        goto LAB_0003512c;
        pcVar17 = *(char **)(iVar50 + DAT_000349ec);
        snprintf(pcVar17,0x400,(char *)(DAT_0003493c + 0x35094),DAT_00034940 + 0x35252);
        FUN_0002b2a8(0,pcVar17);
        iVar25 = DAT_00034948;
        iVar56 = DAT_00034944 + 0x350dc;
        **(uint **)(iVar50 + DAT_000349e8) = *puVar39;
        aiStack_20a5c[0] = 1;
        **(undefined4 **)(iVar50 + DAT_00034978) = 1;
        **(undefined4 **)(iVar50 + DAT_00034a04) = 1;
        iVar25 = acosNvramConfig_match(iVar25 + 0x350e8,iVar56);
        if (iVar25 == 0) goto LAB_00035610;
        pcVar17 = (char *)acosNvramConfig_get(DAT_0003494c + 0x35118);
        iVar25 = atoi(pcVar17);
        iVar56 = DAT_00034950 + 0x3512c;
LAB_000353b0:
        pcVar17 = (char *)acosNvramConfig_get(iVar56);
        iVar56 = atoi(pcVar17);
        bVar65 = iVar25 == iVar56;
        goto LAB_00035614;
      }
LAB_0003512c:
      puVar40 = *(uint **)(iVar50 + DAT_00034a14);
      uVar38 = *puVar40;
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar38 = uVar38 & 0x8000001f;
        if ((int)uVar38 < 0) {
          uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar38 & 0xff)) == 0)
        goto LAB_000351ec;
        pcVar17 = *(char **)(iVar50 + DAT_000349ec);
        snprintf(pcVar17,0x400,(char *)(DAT_00034954 + 0x35194),DAT_00034958 + 0x35352);
        FUN_0002b2a8(0,pcVar17);
        **(uint **)(iVar50 + DAT_000349e8) = *puVar40;
        **(undefined4 **)(iVar50 + DAT_00034978) = 1;
        **(undefined4 **)(iVar50 + DAT_00034a04) = 1;
        goto LAB_00035610;
      }
LAB_000351ec:
      puVar40 = *(uint **)(iVar50 + DAT_00034a1c);
      uVar38 = *puVar40;
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar38 = uVar38 & 0x8000001f;
        if ((int)uVar38 < 0) {
          uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar38 & 0xff)) != 0) {
          pcVar17 = *(char **)(iVar50 + DAT_000349ec);
          snprintf(pcVar17,0x400,(char *)(DAT_0003495c + 0x35254),DAT_00034960 + 0x35412);
          FUN_0002b2a8(0,pcVar17);
          **(undefined4 **)(iVar50 + DAT_00034a04) = 2;
          uVar38 = *puVar40;
          **(undefined4 **)(iVar50 + DAT_00034978) = 1;
          **(uint **)(iVar50 + DAT_000349e8) = uVar38;
          bVar65 = false;
          aiStack_20a5c[0] = 0;
          goto LAB_00035614;
        }
      }
      puVar40 = *(uint **)(iVar50 + DAT_00034964);
      uVar38 = *puVar40;
      if (uVar38 != 0xffffffff) {
        uVar43 = uVar38 + 0x1f;
        if (-1 < (int)uVar38) {
          uVar43 = uVar38;
        }
        uVar38 = uVar38 & 0x8000001f;
        if ((int)uVar38 < 0) {
          uVar38 = ~(~((uVar38 - 1) * 0x8000000) >> 0x1b) + 1;
        }
        if ((fStack_20a38.fds_bits[(int)uVar43 >> 5] & 1 << (uVar38 & 0xff)) != 0) {
          pcVar17 = *(char **)(iVar50 + DAT_000349ec);
          snprintf(pcVar17,0x400,(char *)(DAT_00034968 + 0x35320),DAT_0003496c + 0x354de);
          FUN_0002b2a8(0,pcVar17);
          iVar25 = DAT_00034974;
          iVar56 = DAT_00034970 + 0x35368;
          **(uint **)(iVar50 + DAT_000349e8) = *puVar40;
          **(undefined4 **)(iVar50 + DAT_00034978) = 1;
          aiStack_20a5c[0] = 1;
          **(undefined4 **)(iVar50 + DAT_00034a04) = 1;
          iVar25 = acosNvramConfig_match(iVar25 + 0x35370,iVar56);
          if (iVar25 != 0) {
            pcVar17 = (char *)acosNvramConfig_get(DAT_0003497c + 0x353a0);
            iVar25 = atoi(pcVar17);
            iVar56 = DAT_00034980 + 0x353b4;
            goto LAB_000353b0;
          }
          goto LAB_00035610;
        }
      }
      iVar25 = FUN_0005c934();
      if (iVar25 == 1) {
        if (**(int **)(iVar50 + DAT_00034984) != 0) {
          sync();
          sleep(2);
          system((char *)(DAT_00034988 + 0x35404));
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        iVar56 = DAT_0003498c + 0x35418;
        iVar25 = acosNvramConfig_match(iVar56,DAT_00034990 + 0x3541c);
        if (iVar25 == 0) {
          iVar25 = acosNvramConfig_match(iVar56,DAT_000349a8 + 0x3548c);
          if ((iVar25 != 0) ||
             (iVar25 = acosNvramConfig_match(iVar56,DAT_000349b0 + 0x354c0), iVar25 != 0)) {
            system((char *)(DAT_000349ac + 0x354a0));
            wait_for_ppp_to_terminate();
            sleep(1);
          }
        }
        else {
          system((char *)(DAT_00034994 + 0x35434));
          wait_for_ppp_to_terminate();
          sleep(1);
          iVar25 = FUN_0004953c();
          if (iVar25 == 0) {
            acosNvramConfig_set(DAT_0003499c + 0x35460,DAT_00034998 + 0x3545c);
            acosNvramConfig_set(DAT_000349a4 + 0x35474,DAT_000349a0 + 0x35470);
            acosNvramConfig_save();
          }
        }
        if (**(int **)(iVar50 + DAT_000349b4) == 1) {
          abDisableLanEthernetPort();
        }
        iVar25 = acosNvramConfig_match(DAT_000349bc + 0x354f4,DAT_000349b8 + 0x354f0);
        if (iVar25 != 0) {
          abDisableLanEthernetPort();
          puts((char *)(DAT_000349c0 + 0x3550c));
        }
        acos_cms_del_bridge(DAT_000349c4 + 0x35518);
        system((char *)(DAT_000349c8 + 0x35524));
        goto LAB_00035610;
      }
      iVar25 = FUN_0005cbe0();
      if (iVar25 == 1) {
        pcVar17 = *(char **)(iVar50 + DAT_000349ec);
        snprintf(pcVar17,0x400,(char *)(DAT_000349cc + 0x3554c),DAT_000349d0 + 0x3570a);
        FUN_0002b2a8(0,pcVar17);
        FUN_0005cb88();
        abDisableLanEthernetPort();
        sleep(3);
        abEnableLanEthernetPort();
        goto LAB_00035610;
      }
      iVar25 = FUN_0005cd14();
      if (iVar25 == 1) {
        FUN_0005ccbc();
        wireless_configure();
        goto LAB_00035610;
      }
      iVar25 = FUN_0005ce78();
    } while (iVar25 != 1);
    FUN_0005ce20();
    pFVar31 = fopen64((char *)(DAT_000349d8 + 0x355cc),(char *)(DAT_000349d4 + 0x355c8));
    if (pFVar31 != (FILE *)0x0) {
      fprintf(pFVar31,(char *)(DAT_000349e0 + 0x355f0),DAT_000349dc + 0x35795,0x8ab);
      fclose(pFVar31);
    }
    COMMAND(DAT_000349e4 + 0x35608);
    sleep(5);
LAB_00035610:
    bVar65 = false;
LAB_00035614:
    puVar40 = *(uint **)(iVar50 + DAT_000349e8);
    uVar38 = *puVar40;
    pcVar17 = *(char **)(iVar50 + DAT_000349ec);
    if (((uVar38 == *puVar39) || (uVar38 == **(uint **)(iVar50 + DAT_00034a14))) ||
       ((uVar38 == **(uint **)(iVar50 + DAT_00034a1c) ||
        (uVar38 == **(uint **)(iVar50 + DAT_00034a18))))) {
      snprintf(pcVar17,0x400,(char *)(DAT_000349f4 + 0x356ac),DAT_000349f0 + 0x3584a);
      FUN_0002b2a8(0,pcVar17);
      __addr = (sockaddr *)auStack_20ac8;
      sStack_20b00 = 0x10;
    }
    else {
      snprintf(pcVar17,0x400,(char *)(DAT_000349fc + 0x356f4),DAT_000349f8 + 0x35892);
      FUN_0002b2a8(0,pcVar17);
      __addr = &sStack_20a78;
      sStack_20b00 = 0x1c;
    }
    uVar38 = accept(*puVar40,__addr,&sStack_20b00);
    *puVar33 = uVar38;
  } while (uVar38 == 0xffffffff);
  puStack_20afc = (uint *)0x0;
  uStack_20af8 = 0;
  pcVar53 = (char *)(DAT_00034a00 + 0x3575c);
  uStack_2062c = 0;
  memset(auStack_20628,0,0x1fc);
  acStack_2042c[0] = '\0';
  acStack_2042c[1] = '\0';
  acStack_2042c[2] = '\0';
  acStack_2042c[3] = '\0';
  memset(acStack_2042c + 4,0,0x1fc);
  snprintf(pcVar17,0x400,pcVar53,iVar22);
  FUN_0002b2a8(0,pcVar17);
  acStack_20748[0] = '\0';
  acStack_20748[1] = '\0';
  acStack_20748[2] = '\0';
  acStack_20748[3] = '\0';
  memset(acStack_20748 + 4,0,0x118);
  piVar41 = *(int **)(iVar50 + DAT_00034a04);
  if (*piVar41 != 0) {
    snprintf(pcVar17,0x400,pcVar53,iVar22);
    FUN_0002b2a8(0,pcVar17);
    s = SSL_new(*(SSL_CTX **)(DAT_00034a08 + 0x364d0));
    puVar52 = *(undefined4 **)(iVar50 + DAT_00034a0c);
    uVar38 = *puVar33;
    *puVar52 = s;
    SSL_set_fd(s,uVar38);
    fcntl(*puVar33,4,0x800);
    FUN_0003d7b4();
    iVar25 = SSL_accept((SSL *)*puVar52);
    if (iVar25 < 1) {
      iVar25 = SSL_get_error((SSL *)*puVar52,iVar25);
      if (iVar25 != 2) {
        close(*puVar33);
        SSL_shutdown((SSL *)*puVar52);
        SSL_free((SSL *)*puVar52);
        ERR_print_errors_fp((FILE *)**(undefined4 **)(iVar50 + DAT_00034a10));
        goto LAB_00034448;
      }
      goto LAB_00035898;
    }
  }
  iStack_20af4 = 0;
LAB_00035898:
  uVar38 = *puVar40;
  if ((((uVar38 == *puVar39) || (uVar38 == **(uint **)(iVar50 + DAT_00034a14))) ||
      (uVar38 == **(uint **)(iVar50 + DAT_00034a18))) ||
     (uVar38 == **(uint **)(iVar50 + DAT_00034a1c))) {
    if (aiStack_20ac4[0].s_addr == 0) {
      puts((char *)(DAT_00034a20 + 0x35908));
LAB_00037ec4:
      if (local_24 == **(int **)(iVar50 + DAT_0003812c)) {
        return;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(0);
    }
    iStack_20a4c.s_addr = aiStack_20ac4[0].s_addr;
    aiStack_20a5c[0] = 0;
  }
  else {
    pcVar53 = inet_ntop(10,sStack_20a78.sa_data + 6,acStack_10028,0x40);
    if ((pcVar53 != (char *)0x0) &&
       (iVar25 = acosNvramConfig_match(DAT_00034a28 + 0x35954,DAT_00034a24 + 0x35950), iVar25 != 0))
    {
      pFVar31 = fopen64((char *)(DAT_00034a30 + 0x35970),(char *)(DAT_00034a2c + 0x3596c));
      fprintf(pFVar31,(char *)(DAT_00034a34 + 0x35980),acStack_10028);
      fclose(pFVar31);
    }
    iVar25 = strcmp(acStack_10028,(char *)(DAT_00034a38 + 0x3599c));
    if (iVar25 == 0) goto LAB_00037ec4;
    pcVar53 = strchr(acStack_10028,0x2e);
    if (pcVar53 == (char *)0x0) {
      aiStack_20a5c[0] = 1;
      uStack_20a48._0_1_ = sStack_20a78.sa_data[6];
      uStack_20a48._1_1_ = sStack_20a78.sa_data[7];
      uStack_20a48._2_1_ = sStack_20a78.sa_data[8];
      uStack_20a48._3_1_ = sStack_20a78.sa_data[9];
      acStack_20a44[0] = sStack_20a78.sa_data[10];
      acStack_20a44[1] = sStack_20a78.sa_data[0xb];
      acStack_20a44[2] = sStack_20a78.sa_data[0xc];
      acStack_20a44[3] = sStack_20a78.sa_data[0xd];
      uStack_20a40 = uStack_20a68;
      uStack_20a3c = uStack_20a64;
      printf((char *)(DAT_00036a00 + 0x35a3c),sStack_20a78.sa_data._6_4_ & 0xff,
             (uint)sStack_20a78.sa_data._6_4_ >> 8 & 0xff,
             (uint)sStack_20a78.sa_data._6_4_ >> 0x10 & 0xff);
    }
    else {
      aiStack_20a5c[0] = 0;
      inet_aton(acStack_10021,aiStack_20ac4);
      inet_aton(acStack_10021,&iStack_20a4c);
    }
  }
  auStack_2002c[0]._0_1_ = 0;
  iStack_20ba0 = 0;
  pFStack_20b80 = (FILE *)0x0;
  bVar14 = false;
  pcStack_20ba8 = DAT_00036a04;
  pcStack_20b6c = (char *)0x0;
  bVar32 = true;
  pcStack_20bb0 = (char *)0x0;
  bVar51 = false;
  pcStack_20b74 = (char *)0x0;
  bVar62 = false;
  iVar25 = DAT_00036a08 + 0x35c2e;
  pcVar53 = (char *)(DAT_00036a0c + 0x35a9c);
  iVar56 = DAT_00036a10 + 0x35c4e;
LAB_00035ab0:
  sVar26 = strlen((char *)auStack_2002c);
  if (60000 < sVar26) goto LAB_00037e08;
  iVar42 = 0;
  do {
    fStack_209b8.fds_bits[iVar42] = 0;
    iVar42 = iVar42 + 1;
  } while (iVar42 != 0x20);
  tStack_20ae4.tv_usec = 0;
  uVar43 = *puVar33;
  uVar38 = uVar43 + 0x1f;
  if (-1 < (int)uVar43) {
    uVar38 = uVar43;
  }
  uVar43 = uVar43 & 0x8000001f;
  if ((int)uVar43 < 0) {
    uVar43 = ~(~((uVar43 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  fStack_209b8.fds_bits[(int)uVar38 >> 5] =
       fStack_209b8.fds_bits[(int)uVar38 >> 5] | 1 << (uVar43 & 0xff);
  if (bVar62) {
    tStack_20ae4.tv_sec = 10;
  }
  else {
    tStack_20ae4.tv_sec = 1;
  }
  if (*piVar41 == 0) {
LAB_00035b70:
    iVar42 = select(*puVar33 + 1,&fStack_209b8,(fd_set *)0x0,(fd_set *)0x0,&tStack_20ae4);
  }
  else {
    snprintf(pcVar17,0x400,pcVar53,iVar25);
    FUN_0002b2a8(0,pcVar17);
    iVar42 = SSL_pending((SSL *)**(undefined4 **)(iVar50 + DAT_00036a14));
    snprintf(pcVar17,0x400,pcVar53,iVar25);
    FUN_0002b2a8(0,pcVar17);
    if (iVar42 == 0) goto LAB_00035b70;
  }
  if (iVar42 < 1) {
LAB_000365dc:
    pcVar60 = (char *)(DAT_00036acc + 0x365fc);
    iVar56 = DAT_00036ac8 + 0x3679a;
LAB_000365fc:
    snprintf(pcVar17,0x400,pcVar60,iVar56);
LAB_00036610:
    FUN_0002b2a8(0,pcVar17);
LAB_00036614:
    iVar42 = 0;
    goto LAB_00036eb8;
  }
  uVar43 = *puVar33;
  uVar38 = uVar43 + 0x1f;
  if (-1 < (int)uVar43) {
    uVar38 = uVar43;
  }
  uVar43 = uVar43 & 0x8000001f;
  if ((int)uVar43 < 0) {
    uVar43 = ~(~((uVar43 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  if (((fStack_209b8.fds_bits[(int)uVar38 >> 5] & 1 << (uVar43 & 0xff)) == 0) && (*piVar41 == 0))
  goto LAB_000365dc;
  pcVar60 = (char *)(DAT_00036a18 + 0x35c7c);
  snprintf(pcVar17,0x400,pcVar60,iVar56);
  FUN_0002b2a8(0,pcVar17);
  sVar26 = FUN_0002bed4(*puVar33,acStack_10028,0x400);
  if (sVar26 == 0xffffffff) goto LAB_000365fc;
  if (sVar26 == 0) {
    snprintf(pcVar17,0x400,pcVar60,iVar56);
    goto LAB_00036610;
  }
  if (sVar26 == 0xfffffffe) {
    snprintf(pcVar17,0x400,pcVar60,iVar56);
    FUN_0002b2a8(0,pcVar17);
    goto LAB_00035ab0;
  }
  snprintf(pcVar17,0x400,pcVar60,iVar56);
  FUN_0002b2a8(0,pcVar17);
  if (!bVar51) {
    iVar42 = (int)pcStack_20bb0 + sVar26;
    if (iVar42 < 0x10000) {
      snprintf(pcVar17,0x400,pcVar60,iVar56);
      FUN_0002b2a8(0,pcVar17);
      memcpy((char *)((int)auStack_2002c + (int)pcStack_20bb0),acStack_10028,sVar26);
      *(undefined1 *)((int)auStack_2002c + iVar42) = 0;
      pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036a88 + 0x3642c));
      pcStack_20bb0 = (char *)iVar42;
      if ((((pcVar60 == (char *)0x0) ||
           (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036a8c + 0x3644c)),
           pcVar60 == (char *)0x0)) ||
          (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036a90 + 0x36464)),
          pcVar60 == (char *)0x0)) ||
         ((pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036a94 + 0x3647c)),
          pcVar60 == (char *)0x0 &&
          (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036a9c + 0x364a0)),
          pcVar60 == (char *)0x0)))) {
        pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036aa0 + 0x364b8));
        if ((pcVar60 == (char *)0x0) ||
           ((pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036aa4 + 0x364d0)),
            pcVar60 == (char *)0x0 ||
            (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036aa8 + 0x364e8)),
            pcVar60 == (char *)0x0)))) {
          pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036ab0 + 0x36508));
          if ((pcVar60 == (char *)0x0) ||
             ((pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036ab4 + 0x36520)),
              pcVar60 == (char *)0x0 ||
              (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036ab8 + 0x36538)),
              pcVar60 == (char *)0x0)))) {
            strcasestr((char *)auStack_2002c,(char *)(DAT_00036ac0 + 0x36574));
            goto LAB_00036774;
          }
          pcVar60 = (char *)(DAT_00036abc + 0x3654c);
        }
        else {
          pcVar60 = (char *)(DAT_00036aac + 0x364f8);
        }
      }
      else {
        pcVar60 = (char *)(DAT_00036a98 + 0x36490);
      }
      pcVar60 = strcasestr((char *)auStack_2002c,pcVar60);
      if (pcVar60 == (char *)0x0) goto LAB_0003661c;
      bVar51 = true;
      goto LAB_00036614;
    }
    snprintf(pcVar17,0x400,pcVar60,iVar56);
    FUN_0002b2a8(0,pcVar17);
    pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036ac4 + 0x365b0));
    if (pcVar60 != (char *)0x0) {
      bVar14 = true;
LAB_000365c8:
      bVar32 = false;
      goto LAB_0003661c;
    }
LAB_00036774:
    snprintf(pcVar17,0x400,(char *)(DAT_00036adc + 0x367a0),DAT_00036ad8 + 0x3693a);
    FUN_0002b2a8(0,pcVar17);
    pcVar60 = inet_ntoa(aiStack_20ac4[0]);
    strncpy(acStack_10028,pcVar60,0x1f);
    uStack_10009 = 0;
    iVar42 = isLanSubnet(acStack_10028);
    if (((iVar42 == 0) && (iVar42 = isOpenvpnLanSubnet(acStack_10028), iVar42 == 0)) &&
       (aiStack_20a5c[0] != 1)) {
      iVar42 = isLoopBack(acStack_10028);
      if (iVar42 == 0) {
        if (((*puVar40 == uVar19) &&
            (iVar42 = acosNvramConfig_match(DAT_00036b00 + 0x368f0,DAT_00036afc + 0x368ec),
            iVar42 == 0)) || (uVar38 = *puVar40, uVar38 == **(uint **)(iVar50 + DAT_00036cf4))) {
          puts((char *)(DAT_00036b04 + 0x36904));
          iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_00036b08 + 0x36918),0xb);
          if (iVar42 == 0) {
            iVar54 = DAT_00036b0c + 0x36930;
            iVar42 = acosNvramConfig_match(DAT_00036b10 + 0x36934,iVar54);
            if ((iVar42 != 0) ||
               (iVar42 = acosNvramConfig_match(DAT_00036b14 + 0x36950,iVar54), iVar42 != 0))
            goto LAB_000369e4;
          }
          pcVar60 = (char *)(DAT_00036b18 + 0x36964);
LAB_00036d24:
          puts(pcVar60);
          goto LAB_00035ab0;
        }
        if (((uVar38 == *puVar39) || (uVar38 == **(uint **)(iVar50 + DAT_00036b1c))) ||
           (uVar38 == **(uint **)(iVar50 + DAT_00036b20))) {
          if ((!bVar65) &&
             (iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_00036b24 + 0x369bc),0xb),
             iVar42 == 0)) {
            pcVar60 = (char *)(DAT_00036b28 + 0x369d0);
            goto LAB_00036d24;
          }
        }
        else if ((uVar38 == **(uint **)(iVar50 + DAT_00036b2c)) &&
                (iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_00036b30 + 0x36d14),0xb),
                iVar42 != 0)) {
          pcVar60 = (char *)(DAT_00036b34 + 0x36d28);
          goto LAB_00036d24;
        }
      }
    }
    else {
      iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_00036ae0 + 0x367fc),0xb);
      if ((iVar42 == 0) &&
         (((iVar42 = acosNvramConfig_match(DAT_00036ae8 + 0x3683c,DAT_00036ae4 + 0x36838),
           iVar42 != 0 && (**(int **)(iVar50 + DAT_00036aec) == 0)) ||
          ((iVar42 = acosNvramConfig_match(DAT_00036af8 + 0x36878,DAT_00036af4 + 0x36874),
           iVar42 != 0 && (**(int **)(iVar50 + DAT_00036aec) != 0)))))) {
        pcVar60 = (char *)(DAT_00036af0 + 0x36864);
        goto LAB_00036d24;
      }
    }
LAB_000369e4:
    iVar42 = FUN_0002af84(auStack_2002c,&puStack_20afc);
    if (iVar42 != 0) goto LAB_00036d2c;
    goto LAB_00035ab0;
  }
  snprintf(pcVar17,0x400,pcVar60,iVar56);
  FUN_0002b2a8(0,pcVar17);
  if (bVar32) {
    memcpy((char *)((int)auStack_2002c + (int)pcStack_20bb0),acStack_10028,sVar26);
    pcStack_20bb0 = (char *)((int)pcStack_20bb0 + sVar26);
    *(undefined1 *)((int)auStack_2002c + (int)pcStack_20bb0) = 0;
    pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036a1c + 0x35dcc));
    if ((pcVar60 == (char *)0x0) ||
       (pcVar60 = strcasestr(pcVar60,(char *)(DAT_00036a20 + 0x35de8)), pcVar60 == (char *)0x0)) {
      pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036a3c + 0x35fe4));
      pcVar46 = (char *)0x0;
      if (pcVar60 != (char *)0x0) {
        pcVar46 = (char *)(DAT_00036a40 + 0x35ff8);
        pcVar60 = strcasestr(pcVar60,pcVar46);
        if (pcVar60 == (char *)0x0) {
          pcVar46 = (char *)0x0;
        }
        else {
          pcVar47 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036a44 + 0x36014));
          if ((((pcVar47 == (char *)0x0) || (pcVar47[-1] != '\n')) ||
              (pcVar46 = strcasestr((char *)auStack_2002c,pcVar46), pcVar46 == (char *)0x0)) ||
             (pcVar60 + 4 <= pcVar46 + 4)) {
            pcVar46 = (char *)0x0;
            bVar14 = true;
          }
          else {
            pcVar60 = strcasestr(pcVar47 + 0x10,(char *)(DAT_00036a48 + 0x36064));
            pcVar48 = pcVar47 + 0xf;
            pcStack_20ba8 = (char *)0x0;
            for (iVar42 = 0; iVar42 < (int)pcVar60 - (int)(pcVar47 + 0x10); iVar42 = iVar42 + 1) {
              pcVar48 = pcVar48 + 1;
              pcStack_20ba8 = (char *)((int)pcStack_20ba8 * 10 + *pcVar48 + -0x30);
            }
            if ("" <= pcStack_20ba8) {
              bVar62 = true;
              goto LAB_000362d4;
            }
            pcStack_20ba8 = pcVar46 + 4 + ((int)pcStack_20ba8 - (int)auStack_2002c);
            pcVar46 = (char *)0x0;
            **(undefined4 **)(iVar50 + DAT_00036a4c) = pcStack_20ba8;
          }
        }
      }
LAB_000360f0:
      if (**(int **)(iVar50 + DAT_00036b50) == 1) {
        system((char *)(DAT_00036a50 + 0x36110));
        pFStack_20b80 = fopen64((char *)(DAT_00036a58 + 0x36124),(char *)(DAT_00036a54 + 0x36120));
        if (pFStack_20b80 == (FILE *)0x0) {
          puts((char *)(DAT_00036a60 + 0x361b8));
          bVar14 = true;
        }
        else {
          puVar64 = auStack_20aa8;
          puVar61 = (uint *)((int)auStack_2002c + (int)pcVar46);
          do {
            puVar44 = puVar61 + 2;
            uVar38 = puVar61[1];
            *puVar64 = *puVar61;
            puVar64[1] = uVar38;
            puVar64 = puVar64 + 2;
            puVar61 = puVar44;
          } while (puVar44 != (uint *)((int)auStack_2001c + (int)pcVar46));
          sVar57 = (int)pcStack_20bb0 - (int)(pcVar46 + 0x10);
          sVar26 = fwrite((char *)((int)auStack_2002c + (int)(pcVar46 + 0x10)),1,sVar57,
                          pFStack_20b80);
          if (sVar57 != sVar26) {
            puts((char *)(DAT_00036a5c + 0x36194));
            bVar14 = true;
          }
          iStack_20ba0 = iStack_20ba0 + sVar26;
        }
        goto LAB_0003661c;
      }
      piVar45 = *(int **)(iVar50 + DAT_00036a64);
      if ((void *)*piVar45 != (void *)0x0) {
        free((void *)*piVar45);
        *piVar45 = 0;
      }
      FUN_0005d7cc(&uStack_20adc);
      pcVar60 = (char *)((int)pcStack_20bb0 - (int)pcVar46);
      if (((0 < (int)pcVar60) && (pcVar47 = pcStack_20ba8 + 600, pcStack_20ba8 < pcVar47)) &&
         (pcVar60 < pcVar47)) {
        pvVar27 = malloc((size_t)pcVar47);
        *piVar45 = (int)pvVar27;
        if (pvVar27 == (void *)0x0) {
          puts((char *)(DAT_00036a6c + 0x36240));
          system((char *)(DAT_00036a70 + 0x3624c));
          sleep(2);
          system((char *)(DAT_00036a74 + 0x36260));
          sleep(1);
          pvVar27 = malloc((size_t)pcVar47);
          *piVar45 = (int)pvVar27;
          if (pvVar27 == (void *)0x0) {
            puts((char *)(DAT_00036a78 + 0x3628c));
            bVar62 = false;
            goto LAB_000362d4;
          }
        }
        memset((void *)*piVar45,0x20,(size_t)pcVar47);
        memcpy((void *)*piVar45,(char *)((int)auStack_2002c + (int)pcVar46),(size_t)pcVar60);
        pcStack_20b74 = pcVar60 + *piVar45;
        pcStack_20b6c = pcVar60;
        goto LAB_000365c8;
      }
      puts((char *)(DAT_00036a68 + 0x3621c));
    }
    else {
      bVar9 = pcVar60[0xb];
      FUN_0003d7b4();
      uVar38 = FUN_0003d51c(pcVar60 + 4,0x200);
      if (uVar38 == 0) {
        cVar10 = pcVar60[0x14];
        bVar1 = pcVar60[0x17];
        pcVar46 = pcVar60 + 4 + ((uint)bVar9 - (int)auStack_2002c);
        bVar9 = pcVar60[0x16];
        bVar2 = pcVar60[0x15];
        FUN_0003d7b4();
        cVar11 = pcVar60[0x18];
        bVar3 = pcVar60[0x1b];
        bVar4 = pcVar60[0x1a];
        bVar5 = pcVar60[0x19];
        FUN_0003d7b4();
        uVar34 = (uint)(byte)pcVar60[0x1f] + pcVar60[0x1c] * 0x1000000 +
                 (uint)(byte)pcVar60[0x1e] * 0x100 + (uint)(byte)pcVar60[0x1d] * 0x10000;
        FUN_0003d7b4();
        uVar43 = (uint)(byte)pcVar60[0x23] + pcVar60[0x20] * 0x1000000 +
                 (uint)(byte)pcVar60[0x22] * 0x100 + (uint)(byte)pcVar60[0x21] * 0x10000;
        FUN_0003d7b4();
        cVar12 = pcVar60[0x24];
        bVar6 = pcVar60[0x27];
        bVar7 = pcVar60[0x26];
        bVar8 = pcVar60[0x25];
        FUN_0003d7b4();
        pcStack_20ba8 = (char *)(uVar34 + uVar43);
        uStack_20adc = uVar34;
        uStack_20ad8 = uVar43;
        iStack_20ad4 = (uint)bVar1 + cVar10 * 0x1000000 + (uint)bVar9 * 0x100 +
                       (uint)bVar2 * 0x10000;
        iStack_20ad0 = (uint)bVar3 + cVar11 * 0x1000000 + (uint)bVar4 * 0x100 +
                       (uint)bVar5 * 0x10000;
        iStack_20acc = (uint)bVar6 + cVar12 * 0x1000000 + (uint)bVar7 * 0x100 +
                       (uint)bVar8 * 0x10000;
        FUN_0003d7b4();
        if (**(int **)(iVar50 + DAT_00036a24) == 1) {
          if (uVar34 < 0x6000001) {
            if (uVar43 < 0x6000001) {
              if (pcStack_20ba8 < (char *)0x6000001) goto LAB_000360f0;
              pcVar60 = (char *)(DAT_00036a30 + 0x35f4c);
            }
            else {
              pcVar60 = (char *)(DAT_00036a2c + 0x35f34);
            }
          }
          else {
            pcVar60 = (char *)(DAT_00036a28 + 0x35f20);
          }
          puts(pcVar60);
          if (!bVar14) {
            FUN_0005d6c0(**(undefined4 **)(iVar50 + DAT_00036c70));
          }
          goto LAB_000360f0;
        }
        uStack_20af0 = uVar38;
        getRoofsSize(&uStack_20af0);
        printf((char *)(DAT_00036a34 + 0x35f8c),uVar34,uStack_20af0);
        if (uStack_20af0 < uVar34) {
          FUN_0003d7b4();
          printf((char *)(DAT_00036a38 + 0x35fac),uStack_20af0);
        }
        else {
          if (pcStack_20ba8 < (char *)0x6000001) {
            FUN_0003d7b4();
            bVar62 = true;
            goto LAB_000360f0;
          }
          FUN_0003d7b4();
        }
      }
    }
LAB_000362d4:
    bVar14 = true;
    bVar32 = false;
    goto LAB_00035ab0;
  }
  if (bVar14) goto LAB_00035ab0;
  if (**(int **)(iVar50 + DAT_00036b50) == 1) {
    sVar57 = fwrite(acStack_10028,1,sVar26,pFStack_20b80);
    if (sVar26 != sVar57) {
      puts((char *)(DAT_00036a7c + 0x36338));
      bVar14 = true;
    }
    iStack_20ba0 = iStack_20ba0 + sVar57;
  }
  else {
    memcpy(pcStack_20b74,acStack_10028,sVar26);
    pcStack_20b74 = pcStack_20b74 + sVar26;
    pcStack_20b6c = pcStack_20b6c + sVar26;
    pcStack_20bb0 = (char *)((int)pcStack_20bb0 + sVar26);
    iVar42 = (int)pcStack_20bb0 + 0xffff;
    if (-1 < (int)pcStack_20bb0) {
      iVar42 = (int)pcStack_20bb0;
    }
    if (iVar42 >> 0x10 != *(int *)(DAT_00036a80 + 0x37074)) {
      *(int *)(DAT_00036a80 + 0x37074) = iVar42 >> 0x10;
      fputc(0x2e,(FILE *)**(undefined4 **)(iVar50 + DAT_00036a84));
    }
  }
LAB_0003661c:
  snprintf(pcVar17,0x400,(char *)(DAT_00036ad4 + 0x36644),DAT_00036ad0 + 0x367e2);
  FUN_0002b2a8(0,pcVar17);
  if ((bVar14) || (pcStack_20b6c < pcStack_20ba8)) {
    bVar51 = true;
    goto LAB_00035ab0;
  }
  iVar25 = 0;
  do {
    fStack_209b8.fds_bits[iVar25] = 0;
    iVar25 = iVar25 + 1;
  } while (iVar25 != 0x20);
  puVar39 = *(uint **)(iVar50 + DAT_00036c70);
  uVar43 = *puVar39;
  uVar38 = uVar43 + 0x1f;
  if (-1 < (int)uVar43) {
    uVar38 = uVar43;
  }
  uVar34 = uVar43 & 0x8000001f;
  if ((int)uVar34 < 0) {
    uVar34 = ~(~((uVar34 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  fStack_209b8.fds_bits[(int)uVar38 >> 5] =
       fStack_209b8.fds_bits[(int)uVar38 >> 5] | 1 << (uVar34 & 0xff);
  tStack_20ae4.tv_sec = 0;
  tStack_20ae4.tv_usec = 200;
  puStack_20afc = auStack_2002c;
  iVar25 = select(uVar43 + 1,&fStack_209b8,(fd_set *)0x0,(fd_set *)0x0,&tStack_20ae4);
  if (0 < iVar25) {
    uVar43 = *puVar39;
    uVar38 = uVar43 + 0x1f;
    if (-1 < (int)uVar43) {
      uVar38 = uVar43;
    }
    uVar34 = uVar43 & 0x8000001f;
    bVar65 = (int)uVar34 < 0;
    if (bVar65) {
      uVar34 = uVar34 - 1;
    }
    if (bVar65) {
      uVar34 = ~(~(uVar34 << 0x1b) >> 0x1b) + 1;
    }
    if ((fStack_209b8.fds_bits[(int)uVar38 >> 5] & 1 << (uVar34 & 0xff)) != 0) {
      FUN_0002bed4(uVar43,acStack_10028,0x400);
    }
  }
  bVar51 = true;
  iVar42 = 1;
LAB_00036d2c:
  snprintf(pcVar17,0x400,(char *)(DAT_00036b3c + 0x36d54),DAT_00036b38 + 0x36ef2);
  FUN_0002b2a8(0,pcVar17);
  iVar25 = 0;
  do {
    fStack_209b8.fds_bits[iVar25] = 0;
    iVar25 = iVar25 + 1;
  } while (iVar25 != 0x20);
  puVar39 = *(uint **)(iVar50 + DAT_00036c70);
  uVar43 = *puVar39;
  uVar38 = uVar43 + 0x1f;
  if (-1 < (int)uVar43) {
    uVar38 = uVar43;
  }
  uVar34 = uVar43 & 0x8000001f;
  if ((int)uVar34 < 0) {
    uVar34 = ~(~((uVar34 - 1) * 0x8000000) >> 0x1b) + 1;
  }
  fStack_209b8.fds_bits[(int)uVar38 >> 5] =
       fStack_209b8.fds_bits[(int)uVar38 >> 5] | 1 << (uVar34 & 0xff);
  tStack_20ae4.tv_usec = 200;
  tStack_20ae4.tv_sec = 0;
  iVar25 = select(uVar43 + 1,&fStack_209b8,(fd_set *)0x0,(fd_set *)0x0,&tStack_20ae4);
  if (0 < iVar25) {
    uVar43 = *puVar39;
    uVar38 = uVar43 + 0x1f;
    if (-1 < (int)uVar43) {
      uVar38 = uVar43;
    }
    uVar43 = uVar43 & 0x8000001f;
    if ((int)uVar43 < 0) {
      uVar43 = ~(~((uVar43 - 1) * 0x8000000) >> 0x1b) + 1;
    }
    if ((fStack_209b8.fds_bits[(int)uVar38 >> 5] & 1 << (uVar43 & 0xff)) != 0) {
      pcVar53 = (char *)(DAT_00036b44 + 0x36e64);
      iVar25 = DAT_00036b40 + 0x36ffe;
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b2a8(0,pcVar17);
      FUN_0002bed4(*puVar39,acStack_10028,0x400);
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b2a8(0,pcVar17);
    }
  }
LAB_00036eb8:
  pcVar53 = (char *)(DAT_00036b4c + 0x36edc);
  iVar25 = DAT_00036b48 + 0x37076;
  snprintf(pcVar17,0x400,pcVar53,iVar25);
  FUN_0002b2a8(0,pcVar17);
  piVar45 = *(int **)(iVar50 + DAT_00036b50);
  if (*piVar45 == 1) {
    acStack_2022c[0] = '\0';
    acStack_2022c[1] = '\0';
    acStack_2022c[2] = '\0';
    acStack_2022c[3] = '\0';
    memset(acStack_2022c + 4,0,0x1fc);
    acStack_10028[0] = '\0';
    acStack_10028[1] = '\0';
    acStack_10028[2] = '\0';
    acStack_10028[3] = '\0';
    memset(acStack_10028 + 4,0,0x1fc);
    memset(auStack_20aa8 + 4,0,0x10);
    memset(auStack_20a88,0,0x10);
    snprintf(pcVar17,0x400,pcVar53,iVar25);
    FUN_0002b2a8(0,pcVar17);
    if (pFStack_20b80 != (FILE *)0x0) {
      fclose(pFStack_20b80);
    }
    iVar25 = DAT_00036b54;
    *piVar45 = 0;
    pcVar53 = (char *)(DAT_00036b58 + 0x36fd0);
    rename((char *)(iVar25 + 0x36fc4),pcVar53);
    if (DAT_00036b5c < auStack_20aa8[0] - 1) {
      puts((char *)(DAT_00036b60 + 0x36ffc));
      snprintf(acStack_20748,0x11b,(char *)(DAT_00036b68 + 0x3701c),2);
      uVar38 = *puVar33;
      iVar56 = DAT_00036b6c + 0x3703c;
      iVar25 = DAT_00036b70 + 0x37040;
    }
    else {
      iVar56 = truncate64(pcVar53,(ulonglong)auStack_20aa8[0]);
      if (iVar56 == 0) {
        pcVar60 = (char *)(DAT_00036b88 + 0x370bc);
        printf((char *)(DAT_00036b8c + 0x370c4),auStack_20aa8[0]);
        pFVar31 = fopen64(pcVar53,pcVar60);
        if (pFVar31 == (FILE *)0x0) {
          puts((char *)(DAT_00036b90 + 0x370ec));
          snprintf(acStack_20748,0x11b,(char *)(DAT_00036b98 + 0x3710c),2);
          iVar56 = DAT_00036b9c + 0x3712c;
          iVar25 = DAT_00036ba0 + 0x37130;
          uVar38 = **(uint **)(iVar50 + DAT_00036c70);
        }
        else {
          iVar56 = FUN_0012b360(pFVar31,auStack_20aa8[0],&iStack_20af4);
          if (iVar56 == 0) {
            fclose(pFVar31);
            if (auStack_20aa8[1] == iStack_20af4 && iStack_20af4 != 0) {
              system((char *)(DAT_00036bcc + 0x3723c));
              pFVar31 = fopen64((char *)(iVar25 + 0x36fc4),pcVar60);
              if (pFVar31 == (FILE *)0x0) {
                puts((char *)(DAT_00036bd0 + 0x37268));
                FUN_001310ac(2);
                snprintf(acStack_20748,0x11b,(char *)(DAT_00036bd4 + 0x37284),2);
                iVar56 = DAT_00036bd8 + 0x372a8;
                iVar25 = DAT_00036bdc + 0x372ac;
                uVar38 = **(uint **)(iVar50 + DAT_00036c70);
              }
              else {
                fseek(pFVar31,0,0);
                iStack_20bac = ftell(pFVar31);
                if (iStack_20bac == -1) {
                  perror((char *)(DAT_00036be0 + 0x372dc));
                  iStack_20bac = 0;
                }
                iVar25 = 0;
                bVar51 = false;
                pcVar53 = (char *)(DAT_00036be4 + 0x372f8);
                bVar65 = false;
                puStack_20ba4 = (undefined1 *)0x0;
                pcVar60 = (char *)(DAT_00036be8 + 0x3730c);
                pcStack_20bb0 = (char *)0x0;
                pcVar46 = (char *)(DAT_00036bec + 0x3731c);
                pcVar47 = (char *)(DAT_00036bf0 + 0x37328);
                pcVar48 = (char *)(DAT_00036bf4 + 0x37334);
                bVar62 = false;
                while (iVar56 = feof(pFVar31), iVar56 == 0) {
                  iVar25 = ftell(pFVar31);
                  if (iVar25 == -1) {
                    perror(pcVar53);
                    iVar25 = 0;
                  }
                  uStack_2062c = CONCAT22(uStack_2062c._2_2_,0xffff);
                  fgets((char *)&uStack_2062c,0x200,pFVar31);
                  pcVar28 = strcasestr((char *)&uStack_2062c,pcVar60);
                  bVar32 = (bool)(bVar65 ^ 1);
                  if (pcVar28 == (char *)0x0) {
                    bVar32 = false;
                  }
                  if (bVar32) {
                    strncpy(acStack_2022c,(char *)&uStack_2062c,0x1ff);
                    uStack_2002d = 0;
                    pcStack_20bb0 = acStack_20223;
                    pcVar28 = strrchr(acStack_2022c,0x22);
                    bVar65 = true;
                    if (pcVar28 != (char *)0x0) {
                      *pcVar28 = '\0';
                    }
                    printf(pcVar48,pcStack_20bb0);
                  }
                  else {
                    pcVar28 = strcasestr((char *)&uStack_2062c,pcVar46);
                    if (pcVar28 == (char *)0x0 || bVar62) {
                      if ((char)uStack_2062c == '\0') {
                        bVar32 = (bool)(bVar51 ^ 1);
                        if (uStack_2062c._1_1_ != '\0') {
                          bVar32 = false;
                        }
                        if (!bVar32) goto LAB_000374e0;
                      }
                      else {
LAB_000374e0:
                        pcVar28 = strcasestr((char *)&uStack_2062c,acStack_2042c);
                        if (pcVar28 == (char *)0x0) goto LAB_00037504;
                        if (!bVar51) {
                          iVar25 = iVar25 + -2;
                        }
                      }
                      bVar51 = true;
                    }
                    else {
                      strncpy(acStack_10028,(char *)&uStack_2062c,0x1ff);
                      bVar62 = true;
                      local_fe29 = 0;
                      pcVar28 = strrchr(acStack_10028,0x22);
                      if (pcVar28 != (char *)0x0) {
                        *pcVar28 = '\0';
                      }
                      sVar26 = strlen(acStack_1001e);
                      if (0x1f < sVar26) {
                        local_ffff = 0;
                      }
                      puStack_20ba4 = &stack0xfffdf430 + DAT_00036bf8;
                      printf(pcVar47,puStack_20ba4);
                    }
                  }
LAB_00037504:
                  bVar32 = bVar65;
                  if (!bVar62) {
                    bVar32 = false;
                  }
                  if (bVar32) {
                    if (bVar51) {
                      bVar65 = true;
                      bVar62 = true;
                      break;
                    }
                    bVar65 = true;
                    bVar51 = false;
                    bVar62 = bVar65;
                  }
                }
                bVar65 = (bool)(bVar65 ^ 1);
                printf((char *)(DAT_00036bfc + 0x3754c),iStack_20ba0);
                iVar56 = feof(pFVar31);
                if (iVar56 != 0) {
                  bVar51 = true;
                }
                if (!bVar62) {
                  bVar65 = true;
                }
                fclose(pFVar31);
                if (!bVar65 && bVar51) {
                  iVar25 = iVar25 - iStack_20bac;
                  if (0 < iVar25) {
                    iVar56 = truncate64((char *)(DAT_00036c14 + 0x37600),(longlong)iVar25);
                    if (iVar56 != 0) {
                      perror((char *)(DAT_00036c18 + 0x37614));
                    }
                    printf((char *)(DAT_00036c1c + 0x37624),iVar25);
                  }
                  iVar25 = FUN_00131994(auStack_20ab8,&uStack_20af8,DAT_00036c24 + 0x37644,
                                        DAT_00036c20 + 0x3763c);
                  if (iVar25 == 0) {
                    if (*pcStack_20bb0 != '\0') {
                      __isoc99_sscanf(pcStack_20bb0,DAT_00036c34 + 0x376d4,auStack_20aa8 + 4,
                                      auStack_20a94);
                    }
                    iVar25 = 0;
                    do {
                      auStack_20ab0[iVar25] = (char)(auStack_20aa8 + 4)[iVar25];
                      iVar56 = iVar25 + 1;
                      auStack_20aac[iVar25] = (char)auStack_20a88[iVar25];
                      iVar25 = iVar56;
                    } while (iVar56 != 4);
                    strncpy(acStack_20848,(char *)(DAT_00036c38 + 0x37744),0xff);
                    uStack_20749 = 0;
                    snprintf(acStack_20848,0x100,(char *)(DAT_00036c3c + 0x37768),
                             DAT_00036c40 + 0x37774);
                    pFVar31 = fopen64((char *)(DAT_00036c48 + 0x37788),
                                      (char *)(DAT_00036c44 + 0x37784));
                    puVar39 = *(uint **)(iVar50 + DAT_00036c70);
                    if (pFVar31 == (FILE *)0x0) {
                      FUN_001310ac(3);
                      snprintf(acStack_20748,0x11b,(char *)(DAT_00036c4c + 0x377bc),3);
                      uVar38 = *puVar39;
                      iVar56 = DAT_00036c50 + 0x377dc;
                      iVar25 = DAT_00036c54 + 0x377e0;
                    }
                    else {
                      uVar38 = FUN_0012b4b4(acStack_20848,pFVar31,uStack_20af8,auStack_20ab8);
                      if (uVar38 == 0) {
                        fclose(pFVar31);
                        FUN_00133298(puStack_20ba4);
                        uVar23 = FUN_0003ba74(DAT_00036c64 + 0x37870);
                        uVar29 = FUN_0003ba74(DAT_00036c68 + 0x37880);
                        uStack_20adc = uVar38;
                        FUN_0012b6f4(uVar23,uVar29,&uStack_20adc);
                        iVar25 = DAT_00036c6c + 0x378a8;
                        goto LAB_0003795c;
                      }
                      fclose(pFVar31);
                      FUN_001310ac(5);
                      snprintf(acStack_20748,0x11b,(char *)(DAT_00036c58 + 0x37830),5);
                      uVar38 = *puVar39;
                      iVar56 = DAT_00036c5c + 0x37850;
                      iVar25 = DAT_00036c60 + 0x37854;
                    }
                  }
                  else {
                    FUN_001310ac(4);
                    snprintf(acStack_20748,0x11b,(char *)(DAT_00036c28 + 0x37674),4);
                    iVar56 = DAT_00036c2c + 0x37698;
                    iVar25 = DAT_00036c30 + 0x3769c;
                    uVar38 = **(uint **)(iVar50 + DAT_00036c70);
                  }
                }
                else {
                  puts((char *)(DAT_00036c00 + 0x37594));
                  snprintf(acStack_20748,0x11b,(char *)(DAT_00036c08 + 0x375b4),2);
                  iVar56 = DAT_00036c0c + 0x375d4;
                  iVar25 = DAT_00036c10 + 0x375d8;
                  uVar38 = **(uint **)(iVar50 + DAT_00036c70);
                }
              }
            }
            else {
              puts((char *)(DAT_00036bb8 + 0x371e8));
              snprintf(acStack_20748,0x11b,(char *)(DAT_00036bc0 + 0x37208),2);
              iVar56 = DAT_00036bc4 + 0x37228;
              iVar25 = DAT_00036bc8 + 0x3722c;
              uVar38 = **(uint **)(iVar50 + DAT_00036c70);
            }
          }
          else {
            fclose(pFVar31);
            puts((char *)(DAT_00036ba4 + 0x37160));
            snprintf(acStack_20748,0x11b,(char *)(DAT_00036bac + 0x37184),2);
            iVar56 = DAT_00036bb0 + 0x371a4;
            iVar25 = DAT_00036bb4 + 0x371a8;
            uVar38 = **(uint **)(iVar50 + DAT_00036c70);
          }
        }
      }
      else {
        perror((char *)(DAT_00036b74 + 0x37068));
        snprintf(acStack_20748,0x11b,(char *)(DAT_00036b7c + 0x37088),2);
        uVar38 = *puVar33;
        iVar56 = DAT_00036b80 + 0x370a8;
        iVar25 = DAT_00036b84 + 0x370ac;
      }
    }
    FUN_000618dc(iVar25,acStack_20748,iVar56,uVar38);
  }
  else {
    if (aiStack_20a5c[0] == 0) {
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b2a8(0,pcVar17);
    }
    puVar52 = *(undefined4 **)(iVar50 + DAT_00036c70);
    if ((*puVar40 != uVar19) ||
       (iVar25 = acosNvramConfig_match(DAT_00036c78 + 0x3790c,DAT_00036c74 + 0x37908), iVar25 == 0))
    goto LAB_00037b9c;
    iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036c7c + 0x37928),0x17);
    if (iVar25 == 0) {
      printf((char *)(DAT_00036c84 + 0x3794c),DAT_00036c80 + 0x37af1,0xe2c);
      iVar25 = DAT_00036c88 + 0x37960;
      goto LAB_0003795c;
    }
    pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036c8c + 0x37974));
    if ((((pcVar53 == (char *)0x0) &&
         (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036c90 + 0x3798c)),
         pcVar53 == (char *)0x0)) &&
        (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036c94 + 0x379a4)),
        pcVar53 == (char *)0x0)) &&
       (((pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036c98 + 0x379bc)),
         pcVar53 == (char *)0x0 &&
         (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036c9c + 0x379d4)),
         pcVar53 == (char *)0x0)) &&
        ((pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036ca0 + 0x379ec)),
         pcVar53 == (char *)0x0 &&
         (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036ca4 + 0x37a04)),
         pcVar53 == (char *)0x0)))))) {
      pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036ca8 + 0x37a20));
      if (pcVar53 == (char *)0x0) {
        iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036cb0 + 0x37a4c),0x19);
        if (iVar25 == 0) {
          iVar25 = DAT_00036cb4 + 0x37a60;
        }
        else {
          iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036cb8 + 0x37a74),0xd);
          if ((iVar25 == 0) ||
             (iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036cbc + 0x37a90),0x1d),
             iVar25 == 0)) goto LAB_00037b9c;
          iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036cc0 + 0x37aac),0xe);
          iVar15.s_addr = iStack_20a4c.s_addr;
          if (iVar25 == 0) {
            printf((char *)(DAT_00036cc8 + 0x37ad0),DAT_00036cc4 + 0x37c75,0xe51);
            iVar25 = DAT_00036ccc + 0x37ae4;
          }
          else {
            if ((aiStack_20a5c[0] == 0) &&
               (iVar30 = inet_addr((char *)(DAT_00036cd0 + 0x37b14)), iVar15.s_addr == iVar30))
            goto LAB_00037b9c;
            iVar15.s_addr = iStack_20a4c.s_addr;
            if (aiStack_20a5c[0] == 0) {
              pcVar53 = (char *)acosNvramConfig_get(DAT_00036cd4 + 0x37b30);
              iVar30 = inet_addr(pcVar53);
              if (iVar15.s_addr == iVar30) goto LAB_00037b9c;
            }
            if (aiStack_20a5c[0] == 1) {
              inet_pton(10,(char *)(DAT_00036cd8 + 0x37b64),auStack_20a88);
              iVar25 = memcmp(&uStack_20a48,auStack_20a88,0x10);
              if (iVar25 == 0) goto LAB_00037b9c;
              iVar25 = DAT_00036cdc + 0x37b8c;
            }
            else {
              iVar25 = DAT_00036ce0 + 0x37b9c;
            }
          }
        }
LAB_0003795c:
        FUN_0003c828(iVar25);
        goto LAB_00037e08;
      }
      puts((char *)(DAT_00036cac + 0x37a34));
    }
LAB_00037b9c:
    if (iVar42 == 0) {
      pcVar53 = (char *)(DAT_0003810c + 0x37d48);
      iVar25 = DAT_00038108 + 0x37ee2;
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b2a8(0,pcVar17);
      if (bVar51) {
        snprintf(pcVar17,0x400,pcVar53,iVar25);
        FUN_0002b2a8(0,pcVar17);
        pcVar53 = strcasestr((char *)auStack_2002c,(char *)(DAT_00038110 + 0x37da8));
        if (pcVar53 == (char *)0x0) {
          pcVar53 = strcasestr((char *)auStack_2002c,(char *)(DAT_00038114 + 0x37dc4));
          uVar23 = *puVar52;
          if (pcVar53 == (char *)0x0) {
            FUN_0005d6c0(uVar23);
            goto LAB_00037e08;
          }
        }
        else {
          uVar23 = *puVar52;
        }
        FUN_00049588(uVar23);
      }
      else {
        snprintf(pcVar17,0x400,pcVar53,iVar25);
        FUN_0002b2a8(0,pcVar17);
      }
    }
    else {
      iVar25 = FUN_0002b594(auStack_2002c);
      if (iVar25 == 1) {
        strlcpy(acStack_10028,auStack_2002c,DAT_00036ce4);
        acStack_2022c[0] = '\0';
        acStack_2022c[1] = '\0';
        acStack_2022c[2] = '\0';
        acStack_2022c[3] = '\0';
        memset(acStack_2022c + 4,0,0xfc);
        iVar25 = FUN_0002b1bc(auStack_2002c,acStack_2022c);
        puVar61 = *(uint **)(iVar50 + DAT_00036ce8);
        puVar39 = *(uint **)(iVar50 + DAT_00036cf4);
        printf((char *)(DAT_00036cf0 + 0x37c20),DAT_00036cec + 0x37db1,0xe87,*puVar40);
        iVar15.s_addr = iStack_20a4c.s_addr;
        if ((*puVar40 != *puVar39) && (*puVar40 != *puVar61)) {
          if (aiStack_20a5c[0] == 0) {
            iVar30 = inet_addr((char *)(DAT_00038100 + 0x37cfc));
            iVar16.s_addr = iStack_20a4c.s_addr;
            if (iVar15.s_addr != iVar30) {
              pcVar53 = (char *)acosNvramConfig_get(DAT_00038104 + 0x37d14);
              iVar30 = inet_addr(pcVar53);
              if (iVar16.s_addr != iVar30) goto LAB_00037ca8;
            }
          }
          else {
LAB_00037ca8:
            if (iVar25 != 1 || aiStack_20a5c[0] == 0) {
              printf((char *)(DAT_00036cfc + 0x37ce4),DAT_00036cf8 + 0x37e89,0xe95);
              goto LAB_00037e08;
            }
          }
        }
        sVar26 = strlen((char *)auStack_2002c);
        FUN_00066c50(acStack_10028,*puVar52,iStack_20a4c.s_addr,sVar26);
      }
      else {
        snprintf(pcVar17,0x400,(char *)(DAT_00038160 + 0x380cc),DAT_0003815c + 0x3826a);
        FUN_0002b2a8(0,pcVar17);
        FUN_0002c15c(auStack_2002c,puStack_20afc,aiStack_20a5c,*puVar52);
      }
    }
  }
LAB_00037e08:
  if (*piVar41 != 0) {
    puVar52 = *(undefined4 **)(iVar50 + DAT_00038118);
    iVar25 = SSL_get_fd((SSL *)*puVar52);
    SSL_shutdown((SSL *)*puVar52);
    SSL_free((SSL *)*puVar52);
    snprintf(pcVar17,0x400,(char *)(DAT_00038120 + 0x37e64),DAT_0003811c + 0x38002);
    FUN_0002b2a8(0,pcVar17);
    close(iVar25);
  }
  snprintf(pcVar17,0x400,(char *)(DAT_00038128 + 0x37ea4),DAT_00038124 + 0x38042);
  FUN_0002b2a8(0,pcVar17);
  close(*puVar33);
  goto LAB_00034448;
}


===== ENTRY 0003d7f4 =====
===== FUNCTION FUN_0003d7f4 @ 0003d7f4 =====

void FUN_0003d7f4(char *param_1,int param_2,int param_3,undefined1 *param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  FILE *pFVar5;
  uint uVar6;
  undefined4 uVar7;
  size_t sVar8;
  long lVar9;
  int iVar10;
  int *piVar11;
  char *pcVar12;
  FILE *__stream;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined1 *puStack_90124;
  undefined1 auStack_9010c [4];
  char acStack_90108 [12];
  char acStack_900fc [52];
  char acStack_900c8 [80];
  char acStack_90078 [80];
  char acStack_90028 [65540];
  char acStack_80024 [524292];
  
  iVar13 = DAT_0003e750 + 0x3d818;
  piVar11 = *(int **)(iVar13 + DAT_0003e758);
  iVar10 = *piVar11;
  auStack_9010c[0] = 0;
  iVar2 = acosNvramConfig_match(DAT_0003e754 + 0x3d828,DAT_0003e75c + 0x3d844);
  if (iVar2 != 0) {
    printf((char *)(DAT_0003e764 + 0x3d87c),DAT_0003e760 + 0x3d8ec,0x145,param_1);
  }
  if (param_2 == 0 || param_1 == (char *)0x0) goto LAB_0003f0e0;
  iVar2 = strcmp(param_1,(char *)(DAT_0003e768 + 0x3d89c));
  if ((iVar2 == 0) && (iVar2 = FUN_0003b990(param_4), iVar2 == 0)) {
    FUN_0003bbfc(param_2,*(undefined4 *)(iVar13 + DAT_0003e76c),DAT_0003e770 + 0x3d8cc);
    goto LAB_0003f0e0;
  }
  iVar2 = DAT_0003e778;
  strlcpy(acStack_90108,DAT_0003e774 + 0x3d8f0,0xc);
  puStack_90124 = param_4;
  if (param_4 == (undefined1 *)0x0) {
    puStack_90124 = auStack_9010c;
  }
  pcVar3 = strstr(param_1,(char *)(iVar2 + 0x3d8fc));
  pcVar4 = (char *)(iVar2 + 0x3d8fc);
  if (pcVar3 == (char *)0x0) {
    cVar1 = *param_1;
    if ((cVar1 == '\0') ||
       (pcVar4 = strstr(param_1,(char *)(DAT_0003e77c + 0x3d93c)), pcVar4 != (char *)0x0)) {
      if ((**(int **)(iVar13 + DAT_0003e780) == 0) || (**(int **)(iVar13 + DAT_0003e784) != 0)) {
        pcVar4 = acStack_90108;
        if (cVar1 != '\0') goto LAB_0003d988;
      }
      else {
        pcVar4 = (char *)(DAT_0003e788 + 0x3d974);
      }
      goto LAB_0003d980;
    }
  }
  else {
LAB_0003d980:
    strcpy(param_1,pcVar4);
  }
LAB_0003d988:
  iVar2 = strcmp(param_1,(char *)(DAT_0003e78c + 0x3d998));
  if ((((iVar2 == 0) &&
       (iVar2 = acosNvramConfig_match(DAT_0003e794 + 0x3d9b4,DAT_0003e790 + 0x3d9b0), iVar2 != 0))
      && (iVar2 = acosNvramConfig_match(DAT_0003e79c + 0x3d9d0,DAT_0003e798 + 0x3d9cc), iVar2 != 0))
     || (((iVar2 = strcmp(param_1,(char *)(DAT_0003e7a4 + 0x3d9fc)), iVar2 == 0 &&
          (iVar2 = acosNvramConfig_match(DAT_0003e7ac + 0x3da18,DAT_0003e7a8 + 0x3da14), iVar2 != 0)
          ) && ((iVar2 = acosNvramConfig_match(DAT_0003e7b4 + 0x3da34,DAT_0003e7b0 + 0x3da30),
                iVar2 != 0 &&
                (iVar2 = acosNvramConfig_match(DAT_0003e7bc + 0x3da50,DAT_0003e7b8 + 0x3da4c),
                iVar2 != 0)))))) {
    strcpy(param_1,(char *)(DAT_0003e7a0 + 0x3d9e8));
  }
  pcVar4 = param_1;
  snprintf(acStack_900c8,0x50,(char *)(DAT_0003e7c4 + 0x3da78),DAT_0003e7c0 + 0x3da70,param_1);
  pcVar3 = (char *)acosNvramConfig_get(DAT_0003e7c8 + 0x3da8c);
  iVar2 = strcmp(pcVar3,(char *)(DAT_0003e7cc + 0x3da98));
  if (iVar2 == 0) {
    pcVar3 = (char *)(DAT_0003e7d0 + 0x3daac);
  }
  else {
    pcVar3 = (char *)(DAT_0003e7d4 + 0x3dab4);
  }
  snprintf(acStack_90078,0x50,pcVar3,acStack_900c8,pcVar4);
  if (*param_1 == '\0') {
    iVar2 = acosNvramConfig_match(DAT_0003e7dc + 0x3dadc,DAT_0003e7d8 + 0x3dad8);
    __stream = (FILE *)0x0;
    if (iVar2 != 0) {
      printf((char *)(DAT_0003e7e4 + 0x3db04),DAT_0003e7e0 + 0x3db74,0x188,acStack_90078);
      __stream = (FILE *)0x0;
    }
  }
  else {
    iVar2 = acosNvramConfig_match(DAT_0003e7ec + 0x3db1c,DAT_0003e7e8 + 0x3db18);
    if (iVar2 != 0) {
      printf((char *)(DAT_0003e7f4 + 0x3db44),DAT_0003e7f0 + 0x3dbb4,0x18e,acStack_90078);
    }
    __stream = fopen64(acStack_90078,(char *)(DAT_0003e7f8 + 0x3db54));
  }
  iVar2 = acosNvramConfig_match(DAT_0003e800 + 0x3db6c,DAT_0003e7fc + 0x3db68);
  if (iVar2 != 0) {
    pFVar5 = fopen64((char *)(DAT_0003e808 + 0x3db88),(char *)(DAT_0003e804 + 0x3db84));
    fprintf(pFVar5,(char *)(DAT_0003e80c + 0x3db98),acStack_900c8);
    fclose(pFVar5);
  }
  FUN_0003d7b4();
  FUN_0003d7b4();
  pcVar4 = strstr(param_1,(char *)(DAT_0003e810 + 0x3dbbc));
  pcVar3 = *(char **)(iVar13 + DAT_0003e814);
  if (pcVar4 != (char *)0x0) {
    __stream = (FILE *)0x0;
  }
  snprintf(pcVar3,0x400,(char *)(DAT_0003e818 + 0x3dbd4),DAT_0003e81c + 0x3dc6b,0x1a2);
  FUN_0002b2a8(0,pcVar3);
  pcVar4 = (char *)acosNvramConfig_get(DAT_0003e820 + 0x3dc10);
  iVar2 = atoi(pcVar4);
  if (__stream == (FILE *)0x0 && iVar2 == 1) {
    pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e824 + 0x3dc34));
    if ((pcVar4 == (char *)0x0) ||
       (iVar2 = acosNvramConfig_match(DAT_0003e82c + 0x3dc50,DAT_0003e828 + 0x3dc4c), iVar2 == 0)) {
      pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e834 + 0x3dc70));
      if (((pcVar4 != (char *)0x0) ||
          (pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e838 + 0x3dc88)), pcVar4 != (char *)0x0))
         || ((**(int **)(iVar13 + DAT_0003e780) != 0 && (**(int **)(iVar13 + DAT_0003e784) == 0))))
      {
        strlcpy(acStack_900c8,DAT_0003e83c + 0x3dca4,0x50);
        pcVar4 = (char *)(DAT_0003e840 + 0x3dcb0);
        goto LAB_0003dd88;
      }
      pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e844 + 0x3dce8));
      if (pcVar4 == (char *)0x0) {
        pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e850 + 0x3dd28));
        if (pcVar4 != (char *)0x0) {
          pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e854 + 0x3dd40));
          __stream = (FILE *)0x0;
          if (pcVar4 != (char *)0x0) goto LAB_0003dd94;
        }
        pcVar4 = (char *)acosNvramConfig_get(DAT_0003e858 + 0x3dd54);
        iVar2 = strcmp(pcVar4,(char *)(DAT_0003e85c + 0x3dd60));
        if (iVar2 == 0) {
          iVar2 = DAT_0003e860 + 0x3dd74;
        }
        else {
          iVar2 = DAT_0003e864 + 0x3dd7c;
        }
        strlcpy(acStack_900c8,iVar2,0x50);
        pcVar4 = (char *)(DAT_0003e868 + 0x3dd8c);
        goto LAB_0003dd88;
      }
      __stream = (FILE *)0x0;
      printf((char *)(DAT_0003e84c + 0x3dd14),DAT_0003e848 + 0x3dd8b,0x1bd,acStack_900c8);
    }
    else {
      pcVar4 = (char *)(DAT_0003e830 + 0x3dc60);
LAB_0003dd88:
      __stream = fopen64(acStack_900c8,pcVar4);
    }
LAB_0003dd94:
    iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e86c + 0x3dda4));
    if ((iVar2 == 0) || (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e870 + 0x3ddbc)), iVar2 == 0)
       ) {
      pcVar4 = (char *)acosNvramConfig_get(DAT_0003e874 + 0x3ddd0);
      iVar2 = strcmp(pcVar4,(char *)(DAT_0003e878 + 0x3dddc));
      if (iVar2 == 0) {
        iVar2 = DAT_0003e87c + 0x3ddf0;
      }
      else {
        iVar2 = DAT_0003e880 + 0x3ddf8;
      }
      strlcpy(acStack_900c8,iVar2,0x50);
      __stream = fopen64(acStack_900c8,(char *)(DAT_0003e884 + 0x3de0c));
    }
  }
  pcVar4 = (char *)acosNvramConfig_get(DAT_0003e888 + 0x3de1c);
  iVar2 = atoi(pcVar4);
  pFVar5 = __stream;
  if ((iVar2 == 1) && (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e88c + 0x3de40)), iVar2 == 0))
  {
    snprintf(pcVar3,0x400,(char *)(DAT_0003e894 + 0x3de70),DAT_0003e890 + 0x3deeb,0x1e9);
    FUN_0002b2a8(0,pcVar3);
    iVar2 = acosNvramConfig_match(DAT_0003e89c + 0x3de90,DAT_0003e898 + 0x3de8c);
    if (iVar2 == 0) {
      memset(acStack_90028,0,0x20);
      system((char *)(DAT_0003e8a0 + 0x3deb4));
      pFVar5 = fopen64((char *)(DAT_0003e8a8 + 0x3dec8),(char *)(DAT_0003e8a4 + 0x3dec4));
      if (pFVar5 != (FILE *)0x0) {
        fgets(acStack_80024,0x80,pFVar5);
        __isoc99_sscanf(acStack_80024,DAT_0003e8ac + 0x3df00,acStack_90028);
        fclose(pFVar5);
      }
      iVar2 = DAT_0003e8b4;
      unlink((char *)(DAT_0003e8b0 + 0x3df1c));
      uVar6 = atoi(acStack_90028);
      iVar14 = DAT_0003e8b8 + 0x3df34;
      uVar7 = acosNvramConfig_get(iVar2 + 0x3df2c);
      printf((char *)(DAT_0003e8c0 + 0x3df5c),DAT_0003e8bc + 0x3dfcf,0x220,uVar7);
      iVar2 = acosNvramConfig_match(iVar2 + 0x3df2c,iVar14);
      if (iVar2 == 0) {
        iVar15 = DAT_0003e8c8 + 0x3df8c;
        iVar2 = acosNvramConfig_match(DAT_0003e8cc + 0x3df90,iVar15);
        if ((iVar2 == 0) &&
           (iVar2 = acosNvramConfig_match(DAT_0003e8d4 + 0x3dfc8,iVar15), iVar2 == 0)) {
          iVar2 = acosNvramConfig_match(DAT_0003e8e0 + 0x3e008,iVar14);
          if (iVar2 == 0) {
            iVar2 = DAT_0003e8e8 + 0x3e024;
          }
          else {
            iVar2 = DAT_0003e8e4 + 0x3e01c;
          }
        }
        else if ((uVar6 & 2) == 0) {
          if ((uVar6 & 1) == 0) {
            iVar2 = DAT_0003e8dc + 0x3dff8;
          }
          else {
            iVar2 = DAT_0003e8d8 + 0x3dfec;
          }
        }
        else {
          iVar2 = DAT_0003e8d0 + 0x3dfb8;
        }
      }
      else {
        iVar2 = DAT_0003e8c4 + 0x3df7c;
      }
      strlcpy(acStack_900c8,iVar2);
      iVar2 = acosNvramConfig_match(DAT_0003e8f0 + 0x3e03c,DAT_0003e8ec + 0x3e038);
      if (iVar2 != 0) {
        printf((char *)(DAT_0003e8f8 + 0x3e064),DAT_0003e8f4 + 0x3e0d4,0x238,acStack_900c8);
      }
      pFVar5 = fopen64(acStack_900c8,(char *)(DAT_0003e8fc + 0x3e074));
      if (pFVar5 == (FILE *)0x0) {
        printf((char *)(DAT_0003e904 + 0x3e0a0),DAT_0003e900 + 0x3e10c,0x23b,acStack_900c8);
        pFVar5 = __stream;
      }
      else {
        if (__stream != (FILE *)0x0) {
          fclose(__stream);
        }
        iVar2 = acosNvramConfig_match(DAT_0003e90c + 0x3e0c8,DAT_0003e908 + 0x3e0c4);
        if (iVar2 != 0) {
          printf((char *)(DAT_0003e914 + 0x3e0f0),DAT_0003e910 + 0x3e160,0x244,acStack_900c8);
        }
      }
    }
  }
  pcVar4 = (char *)acosNvramConfig_get(DAT_0003e918 + 0x3e100);
  iVar2 = atoi(pcVar4);
  if ((iVar2 == 1) && (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e91c + 0x3e11c)), iVar2 == 0))
  {
    snprintf(pcVar3,0x400,(char *)(DAT_0003e924 + 0x3e14c),DAT_0003e920 + 0x3e1c7,0x256);
    FUN_0002b2a8(0,pcVar3);
    pcVar4 = (char *)acosNvramConfig_get(DAT_0003e928 + 0x3e164);
    iVar2 = atoi(pcVar4);
    if (iVar2 == 1) {
      if (pFVar5 != (FILE *)0x0) {
        fclose(pFVar5);
      }
      pcVar4 = (char *)acosNvramConfig_get(DAT_0003e92c + 0x3e18c);
      iVar2 = strcmp(pcVar4,(char *)(DAT_0003e930 + 0x3e198));
      if (iVar2 == 0) {
        iVar2 = DAT_0003e934 + 0x3e1ac;
      }
      else {
        iVar2 = DAT_0003e938 + 0x3e1b4;
      }
      strlcpy(acStack_900c8,iVar2,0x50);
      pFVar5 = fopen64(acStack_900c8,(char *)(DAT_0003e93c + 0x3e1c8));
      acosNvramConfig_set(DAT_0003e944 + 0x3e1e0,DAT_0003e940 + 0x3e1d4);
      agApi_natSetWanLanConflictFlag(0);
      acosNvramConfig_save();
    }
  }
  pcVar4 = (char *)acosNvramConfig_get(DAT_0003e948 + 0x3e1f8);
  iVar2 = atoi(pcVar4);
  if (iVar2 == 0) {
    pcVar4 = (char *)acosNvramConfig_get(DAT_0003e94c + 0x3e210);
    iVar2 = atoi(pcVar4);
    if (iVar2 == 1) {
      snprintf(pcVar3,0x400,(char *)(DAT_0003e954 + 0x3e244),DAT_0003e950 + 0x3e2bf,0x26a);
      FUN_0002b2a8(0,pcVar3);
      iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e958 + 0x3e260));
      if ((((iVar2 == 0) ||
           (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e95c + 0x3e278)), iVar2 == 0)) ||
          (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e960 + 0x3e290)), iVar2 == 0)) ||
         ((pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e964 + 0x3e2a8)), pcVar4 == (char *)0x0 ||
          (iVar2 = acosNvramConfig_match(DAT_0003e96c + 0x3e2c4,DAT_0003e968 + 0x3e2c0), iVar2 != 0)
          ))) {
        iVar14 = DAT_0003e98c + 0x3e358;
        iVar2 = acosNvramConfig_match(iVar14,DAT_0003e990 + 0x3e35c);
        if (iVar2 == 0) goto LAB_0003e390;
        iVar2 = DAT_0003e994 + 0x3e378;
        acosNvramConfig_set(DAT_0003e998 + 0x3e37c,iVar2);
        acosNvramConfig_set(iVar14,iVar2);
      }
      else {
        if (pFVar5 != (FILE *)0x0) {
          fclose(pFVar5);
        }
        pcVar4 = (char *)acosNvramConfig_get(DAT_0003e970 + 0x3e2e8);
        iVar2 = strcmp(pcVar4,(char *)(DAT_0003e974 + 0x3e2f4));
        if (iVar2 == 0) {
          iVar2 = DAT_0003e978 + 0x3e308;
        }
        else {
          iVar2 = DAT_0003e97c + 0x3e310;
        }
        strlcpy(acStack_900c8,iVar2,0x50);
        pFVar5 = fopen64(acStack_900c8,(char *)(DAT_0003e980 + 0x3e324));
        acosNvramConfig_set(DAT_0003e988 + 0x3e33c,DAT_0003e984 + 0x3e330);
        agApi_natSetWanLanConflictFlag(0);
      }
      acosNvramConfig_save();
    }
  }
LAB_0003e390:
  pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e99c + 0x3e3a0));
  if (pcVar4 != (char *)0x0) {
    strlcpy(acStack_900c8,DAT_0003e9a0 + 0x3e3bc,0x50);
    pFVar5 = fopen64(acStack_900c8,(char *)(DAT_0003e9a4 + 0x3e3cc));
  }
  if (pFVar5 != (FILE *)0x0) {
    uVar7 = FUN_0003bf60(acStack_900c8);
    strlcpy(acStack_900fc,uVar7,0x32);
    iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e9a8 + 0x3e408));
    if (iVar2 == 0) {
      FUN_0003b188(acStack_900c8,pFVar5);
      FUN_0003bd88(param_2,*(undefined4 *)(iVar13 + DAT_0003e76c),acStack_900fc);
      uVar7 = 0x2a6;
      iVar2 = DAT_0003e9ac + 0x3e4d3;
      pcVar4 = (char *)(DAT_0003e9b0 + 0x3e458);
LAB_0003e548:
      snprintf(pcVar3,0x400,pcVar4,iVar2,uVar7);
    }
    else {
      iVar2 = strcmp(acStack_900fc,(char *)(DAT_0003e9b4 + 0x3e468));
      if (iVar2 == 0) {
        FUN_000c4ae0(acStack_900c8);
        FUN_0003b188(acStack_900c8,pFVar5);
        pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e9b8 + 0x3e494));
        if (pcVar4 == (char *)0x0) {
          FUN_0003bbfc(param_2,*(undefined4 *)(iVar13 + DAT_0003e76c),acStack_900fc);
        }
        uVar7 = 0x2b5;
        iVar2 = DAT_0003e9bc + 0x3e553;
        pcVar4 = (char *)(DAT_0003e9c0 + 0x3e4d8);
LAB_0003e4d4:
        snprintf(pcVar3,0x400,pcVar4,iVar2,uVar7);
      }
      else {
        iVar2 = strcmp(acStack_900fc,(char *)(DAT_0003e9c4 + 0x3e500));
        if (iVar2 == 0) {
          FUN_0003b188(acStack_900c8,pFVar5);
          FUN_0003bab8(param_2,*(undefined4 *)(iVar13 + DAT_0003e76c));
          uVar7 = 0x2be;
          iVar2 = DAT_0003e9c8 + 0x3e5c7;
          pcVar4 = (char *)(DAT_0003e9cc + 0x3e54c);
          goto LAB_0003e548;
        }
        iVar2 = strcmp(acStack_900fc,(char *)(DAT_0003e9d0 + 0x3e570));
        if (iVar2 != 0) {
          uVar6 = FUN_0003c038(pFVar5,acStack_80024);
          if (0x7ffff < uVar6) {
            fseek(pFVar5,0,0);
            fseek(pFVar5,0,2);
            lVar9 = ftell(pFVar5);
            iVar2 = acosNvramConfig_match(DAT_0003ea1c + 0x3eb2c,DAT_0003ea18 + 0x3eb20);
            if (iVar2 != 0) {
              printf((char *)(DAT_0003ea24 + 0x3eb50),DAT_0003ea20 + 0x3ebc0,0x305);
            }
            pcVar4 = strstr(param_1,(char *)(DAT_0003ea28 + 0x3eb60));
            if ((pcVar4 == (char *)0x0) &&
               (pcVar4 = strstr(param_1,(char *)(DAT_0003ea2c + 0x3eb78)), pcVar4 == (char *)0x0)) {
              uVar7 = FUN_0003bf60(acStack_900c8);
              snprintf(acStack_90028,400,(char *)(DAT_0003ea30 + 0x3eb9c),lVar9,uVar7);
              iVar2 = acosNvramConfig_match(DAT_0003ea38 + 0x3ebb8,DAT_0003ea34 + 0x3ebb4);
              if (iVar2 != 0) {
                printf((char *)(DAT_0003ea40 + 0x3ebe0),DAT_0003ea3c + 0x3ec50,0x311,param_1);
              }
            }
            else {
              uVar7 = FUN_0003bf60(acStack_900c8);
              snprintf(acStack_90028,400,(char *)(DAT_0003ea44 + 0x3ec00),lVar9,uVar7);
            }
            sVar8 = strlen(acStack_90028);
            iVar2 = FUN_0002c068(param_2,acStack_90028,sVar8,0);
            if (lVar9 != 0 && iVar2 != -1) {
              fseek(pFVar5,0,0);
              while (sVar8 = fread(acStack_80024,1,0x80000,pFVar5), 0 < (int)sVar8) {
                FUN_0002c068(param_2,acStack_80024,sVar8,0);
              }
            }
            fclose(pFVar5);
            uVar7 = 0x331;
            iVar2 = DAT_0003ea48 + 0x3ed13;
            pcVar4 = (char *)(DAT_0003ea4c + 0x3ec98);
            goto LAB_0003e4d4;
          }
          pcVar4 = strstr(param_1,(char *)(DAT_0003e9e0 + 0x3e60c));
          if ((pcVar4 == (char *)0x0) &&
             (pcVar4 = strstr(param_1,(char *)(DAT_0003e9e4 + 0x3e624)), pcVar4 == (char *)0x0)) {
            uVar7 = FUN_0003bf60(acStack_900c8);
            snprintf(acStack_90028,400,(char *)(DAT_0003e9e8 + 0x3e648),uVar6,uVar7);
            iVar2 = acosNvramConfig_match(DAT_0003e9f0 + 0x3e664,DAT_0003e9ec + 0x3e660);
            if (iVar2 != 0) {
              uVar7 = 0x2e6;
              iVar2 = DAT_0003e9f4 + 0x3e6fc;
              pcVar4 = (char *)(DAT_0003e9f8 + 0x3e68c);
LAB_0003e6e8:
              printf(pcVar4,iVar2,uVar7,param_1);
            }
          }
          else {
            uVar7 = FUN_0003bf60(acStack_900c8);
            snprintf(acStack_90028,400,(char *)(DAT_0003e9fc + 0x3e6a8),uVar6,uVar7);
            iVar2 = acosNvramConfig_match(DAT_0003ea04 + 0x3e6c4,DAT_0003ea00 + 0x3e6c0);
            if (iVar2 != 0) {
              uVar7 = 0x2ef;
              iVar2 = (int)&DAT_0003e75c + DAT_0003ea08;
              pcVar4 = (char *)(DAT_0003ea0c + 0x3e6ec);
              goto LAB_0003e6e8;
            }
          }
          sVar8 = strlen(acStack_90028);
          iVar2 = FUN_0002c068(param_2,acStack_90028,sVar8,0);
          if (uVar6 != 0 && iVar2 != -1) {
            FUN_0002c068(param_2,acStack_80024,uVar6,0);
          }
          fclose(pFVar5);
          uVar7 = 0x2fb;
          iVar2 = DAT_0003ea10 + 0x3e7cb;
          pcVar4 = (char *)((int)&DAT_0003e750 + DAT_0003ea14);
          goto LAB_0003e4d4;
        }
        FUN_0003b188(acStack_900c8,pFVar5);
        FUN_0003bbfc(param_2,*(undefined4 *)(iVar13 + DAT_0003e76c),DAT_0003e9d4 + 0x3e59c);
        snprintf(pcVar3,0x400,(char *)(DAT_0003e9dc + 0x3e5cc),DAT_0003e9d8 + 0x3e647,0x2cd);
      }
    }
    FUN_0002b2a8(0,pcVar3);
    goto LAB_0003f0e0;
  }
  pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003ea50 + 0x3eca8));
  if ((pcVar4 == (char *)0x0) ||
     (pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003ea54 + 0x3ecc0)),
     pcVar4 == (char *)0x0 || param_3 == 0)) {
    iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003ea58 + 0x3ecec));
    if (iVar2 == 0) {
      iVar2 = DAT_0003ea5c + 0x3ed8f;
      pcVar4 = (char *)(DAT_0003ea60 + 0x3ed18);
      snprintf(pcVar3,0x400,pcVar4,iVar2,0x345);
      FUN_0002b2a8(0,pcVar3);
      FUN_00046e7c(param_2);
      uVar7 = 0x348;
LAB_0003eda0:
      snprintf(pcVar3,0x400,pcVar4,iVar2,uVar7);
    }
    else {
      iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003ea64 + 0x3ed50));
      if (iVar2 == 0) {
        iVar2 = DAT_0003ea68 + 0x3edf3;
        pcVar4 = (char *)(DAT_0003ea6c + 0x3ed7c);
        snprintf(pcVar3,0x400,pcVar4,iVar2,0x350);
        FUN_0002b2a8(0,pcVar3);
        FUN_00047428(param_2);
        uVar7 = 0x353;
        goto LAB_0003eda0;
      }
      iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003ea70 + 0x3edd4));
      if (((iVar2 == 0) ||
          (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003ea74 + 0x3edec)), iVar2 == 0)) ||
         (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003ea78 + 0x3ee04)), iVar2 == 0)) {
        iVar2 = DAT_0003ea7c + 0x3eea7;
        pcVar4 = (char *)(DAT_0003ea80 + 0x3ee30);
        snprintf(pcVar3,0x400,pcVar4,iVar2,0x35d);
        FUN_0002b2a8(0,pcVar3);
        FUN_000a6814(param_2,acStack_900c8);
        uVar7 = 0x360;
      }
      else {
        pcVar4 = strstr(param_1,(char *)(DAT_0003ea84 + 0x3ee74));
        if (pcVar4 != (char *)0x0) {
          iVar2 = acosNvramConfig_match(DAT_0003ea8c + 0x3ee90,DAT_0003ea88 + 0x3ee8c);
          if (iVar2 != 0) {
            printf((char *)(DAT_0003ea94 + 0x3eeb8),DAT_0003ea90 + 0x3ef28,0x369,param_1);
          }
          snprintf(acStack_90028,DAT_0003eaa8,(char *)(DAT_0003ea98 + 0x3eed4),param_1);
          pcVar4 = strstr(acStack_90028,(char *)(DAT_0003ea9c + 0x3eee8));
          if (pcVar4 != (char *)0x0) {
            memset(acStack_80024,0,DAT_0003eaa8);
            if (*pcVar4 == '/') {
              pcVar3 = (char *)(DAT_0003eaa0 + 0x3ef20);
            }
            else {
              pcVar3 = (char *)(DAT_0003eaa4 + 0x3ef28);
            }
            snprintf(acStack_80024,DAT_0003eaa8,pcVar3,pcVar4);
            pcVar4 = strchr(acStack_80024,0x3f);
            if (pcVar4 != (char *)0x0) {
              *pcVar4 = '\0';
            }
            iVar2 = access(acStack_80024,0);
            if (iVar2 == 0) {
              printf((char *)(DAT_0003eab0 + 0x3ef80),DAT_0003eaac + 0x3eff3,0x386,puStack_90124,
                     param_1);
              FUN_000a58cc(puStack_90124,param_2,param_1,0);
            }
          }
          goto LAB_0003f0a8;
        }
        iVar2 = acosNvramConfig_match(DAT_0003eab8 + 0x3efac,DAT_0003eab4 + 0x3efa8);
        if (iVar2 != 0) {
          printf((char *)(DAT_0003eac0 + 0x3efd4),DAT_0003eabc + 0x3f044,0x394,param_1);
        }
        pcVar4 = strchr(param_1,0x3f);
        iVar2 = DAT_0003eac8;
        iVar13 = DAT_0003eac4 + 0x3efec;
        pcVar12 = pcVar4;
        if (pcVar4 != (char *)0x0) {
          pcVar12 = pcVar4 + 1;
          *pcVar4 = '\0';
        }
        iVar2 = acosNvramConfig_match(iVar2 + 0x3effc,iVar13);
        if (iVar2 != 0) {
          printf((char *)(DAT_0003ead0 + 0x3f02c),DAT_0003eacc + 0x3f098,0x39f,param_1,pcVar12);
        }
        iVar2 = DAT_0003ead4 + 0x3f0c7;
        pcVar4 = (char *)(DAT_0003ead8 + 0x3f050);
        snprintf(pcVar3,0x400,pcVar4,iVar2,0x3a0);
        FUN_0002b2a8(0,pcVar3);
        FUN_0003c924(param_1,pcVar12,param_2,param_3,pcVar12);
        uVar7 = 0x3a3;
      }
      snprintf(pcVar3,0x400,pcVar4,iVar2,uVar7);
    }
    FUN_0002b2a8(0,pcVar3);
  }
  else {
    FUN_0004884c(param_2);
  }
LAB_0003f0a8:
  iVar2 = acosNvramConfig_match(DAT_0003eae0 + 0x3f0bc,DAT_0003eadc + 0x3f0b8);
  if (iVar2 != 0) {
    printf((char *)(DAT_0003eae8 + 0x3f0e0),&UNK_0003f150 + DAT_0003eae4,0x3a7);
  }
LAB_0003f0e0:
  if (iVar10 == *piVar11) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== ENTRY 0003ff28 =====
===== FUNCTION FUN_0003ff28 @ 0003ff28 =====

void FUN_0003ff28(char *param_1)

{
  int iVar1;
  char *pcVar2;
  ulong uVar3;
  in_addr_t iVar4;
  in_addr_t iVar5;
  int iVar6;
  FILE *__stream;
  char *pcVar7;
  in_addr_t iVar8;
  in_addr_t iVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  int iVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  undefined8 uVar18;
  int local_2cd0;
  int local_2ccc;
  int local_2cc8;
  char *local_2cc4;
  int local_2cc0;
  char *local_2cbc;
  int local_2cb8;
  char acStack_2cb4 [128];
  char acStack_2c34 [640];
  char acStack_29b4 [128];
  undefined1 auStack_2934 [4096];
  char acStack_1934 [16];
  char acStack_1924 [16];
  undefined1 auStack_1914 [16];
  char local_1904 [20];
  char local_18f0 [20];
  char local_18dc [20];
  undefined4 local_18c8;
  undefined1 auStack_18c4 [60];
  char local_1888 [100];
  char acStack_1824 [2048];
  undefined4 local_1024;
  undefined1 auStack_1020 [4092];
  int local_24;
  
  piVar15 = *(int **)(DAT_000405a0 + 0x3ff38 + DAT_000405a4);
  local_24 = *piVar15;
  local_1024 = 0;
  memset(auStack_1020,0,0xffc);
  local_18c8 = 0x2d2d;
  memset(auStack_18c4,0,0x3c);
  iVar1 = isValidNetworkAddr(param_1);
  if (iVar1 == 0) {
    pcVar2 = (char *)(DAT_000405a8 + 0x3ffb4);
    pcVar13 = param_1;
LAB_00040038:
    printf(pcVar2,pcVar13);
  }
  else {
    pcVar13 = param_1 + 0x10;
    iVar1 = strncmp(pcVar13,(char *)(DAT_000405ac + 0x3ffcc),2);
    if (iVar1 == 0) {
      uVar3 = strtoul(pcVar13,(char **)0x0,0x10);
      inet_ntoa_b(uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                  uVar3 >> 0x18,acStack_1924);
    }
    else {
      strlcpy(acStack_1924,pcVar13);
    }
    iVar1 = isValidNetmask(acStack_1924);
    if ((iVar1 == 0) && (iVar1 = strcmp(acStack_1924,(char *)(DAT_000405b0 + 0x40024)), iVar1 != 0))
    {
      pcVar2 = (char *)(DAT_000405b4 + 0x4003c);
      goto LAB_00040038;
    }
    pcVar13 = param_1 + 0x20;
    uVar18 = isValidIpAddr(pcVar13);
    if ((int)uVar18 == 0) {
      pcVar2 = (char *)(DAT_000405b8 + 0x40060);
      goto LAB_00040038;
    }
    uVar10 = acosNvramConfig_get(DAT_000405bc + 0x4006c,(int)((ulonglong)uVar18 >> 0x20));
    strlcpy(&local_1024,uVar10,0x1000);
    iVar1 = getTokens(&local_1024,DAT_000405c0 + 0x400a0,auStack_2934,0x20);
    if (0x1f < iVar1) {
      pcVar13 = (char *)0x20;
      pcVar2 = (char *)(DAT_000405c4 + 0x400bc);
      goto LAB_00040038;
    }
    iVar4 = inet_addr(param_1);
    iVar5 = inet_addr(acStack_1924);
    inet_ntoa_b(iVar5 & iVar4,acStack_1934);
    iVar11 = DAT_000405c8 + 0x40100;
    for (iVar14 = 0; iVar14 < iVar1; iVar14 = iVar14 + 1) {
      getTokens(auStack_2934 + iVar14 * 0x80,iVar11,acStack_2cb4,7);
      iVar4 = inet_addr(acStack_1934);
      iVar5 = inet_addr(acStack_2cb4);
      if (iVar4 == iVar5) {
        iVar4 = inet_addr(acStack_1924);
        iVar5 = inet_addr(acStack_2c34);
        if (iVar4 == iVar5) {
          pcVar13 = (char *)(DAT_000405cc + 0x4016c);
          goto LAB_0004056c;
        }
      }
      iVar6 = strcmp(param_1 + 0x3c,acStack_29b4);
      if (iVar6 == 0) {
        pcVar13 = (char *)(DAT_000405d0 + 0x40188);
        goto LAB_0004056c;
      }
    }
    uVar17 = *(uint *)(param_1 + 0x30);
    if (uVar17 < 0x11) {
      uVar12 = *(uint *)(param_1 + 0x34);
      if (1 < uVar12) {
        pcVar13 = (char *)(DAT_000405d8 + 0x401bc);
        goto LAB_000401d0;
      }
      uVar16 = *(uint *)(param_1 + 0x38);
      if (1 < uVar16) {
        pcVar13 = (char *)(DAT_000405dc + 0x401d4);
        goto LAB_000401d0;
      }
      strlcpy(acStack_1824,param_1 + 0x3c,0x800);
      strlcpy(&local_18c8,acStack_1824,0x40);
      snprintf(acStack_1824,0x800,(char *)(DAT_000405e0 + 0x40228),acStack_1934,acStack_1924,pcVar13
               ,uVar17,uVar12,uVar16,&local_18c8);
      if (iVar1 == 0) {
        strlcpy(&local_1024,acStack_1824);
      }
      else {
        strlcat(&local_1024,DAT_000405e4 + 0x40268,0x1000);
        strlcat(&local_1024,acStack_1824,0x1000);
      }
      iVar1 = isLanSubnet(pcVar13);
      if (iVar1 == 0) {
        iVar1 = isSecWanSubnet(pcVar13);
        if (iVar1 != 0) {
          iVar1 = DAT_000405ec + 0x402b0;
          goto LAB_00040318;
        }
        iVar11 = DAT_000405f0 + 0x402c0;
        iVar1 = acosNvramConfig_match(iVar11,DAT_000405f4 + 0x402c4);
        if (((iVar1 == 0) &&
            (iVar1 = acosNvramConfig_match(iVar11,DAT_000405fc + 0x402f0), iVar1 == 0)) &&
           (iVar1 = acosNvramConfig_match(iVar11,DAT_00040600 + 0x40308), iVar1 == 0)) {
          iVar1 = DAT_00040604 + 0x4031c;
          goto LAB_00040318;
        }
        iVar1 = DAT_000405f8 + 0x402e0;
      }
      else {
        iVar1 = DAT_000405e8 + 0x40298;
LAB_00040318:
        iVar1 = acosNvramConfig_get(iVar1);
      }
      strlcpy(auStack_1914,iVar1,0x10);
      local_1888[0] = '\0';
      local_1888[1] = '\0';
      local_1888[2] = '\0';
      local_1888[3] = '\0';
      memset(local_1888 + 4,0,0x60);
      local_1904[0] = '\0';
      local_1904[1] = '\0';
      local_1904[2] = '\0';
      local_1904[3] = '\0';
      memset(local_1904 + 4,0,0x10);
      local_18f0[0] = '\0';
      local_18f0[1] = '\0';
      local_18f0[2] = '\0';
      local_18f0[3] = '\0';
      memset(local_18f0 + 4,0,0x10);
      local_18dc[0] = '\0';
      local_18dc[1] = '\0';
      local_18dc[2] = '\0';
      local_18dc[3] = '\0';
      memset(local_18dc + 4,0,0x10);
      iVar4 = inet_addr(acStack_1934);
      iVar5 = inet_addr(acStack_1924);
      system((char *)(DAT_00040608 + 0x403b8));
      __stream = fopen64((char *)(DAT_00040610 + 0x403cc),(char *)(DAT_0004060c + 0x403c8));
      if (__stream != (FILE *)0x0) {
        pcVar2 = (char *)(DAT_00040614 + 0x403e4);
        iVar1 = DAT_00040618 + 0x403f0;
        do {
          do {
            pcVar7 = fgets(local_1888,100,__stream);
            if (pcVar7 == (char *)0x0) goto LAB_000404fc;
          } while ((local_1888[0] == 'K' || local_1888[0] == 'D') ||
                  (iVar11 = strncmp(local_1888,pcVar2,9), iVar11 == 0));
          __isoc99_sscanf(local_1888,iVar1,local_1904,local_18dc,local_18f0);
          iVar8 = inet_addr(local_1904);
          iVar9 = inet_addr(local_18f0);
        } while (((iVar4 & iVar5) != (iVar9 & iVar8)) ||
                (iVar11 = strcmp(local_18dc,pcVar13), iVar11 != 0));
        local_2cd0 = DAT_0004061c + 0x404c0;
        local_2ccc = DAT_00040620 + 0x404d0;
        local_2cc8 = DAT_00040624 + 0x404e0;
        local_2cc0 = DAT_00040628 + 0x404f0;
        local_2cc4 = local_1904;
        local_2cbc = local_18f0;
        local_2cb8 = iVar11;
        _eval_daemon(&local_2cd0,DAT_0004062c + 0x404fc,0,0,0);
LAB_000404fc:
        fclose(__stream);
        remove((char *)(DAT_00040630 + 0x40510));
      }
      iVar1 = route_add(auStack_1914,uVar17,acStack_1934,pcVar13,acStack_1924);
      if (uVar12 == 0 && iVar1 == 0) {
        route_del(auStack_1914,uVar17,acStack_1934,pcVar13,acStack_1924);
      }
      iVar1 = acosNvramConfig_set(DAT_00040634 + 0x4055c,&local_1024);
      uVar10 = 0;
      if (iVar1 == 0) goto LAB_00040574;
      pcVar13 = (char *)(DAT_00040638 + 0x40570);
LAB_0004056c:
      printf(pcVar13);
    }
    else {
      pcVar13 = (char *)(DAT_000405d4 + 0x401a4);
LAB_000401d0:
      puts(pcVar13);
    }
  }
  uVar10 = 0xffffffff;
LAB_00040574:
  if (local_24 == *piVar15) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar10);
}


===== ENTRY 00047428 =====
===== FUNCTION FUN_00047428 @ 00047428 =====

void FUN_00047428(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  FILE *pFVar3;
  char *pcVar4;
  size_t sVar5;
  FILE *__stream;
  FILE *__stream_00;
  void *__ptr;
  undefined4 uVar6;
  size_t sVar7;
  char *pcVar8;
  int iVar9;
  int *piVar10;
  char *__s;
  char *pcVar11;
  char acStack_298 [8];
  char acStack_290 [8];
  undefined1 auStack_288 [32];
  undefined1 auStack_268 [32];
  undefined1 auStack_248 [64];
  char acStack_208 [100];
  char acStack_1a4 [128];
  char acStack_124 [256];
  int local_24;
  
  piVar10 = *(int **)(DAT_000483d8 + 0x4743c + DAT_000483dc);
  local_24 = *piVar10;
  strcpy(acStack_298,(char *)(DAT_000483e0 + 0x47454));
  strcpy(acStack_290,(char *)(DAT_000483e4 + 0x47474));
  system((char *)(DAT_000483e8 + 0x47480));
  isTriBand();
  FUN_00046df4();
  iVar2 = acosNvramConfig_match(DAT_000483f0 + 0x4749c,DAT_000483ec + 0x47498);
  if (iVar2 != 0) {
    system((char *)(DAT_000483f4 + 0x474b8));
    pFVar3 = fopen64((char *)(DAT_000483fc + 0x474cc),(char *)(DAT_000483f8 + 0x474c8));
    if (pFVar3 != (FILE *)0x0) {
      pcVar8 = (char *)(DAT_00048400 + 0x474e4);
      pcVar11 = (char *)(DAT_00048404 + 0x474ec);
      iVar2 = DAT_00048408 + 0x474f4;
      while( true ) {
        pcVar4 = fgets(acStack_1a4,0x80,pFVar3);
        if (pcVar4 == (char *)0x0) break;
        system(pcVar8);
        __isoc99_sscanf(acStack_1a4,iVar2,auStack_288,auStack_248);
        snprintf(acStack_124,0x100,pcVar11,auStack_248);
        system(acStack_124);
      }
      fclose(pFVar3);
    }
    snprintf(acStack_124,0x100,(char *)(DAT_0004840c + 0x47570),acStack_290);
    system(acStack_124);
    pFVar3 = fopen64((char *)(DAT_00048414 + 0x4758c),(char *)(DAT_00048410 + 0x47588));
    if (pFVar3 != (FILE *)0x0) {
      pcVar8 = (char *)(DAT_00048418 + 0x475a4);
      iVar2 = DAT_0004841c + 0x475ac;
      pcVar11 = (char *)(DAT_00048420 + 0x475b4);
      while( true ) {
        pcVar4 = fgets(acStack_1a4,0x80,pFVar3);
        if (pcVar4 == (char *)0x0) break;
        snprintf(acStack_124,0x100,pcVar8,acStack_290);
        system(acStack_124);
        __isoc99_sscanf(acStack_1a4,iVar2,auStack_288,auStack_248);
        snprintf(acStack_124,0x100,pcVar11,acStack_290,auStack_248);
        system(acStack_124);
      }
      fclose(pFVar3);
    }
    iVar9 = DAT_0004842c;
    iVar2 = DAT_00048428;
    system((char *)(DAT_00048424 + 0x4764c));
    system((char *)(DAT_00048430 + 0x47664));
    system((char *)(DAT_00048434 + 0x47670));
    system((char *)(DAT_00048438 + 0x4767c));
    snprintf(acStack_124,0x100,(char *)(DAT_0004843c + 0x47690),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(DAT_00048440 + 0x476b0),acStack_290);
    system(acStack_124);
    system((char *)(DAT_00048444 + 0x476c8));
    system((char *)(DAT_00048448 + 0x476d4));
    snprintf(acStack_124,0x100,(char *)(DAT_0004844c + 0x476e8),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(DAT_00048450 + 0x47708),acStack_290);
    system(acStack_124);
    system((char *)(DAT_00048454 + 0x47720));
    system((char *)(DAT_00048458 + 0x4772c));
    snprintf(acStack_124,0x100,(char *)(DAT_0004845c + 0x47740),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(DAT_00048460 + 0x47760),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(iVar2 + 0x4765c),acStack_298);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(iVar9 + 0x47660),acStack_298);
    system(acStack_124);
    iVar1 = DAT_00048464;
    snprintf(acStack_124,0x100,(char *)(iVar2 + 0x4765c),acStack_290);
    system(acStack_124);
    iVar2 = DAT_00048468;
    snprintf(acStack_124,0x100,(char *)(iVar9 + 0x47660),acStack_290);
    system(acStack_124);
    system((char *)(DAT_0004846c + 0x477f8));
    system((char *)(iVar2 + 0x477f0));
    snprintf(acStack_124,0x100,(char *)(DAT_00048470 + 0x47814),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(DAT_00048474 + 0x47834),acStack_290);
    system(acStack_124);
    system((char *)(DAT_00048478 + 0x4784c));
    system((char *)(DAT_0004847c + 0x47858));
    system((char *)(iVar2 + 0x477f0));
    snprintf(acStack_124,0x100,(char *)(DAT_00048480 + 0x47874),acStack_290);
    system(acStack_124);
    iVar2 = DAT_00048488;
    snprintf(acStack_124,0x100,(char *)(DAT_00048484 + 0x47894),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(iVar1 + 0x477f4),acStack_298);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(iVar2 + 0x478ac),acStack_298);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(iVar1 + 0x477f4),acStack_290);
    system(acStack_124);
    pcVar11 = (char *)(DAT_0004848c + 0x47918);
    snprintf(acStack_124,0x100,(char *)(iVar2 + 0x478ac),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,pcVar11,acStack_298);
    system(acStack_124);
    pcVar8 = (char *)(DAT_00048490 + 0x47950);
    snprintf(acStack_124,0x100,pcVar8,acStack_298);
    system(acStack_124);
    snprintf(acStack_124,0x100,pcVar11,acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,pcVar8,acStack_290);
    system(acStack_124);
  }
  iVar2 = acosNvramConfig_match(DAT_00048498 + 0x479ac,DAT_00048494 + 0x479a8);
  if (iVar2 != 0) {
    system((char *)(DAT_0004849c + 0x479c0));
    system((char *)(DAT_000484a0 + 0x479cc));
    system((char *)(DAT_000484a4 + 0x479d8));
    system((char *)(DAT_000484a8 + 0x479e4));
    system((char *)(DAT_000484ac + 0x479f0));
    system((char *)(DAT_000484b0 + 0x479fc));
  }
  iVar2 = acosNvramConfig_match(DAT_000484b8 + 0x47a10,DAT_000484b4 + 0x47a0c);
  if (iVar2 == 0) {
    system((char *)(DAT_000484bc + 0x47a24));
    system((char *)(DAT_000484c0 + 0x47a30));
  }
  pcVar11 = (char *)(DAT_000484c4 + 0x47a40);
  iVar9 = DAT_000484c8 + 0x47a48;
  pcVar8 = (char *)(DAT_000484cc + 0x47a50);
  system(pcVar11);
  acosNvramConfig_set(DAT_000484d0 + 0x47a60,iVar9);
  acosNvramConfig_set(DAT_000484d4 + 0x47a70,iVar9);
  acosNvramConfig_set(DAT_000484d8 + 0x47a80,iVar9);
  acosNvramConfig_set(DAT_000484dc + 0x47a90,iVar9);
  iVar2 = DAT_000484e4;
  acosNvramConfig_set(DAT_000484e0 + 0x47aa4,iVar9);
  FUN_00047008();
  system((char *)(DAT_000484e8 + 0x47ab8));
  system((char *)(DAT_000484ec + 0x47ac4));
  system((char *)(DAT_000484f0 + 0x47ad0));
  system((char *)(DAT_000484f4 + 0x47adc));
  system((char *)(DAT_000484f8 + 0x47ae8));
  system((char *)(DAT_000484fc + 0x47af4));
  system((char *)(DAT_00048500 + 0x47b00));
  system((char *)(DAT_00048504 + 0x47b0c));
  system((char *)(DAT_00048508 + 0x47b18));
  system((char *)(DAT_0004850c + 0x47b24));
  system((char *)(DAT_00048510 + 0x47b30));
  system((char *)(DAT_00048514 + 0x47b3c));
  system((char *)(iVar2 + 0x47aac));
  system(pcVar8);
  iVar9 = DAT_00048518;
  system((char *)(iVar2 + 0x47aac));
  system((char *)(DAT_0004851c + 0x47b68));
  system((char *)(iVar9 + 0x47b64));
  system(pcVar8);
  system((char *)(iVar9 + 0x47b64));
  system((char *)(DAT_00048520 + 0x47b94));
  system((char *)(DAT_00048524 + 0x47ba0));
  system((char *)(DAT_00048528 + 0x47bac));
  system((char *)(DAT_0004852c + 0x47bb8));
  system((char *)(DAT_00048530 + 0x47bc4));
  system((char *)(DAT_00048534 + 0x47bd0));
  system((char *)(DAT_00048538 + 0x47bdc));
  system((char *)(DAT_0004853c + 0x47be8));
  system((char *)(DAT_00048540 + 0x47bf4));
  system((char *)(DAT_00048544 + 0x47c00));
  system((char *)(DAT_00048548 + 0x47c0c));
  system((char *)(DAT_0004854c + 0x47c18));
  system((char *)(DAT_00048550 + 0x47c24));
  system((char *)(DAT_00048554 + 0x47c30));
  system((char *)(DAT_00048558 + 0x47c3c));
  system((char *)(DAT_0004855c + 0x47c48));
  system((char *)(DAT_00048560 + 0x47c54));
  system((char *)(DAT_00048564 + 0x47c60));
  system((char *)(DAT_00048568 + 0x47c6c));
  system((char *)(DAT_0004856c + 0x47c78));
  system((char *)(DAT_00048570 + 0x47c84));
  system((char *)(DAT_00048574 + 0x47c90));
  system((char *)(DAT_00048578 + 0x47c9c));
  system((char *)(DAT_0004857c + 0x47ca8));
  system((char *)(DAT_00048580 + 0x47cb4));
  system((char *)(DAT_00048584 + 0x47cc0));
  system((char *)(DAT_00048588 + 0x47ccc));
  system((char *)(DAT_0004858c + 0x47cd8));
  system((char *)(DAT_00048590 + 0x47ce4));
  system((char *)(DAT_00048594 + 0x47cf0));
  system((char *)(DAT_00048598 + 0x47cfc));
  system((char *)(DAT_0004859c + 0x47d08));
  snprintf(acStack_124,0x100,(char *)(DAT_000485a0 + 0x47d1c),acStack_290);
  system(acStack_124);
  snprintf(acStack_124,0x100,(char *)(DAT_000485a4 + 0x47d3c),acStack_290);
  system(acStack_124);
  snprintf(acStack_124,0x100,(char *)(DAT_000485a8 + 0x47d5c),acStack_290);
  system(acStack_124);
  system((char *)(DAT_000485ac + 0x47d74));
  system((char *)(DAT_000485b0 + 0x47d80));
  system((char *)(DAT_000485b4 + 0x47d8c));
  system((char *)(DAT_000485b8 + 0x47d98));
  system((char *)(DAT_000485bc + 0x47da4));
  system((char *)(DAT_000485c0 + 0x47db0));
  system((char *)(DAT_000485c4 + 0x47dbc));
  system((char *)(DAT_000485c8 + 0x47dc8));
  system((char *)(DAT_000485cc + 0x47dd4));
  system((char *)(DAT_000485d0 + 0x47de0));
  system((char *)(DAT_000485d4 + 0x47dec));
  system((char *)(DAT_000485d8 + 0x47df8));
  system((char *)(DAT_000485dc + 0x47e04));
  system((char *)(DAT_000485e0 + 0x47e10));
  system((char *)(DAT_000485e4 + 0x47e1c));
  system((char *)(DAT_000485e8 + 0x47e28));
  system(pcVar11);
  system((char *)(DAT_000485ec + 0x47e3c));
  iVar2 = acosNvramConfig_match(DAT_000485f4 + 0x47e50,DAT_000485f0 + 0x47e4c);
  if (iVar2 != 0) {
    system((char *)(DAT_000485f8 + 0x47e64));
  }
  system((char *)(DAT_000485fc + 0x47e70));
  SYSTEM(DAT_00048608 + 0x47e8c,DAT_00048604 + 0x47e88,DAT_00048600 + 0x47e84);
  system((char *)(DAT_0004860c + 0x47e98));
  system((char *)(DAT_00048610 + 0x47ea4));
  system((char *)(DAT_00048614 + 0x47eb0));
  iVar2 = acosNvramConfig_match(DAT_0004861c + 0x47ec4,DAT_00048618 + 0x47ec0);
  if (iVar2 != 0) {
    system((char *)(DAT_00048620 + 0x47ed8));
    system((char *)(DAT_00048624 + 0x47ee4));
    system((char *)(DAT_00048628 + 0x47ef0));
    system((char *)(DAT_0004862c + 0x47efc));
    system((char *)(DAT_00048630 + 0x47f08));
    system((char *)(DAT_00048634 + 0x47f14));
    system((char *)(DAT_00048638 + 0x47f20));
    system((char *)(DAT_0004863c + 0x47f2c));
    system((char *)(DAT_00048640 + 0x47f38));
    system((char *)(DAT_00048644 + 0x47f44));
  }
  iVar2 = DAT_0004864c;
  system((char *)(DAT_00048648 + 0x47f58));
  pcVar4 = (char *)(iVar2 + 0x47f64);
  system((char *)(DAT_00048650 + 0x47f68));
  memset(auStack_268,0,0x20);
  FUN_00047364(auStack_268,0x20);
  doSystem(DAT_00048654 + 0x47f94,auStack_268);
  system((char *)(DAT_00048658 + 0x47fa0));
  pFVar3 = fopen64((char *)(DAT_00048660 + 0x47fb4),(char *)(DAT_0004865c + 0x47fb0));
  fseek(pFVar3,0,2);
  sVar5 = ftell(pFVar3);
  fseek(pFVar3,0,0);
  pcVar8 = calloc(1,sVar5);
  fread(pcVar8,1,sVar5,pFVar3);
  pcVar11 = strstr(pcVar8,(char *)(DAT_00048664 + 0x48010));
  __stream = fopen64((char *)(DAT_00048668 + 0x48024),pcVar4);
  if ((int)sVar5 < 0xa00001) {
    if (0x500000 < (int)sVar5) {
      __stream_00 = fopen64((char *)(DAT_00048670 + 0x480a8),pcVar4);
      fputs(pcVar8 + 0x500000,__stream_00);
      pcVar8[0x500000] = '\0';
      fputs(pcVar8,__stream);
      goto LAB_000480d0;
    }
    system((char *)(DAT_00048674 + 0x480e4));
  }
  else {
    __s = pcVar8 + 0x500000;
    __stream_00 = fopen64((char *)(DAT_0004866c + 0x48044),pcVar4);
    __s[0x500000 - (sVar5 - ((int)pcVar11 - (int)pcVar8))] = '\0';
    fputs(__s,__stream_00);
    *__s = '\0';
    fputs(pcVar8,__stream);
    fputs(pcVar11,__stream_00);
LAB_000480d0:
    fclose(__stream_00);
  }
  fclose(pFVar3);
  fclose(__stream);
  free(pcVar8);
  iVar2 = acosNvramConfig_match(DAT_0004867c + 0x48110,DAT_00048678 + 0x4810c);
  if (iVar2 != 0) {
    system((char *)(DAT_00048680 + 0x48124));
    system((char *)(DAT_00048684 + 0x48130));
    system((char *)(DAT_00048688 + 0x4813c));
    system((char *)(DAT_0004868c + 0x48148));
    system((char *)(DAT_00048690 + 0x48154));
    system((char *)(DAT_00048694 + 0x48160));
    system((char *)(DAT_00048698 + 0x4816c));
    system((char *)(DAT_0004869c + 0x48178));
    system((char *)(DAT_000486a0 + 0x48184));
  }
  SYSTEM(DAT_000486a4 + 0x48190);
  SYSTEM(DAT_000486a8 + 0x4819c);
  SYSTEM(DAT_000486ac + 0x481a8);
  SYSTEM(DAT_000486b0 + 0x481b4);
  SYSTEM(DAT_000486b4 + 0x481c0);
  SYSTEM(DAT_000486b8 + 0x481cc);
  system((char *)(DAT_000486bc + 0x481d8));
  system((char *)(DAT_000486c0 + 0x481e4));
  iVar2 = FUN_00047284();
  if (iVar2 == 0) {
    pcVar8 = (char *)(DAT_000486c8 + 0x48200);
  }
  else {
    pcVar8 = (char *)(DAT_000486c4 + 0x481f8);
  }
  system(pcVar8);
  iVar9 = DAT_000486d4;
  iVar2 = DAT_000486d0;
  system((char *)(DAT_000486cc + 0x48210));
  iVar1 = DAT_000486dc;
  iVar9 = iVar9 + 0x48224;
  system((char *)(DAT_000486d8 + 0x48228));
  system((char *)(DAT_000486e0 + 0x4823c));
  system((char *)(DAT_000486e4 + 0x48248));
  system((char *)(DAT_000486e8 + 0x48254));
  system((char *)(DAT_000486ec + 0x48260));
  system((char *)(DAT_000486f0 + 0x4826c));
  system((char *)(DAT_000486f4 + 0x48278));
  system((char *)(DAT_000486f8 + 0x48284));
  system((char *)(DAT_000486fc + 0x48290));
  system((char *)(DAT_00048700 + 0x4829c));
  system((char *)(DAT_00048704 + 0x482a8));
  system((char *)(DAT_00048708 + 0x482b4));
  system((char *)(DAT_0004870c + 0x482c0));
  system((char *)(iVar2 + 0x48220));
  system((char *)(DAT_00048710 + 0x482d4));
  system((char *)(DAT_00048714 + 0x482e0));
  system((char *)(DAT_00048718 + 0x482ec));
  SYSTEM(DAT_00048720 + 0x48300,DAT_0004871c + 0x482fc);
  system((char *)(DAT_00048724 + 0x4830c));
  system((char *)(DAT_00048728 + 0x48318));
  system((char *)(iVar2 + 0x48220));
  system((char *)(DAT_0004872c + 0x4832c));
  system((char *)(DAT_00048730 + 0x48338));
  acosNvramConfig_set(DAT_00048734 + 0x48348,iVar9);
  acosNvramConfig_unset(DAT_00048738 + 0x48354);
  acosNvramConfig_unset(DAT_0004873c + 0x48360);
  sleep(1);
  pFVar3 = fopen64((char *)(iVar1 + 0x48238),(char *)(DAT_00048740 + 0x48378));
  if (pFVar3 == (FILE *)0x0) {
    puts((char *)(DAT_00048744 + 0x4838c));
  }
  else {
    fseek(pFVar3,0,2);
    sVar5 = ftell(pFVar3);
    __ptr = calloc(1,sVar5);
    if (__ptr != (void *)0x0) {
      fseek(pFVar3,0,0);
      sVar5 = fread(__ptr,1,sVar5,pFVar3);
      fclose(pFVar3);
      printf((char *)(DAT_00048750 + 0x487b0),DAT_0004874c + 0x487b4,0x41d);
      unlink((char *)(iVar1 + 0x48238));
      acosNvramConfig_set(DAT_00048754 + 0x487c8,iVar9);
      acosNvramConfig_set(DAT_00048758 + 0x487d8,iVar9);
      snprintf(acStack_208,100,(char *)(DAT_0004875c + 0x487ec),sVar5);
      sVar7 = strlen(acStack_208);
      FUN_0002c068(param_1,acStack_208,sVar7,0);
      FUN_0002c068(param_1,__ptr,sVar5,0);
      free(__ptr);
      uVar6 = 0;
      goto LAB_0004882c;
    }
    puts((char *)(DAT_00048748 + 0x483c8));
    fclose(pFVar3);
  }
  uVar6 = 0xffffffff;
LAB_0004882c:
  if (local_24 == *piVar10) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar6);
}


===== ENTRY 0007ba10 =====
===== FUNCTION FUN_0007ba10 @ 0007ba10 =====

void FUN_0007ba10(undefined4 param_1)

{
  FILE *__stream;
  char *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char acStack_a4 [128];
  int local_24;
  
  iVar3 = DAT_0007bad0 + 0x7ba2c;
  piVar2 = *(int **)(iVar3 + DAT_0007bad4);
  local_24 = *piVar2;
  __stream = popen((char *)(DAT_0007badc + 0x7ba40),(char *)(DAT_0007bad8 + 0x7ba3c));
  if (__stream != (FILE *)0x0) {
    iVar4 = DAT_0007bae0 + 0x7ba64;
    while (pcVar1 = fgets(acStack_a4,0x80,__stream), pcVar1 != (char *)0x0) {
      pcVar1 = strstr(acStack_a4,*(char **)(iVar3 + DAT_0007bae4));
      if (pcVar1 != (char *)0x0) {
        __isoc99_sscanf(acStack_a4,iVar4,param_1);
      }
    }
    pclose(__stream);
  }
  if (local_24 != *piVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


===== ENTRY 0007bae8 =====
===== FUNCTION FUN_0007bae8 @ 0007bae8 =====

void FUN_0007bae8(char *param_1,undefined4 param_2)

{
  int iVar1;
  FILE *__stream;
  FILE *__stream_00;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  char local_144 [32];
  char local_124 [128];
  char local_a4 [128];
  int local_24;
  
  iVar4 = DAT_0007bd94 + 0x7bb08;
  piVar5 = *(int **)(iVar4 + DAT_0007bd98);
  local_124[0] = '\0';
  local_124[1] = '\0';
  local_124[2] = '\0';
  local_124[3] = '\0';
  local_24 = *piVar5;
  memset(local_124 + 4,0,0x7c);
  local_144[0] = '\0';
  local_144[1] = '\0';
  local_144[2] = '\0';
  local_144[3] = '\0';
  memset(local_144 + 4,0,0x1c);
  FUN_0007ba10(local_144);
  iVar1 = access((char *)(DAT_0007bd9c + 0x7bb58),0);
  if (iVar1 == -1) {
    system((char *)(DAT_0007bda0 + 0x7bb70));
  }
  system((char *)(DAT_0007bda4 + 0x7bb7c));
  __stream = fopen64((char *)(DAT_0007bdac + 0x7bb90),(char *)(DAT_0007bda8 + 0x7bb8c));
  if (__stream == (FILE *)0x0) {
    strlcpy(*(undefined4 *)(iVar4 + DAT_0007bdb0),DAT_0007bdb4 + 0x7bbb0,4);
    goto LAB_0007bd70;
  }
  __stream_00 = fopen64((char *)(DAT_0007bdbc + 0x7bbd0),(char *)(DAT_0007bdb8 + 0x7bbcc));
  if (__stream_00 == (FILE *)0x0) {
    strlcpy(*(undefined4 *)(iVar4 + DAT_0007bdb0),DAT_0007bdc0 + 0x7bbf0,4);
    fclose(__stream);
    goto LAB_0007bd70;
  }
  local_a4[0] = '\0';
  local_a4[1] = '\0';
  local_a4[2] = '\0';
  local_a4[3] = '\0';
  memset(local_a4 + 4,0,0x7c);
  FUN_0006ee50(param_2,local_a4);
  pcVar2 = (char *)acosNvramConfig_get(DAT_0007bdc4 + 0x7bc34);
  iVar1 = strcmp(param_1,pcVar2);
  if (iVar1 == 0) {
    pcVar2 = (char *)acosNvramConfig_get(DAT_0007bdc8 + 0x7bc58);
    iVar1 = strcmp(local_a4,pcVar2);
    if (iVar1 != 0) goto LAB_0007bcf4;
    while (pcVar2 = fgets(local_124,0x80,__stream_00), pcVar2 != (char *)0x0) {
      pcVar2 = strstr(local_124,local_144);
      if (pcVar2 == (char *)0x0) {
        fputs(local_124,__stream);
      }
    }
    uVar3 = sys_uptime();
    sprintf(local_124,(char *)(DAT_0007bdcc + 0x7bcbc),local_144,uVar3);
    fputs(local_124,__stream);
  }
  else {
LAB_0007bcf4:
    while (pcVar2 = fgets(local_124,0x80,__stream_00), pcVar2 != (char *)0x0) {
      pcVar2 = strstr(local_124,local_144);
      if (pcVar2 == (char *)0x0) {
        fputs(local_124,__stream);
      }
    }
    strlcpy(*(undefined4 *)(iVar4 + DAT_0007bdb0),DAT_0007bdd0 + 0x7bd24,4);
  }
  fclose(__stream_00);
  fclose(__stream);
  uStack_150 = *(undefined4 *)(DAT_0007bdd4 + 0x7bd68);
  uStack_14c = *(undefined4 *)(DAT_0007bdd4 + 0x7bd6c);
  uStack_148 = *(undefined4 *)(DAT_0007bdd4 + 0x7bd70);
  _eval_daemon(&uStack_150,DAT_0007bdd8 + 0x7bd70,0,0,0);
LAB_0007bd70:
  if (local_24 != *piVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}


===== ENTRY 000a58cc =====
===== FUNCTION FUN_000a58cc @ 000a58cc =====

void FUN_000a58cc(char *param_1,undefined4 param_2,char *param_3,int param_4)

{
  char *pcVar1;
  __pid_t _Var2;
  FILE *pFVar3;
  char *pcVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined4 *puVar14;
  int iStack_20528;
  char acStack_20524 [16];
  undefined1 auStack_20514 [16];
  undefined1 auStack_20504 [32];
  char acStack_204e4 [64];
  char acStack_204a4 [64];
  undefined1 auStack_20464 [64];
  char acStack_20424 [256];
  char acStack_20324 [256];
  char acStack_20224 [512];
  char acStack_20024 [65536];
  char acStack_10024 [65540];
  
  piVar13 = *(int **)(DAT_000a6438 + 0xa58f0 + DAT_000a643c);
  iVar10 = *piVar13;
  pcVar1 = strchr(param_3,0x3b);
  if ((((pcVar1 != (char *)0x0) || (pcVar1 = strchr(param_3,0x60), pcVar1 != (char *)0x0)) ||
      (pcVar1 = strchr(param_3,0x24), pcVar1 != (char *)0x0)) ||
     (pcVar1 = strstr(param_3,(char *)(DAT_000a6440 + 0xa5954)), pcVar1 != (char *)0x0)) {
LAB_000a640c:
    if (iVar10 == *piVar13) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  _Var2 = fork();
  if (_Var2 != 0) {
    if (0 < _Var2) {
      waitpid(_Var2,&iStack_20528,0);
    }
    goto LAB_000a640c;
  }
  _Var2 = fork();
  if (_Var2 != 0) goto LAB_000a63f4;
  memset(acStack_10024,0,0xffff);
  iVar10 = acosNvramConfig_match(DAT_000a6448 + 0xa59a4,DAT_000a6444 + 0xa59a0);
  if (iVar10 != 0) {
    printf((char *)(DAT_000a6450 + 0xa59cc),DAT_000a644c + 0xa59c8,0x47,param_3,param_4);
  }
  pFVar3 = fopen64((char *)(DAT_000a6458 + 0xa59e0),(char *)(DAT_000a6454 + 0xa59dc));
  if (pFVar3 == (FILE *)0x0) {
    system((char *)(DAT_000a645c + 0xa59f4));
    iVar10 = acosNvramConfig_match(DAT_000a6464 + 0xa5a08,DAT_000a6460 + 0xa5a04);
    if (iVar10 != 0) {
      puts((char *)(DAT_000a6468 + 0xa5a1c));
    }
  }
  else {
    fclose(pFVar3);
  }
  pcVar1 = strstr(param_3,(char *)(DAT_000a646c + 0xa5a3c));
  if (pcVar1 != (char *)0x0) {
    iVar10 = acosNvramConfig_match(DAT_000a6474 + 0xa5a58,DAT_000a6470 + 0xa5a54);
    if (iVar10 != 0) {
      printf((char *)(DAT_000a647c + 0xa5a78),DAT_000a6478 + 0xa5a74,0x58);
    }
    pcVar4 = strchr(pcVar1,0x3f);
    if (pcVar4 == (char *)0x0) {
      iVar10 = acosNvramConfig_match(DAT_000a64c4 + 0xa5be8,DAT_000a64c0 + 0xa5be4);
      if (iVar10 != 0) {
        printf((char *)(DAT_000a64cc + 0xa5c08),DAT_000a64c8 + 0xa5c04,0x72);
      }
      pcVar4 = strchr(pcVar1,0x2f);
      if (pcVar4 == (char *)0x0) {
        pcVar7 = (char *)0x0;
      }
      else {
        pcVar7 = strchr(pcVar4 + 1,0x2f);
      }
      memset(acStack_204e4,0,0x40);
      if (pcVar7 == (char *)0x0 || pcVar4 == (char *)0x0) {
        if (pcVar7 == (char *)0x0 && pcVar4 != (char *)0x0) {
          strlcpy(acStack_204e4,pcVar4 + 1,0x40);
        }
      }
      else {
        if ((uint)((int)pcVar7 - (int)pcVar4) < 0x41) {
          strlcpy(acStack_204e4,pcVar4 + 1);
        }
        iVar10 = acosNvramConfig_match(DAT_000a64d4 + 0xa5c80,DAT_000a64d0 + 0xa5c7c);
        if (iVar10 != 0) {
          printf((char *)(DAT_000a64d8 + 0xa5ca4),pcVar1,pcVar4,pcVar7,acStack_204e4);
        }
        pcVar1 = acStack_20324;
        strlcpy(pcVar1,pcVar7,0x100);
        iVar10 = acosNvramConfig_match(DAT_000a64e0 + 0xa5ccc,DAT_000a64dc + 0xa5cc8);
        if (iVar10 != 0) {
          uVar9 = 0x82;
          iVar10 = DAT_000a64e4 + 0xa5cec;
          pcVar4 = (char *)(DAT_000a64e8 + 0xa5cf0);
          goto LAB_000a5cec;
        }
      }
    }
    else {
      iVar10 = acosNvramConfig_match(DAT_000a6484 + 0xa5aa0,DAT_000a6480 + 0xa5a9c);
      if (iVar10 != 0) {
        printf((char *)(DAT_000a648c + 0xa5ac0),DAT_000a6488 + 0xa5abc,0x5c);
      }
      pcVar4 = strchr(pcVar1,0x3f);
      iVar10 = acosNvramConfig_match(DAT_000a6494 + 0xa5ae4,DAT_000a6490 + 0xa5ad8);
      if (iVar10 != 0) {
        printf((char *)(DAT_000a649c + 0xa5b14),DAT_000a6498 + 0xa5b0c,0x5f,pcVar1,pcVar4 + 1);
      }
      strlcpy(acStack_20424,pcVar4 + 1,0x100);
      iVar10 = acosNvramConfig_match(DAT_000a64a4 + 0xa5b3c,DAT_000a64a0 + 0xa5b38);
      if (iVar10 != 0) {
        printf((char *)(DAT_000a64ac + 0xa5b60),DAT_000a64a8 + 0xa5b5c,99,acStack_20424);
      }
      pcVar1 = strchr(param_3,0x2f);
      if (pcVar1 != (char *)0x0) {
        memset(acStack_204e4,0,0x40);
        if ((uint)((int)pcVar4 - (int)pcVar1) < 0x41) {
          strlcpy(acStack_204e4,pcVar1 + 1);
        }
        iVar10 = acosNvramConfig_match(DAT_000a64b4 + 0xa5bb0,DAT_000a64b0 + 0xa5bac);
        if (iVar10 != 0) {
          uVar9 = 0x6c;
          iVar10 = DAT_000a64b8 + 0xa5bd0;
          pcVar4 = (char *)(DAT_000a64bc + 0xa5bd4);
          pcVar1 = acStack_204e4;
LAB_000a5cec:
          printf(pcVar4,iVar10,uVar9,pcVar1);
        }
      }
    }
    puVar14 = (undefined4 *)(DAT_000a64ec + 0xa5d20);
    do {
      puVar14 = puVar14 + 1;
      pcVar1 = (char *)*puVar14;
      if (pcVar1 == (char *)0x0) goto LAB_000a63f4;
      sVar5 = strlen(acStack_204e4);
      sVar6 = strlen(pcVar1);
    } while ((sVar5 != sVar6) || (iVar10 = strncmp(acStack_204e4,pcVar1,sVar5), iVar10 != 0));
  }
  if ((param_4 == 0) || ((param_4 == 1 || (param_4 == 2)))) {
    strlcpy(acStack_20524);
  }
  iVar10 = acosNvramConfig_match(DAT_000a6500 + 0xa5dc0,DAT_000a64fc + 0xa5dbc);
  if (iVar10 != 0) {
    printf((char *)(DAT_000a6508 + 0xa5de4),DAT_000a6504 + 0xa5de0,0xa5,acStack_20524);
  }
  if (acStack_20324[0] != '\0') {
    setenv((char *)(DAT_000a650c + 0xa5e0c),acStack_20324,1);
  }
  iVar10 = acosNvramConfig_match(DAT_000a6514 + 0xa5e20,DAT_000a6510 + 0xa5e1c);
  if (iVar10 != 0) {
    pcVar1 = getenv((char *)(DAT_000a6518 + 0xa5e34));
    printf((char *)(DAT_000a6520 + 0xa5e50),DAT_000a651c + 0xa5e44,0xab,pcVar1);
  }
  pcVar1 = (char *)(DAT_000a6524 + 0xa5e64);
  setenv(pcVar1,(char *)(DAT_000a6528 + 0xa5e68),1);
  iVar10 = acosNvramConfig_match(DAT_000a6530 + 0xa5e80,DAT_000a652c + 0xa5e7c);
  if (iVar10 != 0) {
    pcVar1 = getenv(pcVar1);
    printf((char *)(DAT_000a6538 + 0xa5eac),DAT_000a6534 + 0xa5ea0,0xaf,pcVar1);
  }
  pcVar1 = (char *)(DAT_000a653c + 0xa5ec0);
  setenv(pcVar1,acStack_20524,1);
  iVar10 = acosNvramConfig_match(DAT_000a6544 + 0xa5ed8,DAT_000a6540 + 0xa5ed4);
  if (iVar10 != 0) {
    pcVar1 = getenv(pcVar1);
    printf((char *)(DAT_000a654c + 0xa5f04),DAT_000a6548 + 0xa5ef8,0xb3,pcVar1);
  }
  if (acStack_20424[0] != '\0') {
    setenv((char *)(DAT_000a6550 + 0xa5f24),acStack_20424,1);
  }
  iVar10 = strcmp(acStack_20524,(char *)(DAT_000a6554 + 0xa5f38));
  if (iVar10 == 0) {
    pFVar3 = fopen64((char *)(DAT_000a655c + 0xa5f54),(char *)(DAT_000a6558 + 0xa5f50));
    if (pFVar3 != (FILE *)0x0) {
      fclose(pFVar3);
      system((char *)(DAT_000a6560 + 0xa5f6c));
      iVar10 = acosNvramConfig_match(DAT_000a6568 + 0xa5f80,DAT_000a6564 + 0xa5f7c);
      if (iVar10 != 0) {
        puts((char *)(DAT_000a656c + 0xa5f94));
      }
    }
    system((char *)(DAT_000a6570 + 0xa5fa0));
    sleep(1);
    pFVar3 = fopen64((char *)(DAT_000a6578 + 0xa5fbc),(char *)(DAT_000a6574 + 0xa5fb8));
    if (pFVar3 != (FILE *)0x0) {
      fputs(param_1,pFVar3);
      fclose(pFVar3);
    }
    pcVar1 = (char *)(DAT_000a657c + 0xa5fe8);
  }
  else {
    iVar10 = strcmp(acStack_20524,(char *)(DAT_000a6580 + 0xa5ff8));
    if (iVar10 == 0) {
      pFVar3 = fopen64((char *)(DAT_000a6588 + 0xa6014),(char *)(DAT_000a6584 + 0xa6010));
      if (pFVar3 != (FILE *)0x0) {
        fclose(pFVar3);
        system((char *)(DAT_000a658c + 0xa602c));
        iVar10 = acosNvramConfig_match(DAT_000a6594 + 680000,DAT_000a6590 + 0xa603c);
        if (iVar10 != 0) {
          puts((char *)(DAT_000a6598 + 0xa6054));
        }
      }
      pcVar1 = (char *)(DAT_000a659c + 0xa6064);
    }
    else {
      pFVar3 = fopen64((char *)(DAT_000a65a4 + 0xa6078),(char *)(DAT_000a65a0 + 0xa6074));
      if (pFVar3 != (FILE *)0x0) {
        fclose(pFVar3);
        system((char *)(DAT_000a65a8 + 0xa6090));
        iVar10 = acosNvramConfig_match(DAT_000a65b0 + 0xa60a4,DAT_000a65ac + 0xa60a0);
        if (iVar10 != 0) {
          puts((char *)(DAT_000a65b4 + 0xa60b8));
        }
      }
      pcVar1 = (char *)(DAT_000a65b8 + 0xa60c8);
    }
  }
  snprintf(acStack_20224,0x200,pcVar1,acStack_204e4);
  system(acStack_20224);
  memset(acStack_204a4,0,0x40);
  memset(auStack_20464,0,0x40);
  memset(auStack_20504,0,0x20);
  memset(auStack_20514,0,0x10);
  iVar10 = acosNvramConfig_match(DAT_000a65c0 + 0xa6130,DAT_000a65bc + 0xa612c);
  if (iVar10 != 0) {
    printf((char *)(DAT_000a65c8 + 0xa6150),DAT_000a65c4 + 0xa614c,0xec);
  }
  iVar10 = strcmp(acStack_20524,(char *)(DAT_000a65cc + 0xa6160));
  if (iVar10 == 0) {
    pcVar4 = (char *)(DAT_000a65d0 + 0xa6174);
    pcVar1 = (char *)(DAT_000a65d4 + 0xa6178);
  }
  else {
    iVar10 = strcmp(acStack_20524,(char *)(DAT_000a65d8 + 0xa6188));
    if (iVar10 == 0) {
      pcVar4 = (char *)(DAT_000a65dc + 0xa619c);
      pcVar1 = (char *)(DAT_000a65e0 + 0xa61a0);
    }
    else {
      pcVar4 = (char *)(DAT_000a65e4 + 0xa61ac);
      pcVar1 = (char *)(DAT_000a65e8 + 0xa61b0);
    }
  }
  pFVar3 = fopen64(pcVar1,pcVar4);
  if (pFVar3 != (FILE *)0x0) {
    iVar10 = acosNvramConfig_match(DAT_000a65f0 + 0xa61d0,DAT_000a65ec + 0xa61cc);
    if (iVar10 != 0) {
      printf((char *)(DAT_000a65f8 + 0xa61f0),DAT_000a65f4 + 0xa61ec,0xff);
    }
    iVar10 = DAT_000a65fc + 0xa6200;
    pcVar4 = (char *)(DAT_000a6600 + 0xa620c);
    pcVar1 = (char *)(DAT_000a6604 + 0xa6214);
    iVar11 = DAT_000a6608 + 0xa6218;
    iVar12 = DAT_000a660c + 0xa6224;
    while( true ) {
      pcVar7 = fgets(acStack_20024,0xffff,pFVar3);
      if (pcVar7 == (char *)0x0) break;
      iVar8 = acosNvramConfig_match(iVar11,iVar10);
      if (iVar8 != 0) {
        printf(pcVar4,iVar12,0x104,acStack_20024);
      }
      pcVar7 = strstr(acStack_20024,pcVar1);
      if (pcVar7 == (char *)0x0) {
        iVar8 = acosNvramConfig_match(DAT_000a6628 + 0xa630c,DAT_000a6624 + 0xa6308);
        if (iVar8 != 0) {
          printf((char *)(DAT_000a6630 + 0xa6330),DAT_000a662c + 0xa632c,0x115,acStack_20024);
        }
      }
      else {
        strlcpy(acStack_204a4,pcVar7 + 7,0x40);
        pcVar7 = strchr(acStack_204a4,10);
        iVar8 = DAT_000a6610 + 0xa62a4;
        if (pcVar7 != (char *)0x0) {
          *pcVar7 = '\0';
        }
        iVar8 = acosNvramConfig_match(DAT_000a6614 + 0xa62b8,iVar8);
        if (iVar8 != 0) {
          printf((char *)(DAT_000a661c + 0xa62dc),DAT_000a6618 + 0xa62d8,0x10b,acStack_204a4);
        }
        snprintf(acStack_10024,0xffff,(char *)(DAT_000a6620 + 0xa62f4),acStack_204a4);
      }
    }
    fclose(pFVar3);
  }
  if (acStack_10024[0] != '\0') {
    strcat(acStack_10024,(char *)(DAT_000a6634 + 0xa635c));
  }
  iVar10 = acosNvramConfig_match(DAT_000a663c + 0xa6370,DAT_000a6638 + 0xa636c);
  if (iVar10 != 0) {
    printf((char *)(DAT_000a6644 + 0xa6394),DAT_000a6640 + 0xa6390,0x120,acStack_10024);
  }
  if (acStack_10024[0] != '\0') {
    sVar5 = strlen(acStack_10024);
    FUN_0002c068(param_2,acStack_10024,sVar5,0);
  }
  iVar10 = acosNvramConfig_match(DAT_000a664c + 0xa63d4,DAT_000a6648 + 0xa63d0);
  if (iVar10 != 0) {
    printf((char *)(DAT_000a6654 + 0xa63f4),DAT_000a6650 + 0xa63f0,0x125);
  }
LAB_000a63f4:
                    /* WARNING: Subroutine does not return */
  exit(0);
}


===== ENTRY 000c44d8 =====
===== FUNCTION FUN_000c44d8 @ 000c44d8 =====

void FUN_000c44d8(void)

{
  char *pcVar1;
  FILE *__stream;
  undefined4 uVar2;
  char *__modes;
  int *piVar3;
  int iVar4;
  char acStack_d8 [32];
  char acStack_b8 [64];
  char acStack_78 [100];
  int local_14;
  
  iVar4 = DAT_000c45f4 + 0xc44f8;
  piVar3 = *(int **)(iVar4 + DAT_000c45f8);
  local_14 = *piVar3;
  snprintf(acStack_78,100,(char *)(DAT_000c45fc + 0xc4508),DAT_000c4608 + 0xc4530,
           DAT_000c4604 + 0xc4524,DAT_000c4600 + 0xc4518);
  system(acStack_78);
  __modes = (char *)(DAT_000c4610 + 0xc4554);
  pcVar1 = (char *)(DAT_000c4614 + 0xc4558);
  **(undefined4 **)(iVar4 + DAT_000c460c) = 0x33e0;
  __stream = fopen64(pcVar1,__modes);
  if (__stream == (FILE *)0x0) {
    puts((char *)(DAT_000c4618 + 0xc4570));
    uVar2 = 0;
  }
  else {
    pcVar1 = fgets(acStack_d8,0x20,__stream);
    if (pcVar1 == (char *)0x0) {
      puts((char *)(DAT_000c461c + 0xc45a0));
    }
    fclose(__stream);
    snprintf(acStack_b8,0x40,(char *)(DAT_000c4624 + 0xc45c8),DAT_000c4620 + 0xc45c0,acStack_d8);
    system(acStack_b8);
    uVar2 = 1;
  }
  if (local_14 != *piVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}


===== ENTRY 000c7e20 =====
===== FUNCTION FUN_000c7e20 @ 000c7e20 =====

void FUN_000c7e20(undefined4 param_1)

{
  FILE *__stream;
  char *__format;
  char *__modes;
  char *__format_00;
  int iVar1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  undefined1 auStack_2bc [152];
  char acStack_224 [256];
  char acStack_124 [256];
  int local_24;
  
  iVar5 = DAT_000c7fa0 + 0xc7e40;
  iVar2 = 0;
  piVar3 = *(int **)(iVar5 + DAT_000c7fa4);
  iVar1 = 0;
  local_24 = *piVar3;
  memcpy(auStack_2bc,&UNK_000c81eb + DAT_000c7fa8,0x96);
  memset(acStack_224,0,0x100);
  memset(acStack_124,0,0x100);
  __format = (char *)(DAT_000c7fac + 0xc7ea4);
  __modes = (char *)(DAT_000c7fb0 + 0xc7eb0);
  __format_00 = (char *)(DAT_000c7fb4 + 0xc7ebc);
  do {
    snprintf(acStack_224,0x100,__format,param_1,auStack_2bc + iVar2);
    __stream = popen(acStack_224,__modes);
    if (__stream == (FILE *)0x0) {
      perror((char *)(DAT_000c7fb8 + 0xc7efc));
      iVar1 = 0;
      goto LAB_000c7f80;
    }
    fgets(acStack_124,0x100,__stream);
    strToLower(acStack_124);
    pcVar4 = (char *)(iVar2 + *(int *)(iVar5 + DAT_000c7fbc));
    iVar2 = iVar2 + 0x32;
    strToLower(pcVar4);
    printf(__format_00,acStack_124,pcVar4);
    pcVar4 = strstr(acStack_124,pcVar4);
    if (pcVar4 == (char *)0x0) {
      iVar1 = iVar1 + 1;
    }
    pclose(__stream);
  } while (iVar2 != 0x96);
  printf((char *)(DAT_000c7fc0 + 0xc7f7c),iVar1);
LAB_000c7f80:
  if (local_24 != *piVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}


===== ENTRY 000c7fc4 =====
===== FUNCTION FUN_000c7fc4 @ 000c7fc4 =====

void FUN_000c7fc4(void)

{
  char *pcVar1;
  FILE *__stream;
  char *__modes;
  int *piVar2;
  int iVar3;
  int local_a8;
  int local_a4;
  char *local_a0;
  undefined4 local_9c;
  char acStack_98 [32];
  char acStack_78 [100];
  int local_14;
  
  iVar3 = DAT_000c80e8 + 0xc7fe4;
  piVar2 = *(int **)(iVar3 + DAT_000c80ec);
  local_14 = *piVar2;
  snprintf(acStack_78,100,(char *)(DAT_000c80f0 + 0xc7ff4),DAT_000c80f4 + 0xc8004);
  system(acStack_78);
  __modes = (char *)(DAT_000c80fc + 0xc8028);
  pcVar1 = (char *)(DAT_000c8100 + 0xc802c);
  **(undefined4 **)(iVar3 + DAT_000c80f8) = 0x33e0;
  __stream = fopen64(pcVar1,__modes);
  if (__stream == (FILE *)0x0) {
    puts((char *)(DAT_000c8104 + 0xc8044));
  }
  else {
    pcVar1 = fgets(acStack_98,0x20,__stream);
    if (pcVar1 == (char *)0x0) {
      puts((char *)(DAT_000c8108 + 0xc8070));
    }
    fclose(__stream);
    unlink((char *)(DAT_000c810c + 0xc8084));
    unlink((char *)(DAT_000c8110 + 0xc8090));
    local_a8 = DAT_000c8114 + 0xc80a4;
    local_a4 = DAT_000c811c + 0xc80b8;
    local_9c = 0;
    local_a0 = acStack_98;
    _eval_daemon(&local_a8,DAT_000c8118 + 0xc80b0,0,0,0);
  }
  if (local_14 != *piVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


===== ENTRY 0010f80c =====
===== FUNCTION FUN_0010f80c @ 0010f80c =====

void FUN_0010f80c(void)

{
  undefined2 uVar1;
  FILE *__stream;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  FILE *pFVar7;
  char *pcVar8;
  int iVar9;
  char *__s2;
  int iVar10;
  char *__needle;
  char *__format;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  int iVar17;
  char *pcVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  byte local_26c;
  int local_260;
  char local_23c [4];
  undefined4 auStack_238 [2];
  undefined2 auStack_230 [10];
  char acStack_21c [7];
  char local_215;
  char local_214 [24];
  undefined1 auStack_1fc [32];
  undefined1 auStack_1dc [32];
  char local_1bc [151];
  char acStack_125 [257];
  int local_24;
  
  iVar14 = 0;
  iVar9 = DAT_0010fcec + 0x10f82c;
  piVar15 = *(int **)(iVar9 + DAT_0010fcf0);
  local_1bc[0] = '\0';
  local_1bc[1] = '\0';
  local_1bc[2] = '\0';
  local_1bc[3] = '\0';
  local_24 = *piVar15;
  memset(local_1bc + 4,0,0x92);
  chdir((char *)(DAT_0010fcf4 + 0x10f858));
  system((char *)(DAT_0010fcf8 + 0x10f864));
  __stream = fopen64((char *)(DAT_0010fd00 + 0x10f878),(char *)(DAT_0010fcfc + 0x10f874));
  if (__stream == (FILE *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    __s2 = (char *)(DAT_0010fd04 + 0x10f8a0);
    iVar10 = DAT_0010fd08 + 0x10f8ac;
    __needle = (char *)(DAT_0010fd0c + 0x10f8b8);
    __format = (char *)(DAT_0010fd10 + 0x10f8c4);
    iVar19 = -1;
    iVar20 = -1;
    do {
      do {
        do {
          do {
            do {
              pcVar3 = fgets(local_1bc,0x96,__stream);
              if (pcVar3 == (char *)0x0) goto LAB_0010fcb0;
              iVar4 = strncmp(local_1bc,__s2,7);
            } while (iVar4 != 0);
            __isoc99_sscanf(local_1bc,iVar10,acStack_21c,auStack_1fc,auStack_1dc);
            iVar4 = local_215 + -0x61;
            local_26c = (byte)iVar4;
          } while ((0x19 < local_26c) ||
                  (pcVar3 = strstr(local_1bc,__needle), pcVar3 == (char *)0x0));
          sVar5 = strlen(acStack_21c);
          iVar6 = 0;
          if (8 < sVar5) {
            iVar6 = atoi(local_214);
          }
        } while (iVar4 == iVar20 && iVar6 == iVar19);
        if (local_214[0] == '\0') {
          local_260 = 0;
        }
        else {
          local_260 = atoi(local_214);
        }
        iVar16 = DAT_0010fd14;
        iVar17 = DAT_0010fd14 * iVar14;
        iVar11 = *(int *)(iVar9 + DAT_0010fd18);
        iVar21 = iVar17 + 0xc0;
        FUN_0010d018(acStack_21c,iVar11 + iVar21,0x40);
        iVar19 = iVar6;
        iVar20 = iVar4;
      } while (*(char *)(iVar21 + iVar11) == '\0');
      pcVar18 = acStack_125 + 1;
      pcVar3 = (char *)(iVar17 + 0x100 + iVar11);
      memset(pcVar18,0,0x100);
      snprintf(pcVar18,0x100,__format,(int)local_215);
      pFVar7 = fopen64(pcVar18,(char *)(DAT_0010fd1c + 0x10fa14));
      if (pFVar7 == (FILE *)0x0) {
        strlcpy(pcVar3,DAT_0010fd20 + 0x10fa64,0x40);
      }
      else {
        fgets(pcVar3,0x40,pFVar7);
        fclose(pFVar7);
        sVar5 = strlen(pcVar3);
        if (1 < sVar5) {
          pcVar3[sVar5 - 1] = '\0';
        }
      }
      pcVar3 = acStack_125 + 1;
      memset(pcVar3,0,0x100);
      snprintf(pcVar3,0x100,(char *)(DAT_0010fd24 + 0x10fa8c),(int)local_215);
      pFVar7 = fopen64(pcVar3,(char *)(DAT_0010fd28 + 0x10faa0));
      pcVar3 = (char *)(iVar16 * iVar14 + iVar11 + 0x140);
      if (pFVar7 == (FILE *)0x0) {
        strlcpy(pcVar3,DAT_0010fd2c + 0x10faf8,0x40);
      }
      else {
        fgets(pcVar3,0x40,pFVar7);
        fclose(pFVar7);
        sVar5 = strlen(pcVar3);
        if (1 < sVar5) {
          pcVar3[sVar5 - 1] = '\0';
        }
      }
      pcVar18 = (char *)(iVar16 * iVar14 + iVar11 + 0x39);
      pcVar3 = local_23c;
      puVar13 = (undefined4 *)(DAT_0010fd30 + 0x10fb0c);
      do {
        puVar12 = puVar13;
        pcVar8 = pcVar3;
        puVar13 = puVar12 + 2;
        uVar2 = puVar12[1];
        *(undefined4 *)pcVar8 = *puVar12;
        *(undefined4 *)(pcVar8 + 4) = uVar2;
        pcVar3 = pcVar8 + 8;
      } while (puVar13 != (undefined4 *)(DAT_0010fd30 + 0x10fb24));
      uVar1 = *(undefined2 *)(puVar12 + 3);
      *(undefined4 *)(pcVar8 + 8) = *puVar13;
      *(undefined2 *)(pcVar8 + 0xc) = uVar1;
      snprintf(local_23c,0x1e,(char *)(DAT_0010fd34 + 0x10fb58),(int)local_215);
      pFVar7 = fopen64(local_23c,(char *)(DAT_0010fd38 + 0x10fb6c));
      if (pFVar7 != (FILE *)0x0) {
        fgets(acStack_125 + 1,0x80,pFVar7);
        fclose(pFVar7);
        sVar5 = strlen(acStack_125 + 1);
        if (1 < sVar5) {
          acStack_125[sVar5] = '\0';
        }
      }
      pcVar3 = acStack_125 + 1;
      snprintf(pcVar18,0x20,(char *)(DAT_0010fd3c + 0x10fbd0),pcVar3);
      snprintf(local_23c,0x1e,(char *)(DAT_0010fd40 + 0x10fbe8),(int)local_215);
      pFVar7 = fopen64(local_23c,(char *)(DAT_0010fd44 + 0x10fbfc));
      if (pFVar7 != (FILE *)0x0) {
        fgets(pcVar3,0x80,pFVar7);
        fclose(pFVar7);
        sVar5 = strlen(pcVar3);
        if (1 < sVar5) {
          acStack_125[sVar5] = '\0';
        }
      }
      iVar16 = iVar16 * iVar14;
      strlcat(pcVar18,acStack_125 + 1,4);
      iVar6 = DAT_0010fd48;
      iVar17 = iVar11 + iVar16;
      iVar14 = iVar14 + 1;
      *(int *)(iVar17 + 0xc) = iVar4;
      *(undefined4 *)(iVar11 + iVar16) = 1;
      *(int *)(iVar17 + 0x10) = local_260;
      snprintf((char *)(iVar17 + 0x79),0x20,(char *)(iVar6 + 0x10fc74),auStack_1fc);
      snprintf((char *)(iVar11 + iVar16 + 0x99),0x20,(char *)(iVar6 + 0x10fc74),auStack_1dc);
    } while (iVar14 < 0x14);
LAB_0010fcb0:
    fclose(__stream);
    uVar2 = 0;
  }
  if (local_24 == *piVar15) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}


===== ENTRY 00119e20 =====
===== FUNCTION FUN_00119e20 @ 00119e20 =====

void FUN_00119e20(int param_1)

{
  __pid_t _Var1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  FILE *__stream;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  int iStack_100;
  char acStack_fc [32];
  char local_dc [64];
  char acStack_9c [128];
  int local_1c;
  
  iVar10 = DAT_0011a310 + 0x119e40;
  piVar11 = *(int **)(iVar10 + DAT_0011a314);
  local_dc[0] = '\0';
  local_dc[1] = '\0';
  local_dc[2] = '\0';
  local_dc[3] = '\0';
  local_1c = *piVar11;
  memset(local_dc + 4,0,0x3c);
  snprintf(local_dc,0x40,(char *)(DAT_0011a31c + 0x119e7c),DAT_0011a318 + 0x119e78);
  COMMAND(local_dc);
  if (param_1 == 1) {
    system((char *)(DAT_0011a320 + 0x119e98));
    FUN_00110120(0);
  }
  _Var1 = fork();
  if (_Var1 != 0) {
    if (0 < _Var1) {
      waitpid(_Var1,&iStack_100,0);
    }
    if (local_1c == *piVar11) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  _Var1 = fork();
  if (_Var1 != 0) goto LAB_0011a2e0;
  if (**(int **)(iVar10 + DAT_0011a324) != 0) {
    close(**(int **)(iVar10 + DAT_0011a324));
  }
  if (**(int **)(iVar10 + DAT_0011a328) != 0) {
    close(**(int **)(iVar10 + DAT_0011a328));
  }
  if (**(int **)(iVar10 + DAT_0011a32c) != -1) {
    close(**(int **)(iVar10 + DAT_0011a32c));
  }
  if (**(int **)(iVar10 + DAT_0011a330) != -1) {
    close(**(int **)(iVar10 + DAT_0011a330));
  }
  iVar10 = DAT_0011a338;
  if (param_1 == 1) {
    system((char *)(DAT_0011a334 + 0x119f34));
    FUN_00110120(0);
    FUN_0011805c();
    iVar2 = acosNvramConfig_match(DAT_0011a33c + 0x119f54,iVar10 + 0x119f44);
    if (iVar2 == 0) {
      iVar10 = acosNvramConfig_match(DAT_0011a344 + 0x119f7c,iVar10 + 0x119f44);
      if ((iVar10 != 0) &&
         (iVar10 = acosNvramConfig_match(DAT_0011a34c + 0x119f98,DAT_0011a348 + 0x119f94),
         iVar10 != 0)) {
        pcVar3 = (char *)acosNvramConfig_get(DAT_0011a350 + 0x119fac);
        pcVar4 = (char *)acosNvramConfig_get(DAT_0011a354 + 0x119fbc);
        iVar10 = strcmp(pcVar3,pcVar4);
        if (iVar10 == 0) goto LAB_00119f5c;
      }
    }
    else {
LAB_00119f5c:
      system((char *)(DAT_0011a340 + 0x119f68));
    }
    iVar10 = acosNvramConfig_match(DAT_0011a35c + 0x119fe4,DAT_0011a358 + 0x119fe0);
    if ((iVar10 != 0) &&
       (iVar10 = acosNvramConfig_match(DAT_0011a36c + 0x11a020,DAT_0011a368 + 0x11a01c), iVar10 == 0
       )) {
LAB_0011a028:
      FUN_00119184();
      pcVar3 = (char *)(DAT_0011a370 + 0x11a038);
      goto LAB_0011a13c;
    }
    iVar10 = acosNvramConfig_match(DAT_0011a364 + 0x11a000,DAT_0011a360 + 0x119ffc);
    if (iVar10 != 0) {
      pcVar3 = (char *)acosNvramConfig_get(DAT_0011a374 + 0x11a044);
      pcVar4 = (char *)acosNvramConfig_get(DAT_0011a378 + 0x11a054);
      iVar10 = strcmp(pcVar3,pcVar4);
      if (iVar10 != 0) goto LAB_0011a028;
    }
  }
  else {
    if (((param_1 != 2) ||
        (iVar10 = acosNvramConfig_match(DAT_0011a380 + 0x11a088,DAT_0011a37c + 0x11a084),
        iVar10 == 0)) ||
       (iVar10 = acosNvramConfig_match(DAT_0011a388 + 0x11a0a4,DAT_0011a384 + 0x11a0a0), iVar10 != 0
       )) goto LAB_0011a140;
    __stream = fopen64((char *)(DAT_0011a390 + 0x11a0c0),(char *)(DAT_0011a38c + 0x11a0bc));
    if (__stream != (FILE *)0x0) {
      fgets(acStack_fc,0x10,__stream);
      fclose(__stream);
      FUN_0011805c();
      printf((char *)(DAT_0011a394 + 0x11a0f8),acStack_fc);
      snprintf(acStack_9c,0x80,(char *)(DAT_0011a398 + 0x11a110),acStack_fc);
      COMMAND(acStack_9c);
      FUN_00110120(1);
      system((char *)(DAT_0011a39c + 0x11a130));
    }
    FUN_00119184();
    pcVar3 = (char *)(DAT_0011a3a0 + 0x11a140);
LAB_0011a13c:
    system(pcVar3);
  }
LAB_0011a140:
  pcVar3 = (char *)acosNvramConfig_get(DAT_0011a3a4 + 0x11a14c);
  iVar2 = atoi(pcVar3);
  pcVar3 = (char *)acosNvramConfig_get(DAT_0011a3a8 + 0x11a160);
  iVar10 = atoi(pcVar3);
  pcVar3 = (char *)acosNvramConfig_get(DAT_0011a3ac + 0x11a174);
  iVar5 = atoi(pcVar3);
  iVar6 = acosNvramConfig_match(DAT_0011a3b4 + 0x11a190,DAT_0011a3b0 + 0x11a184);
  if (iVar6 == 0) {
    agApi_setDeviceListenPort(7,iVar2,0);
    agApi_setDeviceListenPort(8,iVar10,0);
  }
  else {
    agApi_setDeviceListenPort(8,iVar10,0);
    agApi_setDeviceListenPort(7,iVar2,1);
    if (iVar2 <= iVar5 && iVar10 <= iVar2) {
      iVar5 = iVar5 - iVar10;
      iVar10 = iVar2 + 1;
      iVar5 = iVar5 + iVar10;
    }
    agApi_setDeviceListenPortRange(8,iVar10,iVar5);
  }
  uVar7 = acosNvramConfig_get(DAT_0011a3b8 + 0x11a21c);
  uVar8 = acosNvramConfig_get(DAT_0011a3bc + 0x11a22c);
  uVar9 = acosNvramConfig_get(DAT_0011a3c0 + 0x11a23c);
  iVar10 = acosNvramConfig_match(DAT_0011a3c8 + 0x11a254,DAT_0011a3c4 + 0x11a248);
  if ((iVar10 == 0) ||
     (iVar10 = acosNvramConfig_match(DAT_0011a3d0 + 0x11a270,DAT_0011a3cc + 0x11a26c), iVar10 != 0))
  {
    iVar10 = FUN_0010fe28(uVar7,uVar8,uVar9);
    if (iVar10 != 0) {
      uVar7 = 0;
      goto LAB_0011a2b4;
    }
  }
  else {
    iVar10 = FUN_0010fe28(uVar7,uVar8,uVar9);
    if (iVar10 == 0) {
      uVar7 = 1;
LAB_0011a2b4:
      FUN_0010fd4c(uVar7);
    }
  }
  snprintf(local_dc,0x40,(char *)(DAT_0011a3d8 + 0x11a2d4),DAT_0011a3d4 + 0x11a2d0);
  COMMAND(local_dc);
LAB_0011a2e0:
                    /* WARNING: Subroutine does not return */
  exit(0);
}


===== ENTRY 0011c6fc =====
===== FUNCTION FUN_0011c6fc @ 0011c6fc =====

void FUN_0011c6fc(void)

{
  char cVar1;
  FILE *pFVar2;
  char *pcVar3;
  size_t sVar4;
  void *__dest;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  int iVar9;
  void *__src;
  int iVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  int local_2b4 [20];
  char acStack_264 [64];
  char local_224 [512];
  int local_24;
  
  iVar5 = DAT_0011cc70 + 0x11c71c;
  iVar9 = 0;
  piVar8 = *(int **)(iVar5 + DAT_0011cc74);
  local_24 = *piVar8;
  memset(local_2b4,0,0x50);
  __dest = *(void **)(iVar5 + DAT_0011cc78);
  __src = *(void **)(iVar5 + DAT_0011cc80);
  pcVar6 = (char *)((int)__src + 0x180);
  memcpy(__dest,__src,DAT_0011cc7c);
  memset(__src,0,DAT_0011cc7c);
  FUN_0010f80c();
  FUN_0010dff4();
  pcVar7 = pcVar6;
  do {
    if (*(int *)(pcVar7 + -0x180) != 0) {
      pcVar11 = (char *)((int)__dest + 0xc0);
      do {
        iVar5 = strcmp(pcVar7 + -0xc0,pcVar11);
        if (((iVar5 == 0) && (*(int *)(pcVar7 + -0x170) == *(int *)(pcVar11 + -0xb0))) &&
           (iVar5 = strcmp(pcVar7 + -0x107,pcVar11 + -0x47), iVar5 == 0)) {
          local_2b4[iVar9] = 1;
          pcVar7[-0x168] = pcVar11[-0xa8];
          *(int *)(pcVar7 + -0xc4) = *(int *)(pcVar7 + -0xc4) + 1;
          strlcpy(pcVar7,pcVar11 + 0xc0,0x40);
          strlcpy(pcVar7 + 0x40,pcVar11 + 0x100,0x80);
          pcVar7[0xc0] = pcVar11[0x180];
          pcVar7[0xc1] = pcVar11[0x181];
          strlcpy(pcVar7 + 0xc2,pcVar11 + 0x182,10);
          strlcpy(pcVar7 + 0xcc,pcVar11 + 0x18c,0x180);
          strlcpy(pcVar7 + 0x24c,pcVar11 + 0x30c,0x180);
          strlcpy(pcVar7 + 0x3cc,pcVar11 + 0x48c,0x180);
        }
        pcVar11 = pcVar11 + 0x54d80;
      } while (pcVar11 != (char *)((int)__dest + 0x6a0ec0));
    }
    iVar9 = iVar9 + 1;
    pcVar7 = pcVar7 + 0x54d80;
  } while (iVar9 != 0x14);
  iVar5 = 0;
  pcVar7 = (char *)(DAT_0011cc84 + 0x11c7c8);
  iVar12 = DAT_0011cc88 + 0x11c7d0;
  iVar9 = DAT_0011cc8c + 0x11c7d8;
  pcVar11 = (char *)(DAT_0011cc90 + 0x11c7e0);
  iVar10 = DAT_0011cc94 + 0x11c7e4;
  do {
    if (*(int *)(pcVar6 + -0x180) != 0) {
      if (local_2b4[iVar5] != 1) {
        cVar1 = FUN_00113650(pcVar6 + -0x180);
        *(int *)(pcVar6 + -0xc4) = *(int *)(pcVar6 + -0xc4) + 1;
        pcVar6[-0x168] = cVar1;
        snprintf(pcVar6 + 0x40,0x80,pcVar7);
        if (pcVar6[-0x168] == 'U') {
          strlcpy(pcVar6,iVar10,0x40);
        }
        else {
          snprintf(pcVar6,0x40,pcVar11);
        }
        pcVar6[0xc0] = '\0';
        pcVar6[0xc1] = '\0';
        strlcpy(pcVar6 + 0xc2,iVar12,10);
        strlcpy(pcVar6 + 0xcc,iVar9,0x180);
        strlcpy(pcVar6 + 0x24c,iVar9,0x180);
        strlcpy(pcVar6 + 0x3cc,iVar9,0x180);
      }
      FUN_00113204(pcVar6 + -0x180);
    }
    iVar5 = iVar5 + 1;
    pcVar6 = pcVar6 + 0x54d80;
  } while (iVar5 != 0x14);
  local_224[0] = '\0';
  local_224[1] = '\0';
  local_224[2] = '\0';
  local_224[3] = '\0';
  memset(local_224 + 4,0,0x92);
  pcVar7 = (char *)((int)__src + 0x59);
  pcVar6 = (char *)(DAT_0011cc98 + 0x11c9f8);
  pcVar11 = (char *)(DAT_0011cc9c + 0x11c9fc);
  pcVar13 = (char *)(DAT_0011cca0 + 0x11ca00);
  iVar5 = DAT_0011cca4 + 0x11ca97;
  do {
    if (*(int *)(pcVar7 + -0x59) != 0) {
      cVar1 = (char)*(undefined4 *)(pcVar7 + -0x4d) + 'a';
      if (*(int *)(pcVar7 + -0x49) == 0) {
        snprintf(acStack_264,0x40,(char *)(DAT_0011cca8 + 0x11ca44),(int)cVar1);
      }
      else {
        snprintf(acStack_264,0x40,(char *)(DAT_0011ccac + 0x11ca64),(int)cVar1,
                 *(int *)(pcVar7 + -0x49));
      }
      pFVar2 = fopen64(acStack_264,pcVar6);
      if (pFVar2 == (FILE *)0x0) {
        printf(pcVar11,iVar5,0x15b7);
      }
      else {
        pcVar3 = fgets(local_224,0x96,pFVar2);
        if (pcVar3 == (char *)0x0) {
          cVar1 = pcVar7[-0x41];
          pcVar3 = pcVar13;
LAB_0011cb0c:
          snprintf(pcVar7,0x20,pcVar3,(int)cVar1,pcVar7 + 0x20);
        }
        else {
          sVar4 = strlen(local_224);
          if (sVar4 < 2) {
            cVar1 = pcVar7[-0x41];
            pcVar3 = (char *)(DAT_0011ccb0 + 0x11cac0);
            goto LAB_0011cb0c;
          }
          iVar9 = 0;
          do {
            if (local_224[iVar9] == '\n') {
              local_224[iVar9] = '\0';
              break;
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 != 0x96);
          strlcpy(pcVar7,local_224,0x20);
        }
        fclose(pFVar2);
      }
    }
    pcVar7 = pcVar7 + 0x54d80;
  } while ((char *)((int)__src + 0x6a0e59) != pcVar7);
  FUN_00110310();
  FUN_0011bf90();
  iVar5 = FUN_001129ec();
  if (iVar5 < 1) {
    iVar5 = DAT_0011ccbc + 0x11cb74;
    iVar9 = DAT_0011ccc0 + 0x11cb78;
  }
  else {
    iVar5 = DAT_0011ccb4 + 0x11cb64;
    iVar9 = DAT_0011ccb8 + 0x11cb68;
  }
  acosNvramConfig_set(iVar9,iVar5);
  iVar9 = DAT_0011cccc;
  iVar5 = DAT_0011ccc8;
  sVar4 = 0;
  system((char *)(DAT_0011ccc4 + 0x11cb8c));
  pcVar7 = (char *)(DAT_0011ccd0 + 0x11cbac);
  pcVar6 = (char *)(DAT_0011ccd4 + 0x11cbb0);
  pcVar11 = (char *)(DAT_0011ccd8 + 0x11cbb4);
  do {
    if (*(int *)((int)__src + sVar4) == 0) break;
    if (*(int *)((int)__src + sVar4) == 1) {
      snprintf(local_224,0x200,(char *)(iVar5 + 0x11cba0),(int)__src + sVar4 + 0xc0,
               (int)__src + sVar4 + 0x39,(int)__src + sVar4 + 0x79);
      printf((char *)(iVar9 + 0x11cba8),local_224);
      pFVar2 = fopen64(pcVar6,pcVar7);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,pcVar11,local_224);
        fclose(pFVar2);
      }
    }
    sVar4 = sVar4 + 0x54d80;
  } while (sVar4 != DAT_0011cc7c);
  if (local_24 != *piVar8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

