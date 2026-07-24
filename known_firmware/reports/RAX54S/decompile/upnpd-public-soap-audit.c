
===== TARGET Public_UPNP_C3 =====

===== FUNCTION FUN_00038500 @ 00038500 =====

void FUN_00038500(char *param_1,undefined4 param_2,undefined4 param_3)

{
  size_t sVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  long lVar7;
  FILE *pFVar8;
  char *pcVar9;
  undefined4 *puVar10;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  int *piVar15;
  char *__s1;
  int iVar16;
  int iStack_20424;
  int iStack_20420;
  int iStack_2041c;
  int iStack_20418;
  int iStack_20414;
  char acStack_20024 [4];
  char acStack_20020 [131072];
  
  iVar14 = DAT_00039148 + 0x38520;
  piVar15 = *(int **)(iVar14 + DAT_0003914c);
  iVar12 = *piVar15;
  memset(acStack_20024 + 4,0,0x1fffc);
  FUN_0001ab94(3,DAT_00039154 + 0x38574,DAT_00039150 + 0x38648,0x882);
  if (*param_1 == '\0') {
LAB_00038584:
    iVar16 = 0x192;
LAB_00038588:
    memset(acStack_20024,0,0x20000);
  }
  else {
    pcVar2 = (char *)acosNvramConfig_get(DAT_00039158 + 0x38608);
    lVar3 = strtol(pcVar2,(char **)0x0,10);
    pcVar2 = *(char **)(iVar14 + DAT_0003915c);
    memset(pcVar2,0,0x400);
    iVar16 = FUN_00035264(param_1);
    iVar4 = DAT_00039164;
    if (iVar16 < 0) {
      iVar16 = -iVar16;
      goto LAB_00038588;
    }
    puVar10 = *(undefined4 **)(iVar14 + DAT_00039160);
    pcVar9 = (char *)(DAT_00039168 + 0x38664);
    *puVar10 = 0x10;
    __s1 = *(char **)(iVar14 + iVar4);
    iVar4 = strcmp(__s1,pcVar9);
    if (iVar4 == 0) {
      iStack_20424 = iVar4;
      iStack_20420 = iVar4;
      iStack_2041c = iVar4;
      iStack_20418 = iVar4;
      iStack_20414 = iVar4;
      iVar16 = FUN_0003812c();
      if (iVar16 == 1) {
        strncpy((char *)&iStack_20424,(char *)(DAT_000391c8 + 0x389dc),0x13);
      }
      else if (iVar16 == 2) {
        strncpy((char *)&iStack_20424,(char *)(DAT_000391a8 + 0x3889c),0x13);
      }
      snprintf(pcVar2,0x400,*(char **)(iVar14 + DAT_000391ac),__s1);
      pcVar11 = *(char **)(iVar14 + DAT_000391b0);
      snprintf(pcVar11,0x400,(char *)(DAT_000391b4 + 0x388d4),&iStack_20424);
      sVar1 = strlen(pcVar2);
      pcVar9 = stpcpy(pcVar2 + sVar1,pcVar11);
      strncpy(pcVar11,(char *)(DAT_000391b8 + 0x38904),0x3ff);
      strcpy(pcVar9,pcVar11);
      snprintf(pcVar11,0x400,*(char **)(iVar14 + DAT_000391bc),__s1);
      strcat(pcVar2,pcVar11);
LAB_0003893c:
      memset(acStack_20024,0,0x20000);
LAB_00038950:
      FUN_000357f0(acStack_20024,0x20000);
      sVar1 = strlen(acStack_20024);
      FUN_0001a768(param_2,acStack_20024,sVar1,1);
      iVar14 = strcmp(__s1,(char *)(DAT_000391c0 + 0x38998));
      if ((iVar14 != 0) && (iVar14 = strcmp(__s1,(char *)(DAT_000391c4 + 0x389b0)), iVar14 != 0)) {
        pcVar2 = (char *)acosNvramConfig_get(DAT_000391f0 + 0x38b78);
        lVar7 = strtol(pcVar2,(char **)0x0,10);
        if (lVar3 == lVar7) goto LAB_000385d4;
      }
      FUN_00034bfc(*puVar10);
      goto LAB_000385d4;
    }
    iVar4 = strcmp(__s1,(char *)(DAT_0003916c + 0x3868c));
    if (iVar4 == 0) {
      snprintf(pcVar2,0x400,*(char **)(iVar14 + DAT_000391ac),__s1);
      pcVar9 = *(char **)(iVar14 + DAT_000391b0);
      strncpy(pcVar9,(char *)(DAT_000391f4 + 0x38bc8),0x3ff);
      strcat(pcVar2,pcVar9);
      snprintf(pcVar9,0x400,(char *)(DAT_000391f8 + 0x38bf0),1);
LAB_00038ad8:
      strcat(pcVar2,pcVar9);
      snprintf(pcVar9,0x400,*(char **)(iVar14 + DAT_000391bc),__s1);
      strcat(pcVar2,pcVar9);
      goto LAB_0003893c;
    }
    iVar5 = strcmp(__s1,(char *)(DAT_00039170 + 0x386a4));
    iVar4 = DAT_00039200;
    if (iVar5 == 0) {
      FUN_0001aa78(DAT_000391fc + 0x38c0c,param_3);
      iVar4 = iVar4 + 0x38c14;
      iVar16 = acosNvramConfig_match(iVar4,DAT_00039204 + 0x38c20);
      if (iVar16 == 0) {
        iVar16 = acosNvramConfig_match(iVar4,DAT_00039214 + 0x38cc8);
        if (iVar16 == 0) {
          iVar16 = acosNvramConfig_match(iVar4,DAT_00039220 + 0x38d74);
          if (iVar16 == 0) {
            iVar16 = acosNvramConfig_match(iVar4,DAT_0003922c + 0x38e74);
            if (iVar16 == 0) {
              iVar16 = acosNvramConfig_match(iVar4,DAT_0003925c + 0x39038);
              if (iVar16 == 0) goto LAB_0003883c;
              iVar16 = FUN_000370ec();
              if (iVar16 != 3) {
                iVar16 = FUN_000370ec();
                if ((iVar16 == 1) || (iVar16 = FUN_000370ec(), iVar16 == 2)) goto LAB_00038ce8;
                snprintf((char *)&iStack_20424,0x400,(char *)(DAT_00039260 + 0x3907c),10);
                system((char *)&iStack_20424);
              }
              iVar16 = 0x32;
              do {
                iVar4 = FUN_000370ec();
                if (iVar4 != 6) break;
                sleep(1);
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
            }
            else {
              iVar16 = FUN_000370ec();
              if (iVar16 != 3) {
                iVar16 = FUN_000370ec();
                if ((iVar16 == 1) || (iVar16 = FUN_000370ec(), iVar16 == 2)) goto LAB_00038ce8;
                FUN_00037020();
              }
              iVar16 = 0x32;
              do {
                iVar4 = FUN_000370ec();
                if (iVar4 != 6) break;
                sleep(1);
                iVar16 = iVar16 + -1;
              } while (iVar16 != 0);
            }
          }
          else {
            iVar16 = FUN_000370ec();
            if (iVar16 != 3) {
              iVar16 = FUN_000370ec();
              if ((iVar16 == 1) || (iVar16 = FUN_000370ec(), iVar16 == 2)) goto LAB_00038ce8;
              FUN_00037020();
            }
            iVar16 = 0x32;
            do {
              iVar4 = FUN_000370ec();
              if (iVar4 != 6) break;
              sleep(1);
              iVar16 = iVar16 + -1;
            } while (iVar16 != 0);
          }
        }
        else {
          iVar16 = FUN_000370ec();
          if (iVar16 != 3) {
            iVar16 = FUN_000370ec();
            if ((iVar16 == 1) || (iVar16 = FUN_000370ec(), iVar16 == 2)) {
LAB_00038ce8:
              iVar16 = 0x2c1;
              goto LAB_00038588;
            }
            FUN_00036efc();
          }
          iVar16 = 0x32;
          do {
            iVar4 = FUN_000370ec();
            if (iVar4 != 6) break;
            sleep(1);
            iVar16 = iVar16 + -1;
          } while (iVar16 != 0);
        }
      }
      else {
        iVar16 = FUN_000370ec();
        if ((iVar16 == 6) &&
           (iStack_20424 = iVar5, iStack_20420 = iVar5,
           pFVar8 = fopen64((char *)(DAT_00039258 + 0x38fe4),(char *)(DAT_00039254 + 0x38fdc)),
           pFVar8 != (FILE *)0x0)) {
          fread(&iStack_20424,1,8,pFVar8);
          if ((char)iStack_20424 != '\0') {
            lVar7 = strtol((char *)&iStack_20424,(char **)0x0,10);
            kill(lVar7,10);
          }
          fclose(pFVar8);
        }
        iVar16 = 0x32;
        do {
          iVar4 = FUN_000370ec();
          if (iVar4 != 6) break;
          sleep(1);
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
      }
      iVar16 = FUN_000370ec();
      if (iVar16 != 6) goto LAB_0003883c;
      iVar16 = 0x2c0;
      goto LAB_00038588;
    }
    iVar4 = strcmp(__s1,(char *)(DAT_00039174 + 0x386c0));
    if (iVar4 == 0) {
      iVar5 = DAT_0003920c + 0x38c88;
      FUN_0001aa78(DAT_00039208 + 0x38c80,param_3);
      iVar16 = acosNvramConfig_match(iVar5,DAT_00039210 + 0x38c98);
      if (iVar16 == 0) {
        iVar16 = acosNvramConfig_match(iVar5,DAT_00039218 + 0x38d28);
        if (iVar16 == 0) {
          iVar4 = DAT_00039228 + 0x38dfc;
          iVar16 = acosNvramConfig_match(iVar5,iVar4);
          if (iVar16 == 0) {
            iVar16 = acosNvramConfig_match(iVar5,iVar4);
            if (iVar16 == 0) {
              iVar16 = acosNvramConfig_match(DAT_00039268 + 0x390c4,DAT_00039264 + 0x390c0);
              if (iVar16 != 0) {
                iVar16 = FUN_000370ec();
                if (iVar16 == 6) goto LAB_00038cb0;
                system((char *)(DAT_0003926c + 0x390e4));
                acosNvramConfig_set(DAT_00039274 + 0x390f8,DAT_00039270 + 0x390f4);
              }
            }
            else {
              iVar16 = FUN_000370ec();
              if (iVar16 == 6) goto LAB_00038cb0;
              FUN_00036d3c();
            }
          }
          else {
            iVar16 = FUN_000370ec();
            if (iVar16 == 6) goto LAB_00038cb0;
            FUN_00036d3c();
          }
        }
        else {
          iVar16 = FUN_000370ec();
          if (iVar16 == 6) goto LAB_00038cb0;
          FUN_00036e1c();
        }
      }
      else {
        iVar16 = FUN_000370ec();
        if (iVar16 == 6) {
LAB_00038cb0:
          iVar16 = 0x2c7;
          goto LAB_00038588;
        }
        iStack_20424 = iVar4;
        iStack_20420 = iVar4;
        pFVar8 = fopen64((char *)(DAT_00039234 + 0x38ee4),(char *)(DAT_00039230 + 0x38edc));
        if (pFVar8 != (FILE *)0x0) {
          fread(&iStack_20424,1,8,pFVar8);
          if ((char)iStack_20424 != '\0') {
            lVar7 = strtol((char *)&iStack_20424,(char **)0x0,10);
            kill(lVar7,0xc);
          }
          fclose(pFVar8);
        }
        iVar16 = DAT_00039238 + 0x38f30;
        acosNvramConfig_set(DAT_0003923c + 0x38f34,iVar16);
        acosNvramConfig_set(DAT_00039240 + 0x38f48,iVar16);
        acosNvramConfig_set(DAT_00039244 + 0x38f58,iVar16);
        acosNvramConfig_set(DAT_00039248 + 0x38f68,iVar16);
        acosNvramConfig_set(DAT_0003924c + 0x38f78,iVar16);
      }
LAB_0003883c:
      snprintf(pcVar2,0x400,*(char **)(iVar14 + DAT_000391a4),__s1);
      goto LAB_0003893c;
    }
    iVar4 = strcmp(__s1,(char *)(DAT_00039178 + 0x386d8));
    if (iVar4 == 0) {
      iStack_20424 = iVar4;
      memset(&iStack_20420,0,0x3fc);
      uVar6 = FUN_000370ec();
      switch(uVar6) {
      case 0:
        strncpy((char *)&iStack_20424,(char *)(DAT_000391ec + 0x38b68),0x3ff);
        break;
      case 1:
        strncpy((char *)&iStack_20424,(char *)(DAT_000391e8 + 0x38b54),0x3ff);
        break;
      case 2:
        strncpy((char *)&iStack_20424,(char *)(DAT_000391e4 + 0x38b40),0x3ff);
        break;
      case 3:
        strncpy((char *)&iStack_20424,(char *)(DAT_000391e0 + 0x38b2c),0x3ff);
        break;
      case 4:
        strncpy((char *)&iStack_20424,(char *)(DAT_000391dc + 0x38b18),0x3ff);
        break;
      case 5:
        strncpy((char *)&iStack_20424,(char *)(DAT_000391cc + 0x38a3c),0x3ff);
        break;
      default:
        strncpy((char *)&iStack_20424,(char *)(DAT_00039250 + 0x38fc4),0x3ff);
      }
      snprintf(pcVar2,0x400,*(char **)(iVar14 + DAT_000391ac),__s1);
      pcVar9 = *(char **)(iVar14 + DAT_000391b0);
      snprintf(pcVar9,0x400,(char *)(DAT_000391d0 + 0x38a70),&iStack_20424);
      sVar1 = strlen(pcVar2);
      pcVar11 = stpcpy(pcVar2 + sVar1,pcVar9);
      strncpy(pcVar9,(char *)(DAT_000391d4 + 0x38aa0),0x3ff);
      strcpy(pcVar11,pcVar9);
      uVar6 = sys_uptime();
      snprintf(pcVar9,0x400,(char *)(DAT_000391d8 + 0x38ac8),uVar6);
      goto LAB_00038ad8;
    }
    iVar4 = strcmp(__s1,(char *)(DAT_0003917c + 0x386f0));
    if (iVar4 == 0) {
      iVar16 = FUN_00038308();
    }
    else {
      iVar4 = strcmp(__s1,(char *)(DAT_00039180 + 0x38708));
      if (iVar4 == 0) {
        FUN_0001aa78(DAT_0003921c + 0x38d54,param_3);
        iVar16 = FUN_000376a4(iVar16);
      }
      else {
        iVar4 = strcmp(__s1,(char *)(DAT_00039184 + 0x38720));
        if (iVar4 == 0) {
          FUN_0001aa78(DAT_00039224 + 0x38ddc,param_3);
          iVar16 = FUN_00037db0(iVar16);
        }
        else {
          iVar4 = strcmp(__s1,(char *)(DAT_00039188 + 0x38738));
          if (iVar4 == 0) {
            iVar16 = FUN_00036328(iVar16);
          }
          else {
            iVar4 = strcmp(__s1,(char *)(DAT_0003918c + 0x38750));
            if (iVar4 != 0) {
              iVar4 = strcmp(__s1,(char *)(DAT_00039190 + 0x38768));
              if (iVar4 == 0) {
                FUN_0001aa78(DAT_00039194 + 0x38788,param_3);
                if (9 < iVar16 - 1U) goto LAB_00038584;
                pcVar13 = *(char **)(iVar14 + DAT_00039198);
                pcVar11 = (char *)(DAT_0003919c + 0x387b0);
                iVar4 = 0;
                pcVar9 = pcVar13;
                do {
                  iVar5 = strcmp(pcVar9,pcVar11);
                  if (iVar5 == 0) {
                    iVar16 = iVar4 * 0x804 + 0x400;
                    if (pcVar13[iVar16] == '\0') goto LAB_0003893c;
                    iVar16 = strcmp(pcVar13 + iVar16,(char *)(DAT_000391a0 + 0x38830));
                    if (iVar16 == 0) goto LAB_0003883c;
                    iVar16 = 0x2bf;
                    goto LAB_00038588;
                  }
                  iVar4 = iVar4 + 1;
                  pcVar9 = pcVar9 + 0x804;
                } while (iVar16 != iVar4);
                iVar16 = 0x192;
              }
              else {
                iVar16 = 0x191;
              }
              goto LAB_00038588;
            }
            iVar16 = FUN_000367cc(iVar16);
          }
        }
      }
    }
    memset(acStack_20024,0,0x20000);
    if (iVar16 == 0) goto LAB_00038950;
  }
  FUN_000359f8(iVar16,acStack_20024);
  sVar1 = strlen(acStack_20024);
  FUN_0001a768(param_2,acStack_20024,sVar1,1);
LAB_000385d4:
  if (iVar12 == *piVar15) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(0);
}


===== FUNCTION FUN_0003af54 @ 0003af54 =====

void FUN_0003af54(char *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  size_t __n;
  ssize_t sVar3;
  undefined4 uVar4;
  int *piVar5;
  bool bVar6;
  char local_424 [1024];
  int local_24;
  
  piVar5 = *(int **)(DAT_0003b1bc + 0x3af64 + DAT_0003b1c0);
  local_24 = *piVar5;
  local_424[0] = '\0';
  local_424[1] = '\0';
  local_424[2] = '\0';
  local_424[3] = '\0';
  memset(local_424 + 4,0,0x3fc);
  iVar1 = acosNvramConfig_match(DAT_0003b1c8 + 0x3afbc,DAT_0003b1c4 + 0x3afb8);
  bVar6 = iVar1 != 0;
  if (param_1 != (char *)0x0) {
    pcVar2 = strcasestr(param_1,(char *)(DAT_0003b1cc + 0x3afdc));
    if ((pcVar2 != (char *)0x0 && bVar6) && (iVar1 = FUN_0003aec4(param_2), iVar1 != 0)) {
      uVar4 = FUN_00039584(param_2,param_3,param_4);
      goto LAB_0003b0d0;
    }
    pcVar2 = strcasestr(param_1,(char *)(DAT_0003b1d0 + 0x3b000));
    if ((pcVar2 != (char *)0x0 && bVar6) && (iVar1 = FUN_0003aec4(param_2), iVar1 != 0)) {
      uVar4 = FUN_00039278(param_2,param_3,param_4);
      goto LAB_0003b0d0;
    }
    pcVar2 = strcasestr(param_1,(char *)(DAT_0003b1d4 + 0x3b024));
    if ((pcVar2 != (char *)0x0 && bVar6) && (iVar1 = FUN_0003aec4(param_2), iVar1 != 0)) {
      uVar4 = FUN_00038500(param_2,param_3,param_4);
      goto LAB_0003b0d0;
    }
    pcVar2 = strcasestr(param_1,(char *)(DAT_0003b1d8 + 0x3b048));
    if ((pcVar2 != (char *)0x0 && bVar6) && (iVar1 = FUN_0003aec4(param_2), iVar1 != 0)) {
      uVar4 = FUN_00039954(param_2,param_3,param_4);
      goto LAB_0003b0d0;
    }
    pcVar2 = strcasestr(param_1,(char *)(DAT_0003b1dc + 0x3b06c));
    if ((pcVar2 != (char *)0x0 && bVar6) && (iVar1 = FUN_0003aec4(param_2), iVar1 != 0)) {
      uVar4 = FUN_0003aac8(param_2,param_3,param_4);
      goto LAB_0003b0d0;
    }
    memset(local_424,0,0x400);
    FUN_00030c20(0x194,local_424,0);
    __n = strlen(local_424);
    sVar3 = send(param_3,local_424,__n,0);
    if (sVar3 == -1) {
      FUN_0001ab94(2,DAT_0003b1e0 + 0x3b1b0);
      uVar4 = 0xffffffff;
      goto LAB_0003b0d0;
    }
  }
  uVar4 = 0xffffffff;
LAB_0003b0d0:
  if (local_24 != *piVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}


===== TARGET SOAPAction: =====

===== FUNCTION FUN_000599dc @ 000599dc =====

void FUN_000599dc(char *param_1,int param_2,in_addr param_3,undefined4 param_4)

{
  byte bVar1;
  undefined2 uVar2;
  bool bVar3;
  char *pcVar4;
  size_t sVar5;
  char *pcVar6;
  FILE *pFVar7;
  char *pcVar8;
  size_t sVar9;
  in_addr_t iVar10;
  in_addr_t iVar11;
  in_addr_t iVar12;
  in_addr_t iVar13;
  in_addr_t iVar14;
  in_addr_t iVar15;
  void *pvVar16;
  FILE *__s;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  undefined4 uVar20;
  undefined4 *puVar21;
  char cVar22;
  int *piVar23;
  undefined4 uVar24;
  undefined1 *puVar25;
  char *__dest;
  undefined4 *puVar26;
  undefined4 *puVar27;
  undefined4 uVar28;
  long lVar29;
  char *pcVar30;
  int iVar31;
  int *piVar32;
  byte *pbVar33;
  int iVar34;
  int iVar35;
  uint uVar36;
  int iVar37;
  undefined4 *puVar38;
  int iVar39;
  undefined4 *puVar40;
  byte *pbVar41;
  undefined2 *puVar42;
  undefined4 local_448;
  char *local_444;
  word *local_434;
  uint local_430;
  char *local_42c;
  undefined4 *local_424;
  int local_41c;
  int local_418;
  int local_414;
  uint local_410;
  int local_40c;
  uint local_408;
  char *local_404;
  int local_400;
  undefined4 local_3fc;
  undefined4 uStack_3f8;
  undefined4 local_398;
  undefined4 local_394;
  undefined4 local_390;
  undefined4 local_38c;
  undefined4 local_388;
  undefined4 local_384;
  undefined4 local_380;
  undefined4 local_37c;
  undefined4 local_378;
  undefined4 local_374;
  undefined4 local_370;
  undefined4 local_36c;
  undefined4 local_368;
  undefined4 local_364;
  undefined4 local_360;
  undefined4 local_35c;
  char acStack_358 [52];
  char acStack_324 [127];
  byte bStack_2a5;
  undefined4 local_2a4;
  undefined1 auStack_2a0 [124];
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined3 uStack_218;
  int local_24;
  
  iVar39 = DAT_0005a8cc + 0x599fc;
  piVar23 = *(int **)(iVar39 + DAT_0005a8d0);
  iVar34 = 0;
  local_24 = *piVar23;
  FUN_0001ab94(2,DAT_0005a8d8 + 0x59a38,DAT_0005a8d4 + 0x5a79c);
  iVar31 = DAT_0005a8e0;
  **(undefined4 **)(iVar39 + DAT_0005a8dc) = 0;
  local_430 = 1;
  if (**(int **)(iVar39 + iVar31) != 1) {
    pcVar30 = *(char **)(iVar39 + DAT_0005a8e4);
    pcVar4 = strcasestr(param_1,pcVar30);
    if (pcVar4 == (char *)0x0) {
      local_448 = 0xffffffff;
      goto LAB_00059bd8;
    }
    sVar5 = strlen(pcVar30);
    pcVar30 = *(char **)(iVar39 + DAT_0005a8e8);
    puVar38 = *(undefined4 **)(iVar39 + DAT_0005a8ec);
    pcVar4 = pcVar4 + sVar5;
    do {
      *puVar38 = pcVar30;
      pcVar6 = strcasestr(pcVar4,pcVar30);
      if (pcVar6 != (char *)0x0) goto LAB_00059ac0;
      iVar34 = iVar34 + 1;
      pcVar30 = pcVar30 + 0x1e;
    } while (iVar34 != 0xb);
    iVar34 = -1;
LAB_00059ac0:
    iVar31 = DAT_0005a8f0 + 0x5a848;
    FUN_0001ab94(1,DAT_0005a8f4 + 0x59adc,iVar31);
    FUN_0001ab94(1,DAT_0005a8f8 + 0x59af8,pcVar4);
    FUN_0001ab94(1,DAT_0005a8fc + 0x59b0c,iVar31);
    local_390 = 0;
    local_398 = 0;
    local_394 = 0;
    local_38c = 0;
    local_388 = 0;
    local_384 = 0;
    local_380 = 0;
    local_37c = 0;
    pFVar7 = popen((char *)(DAT_0005a904 + 0x59b28),(char *)(DAT_0005a900 + 0x59b20));
    if (pFVar7 != (FILE *)0x0) {
      iVar31 = DAT_0005a908 + 0x59b64;
      while (pcVar30 = fgets(acStack_324,0x80,pFVar7), pcVar30 != (char *)0x0) {
        pcVar30 = inet_ntoa(param_3);
        pcVar30 = strstr(acStack_324,pcVar30);
        if (pcVar30 != (char *)0x0) {
          __isoc99_sscanf(acStack_324,iVar31,&local_398);
        }
      }
      pclose(pFVar7);
    }
    iVar31 = FUN_000501c0(&local_398,param_3.s_addr);
    if (iVar31 != 0) {
      local_430 = 0x1f7;
      goto LAB_00059bc0;
    }
    pcVar30 = strcasestr(param_1,(char *)(DAT_0005a910 + 0x59c24));
    pcVar6 = strcasestr(param_1,(char *)(DAT_0005a914 + 0x59c30));
    if ((((pcVar6 == (char *)0x0) || (pcVar6[-2] != '\r')) || (pcVar6[-1] != '\n')) ||
       (pcVar8 = strchr(pcVar6,0xd), iVar31 = DAT_0005a944, pcVar8 == (char *)0x0)) {
      bVar3 = true;
    }
    else {
      *pcVar8 = '\0';
      pcVar6 = strcasestr(pcVar6,(char *)(iVar31 + 0x59ed4));
      *pcVar8 = '\r';
      bVar3 = pcVar6 == (char *)0x0;
    }
    if (pcVar30 == (char *)0x0) {
      bVar3 = false;
    }
    if ((bVar3) && (pcVar6 = strchr(pcVar30,0xd), iVar31 = DAT_0005a918, pcVar6 != (char *)0x0)) {
      *pcVar6 = '\0';
      pcVar30 = strstr(pcVar30,(char *)(iVar31 + 0x59c90));
      if (pcVar30 == (char *)0x0) {
        *pcVar6 = '\r';
        goto LAB_00059d20;
      }
      pcVar30 = pcVar30 + 8;
      pcVar8 = strchr(pcVar30,0x3b);
      if (pcVar8 == (char *)0x0) {
        iVar31 = FUN_00050630(pcVar30,&local_398,param_3.s_addr);
      }
      else {
        *pcVar8 = '\0';
        iVar31 = FUN_00050630(pcVar30,&local_398,param_3.s_addr);
        *pcVar8 = ';';
      }
      if (iVar31 != 0) {
        *pcVar6 = '\r';
        goto LAB_00059cf0;
      }
    }
    else {
LAB_00059d20:
      pcVar6 = *(char **)(iVar39 + DAT_0005a920);
      strncpy(pcVar6,(char *)(DAT_0005a924 + 0x59d38),0x13);
      pcVar30 = inet_ntoa(param_3);
      strncpy(pcVar6,pcVar30,0x13);
      pcVar30 = inet_ntoa(param_3);
      pcVar6 = (char *)acosNvramConfig_get(DAT_0005a928 + 0x59d6c);
      iVar31 = strcmp(pcVar30,pcVar6);
      if (iVar31 == 0) {
LAB_00059cf0:
        iVar31 = strcmp((char *)*puVar38,(char *)(DAT_0005a91c + 0x59d00));
        if (iVar31 == 0) {
LAB_0005a290:
          FUN_0001ab94(3,DAT_0005a990 + 0x5a2a4,pcVar4);
          iVar31 = strncmp(pcVar4,(char *)(DAT_0005a994 + 0x5a2b8),0x3a);
          if ((iVar31 == 0) ||
             (iVar31 = strncmp(pcVar4,(char *)(DAT_0005a998 + 0x5a2d4),0x3c), iVar31 == 0)) {
            pcVar30 = strcasestr(pcVar4,(char *)(DAT_0005a99c + 0x5a2ec));
            if ((pcVar30 != (char *)0x0) &&
               (pcVar30 = strcasestr(pcVar30,(char *)(DAT_0005a9a0 + 0x5a300)),
               pcVar30 != (char *)0x0)) {
              pcVar30 = pcVar30 + 1;
              pcVar6 = strcasestr(pcVar4,(char *)(DAT_0005a9a4 + 0x5a31c));
              if (pcVar6 != (char *)0x0) {
                if ((pcVar6 < pcVar30) || (sVar5 = (int)pcVar6 - (int)pcVar30, 0x40 < (int)sVar5))
                goto LAB_0005a338;
                pcVar6 = *(char **)(iVar39 + DAT_0005a9a8);
                strncpy(pcVar6,(char *)(DAT_0005a9ac + 0x5a358),0x5f);
                strncpy(pcVar6,pcVar30,sVar5);
                pcVar6[sVar5] = '\0';
              }
            }
            pcVar30 = strcasestr(pcVar4,(char *)(DAT_0005a9b0 + 0x5a38c));
            if ((pcVar30 != (char *)0x0) &&
               (pcVar30 = strcasestr(pcVar30,(char *)(DAT_0005a9b4 + 0x5a3a0)),
               pcVar30 != (char *)0x0)) {
              pcVar30 = pcVar30 + 1;
              pcVar4 = strcasestr(pcVar4,(char *)(DAT_0005a9b8 + 0x5a3bc));
              if (pcVar4 != (char *)0x0) {
                if ((pcVar4 < pcVar30) || (sVar5 = (int)pcVar4 - (int)pcVar30, 0x40 < (int)sVar5))
                goto LAB_0005a338;
                pcVar4 = *(char **)(iVar39 + DAT_0005a9bc);
                strncpy(pcVar4,(char *)(DAT_0005a9c0 + 0x5a3f0),0x5f);
                strncpy(pcVar4,pcVar30,sVar5);
                pcVar4[sVar5] = '\0';
              }
            }
          }
          else {
            pcVar30 = strcasestr(pcVar4,(char *)(DAT_0005a9c4 + 0x5a434));
            if (pcVar30 != (char *)0x0) {
              if (pcVar30[0xb] == '<') {
                iVar31 = (int)pcVar30[10];
                puVar25 = *(undefined1 **)(iVar39 + DAT_0005a9c8);
              }
              else {
                iVar31 = 0x58;
                puVar25 = *(undefined1 **)(iVar39 + DAT_0005a9c8);
              }
              *puVar25 = (char)iVar31;
              FUN_0001ab94(3,DAT_0005a9cc + 0x5a474,iVar31);
            }
            pcVar30 = strcasestr(pcVar4,(char *)(DAT_0005a9d0 + 0x5a484));
            if (pcVar30 != (char *)0x0) {
              pcVar6 = strcasestr(pcVar4,(char *)(DAT_0005a9d4 + 0x5a49c));
              pcVar8 = (char *)(DAT_0005a9dc + 0x5a4b0);
              __dest = *(char **)(iVar39 + DAT_0005a9d8);
              if (pcVar6 == (char *)0x0) {
                pcVar30 = pcVar30 + 0xe;
              }
              else {
                pcVar30 = pcVar30 + 0x24;
              }
              strncpy(__dest,pcVar8,0x1f);
              pcVar6 = strcasestr(pcVar4,(char *)(DAT_0005a9e0 + 0x5a4dc));
              if (pcVar6 == (char *)0x0) goto LAB_0005a538;
              if ((pcVar30 <= pcVar6) && (uVar36 = (int)pcVar6 - (int)pcVar30, uVar36 < 0x20)) {
                strncpy(__dest,pcVar8,0x1f);
                strncpy(__dest,pcVar30,uVar36);
                iVar31 = DAT_0005a9e4 + 0x5a530;
                __dest[uVar36] = '\0';
                FUN_0001ab94(3,iVar31,__dest);
                goto LAB_0005a538;
              }
LAB_0005a338:
              local_430 = 0x25d;
              goto LAB_00059bc0;
            }
LAB_0005a538:
            pcVar30 = strcasestr(pcVar4,(char *)(DAT_0005a9e8 + 0x5a548));
            if (pcVar30 != (char *)0x0) {
              pcVar6 = strcasestr(pcVar4,(char *)(DAT_0005a9ec + 0x5a560));
              if (pcVar6 == (char *)0x0) {
                pcVar30 = pcVar30 + 0xc;
              }
              else {
                pcVar30 = pcVar30 + 0x22;
              }
              pcVar4 = strcasestr(pcVar4,(char *)(DAT_0005a9f0 + 0x5a56c));
              if (pcVar4 != (char *)0x0) {
                if ((pcVar4 < pcVar30) || (sVar5 = (int)pcVar4 - (int)pcVar30, 0x20 < (int)sVar5))
                goto LAB_0005a338;
                pcVar4 = *(char **)(iVar39 + DAT_0005a9f4);
                strncpy(pcVar4,(char *)(DAT_0005a9f8 + 0x5a5b0),0x3f);
                strncpy(pcVar4,pcVar30,sVar5);
                iVar31 = DAT_0005a9fc + 0x5a5d8;
                pcVar4[sVar5] = '\0';
                FUN_0001ab94(3,iVar31,pcVar4);
              }
            }
          }
        }
        if (iVar34 == -1) goto LAB_00059d10;
        pcVar30 = (char *)*puVar38;
      }
      else {
        iVar31 = strncmp(pcVar4,(char *)(DAT_0005a92c + 0x59d94),0x3a);
        if ((((iVar31 != 0) &&
             (iVar31 = strncmp(pcVar4,(char *)(DAT_0005a948 + 0x59f00),0x3c), iVar31 != 0)) ||
            (iVar34 != 7)) &&
           (((iVar31 = strncmp(pcVar4,(char *)(DAT_0005a930 + 0x59db8),0x34), iVar31 != 0 &&
             (iVar31 = strncmp(pcVar4,(char *)(DAT_0005a934 + 0x59dd4),0x36), iVar31 != 0)) ||
            (iVar34 != 1)))) {
          iVar31 = strncmp(pcVar4,(char *)(DAT_0005a938 + 0x59df8),0x30);
          if (iVar31 != 0) {
            memset(&local_2a4,0,0x20);
            memset(&local_224,0,0x80);
            pFVar7 = fopen64((char *)(DAT_0005a940 + 0x59e44),(char *)(DAT_0005a93c + 0x59e40));
            if (pFVar7 == (FILE *)0x0) goto LAB_00059d10;
            FUN_0003ea90(&local_2a4);
            do {
              pcVar30 = fgets((char *)&local_224,0x80,pFVar7);
              if (pcVar30 == (char *)0x0) {
                fclose(pFVar7);
                goto LAB_00059d10;
              }
              pcVar30 = strstr((char *)&local_224,(char *)&local_2a4);
            } while (pcVar30 == (char *)0x0);
            fclose(pFVar7);
          }
          goto LAB_00059cf0;
        }
        pcVar30 = (char *)*puVar38;
        iVar31 = strcmp(pcVar30,(char *)(DAT_0005a98c + 0x5a288));
        if (iVar31 == 0) goto LAB_0005a290;
      }
      iVar31 = DAT_0005a950;
      iVar19 = DAT_0005a94c + 0x59f24;
      FUN_0001ab94(3,iVar19,DAT_0005a950 + 0x5acb0);
      pcVar6 = *(char **)(iVar39 + DAT_0005a954);
      memset(pcVar6,0,100);
      pcVar4 = strcasestr(param_1,(char *)(DAT_0005a958 + 0x59f68));
      if (((pcVar4 != (char *)0x0) &&
          (pcVar4 = strcasestr(pcVar4 + 4,(char *)(DAT_0005a95c + 0x59f80)), pcVar4 != (char *)0x0))
         && (pcVar8 = strcasestr(param_1,pcVar30), pcVar8 != (char *)0x0)) {
        sVar5 = strlen(pcVar30);
        sVar9 = strlen(pcVar6);
        iVar18 = DAT_0005a960;
        uVar17 = *(undefined4 *)(DAT_0005a960 + 0x59fd0);
        uVar20 = *(undefined4 *)(DAT_0005a960 + 0x59fd4);
        uVar24 = *(undefined4 *)(DAT_0005a960 + 0x59fd8);
        puVar42 = (undefined2 *)(DAT_0005a960 + 0x59fdc);
        *(undefined4 *)(pcVar6 + sVar9) = *(undefined4 *)(DAT_0005a960 + 0x59fcc);
        uVar2 = *puVar42;
        cVar22 = *(char *)(iVar18 + 0x59fde);
        *(undefined4 *)(pcVar6 + sVar9 + 4) = uVar17;
        *(undefined4 *)(pcVar6 + sVar9 + 8) = uVar20;
        *(undefined4 *)(pcVar6 + sVar9 + 0xc) = uVar24;
        pcVar6[sVar9 + 0x12] = cVar22;
        *(undefined2 *)(pcVar6 + sVar9 + 0x10) = uVar2;
        memcpy(pcVar6 + sVar9 + 0x12,pcVar4,(size_t)(pcVar8 + (sVar5 - (int)pcVar4)));
        sVar5 = strlen(pcVar6);
        iVar18 = DAT_0005a968 + 0x5a034;
        cVar22 = *(char *)(DAT_0005a964 + 0x5a032);
        *(undefined2 *)(pcVar6 + sVar5) = *(undefined2 *)(DAT_0005a964 + 0x5a030);
        pcVar6[sVar5 + 2] = cVar22;
        FUN_0001ab94(3,iVar18,pcVar6);
        local_41c = -1;
        local_418 = -1;
        local_40c = -1;
        local_414 = 0;
        local_410 = 0;
        FUN_0001ab94(2,DAT_0005a96c + 0x5a070,iVar31 + 0x5acc8,iVar34);
        local_430 = FUN_0004d600(iVar34,param_1,&local_414,&local_410,&local_41c,&local_418,
                                 &local_40c);
        if (local_430 != 0) goto LAB_0005a770;
        if (local_410 == 0) {
          if (local_414 == 1) {
            FUN_0001ab94(3,iVar19,iVar31 + 0x5acdc);
            pcVar4 = strstr(param_1,(char *)(DAT_0005aa48 + 0x5a884));
            if (pcVar4 != (char *)0x0) {
              pcVar30 = strchr(pcVar4 + 9,0x3e);
              pcVar4 = strstr(pcVar4 + 9,(char *)(DAT_0005aa4c + 0x5a8a8));
              if (pcVar4 != (char *)0x0 && pcVar30 != (char *)0x0) {
                pcVar30 = pcVar30 + 1;
                if (pcVar4 < pcVar30) {
                  uVar36 = (int)pcVar30 - (int)pcVar4;
                }
                else {
                  uVar36 = (int)pcVar4 - (int)pcVar30;
                }
                if (uVar36 < 0x28) {
                  memset(&local_224,0,0x28);
                  memcpy(&local_224,pcVar30,uVar36);
                  iVar31 = strncmp((char *)&local_224,*(char **)(iVar39 + DAT_0005aaf0),uVar36);
                  if (iVar31 == 0) {
                    local_430 = 0;
                    goto LAB_0005a0d4;
                  }
                }
              }
            }
            local_430 = 0x191;
          }
          else {
            local_430 = local_410;
          }
        }
LAB_0005a0d4:
        iVar31 = DAT_0005a970;
        iVar18 = local_418;
        iVar37 = local_41c;
        FUN_0001ab94(2,DAT_0005a974 + 0x5a100,DAT_0005a970 + 0x5ae8c,local_414,local_418,local_41c);
        iVar19 = DAT_0005cb30;
        if (local_418 == 0x2d) {
          FUN_0001ab94(3,DAT_0005aa50 + 0x5ac3c);
          memset(acStack_358,0,0x32);
          local_2a4 = 0;
          memset(auStack_2a0,0,0x60);
          acosNvramConfig_set(DAT_0005aa58 + 0x5ac7c,DAT_0005aa54 + 0x5ac78);
          get_eth_link_status(1,&local_2a4);
          pcVar4 = strcasestr((char *)&local_2a4,(char *)(DAT_0005aa5c + 0x5ac98));
          iVar31 = DAT_0005ab90;
          if (pcVar4 == (char *)0x0) {
            if (*(int *)(DAT_0005ab40 + 0x5b868) == 0) {
              iVar19 = DAT_0005ab8c + 0x5b7f4;
              *(undefined4 *)(DAT_0005ab40 + 0x5b868) = 1;
              acosNvramConfig_set(iVar31 + 0x5b7fc,iVar19);
              acosNvramConfig_set(DAT_0005ab94 + 0x5b810,iVar19);
              acosNvramConfig_set(DAT_0005ab98 + 0x5b820,iVar19);
              acosNvramConfig_set(DAT_0005ab9c + 0x5b830,iVar19);
              acosNvramConfig_set(DAT_0005aba0 + 0x5b840,iVar19);
              iVar31 = acosNvramConfig_match(DAT_0005aba8 + 0x5b854,DAT_0005aba4 + 0x5b850);
              if (iVar31 != 0) {
                agApi_natDisable();
                agApi_natUnhook(0);
              }
              iVar31 = DAT_0005abb0 + 0x5b88c;
              local_400 = *(int *)(DAT_0005abac + 0x5a89c);
              local_3fc = *(undefined4 *)(DAT_0005abac + 0x5a8a0);
              uStack_3f8 = *(undefined4 *)(DAT_0005abac + 0x5a8a4);
              _eval_daemon(&local_400,iVar31,0,0,0);
              iVar18 = 0;
              local_400 = DAT_0005abb4 + 0x5b8c8;
              local_3fc = 0;
              _eval_daemon(&local_400,iVar31,0,0,0);
              agApi_natUnhook(0);
            }
            pFVar7 = fopen64((char *)(DAT_0005ab48 + 0x5b5d0),(char *)(DAT_0005ab44 + 0x5b5cc));
            if (pFVar7 == (FILE *)0x0) goto LAB_0005aca0;
            fgets((char *)&local_224,0x200,pFVar7);
            FUN_0001ab94(3,DAT_0005ab4c + 0x5b608,&local_224);
            fclose(pFVar7);
            pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005ab50 + 0x5b620));
            if (pcVar4 == (char *)0x0) {
              pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005ab84 + 0x5b7c4));
              if (pcVar4 == (char *)0x0) {
                pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005abb8 + 0x5b8ec));
                if (pcVar4 == (char *)0x0) {
                  pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005abe0 + 0x5b9dc));
                  if (pcVar4 == (char *)0x0) {
                    pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005ac18 + 0x5bb98));
                    if (pcVar4 != (char *)0x0) {
                      *(undefined4 *)(DAT_0005ac1c + 0x5be64) = 1;
                    }
                  }
                  else {
                    *(undefined4 *)(DAT_0005abe4 + 0x5bcac) = 5;
                  }
                }
                else {
                  iVar19 = DAT_0005abc0 + 0x5b910;
                  iVar31 = DAT_0005abc4 + 0x5b914;
                  *(undefined4 *)(DAT_0005abbc + 0x5bbc4) = 4;
                  acosNvramConfig_set(iVar31,iVar19);
                }
              }
              else {
                *(undefined4 *)(DAT_0005ab88 + 0x5ba94) = 2;
              }
            }
            else {
              *(undefined4 *)(DAT_0005ab54 + 0x5b8f0) = 3;
            }
            pcVar30 = (char *)(DAT_0005ab58 + 0x5b648);
            pcVar4 = strcasestr((char *)&local_224,pcVar30);
            if (pcVar4 == (char *)0x0) {
              if (*(int *)(DAT_0005ab78 + 0x5ba4c) == 2) {
                acosNvramConfig_set(DAT_0005ab80 + 0x5b7b0,DAT_0005ab7c + 0x5b7ac);
              }
            }
            else {
              local_404 = (char *)0x0;
              strtok_r((char *)&local_224,pcVar30,&local_404);
              pcVar4 = strtok_r((char *)0x0,pcVar30,&local_404);
              acosNvramConfig_set(DAT_0005ab60 + 0x5b6a0,DAT_0005ab5c + 0x5b694);
              acosNvramConfig_set(DAT_0005ab64 + 0x5b6b0,pcVar4);
            }
            acosNvramConfig_save();
            iVar31 = DAT_0005ab68;
            iVar19 = *(int *)(DAT_0005ab68 + 0x5b97c);
            *(undefined4 *)(DAT_0005ab68 + 0x5b978) = 0;
            *(int *)(iVar31 + 0x5b980) = iVar19;
            if (iVar19 == 0) goto LAB_0005acb0;
          }
          else {
LAB_0005aca0:
            *(undefined4 *)(DAT_0005aa60 + 0x5af6c) = 0;
LAB_0005acb0:
            acosNvramConfig_set(DAT_0005aa68 + 0x5acc4,DAT_0005aa64 + 0x5acc0);
          }
          pcVar30 = *(char **)(iVar39 + DAT_0005aa6c);
          memset(pcVar30,0,0x800);
          strncpy(pcVar30,*(char **)(iVar39 + DAT_0005aa70),0x7ff);
          sVar5 = strlen(pcVar30);
          pcVar4 = stpcpy(pcVar30 + sVar5,*(char **)(iVar39 + DAT_0005aa74));
          uVar17 = *(undefined4 *)(DAT_0005aa78 + 0x5ad18);
          iVar31 = DAT_0005aa78 + 0x5ad1c;
          *(undefined4 *)pcVar4 = *(undefined4 *)(DAT_0005aa78 + 0x5ad14);
          *(undefined4 *)(pcVar4 + 4) = uVar17;
          pcVar4 = (char *)FUN_00040758(local_418,uVar17,pcVar4,iVar31);
          iVar31 = DAT_0005aa7c;
          if (pcVar4 == (char *)0x0) {
LAB_0005b5a0:
            local_430 = 0x192;
            goto LAB_00059bc0;
          }
          puVar21 = (undefined4 *)(DAT_0005aa7c + 0x5ad48);
          strncpy(acStack_358,pcVar4,0x31);
          sVar5 = strlen(pcVar30);
          local_42c = stpcpy(pcVar30 + sVar5,acStack_358);
          pcVar4 = local_42c;
          do {
            pcVar6 = pcVar4;
            puVar40 = puVar21;
            uVar17 = puVar40[1];
            uVar20 = puVar40[2];
            uVar24 = puVar40[3];
            *(undefined4 *)pcVar6 = *puVar40;
            *(undefined4 *)(pcVar6 + 4) = uVar17;
            *(undefined4 *)(pcVar6 + 8) = uVar20;
            *(undefined4 *)(pcVar6 + 0xc) = uVar24;
            iVar19 = DAT_0005aa80;
            puVar21 = puVar40 + 4;
            pcVar4 = pcVar6 + 0x10;
          } while (puVar40 + 4 != (undefined4 *)(iVar31 + 0x5ad78));
          uVar2 = *(undefined2 *)(puVar40 + 5);
          *(undefined4 *)(pcVar6 + 0x10) = puVar40[4];
          *(undefined2 *)(pcVar6 + 0x14) = uVar2;
          iVar31 = *(int *)(iVar19 + 0x5b06c);
          if (iVar31 == 0) {
            pcVar4 = pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30));
            uVar20 = *(undefined4 *)(DAT_0005ac00 + 0x5bae0);
            uVar17 = *(undefined4 *)(DAT_0005ac00 + 0x5bae4);
            uVar24 = *(undefined4 *)(DAT_0005ac00 + 0x5bae8);
            puVar21 = (undefined4 *)(DAT_0005ac00 + 0x5baec);
            *(undefined4 *)(pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30))) =
                 *(undefined4 *)(DAT_0005ac00 + 0x5badc);
            pcVar8 = local_42c + (0x4c - (int)pcVar30);
            pcVar6 = pcVar30 + (int)pcVar8;
            *(undefined4 *)(pcVar4 + 8) = uVar17;
            iVar19 = DAT_0005ac08;
            iVar31 = DAT_0005ac04;
            uVar17 = *puVar21;
            *(undefined4 *)(pcVar4 + 4) = uVar20;
            puVar40 = (undefined4 *)(iVar31 + 0x5bb18);
            *(undefined4 *)(pcVar4 + 0x10) = uVar17;
            puVar21 = (undefined4 *)(iVar19 + 0x5bb20);
