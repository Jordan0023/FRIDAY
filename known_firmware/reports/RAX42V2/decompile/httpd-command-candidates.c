
===== ENTRY 00033724 =====
===== FUNCTION FUN_00033724 @ 00033724 =====

void FUN_00033724(void)

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
  
  iVar50 = DAT_0003463c + 0x33744;
  local_24 = **(int **)(iVar50 + DAT_00034640);
  FUN_0003d6c4();
  pcVar17 = (char *)acosNvramConfig_get(DAT_00034644 + 0x3376c);
  iVar18 = strcmp(pcVar17,(char *)(DAT_00034648 + 0x33778));
  **(uint **)(iVar50 + DAT_0003464c) = (uint)(iVar18 == 0);
  FUN_00058350();
  FUN_00058a6c();
  uStack_20af0 = 1;
  tStack_20aec.tv_sec = 1;
  uVar19 = socket(2,1,0);
  puVar35 = *(uint **)(iVar50 + DAT_00034650);
  if (uVar19 == 0xffffffff) {
    pcVar17 = (char *)(DAT_00034658 + 0x337ec);
    pFVar31 = (FILE *)**(undefined4 **)(iVar50 + DAT_00034654);
LAB_00033968:
    fputs(pcVar17,pFVar31);
  }
  else {
    iVar18 = setsockopt(uVar19,1,2,&tStack_20aec,4);
    if (iVar18 < 0) {
      fputs((char *)(DAT_0003465c + 0x33824),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
    }
    memset((sockaddr *)&fStack_20a38,0,0x10);
    fStack_20a38.fds_bits[0]._0_2_ = 2;
    uVar13 = (undefined2)DAT_00034660;
    fStack_20a38.fds_bits[0]._2_2_ = uVar13;
    pcVar17 = (char *)nvram_get(DAT_00034664 + 0x33850);
    if (pcVar17 == (char *)0x0) {
LAB_00033874:
      pcVar17 = (char *)acosNvramConfig_get(DAT_0003466c + 0x33880);
      fStack_20a38.fds_bits[1] = inet_addr(pcVar17);
    }
    else {
      iVar18 = strcmp(pcVar17,(char *)(DAT_00034668 + 0x3386c));
      fStack_20a38.fds_bits[1] = 0;
      if (iVar18 != 0) goto LAB_00033874;
    }
    iVar18 = bind(uVar19,(sockaddr *)&fStack_20a38,0x10);
    if (iVar18 == -1) {
      puVar52 = *(undefined4 **)(iVar50 + DAT_00034654);
      pFVar31 = (FILE *)*puVar52;
      pcVar17 = inet_ntoa((in_addr)fStack_20a38.fds_bits[1]);
      fprintf(pFVar31,(char *)(DAT_00034670 + 0x338c4),pcVar17,0x24e3);
      pFVar31 = (FILE *)*puVar52;
      piVar41 = __errno_location();
      pcVar17 = strerror(*piVar41);
      fprintf(pFVar31,(char *)(DAT_00034674 + 0x338e8),pcVar17);
    }
    else {
      pcVar17 = inet_ntoa((in_addr)fStack_20a38.fds_bits[1]);
      printf((char *)(DAT_0003803c + 0x37e14),pcVar17,0x24e3);
    }
    if (0 < (int)uVar19) {
      uVar21 = fcntl(uVar19,1);
      fcntl(uVar19,2,uVar21 | 1);
    }
    iVar18 = acosNvramConfig_match(DAT_0003467c + 0x33928,DAT_00034678 + 0x33924);
    if (iVar18 == 0) {
      iVar20 = DAT_00034684 + 0x33980;
      iVar18 = acosNvramConfig_match(iVar20,DAT_00034688 + 0x33984);
      if (((iVar18 == 0) &&
          (iVar18 = acosNvramConfig_match(iVar20,DAT_00038040 + 0x37e28), iVar18 == 0)) &&
         (pcVar17 = (char *)acosNvramConfig_get(DAT_00038044 + 0x37e3c), *pcVar17 != '\0'))
      goto LAB_00033930;
    }
    else {
LAB_00033930:
      tStack_20ae4.tv_sec = 1;
      uVar21 = socket(10,1,0);
      if (uVar21 == 0xffffffff) {
        pcVar17 = (char *)(DAT_00034680 + 0x33968);
        pFVar31 = (FILE *)**(undefined4 **)(iVar50 + DAT_00034654);
        goto LAB_00033968;
      }
      iVar18 = setsockopt(uVar21,1,2,&tStack_20ae4,4);
      if (iVar18 < 0) {
        fputs((char *)(DAT_0003804c + 0x37e80),(FILE *)**(undefined4 **)(iVar50 + DAT_00038048));
      }
      uStack_20adc = 1;
      iVar18 = setsockopt(uVar21,0x29,0x1a,&uStack_20adc,4);
      if (iVar18 == -1) {
        fputs((char *)(DAT_00038050 + 0x37ec4),(FILE *)**(undefined4 **)(iVar50 + DAT_00038048));
      }
      else {
        printf((char *)(DAT_00038054 + 0x37ed8));
      }
      memset((sockaddr *)&fStack_209b8,0,0x1c);
      fStack_209b8.fds_bits[0] = CONCAT22(uVar13,10);
      p_Var49 = *(__fd_mask **)(iVar50 + DAT_00038058);
      fStack_209b8.fds_bits[2] = *p_Var49;
      fStack_209b8.fds_bits[3] = p_Var49[1];
      fStack_209b8.fds_bits[4] = p_Var49[2];
      fStack_209b8.fds_bits[5] = p_Var49[3];
      iVar18 = bind(uVar21,(sockaddr *)&fStack_209b8,0x1c);
      if (iVar18 == -1) {
        puVar52 = *(undefined4 **)(iVar50 + DAT_00038048);
        fprintf((FILE *)*puVar52,(char *)(DAT_0003805c + 0x37f38),0x24e3);
        pFVar31 = (FILE *)*puVar52;
        piVar41 = __errno_location();
        pcVar17 = strerror(*piVar41);
        fprintf(pFVar31,(char *)(DAT_00038060 + 0x37f58),pcVar17);
        close(uVar21);
      }
      else {
        printf((char *)(DAT_00038064 + 0x37f80),0x3b3,0x24e3);
        if (0 < (int)uVar21) {
          uVar38 = fcntl(uVar21,1);
          fcntl(uVar21,2,uVar38 | 1);
          *puVar35 = uVar21;
        }
      }
    }
  }
  puVar63 = *(uint **)(iVar50 + DAT_00034924);
  *puVar63 = uVar19;
  uVar19 = FUN_0002a48c(0x50);
  iVar20 = DAT_00034870;
  iVar18 = DAT_0003468c;
  puVar58 = *(uint **)(iVar50 + DAT_00034838);
  *puVar58 = 0xffffffff;
  puVar55 = *(uint **)(iVar50 + iVar20);
  *puVar55 = 0xffffffff;
  pcVar17 = (char *)acosNvramConfig_get(iVar18 + 0x339cc);
  iVar18 = strcmp(pcVar17,(char *)(DAT_00034690 + 0x339dc));
  if (iVar18 == 0) {
    pcVar17 = (char *)acosNvramConfig_get(DAT_00034694 + 0x33a00);
    iVar18 = atoi(pcVar17);
    if (iVar18 == 0x50) {
      *puVar58 = 0xffffffff;
    }
    else {
      pcVar17 = (char *)acosNvramConfig_get(DAT_00034698 + 0x33a24);
      iVar20 = strcmp(pcVar17,(char *)(DAT_0003469c + 0x33a30));
      if (iVar20 != 0) {
        uVar21 = FUN_0002a66c(iVar18);
        *puVar58 = uVar21;
        iVar20 = listen(uVar21,10);
        if (iVar20 == -1) {
          fputs((char *)(DAT_000346a0 + 0x33a6c),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
        }
        agApi_setDeviceListenPort(2,iVar18,1);
      }
    }
    iVar59 = DAT_000346a4 + 0x33a90;
    iVar20 = acosNvramConfig_match(iVar59,DAT_000346a8 + 0x33a94);
    if ((iVar20 == 0) &&
       (iVar20 = acosNvramConfig_match(iVar59,DAT_000346ac + 0x33ab0), iVar20 == 0)) {
      uVar21 = FUN_0002a48c(iVar18);
      *puVar55 = uVar21;
      iVar20 = listen(uVar21,5);
      if (iVar20 == -1) {
        fputs((char *)(DAT_000346b0 + 0x33aec),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
      }
      agApi_setDeviceListenPort(2,iVar18,1);
      agApi_ipv6_set_listen_port(1,0,6,iVar18);
    }
  }
  else {
    iVar18 = 0;
  }
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346b4 + 0x33b24);
  iVar20 = strcmp(pcVar17,(char *)(DAT_000346b8 + 0x33b30));
  puVar36 = *(uint **)(iVar50 + DAT_00034920);
  if (((iVar20 == 0) && (iVar20 = is_russian_case(), iVar20 != 0)) && (iVar18 != 0x50)) {
    uVar21 = FUN_0002a66c(iVar18 + 0x10000);
    *puVar36 = uVar21;
    iVar18 = listen(uVar21,10);
    if (iVar18 == -1) {
      fputs((char *)(DAT_000346bc + 0x33b8c),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
    }
  }
  else {
    *puVar36 = 0xffffffff;
  }
  setsockopt(uVar19,1,2,&uStack_20af0,4);
  iVar18 = listen(uVar19,10);
  if (iVar18 == -1) {
    fputs((char *)(DAT_000346c0 + 0x33be4),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
LAB_00034140:
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if ((*puVar63 != 0xffffffff) && (iVar18 = listen(*puVar63,10), iVar18 == -1)) {
    fputs((char *)(DAT_000346c4 + 0x33c20),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
  }
  if ((*puVar35 != 0xffffffff) && (iVar18 = listen(*puVar35,10), iVar18 == -1)) {
    fputs((char *)(DAT_000346c8 + 0x33c58),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
  }
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346cc + 0x33c68);
  iVar18 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346d0 + 0x33c7c);
  iVar20 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346d4 + 0x33c90);
  iVar59 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346d8 + 0x33ca4);
  iVar22 = atoi(pcVar17);
  puVar37 = *(uint **)(iVar50 + DAT_00034928);
  if ((iVar18 == 0x50) || (iVar59 == 0 || iVar20 != 0 && iVar18 == iVar22)) {
    *puVar37 = 0xffffffff;
  }
  else {
    pcVar17 = (char *)acosNvramConfig_get(DAT_000346dc + 0x33cec);
    iVar20 = strcmp(pcVar17,(char *)(DAT_000346e0 + 0x33cf8));
    if (iVar20 != 0) {
      uVar21 = FUN_0002a66c(iVar18);
      *puVar37 = uVar21;
      iVar20 = listen(uVar21,10);
      if (iVar20 == -1) {
        fputs((char *)(DAT_000346e4 + 0x33d34),(FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
      }
    }
  }
  iVar20 = acosNvramConfig_match(DAT_000346ec + 0x33d5c,DAT_000346e8 + 0x33d58);
  agApi_setDeviceListenPort(6,iVar18,iVar20 != 0);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346f0 + 0x33d7c);
  iVar20 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346f4 + 0x33d90);
  iVar18 = atoi(pcVar17);
  pcVar17 = (char *)acosNvramConfig_get(DAT_000346f8 + 0x33da4);
  iVar59 = atoi(pcVar17);
  iVar22 = acosNvramConfig_match(DAT_00034700 + 0x33dc0,DAT_000346fc + 0x33db4);
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
  iVar20 = DAT_0003470c;
  iVar18 = DAT_00034708;
  uVar23 = acosNvramConfig_get(DAT_00034704 + 0x33e58);
  strlcpy(acStack_10028,uVar23,0x28);
  agApi_natSetReadyshareName(acStack_10028);
  FUN_001115e0(acStack_10028);
  iVar22 = DAT_00034714 + 0x33ea4;
  iVar59 = DAT_00034718 + 0x33ea8;
  **(uint **)(iVar50 + DAT_00034710) = uVar19;
  acosNvramConfig_set(iVar59,iVar22);
  pcVar17 = (char *)acosNvramConfig_get(DAT_0003471c + 0x33eb8);
  strncpy(acStack_20938,pcVar17,0x1f);
  uStack_20919 = 0;
  strncpy(acStack_20918,acStack_20938,0x1f);
  uStack_208f9 = 0;
  iVar59 = acosNvramConfig_match(iVar20 + 0x33e6c,(char *)(iVar18 + 0x33e68));
  if (iVar59 == 0) {
    pcVar17 = (char *)(DAT_00034720 + 0x33f34);
    iVar18 = acosNvramConfig_match(iVar20 + 0x33e6c,pcVar17);
    if (iVar18 == 0) {
      pcVar17 = (char *)acosNvramConfig_get(DAT_00034724 + 0x33f64);
      strncpy(acStack_20878,pcVar17,0x2d);
      uStack_2084b = 0;
    }
    else {
      strncpy(acStack_20878,pcVar17,0x2e);
      uStack_2084a = 0;
    }
  }
  else {
    strncpy(acStack_20878,(char *)(iVar18 + 0x33e68),0x2e);
    uStack_2084a = 0;
  }
  iVar18 = is_russian_case();
  if (iVar18 != 0) {
    iVar20 = DAT_00034728 + 0x33f94;
    iVar18 = acosNvramConfig_match(iVar20,DAT_0003472c + 0x33f98);
    if (((iVar18 != 0) ||
        (iVar18 = acosNvramConfig_match(iVar20,DAT_0003473c + 0x33fec), iVar18 != 0)) ||
       (iVar18 = acosNvramConfig_match(iVar20,DAT_00034740 + 0x34004), iVar18 != 0)) {
      iVar20 = DAT_00034730 + 0x33fb8;
      iVar18 = acosNvramConfig_match(iVar20,DAT_00034734 + 0x33fbc);
      if (iVar18 == 0) {
        iVar18 = acosNvramConfig_match(iVar20,DAT_00034744 + 0x34020);
        if (iVar18 == 0) {
          iVar18 = DAT_0003474c + 0x34040;
        }
        else {
          iVar18 = DAT_00034748 + 0x34038;
        }
      }
      else {
        iVar18 = DAT_00034738 + 0x33fdc;
      }
      acosNvramConfig_read(iVar18,acStack_208f8,0x20);
      strncpy(acStack_208d8,acStack_208f8,0x1f);
      uStack_208b9 = 0;
    }
  }
  iVar18 = DAT_00034750;
  OPENSSL_init_ssl(0,0,0);
  OPENSSL_init_ssl(DAT_00034754,0,0);
  OPENSSL_init_ssl(0,0,0);
  meth = (SSL_METHOD *)TLS_server_method();
  pSVar24 = SSL_CTX_new(meth);
  *(SSL_CTX **)(iVar18 + 0x34d58) = pSVar24;
  SSL_CTX_set_options(pSVar24,0x2000000);
  FUN_0003d6c4();
  if (**(char **)(iVar18 + 0x34d5c) != '\0') {
    iVar18 = SSL_CTX_use_certificate_file
                       (*(SSL_CTX **)(iVar18 + 0x34d58),*(char **)(iVar18 + 0x34d5c),1);
    if (iVar18 == 0) {
      puts((char *)(DAT_00034758 + 0x340d8));
    }
    iVar18 = SSL_CTX_use_PrivateKey_file
                       (*(SSL_CTX **)(DAT_0003475c + 0x34dac),*(char **)(DAT_0003475c + 0x34db4),1);
    if (iVar18 == 0) {
      puts((char *)(DAT_00034760 + 0x34104));
    }
    FUN_001487d4();
    FUN_00148770();
    iVar18 = SSL_CTX_check_private_key(*(SSL_CTX **)(DAT_00034764 + 0x34ddc));
    if (iVar18 == 0) {
      ERR_print_errors_fp((FILE *)**(undefined4 **)(iVar50 + DAT_00034654));
      puts((char *)(DAT_00034768 + 0x34140));
      goto LAB_00034140;
    }
  }
  iVar18 = DAT_0003476c;
  SSL_CTX_ctrl(*(SSL_CTX **)(DAT_0003476c + 0x34e24),0x21,2,(void *)0x0);
  SSL_CTX_set_cipher_list(*(SSL_CTX **)(iVar18 + 0x34e24),(char *)(DAT_00034770 + 0x34178));
  pcVar17 = (char *)acosNvramConfig_get(DAT_00034774 + 0x34184);
  strncpy(acStack_208b8,pcVar17,0x1f);
  uStack_20899 = 0;
  strncpy(acStack_20898,acStack_208b8,0x1f);
  uStack_20879 = 0;
  pFVar31 = fopen64((char *)(DAT_0003477c + 0x341d0),(char *)(DAT_00034778 + 0x341c8));
  if (pFVar31 != (FILE *)0x0) {
    fread(*(void **)(iVar50 + DAT_00034780),4,1,pFVar31);
    fread(*(void **)(iVar50 + DAT_00034784),4,1,pFVar31);
    fclose(pFVar31);
  }
  iVar20 = DAT_00034790;
  iVar18 = DAT_00034788;
  puts((char *)(DAT_0003478c + 0x34240));
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x3423c);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x34240);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34244);
  fStack_209b8.fds_bits[3] = *(__fd_mask *)(iVar18 + 0x34248);
  iVar20 = iVar20 + 0x34250;
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x3424c);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x34250);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34254);
  fStack_209b8.fds_bits[3] = *(__fd_mask *)(iVar18 + 0x34258);
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x3425c);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x34260);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34264);
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  fStack_209b8.fds_bits[0] = *(__fd_mask *)(iVar18 + 0x34268);
  fStack_209b8.fds_bits[1] = *(__fd_mask *)(iVar18 + 0x3426c);
  fStack_209b8.fds_bits[2] = *(__fd_mask *)(iVar18 + 0x34270);
  _eval_daemon((sockaddr *)&fStack_209b8,iVar20,0,0);
  system((char *)(DAT_00034794 + 0x342e0));
  FUN_0003d6c4();
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
  iVar20 = DAT_00034798 + 0x3432c;
  iVar59 = DAT_0003479c + 0x344de;
  iVar22 = DAT_000347a0 + 0x344f2;
