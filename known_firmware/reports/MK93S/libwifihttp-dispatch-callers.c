
===== TARGET 0002f230 =====
REF depth=0 from=0003303c to=0002f230
REF depth=0 from=00033914 to=0002f230
REF depth=0 from=00033e44 to=0002f230

===== FUNCTION copy_wl_index_to_unindex @ 00032cac =====

undefined4 copy_wl_index_to_unindex(FILE *param_1)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  size_t sVar8;
  size_t sVar9;
  undefined4 uVar10;
  int iVar11;
  char *pcVar12;
  uint __fd;
  ssize_t sVar13;
  int iVar14;
  undefined4 *puVar15;
  uint *__s;
  undefined4 *puVar16;
  uint *puVar17;
  char *in_stack_00000004;
  int local_32c;
  undefined4 *local_328;
  undefined4 local_320;
  socklen_t local_31c;
  undefined4 local_318;
  undefined1 local_314;
  timeval local_310;
  undefined4 local_308;
  undefined4 uStack_304;
  undefined4 uStack_300;
  undefined2 local_2fc;
  sockaddr local_2f8;
  char acStack_2e8 [60];
  undefined4 uStack_2ac;
  sockaddr local_2a8 [7];
  undefined4 uStack_22c;
  uint auStack_228 [127];
  undefined1 local_29;
  
  local_308 = *(undefined4 *)(DAT_000333d8 + 0x32cc8);
  uStack_304 = *(undefined4 *)(DAT_000333d8 + 0x32ccc);
  uStack_300 = *(undefined4 *)(DAT_000333d8 + 0x32cd0);
  local_320 = 0;
  local_318 = *(undefined4 *)(DAT_000333dc + 0x338fc);
  local_2fc = (undefined2)*(undefined4 *)(DAT_000333d8 + 0x32cd4);
  local_314 = (undefined1)*(undefined4 *)(DAT_000333dc + 0x33900);
  pcVar2 = (char *)get_cgi(DAT_000333e0 + 0x32d00);
  iVar14 = DAT_000333e4 + 0x32d10;
  if (pcVar2 == (char *)0x0) {
    local_32c = 0;
  }
  else {
    local_32c = strcmp(pcVar2,(char *)(DAT_000333e8 + 0x32d20));
    if (local_32c != 0) {
      pcVar2 = (char *)get_cgi(DAT_00033424 + 0x32fe4);
      if (pcVar2 != (char *)0x0) {
        pcVar3 = (char *)get_cgi(DAT_00033428 + 0x32ff8);
        pcVar12 = pcVar2;
        if ((pcVar3 != (char *)0x0) && (lVar4 = strtol(pcVar3,(char **)0x0,10), lVar4 != 0)) {
          pcVar12 = acStack_2e8;
          snprintf(pcVar12,0x40,(char *)(DAT_00033464 + 0x33368),pcVar2,pcVar3);
        }
        pcVar2 = (char *)nvram_get(DAT_0003342c + 0x33020);
        if (pcVar2 == (char *)0x0) {
          pcVar2 = (char *)(DAT_00033460 + 0x33348);
        }
        iVar5 = strcmp(pcVar2,pcVar12);
        if (iVar5 == 0) goto LAB_00033038;
      }
      local_32c = 1;
    }
  }
  pcVar2 = (char *)get_cgi(DAT_000333ec + 0x32d38);
  if (pcVar2 == (char *)0x0) {
    iVar5 = strcmp(in_stack_00000004,(char *)(DAT_000333f8 + 0x32dd8));
    if (iVar5 == 0) {
      local_29 = 0;
      iVar6 = FUN_0001e08c();
      if (iVar6 != 0) {
        __fd = socket(2,2,0x11);
        if ((int)__fd < 0) {
          fwrite((void *)(DAT_00033470 + 0x333ac),1,0x2f,
                 (FILE *)**(undefined4 **)(iVar14 + DAT_0003346c));
        }
        else {
          local_2a8[0].sa_family = 2;
          local_2a8[0].sa_data[0] = -0x62;
          local_2a8[0].sa_data[1] = '4';
          local_2a8[0].sa_data[2] = '\x7f';
          local_2a8[0].sa_data[3] = '\0';
          local_2a8[0].sa_data[4] = '\0';
          local_2a8[0].sa_data[5] = '\x01';
          local_2a8[0].sa_data._6_4_ = iVar5;
          local_2a8[0].sa_data._10_4_ = iVar5;
          sVar13 = sendto(__fd,(void *)(DAT_00033448 + 0x3320c),4,0,local_2a8,0x10);
          if (sVar13 < 0) {
            perror((char *)(DAT_0003345c + 0x332f4));
          }
          else {
            usleep(100000);
            puVar15 = &uStack_2ac;
            local_31c = 0x10;
            local_310.tv_sec = 2;
            do {
              puVar15 = puVar15 + 1;
              *puVar15 = 0;
            } while (puVar15 != &uStack_22c);
            iVar6 = ((int)__fd >> 5) * 4;
            uVar1 = 1 << (__fd & 0x1f);
            *(uint *)(local_2a8[0].sa_data + iVar6 + -2) =
                 *(uint *)(local_2a8[0].sa_data + iVar6 + -2) | uVar1;
            local_310.tv_usec = iVar5;
            iVar5 = select(__fd + 1,(fd_set *)local_2a8,(fd_set *)0x0,(fd_set *)0x0,&local_310);
            if ((0 < iVar5) && ((uVar1 & *(uint *)(local_2a8[0].sa_data + iVar6 + -2)) != 0)) {
              sVar13 = recvfrom(__fd,auStack_228,0x1ff,0,&local_2f8,&local_31c);
              if (sVar13 == -1) {
                fprintf((FILE *)**(undefined4 **)(iVar14 + DAT_0003346c),
                        (char *)(DAT_00033474 + 0x333d0),0xffffffff);
              }
              else if (0 < sVar13) {
                parse_wps_env(auStack_228);
              }
            }
          }
          close(__fd);
        }
      }
      goto LAB_00032da8;
    }
    iVar5 = nvram_get(DAT_000333fc + 0x32dec);
    if (iVar5 == 0) {
      iVar5 = DAT_0003344c + 0x332c4;
    }
    iVar6 = nvram_get(DAT_00033400 + 0x32e00);
    if (iVar6 == 0) {
      iVar6 = DAT_00033458 + 0x332e8;
    }
    iVar11 = nvram_get(DAT_00033404 + 0x32e14);
    if (iVar11 == 0) {
      iVar11 = DAT_00033454 + 0x332dc;
    }
    iVar7 = nvram_get(DAT_00033408 + 0x32e28);
    if (iVar7 == 0) {
      iVar7 = DAT_00033450 + 0x332d0;
    }
    snprintf((char *)auStack_228,0x100,(char *)(DAT_0003340c + 0x32e50),iVar5,iVar6,iVar11,iVar7);
    iVar5 = remove_dups(auStack_228,0x100);
    if (iVar5 == 0) {
      fwrite((void *)(DAT_00033468 + 0x33384),1,0x3a,param_1);
      return 0xffffffff;
    }
    pcVar2 = (char *)(DAT_00033410 + 0x32e80);
    sVar8 = strspn((char *)auStack_228,pcVar2);
    local_2f8._0_4_ = *(uint *)((int)auStack_228 + sVar8);
    local_2f8.sa_data._6_4_ = *(uint *)((int)auStack_228 + sVar8 + 8);
    local_2f8.sa_data._10_4_ = *(uint *)((int)auStack_228 + sVar8 + 0xc);
    local_2f8.sa_data._2_4_ = *(uint *)((int)auStack_228 + sVar8 + 4);
    sVar9 = strcspn((char *)&local_2f8,pcVar2);
    local_2f8.sa_data[sVar9 - 2] = '\0';
    local_2f8.sa_data._10_4_ = local_2f8.sa_data._10_4_ & 0xffffff;
    pcVar2 = strchr((char *)((int)auStack_228 + sVar8),0x20);
    if ((local_2f8._0_4_ & 0xff) != 0) {
      puVar17 = (uint *)(DAT_00033414 + 0x32ef4);
      pcVar3 = (char *)(DAT_00033418 + 0x32ef8);
      pcVar12 = (char *)(DAT_0003341c + 0x32efc);
      do {
        iVar5 = nvifname_to_osifname(&local_2f8,local_2a8,0x10);
        if (((-1 < iVar5) && (iVar5 = wl_probe(local_2a8), iVar5 == 0)) &&
           (iVar5 = wl_ioctl(local_2a8,0xe,&local_320,4), iVar5 == 0)) {
          snprintf((char *)&local_318,5,(char *)(DAT_00033420 + 0x32fd4),local_320);
          break;
        }
        __s = puVar17;
        if (pcVar2 != (char *)0x0) {
          sVar8 = strspn(pcVar2,pcVar3);
          __s = (uint *)(pcVar2 + sVar8);
        }
        local_2f8.sa_data._6_4_ = __s[2];
        local_2f8.sa_data._10_4_ = __s[3];
        local_2f8._0_4_ = *__s;
        local_2f8.sa_data._2_4_ = __s[1];
        sVar8 = strcspn((char *)&local_2f8,pcVar12);
        local_2f8.sa_data[sVar8 - 2] = '\0';
        local_2f8.sa_data._10_4_ = local_2f8.sa_data._10_4_ & 0xffffff;
        pcVar2 = strchr((char *)__s,0x20);
      } while ((local_2f8._0_4_ & 0xff) != 0);
    }
  }
  else {
    pcVar3 = (char *)get_cgi(DAT_000333f0 + 0x32d4c);
    pcVar12 = pcVar2;
    if ((pcVar3 != (char *)0x0) && (lVar4 = strtol(pcVar3,(char **)0x0,10), lVar4 != 0)) {
      pcVar12 = acStack_2e8;
      snprintf(pcVar12,0x40,(char *)(DAT_00033444 + 0x331a4),pcVar2,pcVar3);
    }
    strncpy((char *)&local_318,pcVar12,4);
  }
  iVar6 = DAT_00033438;
  iVar5 = DAT_00033434;
  local_328 = &local_318;
  if ((char)local_318 != '\0') {
    snprintf((char *)&local_308,0xe,(char *)(DAT_00033430 + 0x33070),local_328);
    puVar16 = *(undefined4 **)(iVar14 + DAT_0003343c);
    iVar14 = DAT_00033440 + 0x33098;
    puVar15 = puVar16;
    do {
      if (((puVar15[6] & 0x200000) == 0) &&
         ((local_308._3_1_ != '.' || ((puVar15[6] & 0x400000) == 0)))) {
        pcVar2 = (char *)*puVar15;
        iVar11 = strncmp(pcVar2,(char *)(iVar5 + 0x33080),7);
        if (iVar11 != 0) {
          if (((*pcVar2 == 'w') && (pcVar2[1] == 'l')) && (pcVar2[2] == '_')) {
            pcVar12 = stpcpy((char *)auStack_228,(char *)&local_308);
            strcpy(pcVar12,pcVar2 + 3);
            iVar11 = nvram_get(auStack_228);
            if ((iVar11 == 0) && (iVar11 = nvram_default_get(auStack_228), iVar11 == 0)) {
              iVar11 = iVar14;
            }
            nvram_set(*puVar15,iVar11);
            pcVar2 = (char *)*puVar15;
          }
          iVar11 = strncmp(pcVar2,(char *)(iVar6 + 0x33088),7);
          if (iVar11 == 0) break;
        }
      }
      puVar15 = puVar15 + 7;
    } while (puVar15 != puVar16 + 0x6ac);
  }
  nvram_set(DAT_000333f4 + 0x32d9c,local_328);
  if (local_32c != 0) {
LAB_00033038:
    uVar10 = FUN_0002f230(param_1);
    return uVar10;
  }