LAB_0005ae48:
            local_42c = local_42c + (0x48 - (int)pcVar30);
            *(undefined4 *)(pcVar4 + 0xc) = uVar24;
            *(undefined4 *)(pcVar30 + (int)local_42c) = *puVar21;
            uVar20 = puVar40[1];
            uVar24 = puVar40[2];
            uVar28 = puVar40[3];
            *(undefined4 *)(pcVar30 + (int)pcVar8) = *puVar40;
            uVar2 = *(undefined2 *)(puVar40 + 5);
            uVar17 = puVar40[4];
            cVar22 = *(char *)((int)puVar40 + 0x16);
            *(undefined4 *)(pcVar6 + 4) = uVar20;
            *(undefined4 *)(pcVar6 + 8) = uVar24;
            *(undefined4 *)(pcVar6 + 0xc) = uVar28;
            *(undefined4 *)(pcVar6 + 0x10) = uVar17;
            *(undefined2 *)(pcVar6 + 0x14) = uVar2;
            pcVar6[0x16] = cVar22;
          }
          else {
            if (iVar31 == 2) {
              pcVar4 = pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30));
              uVar20 = *(undefined4 *)(DAT_0005abf4 + 0x5ba88);
              uVar17 = *(undefined4 *)(DAT_0005abf4 + 0x5ba8c);
              uVar24 = *(undefined4 *)(DAT_0005abf4 + 0x5ba90);
              puVar21 = (undefined4 *)(DAT_0005abf4 + 0x5ba94);
              *(undefined4 *)(pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30))) =
                   *(undefined4 *)(DAT_0005abf4 + 0x5ba84);
              pcVar8 = local_42c + (0x4c - (int)pcVar30);
              pcVar6 = pcVar30 + (int)pcVar8;
              *(undefined4 *)(pcVar4 + 8) = uVar17;
              iVar19 = DAT_0005abfc;
              iVar31 = DAT_0005abf8;
              uVar17 = *puVar21;
              *(undefined4 *)(pcVar4 + 4) = uVar20;
              puVar40 = (undefined4 *)(iVar31 + 0x5bac0);
              *(undefined4 *)(pcVar4 + 0x10) = uVar17;
              puVar21 = (undefined4 *)(iVar19 + 0x5bac8);
              goto LAB_0005ae48;
            }
            if (iVar31 == 1) {
              iVar31 = 0x50 - (int)pcVar30;
              local_424 = (undefined4 *)(DAT_0005ac10 + 0x5bb40);
              pcVar4 = pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30));
              uVar20 = *(undefined4 *)(DAT_0005ac0c + 0x5bb3c);
              uVar24 = *(undefined4 *)(DAT_0005ac0c + 0x5bb40);
              uVar28 = *(undefined4 *)(DAT_0005ac0c + 0x5bb44);
              puVar21 = (undefined4 *)(DAT_0005ac0c + 0x5bb48);
              *(undefined4 *)(pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30))) =
                   *(undefined4 *)(DAT_0005ac0c + 0x5bb38);
              uVar17 = *puVar21;
              *(undefined4 *)(pcVar4 + 8) = uVar24;
              *(undefined4 *)(pcVar4 + 4) = uVar20;
              *(undefined4 *)(pcVar4 + 0x10) = uVar17;
              puVar21 = (undefined4 *)(DAT_0005ac14 + 0x5bb88);