LAB_00034354:
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
           (iVar25 = strcmp(acStack_20918,(char *)(DAT_000347a4 + 0x343e4)), iVar25 == 0)) {
          bVar65 = false;
        }
        else {
          bVar65 = true;
          strncpy(acStack_20938,acStack_20918,0x1f);
          uStack_20919 = 0;
        }
        iVar56 = DAT_000347a8 + 0x3441c;
        iVar25 = acosNvramConfig_match(iVar56,DAT_000347ac + 0x34420);
        if ((iVar25 == 0) &&
           (iVar25 = acosNvramConfig_match(iVar56,DAT_000347b4 + 0x3447c), iVar25 == 0)) {
          iVar56 = DAT_000347b8 + 0x34494;
          iVar25 = acosNvramConfig_match(iVar56,acStack_20878);
          if (iVar25 == 0) {
            bVar65 = true;
            pcVar17 = (char *)acosNvramConfig_get(iVar56);
            strncpy(acStack_20878,pcVar17,0x2e);
            uStack_2084a = 0;
          }
          iVar25 = acosNvramConfig_match(DAT_000347c0 + 0x344d4,DAT_000347bc + 0x344d0);
          if (((iVar25 != 0) &&
              (iVar25 = acosNvramConfig_match(DAT_000347c8 + 0x344f0,DAT_000347c4 + 0x344ec),
              iVar25 == 0)) && (*puVar55 == 0xffffffff)) {
            bVar65 = true;
          }
        }
        else {
          iVar56 = DAT_000347b0 + 0x3443c;
          iVar25 = acosNvramConfig_match(iVar56,acStack_20878);
          if (iVar25 == 0) {
            bVar65 = true;
            pcVar17 = (char *)acosNvramConfig_get(iVar56);
            strncpy(acStack_20878,pcVar17,0x2e);
            uStack_2084a = 0;
          }
        }
        iVar25 = acosNvramConfig_match(DAT_000347d0 + 0x3451c,DAT_000347cc + 0x34518);
        if (iVar25 != 0) {
          pcVar17 = (char *)acosNvramConfig_get(DAT_000347d4 + 0x34538);
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
          iVar56 = DAT_000347d8 + 0x34594;
          iVar25 = acosNvramConfig_match(iVar56,DAT_000347dc + 0x34598);
          if (((iVar25 != 0) ||
              (iVar25 = acosNvramConfig_match(iVar56,DAT_000347ec + 0x345ec), iVar25 != 0)) ||
             (iVar25 = acosNvramConfig_match(iVar56,DAT_000347f0 + 0x34604), iVar25 != 0)) {
            iVar56 = DAT_000347e0 + 0x345b8;
            iVar25 = acosNvramConfig_match(iVar56,DAT_000347e4 + 0x345bc);
            if (iVar25 == 0) {
              iVar25 = acosNvramConfig_match(iVar56,DAT_000347f4 + 0x34620);
              if (iVar25 == 0) {
                iVar25 = DAT_000347fc + 0x34954;
              }
              else {
                iVar25 = (int)&DAT_0003463c + DAT_000347f8;
              }
            }
            else {
              iVar25 = DAT_000347e8 + 0x345dc;
            }
            acosNvramConfig_read(iVar25,acStack_208d8,0x20);
            iVar25 = strcmp(acStack_208d8,acStack_208f8);
            if ((iVar25 != 0) &&
               (iVar25 = strcmp(acStack_208d8,(char *)(DAT_00034800 + 0x3497c)), iVar25 != 0)) {
              bVar65 = true;
              strncpy(acStack_208f8,acStack_208d8,0x1f);
              uStack_208d9 = 0;
            }
          }
        }
        iVar25 = FUN_0010fa90();
        if (iVar25 != 0) {
          FUN_0002a974();
        }
        if (bVar65) {
          FUN_0002a974();
          FUN_0002ab10();
          FUN_00119948(2);
        }
        if ((int)uVar43 < (int)*puVar37) {
          uVar43 = *puVar37;
        }
        if ((int)uVar43 <= (int)uVar19) {
          uVar43 = uVar19;
        }
        iVar25 = acosNvramConfig_match(DAT_00034808 + 0x349e4,DAT_00034804 + 0x349e0);
        if (iVar25 != 0) {
          FUN_0011ad0c();
        }
        tStack_20aec.tv_sec = 1;
        iVar25 = 0;
        tStack_20aec.tv_usec = 0;
        puVar33 = *(uint **)(iVar50 + DAT_0003480c);
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
        if (**(int **)(iVar50 + DAT_00034810) == 1) {
          FUN_0002ab10();
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
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_0003481c + 0x34d00),iVar59);
        FUN_0002b1b4(0,pcVar17);
      }
      if (iVar25 != 0) {
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_00034814 + 0x34cb8),DAT_00034818 + 0x34e76);
        FUN_0002b1b4(0,pcVar17);
      }
      if (((**(int **)(iVar50 + DAT_00034820) != 0) ||
          (iVar25 = acosNvramConfig_match(DAT_00034828 + 0x34d68,DAT_00034824 + 0x34d64),
          iVar25 != 0)) && (**(int **)(iVar50 + DAT_00034890) == 0)) {
        FUN_0002b424();
      }
      if (**(int **)(iVar50 + DAT_0003482c) != 0) {
        **(int **)(iVar50 + DAT_0003482c) = 0;
        iVar56 = **(int **)(iVar50 + DAT_00034830);
        iVar25 = iVar56;
        if (iVar56 != 1) {
          iVar25 = iVar56 + -3;
        }
        if (iVar25 != 0 && (iVar56 != 1 && iVar56 + -3 != 1)) {
          if (iVar56 == 2) {
            FUN_0012c708();
          }
        }
        else if (**(int **)(iVar50 + DAT_00034834) == 1) {
          FUN_000c8b60();
        }
        else {
          FUN_000c6f84();
        }
      }
      puVar39 = *(uint **)(iVar50 + DAT_00034838);
      if ((uVar21 & fStack_20a38.fds_bits[iVar18]) != 0) {
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_0003483c + 0x34e18),DAT_00034840 + 0x34fd6);
        FUN_0002b1b4(0,pcVar17);
        **(uint **)(iVar50 + DAT_000348f4) = uVar19;
        bVar65 = false;
        **(undefined4 **)(iVar50 + DAT_00034884) = 0;
        **(undefined4 **)(iVar50 + DAT_00034910) = 0;
        goto LAB_00035520;
      }
      uVar38 = **(uint **)(iVar50 + DAT_00034924);
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
        goto LAB_00034ec0;
LAB_00034f10:
        **(uint **)(iVar50 + DAT_000348f4) = uVar38;
        bVar65 = false;
        **(undefined4 **)(iVar50 + DAT_00034884) = 0;
        **(undefined4 **)(iVar50 + DAT_00034910) = 1;
        goto LAB_00035520;
      }
LAB_00034ec0:
      uVar38 = **(uint **)(iVar50 + DAT_00034844);
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
        goto LAB_00034f10;
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
        goto LAB_00035038;
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_00034848 + 0x34fa0),DAT_0003484c + 0x3515e);
        FUN_0002b1b4(0,pcVar17);
        iVar25 = DAT_00034854;
        iVar56 = DAT_00034850 + 0x34fe8;
        **(uint **)(iVar50 + DAT_000348f4) = *puVar39;
        aiStack_20a5c[0] = 1;
        **(undefined4 **)(iVar50 + DAT_00034884) = 1;
        **(undefined4 **)(iVar50 + DAT_00034910) = 1;
        iVar25 = acosNvramConfig_match(iVar25 + 0x34ff4,iVar56);
        if (iVar25 == 0) goto LAB_0003551c;
        pcVar17 = (char *)acosNvramConfig_get(DAT_00034858 + 0x35024);
        iVar25 = atoi(pcVar17);
        iVar56 = DAT_0003485c + 0x35038;
LAB_000352bc:
        pcVar17 = (char *)acosNvramConfig_get(iVar56);
        iVar56 = atoi(pcVar17);
        bVar65 = iVar25 == iVar56;
        goto LAB_00035520;
      }
LAB_00035038:
      puVar40 = *(uint **)(iVar50 + DAT_00034920);
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
        goto LAB_000350f8;
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_00034860 + 0x350a0),DAT_00034864 + 0x3525e);
        FUN_0002b1b4(0,pcVar17);
        **(uint **)(iVar50 + DAT_000348f4) = *puVar40;
        **(undefined4 **)(iVar50 + DAT_00034884) = 1;
        **(undefined4 **)(iVar50 + DAT_00034910) = 1;
        goto LAB_0003551c;
      }
LAB_000350f8:
      puVar40 = *(uint **)(iVar50 + DAT_00034928);
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
          pcVar17 = *(char **)(iVar50 + DAT_000348f8);
          snprintf(pcVar17,0x400,(char *)(DAT_00034868 + 0x35160),DAT_0003486c + 0x3531e);
          FUN_0002b1b4(0,pcVar17);
          **(undefined4 **)(iVar50 + DAT_00034910) = 2;
          uVar38 = *puVar40;
          **(undefined4 **)(iVar50 + DAT_00034884) = 1;
          **(uint **)(iVar50 + DAT_000348f4) = uVar38;
          bVar65 = false;
          aiStack_20a5c[0] = 0;
          goto LAB_00035520;
        }
      }
      puVar40 = *(uint **)(iVar50 + DAT_00034870);
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
          pcVar17 = *(char **)(iVar50 + DAT_000348f8);
          snprintf(pcVar17,0x400,(char *)(DAT_00034874 + 0x3522c),DAT_00034878 + 0x353ea);
          FUN_0002b1b4(0,pcVar17);
          iVar25 = DAT_00034880;
          iVar56 = DAT_0003487c + 0x35274;
          **(uint **)(iVar50 + DAT_000348f4) = *puVar40;
          **(undefined4 **)(iVar50 + DAT_00034884) = 1;
          aiStack_20a5c[0] = 1;
          **(undefined4 **)(iVar50 + DAT_00034910) = 1;
          iVar25 = acosNvramConfig_match(iVar25 + 0x3527c,iVar56);
          if (iVar25 != 0) {
            pcVar17 = (char *)acosNvramConfig_get(DAT_00034888 + 0x352ac);
            iVar25 = atoi(pcVar17);
            iVar56 = DAT_0003488c + 0x352c0;
            goto LAB_000352bc;
          }
          goto LAB_0003551c;
        }
      }
      iVar25 = FUN_0005c6d8();
      if (iVar25 == 1) {
        if (**(int **)(iVar50 + DAT_00034890) != 0) {
          sync();
          sleep(2);
          system((char *)(DAT_00034894 + 0x35310));
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        iVar56 = DAT_00034898 + 0x35324;
        iVar25 = acosNvramConfig_match(iVar56,DAT_0003489c + 0x35328);
        if (iVar25 == 0) {
          iVar25 = acosNvramConfig_match(iVar56,DAT_000348b4 + 0x35398);
          if ((iVar25 != 0) ||
             (iVar25 = acosNvramConfig_match(iVar56,DAT_000348bc + 0x353cc), iVar25 != 0)) {
            system((char *)(DAT_000348b8 + 0x353ac));
            wait_for_ppp_to_terminate();
            sleep(1);
          }
        }
        else {
          system((char *)(DAT_000348a0 + 0x35340));
          wait_for_ppp_to_terminate();
          sleep(1);
          iVar25 = FUN_000492ac();
          if (iVar25 == 0) {
            acosNvramConfig_set(DAT_000348a8 + 0x3536c,DAT_000348a4 + 0x35368);
            acosNvramConfig_set(DAT_000348b0 + 0x35380,DAT_000348ac + 0x3537c);
            acosNvramConfig_save();
          }
        }
        if (**(int **)(iVar50 + DAT_000348c0) == 1) {
          abDisableLanEthernetPort();
        }
        iVar25 = acosNvramConfig_match(DAT_000348c8 + 0x35400,DAT_000348c4 + 0x353fc);
        if (iVar25 != 0) {
          abDisableLanEthernetPort();
          puts((char *)(DAT_000348cc + 0x35418));
        }
        acos_cms_del_bridge(DAT_000348d0 + 0x35424);
        system((char *)(DAT_000348d4 + 0x35430));
        goto LAB_0003551c;
      }
      iVar25 = FUN_0005c984();
      if (iVar25 == 1) {
        pcVar17 = *(char **)(iVar50 + DAT_000348f8);
        snprintf(pcVar17,0x400,(char *)(DAT_000348d8 + 0x35458),DAT_000348dc + 0x35616);
        FUN_0002b1b4(0,pcVar17);
        FUN_0005c92c();
        abDisableLanEthernetPort();
        sleep(3);
        abEnableLanEthernetPort();
        goto LAB_0003551c;
      }
      iVar25 = FUN_0005cab8();
      if (iVar25 == 1) {
        FUN_0005ca60();
        wireless_configure();
        goto LAB_0003551c;
      }
      iVar25 = FUN_0005cc1c();
    } while (iVar25 != 1);
    FUN_0005cbc4();
    pFVar31 = fopen64((char *)(DAT_000348e4 + 0x354d8),(char *)(DAT_000348e0 + 0x354d4));
    if (pFVar31 != (FILE *)0x0) {
      fprintf(pFVar31,(char *)(DAT_000348ec + 0x354fc),DAT_000348e8 + 0x356a1,0x8b3);
      fclose(pFVar31);
    }
    COMMAND(DAT_000348f0 + 0x35514);
    sleep(5);
LAB_0003551c:
    bVar65 = false;
LAB_00035520:
    puVar40 = *(uint **)(iVar50 + DAT_000348f4);
    uVar38 = *puVar40;
    pcVar17 = *(char **)(iVar50 + DAT_000348f8);
    if (((uVar38 == *puVar39) || (uVar38 == **(uint **)(iVar50 + DAT_00034920))) ||
       ((uVar38 == **(uint **)(iVar50 + DAT_00034928) ||
        (uVar38 == **(uint **)(iVar50 + DAT_00034924))))) {
      snprintf(pcVar17,0x400,(char *)(DAT_00034900 + 0x355b8),DAT_000348fc + 0x35756);
      FUN_0002b1b4(0,pcVar17);
      __addr = (sockaddr *)auStack_20ac8;
      sStack_20b00 = 0x10;
    }
    else {
      snprintf(pcVar17,0x400,(char *)(DAT_00034908 + 0x35600),DAT_00034904 + 0x3579e);
      FUN_0002b1b4(0,pcVar17);
      __addr = &sStack_20a78;
      sStack_20b00 = 0x1c;
    }
    uVar38 = accept(*puVar40,__addr,&sStack_20b00);
    *puVar33 = uVar38;
  } while (uVar38 == 0xffffffff);
  puStack_20afc = (uint *)0x0;
  uStack_20af8 = 0;
  pcVar53 = (char *)(DAT_0003490c + 0x35668);
  uStack_2062c = 0;
  memset(auStack_20628,0,0x1fc);
  acStack_2042c[0] = '\0';
  acStack_2042c[1] = '\0';
  acStack_2042c[2] = '\0';
  acStack_2042c[3] = '\0';
  memset(acStack_2042c + 4,0,0x1fc);
  snprintf(pcVar17,0x400,pcVar53,iVar22);
  FUN_0002b1b4(0,pcVar17);
  acStack_20748[0] = '\0';
  acStack_20748[1] = '\0';
  acStack_20748[2] = '\0';
  acStack_20748[3] = '\0';
  memset(acStack_20748 + 4,0,0x118);
  piVar41 = *(int **)(iVar50 + DAT_00034910);
  if (*piVar41 != 0) {
    snprintf(pcVar17,0x400,pcVar53,iVar22);
    FUN_0002b1b4(0,pcVar17);
    s = SSL_new(*(SSL_CTX **)(DAT_00034914 + 0x363dc));
    puVar52 = *(undefined4 **)(iVar50 + DAT_00034918);
    uVar38 = *puVar33;
    *puVar52 = s;
    SSL_set_fd(s,uVar38);
    fcntl(*puVar33,4,0x800);
    FUN_0003d6c4();
    iVar25 = SSL_accept((SSL *)*puVar52);
    if (iVar25 < 1) {
      iVar25 = SSL_get_error((SSL *)*puVar52,iVar25);
      if (iVar25 != 2) {
        close(*puVar33);
        SSL_shutdown((SSL *)*puVar52);
        SSL_free((SSL *)*puVar52);
        ERR_print_errors_fp((FILE *)**(undefined4 **)(iVar50 + DAT_0003491c));
        goto LAB_00034354;
      }
      goto LAB_000357a4;
    }
  }
  iStack_20af4 = 0;
LAB_000357a4:
  uVar38 = *puVar40;
  if ((((uVar38 == *puVar39) || (uVar38 == **(uint **)(iVar50 + DAT_00034920))) ||
      (uVar38 == **(uint **)(iVar50 + DAT_00034924))) ||
     (uVar38 == **(uint **)(iVar50 + DAT_00034928))) {
    if (aiStack_20ac4[0].s_addr == 0) {
      puts((char *)(DAT_0003492c + 0x35814));
LAB_00037dd0:
      if (local_24 == **(int **)(iVar50 + DAT_00038038)) {
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
       (iVar25 = acosNvramConfig_match(DAT_00034934 + 0x35860,DAT_00034930 + 0x3585c), iVar25 != 0))
    {
      pFVar31 = fopen64((char *)(DAT_0003493c + 0x3587c),(char *)(DAT_00034938 + 0x35878));
      fprintf(pFVar31,(char *)(DAT_00034940 + 0x3588c),acStack_10028);
      fclose(pFVar31);
    }
    iVar25 = strcmp(acStack_10028,(char *)(DAT_00034944 + 0x358a8));
    if (iVar25 == 0) goto LAB_00037dd0;
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
      printf((char *)(DAT_0003690c + 0x35948),sStack_20a78.sa_data._6_4_ & 0xff,
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
  pcStack_20ba8 = DAT_00036910;
  pcStack_20b6c = (char *)0x0;
  bVar32 = true;
  pcStack_20bb0 = (char *)0x0;
  bVar51 = false;
  pcStack_20b74 = (char *)0x0;
  bVar62 = false;
  iVar25 = DAT_00036914 + 0x35b3a;
  pcVar53 = (char *)(DAT_00036918 + 0x359a8);
  iVar56 = DAT_0003691c + 0x35b5a;
LAB_000359bc:
  sVar26 = strlen((char *)auStack_2002c);
  if (60000 < sVar26) goto LAB_00037d14;
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
LAB_00035a7c:
    iVar42 = select(*puVar33 + 1,&fStack_209b8,(fd_set *)0x0,(fd_set *)0x0,&tStack_20ae4);
  }
  else {
    snprintf(pcVar17,0x400,pcVar53,iVar25);
    FUN_0002b1b4(0,pcVar17);
    iVar42 = SSL_pending((SSL *)**(undefined4 **)(iVar50 + DAT_00036920));
    snprintf(pcVar17,0x400,pcVar53,iVar25);
    FUN_0002b1b4(0,pcVar17);
    if (iVar42 == 0) goto LAB_00035a7c;
  }
  if (iVar42 < 1) {
LAB_000364e8:
    pcVar60 = (char *)(DAT_000369d8 + 0x36508);
    iVar56 = DAT_000369d4 + 0x366a6;
LAB_00036508:
    snprintf(pcVar17,0x400,pcVar60,iVar56);
LAB_0003651c:
    FUN_0002b1b4(0,pcVar17);
LAB_00036520:
    iVar42 = 0;
    goto LAB_00036dc4;
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
  goto LAB_000364e8;
  pcVar60 = (char *)(DAT_00036924 + 0x35b88);
  snprintf(pcVar17,0x400,pcVar60,iVar56);
  FUN_0002b1b4(0,pcVar17);
  sVar26 = FUN_0002bde0(*puVar33,acStack_10028,0x400);
  if (sVar26 == 0xffffffff) goto LAB_00036508;
  if (sVar26 == 0) {
    snprintf(pcVar17,0x400,pcVar60,iVar56);
    goto LAB_0003651c;
  }
  if (sVar26 == 0xfffffffe) {
    snprintf(pcVar17,0x400,pcVar60,iVar56);
    FUN_0002b1b4(0,pcVar17);
    goto LAB_000359bc;
  }
  snprintf(pcVar17,0x400,pcVar60,iVar56);
  FUN_0002b1b4(0,pcVar17);
  if (!bVar51) {
    iVar42 = (int)pcStack_20bb0 + sVar26;
    if (iVar42 < 0x10000) {
      snprintf(pcVar17,0x400,pcVar60,iVar56);
      FUN_0002b1b4(0,pcVar17);
      memcpy((char *)((int)auStack_2002c + (int)pcStack_20bb0),acStack_10028,sVar26);
      *(undefined1 *)((int)auStack_2002c + iVar42) = 0;
      pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036994 + 0x36338));
      pcStack_20bb0 = (char *)iVar42;
      if ((((pcVar60 == (char *)0x0) ||
           (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036998 + 0x36358)),
           pcVar60 == (char *)0x0)) ||
          (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_0003699c + 0x36370)),
          pcVar60 == (char *)0x0)) ||
         ((pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369a0 + 0x36388)),
          pcVar60 == (char *)0x0 &&
          (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369a8 + 0x363ac)),
          pcVar60 == (char *)0x0)))) {
        pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369ac + 0x363c4));
        if ((pcVar60 == (char *)0x0) ||
           ((pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369b0 + 0x363dc)),
            pcVar60 == (char *)0x0 ||
            (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369b4 + 0x363f4)),
            pcVar60 == (char *)0x0)))) {
          pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369bc + 0x36414));
          if ((pcVar60 == (char *)0x0) ||
             ((pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369c0 + 0x3642c)),
              pcVar60 == (char *)0x0 ||
              (pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369c4 + 0x36444)),
              pcVar60 == (char *)0x0)))) {
            strcasestr((char *)auStack_2002c,(char *)(DAT_000369cc + 0x36480));
            goto LAB_00036680;
          }
          pcVar60 = (char *)(DAT_000369c8 + 0x36458);
        }
        else {
          pcVar60 = (char *)(DAT_000369b8 + 0x36404);
        }
      }
      else {
        pcVar60 = (char *)(DAT_000369a4 + 0x3639c);
      }
      pcVar60 = strcasestr((char *)auStack_2002c,pcVar60);
      if (pcVar60 == (char *)0x0) goto LAB_00036528;
      bVar51 = true;
      goto LAB_00036520;
    }
    snprintf(pcVar17,0x400,pcVar60,iVar56);
    FUN_0002b1b4(0,pcVar17);
    pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_000369d0 + 0x364bc));
    if (pcVar60 != (char *)0x0) {
      bVar14 = true;
LAB_000364d4:
      bVar32 = false;
      goto LAB_00036528;
    }