LAB_00032da8:
  do_ej(in_stack_00000004,param_1);
  fflush(param_1);
  return 1;
}


===== FUNCTION FUN_00033994 @ 00033994 =====

void FUN_00033994(char *param_1,FILE *param_2)

{
  char cVar1;
  undefined2 uVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  char *local_b0;
  undefined4 local_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined2 uStack_a0;
  undefined1 local_9e;
  char acStack_9c [16];
  char acStack_8c [104];
  
  local_b0 = (char *)0x0;
  iVar12 = DAT_00033f88 + 0x339b4;
  if (param_2 == (FILE *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail((char *)(DAT_0003404c + 0x33f84),(char *)(DAT_00034048 + 0x33f80),0x33f2,
                  (char *)(DAT_00034044 + 0x34c00));
  }
  if (param_1 == (char *)0x0) {
                    /* WARNING: Subroutine does not return */
    __assert_fail((char *)(DAT_00034040 + 0x33f5c),(char *)(DAT_0003403c + 0x33f58),0x33f3,
                  (char *)(DAT_00034038 + 0x34bd8));
  }
  local_b0 = param_1;
  pcVar3 = strsep(&local_b0,(char *)(DAT_00033f8c + 0x339d8));
  if (pcVar3 == (char *)0x0) {
    pcVar3 = param_1;
  }
  local_ac = *(undefined4 *)(DAT_00033f90 + 0x339f4);
  uStack_a8 = *(undefined4 *)(DAT_00033f90 + 0x339f8);
  uStack_a4 = *(undefined4 *)(DAT_00033f90 + 0x339fc);
  uStack_a0 = (undefined2)*(undefined4 *)(DAT_00033f90 + 0x33a00);
  local_9e = (undefined1)((uint)*(undefined4 *)(DAT_00033f90 + 0x33a00) >> 0x10);
  pcVar4 = (char *)get_cgi(DAT_00033f94 + 0x33a0c);
  if (pcVar4 == (char *)0x0) {
    iVar10 = DAT_00034008 + 0x33e0c;
    pcVar4 = (char *)get_cgi(iVar10);
    if (pcVar4 != (char *)0x0) goto LAB_00033cdc;
    pcVar4 = (char *)nvram_get(iVar10);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = (char *)(DAT_00034018 + 0x33e88);
    }
    uVar11 = strtol(pcVar4,(char **)0x0,10);
joined_r0x00033ca0:
    if (0xff < uVar11) goto LAB_00033ca4;
  }
  else {
    iVar5 = strcmp(pcVar4,(char *)(DAT_00033f98 + 0x33a24));
    iVar10 = DAT_00033fa0;
    if (iVar5 == 0) {
      pcVar4 = (char *)(DAT_00033f9c + 0x33a40);
      puVar13 = (undefined4 *)(DAT_00033fa0 + 0x33a44);
      uVar11 = 0;
LAB_00033a50:
      snprintf((char *)&local_ac,0xf,pcVar4,uVar11);
      pcVar6 = stpcpy(acStack_8c,(char *)&local_ac);
      uVar7 = *puVar13;
      pcVar6[4] = *(char *)(iVar10 + 0x33a48);
      *(undefined4 *)pcVar6 = uVar7;
      iVar5 = nvram_get(acStack_8c);
      if (iVar5 != 0) goto LAB_00033a44;
      puVar13 = *(undefined4 **)(iVar12 + DAT_00033fa4);
      pcVar6 = (char *)(DAT_00033fa8 + 0x33aa8);
      pcVar4 = (char *)*puVar13;
      while (pcVar4 != (char *)0x0) {
        iVar10 = strncmp(pcVar4,pcVar6,4);
        if (iVar10 == 0) {
          pcVar9 = stpcpy(acStack_8c,(char *)&local_ac);
          strcpy(pcVar9,pcVar4 + 4);
          nvram_set(acStack_8c,puVar13[1]);
          pcVar4 = (char *)puVar13[3];
        }
        else {
          pcVar4 = (char *)puVar13[3];
        }
        puVar13 = puVar13 + 3;
      }
      snprintf(acStack_9c,0x10,(char *)(DAT_00033fac + 0x33b20),uVar11);
      pcVar4 = stpcpy(acStack_8c,(char *)&local_ac);
      cVar1 = *(char *)(DAT_00033fb0 + 0x33b44);
      *(undefined4 *)pcVar4 = *(undefined4 *)(DAT_00033fb0 + 0x33b40);
      pcVar4[4] = cVar1;
      nvram_set(acStack_8c,acStack_9c);
      pcVar4 = stpcpy(acStack_8c,(char *)&local_ac);
      iVar10 = DAT_00033fb8 + 0x33b7c;
      uVar2 = *(undefined2 *)(DAT_00033fb4 + 0x33b78);
      *(undefined4 *)pcVar4 = *(undefined4 *)(DAT_00033fb4 + 0x33b74);
      *(undefined2 *)(pcVar4 + 4) = uVar2;
      nvram_set(acStack_8c,iVar10);
      pcVar4 = stpcpy(acStack_8c,(char *)&local_ac);
      uVar2 = *(undefined2 *)(DAT_00033fbc + 0x33bac);
      cVar1 = *(char *)(DAT_00033fbc + 0x33bae);
      *(undefined4 *)pcVar4 = *(undefined4 *)(DAT_00033fbc + 0x33ba8);
      iVar10 = DAT_00033fc0;
      *(undefined2 *)(pcVar4 + 4) = uVar2;
      pcVar4[6] = cVar1;
      iVar10 = nvram_get(iVar10 + 0x33bc8);
      if (iVar10 == 0) {
        iVar10 = DAT_00034010 + 0x33e70;
      }
      nvram_set(acStack_8c,iVar10);
      pcVar4 = stpcpy(acStack_8c,(char *)&local_ac);
      uVar2 = *(undefined2 *)(DAT_00033fc4 + 0x33bf8);
      cVar1 = *(char *)(DAT_00033fc4 + 0x33bfa);
      *(undefined4 *)pcVar4 = *(undefined4 *)(DAT_00033fc4 + 0x33bf4);
      iVar10 = DAT_00033fc8;
      *(undefined2 *)(pcVar4 + 4) = uVar2;
      pcVar4[6] = cVar1;
      iVar10 = nvram_get(iVar10 + 0x33c14);
      if (iVar10 == 0) {
        iVar10 = DAT_0003400c + 0x33e64;
      }
      nvram_set(acStack_8c,iVar10);
      pcVar4 = stpcpy(acStack_8c,(char *)&local_ac);
      uVar7 = *(undefined4 *)(DAT_00033fcc + 0x33c44);
      iVar5 = DAT_00033fcc + 0x33c48;
      *(undefined4 *)pcVar4 = *(undefined4 *)(DAT_00033fcc + 0x33c40);
      iVar10 = DAT_00033fd0;
      *(undefined4 *)(pcVar4 + 4) = uVar7;
      iVar10 = nvram_get(iVar10 + 0x33c54,uVar7,iVar5);
      if (iVar10 == 0) {
        iVar10 = DAT_00034014 + 0x33e7c;
      }
      nvram_set(acStack_8c,iVar10);
      nvram_set(DAT_00033fd8 + 0x33c78,DAT_00033fd4 + 0x33c74);
      nvram_set(DAT_00033fe0 + 0x33c8c,DAT_00033fdc + 0x33c88);
      **(undefined1 **)(iVar12 + DAT_00033fe4) = 1;
      goto joined_r0x00033ca0;
    }
    iVar10 = strcmp(pcVar4,(char *)(DAT_00033fe8 + 0x33cbc));
    if (iVar10 != 0) {
      FUN_0002f230(param_2);
      init_cgi(0);
      return;
    }
    pcVar4 = (char *)get_cgi(DAT_00033fec + 0x33cd0);
    if (pcVar4 != (char *)0x0) {
LAB_00033cdc:
      uVar11 = strtol(pcVar4,(char **)0x0,10);
      goto joined_r0x00033ca0;
    }
LAB_00033ca4:
    uVar11 = 0;
  }
  iVar10 = DAT_00033ff4;
  snprintf((char *)&local_ac,0xf,(char *)(DAT_00033ff0 + 0x33d14),uVar11);
  pcVar4 = (char *)(DAT_00033ff8 + 0x33d28);
  iVar12 = *(int *)(iVar12 + DAT_00033ffc);
  iVar5 = iVar12 + 0x1c;
  do {
    if ((*(uint *)(iVar5 + -4) & 0x200000) == 0) {
      pcVar6 = *(char **)(iVar5 + -0x1c);
      iVar8 = strncmp(pcVar6,(char *)(iVar10 + 0x33d20),4);
      if (iVar8 == 0) {
        pcVar9 = stpcpy(acStack_8c,(char *)&local_ac);
        strcpy(pcVar9,pcVar6 + 4);
        iVar8 = nvram_get(acStack_8c);
        if (iVar8 != 0) {
          nvram_set(*(undefined4 *)(iVar5 + -0x1c));
        }
        iVar8 = strncmp(*(char **)(iVar5 + -0x1c),pcVar4,8);
        if (iVar8 == 0) break;
      }
    }
    iVar5 = iVar5 + 0x1c;
  } while (iVar12 + 0x1acc != iVar5);
  snprintf(acStack_8c,100,(char *)(DAT_00034000 + 0x33dcc),uVar11);
  nvram_set(DAT_00034004 + 0x33ddc,acStack_8c);
  do_ej(pcVar3,param_2);
  fflush(param_2);
LAB_00033df0:
  init_cgi(0);
  return;
LAB_00033a44:
  uVar11 = uVar11 + 1;
  if (uVar11 == 0x100) goto LAB_00033e88;
  goto LAB_00033a50;
LAB_00033e88:
  fwrite((void *)(DAT_0003401c + 0x33ea0),1,0x10,param_2);
  fwrite((void *)(DAT_00034020 + 0x33eb8),1,0x301,param_2);
  fflush(param_2);
  fprintf(param_2,(char *)(DAT_00034024 + 0x33ed4),0x100);
  fflush(param_2);
  iVar12 = get_cgi(DAT_00034028 + 0x33ee8);
  if (iVar12 == 0) {
    iVar12 = DAT_00034034 + 0x33f38;
  }
  fprintf(param_2,(char *)(DAT_0003402c + 0x33f00),iVar12);
  fflush(param_2);
  fwrite((void *)(DAT_00034030 + 0x33f20),1,7,param_2);
  fflush(param_2);
  goto LAB_00033df0;
}