LAB_0005b73c:
              *(undefined4 *)(pcVar4 + 0xc) = uVar28;
              uVar17 = local_424[1];
              *(undefined4 *)(pcVar30 + (int)(local_42c + (0x48 - (int)pcVar30))) = *local_424;
              *(undefined4 *)(pcVar30 + (int)(local_42c + (0x48 - (int)pcVar30) + 4)) = uVar17;
              uVar17 = *puVar21;
              uVar20 = puVar21[1];
              uVar24 = puVar21[2];
              uVar28 = puVar21[3];
              puVar21 = puVar21 + 4;
            }
            else {
              if (iVar31 != 3) {
                if (iVar31 == 4) {
                  pcVar4 = pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30));
                  uVar20 = *(undefined4 *)(DAT_0005abd4 + 0x5b98c);
                  uVar17 = *(undefined4 *)(DAT_0005abd4 + 0x5b990);
                  uVar24 = *(undefined4 *)(DAT_0005abd4 + 0x5b994);
                  puVar21 = (undefined4 *)(DAT_0005abd4 + 0x5b998);
                  *(undefined4 *)(pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30))) =
                       *(undefined4 *)(DAT_0005abd4 + 0x5b988);
                  pcVar8 = local_42c + (0x4c - (int)pcVar30);
                  pcVar6 = pcVar30 + (int)pcVar8;
                  *(undefined4 *)(pcVar4 + 8) = uVar17;
                  iVar19 = DAT_0005abdc;
                  iVar31 = DAT_0005abd8;
                  uVar17 = *puVar21;
                  *(undefined4 *)(pcVar4 + 4) = uVar20;
                  puVar40 = (undefined4 *)(iVar31 + 0x5b9c4);
                  *(undefined4 *)(pcVar4 + 0x10) = uVar17;
                  puVar21 = (undefined4 *)(iVar19 + 0x5b9cc);
                }
                else if (iVar31 == 8) {
                  pcVar4 = pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30));
                  uVar20 = *(undefined4 *)(DAT_0005abc8 + 0x5b934);
                  uVar17 = *(undefined4 *)(DAT_0005abc8 + 0x5b938);
                  uVar24 = *(undefined4 *)(DAT_0005abc8 + 0x5b93c);
                  puVar21 = (undefined4 *)(DAT_0005abc8 + 0x5b940);
                  *(undefined4 *)(pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30))) =
                       *(undefined4 *)(DAT_0005abc8 + 0x5b930);
                  pcVar8 = local_42c + (0x4c - (int)pcVar30);
                  pcVar6 = pcVar30 + (int)pcVar8;
                  *(undefined4 *)(pcVar4 + 8) = uVar17;
                  iVar19 = DAT_0005abd0;
                  iVar31 = DAT_0005abcc;
                  uVar17 = *puVar21;
                  *(undefined4 *)(pcVar4 + 4) = uVar20;
                  puVar40 = (undefined4 *)(iVar31 + 0x5b96c);
                  *(undefined4 *)(pcVar4 + 0x10) = uVar17;
                  puVar21 = (undefined4 *)(iVar19 + 0x5b974);
                }
                else {
                  if (iVar31 == 5) {
                    iVar31 = 0x4f - (int)pcVar30;
                    local_424 = (undefined4 *)(DAT_0005ab70 + 0x5b6f8);
                    pcVar4 = pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30));
                    uVar20 = *(undefined4 *)(DAT_0005ab6c + 0x5b6f4);
                    uVar24 = *(undefined4 *)(DAT_0005ab6c + 0x5b6f8);
                    uVar28 = *(undefined4 *)(DAT_0005ab6c + 0x5b6fc);
                    puVar21 = (undefined4 *)(DAT_0005ab6c + 0x5b700);
                    *(undefined4 *)(pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30))) =
                         *(undefined4 *)(DAT_0005ab6c + 0x5b6f0);
                    uVar17 = *puVar21;
                    *(undefined4 *)(pcVar4 + 8) = uVar24;
                    *(undefined4 *)(pcVar4 + 4) = uVar20;
                    *(undefined4 *)(pcVar4 + 0x10) = uVar17;
                    puVar21 = (undefined4 *)(DAT_0005ab74 + 0x5b740);
                    goto LAB_0005b73c;
                  }
                  pcVar4 = pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30));
                  uVar20 = *(undefined4 *)(DAT_0005aa84 + 0x5ae0c);
                  uVar17 = *(undefined4 *)(DAT_0005aa84 + 0x5ae10);
                  uVar24 = *(undefined4 *)(DAT_0005aa84 + 0x5ae14);
                  puVar21 = (undefined4 *)(DAT_0005aa84 + 0x5ae18);
                  *(undefined4 *)(pcVar30 + (int)(local_42c + (0x35 - (int)pcVar30))) =
                       *(undefined4 *)(DAT_0005aa84 + 0x5ae08);
                  pcVar8 = local_42c + (0x4b - (int)pcVar30);
                  pcVar6 = pcVar30 + (int)pcVar8;
                  *(undefined4 *)(pcVar4 + 8) = uVar17;
                  uVar17 = *puVar21;
                  puVar40 = (undefined4 *)(DAT_0005aa88 + 0x5ae40);
                  puVar21 = (undefined4 *)(DAT_0005aa8c + 0x5ae44);
                  *(undefined4 *)(pcVar4 + 4) = uVar20;
                  *(undefined4 *)(pcVar4 + 0x10) = uVar17;
                }
                goto LAB_0005ae48;
              }
              pcVar4 = local_42c + (0x35 - (int)pcVar30);
              uVar20 = *(undefined4 *)(DAT_0005abe8 + 0x5ba10);
              uVar17 = *(undefined4 *)(DAT_0005abe8 + 0x5ba14);
              uVar24 = *(undefined4 *)(DAT_0005abe8 + 0x5ba18);
              puVar21 = (undefined4 *)(DAT_0005abe8 + 0x5ba1c);
              *(undefined4 *)(pcVar30 + (int)pcVar4) = *(undefined4 *)(DAT_0005abe8 + 0x5ba0c);
              iVar31 = 0x4d - (int)pcVar30;
              *(undefined4 *)(pcVar30 + (int)(pcVar4 + 8)) = uVar17;
              iVar19 = DAT_0005abec;
              uVar17 = *puVar21;
              puVar21 = (undefined4 *)(DAT_0005abec + 0x5ba3c);
              *(undefined4 *)(pcVar30 + (int)(pcVar4 + 4)) = uVar20;
              iVar35 = DAT_0005abf0;
              *(undefined4 *)(pcVar30 + (int)(pcVar4 + 0x10)) = uVar17;
              *(undefined4 *)(pcVar30 + (int)(pcVar4 + 0xc)) = uVar24;
              cVar22 = *(char *)(iVar19 + 0x5ba40);
              *(undefined4 *)(pcVar30 + (int)(local_42c + (0x48 - (int)pcVar30))) = *puVar21;
              uVar17 = *(undefined4 *)(iVar35 + 0x5ba5c);
              uVar20 = *(undefined4 *)(iVar35 + 0x5ba60);
              uVar24 = *(undefined4 *)(iVar35 + 0x5ba64);
              uVar28 = *(undefined4 *)(iVar35 + 0x5ba68);
              puVar21 = (undefined4 *)(iVar35 + 0x5ba6c);
              pcVar30[(int)(local_42c + (0x48 - (int)pcVar30) + 4)] = cVar22;
            }
            local_444 = local_42c + iVar31;
            *(undefined4 *)(pcVar30 + (int)local_444) = uVar17;
            uVar2 = *(undefined2 *)(puVar21 + 1);
            uVar17 = *puVar21;
            cVar22 = *(char *)((int)puVar21 + 6);
            *(undefined4 *)(pcVar30 + (int)(local_444 + 4)) = uVar20;
            *(undefined4 *)(pcVar30 + (int)(local_444 + 8)) = uVar24;
            *(undefined4 *)(pcVar30 + (int)(local_444 + 0xc)) = uVar28;
            *(undefined4 *)(pcVar30 + (int)(local_444 + 0x10)) = uVar17;
            *(undefined2 *)(pcVar30 + (int)(local_444 + 0x14)) = uVar2;
            pcVar30[(int)(local_444 + 0x16)] = cVar22;
          }
          sVar5 = strlen(pcVar30);
          uVar17 = *(undefined4 *)(DAT_0005aa90 + 0x5aea0);
          *(undefined4 *)(pcVar30 + sVar5) = *(undefined4 *)(DAT_0005aa90 + 0x5ae9c);
          *(undefined4 *)(pcVar30 + sVar5 + 4) = uVar17;
          pcVar4 = stpcpy(pcVar30 + sVar5 + 8,acStack_358);
          iVar31 = DAT_0005aa98;
          uVar17 = *(undefined4 *)(DAT_0005aa94 + 0x5aed0);
          uVar20 = *(undefined4 *)(DAT_0005aa94 + 0x5aed4);
          *(undefined4 *)pcVar4 = *(undefined4 *)(DAT_0005aa94 + 0x5aecc);
          *(undefined4 *)(pcVar4 + 8) = uVar20;
          *(undefined4 *)(pcVar4 + 4) = uVar17;
          strcpy(pcVar4 + 0xb,*(char **)(iVar39 + iVar31));
          local_444 = (char *)0x0;
          *(undefined4 *)(DAT_0005aa9c + 0x5b1b8) = 0;
        }
        else {
          if (local_418 == 0x4e) {
            FUN_0001ab94(3,DAT_0005cbcc + 0x5c27c,iVar31 + 0x5aeb4);
            system((char *)(DAT_0005cbd0 + 0x5c288));
            pcVar30 = *(char **)(iVar39 + DAT_0005cb30);
            memset(pcVar30,0,0x800);
            strncpy(pcVar30,*(char **)(iVar39 + DAT_0005cb34),0x7ff);
            sVar5 = strlen(pcVar30);
            pcVar4 = stpcpy(pcVar30 + sVar5,*(char **)(iVar39 + DAT_0005cb38));
            uVar17 = *(undefined4 *)(DAT_0005cbd4 + 0x5c2dc);
            iVar31 = DAT_0005cbd4 + 0x5c2e0;
            *(undefined4 *)pcVar4 = *(undefined4 *)(DAT_0005cbd4 + 0x5c2d8);
            *(undefined4 *)(pcVar4 + 4) = uVar17;
            pcVar4 = (char *)FUN_00040758(local_418,uVar17,pcVar4,iVar31);
            if (pcVar4 != (char *)0x0) {
              strncpy(acStack_358,pcVar4,0x31);
              sVar5 = strlen(pcVar30);
              iVar31 = DAT_0005cbd8;
              puVar21 = (undefined4 *)(DAT_0005cbd8 + 0x5c324);
              pcVar6 = stpcpy(pcVar30 + sVar5,acStack_358);
              pcVar4 = pcVar6;
              do {
                pcVar8 = pcVar4;
                puVar40 = puVar21;
                uVar17 = puVar40[1];
                uVar20 = puVar40[2];
                uVar24 = puVar40[3];
                *(undefined4 *)pcVar8 = *puVar40;
                *(undefined4 *)(pcVar8 + 4) = uVar17;
                *(undefined4 *)(pcVar8 + 8) = uVar20;
                *(undefined4 *)(pcVar8 + 0xc) = uVar24;
                iVar19 = DAT_0005cbdc;
                puVar21 = puVar40 + 4;
                pcVar4 = pcVar8 + 0x10;
              } while (puVar40 + 4 != (undefined4 *)(iVar31 + 0x5c354));
              puVar21 = (undefined4 *)(DAT_0005cbdc + 0x5c380);
              cVar22 = *(char *)(puVar40 + 5);
              *(undefined4 *)(pcVar8 + 0x10) = puVar40[4];
              uVar17 = *puVar21;
              uVar20 = *(undefined4 *)(iVar19 + 0x5c384);
              pcVar8[0x14] = cVar22;
              *(undefined4 *)(pcVar30 + (int)(pcVar6 + (0x35 - (int)pcVar30))) = uVar17;
              *(undefined4 *)(pcVar30 + (int)(pcVar6 + (0x35 - (int)pcVar30) + 4)) = uVar20;
              pcVar4 = stpcpy(pcVar30 + (int)(pcVar6 + (0x3d - (int)pcVar30)),acStack_358);
              local_444 = (char *)0x0;
              puVar21 = (undefined4 *)(DAT_0005cbe0 + 0x5c3c0);
              goto LAB_0005bd60;
            }
            goto LAB_0005b5a0;
          }
          if (local_418 == 0x5c) {
            **(undefined4 **)(iVar39 + DAT_0005cb88) = 1;
            pcVar30 = *(char **)(iVar39 + iVar19);
            memset(pcVar30,0,0x800);
            strncpy(pcVar30,*(char **)(iVar39 + DAT_0005cb34),0x7ff);
            sVar5 = strlen(pcVar30);
            pcVar4 = stpcpy(pcVar30 + sVar5,*(char **)(iVar39 + DAT_0005cb38));
            uVar17 = *(undefined4 *)(DAT_0005cb8c + 0x5bf30);
            iVar31 = DAT_0005cb8c + 0x5bf34;
            *(undefined4 *)pcVar4 = *(undefined4 *)(DAT_0005cb8c + 0x5bf2c);
            *(undefined4 *)(pcVar4 + 4) = uVar17;
            pcVar4 = (char *)FUN_00040758(0x5c,uVar17,pcVar4,iVar31);
            if (pcVar4 == (char *)0x0) goto LAB_0005b5a0;
            strncpy(acStack_358,pcVar4,0x31);
            sVar5 = strlen(pcVar30);
            iVar31 = DAT_0005cb90;
            puVar21 = (undefined4 *)(DAT_0005cb90 + 0x5bf78);
            pcVar6 = stpcpy(pcVar30 + sVar5,acStack_358);
            pcVar4 = pcVar6;
            do {
              pcVar8 = pcVar4;
              puVar40 = puVar21;
              uVar17 = puVar40[1];
              uVar20 = puVar40[2];
              uVar24 = puVar40[3];
              *(undefined4 *)pcVar8 = *puVar40;
              *(undefined4 *)(pcVar8 + 4) = uVar17;
              *(undefined4 *)(pcVar8 + 8) = uVar20;
              *(undefined4 *)(pcVar8 + 0xc) = uVar24;
              iVar19 = DAT_0005cb94;
              puVar21 = puVar40 + 4;
              pcVar4 = pcVar8 + 0x10;
            } while (puVar40 + 4 != (undefined4 *)(iVar31 + 0x5bfa8));
            puVar21 = (undefined4 *)(DAT_0005cb94 + 0x5bfd4);
            cVar22 = *(char *)(puVar40 + 5);
            *(undefined4 *)(pcVar8 + 0x10) = puVar40[4];
            uVar17 = *puVar21;
            uVar20 = *(undefined4 *)(iVar19 + 0x5bfd8);
            pcVar8[0x14] = cVar22;
            *(undefined4 *)(pcVar30 + (int)(pcVar6 + (0x35 - (int)pcVar30))) = uVar17;
            *(undefined4 *)(pcVar30 + (int)(pcVar6 + (0x35 - (int)pcVar30) + 4)) = uVar20;
            pcVar4 = stpcpy(pcVar30 + (int)(pcVar6 + (0x3d - (int)pcVar30)),acStack_358);
            local_444 = (char *)0x0;
            puVar21 = (undefined4 *)(DAT_0005cb98 + 0x5c014);
LAB_0005bd60:
            iVar31 = DAT_0005cb4c;
            uVar17 = puVar21[1];
            uVar20 = puVar21[2];
            *(undefined4 *)pcVar4 = *puVar21;
            *(undefined4 *)(pcVar4 + 4) = uVar17;
            *(undefined4 *)(pcVar4 + 8) = uVar20;
            strcpy(pcVar4 + 0xb,*(char **)(iVar39 + iVar31));
          }
          else {
            if (local_414 == 1) {
              uVar36 = FUN_0003f5d8(param_1,param_4);
              local_430 = uVar36;
              if (uVar36 != 0) goto LAB_0005a770;
              local_430 = FUN_000540e8(iVar34,local_418);
              iVar19 = DAT_0005cb54;
              if (1 < local_430) goto LAB_00059bc0;
              if (local_418 == 0x23) {
                FUN_0001ab94(3,DAT_0005cb50 + 0x5bd9c,iVar31 + 0x5aec8,local_430,iVar18,iVar37);
                iVar31 = DAT_0005cb5c;
                acosNvramConfig_set(DAT_0005cb58 + 0x5bdb8,iVar19 + 0x5bda8);
                iVar31 = iVar31 + 0x5bdc0;
                acosNvramConfig_set(DAT_0005cb60 + 0x5bdcc,iVar31);
                iVar35 = acosNvramConfig_match(DAT_0005cb64 + 0x5bddc,iVar31);
                if (iVar35 != 0) {
                  acosNvramConfig_set(DAT_0005cb68 + 0x5bdf4,iVar19 + 0x5bda8);
                  acosNvramConfig_set(DAT_0005cb6c + 0x5be04,iVar31);
                }
                **(undefined4 **)(iVar39 + DAT_0005cb70) = 1;
              }
              if (local_418 == 0x65) {
                FUN_00019dd8();
              }
              if (local_418 == 0x69) {
                FUN_00019dd8();
              }
              iVar31 = local_418;
              pcVar30 = *(char **)(iVar39 + DAT_0005cb30);
              memset(pcVar30,0,0x800);
              strncpy(pcVar30,*(char **)(iVar39 + DAT_0005cb34),0x7ff);
              sVar5 = strlen(pcVar30);
              pcVar4 = stpcpy(pcVar30 + sVar5,*(char **)(iVar39 + DAT_0005cb38));
              uVar17 = *(undefined4 *)(DAT_0005cb3c + 0x5bc68);
              iVar19 = DAT_0005cb3c + 0x5bc6c;
              *(undefined4 *)pcVar4 = *(undefined4 *)(DAT_0005cb3c + 0x5bc64);
              *(undefined4 *)(pcVar4 + 4) = uVar17;
              pcVar4 = (char *)FUN_00040758(iVar31,uVar17,pcVar4,iVar19);
              if (pcVar4 == (char *)0x0) goto LAB_0005b5a0;
              strncpy(acStack_358,pcVar4,0x31);
              sVar5 = strlen(pcVar30);
              iVar31 = DAT_0005cb40;
              puVar21 = (undefined4 *)(DAT_0005cb40 + 0x5bcb0);
              pcVar6 = stpcpy(pcVar30 + sVar5,acStack_358);
              pcVar4 = pcVar6;
              do {
                pcVar8 = pcVar4;
                puVar40 = puVar21;
                uVar17 = puVar40[1];
                uVar20 = puVar40[2];
                uVar24 = puVar40[3];
                *(undefined4 *)pcVar8 = *puVar40;
                *(undefined4 *)(pcVar8 + 4) = uVar17;
                *(undefined4 *)(pcVar8 + 8) = uVar20;
                *(undefined4 *)(pcVar8 + 0xc) = uVar24;
                puVar21 = puVar40 + 4;
                pcVar4 = pcVar8 + 0x10;
              } while (puVar40 + 4 != (undefined4 *)(iVar31 + 0x5bce0));
              uVar17 = puVar40[4];
              *(undefined2 *)(pcVar8 + 0x14) = *(undefined2 *)(puVar40 + 5);
              *(undefined4 *)(pcVar8 + 0x10) = uVar17;
              iVar31 = DAT_0005cba4;
              if (local_418 == 0x2b) {
                pcVar6 = pcVar6 + (0x35 - (int)pcVar30);
                uVar17 = *(undefined4 *)(DAT_0005cbb4 + 0x5c138);
                uVar20 = *(undefined4 *)(DAT_0005cbb4 + 0x5c13c);
                uVar24 = *(undefined4 *)(DAT_0005cbb4 + 0x5c140);
                puVar21 = (undefined4 *)(DAT_0005cbb4 + 0x5c144);
                local_224 = 0;
                local_220 = 0;
                *(undefined4 *)(pcVar30 + (int)pcVar6) = *(undefined4 *)(DAT_0005cbb4 + 0x5c134);
                iVar31 = DAT_0005cbb8;
                local_21c = 0;
                uStack_218 = 0;
                *(undefined4 *)(pcVar30 + (int)(pcVar6 + 0x10)) = *puVar21;
                iVar19 = DAT_0005cbbc;
                pcVar8 = (char *)(iVar31 + 0x5c16c);
                *(undefined4 *)(pcVar30 + (int)(pcVar6 + 4)) = uVar17;
                *(undefined4 *)(pcVar30 + (int)(pcVar6 + 8)) = uVar20;
                *(undefined4 *)(pcVar30 + (int)(pcVar6 + 0xc)) = uVar24;
                pcVar4 = (char *)acosNvramConfig_get(iVar19 + 0x5c178);
                strcpy((char *)&local_224,pcVar4);
                pcVar4 = strcasestr((char *)&local_224,pcVar8);
                iVar19 = DAT_0005cbc8;
                if (pcVar4 == (char *)0x0) {
                  pcVar6 = (char *)(DAT_0005cbc8 + 0x5c22c);
                  pcVar4 = strcasestr((char *)&local_224,pcVar6);
                  if (pcVar4 == (char *)0x0) {
                    pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005cc14 + 0x5c804));
                    if (pcVar4 == (char *)0x0) {
                      pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005cc24 + 0x5c860));
                      if (pcVar4 == (char *)0x0) {
                        pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005cc3c + 0x5c8d4));
                        if (pcVar4 == (char *)0x0) {
                          pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005cdfc + 0x5d4fc));
                          if (pcVar4 != (char *)0x0) {
                            sVar5 = strlen(pcVar30);
                            uVar17 = *(undefined4 *)(DAT_0005ce00 + 0x5d51c);
                            *(undefined4 *)(pcVar30 + sVar5) =
                                 *(undefined4 *)(DAT_0005ce00 + 0x5d518);
                            *(undefined4 *)(pcVar30 + sVar5 + 4) = uVar17;
                            goto LAB_0005c1bc;
                          }
                          pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005ce04 + 0x5d53c));
                          if (pcVar4 != (char *)0x0) {
                            sVar5 = strlen(pcVar30);
                            puVar21 = (undefined4 *)(DAT_0005ce08 + 0x5d558);
                            goto LAB_0005c820;
                          }
                          pcVar4 = strcasestr((char *)&local_224,(char *)(DAT_0005ce0c + 0x5d56c));
                          if (pcVar4 == (char *)0x0) {
                            sVar5 = strlen(pcVar30);
                            puVar21 = (undefined4 *)(DAT_0005ce14 + 0x5d59c);
                          }
                          else {
                            sVar5 = strlen(pcVar30);
                            puVar21 = (undefined4 *)(DAT_0005ce10 + 0x5d588);
                          }
                        }
                        else {
                          sVar5 = strlen(pcVar30);
                          puVar21 = (undefined4 *)(DAT_0005cc40 + 0x5c8f0);
                        }
                      }
                      else {
                        sVar5 = strlen(pcVar30);
                        puVar21 = (undefined4 *)(DAT_0005cc28 + 0x5c87c);
                      }
                      cVar22 = *(char *)(puVar21 + 1);
                      *(undefined4 *)(pcVar30 + sVar5) = *puVar21;
                      pcVar30[sVar5 + 4] = cVar22;
                    }
                    else {
                      sVar5 = strlen(pcVar30);
                      puVar21 = (undefined4 *)(DAT_0005cc18 + 0x5c820);
LAB_0005c820:
                      uVar2 = *(undefined2 *)(puVar21 + 1);
                      *(undefined4 *)(pcVar30 + sVar5) = *puVar21;
                      *(undefined2 *)(pcVar30 + sVar5 + 4) = uVar2;
                    }
                  }
                  else {
                    sVar5 = strlen(pcVar30);
                    uVar2 = *(undefined2 *)(iVar19 + 0x5c230);
                    cVar22 = *(char *)(iVar19 + 0x5c232);
                    *(undefined4 *)(pcVar30 + sVar5) = *(undefined4 *)pcVar6;
                    *(undefined2 *)(pcVar30 + sVar5 + 4) = uVar2;
                    pcVar30[sVar5 + 6] = cVar22;
                  }
                }
                else {
                  sVar5 = strlen(pcVar30);
                  cVar22 = *(char *)(iVar31 + 0x5c170);
                  *(undefined4 *)(pcVar30 + sVar5) = *(undefined4 *)pcVar8;
                  pcVar30[sVar5 + 4] = cVar22;
                }