LAB_00036680:
    snprintf(pcVar17,0x400,(char *)(DAT_000369e8 + 0x366ac),DAT_000369e4 + 0x36846);
    FUN_0002b1b4(0,pcVar17);
    pcVar60 = inet_ntoa(aiStack_20ac4[0]);
    strncpy(acStack_10028,pcVar60,0x1f);
    uStack_10009 = 0;
    iVar42 = isLanSubnet(acStack_10028);
    if (((iVar42 == 0) && (iVar42 = isOpenvpnLanSubnet(acStack_10028), iVar42 == 0)) &&
       (aiStack_20a5c[0] != 1)) {
      iVar42 = isLoopBack(acStack_10028);
      if (iVar42 == 0) {
        if (((*puVar40 == uVar19) &&
            (iVar42 = acosNvramConfig_match(DAT_00036a0c + 0x367fc,DAT_00036a08 + 0x367f8),
            iVar42 == 0)) || (uVar38 = *puVar40, uVar38 == **(uint **)(iVar50 + DAT_00036c00))) {
          puts((char *)(DAT_00036a10 + 0x36810));
          iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_00036a14 + 0x36824),0xb);
          if (iVar42 == 0) {
            iVar54 = DAT_00036a18 + 0x3683c;
            iVar42 = acosNvramConfig_match(DAT_00036a1c + 0x36840,iVar54);
            if ((iVar42 != 0) ||
               (iVar42 = acosNvramConfig_match(DAT_00036a20 + 0x3685c,iVar54), iVar42 != 0))
            goto LAB_000368f0;
          }
          pcVar60 = (char *)(DAT_00036a24 + 0x36870);
LAB_00036c30:
          puts(pcVar60);
          goto LAB_000359bc;
        }
        if (((uVar38 == *puVar39) || (uVar38 == **(uint **)(iVar50 + DAT_00036a28))) ||
           (uVar38 == **(uint **)(iVar50 + DAT_00036a2c))) {
          if ((!bVar65) &&
             (iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_00036a30 + 0x368c8),0xb),
             iVar42 == 0)) {
            pcVar60 = (char *)(DAT_00036a34 + 0x368dc);
            goto LAB_00036c30;
          }
        }
        else if ((uVar38 == **(uint **)(iVar50 + DAT_00036a38)) &&
                (iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_00036a3c + 0x36c20),0xb),
                iVar42 != 0)) {
          pcVar60 = (char *)(DAT_00036a40 + 0x36c34);
          goto LAB_00036c30;
        }
      }
    }
    else {
      iVar42 = strncmp((char *)auStack_2002c,(char *)(DAT_000369ec + 0x36708),0xb);
      if ((iVar42 == 0) &&
         (((iVar42 = acosNvramConfig_match(DAT_000369f4 + 0x36748,DAT_000369f0 + 0x36744),
           iVar42 != 0 && (**(int **)(iVar50 + DAT_000369f8) == 0)) ||
          ((iVar42 = acosNvramConfig_match(DAT_00036a04 + 0x36784,DAT_00036a00 + 0x36780),
           iVar42 != 0 && (**(int **)(iVar50 + DAT_000369f8) != 0)))))) {
        pcVar60 = (char *)(DAT_000369fc + 0x36770);
        goto LAB_00036c30;
      }
    }
LAB_000368f0:
    iVar42 = FUN_0002ae90(auStack_2002c,&puStack_20afc);
    if (iVar42 != 0) goto LAB_00036c38;
    goto LAB_000359bc;
  }
  snprintf(pcVar17,0x400,pcVar60,iVar56);
  FUN_0002b1b4(0,pcVar17);
  if (bVar32) {
    memcpy((char *)((int)auStack_2002c + (int)pcStack_20bb0),acStack_10028,sVar26);
    pcStack_20bb0 = (char *)((int)pcStack_20bb0 + sVar26);
    *(undefined1 *)((int)auStack_2002c + (int)pcStack_20bb0) = 0;
    pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036928 + 0x35cd8));
    if ((pcVar60 == (char *)0x0) ||
       (pcVar60 = strcasestr(pcVar60,(char *)(DAT_0003692c + 0x35cf4)), pcVar60 == (char *)0x0)) {
      pcVar60 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036948 + 0x35ef0));
      pcVar46 = (char *)0x0;
      if (pcVar60 != (char *)0x0) {
        pcVar46 = (char *)(DAT_0003694c + 0x35f04);
        pcVar60 = strcasestr(pcVar60,pcVar46);
        if (pcVar60 == (char *)0x0) {
          pcVar46 = (char *)0x0;
        }
        else {
          pcVar47 = strcasestr((char *)auStack_2002c,(char *)(DAT_00036950 + 0x35f20));
          if ((((pcVar47 == (char *)0x0) || (pcVar47[-1] != '\n')) ||
              (pcVar46 = strcasestr((char *)auStack_2002c,pcVar46), pcVar46 == (char *)0x0)) ||
             (pcVar60 + 4 <= pcVar46 + 4)) {
            pcVar46 = (char *)0x0;
            bVar14 = true;
          }
          else {
            pcVar60 = strcasestr(pcVar47 + 0x10,(char *)(DAT_00036954 + 0x35f70));
            pcVar48 = pcVar47 + 0xf;
            pcStack_20ba8 = (char *)0x0;
            for (iVar42 = 0; iVar42 < (int)pcVar60 - (int)(pcVar47 + 0x10); iVar42 = iVar42 + 1) {
              pcVar48 = pcVar48 + 1;
              pcStack_20ba8 = (char *)((int)pcStack_20ba8 * 10 + *pcVar48 + -0x30);
            }
            if (&UNK_00100001 <= pcStack_20ba8) {
              bVar62 = true;
              goto LAB_000361e0;
            }
            pcStack_20ba8 = pcVar46 + 4 + ((int)pcStack_20ba8 - (int)auStack_2002c);
            pcVar46 = (char *)0x0;
            **(undefined4 **)(iVar50 + DAT_00036958) = pcStack_20ba8;
          }
        }
      }
LAB_00035ffc:
      if (**(int **)(iVar50 + DAT_00036a5c) == 1) {
        system((char *)(DAT_0003695c + 0x3601c));
        pFStack_20b80 = fopen64((char *)(DAT_00036964 + 0x36030),(char *)(DAT_00036960 + 0x3602c));
        if (pFStack_20b80 == (FILE *)0x0) {
          puts((char *)(DAT_0003696c + 0x360c4));
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
            puts((char *)(DAT_00036968 + 0x360a0));
            bVar14 = true;
          }
          iStack_20ba0 = iStack_20ba0 + sVar26;
        }
        goto LAB_00036528;
      }
      piVar45 = *(int **)(iVar50 + DAT_00036970);
      if ((void *)*piVar45 != (void *)0x0) {
        free((void *)*piVar45);
        *piVar45 = 0;
      }
      FUN_0005d570(&uStack_20adc);
      pcVar60 = (char *)((int)pcStack_20bb0 - (int)pcVar46);
      if (((0 < (int)pcVar60) && (pcVar47 = pcStack_20ba8 + 600, pcStack_20ba8 < pcVar47)) &&
         (pcVar60 < pcVar47)) {
        pvVar27 = malloc((size_t)pcVar47);
        *piVar45 = (int)pvVar27;
        if (pvVar27 == (void *)0x0) {
          puts((char *)(DAT_00036978 + 0x3614c));
          system((char *)(DAT_0003697c + 0x36158));
          sleep(2);
          system((char *)(DAT_00036980 + 0x3616c));
          sleep(1);
          pvVar27 = malloc((size_t)pcVar47);
          *piVar45 = (int)pvVar27;
          if (pvVar27 == (void *)0x0) {
            puts((char *)(DAT_00036984 + 0x36198));
            bVar62 = false;
            goto LAB_000361e0;
          }
        }
        memset((void *)*piVar45,0x20,(size_t)pcVar47);
        memcpy((void *)*piVar45,(char *)((int)auStack_2002c + (int)pcVar46),(size_t)pcVar60);
        pcStack_20b74 = pcVar60 + *piVar45;
        pcStack_20b6c = pcVar60;
        goto LAB_000364d4;
      }
      puts((char *)(DAT_00036974 + 0x36128));
    }
    else {
      bVar9 = pcVar60[0xb];
      FUN_0003d6c4();
      uVar38 = FUN_0003d42c(pcVar60 + 4,0x200);
      if (uVar38 == 0) {
        cVar10 = pcVar60[0x14];
        bVar1 = pcVar60[0x17];
        pcVar46 = pcVar60 + 4 + ((uint)bVar9 - (int)auStack_2002c);
        bVar9 = pcVar60[0x16];
        bVar2 = pcVar60[0x15];
        FUN_0003d6c4();
        cVar11 = pcVar60[0x18];
        bVar3 = pcVar60[0x1b];
        bVar4 = pcVar60[0x1a];
        bVar5 = pcVar60[0x19];
        FUN_0003d6c4();
        uVar34 = (uint)(byte)pcVar60[0x1f] + pcVar60[0x1c] * 0x1000000 +
                 (uint)(byte)pcVar60[0x1e] * 0x100 + (uint)(byte)pcVar60[0x1d] * 0x10000;
        FUN_0003d6c4();
        uVar43 = (uint)(byte)pcVar60[0x23] + pcVar60[0x20] * 0x1000000 +
                 (uint)(byte)pcVar60[0x22] * 0x100 + (uint)(byte)pcVar60[0x21] * 0x10000;
        FUN_0003d6c4();
        cVar12 = pcVar60[0x24];
        bVar6 = pcVar60[0x27];
        bVar7 = pcVar60[0x26];
        bVar8 = pcVar60[0x25];
        FUN_0003d6c4();
        pcStack_20ba8 = (char *)(uVar34 + uVar43);
        uStack_20adc = uVar34;
        uStack_20ad8 = uVar43;
        iStack_20ad4 = (uint)bVar1 + cVar10 * 0x1000000 + (uint)bVar9 * 0x100 +
                       (uint)bVar2 * 0x10000;
        iStack_20ad0 = (uint)bVar3 + cVar11 * 0x1000000 + (uint)bVar4 * 0x100 +
                       (uint)bVar5 * 0x10000;
        iStack_20acc = (uint)bVar6 + cVar12 * 0x1000000 + (uint)bVar7 * 0x100 +
                       (uint)bVar8 * 0x10000;
        FUN_0003d6c4();
        if (**(int **)(iVar50 + DAT_00036930) == 1) {
          if (uVar34 < 0x6000001) {
            if (uVar43 < 0x6000001) {
              if (pcStack_20ba8 < (char *)0x6000001) goto LAB_00035ffc;
              pcVar60 = (char *)(DAT_0003693c + 0x35e58);
            }
            else {
              pcVar60 = (char *)(DAT_00036938 + 0x35e40);
            }
          }
          else {
            pcVar60 = (char *)(DAT_00036934 + 0x35e2c);
          }
          puts(pcVar60);
          if (!bVar14) {
            FUN_0005d464(**(undefined4 **)(iVar50 + DAT_00036b7c));
          }
          goto LAB_00035ffc;
        }
        uStack_20af0 = uVar38;
        getRoofsSize(&uStack_20af0);
        printf((char *)(DAT_00036940 + 0x35e98),uVar34,uStack_20af0);
        if (uStack_20af0 < uVar34) {
          FUN_0003d6c4();
          printf((char *)(DAT_00036944 + 0x35eb8),uStack_20af0);
        }
        else {
          if (pcStack_20ba8 < (char *)0x6000001) {
            FUN_0003d6c4();
            bVar62 = true;
            goto LAB_00035ffc;
          }
          FUN_0003d6c4();
        }
      }
    }
LAB_000361e0:
    bVar14 = true;
    bVar32 = false;
    goto LAB_000359bc;
  }
  if (bVar14) goto LAB_000359bc;
  if (**(int **)(iVar50 + DAT_00036a5c) == 1) {
    sVar57 = fwrite(acStack_10028,1,sVar26,pFStack_20b80);
    if (sVar26 != sVar57) {
      puts((char *)(DAT_00036988 + 0x36244));
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
    if (iVar42 >> 0x10 != *(int *)(DAT_0003698c + 0x36f80)) {
      *(int *)(DAT_0003698c + 0x36f80) = iVar42 >> 0x10;
      fputc(0x2e,(FILE *)**(undefined4 **)(iVar50 + DAT_00036990));
    }
  }
LAB_00036528:
  snprintf(pcVar17,0x400,(char *)(DAT_000369e0 + 0x36550),DAT_000369dc + 0x366ee);
  FUN_0002b1b4(0,pcVar17);
  if ((bVar14) || (pcStack_20b6c < pcStack_20ba8)) {
    bVar51 = true;
    goto LAB_000359bc;
  }
  iVar25 = 0;
  do {
    fStack_209b8.fds_bits[iVar25] = 0;
    iVar25 = iVar25 + 1;
  } while (iVar25 != 0x20);
  puVar39 = *(uint **)(iVar50 + DAT_00036b7c);
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
      FUN_0002bde0(uVar43,acStack_10028,0x400);
    }
  }
  bVar51 = true;
  iVar42 = 1;
LAB_00036c38:
  snprintf(pcVar17,0x400,(char *)(DAT_00036a48 + 0x36c60),DAT_00036a44 + 0x36dfe);
  FUN_0002b1b4(0,pcVar17);
  iVar25 = 0;
  do {
    fStack_209b8.fds_bits[iVar25] = 0;
    iVar25 = iVar25 + 1;
  } while (iVar25 != 0x20);
  puVar39 = *(uint **)(iVar50 + DAT_00036b7c);
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
      pcVar53 = (char *)(DAT_00036a50 + 0x36d70);
      iVar25 = DAT_00036a4c + 0x36f0a;
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b1b4(0,pcVar17);
      FUN_0002bde0(*puVar39,acStack_10028,0x400);
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b1b4(0,pcVar17);
    }
  }
