
===== TARGET isToRouter =====

===== TARGET parse_http_request =====

===== FUNCTION FUN_0004b3c0 @ 0004b3c0 =====

/* WARNING: Type propagation algorithm not settling */

void FUN_0004b3c0(byte *param_1,int param_2,int *param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  size_t sVar10;
  int iVar11;
  FILE *__stream;
  undefined4 uVar12;
  int iVar13;
  time_t tVar14;
  ulong uVar15;
  int iVar16;
  int *piVar17;
  uint *puVar18;
  uint uVar19;
  int extraout_r1;
  int iVar20;
  int *piVar21;
  int *piVar22;
  uint uVar23;
  byte *pbVar24;
  byte *__s;
  byte *pbVar25;
  byte *__haystack;
  undefined4 *puVar26;
  uint uVar27;
  uint uStack_10500;
  uint uStack_104fc;
  char *pcStack_104f8;
  int iStack_104f4;
  char *pcStack_104e8;
  int iStack_104d4;
  undefined1 auStack_104d0 [16];
  char acStack_104c0 [32];
  uint uStack_104a0;
  undefined1 auStack_1049c [28];
  undefined4 uStack_10480;
  undefined1 auStack_1047c [28];
  uint uStack_10460;
  undefined1 auStack_1045c [28];
  char acStack_10440 [32];
  char acStack_10420 [48];
  int iStack_103f0;
  undefined1 auStack_103ec [60];
  int iStack_103b0;
  undefined1 auStack_103ac [60];
  int iStack_10370;
  undefined1 auStack_1036c [60];
  char acStack_10330 [256];
  char acStack_10230 [512];
  int aiStack_10030 [2];
  undefined1 auStack_10028 [503];
  undefined1 local_fe31;
  
  iVar20 = *DAT_0004c304;
  acStack_10420[0] = '\0';
  acStack_10420[1] = '\0';
  acStack_10420[2] = '\0';
  acStack_10420[3] = '\0';
  memset(acStack_10420 + 4,0,0x2b);
  __s = param_1;
  if (param_1 == (byte *)0x0 || param_3 == (int *)0x0) goto LAB_0004b8d4;
  do {
    pbVar24 = __s;
    __s = pbVar24 + 1;
  } while ((*pbVar24 & 0xdf) != 0);
  *pbVar24 = 0;
  __haystack = __s;
  do {
    pbVar25 = __haystack;
    __haystack = pbVar25 + 1;
  } while (*pbVar25 != 0xd && (*pbVar25 & 0xdf) != 0);
  *pbVar25 = 0;
  pcVar4 = strcasestr((char *)__haystack,DAT_0004c308);
  snprintf((char *)aiStack_10030,0x40,DAT_0004c310,*(undefined4 *)(DAT_0004c30c + 0x10));
  pcVar5 = strcasestr((char *)__haystack,(char *)aiStack_10030);
  pcVar6 = strcasestr((char *)__haystack,DAT_0004c314);
  if (pcVar6 != (char *)0x0) {
    pcVar7 = strstr(pcVar6,DAT_0004c318);
    pcVar9 = DAT_0004c318;
    if ((((pcVar7 == (char *)0x0) &&
         (pcVar7 = strstr(pcVar6,DAT_0004c31c), pcVar9 = DAT_0004c31c, pcVar7 == (char *)0x0)) &&
        (pcVar7 = strstr(pcVar6,DAT_0004c320), pcVar9 = DAT_0004c324, pcVar7 == (char *)0x0)) &&
       (pcVar7 = strstr(pcVar6,DAT_0004c48c), pcVar9 = DAT_0004c48c, pcVar7 == (char *)0x0)) {
      pcVar9 = DAT_0004c47c;
    }
    strcpy(acStack_104c0,pcVar9);
    iVar8 = sys_uptime();
    *DAT_0004c470 = iVar8;
  }
  strcasestr((char *)__haystack,DAT_0004c328);
  acStack_10330[0] = '\0';
  acStack_10330[1] = '\0';
  acStack_10330[2] = '\0';
  acStack_10330[3] = '\0';
  memset(acStack_10330 + 4,0,0xfc);
  iStack_104d4 = 0;
  iVar8 = FUN_0004b1f4(__haystack,acStack_10330,0x100);
  if (iVar8 == 0) {
LAB_0004b5e4:
    iStack_104d4 = 1;
  }
  else {
    FUN_00049588(acStack_10330,0x5b);
    FUN_00049588(acStack_10330,0x5d);
    iVar8 = FUN_000496a0(acStack_10330,DAT_0004c32c);
    if (iVar8 != 0) goto LAB_0004b5e4;
    pcVar9 = (char *)acosNvramConfig_get(DAT_0004c330);
    iVar8 = strcmp(acStack_10330,pcVar9);
    if (iVar8 == 0) goto LAB_0004b5e4;
    pcVar9 = (char *)acosNvramConfig_get(DAT_0004c334);
    iVar8 = strcmp(acStack_10330,pcVar9);
    if ((iVar8 == 0) || (iVar8 = inet_pton(10,acStack_10330,auStack_104d0), 0 < iVar8))
    goto LAB_0004b5e4;
    pcVar9 = (char *)acosNvramConfig_get(DAT_0004c37c);
    iVar8 = strcmp(pcVar9,DAT_0004c4fc);
    if (iVar8 == 0) {
      pcVar9 = (char *)acosNvramConfig_get(DAT_0004c380);
      iVar8 = strcmp(pcVar9,DAT_0004c384);
      if (iVar8 == 0) {
        uVar12 = acosNvramConfig_get(DAT_0004c388);
        snprintf((char *)aiStack_10030,0x800,DAT_0004c38c,uVar12);
      }
      else {
        uVar12 = acosNvramConfig_get(DAT_0004c394);
        strlcpy(aiStack_10030,uVar12,0x800);
      }
      iVar8 = strcmp(acStack_10330,(char *)aiStack_10030);
      if (iVar8 == 0) {
        iStack_104d4 = 1;
      }
    }
    if (iStack_104d4 == 0) {
      printf(DAT_0004c390,DAT_0004c4c4,0xc4e);
      goto LAB_0004b8d4;
    }
  }
  iVar8 = FUN_00069224(param_3);
  if (iVar8 == 0) goto LAB_0004b8d4;
  if (*param_3 == 0) {
    pcVar9 = inet_ntoa((in_addr)param_3[4]);
    strlcpy(acStack_10420,pcVar9,0x2f);
  }
  else {
    inet_ntop(10,param_3 + 5,acStack_10420,0x2f);
  }
  if (pbVar24[1] == 0x2f) {
    __s = pbVar24 + 2;
  }
  pcVar7 = strchr((char *)__s,0x3f);
  pcVar9 = DAT_0004c338;
  pcStack_104e8 = pcVar7;
  if (pcVar7 != (char *)0x0) {
    pcStack_104e8 = pcVar7 + 1;
    *pcVar7 = '\0';
  }
  pcVar9 = strstr((char *)__s,pcVar9);
  if (pcVar9 != (char *)0x0) {
    sVar10 = strlen((char *)__s);
    memset(__s,0,sVar10);
    printf(DAT_0004c340,DAT_0004c33c,0xca0,__s);
  }
  pcVar9 = strstr((char *)__s,DAT_0004c344);
  if (pcVar9 != (char *)0x0) {
    sVar10 = strlen((char *)__s);
    memset(__s,0,sVar10);
    printf(DAT_0004c348,DAT_0004c4c4,0xcab,__s);
  }
  pcVar9 = strstr((char *)__s,DAT_0004c34c);
  if (pcVar9 != (char *)0x0) {
    sVar10 = strlen((char *)__s);
    memset(__s,0,sVar10);
    printf(DAT_0004c348,DAT_0004c4c4,0xcb1,__s);
  }
  iVar8 = strcmp((char *)__s,DAT_0004c350);
  if ((iVar8 == 0) || (iVar8 = strcmp((char *)__s,DAT_0004c354), iVar8 == 0)) {
    pcVar9 = (char *)acosNvramConfig_get(DAT_0004c358);
    iVar8 = strcmp(pcVar9,DAT_0004c4fc);
    if ((iVar8 == 0) && (iVar8 = acosNvramConfig_match(DAT_0004c35c,DAT_0004c4fc), iVar8 != 0)) {
      acosNvramConfig_set(DAT_0004c35c,DAT_0004c484);
    }
  }
  iVar8 = strcmp((char *)__s,DAT_0004c360);
  if ((iVar8 == 0) && (iVar8 = acosNvramConfig_match(DAT_0004c364,DAT_0004c4fc), iVar8 != 0)) {
    acosNvramConfig_set(DAT_0004c364,DAT_0004c484);
  }
  pcVar9 = strstr((char *)__s,DAT_0004c368);
  if (pcVar9 != (char *)0x0) {
    strcpy((char *)__s,DAT_0004c368);
  }
  piVar17 = DAT_0004c36c;
  piVar21 = param_3;
  do {
    piVar22 = piVar21 + 2;
    iVar8 = piVar21[1];
    *piVar17 = *piVar21;
    piVar17[1] = iVar8;
    pcVar9 = DAT_0004c4fc;
    piVar17 = piVar17 + 2;
    piVar21 = piVar22;
  } while (piVar22 != param_3 + 8);
  *piVar17 = *piVar22;
  iVar8 = acosNvramConfig_match(DAT_0004c500,pcVar9);
  if (iVar8 == 0) {
LAB_0004b828:
    iVar8 = DAT_0004c378;
    iVar11 = isLoopBack(acStack_10420);
    uVar12 = DAT_0004c4b4;
    if (iVar11 != 0) {
      *(undefined4 *)(iVar8 + 0x2c) = 1;
LAB_0004bb00:
      uStack_104fc = 1;
      uStack_10500 = 1;
      iStack_104f4 = 0;
      goto LAB_0004b9c4;
    }
    *(undefined4 *)(iVar8 + 0x2c) = 0;
    iVar11 = FUN_000496a0(__s,uVar12);
    if (iVar11 != 0) {
      pcVar9 = strstr((char *)__s,DAT_0004c518);
      if (pcVar9 == (char *)0x0) {
        FUN_0006889c(param_3,0);
      }
      else {
        iVar11 = acosNvramConfig_invmatch(DAT_0004c3f0,DAT_0004c4fc);
        if (iVar11 == 0) {
          FUN_0006889c(param_3,1);
          uVar12 = sys_uptime();
          FUN_000684a4(param_3,uVar12);
          pcVar9 = DAT_0004c484;
        }
        else {
          FUN_0006889c(param_3,0);
          pcVar9 = DAT_0004c4fc;
        }
        acosNvramConfig_set(DAT_0004c3f0,pcVar9);
      }
    }
    iVar11 = isLanSubnet(acStack_10420);
    if (iVar11 == 0) {
      isIpv6LanSubnet(acStack_10420);
    }
    pcVar9 = strstr((char *)__s,DAT_0004c3f4);
    if (pcVar9 != (char *)0x0) {
      acosNvramConfig_set(DAT_0004c3f8,acStack_10420);
    }
    if (((iStack_104d4 == 0) &&
        ((iVar11 = acosNvramConfig_match(DAT_0004c4e0,DAT_0004c384), iVar11 != 0 ||
         (iVar11 = acosNvramConfig_match(DAT_0004c4e0,DAT_0004c4dc), iVar11 != 0)))) && (*__s == 0))
    {
      strcpy((char *)__s,DAT_0004c4e8);
    }
    iVar11 = acosNvramConfig_match(DAT_0004c500,DAT_0004c4fc);
    if ((iVar11 != 0) ||
       (iVar13 = FUN_000496a0(__s,DAT_0004c400), iVar11 = DAT_0004c30c, iVar13 != 0)) {
LAB_0004bd44:
      uStack_104fc = 1;
LAB_0004bd54:
      uStack_10500 = 0;
      pcStack_104f8 = (char *)0x0;
      uVar27 = 0;
      uVar19 = 1;
LAB_0004bd58:
      iStack_104f4 = isLanSubnet(acStack_10420);
      if (iStack_104f4 == 0) {
        iStack_104f4 = isIpv6LanSubnet(acStack_10420);
      }
      iVar8 = FUN_00068994(param_3);
      if (iVar8 == 0) {
        FUN_0006860c(param_3,1);
      }
      if ((uVar19 & uStack_10500) == 0) {
        if (uVar19 != 0) {
LAB_0004ca1c:
          iVar8 = FUN_000496a0(__s,DAT_0004c4cc);
          if (uStack_104fc == 0 && iVar8 == 0) {
            FUN_000680c0(param_3);
            FUN_00068ee0();
            if ((uStack_10500 != 0) && (iVar8 = FUN_00068994(param_3), iVar8 != 0)) {
              uVar12 = sys_uptime();
              iVar8 = FUN_00068e1c(param_3,uVar12);
              if (((iVar8 != 0) && (iVar8 = FUN_00068a08(param_3), iVar8 == 0)) &&
                 ((((pcVar5 = strstr((char *)__s,DAT_0004c4d0), pcVar5 != (char *)0x0 ||
                    (pcVar5 = strstr((char *)__s,DAT_0004c4d4), pcVar5 != (char *)0x0)) &&
                   (pcVar5 = (char *)acosNvramConfig_get(DAT_0004c4d8), *pcVar5 != '\0')) &&
                  (iVar8 = FUN_00068b0c(param_3), iVar8 != 0)))) {
                FUN_00068b90(param_3,1);
                FUN_0006889c(param_3,1);
                FUN_000692f8(param_3);
                FUN_000690e0(param_4);
                *(undefined4 *)(DAT_0004c514 + 0x284) = 1;
                goto LAB_0004b8d4;
              }
            }
            FUN_00068b90(param_3,1);
            uVar12 = sys_uptime();
            iVar8 = FUN_00069054(param_3,uVar12);
            if ((iVar8 == 0) &&
               (iVar8 = acosNvramConfig_match(DAT_0004c500,DAT_0004c4fc), iVar8 == 0)) {
              printf(DAT_0004c508,DAT_0004c504,0x131e,pcVar4);
              aiStack_10030[0] = iVar8;
              memset(aiStack_10030 + 1,0,0xfc);
              iStack_103f0 = iVar8;
              memset(auStack_103ec,0,0x1c);
              iStack_103b0 = iVar8;
              memset(auStack_103ac,0,0x1c);
              iStack_10370 = iVar8;
              memset(auStack_1036c,0,0x1c);
              puVar26 = DAT_0004c50c;
              *DAT_0004c50c = 0;
              if (pcVar4 == (char *)0x0) {
LAB_0004cda0:
                strlcpy(aiStack_10030,DAT_0004c510,0x100);
              }
              else {
                pcVar6 = pcVar4 + 0x11;
                pcVar5 = strchr(pcVar6,0xd);
                if (pcVar5 == (char *)0x0) goto LAB_0004cda0;
                *pcVar5 = '\0';
                *puVar26 = 1;
                sVar10 = strlen(pcVar6);
                piVar17 = aiStack_10030;
                pcVar5 = strstr(pcVar6,DAT_0004c548);
                if (pcVar5 != (char *)0x0) {
                  pcVar5 = strstr(pcVar6,DAT_0004c520);
                  bVar1 = false;
                  if (pcVar5 != (char *)0x0) {
                    bVar1 = (int)pcVar5 - (int)pcVar6 < (int)sVar10;
                    if (bVar1) {
                      strlcpy(&iStack_103f0,DAT_0004c54c,0x20);
                      sVar10 = (int)pcVar5 - (int)pcVar6;
                    }
                    strlcat(piVar17,DAT_0004c550,0x100);
                  }
                  pcVar5 = strstr(pcVar6,DAT_0004c524);
                  if (pcVar5 != (char *)0x0) {
                    if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                      strlcpy(&iStack_103f0,DAT_0004c54c,0x20);
                      bVar1 = true;
                      sVar10 = (int)pcVar5 - (int)pcVar6;
                    }
                    strlcat(piVar17,DAT_0004c550,0x100);
                  }
                  pcVar5 = strstr(pcVar6,DAT_0004c528);
                  if (pcVar5 != (char *)0x0) {
                    if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                      strlcpy(&iStack_103f0,DAT_0004c54c,0x20);
                      bVar1 = true;
                      sVar10 = (int)pcVar5 - (int)pcVar6;
                    }
                    strlcat(piVar17,DAT_0004c550,0x100);
                  }
                  pcVar5 = strstr(pcVar6,DAT_0004c52c);
                  if (pcVar5 != (char *)0x0) {
                    if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                      strlcpy(&iStack_103f0,DAT_0004c53c,0x20);
                      bVar1 = true;
                      sVar10 = (int)pcVar5 - (int)pcVar6;
                    }
                    strlcat(piVar17,DAT_0004c540,0x100);
                  }
                  pcVar5 = strstr(pcVar6,DAT_0004c530);
                  if (pcVar5 != (char *)0x0) {
                    if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                      strlcpy(&iStack_103f0,DAT_0004c53c,0x20);
                      bVar1 = true;
                      sVar10 = (int)pcVar5 - (int)pcVar6;
                    }
                    strlcat(piVar17,DAT_0004c540,0x100);
                  }
                  pcVar5 = strstr(pcVar6,DAT_0004c534);
                  if (pcVar5 != (char *)0x0) {
                    if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                      strlcpy(&iStack_103f0,DAT_0004c53c,0x20);
                      bVar1 = true;
                      sVar10 = (int)pcVar5 - (int)pcVar6;
                    }
                    strlcat(piVar17,DAT_0004c540,0x100);
                  }
                  pcVar5 = strstr(pcVar6,DAT_0004c538);
                  if (pcVar5 != (char *)0x0) {
                    if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                      strlcpy(&iStack_103f0,DAT_0004c53c,0x20);
                      bVar1 = true;
                      sVar10 = (int)pcVar5 - (int)pcVar6;
                    }
                    strlcat(piVar17,DAT_0004c540,0x100);
                  }
                  pcVar5 = strstr(pcVar6,DAT_0004c544);
                  if (pcVar5 != (char *)0x0) {
                    if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                      strlcpy(&iStack_103f0,DAT_0004c54c,0x20);
                      bVar1 = true;
                      sVar10 = (int)pcVar5 - (int)pcVar6;
                    }
                    strlcat(piVar17,DAT_0004c550,0x100);
                  }
                  if (!bVar1) {
                    sVar10 = strlen(pcVar6);
                    pcVar5 = strstr(pcVar6,DAT_0004c548);
                    if (pcVar5 != (char *)0x0) {
                      if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                        strlcpy(&iStack_103f0,DAT_0004c54c,0x20);
                        sVar10 = (int)pcVar5 - (int)pcVar6;
                      }
                      strlcat(piVar17,DAT_0004c550,0x100);
                    }
                  }
                }
                pcVar5 = strstr(pcVar6,DAT_0004c554);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c558,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c55c,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c560);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c564,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c568,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c56c);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c570,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c574,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c578);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c57c,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c580,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c584);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c588,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c58c,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c590);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c594,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c598,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c59c);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c5a0,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c5a4,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c5a8);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c5ac,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c5b0,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c5b4);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c5b8,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c5bc,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c5c0);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c5c4,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c5c8,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c5cc);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c5d0,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c5d4,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c5d8);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c5dc,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c5e0,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c5e4);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c5f0,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c5f4,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c5e8);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c5f0,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c5f4,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c5ec);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c5f0,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c5f4,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c5f8);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c5fc,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c600,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c604);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c608,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c60c,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c610);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c614,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c618,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c61c);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004c620,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004c624,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004c628);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004dc48,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004dc4c,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004dc50);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004dc54,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004dc58,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004dc5c);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004dc60,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004dc64,0x100);
                }
                pcVar5 = strstr(pcVar6,DAT_0004dc68);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004dc6c,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar6;
                  }
                  strlcat(piVar17,DAT_0004dc70,0x100);
                }
                strlcpy(&iStack_103b0,&iStack_103f0,0x20);
                pcVar5 = strstr(pcVar6,DAT_0004dc74);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar6 < (int)sVar10) {
                    strlcpy(&iStack_103f0,DAT_0004dcbc,0x20);
                  }
                  strlcat(piVar17,DAT_0004dc78,0x100);
                }
                if ((char)iStack_103f0 == '\0') {
                  strlcpy(&iStack_103f0,DAT_0004dcbc,0x20);
                }
                acosNvramConfig_set(DAT_0004dc7c,&iStack_103f0);
                acosNvramConfig_set(DAT_0004dc80,piVar17);
                printf(DAT_0004db10,DAT_0004db0c,0x14b3,&iStack_103f0,piVar17);
                iVar8 = acosNvramConfig_match(DAT_0004dd28,DAT_0004dd24);
                if (iVar8 != 0) {
                  iVar8 = strcmp((char *)__s,DAT_0004dc8c);
                  if (((iVar8 == 0) || (iVar8 = strcmp((char *)__s,DAT_0004dc90), iVar8 == 0)) ||
                     ((iVar8 = strcmp((char *)__s,DAT_0004dc94), iVar8 == 0 ||
                      ((iVar8 = strcmp((char *)__s,DAT_0004dc98), iVar8 == 0 ||
                       (iVar8 = strcmp((char *)__s,DAT_0004db14), iVar8 == 0)))))) {
                    printf(DAT_0004dc9c,&iStack_103b0,&iStack_103f0);
                    acosNvramConfig_set(DAT_0004dcb0,DAT_0004dd24);
                    FUN_000e8710(&iStack_103f0);
                  }
                  iVar8 = strcmp((char *)__s,DAT_0004dcd4);
                  if (iVar8 == 0) {
                    uVar12 = acosNvramConfig_get(DAT_0004dcdc);
                    strlcpy(&iStack_10370,uVar12,0x20);
                    FUN_000e8710(&iStack_10370);
                  }
                }
                printf(DAT_0004db18,DAT_0004db0c,0x14c7,__s,piVar17);
                iVar8 = strcmp((char *)__s,DAT_0004dca0);
                if (((iVar8 == 0) || (iVar8 = strcmp((char *)__s,DAT_0004dca4), iVar8 == 0)) ||
                   (iVar8 = strcmp((char *)__s,DAT_0004dca8), iVar8 == 0)) {
                  iVar8 = acosNvramConfig_match(DAT_0004dcb0,DAT_0004dcac);
                  if (iVar8 == 0) {
                    piVar17 = &iStack_103f0;
                  }
                  else {
                    uVar12 = acosNvramConfig_get(DAT_0004dcdc);
                    piVar17 = &iStack_10370;
                    strlcpy(piVar17,uVar12,0x20);
                  }
                  FUN_000e8710(piVar17);
                }
                printf(DAT_0004db1c,DAT_0004db0c,0x14da,1);
                iVar8 = acosNvramConfig_match(DAT_0004dcb0,DAT_0004dcac);
                if (iVar8 != 0) {
                  acosNvramConfig_set(DAT_0004dcb0,DAT_0004dd24);
                }
                FUN_000e8710(&iStack_103f0);
              }
              if (*(int *)(DAT_0004c514 + 0x298) == 0) {
                pcVar5 = strstr((char *)__s,DAT_0004c518);
                if (pcVar5 == (char *)0x0) {
                  FUN_000520ec(DAT_0004c51c,param_4);
                  goto LAB_0004b8d4;
                }
              }
              else {
                *(undefined4 *)(DAT_0004c514 + 0x298) = 0;
              }
            }
            uVar12 = FUN_00068938();
            iVar8 = FUN_00067d2c(uVar12,param_3);
            uVar19 = uStack_10500;
            if (iVar8 != 0) {
              uVar19 = 0;
            }
            uStack_104fc = 0;
            if (uVar19 != 0) {
              if (iStack_104f4 == 0) {
                snprintf(acStack_10230,0x200,DAT_0004db28,acStack_10420);
                sVar10 = strlen(acStack_10230);
                ambitWriteLog(acStack_10230,sVar10,DAT_0004db2c);
                uStack_104fc = 0;
              }
              else {
                snprintf(acStack_10230,0x200,DAT_0004db20,acStack_10420);
                sVar10 = strlen(acStack_10230);
                ambitWriteLog(acStack_10230,sVar10,DAT_0004db24);
              }
            }
          }
          else {
            uStack_104fc = 1;
          }
          *(undefined4 *)(DAT_0004dd20 + 0x298) = 0;
          goto LAB_0004b9c4;
        }
      }
      else {
        if (pcVar6 != (char *)0x0) {
          pcVar9 = strchr(pcVar6,10);
          memset(DAT_0004c4a8,0,0x100);
          pcVar9 = pcVar9 + (1 - (int)pcVar6);
          if (0xff < (int)pcVar9) {
            pcVar9 = (char *)0xff;
          }
          strncpy(DAT_0004c4a8,pcVar6,(size_t)pcVar9);
        }
        iVar8 = FUN_00068584(param_3);
        if ((iVar8 != 0) || (iVar8 = FUN_00068ca0(param_3), iVar8 == 1)) {
          uVar12 = sys_uptime();
          iVar8 = FUN_00068e1c(param_3,uVar12);
          if (iVar8 == 0) {
            iVar8 = FUN_00068584(param_3);
            if ((iVar8 == 0) || (iVar8 = FUN_00068994(param_3), iVar8 == 0)) {
              uVar12 = sys_uptime();
              FUN_0006860c(param_3,uVar12,0);
            }
            else {
              uVar12 = sys_uptime();
              FUN_000684a4(param_3,uVar12);
            }
            FUN_00068c18(param_3,0);
LAB_0004ca10:
            FUN_0006889c(param_3,1);
            goto LAB_0004ca1c;
          }
          uVar12 = sys_uptime();
          iVar8 = FUN_00068e1c(param_3,uVar12);
          if (iVar8 != 0) {
            printf(DAT_0004c3fc,param_3);
            FUN_0005082c();
          }
          iVar8 = FUN_00068ca0(param_3);
          if (iVar8 == 1) {
            iVar8 = FUN_0004b124(__s);
            if (pcVar5 != (char *)0x0 && iVar8 == 0) {
              iVar8 = FUN_00068584(param_3);
              if ((iVar8 == 0) || (iVar8 = FUN_00068994(param_3), iVar8 == 0)) {
                uVar12 = sys_uptime();
                FUN_0006860c(param_3,uVar12,0);
              }
              else {
                uVar12 = sys_uptime();
                FUN_000684a4(param_3,uVar12);
              }
              FUN_00068c18(param_3,0);
              FUN_00068b90(param_3,1);
              goto LAB_0004ca10;
            }
            FUN_00068c18(param_3,0);
            FUN_0006841c(param_3);
            FUN_00068b90(param_3,0);
            FUN_0006889c(param_3,0);
          }
          else {
            iVar8 = rand();
            *(int *)(DAT_0004c30c + 0x10) = *(int *)(DAT_0004c30c + 0x10) + iVar8;
          }
        }
      }
      puts(DAT_0004c4a4);
      iVar8 = FUN_00068584(param_3);
      if (iVar8 == 0) {
LAB_0004c918:
        FUN_00068c18(param_3,1);
      }
      else {
        uVar12 = sys_uptime();
        iVar8 = FUN_00068e1c(param_3,uVar12);
        if (iVar8 != 0) goto LAB_0004c918;
        if (pcVar6 != (char *)0x0) {
          sVar10 = strlen(DAT_0004c4a8);
          iVar8 = strncmp(DAT_0004c4a8,pcVar6,sVar10);
          if (iVar8 == 0) goto LAB_0004c918;
        }
      }
      iVar8 = strncmp((char *)__s,DAT_0004c4ac,8);
      if (((iVar8 == 0) && (pcVar5 = strstr((char *)__s,DAT_0004c4b0), pcVar5 == (char *)0x0)) &&
         ((iVar8 = FUN_000496a0(__s,DAT_0004c4b4), iVar8 != 0 &&
          (iVar8 = strncmp((char *)__s,DAT_0004c4b8,0x11), iVar8 != 0)))) {
        memset(aiStack_10030,0,DAT_0004c4c0);
        snprintf((char *)aiStack_10030,DAT_0004c4c0,DAT_0004c4bc,__s);
        pcVar5 = strchr((char *)aiStack_10030,0x3f);
        if (pcVar5 != (char *)0x0) {
          *pcVar5 = '\0';
        }
        iVar8 = access((char *)aiStack_10030,0);
        if (iVar8 == 0) {
          printf(DAT_0004c4c8,DAT_0004c4c4,0xf18,__s);
          goto LAB_0004b9c4;
        }
      }
      isProductAlias();
      uVar12 = getNTGRAuthrealmAlias();
      *(undefined4 *)(DAT_0004c514 + 0x280) = uVar12;
      FUN_00051ea4(0x191,__haystack,uVar12);
      iVar8 = acosNvramConfig_match(DAT_0004c4e0,DAT_0004c4dc);
      if ((iVar8 == 0) || (iVar8 = acosNvramConfig_match(DAT_0004c4e4,DAT_0004c4fc), iVar8 == 0)) {
        sVar10 = strlen((char *)__haystack);
        FUN_000f8dc8(param_4,__haystack,sVar10);
      }
      else {
        FUN_000520ec(DAT_0004c4e8,param_4);
      }
      if (pcStack_104f8 == (char *)0x0) {
        FUN_000692f8(param_3);
      }
      else if (uVar27 != 0) {
        if (iStack_104f4 == 0) {
          snprintf(acStack_10230,0x200,DAT_0004c4f4,acStack_10420);
          sVar10 = strlen(acStack_10230);
          uVar12 = DAT_0004c4f8;
        }
        else {
          snprintf(acStack_10230,0x200,DAT_0004c4ec,acStack_10420);
          sVar10 = strlen(acStack_10230);
          uVar12 = DAT_0004c4f0;
        }
        ambitWriteLog(acStack_10230,sVar10,uVar12);
      }
      goto LAB_0004b8d4;
    }
    iVar13 = acosNvramConfig_match(DAT_0004c46c,DAT_0004c484);
    if ((iVar13 != 0) && (iVar13 = FUN_000496a0(__s,iVar11 + 0x1f0), iVar13 != 0)) {
      uVar12 = 0x194;
      piVar17 = (int *)0x0;
LAB_0004c1d4:
      FUN_00051ea4(uVar12,__haystack,piVar17);
      sVar10 = strlen((char *)__haystack);
      iVar8 = FUN_000f8dc8(param_4,__haystack,sVar10);
      if (iVar8 == -1) {
        puts(DAT_0004c448);
      }
      goto LAB_0004b8d4;
    }
    iVar13 = acosNvramConfig_match(DAT_0004c46c,DAT_0004c4fc);
    if ((iVar13 != 0) && (iVar13 = FUN_000496a0(__s,DAT_0004c410), iVar13 != 0)) goto LAB_0004bd44;
    iVar13 = acosNvramConfig_match(DAT_0004c404,DAT_0004c4fc);
    if ((iVar13 != 0) && (iVar13 = FUN_000496a0(__s,DAT_0004c414), iVar13 != 0)) {
      acosNvramConfig_set(DAT_0004c404,DAT_0004c484);
      uStack_104fc = 0;
      goto LAB_0004bd54;
    }
    tVar14 = time((time_t *)0x0);
    *(time_t *)(iVar8 + 0x30) = tVar14;
    if (*(int *)(iVar8 + 0x34) != 0) {
      *(int *)(iVar8 + 0x38) = *(int *)(iVar8 + 0x38) + 1;
    }
    if (0 < *(int *)(iVar8 + 0x3c)) {
      printf(DAT_0004c408,DAT_0004c33c,0xd65,*(int *)(iVar8 + 0x38),tVar14,
             *(undefined4 *)(iVar8 + 0x40),*(int *)(iVar8 + 0x3c));
      uVar12 = DAT_0004c488;
      pcVar4 = DAT_0004c484;
      if (*(int *)(iVar8 + 0x30) - *(int *)(iVar8 + 0x40) <= *(int *)(iVar8 + 0x3c)) {
        FUN_000520ec(DAT_0004c418,param_4);
        printf(DAT_0004c41c,
               *(int *)(iVar8 + 0x3c) - (*(int *)(iVar8 + 0x30) - *(int *)(iVar8 + 0x40)));
        goto LAB_0004b8d4;
      }
      *(undefined4 *)(iVar8 + 0x3c) = 0;
      acosNvramConfig_set(uVar12,pcVar4);
      puts(DAT_0004c40c);
LAB_0004bf64:
      FUN_00051ea4(0x191,__haystack,*(undefined4 *)(iVar11 + 0x280));
      sVar10 = strlen((char *)__haystack);
      FUN_000f8dc8(param_4,__haystack,sVar10);
      *(undefined4 *)(iVar8 + 0x34) = 1;
      goto LAB_0004b8d4;
    }
    if (*(int *)(iVar8 + 0x38) == 3) goto LAB_0004bf64;
    pcStack_104f8 = strcasestr((char *)__haystack,DAT_0004c420);
    if (pcStack_104f8 == (char *)0x0) {
      *(undefined4 *)(iVar11 + 0x288) = 0xffffffff;
      pcStack_104f8 = (char *)0x0;
LAB_0004c76c:
      uVar19 = 0;
      uVar27 = uVar19;
    }
    else {
      pcStack_104f8 = pcStack_104f8 + 0x15;
      pcVar9 = strchr(pcStack_104f8,0xd);
      if (pcVar9 != (char *)0x0) {
        *pcVar9 = '\0';
      }
      pcVar9 = strchr(pcStack_104f8,10);
      if (pcVar9 != (char *)0x0) {
        *pcVar9 = '\0';
      }
      base64decode(pcStack_104f8);
      pcVar9 = strchr(pcStack_104f8,0x3a);
      if (pcVar9 == (char *)0x0) goto LAB_0004c76c;
      *pcVar9 = '\0';
      strlcpy(DAT_0004c424,pcStack_104f8,0x800);
      uVar19 = FUN_0004b2a4(DAT_0004c424,pcVar9 + 1);
      iVar13 = acosNvramConfig_match(DAT_0004c428,DAT_0004c4fc);
      if ((((iVar13 == 0) &&
           (iVar13 = acosNvramConfig_match(DAT_0004c42c,DAT_0004c484), iVar13 == 0)) &&
          (iVar13 = acosNvramConfig_match(DAT_0004c500,DAT_0004c4fc),
          uVar19 == 1 && (iVar13 == 0 && *(int *)(iVar8 + 0x44) == 0))) &&
         (((((pcVar9 = strstr((char *)__s,DAT_0004c398), pcVar9 == (char *)0x0 &&
             (pcVar9 = strstr((char *)__s,DAT_0004c4d0), pcVar9 != (char *)0x0)) &&
            ((iVar13 = strcmp((char *)__s,DAT_0004c430), iVar13 != 0 &&
             ((iVar13 = strcmp((char *)__s,DAT_0004c434), iVar13 != 0 &&
              (iVar13 = strcmp((char *)__s,DAT_0004c438), iVar13 != 0)))))) &&
           (iVar13 = strcmp((char *)__s,DAT_0004c43c), iVar13 != 0)) &&
          (iVar13 = strcmp((char *)__s,DAT_0004c440), iVar13 != 0)))) {
        uVar12 = sys_uptime();
        iVar13 = FUN_00069054(param_3,uVar12);
        if (iVar13 != 0) {
          piVar21 = aiStack_10030;
          piVar17 = DAT_0004c444;
          do {
            piVar22 = piVar17 + 2;
            iVar8 = piVar17[1];
            *piVar21 = *piVar17;
            piVar21[1] = iVar8;
            piVar21 = piVar21 + 2;
            piVar17 = piVar22;
          } while (piVar22 != DAT_0004c444 + 8);
          piVar17 = aiStack_10030;
          uVar12 = 0xbcd;
          *(char *)piVar21 = (char)*piVar22;
          goto LAB_0004c1d4;
        }
      }
      iVar13 = isLanSubnet(acStack_10420);
      if (iVar13 == 0) {
        isIpv6LanSubnet(acStack_10420);
      }
      if (uVar19 == 0) {
        if (*(int *)(iVar8 + 0x34) == 0) {
          *(int *)(iVar8 + 0x38) = *(int *)(iVar8 + 0x38) + 1;
        }
        else {
          *(undefined4 *)(iVar8 + 0x34) = 0;
        }
        iVar13 = *(int *)(iVar8 + 0x38);
        if (iVar13 < 3) {
          uVar27 = 1;
          goto LAB_0004c748;
        }
        __aeabi_idivmod(iVar13,3);
        if (extraout_r1 == 0) {
          if (iVar13 == 3) {
            acosNvramConfig_set(DAT_0004c488,DAT_0004c484);
            FUN_000520ec(DAT_0004c418,param_4);
            printf(DAT_0004c450,*(undefined4 *)(iVar8 + 0x38));
            *(undefined4 *)(iVar8 + 0x3c) = 0;
          }
          else {
            if (iVar13 == 6) {
              acosNvramConfig_set(DAT_0004c488,DAT_0004c4fc);
              FUN_000520ec(DAT_0004c418,param_4);
              uVar12 = 0x3c;
            }
            else {
              acosNvramConfig_set(DAT_0004c488,DAT_0004c44c);
              FUN_000520ec(DAT_0004c418,param_4);
              uVar12 = 300;
            }
            *(undefined4 *)(iVar8 + 0x3c) = uVar12;
            tVar14 = time((time_t *)0x0);
            *(time_t *)(iVar8 + 0x40) = tVar14;
            printf(DAT_0004c454,*(undefined4 *)(iVar8 + 0x38),*(undefined4 *)(iVar8 + 0x3c),tVar14);
          }
          goto LAB_0004b8d4;
        }
        uVar27 = 1;
        acosNvramConfig_set(DAT_0004c488,DAT_0004c484);
      }
      else {
        uVar27 = 0;
LAB_0004c748:
        acosNvramConfig_set(DAT_0004c488,DAT_0004c484);
      }
      if (((*DAT_0004c458 == *DAT_0004c45c) || (*DAT_0004c458 == *(int *)(iVar11 + 8))) &&
         (*(int *)(iVar11 + 0x284) != 0)) {
        sprintf(acStack_10230,DAT_0004c460,acStack_10420);
        *(undefined4 *)(iVar11 + 0x284) = 0;
      }
      uVar3 = DAT_0004c468;
      uVar12 = DAT_0004c464;
      if (uVar19 != 0) {
        *(undefined4 *)(iVar11 + 0x288) = 0;
        *(undefined4 *)(iVar8 + 0x38) = 0;
        *(undefined4 *)(iVar8 + 0x34) = 0;
        shared_create_file_with_text(uVar3,uVar12);
      }
    }
    iVar8 = acosNvramConfig_match(DAT_0004c46c,DAT_0004c4fc);
    uStack_104fc = 0;
    if (iVar8 == 0 || uVar19 != 0) {
LAB_0004c884:
      uStack_10500 = 1;
      goto LAB_0004bd58;
    }
    iVar8 = sys_uptime();
    iVar13 = *DAT_0004c470;
    pcVar9 = (char *)acosNvramConfig_get(DAT_0004c474);
    uVar15 = strtoul(pcVar9,(char **)0x0,10);
    pcVar9 = strstr((char *)__s,DAT_0004c478);
    if (pcVar9 != (char *)0x0) {
      uVar19 = 0;
      goto LAB_0004c884;
    }
    iVar16 = strcmp(acStack_104c0,DAT_0004c47c);
    if (iVar16 == 0) {
      pcVar9 = strstr((char *)__s,DAT_0004c480);
      uVar19 = 0;
      if (pcVar9 != (char *)0x0) goto LAB_0004c77c;
LAB_0004c73c:
      *(uint *)(iVar11 + 0x288) = uVar19;
      uStack_104fc = uVar19;
      goto LAB_0004c884;
    }