LAB_0005c1bc:
                sVar5 = strlen(pcVar30);
                iVar31 = DAT_0005cbc0;
                uVar20 = *(undefined4 *)(DAT_0005cbc0 + 0x5c1d4);
                uVar24 = *(undefined4 *)(DAT_0005cbc0 + 0x5c1d8);
                uVar28 = *(undefined4 *)(DAT_0005cbc0 + 0x5c1dc);
                puVar21 = (undefined4 *)(DAT_0005cbc0 + 0x5c1e0);
                *(undefined4 *)(pcVar30 + sVar5) = *(undefined4 *)(DAT_0005cbc0 + 0x5c1d0);
                uVar2 = *(undefined2 *)(iVar31 + 0x5c1e4);
                uVar17 = *puVar21;
                cVar22 = *(char *)(iVar31 + 0x5c1e6);
                *(undefined4 *)(pcVar30 + sVar5 + 4) = uVar20;
                *(undefined4 *)(pcVar30 + sVar5 + 8) = uVar24;
                *(undefined4 *)(pcVar30 + sVar5 + 0xc) = uVar28;
                *(undefined4 *)(pcVar30 + sVar5 + 0x10) = uVar17;
                *(undefined2 *)(pcVar30 + sVar5 + 0x14) = uVar2;
                pcVar30[sVar5 + 0x16] = cVar22;
              }
              else if (local_418 == 0x6d) {
                pcVar6 = pcVar6 + (0x35 - (int)pcVar30);
                puVar42 = (undefined2 *)(DAT_0005cba8 + 0x5c08c);
                uVar17 = *(undefined4 *)(DAT_0005cba4 + 0x5c08c);
                uVar24 = *(undefined4 *)(DAT_0005cba4 + 0x5c090);
                uVar28 = *(undefined4 *)(DAT_0005cba4 + 0x5c094);
                puVar21 = (undefined4 *)(DAT_0005cba4 + 0x5c098);
                *(undefined4 *)(pcVar30 + (int)pcVar6) = *(undefined4 *)(DAT_0005cba4 + 0x5c088);
                *(undefined4 *)(pcVar30 + (int)(pcVar6 + 4)) = uVar17;
                uVar17 = *puVar21;
                uVar20 = *(undefined4 *)(iVar31 + 0x5c09c);
                *(undefined4 *)(pcVar30 + (int)(pcVar6 + 8)) = uVar24;
                *(undefined4 *)(pcVar30 + (int)(pcVar6 + 0xc)) = uVar28;
                *(undefined4 *)(pcVar30 + (int)(pcVar6 + 0x10)) = uVar17;
                iVar31 = DAT_0005cbac;
                *(undefined4 *)(pcVar30 + (int)(pcVar6 + 0x14)) = uVar20;
                iVar31 = acosNvramConfig_match(iVar31 + 0x5c0b8,puVar42);
                if (iVar31 == 0) {
                  sVar5 = strlen(pcVar30);
                  *(undefined2 *)(pcVar30 + sVar5) = *(undefined2 *)(DAT_0005cbc4 + 0x5c214);
                }
                else {
                  sVar5 = strlen(pcVar30);
                  *(undefined2 *)(pcVar30 + sVar5) = *puVar42;
                }
                sVar5 = strlen(pcVar30);
                iVar31 = DAT_0005cbb0;
                uVar17 = *(undefined4 *)(DAT_0005cbb0 + 0x5c0e8);
                uVar24 = *(undefined4 *)(DAT_0005cbb0 + 0x5c0ec);
                uVar28 = *(undefined4 *)(DAT_0005cbb0 + 0x5c0f0);
                puVar21 = (undefined4 *)(DAT_0005cbb0 + 0x5c0f4);
                *(undefined4 *)(pcVar30 + sVar5) = *(undefined4 *)(DAT_0005cbb0 + 0x5c0e4);
                *(undefined4 *)(pcVar30 + sVar5 + 4) = uVar17;
                uVar17 = *puVar21;
                uVar20 = *(undefined4 *)(iVar31 + 0x5c0f8);
                *(undefined4 *)(pcVar30 + sVar5 + 8) = uVar24;
                *(undefined4 *)(pcVar30 + sVar5 + 0xc) = uVar28;
                uVar2 = *(undefined2 *)(iVar31 + 0x5c0fc);
                cVar22 = *(char *)(iVar31 + 0x5c0fe);
                *(undefined4 *)(pcVar30 + sVar5 + 0x10) = uVar17;
                *(undefined4 *)(pcVar30 + sVar5 + 0x14) = uVar20;
                *(undefined2 *)(pcVar30 + sVar5 + 0x18) = uVar2;
                pcVar30[sVar5 + 0x1a] = cVar22;
              }
              sVar5 = strlen(pcVar30);
              uVar17 = *(undefined4 *)(DAT_0005cb44 + 0x5bd38);
              *(undefined4 *)(pcVar30 + sVar5) = *(undefined4 *)(DAT_0005cb44 + 0x5bd34);
              *(undefined4 *)(pcVar30 + sVar5 + 4) = uVar17;
              pcVar4 = stpcpy(pcVar30 + sVar5 + 8,acStack_358);
              puVar21 = (undefined4 *)(DAT_0005cb48 + 0x5bd60);
              local_444 = (char *)local_430;
              local_430 = uVar36;
              goto LAB_0005bd60;
            }
            pcVar30 = (char *)0x0;
            local_444 = (char *)0x0;
          }
        }
        iVar31 = local_40c;
        if (local_41c == -1) {
          if (local_40c < 1) {
            local_434 = (word *)0x20000;
          }
          else {
            FUN_0001ab94(3,DAT_0005aa04 + 0x5a624,DAT_0005aa00 + 0x5b438,0xffffffff,iVar18,iVar37);
            puVar21 = *(undefined4 **)(iVar39 + DAT_0005aa08);
            memset(puVar21,0,0x41);
            iVar34 = DAT_0005aa10;
            if (iVar31 == 1) {
              iVar19 = 0;
            }
            else {
              iVar19 = 0x1e;
            }
            **(int **)(iVar39 + DAT_0005aa0c) = iVar31;
            puVar26 = (undefined4 *)(iVar19 + *(int *)(iVar39 + iVar34));
            puVar40 = puVar26;
            do {
              puVar27 = puVar40 + 4;
              uVar24 = puVar40[1];
              uVar17 = puVar40[2];
              uVar20 = puVar40[3];
              *puVar21 = *puVar40;
              puVar21[1] = uVar24;
              puVar21[2] = uVar17;
              puVar21[3] = uVar20;
              puVar40 = puVar27;
              puVar21 = puVar21 + 4;
            } while (puVar27 != puVar26 + 0x10);
            pcVar30 = *(char **)(iVar39 + DAT_0005aa14);
LAB_0005a6a0:
            if (local_41c == 0x1e) {
              local_434 = &WORD_00015800;
            }
            else {
              local_434 = (word *)0x20000;
            }
          }
          if ((**(int **)(iVar39 + DAT_0005aa18) == 0x17) && (local_418 == 0x59)) {
            pcVar4 = (char *)0x0;
            local_408 = 0;
            local_404 = (char *)0x0;
            memset(&local_224,0,0x80);
            FUN_0001ab94(3,DAT_0005aab0 + 0x5b040);
            puVar21 = *(undefined4 **)(iVar39 + DAT_0005aab4);
            uVar36 = *(uint *)(DAT_0005aab8 + 0x5b2f4);
            iVar31 = *(int *)(DAT_0005aab8 + 0x5b2f8);
            *puVar21 = 0x41;
            getRoofsSize(&local_408);
            printf((char *)(DAT_0005aabc + 0x5b088),uVar36,local_408);
            if (local_408 < uVar36) {
              printf((char *)(DAT_0005aac0 + 0x5b0a0));
LAB_0005b0a0:
              *puVar21 = 0x42;
              local_444 = (char *)0x1f5;
            }
            else {
              pcVar6 = (char *)(DAT_0005cce4 + 0x5ce28);
              pFVar7 = fopen64(pcVar6,(char *)(DAT_0005cce8 + 0x5ce2c));
              if (pFVar7 == (FILE *)0x0) {
                FUN_0001ab94(3,DAT_0005cd0c + 0x5d028,pcVar6);
                goto LAB_0005b0a0;
              }
              FUN_000507d8(pFVar7,&local_404);
              pvVar16 = malloc(0x400);
              if (pvVar16 == (void *)0x0) {
                FUN_0001ab94(3,DAT_0005cd08 + 0x5d010);
                goto LAB_0005b0a0;
              }
              MD5Init(&local_400);
              do {
                sVar5 = fread(pvVar16,1,0x400,pFVar7);
                MD5Update(&local_400,pvVar16,sVar5);
                memset(pvVar16,0,0x400);
                pcVar4 = pcVar4 + sVar5;
                if (sVar5 == 0) break;
              } while (pcVar4 <= local_404);
              MD5Final(&local_378,&local_400);
              iVar34 = (int)&local_2a4 + 1;
              puVar40 = &local_2a4;
              pbVar33 = (byte *)&local_378;
              do {
                pbVar41 = pbVar33 + 1;
                bVar1 = *pbVar33;
                *(byte *)(iVar34 + -1) = bVar1 >> 4;
                *(byte *)((int)puVar40 + 1) = bVar1 & 0xf;
                bVar1 = *(byte *)(iVar34 + -1);
                if (bVar1 < 10) {
                  cVar22 = bVar1 + 0x30;
                }
                else {
                  cVar22 = bVar1 + 0x37;
                }
                *(char *)(iVar34 + -1) = cVar22;
                bVar1 = *(byte *)((int)puVar40 + 1);
                if (bVar1 < 10) {
                  cVar22 = bVar1 + 0x30;
                }
                else {
                  cVar22 = bVar1 + 0x37;
                }
                *(char *)((int)puVar40 + 1) = cVar22;
                iVar34 = iVar34 + 2;
                puVar40 = (undefined4 *)((int)puVar40 + 2);
                pbVar33 = pbVar41;
              } while (pbVar41 != (byte *)&local_368);
              pbVar33 = &bStack_2a5;
              free(pvVar16);
              iVar34 = DAT_0005ccf0;
              pcVar4 = (char *)(*(int *)(iVar39 + DAT_0005ccec) + -1);
              do {
                pcVar4 = pcVar4 + 1;
                pbVar33 = pbVar33 + 1;
                if ((int)*pcVar4 != (uint)*pbVar33) {
                  FUN_0001ab94(3,DAT_0005cd1c + 0x5d0a8);
                  goto LAB_0005b0a0;
                }
              } while ((char *)(*(int *)(iVar39 + DAT_0005ccec) + 0x1f) != pcVar4);
              sVar5 = uVar36 + iVar31 + 0x400;
              lVar29 = *(long *)(DAT_0005ccf0 + 0x5d220);
              acosNvramConfig_set(DAT_0005ccf8 + 0x5cf88,DAT_0005ccf4 + 0x5cf84);
              remove_running_modules(1);
              create_upgrade_file();
              fseek(pFVar7,lVar29,0);
              pvVar16 = malloc(sVar5);
              if (pvVar16 == (void *)0x0) {
                FUN_0001ab94(3,DAT_0005cd40 + 0x5d1d8);
                goto LAB_0005b0a0;
              }
              sVar5 = fread(pvVar16,1,sVar5,pFVar7);
              if (sVar5 == 0) {
                FUN_0001ab94(3,DAT_0005cd00 + 0x5cff0,0,DAT_0005ccfc + 0x5cfec);
                goto LAB_0005b0a0;
              }
              calculate_checksum(0,0);
              calculate_checksum(1,pvVar16,uVar36);
              iVar31 = calculate_checksum(2,0);
              if (iVar31 != *(int *)(iVar34 + 0x5d214)) {
                FUN_0001ab94(3,DAT_0005cd20 + 0x5d0fc,iVar31);
              }
              pcVar4 = (char *)(DAT_0005cd24 + 0x5d10c);
              __s = fopen64(pcVar4,(char *)(DAT_0005cd28 + 0x5d110));
              if (__s == (FILE *)0x0) {
                printf((char *)(DAT_0005cd48 + 0x5d208),pcVar4);
                local_444 = (char *)0xffffffff;
              }
              else {
                sVar5 = fwrite(pvVar16,1,uVar36,__s);
                if (uVar36 == sVar5) {
                  local_444 = (char *)0x0;
                  fclose(__s);
                  fclose(pFVar7);
                  unlink((char *)(DAT_0005cd2c + 0x5d15c));
                  snprintf((char *)&local_224,0x80,(char *)(DAT_0005cd30 + 0x5d178),pcVar4);
                  free(pvVar16);
                  system((char *)&local_224);
                  FUN_0001ab94(3,DAT_0005cd34 + 0x5d198);
                  iVar34 = DAT_0005cd3c;
                  iVar31 = DAT_0005cd38;
                  *puVar21 = 0x43;
                  piVar32 = *(int **)(iVar39 + iVar31);
                  *piVar32 = 0x59;
                  **(undefined4 **)(iVar39 + iVar34) = 1;
                  goto LAB_0005a6d0;
                }
                printf((char *)(DAT_0005cd44 + 0x5d1ec),pcVar4);
                local_444 = (char *)0xffffffff;
              }
            }
            iVar31 = DAT_0005aac8;
            **(undefined4 **)(iVar39 + DAT_0005aac4) = 0;
            piVar32 = *(int **)(iVar39 + iVar31);
          }
          else {
            piVar32 = *(int **)(iVar39 + DAT_0005aac8);
          }
LAB_0005a6d0:
          if (pcVar30 != (char *)0x0) {
            local_430 = FUN_0004b6b8(local_434,pcVar30,param_2,local_444);
          }
          iVar31 = FUN_00052c20();
          if (((iVar31 == 0x43) && (**(int **)(iVar39 + DAT_0005aac4) != 0)) && (local_418 == 0x59))
          {
            FUN_0001ab94(3,DAT_0005aaa0 + 0x5af34);
            sleep(5);
            if (param_2 != 0) {
              close(param_2);
            }
            FUN_0001ab94(3,DAT_0005aaa4 + 0x5af70);
            iVar31 = 0;
            do {
              iVar34 = iVar31 + 1;
              signal(iVar31,(__sighandler_t)0x0);
              iVar31 = iVar34;
            } while (iVar34 != 0x40);
            FUN_0001ab94(3,DAT_0005aaa8 + 0x5afa4);
            kill(-1,0xf);
            sleep(1);
            FUN_0001ab94(3,DAT_0005aaac + 0x5afc8);
            kill(-1,9);
            sleep(1);
            sync();
                    /* WARNING: Subroutine does not return */
            reboot(0x1234567);
          }
          *piVar32 = local_418;
          if (local_418 == 0x16) {
            memset(*(void **)(iVar39 + DAT_0005aaf0),0,100);
            iVar34 = DAT_0005aa20 + 0x5a748;
            iVar31 = DAT_0005aa24 + 0x5a74c;
            **(undefined4 **)(iVar39 + DAT_0005aa1c) = 0;
            iVar31 = acosNvramConfig_match(iVar31,iVar34);
            if (iVar31 == 0) {
              agApi_blankstate_set();
              shared_set_blank_state(0);
            }
            else {
              shared_set_blank_state(1);
            }
          }
        }
        else {
          local_378 = 0;
          local_370 = 0;
          local_374 = 0;
          local_36c = 0;
          local_368 = 0;
          local_364 = 0;
          local_360 = 0;
          local_35c = 0;
          pFVar7 = popen((char *)(DAT_0005a97c + 0x5a15c),(char *)(DAT_0005a978 + 0x5a154));
          if (pFVar7 != (FILE *)0x0) {
            iVar31 = DAT_0005a980 + 0x5a190;
            while (pcVar4 = fgets((char *)&local_2a4,0x80,pFVar7), pcVar4 != (char *)0x0) {
              pcVar4 = inet_ntoa(param_3);
              pcVar4 = strstr((char *)&local_2a4,pcVar4);
              if (pcVar4 != (char *)0x0) {
                __isoc99_sscanf(&local_2a4,iVar31,&local_378);
              }
            }
            pclose(pFVar7);
          }
          if (local_41c - 0x9bU < 2 || (local_41c == 0x58 || local_41c == 0x9f)) {
            local_430 = FUN_0003f5d8(param_1,param_4);
            iVar31 = local_41c;
            if (local_430 == 0) {
              FUN_0001ab94(3,DAT_0005aad0 + 0x5b144,DAT_0005aacc + 0x5bf2c,0x27d0);
              iVar19 = DAT_0005aad8 + 0x5b15c;
              iVar18 = *(int *)(iVar39 + DAT_0005aad4);
              iVar37 = DAT_0005aadc + 0x5bf58;
              pcVar4 = (char *)(iVar18 + 4);
              do {
                if (*pcVar4 != '\0') {
                  iVar35 = *(int *)(pcVar4 + -4);
                  pcVar30 = pcVar4;
                  FUN_0001ab94(3,iVar19,iVar37,0x27d8,pcVar4);
                  if (iVar35 == 0xff70) {
                    iVar31 = strcmp(pcVar4,(char *)(DAT_0005cb7c + 0x5be80));
                    if (iVar31 == 0) {
                      local_41c = 0x9c;
                      **(undefined4 **)(iVar39 + DAT_0005cb80) = 0;
                    }
                    else {
                      iVar31 = strcmp(pcVar4,(char *)(DAT_0005cba0 + 0x5c04c));
                      if (iVar31 == 0) {
                        local_41c = 0x9c;
                        **(undefined4 **)(iVar39 + DAT_0005cb80) = 1;
                      }
                      else {
                        local_41c = 0x9c;
                      }
                    }
                    goto LAB_0005a200;
                  }
                  if (iVar35 == 0xffc1) {
                    lVar29 = strtol(pcVar4,(char **)0x0,10);
                    local_41c = 0x58;
                    **(long **)(iVar39 + DAT_0005cb78) = lVar29;
                    goto LAB_0005a200;
                  }
                  if (iVar35 != 0xff6f) goto LAB_0005b180;
                  iVar19 = strcmp(pcVar4,(char *)(DAT_0005aae0 + 0x5b1f0));
                  if (iVar19 == 0) {
                    FUN_0001ab94(3,DAT_0005cb84 + 0x5beb4,iVar37,0x27e1,pcVar30);
                    if (iVar31 == 0x9b) {
LAB_0005c034:
                      local_41c = 0x9b;
                      goto LAB_0005a200;
                    }
LAB_0005bebc:
                    if (iVar31 == 0x9f) {
                      local_41c = 0x9f;
                      goto LAB_0005a200;
                    }
                  }
                  else {
                    iVar19 = strcmp(pcVar4,(char *)(DAT_0005aae4 + 0x5b208));
                    if (iVar19 == 0) {
                      FUN_0001ab94(3,DAT_0005cb74 + 0x5be34,iVar37,0x27e7,pcVar30);
                    }
                    else {
                      iVar19 = strcmp(pcVar4,(char *)(DAT_0005aae8 + 0x5b220));
                      if (iVar19 != 0) {
                        FUN_0001ab94(3,DAT_0005cb9c + 0x5c02c,iVar37,0x27fa,pcVar30);
                        if (iVar31 != 0x9b) goto LAB_0005bebc;
                        goto LAB_0005c034;
                      }
                      FUN_0001ab94(3,DAT_0005aaec + 0x5b240,iVar37,0x27f4,pcVar30);
                    }
                    if (iVar31 == 0x9b) {
                      local_41c = 0x9e;
                      goto LAB_0005a200;
                    }
                    if (iVar31 == 0x9f) {
                      local_41c = 0xa1;
                      goto LAB_0005a200;
                    }
                  }
                  break;
                }
LAB_0005b180:
                pcVar4 = pcVar4 + 0x4c;
              } while (pcVar4 != (char *)(iVar18 + 0x5f4));
              local_41c = 0;
              goto LAB_0005a200;
            }
          }
          else if ((4 < local_41c - 0xb6U) ||
                  (local_430 = FUN_0003f5d8(param_1,param_4), local_430 == 0)) {
LAB_0005a200:
            if (local_41c == 0xc4) {
              pcVar4 = strcasestr(param_1,(char *)(DAT_0005cbf4 + 0x5c680));
              if ((pcVar4 == (char *)0x0) ||
                 (pcVar4 = strcasestr(pcVar4,(char *)(DAT_0005cbf8 + 0x5c694)),
                 pcVar4 == (char *)0x0)) {
LAB_0005c7ec:
                iVar31 = 0;
              }
              else {
                pcVar30 = strcasestr(param_1,(char *)(DAT_0005cbfc + 0x5c6b0));
                iVar31 = DAT_0005cc00;
                if (pcVar30 == (char *)0x0) goto LAB_0005c7ec;
                *pcVar30 = '\0';
                iVar31 = acosNvramConfig_match(iVar31 + 0x5c6d0,pcVar4 + 1);
                *pcVar30 = '<';
              }
              pcVar4 = strcasestr(param_1,(char *)(DAT_0005cc04 + 0x5c6f0));
              if ((pcVar4 != (char *)0x0) &&
                 (pcVar4 = strcasestr(pcVar4,(char *)(DAT_0005cc08 + 0x5c704)),
                 pcVar4 != (char *)0x0)) {
                pcVar30 = strcasestr(param_1,(char *)(DAT_0005cc0c + 0x5c720));
                if (pcVar30 != (char *)0x0) {
                  *pcVar30 = '\0';
                  local_224 = 0;
                  memset(&local_220,0,0x7c);
                  FUN_0004c3f0(pcVar4 + 1,&local_224);
                  iVar19 = acosNvramConfig_match(DAT_0005cc10 + 0x5c768,&local_224);
                  *pcVar30 = '<';
                  if (iVar31 != 0 && iVar19 != 0) {
                    FUN_00050038(&local_378,param_3.s_addr,0);
                    local_444 = (char *)FUN_00050420(&local_378,param_3.s_addr);
                    if ((int)local_444 < 1) {
                      local_444 = (char *)0x1f7;
                    }
                    goto LAB_0005a218;
                  }
                }
              }
              local_444 = (char *)0x191;
              FUN_00050038(&local_378,param_3.s_addr,1);
            }
            else if (local_41c == 199) {
              pcVar4 = strcasestr(param_1,(char *)(DAT_0005cbec + 0x5c5d4));
              if (pcVar4 == (char *)0x0) {
                local_444 = (char *)0x0;
              }
              else {
                pcVar30 = strchr(pcVar4,0xd);
                iVar31 = DAT_0005cbf0;
                if (pcVar30 == (char *)0x0) {
                  local_444 = (char *)0x0;
                }
                else {
                  *pcVar30 = '\0';
                  pcVar4 = strstr(pcVar4,(char *)(iVar31 + 0x5c614));
                  if (pcVar4 != (char *)0x0) {
                    pcVar4 = pcVar4 + 8;
                    pcVar6 = strchr(pcVar4,0x3b);
                    if (pcVar6 == (char *)0x0) {
                      FUN_000502f4(pcVar4,&local_378,param_3.s_addr);
                    }
                    else {
                      *pcVar6 = '\0';
                      FUN_000502f4(pcVar4,&local_378,param_3.s_addr);
                      *pcVar6 = ';';
                    }
                  }
                  *pcVar30 = '\r';
                  local_444 = (char *)0x0;
                }
              }
            }
            else if ((local_41c == 0xbb) &&
                    ((local_430 = FUN_0003f5d8(param_1,param_4), local_430 != 0 ||
                     ((**(int **)(iVar39 + DAT_0005cd68) == 0 &&
                      (local_430 = FUN_0004fd1c(1), local_430 != 0)))))) goto LAB_0005a770;
LAB_0005a218:
            iVar31 = local_41c;
            FUN_0001ab94(2,DAT_0005a988 + 0x5a23c,DAT_0005a984 + 0x5b038,iVar34,local_41c);
            switch(iVar34) {
            case 0:
              if (iVar31 == 0) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdac);
              }
              else if (iVar31 == 0x12) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cda8);
              }
              else if (iVar31 == 0x13) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cda4);
              }
              else if (iVar31 == 0x97) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cda0);
              }
              else if (iVar31 == 0xa2) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd9c);
              }
              else if (iVar31 == 0x14) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd98);
              }
              else if (iVar31 == 0xaf) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd94);
              }
              else if (iVar31 == 0xae) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd8c);
              }
              else {
                pcVar30 = (char *)0x0;
              }
              break;
            case 1:
              if (iVar31 == 0) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cddc);
              }
              else if (iVar31 == 0x1f) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdd8);
              }
              else if (iVar31 == 0x21) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdd4);
              }
              else if (iVar31 == 0x1e) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdd0);
              }
              else if (iVar31 == 0x1d) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdcc);
              }
              else if (iVar31 == 0x54) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdc8);
              }
              else if (iVar31 == 0x55) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdc4);
              }
              else if (iVar31 == 0x56) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdc0);
              }
              else if (iVar31 == 0x57) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdec);
              }
              else if (iVar31 == 0x58) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cde8);
              }
              else if (iVar31 == 0x78) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cde4);
              }
              else if (iVar31 == 0x7a) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cde0);
              }
              else if (iVar31 == 0x7b) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdf4);
              }
              else if (iVar31 == 0xa4) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdf0);
              }
              else if (iVar31 == 0xa9) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdf8);
              }
              else if (iVar31 == 0xa5) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc44);
              }
              else if (iVar31 == 0x9a) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc34);
              }
              else if (iVar31 == 0x5e) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc30);
              }
              else if (iVar31 == 0x5f) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc38);
              }
              else if (iVar31 == 0xc4) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc2c);
              }
              else if (iVar31 == 199) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc20);
              }
              else if (iVar31 == 0xc2) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc1c);
              }
              else if (iVar31 == 0x99) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cbe8);
              }
              else {
                pcVar30 = (char *)0x0;
              }
              break;
            case 2:
              if (iVar31 == 3) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd60);
              }
              else if (iVar31 == 4) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd5c);
              }
              else if (iVar31 == 5) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd58);
              }
              else if (iVar31 == 0) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd54);
              }
              else if (iVar31 == 0x22) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd50);
              }
              else if (iVar31 == 0x95) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd4c);
              }
              else if (iVar31 == 0x74) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd14);
              }
              else {
                pcVar30 = (char *)0x0;
              }
              break;
            case 3:
              if (iVar31 == 6) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd10);
              }
              else {
                pcVar30 = (char *)0x0;
              }
              break;
            case 4:
              if (iVar31 == 0) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd18);
              }
              else {
                pcVar30 = (char *)0x0;
              }
              break;
            case 5:
              if (iVar31 == 0) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccc0);
              }
              else if (iVar31 == 1) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccbc);
              }
              else if (iVar31 == 2) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd90);
              }
              else if (iVar31 == 7) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccb8);
              }
              else if (iVar31 == 8) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccb4);
              }
              else if (iVar31 == 9) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccb0);
              }
              else if (iVar31 == 10) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccac);
              }
              else if (iVar31 == 0xb) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cca8);
              }
              else if (iVar31 == 0xc) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cca4);
              }
              else if (iVar31 == 0xd) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cca0);
              }
              else if (iVar31 == 0xe) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc9c);
              }
              else if (iVar31 == 0xf) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc98);
              }
              else if (iVar31 == 0x10) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc94);
              }
              else if (iVar31 == 0x11) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc90);
              }
              else if (iVar31 == 0x20) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc8c);
              }
              else if (iVar31 == 0x4f) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc88);
              }
              else if (iVar31 == 0x8b) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc84);
              }
              else if (iVar31 == 0x8c) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc80);
              }
              else if (iVar31 == 0x93) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc7c);
              }
              else if (iVar31 == 0x94) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc78);
              }
              else if (iVar31 == 0x50) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc74);
              }
              else if (iVar31 == 0x9b) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc70);
              }
              else if (iVar31 == 0x9d) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc6c);
              }
              else if (iVar31 == 0x9e) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc68);
              }
              else if (iVar31 == 0x9f) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc64);
              }
              else if (iVar31 == 0xa0) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc60);
              }
              else if (iVar31 == 0xa1) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc5c);
              }
              else if (iVar31 == 0x9c) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc58);
              }
              else if (iVar31 == 0x61) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc54);
              }
              else if (iVar31 == 0x62) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc50);
              }
              else if (iVar31 == 99) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc4c);
              }
              else if (iVar31 == 0x6e) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cc48);
              }
              else if (iVar31 == 0x6f) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdbc);
              }
              else if (iVar31 == 0x70) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdb8);
              }
              else if (iVar31 == 0x71) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdb4);
              }
              else if (iVar31 == 0x72) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cdb0);
              }
              else if (iVar31 == 0x73) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd90);
              }
              else if (iVar31 == 100) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cbe4);
              }
              else {
                pcVar30 = (char *)0x0;
              }
              break;
            case 6:
            default:
              pcVar30 = (char *)0x0;
              break;
            case 7:
              if (iVar31 == 0x47) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccdc);
              }
              else if (iVar31 == 0x48) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccd8);
              }
              else if (iVar31 == 0x49) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccd4);
              }
              else if (iVar31 == 0x4a) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccd0);
              }
              else if (iVar31 == 0x4b) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cccc);
              }
              else if (iVar31 == 0x4c) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccc8);
              }
              else if (iVar31 == 0x4d) {
                pcVar30 = *(char **)(iVar39 + DAT_0005ccc4);
              }
              else {
                pcVar30 = (char *)0x0;
              }
              break;
            case 8:
              if (iVar31 == 0xbe) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd04);
              }
              else if (iVar31 == 0xc0) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cce0);
              }
              else {
                pcVar30 = (char *)0x0;
              }
              break;
            case 9:
              if (iVar31 == 0xb1) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd88);
              }
              else if (iVar31 == 0xb4) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd84);
              }
              else if (iVar31 == 0xbb) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd80);
              }
              else if (iVar31 == 0xbc) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd7c);
              }
              else if (iVar31 == 0xb6) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd78);
              }
              else if (iVar31 == 0xb7) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd74);
              }
              else if (iVar31 == 0xb8) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd70);
              }
              else if (iVar31 == 0xb9) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd6c);
              }
              else if (iVar31 == 0xba) {
                pcVar30 = *(char **)(iVar39 + DAT_0005cd64);
              }
              else {
                pcVar30 = (char *)0x0;
              }
            }
            goto LAB_0005a6a0;
          }
        }