LAB_00036dc4:
  pcVar53 = (char *)(DAT_00036a58 + 0x36de8);
  iVar25 = DAT_00036a54 + 0x36f82;
  snprintf(pcVar17,0x400,pcVar53,iVar25);
  FUN_0002b1b4(0,pcVar17);
  piVar45 = *(int **)(iVar50 + DAT_00036a5c);
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
    FUN_0002b1b4(0,pcVar17);
    if (pFStack_20b80 != (FILE *)0x0) {
      fclose(pFStack_20b80);
    }
    iVar25 = DAT_00036a60;
    *piVar45 = 0;
    pcVar53 = (char *)(DAT_00036a64 + 0x36edc);
    rename((char *)(iVar25 + 0x36ed0),pcVar53);
    if (DAT_00036a68 < auStack_20aa8[0] - 1) {
      puts((char *)(DAT_00036a6c + 0x36f08));
      snprintf(acStack_20748,0x11b,(char *)(DAT_00036a74 + 0x36f28),2);
      uVar38 = *puVar33;
      iVar56 = DAT_00036a78 + 0x36f48;
      iVar25 = DAT_00036a7c + 0x36f4c;
    }
    else {
      iVar56 = truncate64(pcVar53,(ulonglong)auStack_20aa8[0]);
      if (iVar56 == 0) {
        pcVar60 = (char *)(DAT_00036a94 + 0x36fc8);
        printf((char *)(DAT_00036a98 + 0x36fd0),auStack_20aa8[0]);
        pFVar31 = fopen64(pcVar53,pcVar60);
        if (pFVar31 == (FILE *)0x0) {
          puts((char *)(DAT_00036a9c + 0x36ff8));
          snprintf(acStack_20748,0x11b,(char *)(DAT_00036aa4 + 0x37018),2);
          iVar56 = DAT_00036aa8 + 0x37038;
          iVar25 = DAT_00036aac + 0x3703c;
          uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
        }
        else {
          iVar56 = FUN_0012ae88(pFVar31,auStack_20aa8[0],&iStack_20af4);
          if (iVar56 == 0) {
            fclose(pFVar31);
            if (auStack_20aa8[1] == iStack_20af4 && iStack_20af4 != 0) {
              system((char *)(DAT_00036ad8 + 0x37148));
              pFVar31 = fopen64((char *)(iVar25 + 0x36ed0),pcVar60);
              if (pFVar31 == (FILE *)0x0) {
                puts((char *)(DAT_00036adc + 0x37174));
                FUN_00130b80(2);
                snprintf(acStack_20748,0x11b,(char *)(DAT_00036ae0 + 0x37190),2);
                iVar56 = DAT_00036ae4 + 0x371b4;
                iVar25 = DAT_00036ae8 + 0x371b8;
                uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
              }
              else {
                fseek(pFVar31,0,0);
                iStack_20bac = ftell(pFVar31);
                if (iStack_20bac == -1) {
                  perror((char *)(DAT_00036aec + 0x371e8));
                  iStack_20bac = 0;
                }
                iVar25 = 0;
                bVar51 = false;
                pcVar53 = (char *)(DAT_00036af0 + 0x37204);
                bVar65 = false;
                puStack_20ba4 = (undefined1 *)0x0;
                pcVar60 = (char *)(DAT_00036af4 + 0x37218);
                pcStack_20bb0 = (char *)0x0;
                pcVar46 = (char *)(DAT_00036af8 + 0x37228);
                pcVar47 = (char *)(DAT_00036afc + 0x37234);
                pcVar48 = (char *)(DAT_00036b00 + 0x37240);
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
                        if (!bVar32) goto LAB_000373ec;
                      }
                      else {
LAB_000373ec:
                        pcVar28 = strcasestr((char *)&uStack_2062c,acStack_2042c);
                        if (pcVar28 == (char *)0x0) goto LAB_00037410;
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
                      puStack_20ba4 = &stack0xfffdf430 + DAT_00036b04;
                      printf(pcVar47,puStack_20ba4);
                    }
                  }
LAB_00037410:
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
                printf((char *)(DAT_00036b08 + 0x37458),iStack_20ba0);
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
                    iVar56 = truncate64((char *)(DAT_00036b20 + 0x3750c),(longlong)iVar25);
                    if (iVar56 != 0) {
                      perror((char *)(DAT_00036b24 + 0x37520));
                    }
                    printf((char *)(DAT_00036b28 + 0x37530),iVar25);
                  }
                  iVar25 = FUN_00131468(auStack_20ab8,&uStack_20af8,DAT_00036b30 + 0x37550,
                                        DAT_00036b2c + 0x37548);
                  if (iVar25 == 0) {
                    if (*pcStack_20bb0 != '\0') {
                      __isoc99_sscanf(pcStack_20bb0,DAT_00036b40 + 0x375e0,auStack_20aa8 + 4,
                                      auStack_20a94);
                    }
                    iVar25 = 0;
                    do {
                      auStack_20ab0[iVar25] = (char)(auStack_20aa8 + 4)[iVar25];
                      iVar56 = iVar25 + 1;
                      auStack_20aac[iVar25] = (char)auStack_20a88[iVar25];
                      iVar25 = iVar56;
                    } while (iVar56 != 4);
                    strncpy(acStack_20848,(char *)(DAT_00036b44 + 0x37650),0xff);
                    uStack_20749 = 0;
                    snprintf(acStack_20848,0x100,(char *)(DAT_00036b48 + 0x37674),
                             DAT_00036b4c + 0x37680);
                    pFVar31 = fopen64((char *)(DAT_00036b54 + 0x37694),
                                      (char *)(DAT_00036b50 + 0x37690));
                    puVar39 = *(uint **)(iVar50 + DAT_00036b7c);
                    if (pFVar31 == (FILE *)0x0) {
                      FUN_00130b80(3);
                      snprintf(acStack_20748,0x11b,(char *)(DAT_00036b58 + 0x376c8),3);
                      uVar38 = *puVar39;
                      iVar56 = DAT_00036b5c + 0x376e8;
                      iVar25 = DAT_00036b60 + 0x376ec;
                    }
                    else {
                      uVar38 = FUN_0012afdc(acStack_20848,pFVar31,uStack_20af8,auStack_20ab8);
                      if (uVar38 == 0) {
                        fclose(pFVar31);
                        FUN_00132d6c(puStack_20ba4);
                        uVar23 = FUN_0003b984(DAT_00036b70 + 0x3777c);
                        uVar29 = FUN_0003b984(DAT_00036b74 + 0x3778c);
                        uStack_20adc = uVar38;
                        FUN_0012b21c(uVar23,uVar29,&uStack_20adc);
                        iVar25 = DAT_00036b78 + 0x377b4;
                        goto LAB_00037868;
                      }
                      fclose(pFVar31);
                      FUN_00130b80(5);
                      snprintf(acStack_20748,0x11b,(char *)(DAT_00036b64 + 0x3773c),5);
                      uVar38 = *puVar39;
                      iVar56 = DAT_00036b68 + 0x3775c;
                      iVar25 = DAT_00036b6c + 0x37760;
                    }
                  }
                  else {
                    FUN_00130b80(4);
                    snprintf(acStack_20748,0x11b,(char *)(DAT_00036b34 + 0x37580),4);
                    iVar56 = DAT_00036b38 + 0x375a4;
                    iVar25 = DAT_00036b3c + 0x375a8;
                    uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
                  }
                }
                else {
                  puts((char *)(DAT_00036b0c + 0x374a0));
                  snprintf(acStack_20748,0x11b,(char *)(DAT_00036b14 + 0x374c0),2);
                  iVar56 = DAT_00036b18 + 0x374e0;
                  iVar25 = DAT_00036b1c + 0x374e4;
                  uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
                }
              }
            }
            else {
              puts((char *)(DAT_00036ac4 + 0x370f4));
              snprintf(acStack_20748,0x11b,(char *)(DAT_00036acc + 0x37114),2);
              iVar56 = DAT_00036ad0 + 0x37134;
              iVar25 = DAT_00036ad4 + 0x37138;
              uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
            }
          }
          else {
            fclose(pFVar31);
            puts((char *)(DAT_00036ab0 + 0x3706c));
            snprintf(acStack_20748,0x11b,(char *)(DAT_00036ab8 + 0x37090),2);
            iVar56 = DAT_00036abc + 0x370b0;
            iVar25 = DAT_00036ac0 + 0x370b4;
            uVar38 = **(uint **)(iVar50 + DAT_00036b7c);
          }
        }
      }
      else {
        perror((char *)(DAT_00036a80 + 0x36f74));
        snprintf(acStack_20748,0x11b,(char *)(DAT_00036a88 + 0x36f94),2);
        uVar38 = *puVar33;
        iVar56 = DAT_00036a8c + 0x36fb4;
        iVar25 = DAT_00036a90 + 0x36fb8;
      }
    }
    FUN_00061680(iVar25,acStack_20748,iVar56,uVar38);
  }
  else {
    if (aiStack_20a5c[0] == 0) {
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b1b4(0,pcVar17);
    }
    puVar52 = *(undefined4 **)(iVar50 + DAT_00036b7c);
    if ((*puVar40 != uVar19) ||
       (iVar25 = acosNvramConfig_match(DAT_00036b84 + 0x37818,DAT_00036b80 + 0x37814), iVar25 == 0))
    goto LAB_00037aa8;
    iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036b88 + 0x37834),0x17);
    if (iVar25 == 0) {
      printf((char *)(DAT_00036b90 + 0x37858),DAT_00036b8c + 0x379fd,0xe34);
      iVar25 = DAT_00036b94 + 0x3786c;
      goto LAB_00037868;
    }
    pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036b98 + 0x37880));
    if ((((pcVar53 == (char *)0x0) &&
         (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036b9c + 0x37898)),
         pcVar53 == (char *)0x0)) &&
        (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036ba0 + 0x378b0)),
        pcVar53 == (char *)0x0)) &&
       (((pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036ba4 + 0x378c8)),
         pcVar53 == (char *)0x0 &&
         (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036ba8 + 0x378e0)),
         pcVar53 == (char *)0x0)) &&
        ((pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036bac + 0x378f8)),
         pcVar53 == (char *)0x0 &&
         (pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036bb0 + 0x37910)),
         pcVar53 == (char *)0x0)))))) {
      pcVar53 = strstr((char *)auStack_2002c,(char *)(DAT_00036bb4 + 0x3792c));
      if (pcVar53 == (char *)0x0) {
        iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036bbc + 0x37958),0x19);
        if (iVar25 == 0) {
          iVar25 = DAT_00036bc0 + 0x3796c;
        }
        else {
          iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036bc4 + 0x37980),0xd);
          if ((iVar25 == 0) ||
             (iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036bc8 + 0x3799c),0x1d),
             iVar25 == 0)) goto LAB_00037aa8;
          iVar25 = strncmp((char *)auStack_2002c,(char *)(DAT_00036bcc + 0x379b8),0xe);
          iVar15.s_addr = iStack_20a4c.s_addr;
          if (iVar25 == 0) {
            printf((char *)(DAT_00036bd4 + 0x379dc),DAT_00036bd0 + 0x37b81,0xe59);
            iVar25 = DAT_00036bd8 + 0x379f0;
          }
          else {
            if ((aiStack_20a5c[0] == 0) &&
               (iVar30 = inet_addr((char *)(DAT_00036bdc + 0x37a20)), iVar15.s_addr == iVar30))
            goto LAB_00037aa8;
            iVar15.s_addr = iStack_20a4c.s_addr;
            if (aiStack_20a5c[0] == 0) {
              pcVar53 = (char *)acosNvramConfig_get(DAT_00036be0 + 0x37a3c);
              iVar30 = inet_addr(pcVar53);
              if (iVar15.s_addr == iVar30) goto LAB_00037aa8;
            }
            if (aiStack_20a5c[0] == 1) {
              inet_pton(10,(char *)(DAT_00036be4 + 0x37a70),auStack_20a88);
              iVar25 = memcmp(&uStack_20a48,auStack_20a88,0x10);
              if (iVar25 == 0) goto LAB_00037aa8;
              iVar25 = DAT_00036be8 + 0x37a98;
            }
            else {
              iVar25 = DAT_00036bec + 0x37aa8;
            }
          }
        }
LAB_00037868:
        FUN_0003c738(iVar25);
        goto LAB_00037d14;
      }
      puts((char *)(DAT_00036bb8 + 0x37940));
    }
LAB_00037aa8:
    if (iVar42 == 0) {
      pcVar53 = (char *)(DAT_00038018 + 0x37c54);
      iVar25 = DAT_00038014 + 0x37dee;
      snprintf(pcVar17,0x400,pcVar53,iVar25);
      FUN_0002b1b4(0,pcVar17);
      if (bVar51) {
        snprintf(pcVar17,0x400,pcVar53,iVar25);
        FUN_0002b1b4(0,pcVar17);
        pcVar53 = strcasestr((char *)auStack_2002c,(char *)(DAT_0003801c + 0x37cb4));
        if (pcVar53 == (char *)0x0) {
          pcVar53 = strcasestr((char *)auStack_2002c,(char *)(DAT_00038020 + 0x37cd0));
          uVar23 = *puVar52;
          if (pcVar53 == (char *)0x0) {
            FUN_0005d464(uVar23);
            goto LAB_00037d14;
          }
        }
        else {
          uVar23 = *puVar52;
        }
        FUN_000492f8(uVar23);
      }
      else {
        snprintf(pcVar17,0x400,pcVar53,iVar25);
        FUN_0002b1b4(0,pcVar17);
      }
    }
    else {
      iVar25 = FUN_0002b4a0(auStack_2002c);
      if (iVar25 == 1) {
        strlcpy(acStack_10028,auStack_2002c,DAT_00036bf0);
        acStack_2022c[0] = '\0';
        acStack_2022c[1] = '\0';
        acStack_2022c[2] = '\0';
        acStack_2022c[3] = '\0';
        memset(acStack_2022c + 4,0,0xfc);
        iVar25 = FUN_0002b0c8(auStack_2002c,acStack_2022c);
        puVar61 = *(uint **)(iVar50 + DAT_00036bf4);
        puVar39 = *(uint **)(iVar50 + DAT_00036c00);
        printf((char *)(DAT_00036bfc + 0x37b2c),DAT_00036bf8 + 0x37cbd,0xe8f,*puVar40);
        iVar15.s_addr = iStack_20a4c.s_addr;
        if ((*puVar40 != *puVar39) && (*puVar40 != *puVar61)) {
          if (aiStack_20a5c[0] == 0) {
            iVar30 = inet_addr((char *)(DAT_0003800c + 0x37c08));
            iVar16.s_addr = iStack_20a4c.s_addr;
            if (iVar15.s_addr != iVar30) {
              pcVar53 = (char *)acosNvramConfig_get(DAT_00038010 + 0x37c20);
              iVar30 = inet_addr(pcVar53);
              if (iVar16.s_addr != iVar30) goto LAB_00037bb4;
            }
          }
          else {
LAB_00037bb4:
            if (iVar25 != 1 || aiStack_20a5c[0] == 0) {
              printf((char *)(DAT_00036c08 + 0x37bf0),DAT_00036c04 + 0x37d95,0xe9d);
              goto LAB_00037d14;
            }
          }
        }
        sVar26 = strlen((char *)auStack_2002c);
        FUN_000669f4(acStack_10028,*puVar52,iStack_20a4c.s_addr,sVar26);
      }
      else {
        snprintf(pcVar17,0x400,(char *)(DAT_0003806c + 0x37fd8),DAT_00038068 + 0x38176);
        FUN_0002b1b4(0,pcVar17);
        FUN_0002c068(auStack_2002c,puStack_20afc,aiStack_20a5c,*puVar52);
      }
    }
  }
LAB_00037d14:
  if (*piVar41 != 0) {
    puVar52 = *(undefined4 **)(iVar50 + DAT_00038024);
    iVar25 = SSL_get_fd((SSL *)*puVar52);
    SSL_shutdown((SSL *)*puVar52);
    SSL_free((SSL *)*puVar52);
    snprintf(pcVar17,0x400,(char *)(DAT_0003802c + 0x37d70),DAT_00038028 + 0x37f0e);
    FUN_0002b1b4(0,pcVar17);
    close(iVar25);
  }
  snprintf(pcVar17,0x400,(char *)(DAT_00038034 + 0x37db0),DAT_00038030 + 0x37f4e);
  FUN_0002b1b4(0,pcVar17);
  close(*puVar33);
  goto LAB_00034354;
}


===== ENTRY 0003d704 =====
===== FUNCTION FUN_0003d704 @ 0003d704 =====

void FUN_0003d704(char *param_1,int param_2,int param_3,undefined1 *param_4)

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
  
  iVar13 = DAT_0003e660 + 0x3d728;
  piVar11 = *(int **)(iVar13 + DAT_0003e668);
  iVar10 = *piVar11;
  auStack_9010c[0] = 0;
  iVar2 = acosNvramConfig_match(DAT_0003e664 + 0x3d738,DAT_0003e66c + 0x3d754);
  if (iVar2 != 0) {
    printf((char *)(DAT_0003e674 + 0x3d78c),DAT_0003e670 + 0x3d7fc,0x145,param_1);
  }
  if (param_2 == 0 || param_1 == (char *)0x0) goto LAB_0003eff0;
  iVar2 = strcmp(param_1,(char *)(DAT_0003e678 + 0x3d7ac));
  if ((iVar2 == 0) && (iVar2 = FUN_0003b8a0(param_4), iVar2 == 0)) {
    FUN_0003bb0c(param_2,*(undefined4 *)(iVar13 + DAT_0003e67c),DAT_0003e680 + 0x3d7dc);
    goto LAB_0003eff0;
  }
  iVar2 = DAT_0003e688;
  strlcpy(acStack_90108,DAT_0003e684 + 0x3d800,0xc);
  puStack_90124 = param_4;
  if (param_4 == (undefined1 *)0x0) {
    puStack_90124 = auStack_9010c;
  }
  pcVar3 = strstr(param_1,(char *)(iVar2 + 0x3d80c));
  pcVar4 = (char *)(iVar2 + 0x3d80c);
  if (pcVar3 == (char *)0x0) {
    cVar1 = *param_1;
    if ((cVar1 == '\0') ||
       (pcVar4 = strstr(param_1,(char *)(DAT_0003e68c + 0x3d84c)), pcVar4 != (char *)0x0)) {
      if ((**(int **)(iVar13 + DAT_0003e690) == 0) || (**(int **)(iVar13 + DAT_0003e694) != 0)) {
        pcVar4 = acStack_90108;
        if (cVar1 != '\0') goto LAB_0003d898;
      }
      else {
        pcVar4 = (char *)(DAT_0003e698 + 0x3d884);
      }
      goto LAB_0003d890;
    }
  }
  else {
LAB_0003d890:
    strcpy(param_1,pcVar4);
  }
LAB_0003d898:
  iVar2 = strcmp(param_1,(char *)(DAT_0003e69c + 0x3d8a8));
  if ((((iVar2 == 0) &&
       (iVar2 = acosNvramConfig_match(DAT_0003e6a4 + 0x3d8c4,DAT_0003e6a0 + 0x3d8c0), iVar2 != 0))
      && (iVar2 = acosNvramConfig_match(DAT_0003e6ac + 0x3d8e0,DAT_0003e6a8 + 0x3d8dc), iVar2 != 0))
     || (((iVar2 = strcmp(param_1,(char *)(DAT_0003e6b4 + 0x3d90c)), iVar2 == 0 &&
          (iVar2 = acosNvramConfig_match(DAT_0003e6bc + 0x3d928,DAT_0003e6b8 + 0x3d924), iVar2 != 0)
          ) && ((iVar2 = acosNvramConfig_match(DAT_0003e6c4 + 0x3d944,DAT_0003e6c0 + 0x3d940),
                iVar2 != 0 &&
                (iVar2 = acosNvramConfig_match(DAT_0003e6cc + 0x3d960,DAT_0003e6c8 + 0x3d95c),
                iVar2 != 0)))))) {
    strcpy(param_1,(char *)(DAT_0003e6b0 + 0x3d8f8));
  }
  pcVar4 = param_1;
  snprintf(acStack_900c8,0x50,(char *)(DAT_0003e6d4 + 0x3d988),DAT_0003e6d0 + 0x3d980,param_1);
  pcVar3 = (char *)acosNvramConfig_get(DAT_0003e6d8 + 0x3d99c);
  iVar2 = strcmp(pcVar3,(char *)(DAT_0003e6dc + 0x3d9a8));
  if (iVar2 == 0) {
    pcVar3 = (char *)(DAT_0003e6e0 + 0x3d9bc);
  }
  else {
    pcVar3 = (char *)(DAT_0003e6e4 + 0x3d9c4);
  }
  snprintf(acStack_90078,0x50,pcVar3,acStack_900c8,pcVar4);
  if (*param_1 == '\0') {
    iVar2 = acosNvramConfig_match(DAT_0003e6ec + 0x3d9ec,DAT_0003e6e8 + 0x3d9e8);
    __stream = (FILE *)0x0;
    if (iVar2 != 0) {
      printf((char *)(DAT_0003e6f4 + 0x3da14),DAT_0003e6f0 + 0x3da84,0x189,acStack_90078);
      __stream = (FILE *)0x0;
    }
  }
  else {
    iVar2 = acosNvramConfig_match(DAT_0003e6fc + 0x3da2c,DAT_0003e6f8 + 0x3da28);
    if (iVar2 != 0) {
      printf((char *)(DAT_0003e704 + 0x3da54),DAT_0003e700 + 0x3dac4,399,acStack_90078);
    }
    __stream = fopen64(acStack_90078,(char *)(DAT_0003e708 + 0x3da64));
  }
  iVar2 = acosNvramConfig_match(DAT_0003e710 + 0x3da7c,DAT_0003e70c + 0x3da78);
  if (iVar2 != 0) {
    pFVar5 = fopen64((char *)(DAT_0003e718 + 0x3da98),(char *)(DAT_0003e714 + 0x3da94));
    fprintf(pFVar5,(char *)(DAT_0003e71c + 0x3daa8),acStack_900c8);
    fclose(pFVar5);
  }
  FUN_0003d6c4();
  FUN_0003d6c4();
  pcVar4 = strstr(param_1,(char *)(DAT_0003e720 + 0x3dacc));
  pcVar3 = *(char **)(iVar13 + DAT_0003e724);
  if (pcVar4 != (char *)0x0) {
    __stream = (FILE *)0x0;
  }
  snprintf(pcVar3,0x400,(char *)(DAT_0003e728 + 0x3dae4),DAT_0003e72c + 0x3db7b,0x1a3);
  FUN_0002b1b4(0,pcVar3);
  pcVar4 = (char *)acosNvramConfig_get(DAT_0003e730 + 0x3db20);
  iVar2 = atoi(pcVar4);
  if (__stream == (FILE *)0x0 && iVar2 == 1) {
    pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e734 + 0x3db44));
    if ((pcVar4 == (char *)0x0) ||
       (iVar2 = acosNvramConfig_match(DAT_0003e73c + 0x3db60,DAT_0003e738 + 0x3db5c), iVar2 == 0)) {
      pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e744 + 0x3db80));
      if (((pcVar4 != (char *)0x0) ||
          (pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e748 + 0x3db98)), pcVar4 != (char *)0x0))
         || ((**(int **)(iVar13 + DAT_0003e690) != 0 && (**(int **)(iVar13 + DAT_0003e694) == 0))))
      {
        strlcpy(acStack_900c8,DAT_0003e74c + 0x3dbb4,0x50);
        pcVar4 = (char *)(DAT_0003e750 + 0x3dbc0);
        goto LAB_0003dc98;
      }
      pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e754 + 0x3dbf8));
      if (pcVar4 == (char *)0x0) {
        pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e760 + 0x3dc38));
        if (pcVar4 != (char *)0x0) {
          pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e764 + 0x3dc50));
          __stream = (FILE *)0x0;
          if (pcVar4 != (char *)0x0) goto LAB_0003dca4;
        }
        pcVar4 = (char *)acosNvramConfig_get(DAT_0003e768 + 0x3dc64);
        iVar2 = strcmp(pcVar4,(char *)(DAT_0003e76c + 0x3dc70));
        if (iVar2 == 0) {
          iVar2 = DAT_0003e770 + 0x3dc84;
        }
        else {
          iVar2 = DAT_0003e774 + 0x3dc8c;
        }
        strlcpy(acStack_900c8,iVar2,0x50);
        pcVar4 = (char *)(DAT_0003e778 + 0x3dc9c);
        goto LAB_0003dc98;
      }
      __stream = (FILE *)0x0;
      printf((char *)(DAT_0003e75c + 0x3dc24),DAT_0003e758 + 0x3dc9b,0x1be,acStack_900c8);
    }
    else {
      pcVar4 = (char *)(DAT_0003e740 + 0x3db70);
LAB_0003dc98:
      __stream = fopen64(acStack_900c8,pcVar4);
    }