LAB_0004c77c:
    iVar16 = strcmp(acStack_104c0,DAT_0004c48c);
    uVar19 = strcmp(acStack_104c0,DAT_0004c4a0);
    pcVar7 = DAT_0004c4fc;
    pcVar9 = DAT_0004c4a0;
    uVar12 = DAT_0004c490;
    if ((iVar16 != 0) || (2 < *(int *)(iVar11 + 0x288))) {
      if (uVar19 == 0) {
        if (iVar8 - iVar13 <= (int)(uVar15 * 0x3c)) {
          *(int *)(iVar11 + 0x288) = *(int *)(iVar11 + 0x288) + 1;
          uStack_104fc = 0;
          goto LAB_0004c884;
        }
        goto LAB_0004c73c;
      }
LAB_0004c890:
      uVar19 = 0;
      *(undefined4 *)(iVar11 + 0x288) = 0;
      snprintf(pcVar9,0x20,acStack_104c0);
      goto LAB_0004c884;
    }
    if (uVar19 != 0) goto LAB_0004c890;
    if ((int)(uVar15 * 0x3c) < iVar8 - iVar13) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(iVar11 + 0x288) + 1;
    }
    *(int *)(iVar11 + 0x288) = iVar8;
    iVar8 = acosNvramConfig_match(uVar12,pcVar7);
    if (iVar8 != 0) {
      printf(DAT_0004c494,DAT_0004c4c4,0xe3a,acStack_104c0,*(undefined4 *)(iVar11 + 0x288));
    }
    uVar23 = *(uint *)(iVar11 + 0x288);
    uStack_104fc = uVar23;
    if (2 < (int)uVar23) {
      uStack_104fc = 0;
    }
    *(undefined4 *)(iVar11 + 0x280) = DAT_0004c498;
    if (2 < (int)uVar23) goto LAB_0004c884;
    FUN_00051ea4(0x191,__haystack);
    puts(DAT_0004c49c);
  }
  else {
    if (*__s == 0) {
      fputs(DAT_0004c374,(FILE *)*DAT_0004c370);
      goto LAB_0004b828;
    }
    iVar8 = strncmp((char *)__s,DAT_0004c398,6);
    if (iVar8 == 0) goto LAB_0004bb00;
    iVar8 = strcmp((char *)param_1,DAT_0004c39c);
    if (iVar8 == 0) {
      snprintf((char *)aiStack_10030,0x100,DAT_0004c4bc,__s);
      __stream = fopen((char *)aiStack_10030,DAT_0004c3a0);
      if (__stream == (FILE *)0x0) {
LAB_0004bb70:
        iVar8 = acosNvramConfig_match(DAT_0004c3d8,DAT_0004c4fc);
        if ((((iVar8 == 0) || (iVar8 = strcmp((char *)__s,DAT_0004c3dc), iVar8 != 0)) &&
            (iVar8 = strcmp((char *)__s,DAT_0004c3e0), iVar8 != 0)) &&
           (iVar8 = strcmp((char *)__s,DAT_0004c3e4), iVar8 != 0)) {
          strcpy((char *)__s,DAT_0004c3ac);
        }
      }
      else {
        fclose(__stream);
        pcVar9 = strstr((char *)__s,DAT_0004c3a4);
        if (pcVar9 == (char *)0x0) {
          iVar8 = strcmp(DAT_0004c3a8,(char *)__s);
          if (iVar8 == 0) {
            strcpy((char *)__s,DAT_0004c3ac);
            goto LAB_0004b9b8;
          }
          pcVar9 = strstr((char *)__s,DAT_0004c4d0);
          if ((pcVar9 != (char *)0x0) && (iVar8 = strcmp((char *)__s,DAT_0004c3ac), iVar8 != 0))
          goto LAB_0004b828;
        }
      }
      goto LAB_0004bb00;
    }
    iVar8 = strcmp((char *)param_1,DAT_0004c3cc);
    if (iVar8 != 0) {
      iVar8 = strcmp((char *)param_1,DAT_0004c3ec);
      if (iVar8 != 0) goto LAB_0004bb70;
      goto LAB_0004b828;
    }
    strlcpy(aiStack_10030,__s,0x200);
    local_fe31 = 0;
    pcVar9 = strchr((char *)aiStack_10030,0x3f);
    puVar26 = DAT_0004c3d0;
    if (pcVar9 != (char *)0x0) {
      *pcVar9 = '\0';
      puVar26 = DAT_0004c3d0;
    }
    do {
      if ((char *)*puVar26 == (char *)0x0) {
        pcVar9 = strstr((char *)__s,DAT_0004c3d4);
        if (pcVar9 == (char *)0x0) goto LAB_0004bb70;
        goto LAB_0004b828;
      }
      iVar8 = strcmp((char *)*puVar26,(char *)aiStack_10030);
      puVar26 = puVar26 + 2;
    } while (iVar8 != 0);
    pcVar9 = strstr((char *)aiStack_10030,DAT_0004c3e8);
    if (pcVar9 == (char *)0x0) goto LAB_0004b828;
LAB_0004b9b8:
    iStack_104f4 = 0;
    uStack_104fc = 1;
    uStack_10500 = 1;
LAB_0004b9c4:
    iVar8 = strcmp((char *)param_1,DAT_0004c39c);
    if (iVar8 == 0) {
      pcVar5 = strstr((char *)__s,DAT_0004c4d0);
      if ((pcVar5 == (char *)0x0) && (*__s != 0)) {
LAB_0004b9f8:
        iVar8 = strcmp((char *)__s,DAT_0004c3a8);
        if ((((iVar8 == 0) || (iVar8 = strcmp((char *)__s,DAT_0004c3ac), iVar8 == 0)) ||
            (iVar8 = strcmp((char *)__s,DAT_0004c3b0), iVar8 == 0)) ||
           (((iVar8 = strcmp((char *)__s,DAT_0004c3b4), iVar8 == 0 ||
             (iVar8 = strcmp((char *)__s,DAT_0004c3b8), iVar8 == 0)) ||
            ((iVar8 = strcmp((char *)__s,DAT_0004c3bc), iVar8 == 0 ||
             ((iVar8 = strcmp((char *)__s,DAT_0004c3c0), iVar8 == 0 ||
              (iVar8 = strcmp((char *)__s,DAT_0004c3c4), iVar8 == 0)))))))) goto LAB_0004da60;
LAB_0004ba98:
        if ((iStack_104f4 == 0) && (iVar8 = strncmp((char *)__s,DAT_0004c3c8,0x14), iVar8 == 0)) {
          uVar12 = 0x194;
          goto LAB_0004bac8;
        }
      }
      else {
        if ((((uStack_104fc ^ 1) & uStack_10500) != 0) &&
           (pcVar5 = strstr((char *)__s,DAT_0004db30), pcVar5 == (char *)0x0)) {
          uVar12 = sys_uptime();
          FUN_00068194(param_3,uVar12);
        }
        if (*DAT_0004db34 == 0) {
          FUN_0005082c();
        }
        if (*__s != 0) goto LAB_0004b9f8;
LAB_0004da60:
        aiStack_10030[0] = 0;
        memset(aiStack_10030 + 1,0,0xfc);
        uStack_104a0 = 0;
        memset(auStack_1049c,0,0x1c);
        uStack_10480 = 0;
        memset(auStack_1047c,0,0x1c);
        uStack_10460 = 0;
        memset(auStack_1045c,0,0x1c);
        puVar26 = DAT_0004db38;
        *DAT_0004db38 = 0;
        if (pcVar4 != (char *)0x0) {
          pcVar4 = pcVar4 + 0x11;
          pcVar5 = strchr(pcVar4,0xd);
          if (pcVar5 != (char *)0x0) {
            *pcVar5 = '\0';
            *puVar26 = 1;
            sVar10 = strlen(pcVar4);
            pcVar5 = strstr(pcVar4,DAT_0004db68);
            if (pcVar5 != (char *)0x0) {
              pcVar5 = strstr(pcVar4,DAT_0004db40);
              if (pcVar5 == (char *)0x0) {
                bVar1 = false;
              }
              else {
                bVar1 = (int)pcVar5 - (int)pcVar4 < (int)sVar10;
                if (bVar1) {
                  strlcpy(&uStack_104a0,DAT_0004db6c,0x20);
                  sVar10 = (int)pcVar5 - (int)pcVar4;
                }
                strlcat(aiStack_10030,DAT_0004db70,0x100);
              }
              pcVar5 = strstr(pcVar4,DAT_0004db44);
              if (pcVar5 != (char *)0x0) {
                if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                  bVar1 = true;
                  strlcpy(&uStack_104a0,DAT_0004db6c,0x20);
                  sVar10 = (int)pcVar5 - (int)pcVar4;
                }
                strlcat(aiStack_10030,DAT_0004db70,0x100);
              }
              pcVar5 = strstr(pcVar4,DAT_0004db48);
              if (pcVar5 != (char *)0x0) {
                if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                  bVar1 = true;
                  strlcpy(&uStack_104a0,DAT_0004db6c,0x20);
                  sVar10 = (int)pcVar5 - (int)pcVar4;
                }
                strlcat(aiStack_10030,DAT_0004db70,0x100);
              }
              pcVar5 = strstr(pcVar4,DAT_0004db4c);
              if (pcVar5 != (char *)0x0) {
                if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                  bVar1 = true;
                  strlcpy(&uStack_104a0,DAT_0004db5c,0x20);
                  sVar10 = (int)pcVar5 - (int)pcVar4;
                }
                strlcat(aiStack_10030,DAT_0004db60,0x100);
              }
              pcVar5 = strstr(pcVar4,DAT_0004db50);
              if (pcVar5 != (char *)0x0) {
                if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                  bVar1 = true;
                  strlcpy(&uStack_104a0,DAT_0004db5c,0x20);
                  sVar10 = (int)pcVar5 - (int)pcVar4;
                }
                strlcat(aiStack_10030,DAT_0004db60,0x100);
              }
              pcVar5 = strstr(pcVar4,DAT_0004db54);
              if (pcVar5 != (char *)0x0) {
                if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                  bVar1 = true;
                  strlcpy(&uStack_104a0,DAT_0004db5c,0x20);
                  sVar10 = (int)pcVar5 - (int)pcVar4;
                }
                strlcat(aiStack_10030,DAT_0004db60,0x100);
              }
              pcVar5 = strstr(pcVar4,DAT_0004db58);
              if (pcVar5 != (char *)0x0) {
                if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                  bVar1 = true;
                  strlcpy(&uStack_104a0,DAT_0004db5c,0x20);
                  sVar10 = (int)pcVar5 - (int)pcVar4;
                }
                strlcat(aiStack_10030,DAT_0004db60,0x100);
              }
              pcVar5 = strstr(pcVar4,DAT_0004db64);
              if (pcVar5 != (char *)0x0) {
                if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                  bVar1 = true;
                  strlcpy(&uStack_104a0,DAT_0004db6c,0x20);
                  sVar10 = (int)pcVar5 - (int)pcVar4;
                }
                strlcat(aiStack_10030,DAT_0004db70,0x100);
              }
              if (!bVar1) {
                sVar10 = strlen(pcVar4);
                pcVar5 = strstr(pcVar4,DAT_0004db68);
                if (pcVar5 != (char *)0x0) {
                  if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                    strlcpy(&uStack_104a0,DAT_0004db6c,0x20);
                    sVar10 = (int)pcVar5 - (int)pcVar4;
                  }
                  strlcat(aiStack_10030,DAT_0004db70,0x100);
                }
              }
            }
            pcVar5 = strstr(pcVar4,DAT_0004db74);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004db78,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004db7c,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004db80);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004db84,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004db88,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004db8c);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004db90,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004db94,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004db98);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dcd8,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004db9c,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dba0);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dba4,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dba8,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dbac);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dbb0,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dbb4,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dbb8);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dbbc,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dbc0,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dbc4);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dbc8,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dbcc,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dbd0);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dbd4,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dbd8,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dbdc);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dbe0,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dbe4,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dbe8);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dbec,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dbf0,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dbf4);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dbf8,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dbfc,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc00);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc0c,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc10,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc04);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc0c,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc10,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc08);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc0c,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc10,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc14);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc18,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc1c,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc20);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc24,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc28,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc2c);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc30,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc34,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc38);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc3c,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc40,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc44);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc48,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc4c,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc50);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc54,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc58,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc5c);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc60,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc64,0x100);
            }
            pcVar5 = strstr(pcVar4,DAT_0004dc68);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dc6c,0x20);
                sVar10 = (int)pcVar5 - (int)pcVar4;
              }
              strlcat(aiStack_10030,DAT_0004dc70,0x100);
            }
            strlcpy(&uStack_10480,&uStack_104a0,0x20);
            pcVar5 = strstr(pcVar4,DAT_0004dc74);
            if (pcVar5 != (char *)0x0) {
              if ((int)pcVar5 - (int)pcVar4 < (int)sVar10) {
                strlcpy(&uStack_104a0,DAT_0004dcbc,0x20);
              }
              strlcat(aiStack_10030,DAT_0004dc78,0x100);
            }
            if ((uStack_104a0 & 0xff) == 0) {
              strlcpy(&uStack_104a0,DAT_0004dcbc,0x20);
            }
            acosNvramConfig_set(DAT_0004dc7c,&uStack_104a0);
            acosNvramConfig_set(DAT_0004dc80,aiStack_10030);
            iVar8 = acosNvramConfig_match(DAT_0004dd28,DAT_0004dd24);
            if (iVar8 != 0) {
              iVar8 = acosNvramConfig_match(DAT_0004dc84,DAT_0004dcac);
              if (iVar8 == 0) {
                iVar8 = acosNvramConfig_match(DAT_0004dc88,DAT_0004dcac);
                bVar1 = false;
                if (iVar8 != 0) {
                  bVar1 = true;
                }
              }
              else {
                bVar1 = true;
              }
              iVar8 = strcmp((char *)__s,DAT_0004dc8c);
              if (((iVar8 == 0) || (iVar8 = strcmp((char *)__s,DAT_0004dc90), iVar8 == 0)) ||
                 (iVar8 = strcmp((char *)__s,DAT_0004dc94), iVar8 == 0)) {
LAB_0004e758:
                printf(DAT_0004dc9c,&uStack_10480,&uStack_104a0);
                acosNvramConfig_set(DAT_0004dcb0,DAT_0004dd24);
                FUN_000e8710(&uStack_104a0);
              }
              else {
                iVar8 = strcmp((char *)__s,DAT_0004dc98);
                bVar2 = bVar1;
                if (iVar8 == 0) {
                  bVar2 = true;
                }
                if (bVar2) goto LAB_0004e758;
              }
              iVar8 = strcmp((char *)__s,DAT_0004dcd4);
              if (iVar8 == 0) {
                bVar1 = (bool)(bVar1 ^ 1);
              }
              else {
                bVar1 = false;
              }
              if (bVar1) {
                uVar12 = acosNvramConfig_get(DAT_0004dcdc);
                strlcpy(&uStack_10460,uVar12,0x20);
                FUN_000e8710(&uStack_10460);
              }
            }
            iVar8 = strcmp((char *)__s,DAT_0004dca0);
            if (((iVar8 == 0) || (iVar8 = strcmp((char *)__s,DAT_0004dca4), iVar8 == 0)) ||
               (iVar8 = strcmp((char *)__s,DAT_0004dca8), iVar8 == 0)) {
              iVar8 = acosNvramConfig_match(DAT_0004dcb0,DAT_0004dcac);
              if (iVar8 == 0) {
                puVar18 = &uStack_104a0;
              }
              else {
                uVar12 = acosNvramConfig_get(DAT_0004dcdc);
                puVar18 = &uStack_10460;
                strlcpy(puVar18,uVar12,0x20);
              }
              FUN_000e8710(puVar18);
            }
            if ((char)aiStack_10030[0] == '\0') {
              iVar8 = acosNvramConfig_match(DAT_0004dcc0,DAT_0004dd24);
              if (iVar8 != 0) {
                pcVar4 = (char *)acosNvramConfig_get(DAT_0004dcdc);
                iVar8 = strcmp(DAT_0004dcbc,pcVar4);
                if (iVar8 != 0) {
                  FUN_000e8710(DAT_0004dcbc);
                  iVar8 = acosNvramConfig_match(DAT_0004dcc8,DAT_0004dcc4);
                  if (iVar8 != 0) {
                    FUN_000e25c0(DAT_0004dcbc);
LAB_0004e89c:
                    FUN_0006f958(DAT_0004dcd4,param_4);
                    FUN_0006b7bc();
                  }
                }
              }
            }
            else {
              acStack_10440[0] = '\0';
              acStack_10440[1] = '\0';
              acStack_10440[2] = '\0';
              acStack_10440[3] = '\0';
              memset(acStack_10440 + 4,0,0x1c);
              strlcpy(acStack_10440,&uStack_104a0,0x20);
              pcVar4 = (char *)acosNvramConfig_get(DAT_0004dcdc);
              pcVar5 = strcasestr((char *)aiStack_10030,pcVar4);
              pcVar4 = (char *)acosNvramConfig_get(DAT_0004dcdc);
              uVar19 = strcmp((char *)&uStack_104a0,pcVar4);
              pcVar4 = DAT_0004dcb4;
              if (pcVar5 == (char *)0x0) {
                uVar19 = uVar19 | 1;
              }
              if (uVar19 != 0) {
                iStack_103f0 = 0;
                memset(auStack_103ec,0,0x3c);
                iStack_103b0 = 0;
                memset(auStack_103ac,0,0x3c);
                iStack_10370 = 0;
                memset(auStack_1036c,0,0x3c);
                iVar8 = 1;
                acosNvramConfig_read(DAT_0004dcdc,&iStack_10370,0x40);
                do {
                  snprintf((char *)&iStack_103f0,0x40,pcVar4,iVar8);
                  snprintf((char *)&iStack_103b0,0x40,DAT_0004dcb8,iVar8);
                  pcVar5 = (char *)acosNvramConfig_get(&iStack_103f0);
                  iVar11 = strcmp(acStack_10440,pcVar5);
                  if (iVar11 == 0) goto LAB_0004e9c8;
                  iVar8 = iVar8 + 1;
                } while (iVar8 != 0x19);
                iVar8 = 0;
LAB_0004e9c8:
                iVar11 = strcmp(acStack_10440,DAT_0004dcbc);
                if (iVar11 == 0) {
                  iVar8 = 1;
                }
                iVar11 = acosNvramConfig_match(DAT_0004dcc0,DAT_0004dd24);
                if (iVar11 != 0 && iVar8 != 0) {
                  FUN_000e8710(acStack_10440);
                  iVar8 = acosNvramConfig_match(DAT_0004dcc8,DAT_0004dcc4);
                  if (iVar8 != 0) {
                    FUN_000e25c0(acStack_10440);
                    iVar8 = acosNvramConfig_match(&iStack_10370,DAT_0004dcd8);
                    if ((iVar8 != 0) ||
                       (iVar8 = acosNvramConfig_match(DAT_0004dcdc,DAT_0004dcd8), iVar8 != 0)) {
                      printf(DAT_0004dcd0,DAT_0004dccc,0x128e);
                      acosNvramConfig_save();
                      FUN_0006f5d8(DAT_0004dcd4,param_4);
                      FUN_0006b63c(1);
                      goto LAB_0004b8d4;
                    }
                    goto LAB_0004e89c;
                  }
                }
              }
            }
            goto LAB_0004ba98;
          }
        }
        strlcpy(aiStack_10030,DAT_0004db3c,0x100);
      }
      FUN_000527bc(__s,param_4,uStack_10500,&iStack_104d4,pcStack_104e8);
      goto LAB_0004b8d4;
    }
    iVar8 = strcmp((char *)param_1,DAT_0004dce0);
    if (iVar8 == 0) {
      if (param_2 == 0) goto LAB_0004b8d4;
      iVar8 = FUN_00068a8c(param_3);
      if (iVar8 == 0) {
        if (uStack_104fc == 0) {
          pcVar4 = strstr((char *)__s,DAT_0004dce4);
          if (((((((pcVar4 != (char *)0x0) ||
                  (pcVar4 = strstr((char *)__s,DAT_0004dcf0), pcVar4 != (char *)0x0)) ||
                 (pcVar4 = strstr((char *)__s,DAT_0004dcf4), pcVar4 != (char *)0x0)) ||
                ((pcVar4 = strstr((char *)__s,DAT_0004dcf8), pcVar4 != (char *)0x0 ||
                 (pcVar4 = strstr((char *)__s,DAT_0004dd1c), pcVar4 != (char *)0x0)))) ||
               (pcVar4 = strstr((char *)__s,DAT_0004dcfc), pcVar4 != (char *)0x0)) ||
              (((pcVar4 = strstr((char *)__s,DAT_0004dd00), pcVar4 != (char *)0x0 ||
                (pcVar4 = strstr((char *)__s,DAT_0004dd04), pcVar4 != (char *)0x0)) ||
               ((pcVar4 = strstr((char *)__s,DAT_0004dd08), pcVar4 != (char *)0x0 ||
                ((iVar8 = acosNvramConfig_match(DAT_0004dd28,DAT_0004dd24), iVar8 != 0 ||
                 (pcVar4 = strstr((char *)__s,DAT_0004dd0c), pcVar4 != (char *)0x0)))))))) ||
             ((pcVar4 = strstr((char *)__s,DAT_0004dd10), pcVar4 != (char *)0x0 &&
              (pcVar4 = strstr((char *)__s,DAT_0004dd14), pcVar4 == (char *)0x0))))
          goto LAB_0004eac0;
          pcVar4 = strstr((char *)__s,DAT_0004dd18);
          if (pcVar4 == (char *)0x0) {
            pcVar4 = strstr((char *)__s,DAT_0004dd1c);
            if (pcVar4 == (char *)0x0) {
              uVar12 = sys_uptime();
              FUN_00068194(param_3,uVar12);
              FUN_00068b90(param_3,1);
              FUN_000692f8(param_3);
              FUN_000690e0(param_4);
              *(undefined4 *)(DAT_0004dd20 + 0x284) = 1;
              goto LAB_0004b8d4;
            }
            goto LAB_0004ead4;
          }
        }
      }
      else if (uStack_104fc == 0) {
LAB_0004eac0:
        pcVar4 = strstr((char *)__s,DAT_0004dd18);
        if (pcVar4 == (char *)0x0) {
LAB_0004ead4:
          pcVar4 = strstr((char *)__s,DAT_0004dcfc);
          if (((((pcVar4 == (char *)0x0) &&
                (pcVar4 = strstr((char *)__s,DAT_0004dd00), pcVar4 == (char *)0x0)) &&
               (pcVar4 = strstr((char *)__s,DAT_0004dd04), pcVar4 == (char *)0x0)) &&
              ((pcVar4 = strstr((char *)__s,DAT_0004dce8), pcVar4 == (char *)0x0 &&
               (pcVar4 = strstr((char *)__s,DAT_0004dcec), pcVar4 == (char *)0x0)))) &&
             (pcVar4 = strstr((char *)__s,DAT_0004dd08), pcVar4 == (char *)0x0)) {
            uVar12 = sys_uptime();
            FUN_00068194(param_3,uVar12);
          }
        }
      }
      iVar8 = acosNvramConfig_match(DAT_0004dd28,DAT_0004dd24);
      if (iVar8 != 0) {
        uVar12 = sys_uptime();
        FUN_00068194(param_3,uVar12);
      }
      FUN_00052228(__s,param_2,param_4,uStack_10500,pcStack_104e8);
      goto LAB_0004b8d4;
    }
    iVar8 = strcmp((char *)param_1,DAT_0004dd2c);
    if (iVar8 == 0) {
      FUN_00051bf0(__s,param_2,param_4,uStack_10500,0);
      goto LAB_0004b8d4;
    }
    uVar12 = 400;
LAB_0004bac8:
    FUN_00051ea4(uVar12,__haystack,0);
  }
  sVar10 = strlen((char *)__haystack);
  FUN_000f8dc8(param_4,__haystack,sVar10);
LAB_0004b8d4:
  if (iVar20 != *DAT_0004c304) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


===== TARGET routerlogin.net =====

===== TARGET orbilogin.net =====
