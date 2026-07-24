
===== ENTRY 0001eb44 =====
===== FUNCTION FUN_0001eb44 @ 0001eb44 =====

void FUN_0001eb44(undefined4 param_1,FILE *param_2)

{
  char *__name;
  FILE *pFVar1;
  char *pcVar2;
  int iVar3;
  char local_418 [1028];
  
  if (param_2 != (FILE *)0x0) {
    __name = (char *)nvram_get(DAT_0001ed40 + 0x1eb64);
    iVar3 = DAT_0001ed44;
    if (__name == (char *)0x0) {
      __name = (char *)(DAT_0001ed64 + 0x1ecdc);
    }
    local_418[0] = '\0';
    local_418[1] = '\0';
    local_418[2] = '\0';
    local_418[3] = '\0';
    memset(local_418 + 4,0,0x3fc);
    pFVar1 = popen((char *)(iVar3 + 0x1eb90),(char *)(DAT_0001ed48 + 0x1eb98));
    if (pFVar1 == (FILE *)0x0) {
      pFVar1 = fopen((char *)(DAT_0001ed6c + 0x1ecf0),(char *)(DAT_0001ed68 + 0x1ecec));
      if (pFVar1 != (FILE *)0x0) {
        fwrite((void *)(DAT_0001ed70 + 0x1ed10),1,0x16,pFVar1);
        fclose(pFVar1);
      }
    }
    else {
      fprintf(param_2,(char *)(DAT_0001ed4c + 0x1ebb8),(char *)(iVar3 + 0x1eb90));
      fflush(param_2);
      while (pcVar2 = fgets(local_418,0x3ff,pFVar1), pcVar2 != (char *)0x0) {
        fputs(local_418,param_2);
        fflush(param_2);
      }
      pclose(pFVar1);
    }
    if (*__name == '\0') {
      fprintf(param_2,(char *)(DAT_0001ed54 + 0x1ec1c),DAT_0001ed50 + 0x1ec18);
      fflush(param_2);
    }
    else {
      snprintf(local_418,0x100,(char *)(DAT_0001ed58 + 0x1ec54),__name);
      iVar3 = access(local_418,4);
      if (iVar3 != -1) {
        fprintf(param_2,(char *)(DAT_0001ed5c + 0x1ec7c),local_418);
        fflush(param_2);
        FUN_0001e92c(local_418,param_2);
      }
      iVar3 = access(__name,4);
      if (iVar3 != -1) {
        fprintf(param_2,(char *)(DAT_0001ed60 + 0x1ecb8),__name);
        fflush(param_2);
        FUN_0001e92c(__name,param_2);
      }
    }
    fflush(param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail((char *)((int)&DAT_0001ed40 + DAT_0001ed7c),(char *)(DAT_0001ed78 + 0x1ed38),0x32e2,
                (char *)(DAT_0001ed74 + 0x1ee88));
}


===== ENTRY 0002f230 =====
===== FUNCTION FUN_0002f230 @ 0002f230 =====

undefined4 FUN_0002f230(FILE *param_1)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  long lVar6;
  void *pvVar7;
  int iVar8;
  FILE *pFVar9;
  uint uVar10;
  size_t sVar11;
  int iVar12;
  ushort **ppuVar13;
  int iVar14;
  undefined4 uVar15;
  undefined1 *puVar16;
  byte *pbVar17;
  uint *puVar18;
  int iVar19;
  int *piVar20;
  int *piVar21;
  uint uVar22;
  undefined4 *puVar23;
  int iVar24;
  long local_1290;
  undefined1 auStack_1288 [4];
  uint local_1284;
  uint local_1280;
  undefined1 local_127c;
  undefined4 local_1278;
  undefined4 uStack_1274;
  undefined4 uStack_1270;
  undefined2 local_126c;
  char acStack_1268 [16];
  undefined1 auStack_1258 [16];
  uint local_1248;
  uint local_1244;
  uint local_1240;
  uint local_123c;
  uint local_1238;
  uint local_1234;
  uint local_1230;
  uint local_122c;
  undefined4 local_1228;
  undefined4 local_1224;
  undefined4 local_1220;
  undefined4 local_121c;
  undefined4 local_1218;
  undefined4 local_1214;
  undefined4 local_1210;
  undefined4 local_120c;
  undefined4 local_1128;
  undefined4 local_1124;
  undefined4 uStack_1120;
  undefined2 uStack_111c;
  undefined1 local_111a;
  int local_1028;
  undefined4 local_1024;
  undefined4 local_1020;
  char acStack_1015 [8];
  char acStack_100d [7];
  char acStack_1006 [4066];
  
  *(undefined4 *)(DAT_0003018c + 0x2fd98) = 0;
  iVar19 = DAT_00030194;
  fwrite((void *)(DAT_00030190 + 0x2f26c),1,0x10,param_1);
  iVar19 = iVar19 + 0x2f284;
  fwrite((void *)(DAT_00030198 + 0x2f288),1,0x301,param_1);
  fflush(param_1);
  pcVar3 = (char *)get_cgi(DAT_0003019c + 0x2f29c);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = (char *)(DAT_00030234 + 0x2f7b4);
  }
  pcVar4 = (char *)get_cgi(DAT_000301a0 + 0x2f2b0);
  if (pcVar4 == (char *)0x0) {
    pcVar4 = (char *)(DAT_000301e4 + 0x2f4e8);
LAB_0002f4e4:
    iVar5 = strcmp(pcVar4,(char *)(DAT_000301e8 + 0x2f4f4));
    if (iVar5 == 0) {
      iVar19 = nvram_get(DAT_000302b4 + 0x2fb58);
      if (iVar19 == 0) {
        iVar19 = DAT_00030304 + 0x2fd08;
      }
      iVar8 = DAT_000302b8 + 0x2fb6c;
      iVar5 = get_cgi(iVar8);
      if ((iVar5 == 0) && (iVar5 = nvram_get(iVar8), iVar5 == 0)) {
        iVar5 = DAT_00030324 + 0x2fde8;
      }
      pcVar3 = (char *)get_cgi(DAT_000302bc + 0x2fb84);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)(DAT_00030308 + 0x2fd14);
      }
      else if (*pcVar3 == '\0') {
        pcVar3 = (char *)(DAT_000302c0 + 0x2fba0);
      }
      snprintf((char *)&local_1028,0x1000,(char *)(DAT_000302c4 + 0x2fbbc),iVar5,iVar19,pcVar3,
               iVar19);
      fprintf(param_1,(char *)(DAT_000302c8 + 0x2fbd4),&local_1028);
      fflush(param_1);
                    /* WARNING: Subroutine does not return */
      __assert_fail((char *)(DAT_000302d4 + 0x2fc00),(char *)(DAT_000302d0 + 0x2fbf8),0x14b,
                    (char *)((int)&DAT_00030404 + DAT_000302cc));
    }
    iVar5 = strcmp(pcVar4,(char *)(DAT_000301ec + 0x2f50c));
    if (iVar5 == 0) {
      iVar8 = DAT_000302e8 + 0x2fc60;
      iVar5 = get_cgi(iVar8);
      if ((iVar5 == 0) && (iVar5 = nvram_get(iVar8), iVar5 == 0)) {
        iVar5 = DAT_0003037c + 0x30038;
      }
      fprintf(param_1,(char *)(DAT_000302ec + 0x2fc80),iVar5);
      fflush(param_1);
      local_1020 = 0;
      local_1028 = DAT_000302f0 + 0x2fca4;
      local_1024 = iVar5;
      iVar8 = _eval(&local_1028,DAT_000302f4 + 0x2fcb0,0);
      if (iVar8 == 0) {
        fwrite((void *)(DAT_000302f8 + 0x2fcd4),1,8,param_1);
        fflush(param_1);
        nvram_set(DAT_000302fc + 0x2fcec,iVar5);
      }
      else {
        fwrite((void *)(DAT_00030314 + 0x2fd64),1,9,param_1);
        fflush(param_1);
      }
      goto LAB_0002f800;
    }
    iVar5 = strcmp(pcVar4,(char *)(DAT_000301f0 + 0x2f524));
    if (iVar5 == 0) {
      fwrite((void *)(DAT_000302d8 + 0x2fc18),1,0x13,param_1);
      fflush(param_1);
      FUN_0002dd5c(param_1,1);
      *(undefined4 *)(DAT_000302dc + 0x30780) = 0;
      goto LAB_0002f800;
    }
    iVar5 = strcmp(pcVar4,(char *)(DAT_000301f4 + 0x2f53c));
    if (iVar5 == 0) {
      fwrite((void *)(DAT_0003030c + 0x2fd2c),1,0xb,param_1);
      fflush(param_1);
      FUN_0002dd5c(param_1,0);
      *(undefined4 *)(DAT_00030310 + 0x30894) = 0;
      goto LAB_0002f800;
    }
    iVar5 = strcmp(pcVar4,(char *)(DAT_000301f8 + 0x2f554));
    if (iVar5 == 0) {
      pcVar3 = (char *)get_cgi(DAT_00030318 + 0x2fd7c);
      if ((pcVar3 != (char *)0x0) &&
         (uVar10 = strtol(pcVar3,(char **)0x0,10), iVar5 = DAT_00030388, uVar10 < 0x100)) {
        local_1128 = *(uint *)(DAT_00030380 + 0x30058);
        local_1124 = *(undefined4 *)(DAT_00030380 + 0x3005c);
        uStack_1120 = *(undefined4 *)(DAT_00030380 + 0x30060);
        pcVar3 = (char *)(DAT_00030384 + 0x30064);
        puVar23 = (undefined4 *)(DAT_00030388 + 0x30068);
        uStack_111c = (undefined2)*(undefined4 *)(DAT_00030380 + 0x30064);
        local_111a = (undefined1)((uint)*(undefined4 *)(DAT_00030380 + 0x30064) >> 0x10);
        bVar2 = false;
        iVar8 = 0;
LAB_0003009c:
        snprintf((char *)&local_1128,0xf,pcVar3,iVar8);
        pcVar4 = stpcpy((char *)&local_1028,(char *)&local_1128);
        uVar15 = *puVar23;
        pcVar4[4] = *(char *)(iVar5 + 0x3006c);
        *(undefined4 *)pcVar4 = uVar15;
        iVar12 = nvram_get(&local_1028);
        if (iVar12 != 0) {
          if (bVar2) {
            snprintf((char *)&local_1128,0xf,pcVar3,uVar10);
            iVar8 = DAT_00030390;
            fwrite((void *)(DAT_0003038c + 0x30124),1,0x16,param_1);
            fflush(param_1);
            puVar23 = *(undefined4 **)(iVar19 + DAT_00030394);
            pcVar3 = (char *)*puVar23;
            iVar5 = DAT_000303d0;
            while (DAT_000303d0 = iVar5, pcVar3 != (char *)0x0) {
              iVar5 = strncmp(pcVar3,(char *)(iVar8 + 0x30130),4);
              if (iVar5 == 0) {
                pcVar4 = stpcpy((char *)&local_1028,(char *)&local_1128);
                strcpy(pcVar4,pcVar3 + 4);
                nvram_unset(&local_1028);
              }
              puVar23 = puVar23 + 3;
              iVar5 = DAT_000303d0;
              pcVar3 = (char *)*puVar23;
            }
            pcVar3 = (char *)(DAT_000303cc + 0x30720);
            uVar22 = uVar10;
            do {
              snprintf((char *)&local_1128,0xf,pcVar3,uVar22);
              pcVar4 = stpcpy((char *)&local_1028,(char *)&local_1128);
              uVar15 = *(undefined4 *)(iVar5 + 0x30724);
              pcVar4[4] = *(char *)(iVar5 + 0x30728);
              *(undefined4 *)pcVar4 = uVar15;
              iVar12 = nvram_get(&local_1028);
              iVar8 = DAT_000304cc;
              if (iVar12 != 0) goto LAB_00030774;
              uVar22 = uVar22 + 1;
            } while (uVar22 != 0x100);
            if (uVar10 != 0) {
              puVar23 = (undefined4 *)(DAT_000304cc + 0x30f08);
              uVar22 = uVar10;
              do {
                uVar22 = uVar22 - 1;
                snprintf((char *)&local_1128,0xf,pcVar3,uVar22);
                pcVar4 = stpcpy((char *)&local_1028,(char *)&local_1128);
                uVar15 = *puVar23;
                pcVar4[4] = *(char *)(iVar8 + 0x30f0c);
                *(undefined4 *)pcVar4 = uVar15;
                iVar5 = nvram_get(&local_1028);
                if (iVar5 != 0) goto LAB_00030774;
              } while (uVar22 != 0);
            }
            uVar22 = 0xffffffff;
LAB_00030774:
            iVar12 = DAT_000303dc;
            iVar8 = DAT_000303d8;
            snprintf((char *)&local_1028,100,(char *)(DAT_000303d4 + 0x30790),uVar22);
            iVar14 = DAT_000303e4;
            puVar23 = (undefined4 *)(DAT_000303e4 + 0x307b4);
            nvram_set(DAT_000303e0 + 0x307b0,&local_1028);
            iVar5 = 0;
            do {
              snprintf((char *)&local_1128,0xf,(char *)(iVar8 + 0x307a8),iVar5);
              pcVar3 = stpcpy((char *)&local_1028,(char *)&local_1128);
              uVar15 = *(undefined4 *)(iVar12 + 0x307ac);
              pcVar3[4] = *(char *)(iVar12 + 0x307b0);
              *(undefined4 *)pcVar3 = uVar15;
              iVar24 = nvram_get(&local_1028);
              if (iVar24 != 0) {
                pcVar3 = stpcpy((char *)&local_1028,(char *)&local_1128);
                uVar15 = *puVar23;
                *(undefined2 *)(pcVar3 + 4) = *(undefined2 *)(iVar14 + 0x307b8);
                *(undefined4 *)pcVar3 = uVar15;
                pcVar3 = (char *)nvram_get(&local_1028);
                if ((pcVar3 == (char *)0x0) ||
                   (iVar24 = strcmp(pcVar3,(char *)(DAT_000303e8 + 0x30834)), iVar24 == 0))
                goto LAB_000308f0;
                pcVar3 = stpcpy((char *)&local_1028,(char *)&local_1128);
                uVar15 = *(undefined4 *)(DAT_000303ec + 0x3085c);
                iVar24 = DAT_000303ec + 0x30860;
                *(undefined4 *)pcVar3 = *(undefined4 *)(DAT_000303ec + 0x30858);
                *(undefined4 *)(pcVar3 + 4) = uVar15;
                pcVar3 = (char *)nvram_get(&local_1028,uVar15,iVar24);
                if ((pcVar3 == (char *)0x0) || ((*pcVar3 != '1' || (pcVar3[1] != '\0'))))
                goto LAB_000308f0;
                goto LAB_00030888;
              }
LAB_000308f0:
              iVar5 = iVar5 + 1;
            } while (iVar5 != 0x100);
            FUN_000258f8();
LAB_00030888:
            nvram_set(DAT_000303f4 + 0x3089c,DAT_000303f0 + 0x30898);
            nvram_set(DAT_000303fc + 0x308b0,DAT_000303f8 + 0x308ac);
            iVar5 = DAT_00030400;
            **(undefined1 **)(iVar19 + DAT_00030584) = 1;
            fwrite((void *)(iVar5 + 0x308d4),1,8,param_1);
            fflush(param_1);
            *(undefined4 *)(DAT_00030404 + 0x31434) = 2;
            goto LAB_0002f800;
          }
          bVar2 = true;
        }
        iVar8 = iVar8 + 1;
        if (iVar8 == 0x100) goto LAB_00030c44;
        goto LAB_0003009c;
      }
      fwrite((void *)(DAT_0003031c + 0x2fdb4),1,0x29,param_1);
      fflush(param_1);
      *(undefined4 *)(DAT_00030320 + 0x30914) = 0;
      goto LAB_0002f800;
    }
    uVar10 = strcmp((char *)(DAT_000301fc + 0x2f56c),pcVar3);
    if (uVar10 == 0) {
      local_1028 = *(int *)(DAT_0003032c + 0x30640);
      local_1024 = CONCAT31(local_1024._1_3_,(char)*(undefined4 *)(DAT_0003032c + 0x30644));
      local_127c = 0;
      local_1284 = uVar10;
      local_1280 = uVar10;
      local_1248 = uVar10;
      local_1244 = uVar10;
      local_1240 = uVar10;
      local_123c = uVar10;
      local_1238 = uVar10;
      local_1234 = uVar10;
      local_1230 = uVar10;
      local_122c = uVar10;
      memset((void *)((int)&local_1024 + 1),0,0x3fb);
      local_1278 = *(undefined4 *)(DAT_00030330 + 0x2fe74);
      uStack_1274 = *(undefined4 *)(DAT_00030330 + 0x2fe78);
      uStack_1270 = *(undefined4 *)(DAT_00030330 + 0x2fe7c);
      local_126c = (undefined2)*(undefined4 *)(DAT_00030330 + 0x2fe80);
      pcVar3 = (char *)get_cgi(DAT_00030334 + 0x2fe88);
      if (pcVar3 == (char *)0x0) {
        fwrite((void *)(DAT_00030408 + 0x3091c),1,0x1d,param_1);
        goto LAB_0002f800;
      }
      iVar5 = make_wl_prefix(&local_1278,0xe,1,0);
      if (iVar5 == 0) {
        fwrite((void *)(DAT_000304c8 + 0x30ee8),1,0x23,param_1);
        goto LAB_0002f800;
      }
      iVar5 = strcmp(pcVar3,(char *)(DAT_00030338 + 0x2fec4));
      if (iVar5 == 0) {
        fwrite((void *)(DAT_00030398 + 0x305cc),1,0x10,param_1);
        fflush(param_1);
        iVar5 = FUN_0002df04(&local_1128);
        if (iVar5 != -1) {
          nvram_set(&local_1128,DAT_0003039c + 0x305f4);
        }
        snprintf((char *)&local_1228,0x100,(char *)(DAT_000303a0 + 0x30610),&local_1278);
        uVar15 = nvram_default_get(DAT_000303a4 + 0x3061c);
        nvram_set(&local_1228,uVar15);
        snprintf((char *)&local_1228,0x100,(char *)(DAT_000303a8 + 0x30640),&local_1278);
        uVar15 = nvram_default_get(DAT_000303ac + 0x3064c);
        nvram_set(&local_1228,uVar15);
        snprintf((char *)&local_1228,0x100,(char *)(DAT_000303b0 + 0x30670),&local_1278);
        uVar15 = nvram_default_get(DAT_000303b4 + 0x3067c);
        nvram_set(&local_1228,uVar15);
        snprintf((char *)&local_1228,0x100,(char *)(DAT_000303b8 + 0x306a0),&local_1278);
        uVar15 = nvram_default_get(DAT_000303bc + 0x306ac);
        nvram_set(&local_1228,uVar15);
        iVar5 = DAT_000303c0;
        puVar16 = *(undefined1 **)(iVar19 + DAT_00030584);
        *(undefined4 *)(DAT_000303c0 + 0x31220) = 2;
        *(undefined1 *)(iVar5 + 0x311cc) = 0;
        *puVar16 = 1;
        goto LAB_0002f800;
      }
      iVar5 = strcmp(pcVar3,(char *)(DAT_0003033c + 0x2fedc));
      if (iVar5 == 0) {
        fwrite((void *)(DAT_0003040c + 0x30938),1,0x14,param_1);
        fflush(param_1);
        iVar5 = get_cgi(DAT_00030410 + 0x3094c);
        if (iVar5 == 0) {
          fwrite((void *)(DAT_000325c8 + 0x317fc),1,0x18,param_1);
          fflush(param_1);
          goto LAB_0002f800;
        }
        pcVar3 = (char *)get_cgi(DAT_00030414 + 0x30960);
        iVar8 = DAT_0003041c;
        if (pcVar3 == (char *)0x0) {
          fwrite((void *)(DAT_000325d0 + 0x3182c),1,0x23,param_1);
          fflush(param_1);
          goto LAB_0002f800;
        }
        if (*pcVar3 == '\0') {
          *(undefined4 *)(DAT_00030418 + 0x314dc) = 2;
          snprintf((char *)&local_1228,0x100,(char *)(iVar8 + 0x3099c),&local_1278);
          nvram_set(&local_1228,iVar5);
          nvram_set(DAT_00030420 + 0x309bc,iVar5);
          snprintf((char *)&local_1228,0x100,(char *)(DAT_00030424 + 0x309d4),&local_1278);
          nvram_set(&local_1228,pcVar3);
          nvram_set(DAT_00030428 + 0x309f0,pcVar3);
        }
        else {
          iVar8 = get_cgi(DAT_00030518 + 0x31168);
          if (iVar8 == 0) {
            fwrite((void *)(DAT_00032618 + 0x31a58),1,0x1f,param_1);
            fflush(param_1);
            goto LAB_0002f800;
          }
          pcVar4 = (char *)get_cgi(DAT_0003051c + 0x3117c);
          if (pcVar4 == (char *)0x0) {
            fwrite((void *)(DAT_000326ec + 0x320ec),1,0x1e,param_1);
            fflush(param_1);
            goto LAB_0002f800;
          }
          sVar11 = strlen(pcVar4);
          if (sVar11 == 0x40) {
            pbVar17 = (byte *)(pcVar4 + -1);
            do {
              pbVar17 = pbVar17 + 1;
              uVar10 = (uint)*pbVar17;
              if (uVar10 == 0) goto LAB_0003119c;
              ppuVar13 = __ctype_b_loc();
            } while (((*ppuVar13)[uVar10] & 0x1000) != 0);
            fprintf(param_1,(char *)(DAT_00032788 + 0x324f0),uVar10);
            fflush(param_1);
            goto LAB_0002f800;
          }
          if (0x37 < sVar11 - 8) {
            fwrite((void *)(DAT_0003277c + 0x32498),1,100,param_1);
            fflush(param_1);
            goto LAB_0002f800;
          }
LAB_0003119c:
          iVar12 = DAT_00030524;
          *(undefined4 *)(DAT_00030520 + 0x31d04) = 2;
          snprintf((char *)&local_1228,0x100,(char *)(iVar12 + 0x311c4),&local_1278);
          nvram_set(&local_1228,iVar5);
          nvram_set(DAT_00030528 + 0x311e4,iVar5);
          snprintf((char *)&local_1228,0x100,(char *)(DAT_0003052c + 0x311fc),&local_1278);
          nvram_set(&local_1228,pcVar3);
          nvram_set(DAT_00030530 + 0x31218,pcVar3);
          snprintf((char *)&local_1228,0x100,(char *)(DAT_00030534 + 0x31230),&local_1278);
          nvram_set(&local_1228,iVar8);
          nvram_set(DAT_00030538 + 0x3124c,iVar8);
          snprintf((char *)&local_1228,0x100,(char *)(DAT_0003053c + 0x31264),&local_1278);
          nvram_set(&local_1228,pcVar4);
          nvram_set(DAT_00030540 + 0x31280,pcVar4);
        }
        iVar5 = DAT_0003042c;
        FUN_0002e570();
        pvVar7 = (void *)(iVar5 + 0x30a08);
        fwrite(pvVar7,1,8,param_1);
        fflush(param_1);
        fwrite((void *)(DAT_00030430 + 0x30a30),1,0x14,param_1);
        fflush(param_1);
        nvram_set(DAT_00030438 + 0x30a4c,DAT_00030434 + 0x30a48);
        iVar8 = DAT_0003043c + 0x30a5c;
        iVar5 = DAT_00030440 + 0x30a60;
        goto LAB_0002f910;
      }
      iVar8 = strcmp(pcVar3,(char *)(DAT_00030340 + 0x2fef4));
      iVar5 = DAT_00030478;
      if (iVar8 == 0) {
        fwrite((void *)(DAT_00030474 + 0x30c9c),1,0x15,param_1);
        fflush(param_1);
        iVar8 = DAT_0003047c;
        *(undefined4 *)(iVar5 + 0x319c4) = 3;
        fwrite((void *)(iVar8 + 0x30cc8),1,0x24,param_1);
        fflush(param_1);
        iVar8 = snprintf((char *)&local_1024,0x3fc,(char *)(DAT_00030480 + 0x30ce8),
                         *(undefined4 *)(iVar5 + 0x319c4));
        iVar8 = FUN_0002098c(param_1,&local_1028,iVar8 + 4);
        if (iVar8 == -1) goto LAB_0002f800;
        pcVar3 = (char *)get_cgi(DAT_00030484 + 0x30d10);
        iVar14 = DAT_0003048c;
        iVar12 = DAT_00030488;
        if (pcVar3 != (char *)0x0) {
          if (*pcVar3 == '\0') {
            *(undefined4 *)(iVar5 + 0x31964) = 2;
            local_1284 = *(uint *)(iVar12 + 0x30d48);
            local_1280 = *(uint *)(iVar12 + 0x30d4c);
            sVar11 = 0x400 - iVar8;
            pcVar3 = (char *)((int)&local_1028 + iVar8);
            iVar8 = iVar8 + 0x13;
            snprintf(pcVar3,sVar11,(char *)(iVar14 + 0x30d50));
          }
          else {
            *(undefined4 *)(iVar5 + 0x31964) = 1;
            iVar5 = FUN_0001ae54(&local_1284);
            if (iVar5 != 0) {
              fwrite((void *)(DAT_00032610 + 0x319d4),1,0x22,param_1);
              fflush(param_1);
              goto LAB_0002f800;
            }
            pcVar3 = (char *)get_cgi(DAT_00030594 + 0x314b8);
            if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
              iVar5 = ether_atoe(pcVar3,&local_1128);
              if ((iVar5 != 0) && ((local_1128 & 1) == 0)) {
                if ((((((char)local_1128 != '\0' || local_1128._1_1_ != '\0') ||
                      local_1128._2_1_ != '\0') || local_1128._3_1_ != '\0') ||
                    (char)local_1124 != '\0') || local_1124._1_1_ != '\0') {
                  iVar5 = snprintf((char *)((int)&local_1028 + iVar8),0x400 - iVar8,
                                   (char *)(DAT_00032778 + 0x32464),pcVar3);
                  iVar8 = iVar8 + iVar5;
                  snprintf((char *)&local_1248,0x20,pcVar3);
                  goto LAB_00030d60;
                }
              }
              fprintf(param_1,(char *)(DAT_00032780 + 0x324b8),pcVar3);
              fflush(param_1);
              *(undefined4 *)(DAT_00032784 + 0x33018) = 0;
              goto LAB_0002f800;
            }
          }
LAB_00030d60:
          iVar5 = snprintf((char *)((int)&local_1028 + iVar8),0x400 - iVar8,
                           (char *)(DAT_00030490 + 0x30d78),&local_1284);
          iVar8 = iVar8 + iVar5;
          iVar5 = snprintf((char *)((int)&local_1028 + iVar8),0x400 - iVar8,
                           (char *)(DAT_00030498 + 0x30d9c),*(undefined4 *)(DAT_00030494 + 0x31a50))
          ;
          iVar8 = iVar8 + iVar5;
        }
        fwrite((void *)(DAT_0003049c + 0x30db8),1,2,param_1);
        fflush(param_1);
        nvram_set(DAT_000304a4 + 0x30dd4,DAT_000304a0 + 0x30dd0);
        pcVar3 = (char *)nvram_get(DAT_000304a8 + 0x30de0);
        iVar5 = DAT_000304ac;
        if (pcVar3 == (char *)0x0) {
          pcVar3 = (char *)(DAT_000325cc + 0x31814);
        }
        pcVar4 = (char *)(DAT_000304ac + 0x31af4);
        strncpy(pcVar4,pcVar3,0x20);
        iVar12 = DAT_000304b0;
        *(undefined1 *)(iVar5 + 0x31b13) = 0;
        iVar5 = snprintf((char *)((int)&local_1028 + iVar8),0x400 - iVar8,(char *)(iVar12 + 0x30e30)
                         ,1);
        snprintf(acStack_1268,0x10,(char *)(DAT_000304b4 + 0x30e50),pcVar4);
        nvifname_to_osifname(acStack_1268,auStack_1258,0x10);
        snprintf((char *)((int)&local_1028 + iVar8 + iVar5),0x400 - (iVar8 + iVar5),
                 (char *)(DAT_000304b8 + 0x30e78),auStack_1258);
        pcVar3 = (char *)nvram_get(DAT_000304bc + 0x30e84);
        if ((pcVar3 != (char *)0x0) &&
           (iVar5 = strcmp(pcVar3,(char *)(DAT_000304c0 + 0x30e98)), iVar5 == 0)) {
LAB_00030ea0:
          FUN_0001e800(&local_1028);
          goto LAB_0002f800;
        }
        local_1128 = 0;
        memset(&local_1124,0,0xfc);
        if (*(int *)(DAT_00030598 + 0x321b0) == 2) {
          snprintf((char *)&local_1128,0x100,(char *)(DAT_000326e4 + 0x320c4),DAT_000326e0 + 0x320c0
                   ,auStack_1258);
        }
        else if (*(int *)(DAT_00030598 + 0x321b0) == 1) {
          if ((local_1248 & 0xff) == 0) {
            puVar18 = (uint *)(DAT_00032670 + 0x31d3c);
          }
          else {
            puVar18 = &local_1248;
          }
          snprintf((char *)&local_1128,0x100,(char *)(DAT_00032678 + 0x31d6c),DAT_00032674 + 0x31d64
                   ,auStack_1258,&local_1284,0x78,puVar18);
        }
        if ((char)local_1128 == '\0') goto LAB_0002f800;
        iVar8 = system((char *)&local_1128);
        iVar5 = DAT_0003059c;
        if (iVar8 == 0) {
          *(undefined4 *)(DAT_0003059c + 0x31534) = 1;
          wl_wlif_update_wps_ui();
          if (*(int *)(iVar5 + 0x321f0) == 1) {
            wl_wlif_create_thrd(&local_1228,DAT_000305a0 + 0x31558,0);
          }
          goto LAB_0002f800;
        }
        pFVar9 = fopen((char *)(DAT_000327cc + 0x32964),(char *)(DAT_000327c8 + 0x32960));
        if (pFVar9 == (FILE *)0x0) goto LAB_0002f800;
        iVar5 = DAT_000327d0 + 0x32980;
        pcVar3 = (char *)(DAT_000327d4 + 0x32984);
      }
      else {
        iVar8 = strcmp(pcVar3,(char *)(DAT_00030344 + 0x2ff0c));
        iVar5 = DAT_000304d4;
        if (iVar8 == 0) {
          pvVar7 = (void *)(DAT_000304d8 + 0x30f94);
          *(undefined4 *)(DAT_000304d4 + 0x30f90) = 1;
          fwrite(pvVar7,1,0x15,param_1);
          fflush(param_1);
          pcVar3 = (char *)get_cgi(DAT_000304dc + 0x30fac);
          if (pcVar3 == (char *)0x0) {
            fwrite((void *)(DAT_00032688 + 0x31e3c),1,0x1a,param_1);
            fflush(param_1);
            goto LAB_0002f800;
          }
          iVar8 = strcmp(pcVar3,(char *)(DAT_000304e0 + 0x30fc0));
          if (iVar8 == 0) {
            *(undefined4 *)(iVar5 + 0x31cac) = 1;
          }
          else {
            iVar8 = strcmp(pcVar3,(char *)(DAT_000304e4 + 0x30fdc));
            if (iVar8 == 0) {
              *(undefined4 *)(iVar5 + 0x31cac) = 4;
            }
            else {
              iVar8 = strcmp(pcVar3,(char *)(DAT_000304e8 + 0x30ffc));
              if (iVar8 == 0) {
                *(undefined4 *)(iVar5 + 0x31cac) = 5;
              }
            }
          }
          iVar5 = DAT_000304ec;
          snprintf((char *)&local_1228,0x100,(char *)(DAT_000304f0 + 0x3102c),
                   *(undefined4 *)(DAT_000304ec + 0x31d40));
          nvram_set(DAT_000304f4 + 0x3103c,&local_1228);
          fprintf(param_1,(char *)(DAT_000304f8 + 0x31050),pcVar3);
          fflush(param_1);
          iVar8 = snprintf((char *)&local_1024,0x3fc,(char *)(DAT_000304fc + 0x31070),
                           *(undefined4 *)(iVar5 + 0x31d40));
          iVar12 = iVar8 + 4;
          if (*(int *)(iVar5 + 0x31d40) == 1) {
            pcVar3 = (char *)get_cgi(DAT_000325fc + 0x3195c);
            iVar14 = strcmp(pcVar3,(char *)(DAT_00032600 + 0x3196c));
            if (iVar14 == 0) {
              *(undefined4 *)(iVar5 + 0x31ce0) = 1;
            }
            else {
              iVar24 = strcmp(pcVar3,(char *)(DAT_00032604 + 0x3198c));
              iVar14 = DAT_0003268c;
              if (iVar24 == 0) {
                *(undefined4 *)(iVar5 + 0x31ce0) = 2;
                local_1284 = *(uint *)(iVar14 + 0x31e64);
                local_1280 = *(uint *)(iVar14 + 0x31e68);
                sVar11 = 0x400 - iVar12;
                pcVar3 = (char *)((int)&local_1028 + iVar12);
                iVar12 = iVar8 + 0x17;
                snprintf(pcVar3,sVar11,(char *)(DAT_00032690 + 0x31e7c));
              }
            }
            iVar5 = snprintf((char *)((int)&local_1028 + iVar12),0x400 - iVar12,
                             (char *)(DAT_0003260c + 0x319b4),
                             *(undefined4 *)((int)&DAT_00032668 + DAT_00032608));
            iVar12 = iVar12 + iVar5;
          }
          if ((*(int *)(DAT_00030500 + 0x31dac) == 4) &&
             (iVar12 = FUN_0002098c(param_1,&local_1028,iVar12), iVar12 < 0)) goto LAB_0002f800;
          iVar8 = DAT_00032680;
          iVar5 = DAT_00030504;
          if (*(int *)(DAT_00030504 + 0x31dc0) - 4U < 2) {
            *(undefined4 *)(DAT_00030504 + 0x31d60) = 1;
            iVar8 = snprintf((char *)((int)&local_1028 + iVar12),0x400 - iVar12,
                             (char *)(iVar8 + 0x31db0));
            iVar12 = iVar12 + iVar8;
            if (*(int *)(iVar5 + 0x31d60) == 1) {
              iVar5 = get_cgi(DAT_000327d8 + 0x329a4);
              if ((iVar5 != 0) && (iVar5 = FUN_0001ae54(&local_1284), iVar5 != 0)) {
                fwrite((void *)(DAT_000327e4 + 0x32a10),1,0x1c,param_1);
                fflush(param_1);
                goto LAB_0002f800;
              }
              iVar5 = snprintf((char *)((int)&local_1028 + iVar12),0x400 - iVar12,
                               (char *)(DAT_000327dc + 0x329dc),&local_1284);
              iVar12 = iVar12 + iVar5;
              iVar5 = *(int *)((int)&DAT_00033708 + DAT_000327e0);
              if (iVar5 == 1) goto LAB_000310b8;
            }
            else {
              iVar5 = *(int *)(iVar5 + 0x31dc0);
              if (iVar5 == 1) goto LAB_00031308;
            }
            if (iVar5 - 4U < 2) {
LAB_000310cc:
              pcVar3 = (char *)get_cgi(DAT_0003050c + 0x310d8);
              if (((pcVar3 == (char *)0x0) || (lVar6 = strtol(pcVar3,(char **)0x0,10), lVar6 == -1))
                 || (*(char *)(DAT_00030510 + 0x31108) != '\x01')) {
LAB_00031138:
                fwrite((void *)(DAT_00030514 + 0x31150),1,0x1e,param_1);
                fflush(param_1);
                goto LAB_0002f800;
              }
              pcVar3 = (char *)(DAT_00030510 + 0x31108);
              if (lVar6 != 0) {
                iVar5 = 0;
                do {
                  pcVar3 = pcVar3 + 0x38;
                  iVar5 = iVar5 + 1;
                  if (*pcVar3 != '\x01') goto LAB_00031138;
                } while (lVar6 != iVar5);
              }
              iVar5 = *(int *)(DAT_00030544 + 0x31fb0);
              **(undefined4 **)(iVar19 + DAT_00030548) = pcVar3;
              if (iVar5 - 4U < 2) {
                if (pcVar3[0x36] == '\0') {
                  iVar5 = DAT_00032694 + 0x31e9c;
                }
                else {
                  iVar5 = DAT_000326e8 + 0x320d4;
                }
                iVar5 = snprintf((char *)((int)&local_1028 + iVar12),0x400 - iVar12,
                                 (char *)(DAT_00032698 + 0x31eac),iVar5);
                iVar12 = iVar12 + iVar5;
              }
              iVar5 = snprintf((char *)((int)&local_1028 + iVar12),0x400 - iVar12,
                               (char *)(DAT_0003054c + 0x312c0),pcVar3 + 1);
              iVar12 = iVar12 + iVar5;
              uVar15 = ether_etoa(pcVar3 + 0x23,&local_1128);
              iVar5 = snprintf((char *)((int)&local_1028 + iVar12),0x400 - iVar12,
                               (char *)(DAT_00030550 + 0x312e8),uVar15);
              iVar12 = iVar12 + iVar5;
              iVar5 = snprintf((char *)((int)&local_1028 + iVar12),0x400 - iVar12,
                               (char *)(DAT_00030554 + 0x31304),(uint)(byte)pcVar3[0x35]);
              iVar12 = iVar12 + iVar5;
            }
          }
          else if (*(int *)(DAT_00030504 + 0x31dc0) == 1) {
LAB_000310b8:
            if (*(int *)(DAT_00030508 + 0x31d80) == 1) goto LAB_000310cc;
          }
LAB_00031308:
          fwrite((void *)(DAT_00030558 + 0x31320),1,2,param_1);
          fflush(param_1);
          nvram_set(DAT_00030560 + 0x3133c,DAT_0003055c + 0x31338);
          pcVar3 = (char *)nvram_get(DAT_00030564 + 0x31348);
          iVar5 = DAT_00030568;
          if (pcVar3 == (char *)0x0) {
            pcVar3 = (char *)(DAT_00032614 + 0x319f4);
          }
          puVar23 = (undefined4 *)(DAT_00030568 + 0x31364);
          pcVar4 = (char *)(DAT_00030568 + 0x3205c);
          strncpy(pcVar4,pcVar3,0x20);
          iVar8 = DAT_0003056c;
          uVar15 = *puVar23;
          *(undefined1 *)(iVar5 + 0x3207b) = 0;
          iVar5 = snprintf((char *)((int)&local_1028 + iVar12),0x400 - iVar12,
                           (char *)(iVar8 + 0x31390),uVar15);
          snprintf(acStack_1268,0x10,(char *)(DAT_00030570 + 0x313b0),pcVar4);
          nvifname_to_osifname(acStack_1268,auStack_1258,0x10);
          snprintf((char *)((int)&local_1028 + iVar12 + iVar5),0x400 - (iVar12 + iVar5),
                   (char *)(DAT_00030574 + 0x313d8),auStack_1258);
          pcVar3 = (char *)nvram_get(DAT_00030578 + 0x313e4);
          if (((pcVar3 == (char *)0x0) ||
              (iVar5 = strcmp(pcVar3,(char *)(DAT_0003057c + 0x313f8)), iVar5 != 0)) &&
             (iVar5 = DAT_00030580, *(int *)(DAT_00030580 + 0x32128) == 1)) {
            local_1128 = 0;
            memset(&local_1124,0,0xfc);
            if (*(int *)(iVar5 + 0x320c8) == 1) {
              iVar5 = nvram_get(DAT_0003269c + 0x31ec0);
              if (iVar5 == 0) {
                iVar5 = DAT_00032774 + 0x32400;
              }
              snprintf((char *)&local_1128,0x100,(char *)(DAT_000326a0 + 0x31ee8),acStack_1268,
                       auStack_1258,iVar5);
            }
            else if (*(int *)(iVar5 + 0x320c8) == 2) {
              snprintf((char *)&local_1128,0x100,(char *)(DAT_00032644 + 0x31bb4),acStack_1268,
                       auStack_1258);
            }
            iVar8 = system((char *)&local_1128);
            iVar5 = DAT_00032648;
            if (iVar8 == 0) {
              *(undefined4 *)(DAT_00032648 + 0x31bd8) = 1;
              wl_wlif_update_wps_ui(6);
              if (*(int *)(iVar5 + 0x32894) == 1) {
                wl_wlif_create_thrd(auStack_1288,DAT_0003264c + 0x31bfc,0);
              }
            }
            else {
              pFVar9 = fopen((char *)(DAT_000326f4 + 0x3210c),(char *)(DAT_000326f0 + 0x32108));
              if (pFVar9 != (FILE *)0x0) {
                fprintf(pFVar9,(char *)(DAT_000326fc + 0x32130),DAT_000326f8 + 0x32d44,&local_1128);
                fclose(pFVar9);
              }
            }
          }
          else {
            FUN_0001e800(&local_1028);
          }
          **(undefined1 **)(iVar19 + DAT_00030584) = 1;
          goto LAB_0002f800;
        }
        iVar5 = strcmp(pcVar3,(char *)(DAT_00030348 + 0x2ff28));
        if (iVar5 == 0) {
          fwrite((void *)(DAT_00030588 + 0x31448),1,0x22,param_1);
          fflush(param_1);
          if (*(int *)(DAT_0003058c + 0x3145c) == 0) {
            FUN_0002d0a8();
          }
          fwrite((void *)(DAT_00030590 + 0x3147c),1,2,param_1);
          fflush(param_1);
          goto LAB_0002f800;
        }
        iVar5 = strcmp(pcVar3,(char *)(DAT_0003034c + 0x2ff40));
        if (iVar5 != 0) {
          iVar5 = strcmp(pcVar3,(char *)(DAT_00030350 + 0x2ff58));
          if (iVar5 == 0) {
            fwrite((void *)(DAT_00032630 + 0x31b04),1,0x1c,param_1);
            fflush(param_1);
            iVar5 = FUN_00020eb0(&local_1128);
            if (iVar5 == 0) {
              nvram_set(DAT_00032634 + 0x31b2c,&local_1128);
              iVar5 = DAT_0003263c;
              **(undefined1 **)(iVar19 + DAT_00032638) = 1;
              fwrite((void *)(iVar5 + 0x31b50),1,2,param_1);
              fflush(param_1);
              *(undefined4 *)((int)&DAT_000326b0 + DAT_00032640) = 2;
            }
            else {
              fwrite((void *)(DAT_0003267c + 0x31d88),1,4,param_1);
              fflush(param_1);
            }
            goto LAB_0002f800;
          }
          iVar5 = strcmp(pcVar3,(char *)(DAT_00030354 + 0x2ff70));
          if (iVar5 == 0) {
            pcVar3 = (char *)nvram_get(DAT_0003261c + 0x31a70);
            if ((pcVar3 == (char *)0x0) ||
               (iVar5 = strcmp(pcVar3,(char *)(DAT_00032620 + 0x31a84)), iVar5 != 0)) {
              local_1128 = 0;
              memset(&local_1124,0,0xfc);
              local_1228 = 0;
              local_1224 = 0;
              local_1220 = 0;
              local_121c = 0;
              local_1218 = 0;
              local_1214 = 0;
              local_1210 = 0;
              local_120c = 0;
              pcVar3 = (char *)nvram_get(DAT_00032650 + 0x31c2c);
              iVar5 = DAT_00032654;
              if (pcVar3 == (char *)0x0) {
                pcVar3 = (char *)(DAT_000326dc + 0x320a4);
              }
              pcVar3 = strncpy((char *)(DAT_00032654 + 0x32960),pcVar3,0x20);
              iVar8 = DAT_00032658;
              *(undefined1 *)(iVar5 + 0x3297f) = 0;
              snprintf(acStack_1268,0x10,(char *)(iVar8 + 0x31c94),pcVar3);
              nvifname_to_osifname(acStack_1268,auStack_1258,0x10);
              snprintf((char *)&local_1228,0x20,(char *)(DAT_0003265c + 0x31cbc),acStack_1268);
              pcVar3 = (char *)nvram_get(&local_1228);
              if ((pcVar3 == (char *)0x0) ||
                 (iVar5 = strcmp(pcVar3,(char *)(DAT_00032660 + 0x31cd8)), iVar5 != 0)) {
                snprintf((char *)&local_1128,0x100,(char *)(DAT_000326d8 + 0x32094),acStack_1268,
                         auStack_1258);
              }
              else {
                snprintf((char *)&local_1128,0x100,(char *)(DAT_00032668 + 0x31d00),
                         DAT_00032664 + 0x31cfc,auStack_1258);
              }
              iVar5 = system((char *)&local_1128);
              if (iVar5 == 0) {
                *(undefined4 *)(DAT_0003266c + 0x31d1c) = 0;
                wl_wlif_update_wps_ui();
              }
            }
            else {
              snprintf((char *)&local_1024,0x3fc,(char *)(DAT_00032624 + 0x31aa4),2);
              snprintf(acStack_100d,0x3e5,(char *)(DAT_00032628 + 0x31abc),0);
              FUN_0001e800(&local_1028);
            }
            fwrite((void *)(DAT_0003262c + 0x31adc),1,0x13,param_1);
            fflush(param_1);
            goto LAB_0002f800;
          }
          iVar5 = strcmp(pcVar3,(char *)(DAT_00030358 + 0x2ff88));
          if (iVar5 == 0) {
            pvVar7 = (void *)(DAT_00032704 + 0x32160);
            *(undefined4 *)(DAT_00032700 + 0x32ca4) = 0;
            fwrite(pvVar7,1,0x14,param_1);
            fflush(param_1);
            iVar5 = get_cgi(DAT_00032708 + 0x32178);
            if (iVar5 == 0) {
              iVar5 = DAT_00032770 + 0x323f4;
            }
            iVar8 = get_cgi(DAT_0003270c + 0x3218c);
            if (iVar8 == 0) {
              iVar8 = DAT_0003276c + 0x323e8;
            }
            iVar14 = nvram_get(DAT_00032710 + 0x321a0);
            iVar12 = DAT_0003271c;
            if (iVar14 == 0) {
              iVar14 = DAT_00032768 + 0x323dc;
            }
            pvVar7 = (void *)(DAT_00032714 + 0x321c8);
            iVar24 = 3;
            printf((char *)(DAT_00032718 + 0x321d0),iVar8,iVar5,iVar14);
            fwrite(pvVar7,1,8,param_1);
            fflush(param_1);
            fwrite((void *)(DAT_00032720 + 0x32208),1,0x14,param_1);
            fflush(param_1);
            fwrite(pvVar7,1,8,param_1);
            fflush(param_1);
            fwrite((void *)(DAT_00032724 + 0x32244),1,0x16,param_1);
            fflush(param_1);
            do {
              pcVar3 = (char *)nvram_get(iVar12 + 0x321f0);
              if ((pcVar3 != (char *)0x0) && (*pcVar3 == '\0')) break;
              sleep(1);
              iVar24 = iVar24 + -1;
            } while (iVar24 != 0);
            snprintf((char *)&local_1128,0x40,(char *)(DAT_00032728 + 0x32288),iVar14,iVar8,iVar5);
            nvram_set(DAT_0003272c + 0x3229c,&local_1128);
            nvram_set(DAT_00032734 + 0x322b0,DAT_00032730 + 0x322ac);
            pcVar3 = (char *)nvram_get(DAT_00032738 + 0x322bc);
            if ((pcVar3 != (char *)0x0) &&
               (iVar5 = strcmp(pcVar3,(char *)(DAT_0003273c + 0x322d0)), iVar5 == 0)) {
              nvram_unset(DAT_00032740 + 0x322e4);
              nvram_set(DAT_00032748 + 0x322f8,DAT_00032744 + 0x322f4);
            }
            goto LAB_000322f8;
          }
          iVar5 = strcmp(pcVar3,(char *)(DAT_0003035c + 0x2ffa0));
          if (iVar5 == 0) {
            iVar5 = 3;
            iVar8 = DAT_000326a8 + 0x31f08;
            puts((char *)(DAT_000326a4 + 0x31f04));
            do {
              pcVar3 = (char *)nvram_get(iVar8);
              if ((pcVar3 != (char *)0x0) && (*pcVar3 == '\0')) break;
              sleep(1);
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
            iVar8 = 3;
            iVar5 = DAT_000326ac + 0x31f38;
            nvram_set(iVar5,DAT_000326b0 + 0x31f3c);
            do {
              sleep(1);
              pcVar3 = (char *)nvram_get(iVar5);
              if ((pcVar3 != (char *)0x0) && (*pcVar3 == '\0')) break;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
            pvVar7 = (void *)(DAT_000326b8 + 0x31f88);
            *(undefined4 *)(DAT_000326b4 + 0x32acc) = 0;
            fwrite(pvVar7,1,0x1a,param_1);
            fflush(param_1);
            fwrite((void *)(DAT_000326bc + 0x31fac),1,0x20,param_1);
            fflush(param_1);
            fwrite((void *)(DAT_000326c0 + 0x31fcc),1,5,param_1);
            fflush(param_1);
            fprintf(param_1,(char *)(DAT_000326c8 + 0x31fec),DAT_000326c4 + 0x31fe8);
            fflush(param_1);
            fwrite((void *)(DAT_000326cc + 0x3200c),1,6,param_1);
            fflush(param_1);
            fwrite((void *)(DAT_000326d0 + 0x3202c),1,10,param_1);
            fflush(param_1);
            fwrite((void *)(DAT_000326d4 + 0x3204c),1,7,param_1);
            fflush(param_1);
            goto LAB_0002f800;
          }
          iVar5 = strcmp(pcVar3,(char *)(DAT_00030360 + 0x2ffb8));
          if (iVar5 != 0) {
            iVar5 = strcmp(pcVar3,(char *)(DAT_00030364 + 0x2ffd0));
            if (iVar5 == 0) {
              iVar5 = get_cgi(DAT_00030368 + 0x2ffe4);
              if (iVar5 == 0) {
                iVar5 = DAT_0003278c + 0x32508;
              }
              nvram_set(DAT_0003036c + 0x2fff8,iVar5);
              nvram_set(DAT_00030374 + 0x3000c,DAT_00030370 + 0x30008);
              *(undefined4 *)(DAT_00030378 + 0x30b64) = 0;
            }
            goto LAB_0002f800;
          }
          pcVar3 = (char *)get_cgi(DAT_00032790 + 0x32514);
          if (pcVar3 == (char *)0x0) {
            pcVar3 = (char *)(DAT_000327b4 + 0x328d0);
          }
          lVar6 = strtol(pcVar3,(char **)0x0,10);
          if (lVar6 < 0) {
LAB_00032854:
            puts((char *)(DAT_000327a0 + 0x32860));
            fwrite((void *)(DAT_000327a4 + 0x32878),1,0x1e,param_1);
            fflush(param_1);
LAB_00032880:
            fprintf(param_1,(char *)(DAT_000327ac + 0x32898),DAT_000327a8 + 0x32894);
            fflush(param_1);
            fwrite((void *)(DAT_000327b0 + 0x328b8),1,7,param_1);
            fflush(param_1);
          }
          else {
            pcVar4 = (char *)nvram_get(DAT_00032794 + 0x32540);
            if ((pcVar4 == (char *)0x0) ||
               (iVar5 = strcmp(pcVar4,(char *)(DAT_00032798 + 0x32554)), iVar5 != 0)) {
              nvram_set(DAT_0003279c + 0x3256c,pcVar3);
            }
            else {
              pcVar3 = (char *)nvram_get(DAT_000327b8 + 0x328dc);
              if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
                uVar10 = strtol(pcVar3,(char **)0x0,10);
                printf((char *)(DAT_000327bc + 0x32910),uVar10);
                if (uVar10 < 4) {
                  if (uVar10 == 0) {
                    puts((char *)(DAT_000327c0 + 0x3292c));
                    fwrite((void *)(DAT_000327c4 + 0x32944),1,0x14,param_1);
                    fflush(param_1);
                  }
                  else {
                    if (uVar10 == 1) goto LAB_00032854;
                    if (uVar10 == 2) {
                      fwrite((void *)(DAT_000327f0 + 0x32a88),1,0x26,param_1);
                      fflush(param_1);
                    }
                    else {
                      fwrite((void *)(DAT_000327e8 + 0x32a44),1,0xc,param_1);
                      fflush(param_1);
                    }
                  }
                }
                else {
                  fwrite((void *)(DAT_000327ec + 0x32a68),1,0xd,param_1);
                  fflush(param_1);
                }
                goto LAB_00032880;
              }
            }
LAB_000322f8:
            fwrite((void *)(DAT_0003274c + 0x32310),1,0x20,param_1);
            fflush(param_1);
            fwrite((void *)(DAT_00032750 + 0x32330),1,5,param_1);
            fflush(param_1);
            fprintf(param_1,(char *)(DAT_00032758 + 0x32350),DAT_00032754 + 0x3234c);
            fflush(param_1);
            fwrite((void *)(DAT_0003275c + 0x32370),1,6,param_1);
            fflush(param_1);
            fwrite((void *)(DAT_00032760 + 0x32390),1,10,param_1);
            fflush(param_1);
            fwrite((void *)(DAT_00032764 + 0x323b0),1,7,param_1);
            fflush(param_1);
          }
          goto LAB_0002f800;
        }
        fwrite((void *)(DAT_000305a4 + 0x31574),1,0x15,param_1);
        fflush(param_1);
        pcVar3 = (char *)nvram_get(DAT_000305a8 + 0x31588);
        bVar2 = false;
        if (pcVar3 != (char *)0x0) {
          iVar5 = strcmp(pcVar3,(char *)(DAT_000305ac + 0x3159c));
          bVar2 = iVar5 == 0;
        }
        pcVar3 = (char *)get_cgi(DAT_00032570 + 0x315b0);
        if (pcVar3 == (char *)0x0) {
          fwrite((void *)(DAT_0003283c + 0x32c60),1,0x1a,param_1);
          goto LAB_0002f800;
        }
        pcVar4 = (char *)nvram_get(DAT_00032574 + 0x315c4);
        iVar5 = DAT_00032578;
        if (pcVar4 == (char *)0x0) {
          pcVar4 = (char *)(DAT_00032838 + 0x32c48);
        }
        pcVar4 = strncpy((char *)(DAT_00032578 + 0x322d8),pcVar4,0x20);
        iVar8 = DAT_0003257c;
        *(undefined1 *)(iVar5 + 0x322f7) = 0;
        snprintf(acStack_1268,0x10,(char *)(iVar8 + 0x3160c),pcVar4);
        nvifname_to_osifname(acStack_1268,auStack_1258,0x10);
        iVar12 = strcmp(pcVar3,(char *)(DAT_00032580 + 0x3162c));
        iVar8 = DAT_000325d8;
        if (iVar12 == 0) {
          fwrite((void *)(DAT_000325d4 + 0x31854),1,2,param_1);
          fflush(param_1);
          nvram_set(DAT_000325dc + 0x31870,(char *)(iVar8 + 0x31860));
          pcVar3 = (char *)nvram_get(DAT_000325e0 + 0x3187c);
          if ((pcVar3 != (char *)0x0) &&
             (iVar8 = strcmp(pcVar3,(char *)(iVar8 + 0x31860)), iVar8 == 0)) {
            snprintf((char *)&local_1024,0x3fc,(char *)(DAT_000325e4 + 0x318ac),2);
            if ((bVar2) && (*(char *)(iVar5 + 0x322a0) != '\0')) {
              iVar5 = snprintf(acStack_1015,0x3ed,(char *)(DAT_00032808 + 0x32b3c),iVar5 + 0x322a0);
              iVar5 = iVar5 + 0x13;
            }
            else {
              iVar5 = 0x13;
            }
            iVar8 = snprintf((char *)((int)&local_1028 + iVar5),0x400 - iVar5,
                             (char *)(DAT_000325e8 + 0x318d8));
            iVar5 = iVar5 + iVar8;
            iVar8 = snprintf((char *)((int)&local_1028 + iVar5),0x400 - iVar5,
                             (char *)(DAT_000325ec + 0x318f4),3);
            iVar5 = iVar5 + iVar8;
            iVar8 = snprintf((char *)((int)&local_1028 + iVar5),0x400 - iVar5,
                             (char *)(DAT_000325f0 + 0x31910),1);
            iVar5 = iVar5 + iVar8;
            iVar8 = snprintf((char *)((int)&local_1028 + iVar5),0x400 - iVar5,
                             (char *)(DAT_000325f4 + 0x3192c),2);
            snprintf((char *)((int)&local_1028 + iVar5 + iVar8),0x400 - (iVar5 + iVar8),
                     (char *)(DAT_000325f8 + 0x31948),auStack_1258);
            goto LAB_00030ea0;
          }
          local_1128 = 0;
          memset(&local_1124,0,0xfc);
          snprintf((char *)&local_1128,0x100,(char *)(DAT_000327f8 + 0x32acc),DAT_000327f4 + 0x32ac8
                   ,auStack_1258);
          iVar5 = system((char *)&local_1128);
          if (iVar5 == 0) {
            *(undefined4 *)(DAT_0003281c + 0x32b84) = 0;
            wl_wlif_update_wps_ui();
          }
          snprintf((char *)&local_1128,0x100,(char *)(DAT_00032800 + 0x32afc),DAT_000327fc + 0x32af8
                   ,auStack_1258);
          iVar5 = system((char *)&local_1128);
          if (iVar5 == 0) {
            *(undefined4 *)(DAT_00032804 + 0x32b1c) = 1;
            wl_wlif_update_wps_ui();
            goto LAB_0002f800;
          }
          pFVar9 = fopen((char *)(DAT_00032810 + 0x32b58),(char *)(DAT_0003280c + 0x32b54));
          if (pFVar9 == (FILE *)0x0) goto LAB_0002f800;
          iVar5 = DAT_00032814 + 0x32b74;
          pcVar3 = (char *)(DAT_00032818 + 0x32b78);
        }
        else {
          iVar8 = strcmp(pcVar3,(char *)(DAT_00032584 + 0x31644));
          iVar5 = DAT_0003258c;
          if (iVar8 != 0) goto LAB_0002f800;
          snprintf((char *)&local_1024,0x3fc,(char *)(DAT_00032588 + 0x31668),2);
          fwrite((void *)(DAT_00032590 + 0x31684),1,2,param_1);
          fflush(param_1);
          nvram_set(DAT_00032594 + 0x3169c,(char *)(iVar5 + 0x31680));
          pcVar3 = (char *)nvram_get(DAT_00032598 + 0x316a8);
          if ((pcVar3 != (char *)0x0) &&
             (iVar5 = strcmp(pcVar3,(char *)(iVar5 + 0x31680)), iVar5 == 0)) {
            snprintf(acStack_1015,0x3ed,(char *)(DAT_0003259c + 0x316d8),1);
            iVar5 = snprintf(acStack_1006,0x3de,(char *)(DAT_000325a0 + 0x316f0),1);
            iVar5 = iVar5 + 0x22;
            iVar8 = snprintf((char *)((int)&local_1028 + iVar5),0x400 - iVar5,
                             (char *)(DAT_000325a4 + 0x3170c),2);
            iVar5 = iVar5 + iVar8;
            iVar8 = snprintf((char *)((int)&local_1028 + iVar5),0x400 - iVar5,
                             (char *)(DAT_000325a8 + 0x31728),auStack_1258);
            iVar5 = iVar5 + iVar8;
            iVar8 = nvram_get(DAT_000325ac + 0x3173c);
            if (iVar8 == 0) {
              iVar8 = DAT_00032824 + 0x32ba4;
            }
            iVar8 = snprintf((char *)((int)&local_1028 + iVar5),0x400 - iVar5,
                             (char *)(DAT_000325b0 + 0x3175c),iVar8);
            iVar5 = iVar5 + iVar8;
            iVar8 = nvram_get(DAT_000325b4 + 0x31770);
            if (iVar8 == 0) {
              iVar8 = DAT_00032820 + 0x32b98;
            }
            iVar8 = snprintf((char *)((int)&local_1028 + iVar5),0x400 - iVar5,
                             (char *)(DAT_000325b8 + 0x31790),iVar8);
            iVar12 = nvram_get(DAT_000325bc + 0x317ac);
            if (iVar12 == 0) {
              iVar12 = DAT_00032828 + 0x32bb0;
            }
            snprintf((char *)((int)&local_1028 + iVar5 + iVar8),0x400 - (iVar5 + iVar8),
                     (char *)(DAT_000325c0 + 0x317c8),iVar12);
            printf((char *)(DAT_000325c4 + 0x317d8),&local_1028);
            FUN_0001e800(&local_1028);
            goto LAB_0002f800;
          }
          local_1128 = 0;
          memset(&local_1124,0,0xfc);
          snprintf((char *)&local_1128,0x100,(char *)(DAT_0003282c + 0x32be4),acStack_1268,
                   auStack_1258);
          iVar5 = system((char *)&local_1128);
          if (iVar5 == 0) {
            *(undefined4 *)(DAT_00032850 + 0x32ca4) = 0;
            wl_wlif_update_wps_ui();
          }
          snprintf((char *)&local_1128,0x100,(char *)(DAT_00032830 + 0x32c10),acStack_1268,
                   auStack_1258);
          iVar5 = system((char *)&local_1128);
          if (iVar5 == 0) {
            *(undefined4 *)(DAT_00032834 + 0x32c34) = 1;
            wl_wlif_update_wps_ui(6);
            goto LAB_0002f800;
          }
          pFVar9 = fopen((char *)(DAT_00032844 + 0x32c78),(char *)(DAT_00032840 + 0x32c74));
          if (pFVar9 == (FILE *)0x0) goto LAB_0002f800;
          iVar5 = DAT_00032848 + 0x32c94;
          pcVar3 = (char *)(DAT_0003284c + 0x32c98);
        }
      }
      fprintf(pFVar9,pcVar3,iVar5 + 0xc1c,&local_1128);
      fclose(pFVar9);
      goto LAB_0002f800;
    }
    iVar5 = strcmp((char *)(DAT_00030200 + 0x2f584),pcVar3);
    if (iVar5 != 0) {
      fprintf(param_1,(char *)(DAT_00030328 + 0x2fdfc),pcVar4);
      fflush(param_1);
      goto LAB_0002f800;
    }
    local_1028 = iVar5;
    memset(&local_1024,0,0x3fc);
    local_1278 = *(undefined4 *)(DAT_00030204 + 0x2f5b4);
    uStack_1274 = *(undefined4 *)(DAT_00030204 + 0x2f5b8);
    uStack_1270 = *(undefined4 *)(DAT_00030204 + 0x2f5bc);
    local_126c = (undefined2)*(undefined4 *)(DAT_00030204 + 0x2f5c0);
    pcVar3 = (char *)get_cgi(DAT_00030208 + 0x2f5c8);
    if (pcVar3 == (char *)0x0) {
      fwrite((void *)(DAT_000303c8 + 0x30708),1,0x1d,param_1);
      goto LAB_0002f800;
    }
    iVar5 = make_wl_prefix(&local_1278,0xe,1,0);
    if (iVar5 == 0) {
      fwrite((void *)(DAT_00030468 + 0x30c40),1,0x23,param_1);
      goto LAB_0002f800;
    }
    pcVar4 = (char *)nvram_get(DAT_0003020c + 0x2f604);
    if (pcVar4 == (char *)0x0) {
      pcVar4 = (char *)(DAT_000303c4 + 0x306f0);
    }
    pcVar4 = strncpy((char *)&local_1248,pcVar4,0x20);
    local_122c = local_122c & 0xffffff;
    snprintf(acStack_1268,0x10,(char *)(DAT_00030210 + 0x2f644),pcVar4);
    nvifname_to_osifname(acStack_1268,auStack_1258,0x10);
    iVar5 = get_cgi(DAT_00030214 + 0x2f660);
    if (iVar5 == 0) goto LAB_0002f800;
    local_1128 = 0;
    memset(&local_1124,0,0xfc);
    local_1228 = 0;
    memset(&local_1224,0,0x3d);
    iVar8 = strcmp(pcVar3,(char *)(DAT_00030218 + 0x2f6a0));
    if (iVar8 == 0) {
      fwrite((void *)(DAT_00030444 + 0x30a7c),1,0x15,param_1);
      fflush(param_1);
      fwrite((void *)(DAT_00030448 + 0x30a9c),1,0x24,param_1);
      fflush(param_1);
      snprintf((char *)&local_1028,0x400,(char *)(DAT_0003044c + 0x30ac0),auStack_1258,iVar5);
      pFVar9 = popen((char *)&local_1028,(char *)(DAT_00030450 + 0x30ad0));
      while (pcVar3 = fgets((char *)&local_1128,0x100,pFVar9), pcVar3 != (char *)0x0) {
        local_1290 = strtol((char *)&local_1128,(char **)0x0,10);
      }
      pclose(pFVar9);
      sleep(2);
      memset(&local_1028,0,0x400);
      snprintf((char *)&local_1028,0x400,(char *)(DAT_00030454 + 0x30b50),&local_1278);
      pcVar3 = (char *)nvram_get(&local_1028);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)(DAT_000304d0 + 0x30f68);
        sVar11 = 0;