LAB_0003dca4:
    iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e77c + 0x3dcb4));
    if ((iVar2 == 0) || (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e780 + 0x3dccc)), iVar2 == 0)
       ) {
      pcVar4 = (char *)acosNvramConfig_get(DAT_0003e784 + 0x3dce0);
      iVar2 = strcmp(pcVar4,(char *)(DAT_0003e788 + 0x3dcec));
      if (iVar2 == 0) {
        iVar2 = DAT_0003e78c + 0x3dd00;
      }
      else {
        iVar2 = DAT_0003e790 + 0x3dd08;
      }
      strlcpy(acStack_900c8,iVar2,0x50);
      __stream = fopen64(acStack_900c8,(char *)(DAT_0003e794 + 0x3dd1c));
    }
  }
  pcVar4 = (char *)acosNvramConfig_get(DAT_0003e798 + 0x3dd2c);
  iVar2 = atoi(pcVar4);
  pFVar5 = __stream;
  if ((iVar2 == 1) && (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e79c + 0x3dd50)), iVar2 == 0))
  {
    snprintf(pcVar3,0x400,(char *)(DAT_0003e7a4 + 0x3dd80),DAT_0003e7a0 + 0x3ddfb,0x1ea);
    FUN_0002b1b4(0,pcVar3);
    iVar2 = acosNvramConfig_match(DAT_0003e7ac + 0x3dda0,DAT_0003e7a8 + 0x3dd9c);
    if (iVar2 == 0) {
      memset(acStack_90028,0,0x20);
      system((char *)(DAT_0003e7b0 + 0x3ddc4));
      pFVar5 = fopen64((char *)(DAT_0003e7b8 + 0x3ddd8),(char *)(DAT_0003e7b4 + 0x3ddd4));
      if (pFVar5 != (FILE *)0x0) {
        fgets(acStack_80024,0x80,pFVar5);
        __isoc99_sscanf(acStack_80024,DAT_0003e7bc + 0x3de10,acStack_90028);
        fclose(pFVar5);
      }
      iVar2 = DAT_0003e7c4;
      unlink((char *)(DAT_0003e7c0 + 0x3de2c));
      uVar6 = atoi(acStack_90028);
      iVar14 = DAT_0003e7c8 + 0x3de44;
      uVar7 = acosNvramConfig_get(iVar2 + 0x3de3c);
      printf((char *)(DAT_0003e7d0 + 0x3de6c),DAT_0003e7cc + 0x3dedf,0x221,uVar7);
      iVar2 = acosNvramConfig_match(iVar2 + 0x3de3c,iVar14);
      if (iVar2 == 0) {
        iVar15 = DAT_0003e7d8 + 0x3de9c;
        iVar2 = acosNvramConfig_match(DAT_0003e7dc + 0x3dea0,iVar15);
        if ((iVar2 == 0) &&
           (iVar2 = acosNvramConfig_match(DAT_0003e7e4 + 0x3ded8,iVar15), iVar2 == 0)) {
          iVar2 = acosNvramConfig_match(DAT_0003e7f0 + 0x3df18,iVar14);
          if (iVar2 == 0) {
            iVar2 = DAT_0003e7f8 + 0x3df34;
          }
          else {
            iVar2 = DAT_0003e7f4 + 0x3df2c;
          }
        }
        else if ((uVar6 & 2) == 0) {
          if ((uVar6 & 1) == 0) {
            iVar2 = DAT_0003e7ec + 0x3df08;
          }
          else {
            iVar2 = DAT_0003e7e8 + 0x3defc;
          }
        }
        else {
          iVar2 = DAT_0003e7e0 + 0x3dec8;
        }
      }
      else {
        iVar2 = DAT_0003e7d4 + 0x3de8c;
      }
      strlcpy(acStack_900c8,iVar2);
      iVar2 = acosNvramConfig_match(DAT_0003e800 + 0x3df4c,DAT_0003e7fc + 0x3df48);
      if (iVar2 != 0) {
        printf((char *)(DAT_0003e808 + 0x3df74),DAT_0003e804 + 0x3dfe4,0x239,acStack_900c8);
      }
      pFVar5 = fopen64(acStack_900c8,(char *)(DAT_0003e80c + 0x3df84));
      if (pFVar5 == (FILE *)0x0) {
        printf((char *)(DAT_0003e814 + 0x3dfb0),DAT_0003e810 + 0x3e01c,0x23c,acStack_900c8);
        pFVar5 = __stream;
      }
      else {
        if (__stream != (FILE *)0x0) {
          fclose(__stream);
        }
        iVar2 = acosNvramConfig_match(DAT_0003e81c + 0x3dfd8,DAT_0003e818 + 0x3dfd4);
        if (iVar2 != 0) {
          printf((char *)(DAT_0003e824 + 0x3e000),DAT_0003e820 + 0x3e070,0x245,acStack_900c8);
        }
      }
    }
  }
  pcVar4 = (char *)acosNvramConfig_get(DAT_0003e828 + 0x3e010);
  iVar2 = atoi(pcVar4);
  if ((iVar2 == 1) && (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e82c + 0x3e02c)), iVar2 == 0))
  {
    snprintf(pcVar3,0x400,(char *)(DAT_0003e834 + 0x3e05c),DAT_0003e830 + 0x3e0d7,599);
    FUN_0002b1b4(0,pcVar3);
    pcVar4 = (char *)acosNvramConfig_get(DAT_0003e838 + 0x3e074);
    iVar2 = atoi(pcVar4);
    if (iVar2 == 1) {
      if (pFVar5 != (FILE *)0x0) {
        fclose(pFVar5);
      }
      pcVar4 = (char *)acosNvramConfig_get(DAT_0003e83c + 0x3e09c);
      iVar2 = strcmp(pcVar4,(char *)(DAT_0003e840 + 0x3e0a8));
      if (iVar2 == 0) {
        iVar2 = DAT_0003e844 + 0x3e0bc;
      }
      else {
        iVar2 = DAT_0003e848 + 0x3e0c4;
      }
      strlcpy(acStack_900c8,iVar2,0x50);
      pFVar5 = fopen64(acStack_900c8,(char *)(DAT_0003e84c + 0x3e0d8));
      acosNvramConfig_set(DAT_0003e854 + 0x3e0f0,DAT_0003e850 + 0x3e0e4);
      agApi_natSetWanLanConflictFlag(0);
      acosNvramConfig_save();
    }
  }
  pcVar4 = (char *)acosNvramConfig_get(DAT_0003e858 + 0x3e108);
  iVar2 = atoi(pcVar4);
  if (iVar2 == 0) {
    pcVar4 = (char *)acosNvramConfig_get(DAT_0003e85c + 0x3e120);
    iVar2 = atoi(pcVar4);
    if (iVar2 == 1) {
      snprintf(pcVar3,0x400,(char *)(DAT_0003e864 + 0x3e154),DAT_0003e860 + 0x3e1cf,0x26b);
      FUN_0002b1b4(0,pcVar3);
      iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e868 + 0x3e170));
      if ((((iVar2 == 0) ||
           (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e86c + 0x3e188)), iVar2 == 0)) ||
          (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e870 + 0x3e1a0)), iVar2 == 0)) ||
         ((pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e874 + 0x3e1b8)), pcVar4 == (char *)0x0 ||
          (iVar2 = acosNvramConfig_match(DAT_0003e87c + 0x3e1d4,DAT_0003e878 + 0x3e1d0), iVar2 != 0)
          ))) {
        iVar14 = DAT_0003e89c + 0x3e268;
        iVar2 = acosNvramConfig_match(iVar14,DAT_0003e8a0 + 0x3e26c);
        if (iVar2 == 0) goto LAB_0003e2a0;
        iVar2 = DAT_0003e8a4 + 0x3e288;
        acosNvramConfig_set(DAT_0003e8a8 + 0x3e28c,iVar2);
        acosNvramConfig_set(iVar14,iVar2);
      }
      else {
        if (pFVar5 != (FILE *)0x0) {
          fclose(pFVar5);
        }
        pcVar4 = (char *)acosNvramConfig_get(DAT_0003e880 + 0x3e1f8);
        iVar2 = strcmp(pcVar4,(char *)(DAT_0003e884 + 0x3e204));
        if (iVar2 == 0) {
          iVar2 = DAT_0003e888 + 0x3e218;
        }
        else {
          iVar2 = DAT_0003e88c + 0x3e220;
        }
        strlcpy(acStack_900c8,iVar2,0x50);
        pFVar5 = fopen64(acStack_900c8,(char *)(DAT_0003e890 + 0x3e234));
        acosNvramConfig_set(DAT_0003e898 + 0x3e24c,DAT_0003e894 + 0x3e240);
        agApi_natSetWanLanConflictFlag(0);
      }
      acosNvramConfig_save();
    }
  }
LAB_0003e2a0:
  pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e8ac + 0x3e2b0));
  if (pcVar4 != (char *)0x0) {
    strlcpy(acStack_900c8,DAT_0003e8b0 + 0x3e2cc,0x50);
    pFVar5 = fopen64(acStack_900c8,(char *)(DAT_0003e8b4 + 0x3e2dc));
  }
  if (pFVar5 != (FILE *)0x0) {
    uVar7 = FUN_0003be70(acStack_900c8);
    strlcpy(acStack_900fc,uVar7,0x32);
    iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e8b8 + 0x3e318));
    if (iVar2 == 0) {
      FUN_0003b098(acStack_900c8,pFVar5);
      FUN_0003bc98(param_2,*(undefined4 *)(iVar13 + DAT_0003e67c),acStack_900fc);
      uVar7 = 0x2a7;
      iVar2 = DAT_0003e8bc + 0x3e3e3;
      pcVar4 = (char *)(DAT_0003e8c0 + 0x3e368);
LAB_0003e458:
      snprintf(pcVar3,0x400,pcVar4,iVar2,uVar7);
    }
    else {
      iVar2 = strcmp(acStack_900fc,(char *)(DAT_0003e8c4 + 0x3e378));
      if (iVar2 == 0) {
        FUN_000c4714(acStack_900c8);
        FUN_0003b098(acStack_900c8,pFVar5);
        pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e8c8 + 0x3e3a4));
        if (pcVar4 == (char *)0x0) {
          FUN_0003bb0c(param_2,*(undefined4 *)(iVar13 + DAT_0003e67c),acStack_900fc);
        }
        uVar7 = 0x2b6;
        iVar2 = DAT_0003e8cc + 0x3e463;
        pcVar4 = (char *)(DAT_0003e8d0 + 0x3e3e8);
LAB_0003e3e4:
        snprintf(pcVar3,0x400,pcVar4,iVar2,uVar7);
      }
      else {
        iVar2 = strcmp(acStack_900fc,(char *)(DAT_0003e8d4 + 0x3e410));
        if (iVar2 == 0) {
          FUN_0003b098(acStack_900c8,pFVar5);
          FUN_0003b9c8(param_2,*(undefined4 *)(iVar13 + DAT_0003e67c));
          uVar7 = 0x2bf;
          iVar2 = DAT_0003e8d8 + 0x3e4d7;
          pcVar4 = (char *)(DAT_0003e8dc + 0x3e45c);
          goto LAB_0003e458;
        }
        iVar2 = strcmp(acStack_900fc,(char *)(DAT_0003e8e0 + 0x3e480));
        if (iVar2 != 0) {
          uVar6 = FUN_0003bf48(pFVar5,acStack_80024);
          if (0x7ffff < uVar6) {
            fseek(pFVar5,0,0);
            fseek(pFVar5,0,2);
            lVar9 = ftell(pFVar5);
            iVar2 = acosNvramConfig_match(DAT_0003e92c + 0x3ea3c,DAT_0003e928 + 0x3ea30);
            if (iVar2 != 0) {
              printf((char *)(DAT_0003e934 + 0x3ea60),DAT_0003e930 + 0x3ead0,0x306);
            }
            pcVar4 = strstr(param_1,(char *)(DAT_0003e938 + 0x3ea70));
            if ((pcVar4 == (char *)0x0) &&
               (pcVar4 = strstr(param_1,(char *)(DAT_0003e93c + 0x3ea88)), pcVar4 == (char *)0x0)) {
              uVar7 = FUN_0003be70(acStack_900c8);
              snprintf(acStack_90028,400,(char *)(DAT_0003e940 + 0x3eaac),lVar9,uVar7);
              iVar2 = acosNvramConfig_match(DAT_0003e948 + 0x3eac8,DAT_0003e944 + 0x3eac4);
              if (iVar2 != 0) {
                printf((char *)(DAT_0003e950 + 0x3eaf0),DAT_0003e94c + 0x3eb60,0x312,param_1);
              }
            }
            else {
              uVar7 = FUN_0003be70(acStack_900c8);
              snprintf(acStack_90028,400,(char *)(DAT_0003e954 + 0x3eb10),lVar9,uVar7);
            }
            sVar8 = strlen(acStack_90028);
            iVar2 = FUN_0002bf74(param_2,acStack_90028,sVar8,0);
            if (lVar9 != 0 && iVar2 != -1) {
              fseek(pFVar5,0,0);
              while (sVar8 = fread(acStack_80024,1,0x80000,pFVar5), 0 < (int)sVar8) {
                FUN_0002bf74(param_2,acStack_80024,sVar8,0);
              }
            }
            fclose(pFVar5);
            uVar7 = 0x332;
            iVar2 = DAT_0003e958 + 0x3ec23;
            pcVar4 = (char *)(DAT_0003e95c + 0x3eba8);
            goto LAB_0003e3e4;
          }
          pcVar4 = strstr(param_1,(char *)(DAT_0003e8f0 + 0x3e51c));
          if ((pcVar4 == (char *)0x0) &&
             (pcVar4 = strstr(param_1,(char *)(DAT_0003e8f4 + 0x3e534)), pcVar4 == (char *)0x0)) {
            uVar7 = FUN_0003be70(acStack_900c8);
            snprintf(acStack_90028,400,(char *)(DAT_0003e8f8 + 0x3e558),uVar6,uVar7);
            iVar2 = acosNvramConfig_match(DAT_0003e900 + 0x3e574,DAT_0003e8fc + 0x3e570);
            if (iVar2 != 0) {
              uVar7 = 0x2e7;
              iVar2 = DAT_0003e904 + 0x3e60c;
              pcVar4 = (char *)(DAT_0003e908 + 0x3e59c);
LAB_0003e5f8:
              printf(pcVar4,iVar2,uVar7,param_1);
            }
          }
          else {
            uVar7 = FUN_0003be70(acStack_900c8);
            snprintf(acStack_90028,400,(char *)(DAT_0003e90c + 0x3e5b8),uVar6,uVar7);
            iVar2 = acosNvramConfig_match(DAT_0003e914 + 0x3e5d4,DAT_0003e910 + 0x3e5d0);
            if (iVar2 != 0) {
              uVar7 = 0x2f0;
              iVar2 = (int)&DAT_0003e66c + DAT_0003e918;
              pcVar4 = (char *)(DAT_0003e91c + 0x3e5fc);
              goto LAB_0003e5f8;
            }
          }
          sVar8 = strlen(acStack_90028);
          iVar2 = FUN_0002bf74(param_2,acStack_90028,sVar8,0);
          if (uVar6 != 0 && iVar2 != -1) {
            FUN_0002bf74(param_2,acStack_80024,uVar6,0);
          }
          fclose(pFVar5);
          uVar7 = 0x2fc;
          iVar2 = DAT_0003e920 + 0x3e6db;
          pcVar4 = (char *)((int)&DAT_0003e660 + DAT_0003e924);
          goto LAB_0003e3e4;
        }
        FUN_0003b098(acStack_900c8,pFVar5);
        FUN_0003bb0c(param_2,*(undefined4 *)(iVar13 + DAT_0003e67c),DAT_0003e8e4 + 0x3e4ac);
        snprintf(pcVar3,0x400,(char *)(DAT_0003e8ec + 0x3e4dc),DAT_0003e8e8 + 0x3e557,0x2ce);
      }
    }
    FUN_0002b1b4(0,pcVar3);
    goto LAB_0003eff0;
  }
  pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e960 + 0x3ebb8));
  if ((pcVar4 == (char *)0x0) ||
     (pcVar4 = strstr(acStack_900c8,(char *)(DAT_0003e964 + 0x3ebd0)),
     pcVar4 == (char *)0x0 || param_3 == 0)) {
    iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e968 + 0x3ebfc));
    if (iVar2 == 0) {
      iVar2 = DAT_0003e96c + 0x3ec9f;
      pcVar4 = (char *)(DAT_0003e970 + 0x3ec28);
      snprintf(pcVar3,0x400,pcVar4,iVar2,0x346);
      FUN_0002b1b4(0,pcVar3);
      FUN_00046bec(param_2);
      uVar7 = 0x349;
LAB_0003ecb0:
      snprintf(pcVar3,0x400,pcVar4,iVar2,uVar7);
    }
    else {
      iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e974 + 0x3ec60));
      if (iVar2 == 0) {
        iVar2 = DAT_0003e978 + 0x3ed03;
        pcVar4 = (char *)(DAT_0003e97c + 0x3ec8c);
        snprintf(pcVar3,0x400,pcVar4,iVar2,0x351);
        FUN_0002b1b4(0,pcVar3);
        FUN_00047198(param_2);
        uVar7 = 0x354;
        goto LAB_0003ecb0;
      }
      iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e980 + 0x3ece4));
      if (((iVar2 == 0) ||
          (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e984 + 0x3ecfc)), iVar2 == 0)) ||
         (iVar2 = strcmp(acStack_900c8,(char *)(DAT_0003e988 + 0x3ed14)), iVar2 == 0)) {
        iVar2 = DAT_0003e98c + 0x3edb7;
        pcVar4 = (char *)(DAT_0003e990 + 0x3ed40);
        snprintf(pcVar3,0x400,pcVar4,iVar2,0x35e);
        FUN_0002b1b4(0,pcVar3);
        FUN_000a660c(param_2,acStack_900c8);
        uVar7 = 0x361;
      }
      else {
        pcVar4 = strstr(param_1,(char *)(DAT_0003e994 + 0x3ed84));
        if (pcVar4 != (char *)0x0) {
          iVar2 = acosNvramConfig_match(DAT_0003e99c + 0x3eda0,DAT_0003e998 + 0x3ed9c);
          if (iVar2 != 0) {
            printf((char *)(DAT_0003e9a4 + 0x3edc8),DAT_0003e9a0 + 0x3ee38,0x36a,param_1);
          }
          snprintf(acStack_90028,DAT_0003e9b8,(char *)(DAT_0003e9a8 + 0x3ede4),param_1);
          pcVar4 = strstr(acStack_90028,(char *)(DAT_0003e9ac + 0x3edf8));
          if (pcVar4 != (char *)0x0) {
            memset(acStack_80024,0,DAT_0003e9b8);
            if (*pcVar4 == '/') {
              pcVar3 = (char *)(DAT_0003e9b0 + 0x3ee30);
            }
            else {
              pcVar3 = (char *)(DAT_0003e9b4 + 0x3ee38);
            }
            snprintf(acStack_80024,DAT_0003e9b8,pcVar3,pcVar4);
            pcVar4 = strchr(acStack_80024,0x3f);
            if (pcVar4 != (char *)0x0) {
              *pcVar4 = '\0';
            }
            iVar2 = access(acStack_80024,0);
            if (iVar2 == 0) {
              printf((char *)(DAT_0003e9c0 + 0x3ee90),DAT_0003e9bc + 0x3ef03,0x387,puStack_90124,
                     param_1);
              FUN_000a56c4(puStack_90124,param_2,param_1,0);
            }
          }
          goto LAB_0003efb8;
        }
        iVar2 = acosNvramConfig_match(DAT_0003e9c8 + 0x3eebc,DAT_0003e9c4 + 0x3eeb8);
        if (iVar2 != 0) {
          printf((char *)(DAT_0003e9d0 + 0x3eee4),DAT_0003e9cc + 0x3ef54,0x395,param_1);
        }
        pcVar4 = strchr(param_1,0x3f);
        iVar2 = DAT_0003e9d8;
        iVar13 = DAT_0003e9d4 + 0x3eefc;
        pcVar12 = pcVar4;
        if (pcVar4 != (char *)0x0) {
          pcVar12 = pcVar4 + 1;
          *pcVar4 = '\0';
        }
        iVar2 = acosNvramConfig_match(iVar2 + 0x3ef0c,iVar13);
        if (iVar2 != 0) {
          printf((char *)(DAT_0003e9e0 + 0x3ef3c),DAT_0003e9dc + 0x3efa8,0x3a0,param_1,pcVar12);
        }
        iVar2 = DAT_0003e9e4 + 0x3efd7;
        pcVar4 = (char *)(DAT_0003e9e8 + 0x3ef60);
        snprintf(pcVar3,0x400,pcVar4,iVar2,0x3a1);
        FUN_0002b1b4(0,pcVar3);
        FUN_0003c834(param_1,pcVar12,param_2,param_3,pcVar12);
        uVar7 = 0x3a4;
      }
      snprintf(pcVar3,0x400,pcVar4,iVar2,uVar7);
    }
    FUN_0002b1b4(0,pcVar3);
  }
  else {
    FUN_000485bc(param_2);
  }