LAB_0005a770:
        iVar31 = DAT_0005aa28;
        if (1 < local_430) goto LAB_00059bc0;
        *puVar38 = 0;
        piVar32 = *(int **)(iVar39 + iVar31);
        if (*piVar32 != 0) {
          deviceAccessControlInit();
          iVar31 = open64((char *)(DAT_0005ab2c + 0x5b544),2);
          dnsRedirect_configAccessCtrl();
          close(iVar31);
          iVar31 = acosNvramConfig_match(DAT_0005ab34 + 0x5b568,DAT_0005ab30 + 0x5b564);
          agApi_feature_set(iVar31 == 0);
          system((char *)(DAT_0005ab38 + 0x5b580));
          system((char *)(DAT_0005ab3c + 0x5b58c));
        }
        iVar31 = DAT_0005aa2c;
        *piVar32 = 0;
        piVar32 = *(int **)(iVar39 + iVar31);
        if (*piVar32 != 0) {
          wireless_configure();
          iVar31 = acosNvramConfig_match(DAT_0005ab28 + 0x5b51c,DAT_0005ab24 + 0x5b518);
          if (iVar31 != 0) {
            sleep(10);
          }
        }
        iVar31 = DAT_0005aa30;
        *piVar32 = 0;
        piVar32 = *(int **)(iVar39 + iVar31);
        if ((*piVar32 != 0) || (**(int **)(iVar39 + DAT_0005aa34) != 0)) {
          iVar34 = DAT_0005aa38 + 0x5a7f0;
          iVar31 = acosNvramConfig_match(iVar34,DAT_0005aa3c + 0x5a7f4);
          if (iVar31 == 0) {
            iVar31 = acosNvramConfig_match(iVar34,DAT_0005aaf4 + 0x5b2c8);
            if (iVar31 != 0) {
              iVar31 = DAT_0005aaf8 + 0x5b2dc;
              pcVar4 = (char *)acosNvramConfig_get(iVar31);
              if (((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) &&
                 ((pcVar30 = (char *)acosNvramConfig_get(DAT_0005aafc + 0x5b300),
                  pcVar30 != (char *)0x0 &&
                  ((((*pcVar30 != '\0' &&
                     (pcVar6 = (char *)acosNvramConfig_get(DAT_0005ab00 + 0x5b320),
                     pcVar6 != (char *)0x0)) && (*pcVar6 != '\0')) &&
                   ((pcVar8 = (char *)acosNvramConfig_get(iVar31), pcVar8 != (char *)0x0 &&
                    (*pcVar8 != '\0')))))))) {
                iVar10 = inet_addr(pcVar4);
                iVar11 = inet_addr(pcVar8);
                iVar12 = inet_addr(pcVar30);
                iVar13 = inet_addr(pcVar4);
                iVar14 = inet_addr(pcVar8);
                iVar15 = inet_addr(pcVar6);
                if (((iVar10 << 0x18 | (iVar10 >> 8 & 0xff) << 0x10 | (iVar10 >> 0x10 & 0xff) << 8 |
                     iVar10 >> 0x18) &
                     (iVar11 << 0x18 | (iVar11 >> 8 & 0xff) << 0x10 | (iVar11 >> 0x10 & 0xff) << 8 |
                     iVar11 >> 0x18) &
                    (iVar12 << 0x18 | (iVar12 >> 8 & 0xff) << 0x10 | (iVar12 >> 0x10 & 0xff) << 8 |
                    iVar12 >> 0x18)) ==
                    ((iVar13 << 0x18 | (iVar13 >> 8 & 0xff) << 0x10 | (iVar13 >> 0x10 & 0xff) << 8 |
                     iVar13 >> 0x18) &
                     (iVar14 << 0x18 | (iVar14 >> 8 & 0xff) << 0x10 | (iVar14 >> 0x10 & 0xff) << 8 |
                     iVar14 >> 0x18) &
                    (iVar15 << 0x18 | (iVar15 >> 8 & 0xff) << 0x10 | (iVar15 >> 0x10 & 0xff) << 8 |
                    iVar15 >> 0x18))) {
                  abLanIpWorkaround(pcVar30);
                  acosNvramConfig_set(DAT_0005ab08 + 0x5b3cc,DAT_0005ab04 + 0x5b3c8);
                  acosNvramConfig_save();
                }
              }
              goto LAB_0005a800;
            }
            iVar31 = acosNvramConfig_match(iVar34,DAT_0005ab0c + 0x5b3e8);
            if (iVar31 != 0) {
              iVar31 = DAT_0005ab10 + 0x5b3fc;
              pcVar4 = (char *)acosNvramConfig_get(iVar31);
              if (((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) &&
                 (((pcVar30 = (char *)acosNvramConfig_get(DAT_0005ab14 + 0x5b420),
                   pcVar30 != (char *)0x0 &&
                   (((*pcVar30 != '\0' &&
                     (pcVar6 = (char *)acosNvramConfig_get(DAT_0005ab18 + 0x5b440),
                     pcVar6 != (char *)0x0)) && (*pcVar6 != '\0')))) &&
                  ((pcVar8 = (char *)acosNvramConfig_get(iVar31), pcVar8 != (char *)0x0 &&
                   (*pcVar8 != '\0')))))) {
                iVar10 = inet_addr(pcVar4);
                iVar11 = inet_addr(pcVar8);
                iVar12 = inet_addr(pcVar30);
                iVar13 = inet_addr(pcVar4);
                iVar14 = inet_addr(pcVar8);
                iVar15 = inet_addr(pcVar6);
                if (((iVar10 << 0x18 | (iVar10 >> 8 & 0xff) << 0x10 | (iVar10 >> 0x10 & 0xff) << 8 |
                     iVar10 >> 0x18) &
                     (iVar11 << 0x18 | (iVar11 >> 8 & 0xff) << 0x10 | (iVar11 >> 0x10 & 0xff) << 8 |
                     iVar11 >> 0x18) &
                    (iVar12 << 0x18 | (iVar12 >> 8 & 0xff) << 0x10 | (iVar12 >> 0x10 & 0xff) << 8 |
                    iVar12 >> 0x18)) ==
                    ((iVar13 << 0x18 | (iVar13 >> 8 & 0xff) << 0x10 | (iVar13 >> 0x10 & 0xff) << 8 |
                     iVar13 >> 0x18) &
                     (iVar14 << 0x18 | (iVar14 >> 8 & 0xff) << 0x10 | (iVar14 >> 0x10 & 0xff) << 8 |
                     iVar14 >> 0x18) &
                    (iVar15 << 0x18 | (iVar15 >> 8 & 0xff) << 0x10 | (iVar15 >> 0x10 & 0xff) << 8 |
                    iVar15 >> 0x18))) {
                  abLanIpWorkaround(pcVar30);
                  acosNvramConfig_set(DAT_0005ab20 + 0x5b4ec,DAT_0005ab1c + 0x5b4e8);
                  acosNvramConfig_save();
                }
              }
              goto LAB_0005a800;
            }
          }
          else {
LAB_0005a800:
            system((char *)(DAT_0005aa40 + 0x5a80c));
            wait_for_ppp_to_terminate();
            sleep(1);
          }
          close(param_2);
          sleep(3);
          abDisableLanEthernetPort();
          system((char *)(DAT_0005aa44 + 0x5a838));
        }
        *piVar32 = 0;
        local_448 = 0;
        goto LAB_00059bd8;
      }
    }