LAB_00030f64:
        uVar10 = sVar11 + 1 & 0xffff;
      }
      else {
        sVar11 = strlen(pcVar3);
        if (sVar11 + 1 < 0x22) goto LAB_00030f64;
        uVar10 = 0x21;
      }
      wl_ascii_str_to_hex_str(pcVar3,uVar10,&local_1228,0x41);
      memset(&local_1028,0,0x400);
      pcVar3 = stpcpy((char *)&local_1028,(char *)&local_1278);
      uVar15 = *(undefined4 *)(DAT_00030458 + 0x30bb8);
      cVar1 = *(char *)(DAT_00030458 + 0x30bbc);
      *(undefined4 *)pcVar3 = *(undefined4 *)(DAT_00030458 + 0x30bb4);
      *(undefined4 *)(pcVar3 + 4) = uVar15;
      pcVar3[8] = cVar1;
      pcVar3 = (char *)nvram_get(&local_1028);
      if ((pcVar3 == (char *)0x0) ||
         (iVar5 = strcmp(pcVar3,(char *)(DAT_0003045c + 0x30be0)), iVar5 != 0)) {
        snprintf((char *)&local_1028,0x400,(char *)(DAT_000304c4 + 0x30ecc),auStack_1258,local_1290)
        ;
      }
      else {
        iVar5 = get_cgi(DAT_00030460 + 0x30bf4);
        if (iVar5 != 0) {
          snprintf((char *)&local_1028,0x400,(char *)(DAT_00030464 + 0x30c24),auStack_1258,
                   local_1290,&local_1228,iVar5);
        }
      }
    }
    else {
      iVar8 = strcmp(pcVar3,(char *)(DAT_0003021c + 0x2f6b8));
      if (iVar8 != 0) goto LAB_0002f800;
      fwrite((void *)(DAT_00030220 + 0x2f6dc),1,0x15,param_1);
      fflush(param_1);
      fwrite((void *)(DAT_00030224 + 0x2f6fc),1,0x24,param_1);
      fflush(param_1);
      snprintf((char *)&local_1028,0x400,(char *)(DAT_00030228 + 0x2f724),auStack_1258,auStack_1258,
               iVar5);
      pFVar9 = popen((char *)&local_1028,(char *)(DAT_0003022c + 0x2f734));
      while (pcVar3 = fgets((char *)&local_1128,0x100,pFVar9), pcVar3 != (char *)0x0) {
        local_1290 = strtol((char *)&local_1128,(char **)0x0,10);
      }
      pclose(pFVar9);
      sleep(2);
      snprintf((char *)&local_1028,0x400,(char *)(DAT_00030230 + 0x2f798),auStack_1258,auStack_1258,
               local_1290);
    }
    system((char *)&local_1028);
    goto LAB_0002f800;
  }
  iVar5 = strcmp(pcVar4,(char *)(DAT_000301a4 + 0x2f2c4));
  if (iVar5 == 0) {
    pvVar7 = (void *)(DAT_000301d0 + 0x2f3d0);
    *(undefined4 *)(DAT_000301cc + 0x2ff14) = 2;
    fwrite(pvVar7,1,0x14,param_1);
    fflush(param_1);
    iVar5 = strcmp((char *)(DAT_000301d4 + 0x2f3ec),pcVar3);
    if (iVar5 == 0) {
      FUN_00022164(param_1);
    }
    else {
      pvVar7 = malloc(5000);
      iVar5 = DAT_000301dc;
      piVar20 = *(int **)(iVar19 + DAT_000301d8);
      *piVar20 = (int)pvVar7;
      piVar21 = *(int **)(iVar19 + iVar5);
      *piVar21 = 0;
      if (pvVar7 == (void *)0x0) {
        fwrite((void *)(DAT_00032684 + 0x31e10),1,0x11,param_1);
        fflush(param_1);
        fflush(param_1);
      }
      else {
        iVar5 = *(int *)(iVar19 + DAT_000301e0) + 0x1c;
        iVar8 = *(int *)(iVar19 + DAT_000301e0) + 0x1acc;
        do {
          while( true ) {
            iVar12 = iVar5 + -0x1c;
            pcVar3 = (char *)get_cgi(*(undefined4 *)(iVar5 + -0x1c));
            if ((pcVar3 != (char *)0x0) && ((*(uint *)(iVar5 + -4) & 0x200000) == 0)) break;
LAB_0002f448:
            iVar5 = iVar5 + 0x1c;
            if (iVar8 == iVar5) goto LAB_0002f4a8;
          }
          if (((*pcVar3 == '\0') && (*(int *)(iVar5 + -8) != 0)) ||
             (puVar23 = (undefined4 *)(iVar5 + -0x10), (code *)*puVar23 == (code *)0x0)) {
            nvram_set(*(undefined4 *)(iVar5 + -0x1c));
            goto LAB_0002f448;
          }
          iVar5 = iVar5 + 0x1c;
          (*(code *)*puVar23)(param_1,pcVar3,iVar12,0);
        } while (iVar8 != iVar5);
LAB_0002f4a8:
        *(undefined1 *)(*piVar20 + *piVar21) = 0;
        fprintf(param_1,(char *)*piVar20);
        fflush(param_1);
        free((void *)*piVar20);
        *piVar20 = 0;
      }
    }
    if (**(int **)(iVar19 + DAT_00030238) != 0) {
      fwrite((void *)(DAT_0003023c + 0x2f7e8),1,4,param_1);
      fflush(param_1);
      *(undefined4 *)((int)&DAT_00030348 + DAT_00030240) = 0;
      goto LAB_0002f800;
    }
    pvVar7 = (void *)(DAT_00030264 + 0x2f8c0);
    fwrite(pvVar7,1,8,param_1);
    fflush(param_1);
    fwrite((void *)(DAT_00030268 + 0x2f8e4),1,0x14,param_1);
    fflush(param_1);
    nvram_set(DAT_00030270 + 0x2f900,DAT_0003026c + 0x2f8fc);
    iVar8 = DAT_00030274 + 0x2f910;
    iVar5 = DAT_00030278 + 0x2f914;
LAB_0002f910:
    nvram_set(iVar5,iVar8);
    **(undefined1 **)(iVar19 + DAT_000301c0) = 1;
    fwrite(pvVar7,1,8,param_1);
    fflush(param_1);
    goto LAB_0002f800;
  }
  iVar5 = strncmp(pcVar4,(char *)(DAT_000301a8 + 0x2f2e0),7);
  if (iVar5 != 0) {
    iVar5 = strcmp(pcVar4,(char *)(DAT_0003027c + 0x2f950));
    if (iVar5 == 0) {
      fwrite((void *)(DAT_00030280 + 0x2f970),1,0x12,param_1);
      fflush(param_1);
      pcVar3 = (char *)nvram_get(DAT_00030284 + 0x2f984);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)(DAT_000302e0 + 0x2fc48);
      }
      uVar10 = strtol(pcVar3,(char **)0x0,10);
      snprintf((char *)&local_1028,100,(char *)(DAT_00030288 + 0x2f9b4),
               uVar10 & ~((int)uVar10 >> 0x1f));
      pcVar3 = (char *)file2str(&local_1028);
      if (pcVar3 == (char *)0x0) goto LAB_0002f9f4;
      lVar6 = strtol(pcVar3,(char **)0x0,10);
      free(pcVar3);
      iVar5 = kill(lVar6,0xc);
      if (iVar5 != 0) goto LAB_0002f9f4;