LAB_0003efb8:
  iVar2 = acosNvramConfig_match(DAT_0003e9f0 + 0x3efcc,DAT_0003e9ec + 0x3efc8);
  if (iVar2 != 0) {
    printf((char *)(DAT_0003e9f8 + 0x3eff0),&UNK_0003f060 + DAT_0003e9f4,0x3a8);
  }
LAB_0003eff0:
  if (iVar10 == *piVar11) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== ENTRY 00047198 =====
===== FUNCTION FUN_00047198 @ 00047198 =====

void FUN_00047198(undefined4 param_1)

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
  
  piVar10 = *(int **)(DAT_00048148 + 0x471ac + DAT_0004814c);
  local_24 = *piVar10;
  strcpy(acStack_298,(char *)(DAT_00048150 + 0x471c4));
  strcpy(acStack_290,(char *)(DAT_00048154 + 0x471e4));
  system((char *)(DAT_00048158 + 0x471f0));
  isTriBand();
  FUN_00046b64();
  iVar2 = acosNvramConfig_match(DAT_00048160 + 0x4720c,DAT_0004815c + 0x47208);
  if (iVar2 != 0) {
    system((char *)(DAT_00048164 + 0x47228));
    pFVar3 = fopen64((char *)(DAT_0004816c + 0x4723c),(char *)(DAT_00048168 + 0x47238));
    if (pFVar3 != (FILE *)0x0) {
      pcVar8 = (char *)(DAT_00048170 + 0x47254);
      pcVar11 = (char *)(DAT_00048174 + 0x4725c);
      iVar2 = DAT_00048178 + 0x47264;
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
    snprintf(acStack_124,0x100,(char *)(DAT_0004817c + 0x472e0),acStack_290);
    system(acStack_124);
    pFVar3 = fopen64((char *)(DAT_00048184 + 0x472fc),(char *)(DAT_00048180 + 0x472f8));
    if (pFVar3 != (FILE *)0x0) {
      pcVar8 = (char *)(DAT_00048188 + 0x47314);
      iVar2 = DAT_0004818c + 0x4731c;
      pcVar11 = (char *)(DAT_00048190 + 0x47324);
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
    iVar9 = DAT_0004819c;
    iVar2 = DAT_00048198;
    system((char *)(DAT_00048194 + 0x473bc));
    system((char *)(DAT_000481a0 + 0x473d4));
    system((char *)(DAT_000481a4 + 0x473e0));
    system((char *)(DAT_000481a8 + 0x473ec));
    snprintf(acStack_124,0x100,(char *)(DAT_000481ac + 0x47400),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(DAT_000481b0 + 0x47420),acStack_290);
    system(acStack_124);
    system((char *)(DAT_000481b4 + 0x47438));
    system((char *)(DAT_000481b8 + 0x47444));
    snprintf(acStack_124,0x100,(char *)(DAT_000481bc + 0x47458),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(DAT_000481c0 + 0x47478),acStack_290);
    system(acStack_124);
    system((char *)(DAT_000481c4 + 0x47490));
    system((char *)(DAT_000481c8 + 0x4749c));
    snprintf(acStack_124,0x100,(char *)(DAT_000481cc + 0x474b0),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(DAT_000481d0 + 0x474d0),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(iVar2 + 0x473cc),acStack_298);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(iVar9 + 0x473d0),acStack_298);
    system(acStack_124);
    iVar1 = DAT_000481d4;
    snprintf(acStack_124,0x100,(char *)(iVar2 + 0x473cc),acStack_290);
    system(acStack_124);
    iVar2 = DAT_000481d8;
    snprintf(acStack_124,0x100,(char *)(iVar9 + 0x473d0),acStack_290);
    system(acStack_124);
    system((char *)(DAT_000481dc + 0x47568));
    system((char *)(iVar2 + 0x47560));
    snprintf(acStack_124,0x100,(char *)(DAT_000481e0 + 0x47584),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(DAT_000481e4 + 0x475a4),acStack_290);
    system(acStack_124);
    system((char *)(DAT_000481e8 + 0x475bc));
    system((char *)(DAT_000481ec + 0x475c8));
    system((char *)(iVar2 + 0x47560));
    snprintf(acStack_124,0x100,(char *)(DAT_000481f0 + 0x475e4),acStack_290);
    system(acStack_124);
    iVar2 = DAT_000481f8;
    snprintf(acStack_124,0x100,(char *)(DAT_000481f4 + 0x47604),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(iVar1 + 0x47564),acStack_298);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(iVar2 + 0x4761c),acStack_298);
    system(acStack_124);
    snprintf(acStack_124,0x100,(char *)(iVar1 + 0x47564),acStack_290);
    system(acStack_124);
    pcVar11 = (char *)(DAT_000481fc + 0x47688);
    snprintf(acStack_124,0x100,(char *)(iVar2 + 0x4761c),acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,pcVar11,acStack_298);
    system(acStack_124);
    pcVar8 = (char *)(DAT_00048200 + 0x476c0);
    snprintf(acStack_124,0x100,pcVar8,acStack_298);
    system(acStack_124);
    snprintf(acStack_124,0x100,pcVar11,acStack_290);
    system(acStack_124);
    snprintf(acStack_124,0x100,pcVar8,acStack_290);
    system(acStack_124);
  }
  iVar2 = acosNvramConfig_match(DAT_00048208 + 0x4771c,DAT_00048204 + 0x47718);
  if (iVar2 != 0) {
    system((char *)(DAT_0004820c + 0x47730));
    system((char *)(DAT_00048210 + 0x4773c));
    system((char *)(DAT_00048214 + 0x47748));
    system((char *)(DAT_00048218 + 0x47754));
    system((char *)(DAT_0004821c + 0x47760));
    system((char *)(DAT_00048220 + 0x4776c));
  }
  iVar2 = acosNvramConfig_match(DAT_00048228 + 0x47780,DAT_00048224 + 0x4777c);
  if (iVar2 == 0) {
    system((char *)(DAT_0004822c + 0x47794));
    system((char *)(DAT_00048230 + 0x477a0));
  }
  pcVar11 = (char *)(DAT_00048234 + 0x477b0);
  iVar9 = DAT_00048238 + 0x477b8;
  pcVar8 = (char *)(DAT_0004823c + 0x477c0);
  system(pcVar11);
  acosNvramConfig_set(DAT_00048240 + 0x477d0,iVar9);
  acosNvramConfig_set(DAT_00048244 + 0x477e0,iVar9);
  acosNvramConfig_set(DAT_00048248 + 0x477f0,iVar9);
  acosNvramConfig_set(DAT_0004824c + 0x47800,iVar9);
  iVar2 = DAT_00048254;
  acosNvramConfig_set(DAT_00048250 + 0x47814,iVar9);
  FUN_00046d78();
  system((char *)(DAT_00048258 + 0x47828));
  system((char *)(DAT_0004825c + 0x47834));
  system((char *)(DAT_00048260 + 0x47840));
  system((char *)(DAT_00048264 + 0x4784c));
  system((char *)(DAT_00048268 + 0x47858));
  system((char *)(DAT_0004826c + 0x47864));
  system((char *)(DAT_00048270 + 0x47870));
  system((char *)(DAT_00048274 + 0x4787c));
  system((char *)(DAT_00048278 + 0x47888));
  system((char *)(DAT_0004827c + 0x47894));
  system((char *)(DAT_00048280 + 0x478a0));
  system((char *)(DAT_00048284 + 0x478ac));
  system((char *)(iVar2 + 0x4781c));
  system(pcVar8);
  iVar9 = DAT_00048288;
  system((char *)(iVar2 + 0x4781c));
  system((char *)(DAT_0004828c + 0x478d8));
  system((char *)(iVar9 + 0x478d4));
  system(pcVar8);
  system((char *)(iVar9 + 0x478d4));
  system((char *)(DAT_00048290 + 0x47904));
  system((char *)(DAT_00048294 + 0x47910));
  system((char *)(DAT_00048298 + 0x4791c));
  system((char *)(DAT_0004829c + 0x47928));
  system((char *)(DAT_000482a0 + 0x47934));
  system((char *)(DAT_000482a4 + 0x47940));
  system((char *)(DAT_000482a8 + 0x4794c));
  system((char *)(DAT_000482ac + 0x47958));
  system((char *)(DAT_000482b0 + 0x47964));
  system((char *)(DAT_000482b4 + 0x47970));
  system((char *)(DAT_000482b8 + 0x4797c));
  system((char *)(DAT_000482bc + 0x47988));
  system((char *)(DAT_000482c0 + 0x47994));
  system((char *)(DAT_000482c4 + 0x479a0));
  system((char *)(DAT_000482c8 + 0x479ac));
  system((char *)(DAT_000482cc + 0x479b8));
  system((char *)(DAT_000482d0 + 0x479c4));
  system((char *)(DAT_000482d4 + 0x479d0));
  system((char *)(DAT_000482d8 + 0x479dc));
  system((char *)(DAT_000482dc + 0x479e8));
  system((char *)(DAT_000482e0 + 0x479f4));
  system((char *)(DAT_000482e4 + 0x47a00));
  system((char *)(DAT_000482e8 + 0x47a0c));
  system((char *)(DAT_000482ec + 0x47a18));
  system((char *)(DAT_000482f0 + 0x47a24));
  system((char *)(DAT_000482f4 + 0x47a30));
  system((char *)(DAT_000482f8 + 0x47a3c));
  system((char *)(DAT_000482fc + 0x47a48));
  system((char *)(DAT_00048300 + 0x47a54));
  system((char *)(DAT_00048304 + 0x47a60));
  system((char *)(DAT_00048308 + 0x47a6c));
  system((char *)(DAT_0004830c + 0x47a78));
  snprintf(acStack_124,0x100,(char *)(DAT_00048310 + 0x47a8c),acStack_290);
  system(acStack_124);
  snprintf(acStack_124,0x100,(char *)(DAT_00048314 + 0x47aac),acStack_290);
  system(acStack_124);
  snprintf(acStack_124,0x100,(char *)(DAT_00048318 + 0x47acc),acStack_290);
  system(acStack_124);
  system((char *)(DAT_0004831c + 0x47ae4));
  system((char *)(DAT_00048320 + 0x47af0));
  system((char *)(DAT_00048324 + 0x47afc));
  system((char *)(DAT_00048328 + 0x47b08));
  system((char *)(DAT_0004832c + 0x47b14));
  system((char *)(DAT_00048330 + 0x47b20));
  system((char *)(DAT_00048334 + 0x47b2c));
  system((char *)(DAT_00048338 + 0x47b38));
  system((char *)(DAT_0004833c + 0x47b44));
  system((char *)(DAT_00048340 + 0x47b50));
  system((char *)(DAT_00048344 + 0x47b5c));
  system((char *)(DAT_00048348 + 0x47b68));
  system((char *)(DAT_0004834c + 0x47b74));
  system((char *)(DAT_00048350 + 0x47b80));
  system((char *)(DAT_00048354 + 0x47b8c));
  system((char *)(DAT_00048358 + 0x47b98));
  system(pcVar11);
  system((char *)(DAT_0004835c + 0x47bac));
  iVar2 = acosNvramConfig_match(DAT_00048364 + 0x47bc0,DAT_00048360 + 0x47bbc);
  if (iVar2 != 0) {
    system((char *)(DAT_00048368 + 0x47bd4));
  }
  system((char *)(DAT_0004836c + 0x47be0));
  SYSTEM(DAT_00048378 + 0x47bfc,DAT_00048374 + 0x47bf8,DAT_00048370 + 0x47bf4);
  system((char *)(DAT_0004837c + 0x47c08));
  system((char *)(DAT_00048380 + 0x47c14));
  system((char *)(DAT_00048384 + 0x47c20));
  iVar2 = acosNvramConfig_match(DAT_0004838c + 0x47c34,DAT_00048388 + 0x47c30);
  if (iVar2 != 0) {
    system((char *)(DAT_00048390 + 0x47c48));
    system((char *)(DAT_00048394 + 0x47c54));
    system((char *)(DAT_00048398 + 0x47c60));
    system((char *)(DAT_0004839c + 0x47c6c));
    system((char *)(DAT_000483a0 + 0x47c78));
    system((char *)(DAT_000483a4 + 0x47c84));
    system((char *)(DAT_000483a8 + 0x47c90));
    system((char *)(DAT_000483ac + 0x47c9c));
    system((char *)(DAT_000483b0 + 0x47ca8));
    system((char *)(DAT_000483b4 + 0x47cb4));
  }
  iVar2 = DAT_000483bc;
  system((char *)(DAT_000483b8 + 0x47cc8));
  pcVar4 = (char *)(iVar2 + 0x47cd4);
  system((char *)(DAT_000483c0 + 0x47cd8));
  memset(auStack_268,0,0x20);
  FUN_000470d4(auStack_268,0x20);
  doSystem(DAT_000483c4 + 0x47d04,auStack_268);
  system((char *)(DAT_000483c8 + 0x47d10));
  pFVar3 = fopen64((char *)(DAT_000483d0 + 0x47d24),(char *)(DAT_000483cc + 0x47d20));
  fseek(pFVar3,0,2);
  sVar5 = ftell(pFVar3);
  fseek(pFVar3,0,0);
  pcVar8 = calloc(1,sVar5);
  fread(pcVar8,1,sVar5,pFVar3);
  pcVar11 = strstr(pcVar8,(char *)(DAT_000483d4 + 0x47d80));
  __stream = fopen64((char *)(DAT_000483d8 + 0x47d94),pcVar4);
  if ((int)sVar5 < 0xa00001) {
    if (0x500000 < (int)sVar5) {
      __stream_00 = fopen64((char *)(DAT_000483e0 + 0x47e18),pcVar4);
      fputs(pcVar8 + 0x500000,__stream_00);
      pcVar8[0x500000] = '\0';
      fputs(pcVar8,__stream);
      goto LAB_00047e40;
    }
    system((char *)(DAT_000483e4 + 0x47e54));
  }
  else {
    __s = pcVar8 + 0x500000;
    __stream_00 = fopen64((char *)(DAT_000483dc + 0x47db4),pcVar4);
    __s[0x500000 - (sVar5 - ((int)pcVar11 - (int)pcVar8))] = '\0';
    fputs(__s,__stream_00);
    *__s = '\0';
    fputs(pcVar8,__stream);
    fputs(pcVar11,__stream_00);
LAB_00047e40:
    fclose(__stream_00);
  }
  fclose(pFVar3);
  fclose(__stream);
  free(pcVar8);
  iVar2 = acosNvramConfig_match(DAT_000483ec + 0x47e80,DAT_000483e8 + 0x47e7c);
  if (iVar2 != 0) {
    system((char *)(DAT_000483f0 + 0x47e94));
    system((char *)(DAT_000483f4 + 0x47ea0));
    system((char *)(DAT_000483f8 + 0x47eac));
    system((char *)(DAT_000483fc + 0x47eb8));
    system((char *)(DAT_00048400 + 0x47ec4));
    system((char *)(DAT_00048404 + 0x47ed0));
    system((char *)(DAT_00048408 + 0x47edc));
    system((char *)(DAT_0004840c + 0x47ee8));
    system((char *)(DAT_00048410 + 0x47ef4));
  }
  SYSTEM(DAT_00048414 + 0x47f00);
  SYSTEM(DAT_00048418 + 0x47f0c);
  SYSTEM(DAT_0004841c + 0x47f18);
  SYSTEM(DAT_00048420 + 0x47f24);
  SYSTEM(DAT_00048424 + 0x47f30);
  SYSTEM(DAT_00048428 + 0x47f3c);
  system((char *)(DAT_0004842c + 0x47f48));
  system((char *)(DAT_00048430 + 0x47f54));
  iVar2 = FUN_00046ff4();
  if (iVar2 == 0) {
    pcVar8 = (char *)(DAT_00048438 + 0x47f70);
  }
  else {
    pcVar8 = (char *)(DAT_00048434 + 0x47f68);
  }
  system(pcVar8);
  iVar9 = DAT_00048444;
  iVar2 = DAT_00048440;
  system((char *)(DAT_0004843c + 0x47f80));
  iVar1 = DAT_0004844c;
  iVar9 = iVar9 + 0x47f94;
  system((char *)(DAT_00048448 + 0x47f98));
  system((char *)(DAT_00048450 + 0x47fac));
  system((char *)(DAT_00048454 + 0x47fb8));
  system((char *)(DAT_00048458 + 0x47fc4));
  system((char *)(DAT_0004845c + 0x47fd0));
  system((char *)(DAT_00048460 + 0x47fdc));
  system((char *)(DAT_00048464 + 0x47fe8));
  system((char *)(DAT_00048468 + 0x47ff4));
  system((char *)(DAT_0004846c + 0x48000));
  system((char *)(DAT_00048470 + 0x4800c));
  system((char *)(DAT_00048474 + 0x48018));
  system((char *)(DAT_00048478 + 0x48024));
  system((char *)(DAT_0004847c + 0x48030));
  system((char *)(iVar2 + 0x47f90));
  system((char *)(DAT_00048480 + 0x48044));
  system((char *)(DAT_00048484 + 0x48050));
  system((char *)(DAT_00048488 + 0x4805c));
  SYSTEM(DAT_00048490 + 0x48070,DAT_0004848c + 0x4806c);
  system((char *)(DAT_00048494 + 0x4807c));
  system((char *)(DAT_00048498 + 0x48088));
  system((char *)(iVar2 + 0x47f90));
  system((char *)(DAT_0004849c + 0x4809c));
  system((char *)(DAT_000484a0 + 0x480a8));
  acosNvramConfig_set(DAT_000484a4 + 0x480b8,iVar9);
  acosNvramConfig_unset(DAT_000484a8 + 0x480c4);
  acosNvramConfig_unset(DAT_000484ac + 0x480d0);
  sleep(1);
  pFVar3 = fopen64((char *)(iVar1 + 0x47fa8),(char *)(DAT_000484b0 + 0x480e8));
  if (pFVar3 == (FILE *)0x0) {
    puts((char *)(DAT_000484b4 + 0x480fc));
  }
  else {
    fseek(pFVar3,0,2);
    sVar5 = ftell(pFVar3);
    __ptr = calloc(1,sVar5);
    if (__ptr != (void *)0x0) {
      fseek(pFVar3,0,0);
      sVar5 = fread(__ptr,1,sVar5,pFVar3);
      fclose(pFVar3);
      printf((char *)(DAT_000484c0 + 0x48520),DAT_000484bc + 0x48524,0x41a);
      unlink((char *)(iVar1 + 0x47fa8));
      acosNvramConfig_set(DAT_000484c4 + 0x48538,iVar9);
      acosNvramConfig_set(DAT_000484c8 + 0x48548,iVar9);
      snprintf(acStack_208,100,(char *)(DAT_000484cc + 0x4855c),sVar5);
      sVar7 = strlen(acStack_208);
      FUN_0002bf74(param_1,acStack_208,sVar7,0);
      FUN_0002bf74(param_1,__ptr,sVar5,0);
      free(__ptr);
      uVar6 = 0;
      goto LAB_0004859c;
    }
    puts((char *)(DAT_000484b8 + 0x48138));
    fclose(pFVar3);
  }
  uVar6 = 0xffffffff;
LAB_0004859c:
  if (local_24 == *piVar10) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar6);
}


===== ENTRY 00066d58 =====
===== FUNCTION FUN_00066d58 @ 00066d58 =====