LAB_00059d10:
    local_430 = 0x191;
  }
LAB_00059bc0:
  local_448 = FUN_0004b6b8(0x20000,*(undefined4 *)(iVar39 + DAT_0005a90c),param_2,local_430);
LAB_00059bd8:
  if (local_24 != *piVar23) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_448);
  }
  return;
}


===== TARGET SOAPLogin =====

===== TARGET Authenticate =====

===== TARGET GetInfo =====

===== FUNCTION FUN_00040758 @ 00040758 =====

void FUN_00040758(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  iVar1 = DAT_0004083c + 0x4076c;
  piVar5 = *(int **)(iVar1 + DAT_00040840);
  iVar3 = *piVar5;
  if (param_1 < 0xff00) {
    iVar2 = 0;
    do {
      if (param_1 == *(int *)(*(int *)(iVar1 + DAT_00040848) + iVar2 * 8)) {
        uVar6 = *(undefined4 *)(*(int *)(iVar1 + DAT_00040848) + iVar2 * 8 + 4);
        goto LAB_000407f4;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 200);
  }
  else {
    iVar4 = 0;
    iVar2 = 0;
    do {
      if (param_1 == *(int *)(*(int *)(iVar1 + DAT_00040844) + iVar4)) {
        uVar6 = *(undefined4 *)(*(int *)(iVar1 + DAT_00040844) + iVar2 * 0xc + 4);
        goto LAB_000407f4;
      }
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0xc;
    } while (iVar2 != 0xcd);
  }
  uVar6 = 0;
LAB_000407f4:
  FUN_0001ab94(3,DAT_00040850 + 0x40814,DAT_0004084c + 0x409a4,uVar6);
  if (iVar3 == *piVar5) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar6);
}


===== TARGET SetOOKLASpeedTestStart =====

===== TARGET CheckNewFirmware =====

===== TARGET UpdateNewFirmware =====

===== TARGET SetFirmware =====

===== TARGET NewNTPServer1 =====

===== TARGET RouterPassword =====