LAB_0002fadc:
      fwrite((void *)(DAT_000302a4 + 0x2faf4),1,8,param_1);
      fflush(param_1);
    }
    else {
      iVar5 = strcmp(pcVar4,(char *)(DAT_00030294 + 0x2fa38));
      if (iVar5 != 0) {
        iVar5 = strcmp(pcVar4,(char *)(DAT_000302a8 + 0x2fb10));
        if (iVar5 == 0) {
          fwrite((void *)(DAT_000302ac + 0x2fb30),1,0xc,param_1);
          fflush(param_1);
          *(undefined4 *)(DAT_000302b0 + 0x30690) = 1;
          goto LAB_0002f800;
        }
        goto LAB_0002f4e4;
      }
      fwrite((void *)(DAT_00030298 + 0x2fa58),1,0x11,param_1);
      fflush(param_1);
      pcVar3 = (char *)nvram_get(DAT_0003029c + 0x2fa6c);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)(DAT_00030300 + 0x2fcfc);
      }
      uVar10 = strtol(pcVar3,(char **)0x0,10);
      snprintf((char *)&local_1028,100,(char *)(DAT_000302a0 + 0x2fa9c),
               uVar10 & ~((int)uVar10 >> 0x1f));
      pcVar3 = (char *)file2str(&local_1028);
      if (pcVar3 != (char *)0x0) {
        lVar6 = strtol(pcVar3,(char **)0x0,10);
        free(pcVar3);
        iVar5 = kill(lVar6,10);
        if (iVar5 == 0) goto LAB_0002fadc;
      }