void FUN_00066d58(uint param_1,void *param_2,size_t param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  void *__dest;
  size_t __n;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  size_t sVar7;
  timeval local_20d0;
  undefined1 auStack_20c8 [36];
  fd_set local_20a4;
  void *local_2024;
  undefined1 auStack_2020 [8188];
  int local_24;
  
  iVar6 = DAT_00067074 + 0x66da8;
  piVar3 = *(int **)(DAT_00067078 + 0x66dac + DAT_00067070);
  local_24 = *piVar3;
  memset(auStack_20c8,0,0x24);
  local_20a4.fds_bits[0] = *(__fd_mask *)(DAT_0006707c + 0x66de4);
  local_20a4.fds_bits[1] = *(__fd_mask *)(DAT_0006707c + 0x66de8);
  local_20a4.fds_bits[2] = *(__fd_mask *)(DAT_0006707c + 0x66dec);
  local_20a4.fds_bits[3] = *(__fd_mask *)(DAT_0006707c + 0x66df0);
  _eval_daemon(&local_20a4,DAT_00067080 + 0x66e04,0,0,0);
  iVar1 = acosNvramConfig_match(iVar6,DAT_00067084 + 0x66e14);
  if (((iVar1 != 0) || (iVar1 = acosNvramConfig_match(iVar6,DAT_0006708c + 0x66e50), iVar1 != 0)) ||
     (iVar1 = acosNvramConfig_match(iVar6,DAT_00067090 + 0x66e68), iVar1 != 0)) {
    system((char *)(DAT_00067088 + 0x66e30));
    wait_for_ppp_to_terminate();
    sleep(1);
  }
  sVar7 = param_4 + 0x10;
  system((char *)(DAT_00067094 + 0x66e80));
  system((char *)(DAT_00067098 + 0x66e8c));
  system((char *)(DAT_0006709c + 0x66e98));
  __dest = malloc(sVar7);
  if (__dest == (void *)0x0) {
    local_2024 = __dest;
    memset(auStack_2020,0,0x1fc);
    FUN_00069de8(2,DAT_000670a4 + 0x66edc,sVar7,DAT_000670a0 + 0x66ef6);
    FUN_000668c0(500,&local_2024,0);
    sVar7 = strlen((char *)&local_2024);
    send(param_1,&local_2024,sVar7,0);
  }
  else {
    if ((int)param_3 < (int)sVar7) {
      memcpy(__dest,param_2,param_3);
    }
    else {
      param_3 = 0;
    }
    uVar4 = param_1 + 0x1f;
    if (-1 < (int)param_1) {
      uVar4 = param_1;
    }
    uVar5 = param_1 & 0x8000001f;
    if ((int)uVar5 < 0) {
      uVar5 = ~(~((uVar5 - 1) * 0x8000000) >> 0x1b) + 1;
    }
    while( true ) {
      local_20d0.tv_sec = 2;
      local_20d0.tv_usec = 0;
      iVar1 = 0;
      do {
        local_20a4.fds_bits[iVar1] = 0;
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0x20);
      local_20a4.fds_bits[(int)uVar4 >> 5] =
           local_20a4.fds_bits[(int)uVar4 >> 5] | 1 << (uVar5 & 0xff);
      iVar1 = select(param_1 + 1,&local_20a4,(fd_set *)0x0,(fd_set *)0x0,&local_20d0);
      if (iVar1 < 0) break;
      if (iVar1 == 0) {
        FUN_000669f4(__dest,param_1,param_5,param_3,auStack_20c8,0);
        free(__dest);
        uVar2 = 0;
        goto LAB_00067044;
      }
      __n = recv(param_1,&local_2024,0x1fff,0);
      if ((int)__n < 0) break;
      if ((int)(param_3 + __n) < (int)sVar7) {
        memcpy((void *)((int)__dest + param_3),&local_2024,__n);
        param_3 = param_3 + __n;
      }
    }
    free(__dest);
  }
  uVar2 = 0xffffffff;
LAB_00067044:
  if (local_24 == *piVar3) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}


===== ENTRY 000a56c4 =====
===== FUNCTION FUN_000a56c4 @ 000a56c4 =====

void FUN_000a56c4(char *param_1,undefined4 param_2,char *param_3,int param_4)

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
  
  piVar13 = *(int **)(DAT_000a6230 + 0xa56e8 + DAT_000a6234);
  iVar10 = *piVar13;
  pcVar1 = strchr(param_3,0x3b);
  if ((((pcVar1 != (char *)0x0) || (pcVar1 = strchr(param_3,0x60), pcVar1 != (char *)0x0)) ||
      (pcVar1 = strchr(param_3,0x24), pcVar1 != (char *)0x0)) ||
     (pcVar1 = strstr(param_3,(char *)(DAT_000a6238 + 0xa574c)), pcVar1 != (char *)0x0)) {
LAB_000a6204:
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
    goto LAB_000a6204;
  }
  _Var2 = fork();
  if (_Var2 != 0) goto LAB_000a61ec;
  memset(acStack_10024,0,0xffff);
  iVar10 = acosNvramConfig_match(DAT_000a6240 + 0xa579c,DAT_000a623c + 0xa5798);
  if (iVar10 != 0) {
    printf((char *)(DAT_000a6248 + 0xa57c4),DAT_000a6244 + 0xa57c0,0x47,param_3,param_4);
  }
  pFVar3 = fopen64((char *)(DAT_000a6250 + 0xa57d8),(char *)(DAT_000a624c + 0xa57d4));
  if (pFVar3 == (FILE *)0x0) {
    system((char *)(DAT_000a6254 + 0xa57ec));
    iVar10 = acosNvramConfig_match(DAT_000a625c + 0xa5800,DAT_000a6258 + 0xa57fc);
    if (iVar10 != 0) {
      puts((char *)(DAT_000a6260 + 0xa5814));
    }
  }
  else {
    fclose(pFVar3);
  }
  pcVar1 = strstr(param_3,(char *)(DAT_000a6264 + 0xa5834));
  if (pcVar1 != (char *)0x0) {
    iVar10 = acosNvramConfig_match(DAT_000a626c + 0xa5850,DAT_000a6268 + 0xa584c);
    if (iVar10 != 0) {
      printf((char *)(DAT_000a6274 + 0xa5870),DAT_000a6270 + 0xa586c,0x58);
    }
    pcVar4 = strchr(pcVar1,0x3f);
    if (pcVar4 == (char *)0x0) {
      iVar10 = acosNvramConfig_match(DAT_000a62bc + 0xa59e0,DAT_000a62b8 + 0xa59dc);
      if (iVar10 != 0) {
        printf((char *)(DAT_000a62c4 + 0xa5a00),DAT_000a62c0 + 0xa59fc,0x72);
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
        iVar10 = acosNvramConfig_match(DAT_000a62cc + 0xa5a78,DAT_000a62c8 + 0xa5a74);
        if (iVar10 != 0) {
          printf((char *)(DAT_000a62d0 + 0xa5a9c),pcVar1,pcVar4,pcVar7,acStack_204e4);
        }
        pcVar1 = acStack_20324;
        strlcpy(pcVar1,pcVar7,0x100);
        iVar10 = acosNvramConfig_match(DAT_000a62d8 + 0xa5ac4,DAT_000a62d4 + 0xa5ac0);
        if (iVar10 != 0) {
          uVar9 = 0x82;
          iVar10 = DAT_000a62dc + 0xa5ae4;
          pcVar4 = (char *)(DAT_000a62e0 + 0xa5ae8);
          goto LAB_000a5ae4;
        }
      }
    }
    else {
      iVar10 = acosNvramConfig_match(DAT_000a627c + 0xa5898,DAT_000a6278 + 0xa5894);
      if (iVar10 != 0) {
        printf((char *)(DAT_000a6284 + 0xa58b8),DAT_000a6280 + 0xa58b4,0x5c);
      }
      pcVar4 = strchr(pcVar1,0x3f);
      iVar10 = acosNvramConfig_match(DAT_000a628c + 0xa58dc,DAT_000a6288 + 0xa58d0);
      if (iVar10 != 0) {
        printf((char *)(DAT_000a6294 + 0xa590c),DAT_000a6290 + 0xa5904,0x5f,pcVar1,pcVar4 + 1);
      }
      strlcpy(acStack_20424,pcVar4 + 1,0x100);
      iVar10 = acosNvramConfig_match(DAT_000a629c + 0xa5934,DAT_000a6298 + 0xa5930);
      if (iVar10 != 0) {
        printf((char *)(DAT_000a62a4 + 0xa5958),DAT_000a62a0 + 0xa5954,99,acStack_20424);
      }
      pcVar1 = strchr(param_3,0x2f);
      if (pcVar1 != (char *)0x0) {
        memset(acStack_204e4,0,0x40);
        if ((uint)((int)pcVar4 - (int)pcVar1) < 0x41) {
          strlcpy(acStack_204e4,pcVar1 + 1);
        }
        iVar10 = acosNvramConfig_match(DAT_000a62ac + 0xa59a8,DAT_000a62a8 + 0xa59a4);
        if (iVar10 != 0) {
          uVar9 = 0x6c;
          iVar10 = DAT_000a62b0 + 0xa59c8;
          pcVar4 = (char *)(DAT_000a62b4 + 0xa59cc);
          pcVar1 = acStack_204e4;
LAB_000a5ae4:
          printf(pcVar4,iVar10,uVar9,pcVar1);
        }
      }
    }
    puVar14 = (undefined4 *)(DAT_000a62e4 + 0xa5b18);
    do {
      puVar14 = puVar14 + 1;
      pcVar1 = (char *)*puVar14;
      if (pcVar1 == (char *)0x0) goto LAB_000a61ec;
      sVar5 = strlen(acStack_204e4);
      sVar6 = strlen(pcVar1);
    } while ((sVar5 != sVar6) || (iVar10 = strncmp(acStack_204e4,pcVar1,sVar5), iVar10 != 0));
  }
  if ((param_4 == 0) || ((param_4 == 1 || (param_4 == 2)))) {
    strlcpy(acStack_20524);
  }
  iVar10 = acosNvramConfig_match(DAT_000a62f8 + 0xa5bb8,DAT_000a62f4 + 0xa5bb4);
  if (iVar10 != 0) {
    printf((char *)(DAT_000a6300 + 0xa5bdc),DAT_000a62fc + 0xa5bd8,0xa5,acStack_20524);
  }
  if (acStack_20324[0] != '\0') {
    setenv((char *)(DAT_000a6304 + 0xa5c04),acStack_20324,1);
  }
  iVar10 = acosNvramConfig_match(DAT_000a630c + 0xa5c18,DAT_000a6308 + 0xa5c14);
  if (iVar10 != 0) {
    pcVar1 = getenv((char *)(DAT_000a6310 + 0xa5c2c));
    printf((char *)(DAT_000a6318 + 0xa5c48),DAT_000a6314 + 0xa5c3c,0xab,pcVar1);
  }
  pcVar1 = (char *)(DAT_000a631c + 0xa5c5c);
  setenv(pcVar1,(char *)(DAT_000a6320 + 0xa5c60),1);
  iVar10 = acosNvramConfig_match(DAT_000a6328 + 0xa5c78,DAT_000a6324 + 0xa5c74);
  if (iVar10 != 0) {
    pcVar1 = getenv(pcVar1);
    printf((char *)(DAT_000a6330 + 0xa5ca4),DAT_000a632c + 0xa5c98,0xaf,pcVar1);
  }
  pcVar1 = (char *)(DAT_000a6334 + 0xa5cb8);
  setenv(pcVar1,acStack_20524,1);
  iVar10 = acosNvramConfig_match(DAT_000a633c + 0xa5cd0,DAT_000a6338 + 0xa5ccc);
  if (iVar10 != 0) {
    pcVar1 = getenv(pcVar1);
    printf((char *)(DAT_000a6344 + 0xa5cfc),DAT_000a6340 + 0xa5cf0,0xb3,pcVar1);
  }
  if (acStack_20424[0] != '\0') {
    setenv((char *)(DAT_000a6348 + 0xa5d1c),acStack_20424,1);
  }
  iVar10 = strcmp(acStack_20524,(char *)(DAT_000a634c + 0xa5d30));
  if (iVar10 == 0) {
    pFVar3 = fopen64((char *)(DAT_000a6354 + 0xa5d4c),(char *)(DAT_000a6350 + 0xa5d48));
    if (pFVar3 != (FILE *)0x0) {
      fclose(pFVar3);
      system((char *)(DAT_000a6358 + 0xa5d64));
      iVar10 = acosNvramConfig_match(DAT_000a6360 + 0xa5d78,DAT_000a635c + 0xa5d74);
      if (iVar10 != 0) {
        puts((char *)(DAT_000a6364 + 0xa5d8c));
      }
    }
    system((char *)(DAT_000a6368 + 0xa5d98));
    sleep(1);
    pFVar3 = fopen64((char *)(DAT_000a6370 + 0xa5db4),(char *)(DAT_000a636c + 0xa5db0));
    if (pFVar3 != (FILE *)0x0) {
      fputs(param_1,pFVar3);
      fclose(pFVar3);
    }
    pcVar1 = (char *)(DAT_000a6374 + 0xa5de0);
  }
  else {
    iVar10 = strcmp(acStack_20524,(char *)(DAT_000a6378 + 0xa5df0));
    if (iVar10 == 0) {
      pFVar3 = fopen64((char *)(DAT_000a6380 + 0xa5e0c),(char *)(DAT_000a637c + 0xa5e08));
      if (pFVar3 != (FILE *)0x0) {
        fclose(pFVar3);
        system((char *)(DAT_000a6384 + 0xa5e24));
        iVar10 = acosNvramConfig_match(DAT_000a638c + 0xa5e38,DAT_000a6388 + 0xa5e34);
        if (iVar10 != 0) {
          puts((char *)(DAT_000a6390 + 0xa5e4c));
        }
      }
      pcVar1 = (char *)(DAT_000a6394 + 0xa5e5c);
    }
    else {
      pFVar3 = fopen64((char *)(DAT_000a639c + 0xa5e70),(char *)(DAT_000a6398 + 0xa5e6c));
      if (pFVar3 != (FILE *)0x0) {
        fclose(pFVar3);
        system((char *)(DAT_000a63a0 + 0xa5e88));
        iVar10 = acosNvramConfig_match(DAT_000a63a8 + 0xa5e9c,DAT_000a63a4 + 0xa5e98);
        if (iVar10 != 0) {
          puts((char *)(DAT_000a63ac + 0xa5eb0));
        }
      }
      pcVar1 = (char *)(DAT_000a63b0 + 0xa5ec0);
    }
  }
  snprintf(acStack_20224,0x200,pcVar1,acStack_204e4);
  system(acStack_20224);
  memset(acStack_204a4,0,0x40);
  memset(auStack_20464,0,0x40);
  memset(auStack_20504,0,0x20);
  memset(auStack_20514,0,0x10);
  iVar10 = acosNvramConfig_match(DAT_000a63b8 + 0xa5f28,DAT_000a63b4 + 0xa5f24);
  if (iVar10 != 0) {
    printf((char *)(DAT_000a63c0 + 0xa5f48),DAT_000a63bc + 0xa5f44,0xec);
  }
  iVar10 = strcmp(acStack_20524,(char *)(DAT_000a63c4 + 0xa5f58));
  if (iVar10 == 0) {
    pcVar4 = (char *)(DAT_000a63c8 + 0xa5f6c);
    pcVar1 = (char *)(DAT_000a63cc + 0xa5f70);
  }
  else {
    iVar10 = strcmp(acStack_20524,(char *)(DAT_000a63d0 + 0xa5f80));
    if (iVar10 == 0) {
      pcVar4 = (char *)(DAT_000a63d4 + 0xa5f94);
      pcVar1 = (char *)(DAT_000a63d8 + 0xa5f98);
    }
    else {
      pcVar4 = (char *)(DAT_000a63dc + 0xa5fa4);
      pcVar1 = (char *)(DAT_000a63e0 + 0xa5fa8);
    }
  }
  pFVar3 = fopen64(pcVar1,pcVar4);
  if (pFVar3 != (FILE *)0x0) {
    iVar10 = acosNvramConfig_match(DAT_000a63e8 + 0xa5fc8,DAT_000a63e4 + 0xa5fc4);
    if (iVar10 != 0) {
      printf((char *)(DAT_000a63f0 + 0xa5fe8),DAT_000a63ec + 0xa5fe4,0xff);
    }
    iVar10 = DAT_000a63f4 + 0xa5ff8;
    pcVar4 = (char *)(DAT_000a63f8 + 0xa6004);
    pcVar1 = (char *)(DAT_000a63fc + 0xa600c);
    iVar11 = DAT_000a6400 + 0xa6010;
    iVar12 = DAT_000a6404 + 0xa601c;
    while( true ) {
      pcVar7 = fgets(acStack_20024,0xffff,pFVar3);
      if (pcVar7 == (char *)0x0) break;
      iVar8 = acosNvramConfig_match(iVar11,iVar10);
      if (iVar8 != 0) {
        printf(pcVar4,iVar12,0x104,acStack_20024);
      }
      pcVar7 = strstr(acStack_20024,pcVar1);
      if (pcVar7 == (char *)0x0) {
        iVar8 = acosNvramConfig_match(DAT_000a6420 + 0xa6104,DAT_000a641c + 0xa6100);
        if (iVar8 != 0) {
          printf((char *)(DAT_000a6428 + 0xa6128),DAT_000a6424 + 0xa6124,0x115,acStack_20024);
        }
      }
      else {
        strlcpy(acStack_204a4,pcVar7 + 7,0x40);
        pcVar7 = strchr(acStack_204a4,10);
        iVar8 = DAT_000a6408 + 0xa609c;
        if (pcVar7 != (char *)0x0) {
          *pcVar7 = '\0';
        }
        iVar8 = acosNvramConfig_match(DAT_000a640c + 0xa60b0,iVar8);
        if (iVar8 != 0) {
          printf((char *)(DAT_000a6414 + 0xa60d4),DAT_000a6410 + 0xa60d0,0x10b,acStack_204a4);
        }
        snprintf(acStack_10024,0xffff,(char *)(DAT_000a6418 + 0xa60ec),acStack_204a4);
      }
    }
    fclose(pFVar3);
  }
  if (acStack_10024[0] != '\0') {
    strcat(acStack_10024,(char *)(DAT_000a642c + 0xa6154));
  }
  iVar10 = acosNvramConfig_match(DAT_000a6434 + 0xa6168,DAT_000a6430 + 0xa6164);
  if (iVar10 != 0) {
    printf((char *)(DAT_000a643c + 0xa618c),DAT_000a6438 + 0xa6188,0x120,acStack_10024);
  }
  if (acStack_10024[0] != '\0') {
    sVar5 = strlen(acStack_10024);
    FUN_0002bf74(param_2,acStack_10024,sVar5,0);
  }
  iVar10 = acosNvramConfig_match(DAT_000a6444 + 0xa61cc,DAT_000a6440 + 0xa61c8);
  if (iVar10 != 0) {
    printf((char *)(DAT_000a644c + 0xa61ec),DAT_000a6448 + 0xa61e8,0x125);
  }
LAB_000a61ec:
                    /* WARNING: Subroutine does not return */
  exit(0);
}


===== ENTRY 000c410c =====
===== FUNCTION FUN_000c410c @ 000c410c =====

void FUN_000c410c(void)

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
  
  iVar4 = DAT_000c4228 + 0xc412c;
  piVar3 = *(int **)(iVar4 + DAT_000c422c);
  local_14 = *piVar3;
  snprintf(acStack_78,100,(char *)(DAT_000c4230 + 0xc413c),DAT_000c423c + 0xc4164,
           DAT_000c4238 + 0xc4158,DAT_000c4234 + 0xc414c);
  system(acStack_78);
  __modes = (char *)(DAT_000c4244 + 0xc4188);
  pcVar1 = (char *)(DAT_000c4248 + 0xc418c);
  **(undefined4 **)(iVar4 + DAT_000c4240) = 0x33e0;
  __stream = fopen64(pcVar1,__modes);
  if (__stream == (FILE *)0x0) {
    puts((char *)(DAT_000c424c + 0xc41a4));
    uVar2 = 0;
  }
  else {
    pcVar1 = fgets(acStack_d8,0x20,__stream);
    if (pcVar1 == (char *)0x0) {
      puts((char *)(DAT_000c4250 + 0xc41d4));
    }
    fclose(__stream);
    snprintf(acStack_b8,0x40,(char *)(DAT_000c4258 + 0xc41fc),DAT_000c4254 + 0xc41f4,acStack_d8);
    system(acStack_b8);
    uVar2 = 1;
  }
  if (local_14 != *piVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}


===== ENTRY 000c7a54 =====
===== FUNCTION FUN_000c7a54 @ 000c7a54 =====

void FUN_000c7a54(undefined4 param_1)

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
  
  iVar5 = DAT_000c7bd4 + 0xc7a74;
  iVar2 = 0;
  piVar3 = *(int **)(iVar5 + DAT_000c7bd8);
  iVar1 = 0;
  local_24 = *piVar3;
  memcpy(auStack_2bc,&UNK_000c7e1f + DAT_000c7bdc,0x96);
  memset(acStack_224,0,0x100);
  memset(acStack_124,0,0x100);
  __format = (char *)(DAT_000c7be0 + 0xc7ad8);
  __modes = (char *)(DAT_000c7be4 + 0xc7ae4);
  __format_00 = (char *)(DAT_000c7be8 + 0xc7af0);
  do {
    snprintf(acStack_224,0x100,__format,param_1,auStack_2bc + iVar2);
    __stream = popen(acStack_224,__modes);
    if (__stream == (FILE *)0x0) {
      perror((char *)(DAT_000c7bec + 0xc7b30));
      iVar1 = 0;
      goto LAB_000c7bb4;
    }
    fgets(acStack_124,0x100,__stream);
    strToLower(acStack_124);
    pcVar4 = (char *)(iVar2 + *(int *)(iVar5 + DAT_000c7bf0));
    iVar2 = iVar2 + 0x32;
    strToLower(pcVar4);
    printf(__format_00,acStack_124,pcVar4);
    pcVar4 = strstr(acStack_124,pcVar4);
    if (pcVar4 == (char *)0x0) {
      iVar1 = iVar1 + 1;
    }
    pclose(__stream);
  } while (iVar2 != 0x96);
  printf((char *)(DAT_000c7bf4 + 0xc7bb0),iVar1);
LAB_000c7bb4:
  if (local_24 != *piVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}


===== ENTRY 000c7bf8 =====
===== FUNCTION FUN_000c7bf8 @ 000c7bf8 =====

void FUN_000c7bf8(void)

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
  
  iVar3 = DAT_000c7d1c + 0xc7c18;
  piVar2 = *(int **)(iVar3 + DAT_000c7d20);
  local_14 = *piVar2;
  snprintf(acStack_78,100,(char *)(DAT_000c7d24 + 0xc7c28),DAT_000c7d28 + 0xc7c38);
  system(acStack_78);
  __modes = (char *)(DAT_000c7d30 + 0xc7c5c);
  pcVar1 = (char *)(DAT_000c7d34 + 0xc7c60);
  **(undefined4 **)(iVar3 + DAT_000c7d2c) = 0x33e0;
  __stream = fopen64(pcVar1,__modes);
  if (__stream == (FILE *)0x0) {
    puts((char *)(DAT_000c7d38 + 0xc7c78));
  }
  else {
    pcVar1 = fgets(acStack_98,0x20,__stream);
    if (pcVar1 == (char *)0x0) {
      puts((char *)(DAT_000c7d3c + 0xc7ca4));
    }
    fclose(__stream);
    unlink((char *)(DAT_000c7d40 + 0xc7cb8));
    unlink((char *)(DAT_000c7d44 + 0xc7cc4));
    local_a8 = DAT_000c7d48 + 0xc7cd8;
    local_a4 = DAT_000c7d50 + 0xc7cec;
    local_9c = 0;
    local_a0 = acStack_98;
    _eval_daemon(&local_a8,DAT_000c7d4c + 0xc7ce4,0,0,0);
  }
  if (local_14 != *piVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


===== ENTRY 0010f334 =====
===== FUNCTION FUN_0010f334 @ 0010f334 =====

void FUN_0010f334(void)

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
  iVar9 = DAT_0010f814 + 0x10f354;
  piVar15 = *(int **)(iVar9 + DAT_0010f818);
  local_1bc[0] = '\0';
  local_1bc[1] = '\0';
  local_1bc[2] = '\0';
  local_1bc[3] = '\0';
  local_24 = *piVar15;
  memset(local_1bc + 4,0,0x92);
  chdir((char *)(DAT_0010f81c + 0x10f380));
  system((char *)(DAT_0010f820 + 0x10f38c));
  __stream = fopen64((char *)(DAT_0010f828 + 0x10f3a0),(char *)(DAT_0010f824 + 0x10f39c));
  if (__stream == (FILE *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    __s2 = (char *)(DAT_0010f82c + 0x10f3c8);
    iVar10 = DAT_0010f830 + 0x10f3d4;
    __needle = (char *)(DAT_0010f834 + 0x10f3e0);
    __format = (char *)(DAT_0010f838 + 0x10f3ec);
    iVar19 = -1;
    iVar20 = -1;
    do {
      do {
        do {
          do {
            do {
              pcVar3 = fgets(local_1bc,0x96,__stream);
              if (pcVar3 == (char *)0x0) goto LAB_0010f7d8;
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
        iVar16 = DAT_0010f83c;
        iVar17 = DAT_0010f83c * iVar14;
        iVar11 = *(int *)(iVar9 + DAT_0010f840);
        iVar21 = iVar17 + 0xc0;
        FUN_0010cb40(acStack_21c,iVar11 + iVar21,0x40);
        iVar19 = iVar6;
        iVar20 = iVar4;
      } while (*(char *)(iVar21 + iVar11) == '\0');
      pcVar18 = acStack_125 + 1;
      pcVar3 = (char *)(iVar17 + 0x100 + iVar11);
      memset(pcVar18,0,0x100);
      snprintf(pcVar18,0x100,__format,(int)local_215);
      pFVar7 = fopen64(pcVar18,(char *)(DAT_0010f844 + 0x10f53c));
      if (pFVar7 == (FILE *)0x0) {
        strlcpy(pcVar3,DAT_0010f848 + 0x10f58c,0x40);
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
      snprintf(pcVar3,0x100,(char *)(DAT_0010f84c + 0x10f5b4),(int)local_215);
      pFVar7 = fopen64(pcVar3,(char *)(DAT_0010f850 + 0x10f5c8));
      pcVar3 = (char *)(iVar16 * iVar14 + iVar11 + 0x140);
      if (pFVar7 == (FILE *)0x0) {
        strlcpy(pcVar3,DAT_0010f854 + 0x10f620,0x40);
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
      puVar13 = (undefined4 *)(DAT_0010f858 + 0x10f634);
      do {
        puVar12 = puVar13;
        pcVar8 = pcVar3;
        puVar13 = puVar12 + 2;
        uVar2 = puVar12[1];
        *(undefined4 *)pcVar8 = *puVar12;
        *(undefined4 *)(pcVar8 + 4) = uVar2;
        pcVar3 = pcVar8 + 8;
      } while (puVar13 != (undefined4 *)(DAT_0010f858 + 0x10f64c));
      uVar1 = *(undefined2 *)(puVar12 + 3);
      *(undefined4 *)(pcVar8 + 8) = *puVar13;
      *(undefined2 *)(pcVar8 + 0xc) = uVar1;
      snprintf(local_23c,0x1e,(char *)(DAT_0010f85c + 0x10f680),(int)local_215);
      pFVar7 = fopen64(local_23c,(char *)(DAT_0010f860 + 0x10f694));
      if (pFVar7 != (FILE *)0x0) {
        fgets(acStack_125 + 1,0x80,pFVar7);
        fclose(pFVar7);
        sVar5 = strlen(acStack_125 + 1);
        if (1 < sVar5) {
          acStack_125[sVar5] = '\0';
        }
      }
      pcVar3 = acStack_125 + 1;
      snprintf(pcVar18,0x20,(char *)(DAT_0010f864 + 0x10f6f8),pcVar3);
      snprintf(local_23c,0x1e,(char *)(DAT_0010f868 + 0x10f710),(int)local_215);
      pFVar7 = fopen64(local_23c,(char *)(DAT_0010f86c + 0x10f724));
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
      iVar6 = DAT_0010f870;
      iVar17 = iVar11 + iVar16;
      iVar14 = iVar14 + 1;
      *(int *)(iVar17 + 0xc) = iVar4;
      *(undefined4 *)(iVar11 + iVar16) = 1;
      *(int *)(iVar17 + 0x10) = local_260;
      snprintf((char *)(iVar17 + 0x79),0x20,(char *)(iVar6 + 0x10f79c),auStack_1fc);
      snprintf((char *)(iVar11 + iVar16 + 0x99),0x20,(char *)(iVar6 + 0x10f79c),auStack_1dc);
    } while (iVar14 < 0x14);
LAB_0010f7d8:
    fclose(__stream);
    uVar2 = 0;
  }
  if (local_24 == *piVar15) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}


===== ENTRY 00119948 =====
===== FUNCTION FUN_00119948 @ 00119948 =====

void FUN_00119948(int param_1)

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
  
  iVar10 = DAT_00119e38 + 0x119968;
  piVar11 = *(int **)(iVar10 + DAT_00119e3c);
  local_dc[0] = '\0';
  local_dc[1] = '\0';
  local_dc[2] = '\0';
  local_dc[3] = '\0';
  local_1c = *piVar11;
  memset(local_dc + 4,0,0x3c);
  snprintf(local_dc,0x40,(char *)(DAT_00119e44 + 0x1199a4),DAT_00119e40 + 0x1199a0);
  COMMAND(local_dc);
  if (param_1 == 1) {
    system((char *)(DAT_00119e48 + 0x1199c0));
    FUN_0010fc48(0);
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
  if (_Var1 != 0) goto LAB_00119e08;
  if (**(int **)(iVar10 + DAT_00119e4c) != 0) {
    close(**(int **)(iVar10 + DAT_00119e4c));
  }
  if (**(int **)(iVar10 + DAT_00119e50) != 0) {
    close(**(int **)(iVar10 + DAT_00119e50));
  }
  if (**(int **)(iVar10 + DAT_00119e54) != -1) {
    close(**(int **)(iVar10 + DAT_00119e54));
  }
  if (**(int **)(iVar10 + DAT_00119e58) != -1) {
    close(**(int **)(iVar10 + DAT_00119e58));
  }
  iVar10 = DAT_00119e60;
  if (param_1 == 1) {
    system((char *)(DAT_00119e5c + 0x119a5c));
    FUN_0010fc48(0);
    FUN_00117b84();
    iVar2 = acosNvramConfig_match(DAT_00119e64 + 0x119a7c,iVar10 + 0x119a6c);
    if (iVar2 == 0) {
      iVar10 = acosNvramConfig_match(DAT_00119e6c + 0x119aa4,iVar10 + 0x119a6c);
      if ((iVar10 != 0) &&
         (iVar10 = acosNvramConfig_match(DAT_00119e74 + 0x119ac0,DAT_00119e70 + 0x119abc),
         iVar10 != 0)) {
        pcVar3 = (char *)acosNvramConfig_get(DAT_00119e78 + 0x119ad4);
        pcVar4 = (char *)acosNvramConfig_get(DAT_00119e7c + 0x119ae4);
        iVar10 = strcmp(pcVar3,pcVar4);
        if (iVar10 == 0) goto LAB_00119a84;
      }
    }
    else {
LAB_00119a84:
      system((char *)(DAT_00119e68 + 0x119a90));
    }
    iVar10 = acosNvramConfig_match(DAT_00119e84 + 0x119b0c,DAT_00119e80 + 0x119b08);
    if ((iVar10 != 0) &&
       (iVar10 = acosNvramConfig_match(DAT_00119e94 + 0x119b48,DAT_00119e90 + 0x119b44), iVar10 == 0
       )) {
LAB_00119b50:
      FUN_00118cac();
      pcVar3 = (char *)(DAT_00119e98 + 0x119b60);
      goto LAB_00119c64;
    }
    iVar10 = acosNvramConfig_match(DAT_00119e8c + 0x119b28,DAT_00119e88 + 0x119b24);
    if (iVar10 != 0) {
      pcVar3 = (char *)acosNvramConfig_get(DAT_00119e9c + 0x119b6c);
      pcVar4 = (char *)acosNvramConfig_get(DAT_00119ea0 + 0x119b7c);
      iVar10 = strcmp(pcVar3,pcVar4);
      if (iVar10 != 0) goto LAB_00119b50;
    }
  }
  else {
    if (((param_1 != 2) ||
        (iVar10 = acosNvramConfig_match(DAT_00119ea8 + 0x119bb0,DAT_00119ea4 + 0x119bac),
        iVar10 == 0)) ||
       (iVar10 = acosNvramConfig_match(DAT_00119eb0 + 0x119bcc,DAT_00119eac + 0x119bc8), iVar10 != 0
       )) goto LAB_00119c68;
    __stream = fopen64((char *)(DAT_00119eb8 + 0x119be8),(char *)(DAT_00119eb4 + 0x119be4));
    if (__stream != (FILE *)0x0) {
      fgets(acStack_fc,0x10,__stream);
      fclose(__stream);
      FUN_00117b84();
      printf((char *)(DAT_00119ebc + 0x119c20),acStack_fc);
      snprintf(acStack_9c,0x80,(char *)(DAT_00119ec0 + 0x119c38),acStack_fc);
      COMMAND(acStack_9c);
      FUN_0010fc48(1);
      system((char *)(DAT_00119ec4 + 0x119c58));
    }
    FUN_00118cac();
    pcVar3 = (char *)(DAT_00119ec8 + 0x119c68);
LAB_00119c64:
    system(pcVar3);
  }
LAB_00119c68:
  pcVar3 = (char *)acosNvramConfig_get(DAT_00119ecc + 0x119c74);
  iVar2 = atoi(pcVar3);
  pcVar3 = (char *)acosNvramConfig_get(DAT_00119ed0 + 0x119c88);
  iVar10 = atoi(pcVar3);
  pcVar3 = (char *)acosNvramConfig_get(DAT_00119ed4 + 0x119c9c);
  iVar5 = atoi(pcVar3);
  iVar6 = acosNvramConfig_match(DAT_00119edc + 0x119cb8,DAT_00119ed8 + 0x119cac);
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
  uVar7 = acosNvramConfig_get(DAT_00119ee0 + 0x119d44);
  uVar8 = acosNvramConfig_get(DAT_00119ee4 + 0x119d54);
  uVar9 = acosNvramConfig_get(DAT_00119ee8 + 0x119d64);
  iVar10 = acosNvramConfig_match(DAT_00119ef0 + 0x119d7c,DAT_00119eec + 0x119d70);
  if ((iVar10 == 0) ||
     (iVar10 = acosNvramConfig_match(DAT_00119ef8 + 0x119d98,DAT_00119ef4 + 0x119d94), iVar10 != 0))
  {
    iVar10 = FUN_0010f950(uVar7,uVar8,uVar9);
    if (iVar10 != 0) {
      uVar7 = 0;
      goto LAB_00119ddc;
    }
  }
  else {
    iVar10 = FUN_0010f950(uVar7,uVar8,uVar9);
    if (iVar10 == 0) {
      uVar7 = 1;
LAB_00119ddc:
      FUN_0010f874(uVar7);
    }
  }
  snprintf(local_dc,0x40,(char *)(DAT_00119f00 + 0x119dfc),DAT_00119efc + 0x119df8);
  COMMAND(local_dc);
LAB_00119e08:
                    /* WARNING: Subroutine does not return */
  exit(0);
}


===== ENTRY 0011c224 =====
===== FUNCTION FUN_0011c224 @ 0011c224 =====

void FUN_0011c224(void)

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
  
  iVar5 = DAT_0011c798 + 0x11c244;
  iVar9 = 0;
  piVar8 = *(int **)(iVar5 + DAT_0011c79c);
  local_24 = *piVar8;
  memset(local_2b4,0,0x50);
  __dest = *(void **)(iVar5 + DAT_0011c7a0);
  __src = *(void **)(iVar5 + DAT_0011c7a8);
  pcVar6 = (char *)((int)__src + 0x180);
  memcpy(__dest,__src,DAT_0011c7a4);
  memset(__src,0,DAT_0011c7a4);
  FUN_0010f334();
  FUN_0010db1c();
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
  pcVar7 = (char *)(DAT_0011c7ac + 0x11c2f0);
  iVar12 = DAT_0011c7b0 + 0x11c2f8;
  iVar9 = DAT_0011c7b4 + 0x11c300;
  pcVar11 = (char *)(DAT_0011c7b8 + 0x11c308);
  iVar10 = DAT_0011c7bc + 0x11c30c;
  do {
    if (*(int *)(pcVar6 + -0x180) != 0) {
      if (local_2b4[iVar5] != 1) {
        cVar1 = FUN_00113178(pcVar6 + -0x180);
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
      FUN_00112d2c(pcVar6 + -0x180);
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
  pcVar6 = (char *)(DAT_0011c7c0 + 0x11c520);
  pcVar11 = (char *)(DAT_0011c7c4 + 0x11c524);
  pcVar13 = (char *)(DAT_0011c7c8 + 0x11c528);
  iVar5 = DAT_0011c7cc + 0x11c5bf;
  do {
    if (*(int *)(pcVar7 + -0x59) != 0) {
      cVar1 = (char)*(undefined4 *)(pcVar7 + -0x4d) + 'a';
      if (*(int *)(pcVar7 + -0x49) == 0) {
        snprintf(acStack_264,0x40,(char *)(DAT_0011c7d0 + 0x11c56c),(int)cVar1);
      }
      else {
        snprintf(acStack_264,0x40,(char *)(DAT_0011c7d4 + 0x11c58c),(int)cVar1,
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
LAB_0011c634:
          snprintf(pcVar7,0x20,pcVar3,(int)cVar1,pcVar7 + 0x20);
        }
        else {
          sVar4 = strlen(local_224);
          if (sVar4 < 2) {
            cVar1 = pcVar7[-0x41];
            pcVar3 = (char *)(DAT_0011c7d8 + 0x11c5e8);
            goto LAB_0011c634;
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
  FUN_0010fe38();
  FUN_0011bab8();
  iVar5 = FUN_00112514();
  if (iVar5 < 1) {
    iVar5 = DAT_0011c7e4 + 0x11c69c;
    iVar9 = DAT_0011c7e8 + 0x11c6a0;
  }
  else {
    iVar5 = DAT_0011c7dc + 0x11c68c;
    iVar9 = DAT_0011c7e0 + 0x11c690;
  }
  acosNvramConfig_set(iVar9,iVar5);
  iVar9 = DAT_0011c7f4;
  iVar5 = DAT_0011c7f0;
  sVar4 = 0;
  system((char *)(DAT_0011c7ec + 0x11c6b4));
  pcVar7 = (char *)(DAT_0011c7f8 + 0x11c6d4);
  pcVar6 = (char *)(DAT_0011c7fc + 0x11c6d8);
  pcVar11 = (char *)(DAT_0011c800 + 0x11c6dc);
  do {
    if (*(int *)((int)__src + sVar4) == 0) break;
    if (*(int *)((int)__src + sVar4) == 1) {
      snprintf(local_224,0x200,(char *)(iVar5 + 0x11c6c8),(int)__src + sVar4 + 0xc0,
               (int)__src + sVar4 + 0x39,(int)__src + sVar4 + 0x79);
      printf((char *)(iVar9 + 0x11c6d0),local_224);
      pFVar2 = fopen64(pcVar6,pcVar7);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,pcVar11,local_224);
        fclose(pFVar2);
      }
    }
    sVar4 = sVar4 + 0x54d80;
  } while (sVar4 != DAT_0011c7a4);
  if (local_24 != *piVar8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