LAB_0002f9f4:
      fwrite((void *)(DAT_0003028c + 0x2fa0c),1,9,param_1);
      fflush(param_1);
    }
    *(undefined4 *)((int)&DAT_0003056c + DAT_00030290) = 0;
    goto LAB_0002f800;
  }
  fwrite((void *)(DAT_000301ac + 0x2f300),1,0x15,param_1);
  fflush(param_1);
  nvram_set(DAT_000301b4 + 0x2f31c,DAT_000301b0 + 0x2f318);
  pcVar3 = (char *)nvram_get(DAT_000301b8 + 0x2f328);
  if (pcVar3 == (char *)0x0) {
    pcVar3 = (char *)(DAT_0003025c + 0x2f89c);
  }
  lVar6 = strtol(pcVar3,(char **)0x0,10);
  if (lVar6 == 1) {
LAB_0002f880:
    nvram_unset(DAT_00030258 + 0x2f88c);
  }
  else {
    pcVar3 = (char *)nvram_get(DAT_000301bc + 0x2f350);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = (char *)(DAT_000302e4 + 0x2fc54);
    }
    lVar6 = strtol(pcVar3,(char **)0x0,10);
    if (lVar6 == 2) goto LAB_0002f880;
  }
  pvVar7 = (void *)(DAT_000301c4 + 0x2f390);
  **(undefined1 **)(iVar19 + DAT_000301c0) = 1;
  fwrite(pvVar7,1,8,param_1);
  fflush(param_1);
  *(undefined4 *)(DAT_000301c8 + 0x2fef0) = 1;
LAB_0002f800:
  iVar5 = get_cgi(DAT_00030244 + 0x2f80c);
  if (iVar5 == 0) {
    iVar5 = DAT_00030260 + 0x2f8a8;
  }
  fprintf(param_1,(char *)(DAT_00030248 + 0x2f824),iVar5);
  fflush(param_1);
  fwrite((void *)(DAT_0003024c + 0x2f844),1,7,param_1);
  fflush(param_1);
  if (*(int *)((int)&DAT_000303a0 + DAT_00030250) - 1U < 2) {
    **(undefined1 **)(iVar19 + DAT_00030254) = 1;
  }
  return 1;
LAB_00030c44:
  fwrite((void *)(DAT_0003046c + 0x30c64),1,0x23,param_1);
  fflush(param_1);
  *(undefined4 *)(DAT_00030470 + 0x317c4) = 0;
  goto LAB_0002f800;
}

