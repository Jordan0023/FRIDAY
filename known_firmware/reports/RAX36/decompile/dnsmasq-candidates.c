
===== ENTRY 00025c50 =====
===== FUNCTION FUN_00025c50 @ 00025c50 =====

void FUN_00025c50(int *param_1)

{
  char cVar1;
  ushort uVar2;
  ssize_t sVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  char *pcVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  byte *pbVar15;
  char *pcVar16;
  char *pcVar17;
  undefined4 *puVar18;
  byte *pbVar19;
  sockaddr *psVar20;
  uint uVar21;
  socklen_t local_10d0;
  undefined4 local_10cc;
  undefined4 local_10c8;
  undefined4 local_10c4;
  undefined4 local_10c0;
  undefined4 local_10bc;
  undefined4 local_10b8 [12];
  sockaddr local_1088;
  sockaddr sStack_1078;
  undefined2 local_105c [4];
  undefined4 local_1054 [5];
  char local_1040 [256];
  undefined4 local_f40;
  undefined2 local_f3c;
  undefined4 local_f3a;
  undefined2 local_f36;
  ushort local_f34;
  undefined4 local_f32;
  ushort local_f2e;
  byte local_f2c;
  undefined1 local_f2b;
  undefined4 local_f2a [4];
  undefined4 local_f1a [4];
  ushort local_f08;
  ushort local_f06;
  ushort local_f04;
  undefined1 auStack_f02 [12];
  byte abStack_ef6 [246];
  undefined1 auStack_e00 [14];
  undefined4 local_df2;
  ushort local_dee;
  undefined1 uStack_dec;
  undefined1 local_deb;
  undefined4 local_dea [8];
  undefined2 local_dca;
  undefined2 local_dc8;
  undefined2 local_dc4;
  undefined4 local_a00;
  undefined2 local_9fc;
  undefined4 local_9fa;
  undefined2 local_9f6;
  undefined4 local_9f4;
  undefined2 local_9f0;
  ushort local_9ee;
  undefined2 local_9ec;
  undefined4 local_9ea [8];
  undefined2 local_9ca;
  undefined2 local_9c8;
  ushort local_9c6;
  undefined2 local_9c4;
  undefined1 auStack_9c2 [951];
  char acStack_60b [13];
  undefined2 local_5fe;
  undefined4 uStack_5fc;
  undefined4 local_5f8;
  undefined1 auStack_5f0 [12];
  undefined1 auStack_5e4 [1472];
  int local_24;
  
  local_24 = **(int **)(DAT_00026400 + 0x25c78 + DAT_000263fc);
  if (**(int **)(DAT_00026404 + 0x25c7c + DAT_00026408) == 0) goto LAB_00025d50;
  local_a00 = 0;
  local_10c8 = 0;
  local_10c4 = 0;
  local_10c0 = 0;
  local_10bc = 0;
  memset(&local_9fc,0,0x3fc);
  local_10d0 = 0x1c;
  memset(&sStack_1078,0,0x1c);
  memset(&local_f40,0,0x13e);
  memset(auStack_e00,0,0x400);
  sVar3 = recvfrom(*param_1,auStack_e00,0x400,0,&sStack_1078,&local_10d0);
  if (-1 < sVar3) {
    FUN_00037f88(6,DAT_00026414 + 0x25d90,sVar3);
    memcpy(&local_f40,auStack_e00,0x13e);
    memset(&local_a00,0,0x400);
    if (0x3d < sVar3) {
      if (((local_f2c != 0x11) || (local_f08 != 0x3500)) || ((uint)local_f06 != (uint)local_f2e)) {
        FUN_00037f88(6,DAT_0002641c + 0x25e20,(uint)local_f2c << 8,local_f34 << 8 | local_f34 >> 8,
                     local_f08 << 8 | local_f08 >> 8,
                     (local_f2e & 0xff) << 8 | (uint)(local_f2e >> 8));
        goto LAB_00025d50;
      }
      iVar4 = memcmp(local_f2a,&local_10c8,2);
      if (iVar4 != 0) {
        puVar18 = local_10b8;
        puVar11 = local_f2a;
        do {
          puVar14 = puVar11 + 2;
          uVar9 = puVar11[1];
          *puVar18 = *puVar11;
          puVar18[1] = uVar9;
          puVar18 = puVar18 + 2;
          puVar11 = puVar14;
        } while (puVar14 != local_f1a);
        puVar18 = local_10b8 + 4;
        puVar11 = local_f1a;
        do {
          puVar14 = puVar11 + 2;
          uVar9 = puVar11[1];
          *puVar18 = *puVar11;
          puVar18[1] = uVar9;
          uVar2 = local_f04;
          puVar18 = puVar18 + 2;
          puVar11 = puVar14;
        } while (puVar14 != (undefined4 *)&stack0xfffff0f6);
        puVar18 = local_10b8;
        local_dc4 = 0;
        local_df2 = 0;
        local_dee = 0;
        uStack_dec = 0;
        uVar21 = (uint)local_f04;
        local_f32 = 0;
        local_f2c = 0;
        local_f04 = 0;
        local_f2b = 0x11;
        puVar11 = local_f2a;
        do {
          uVar9 = *puVar18;
          uVar10 = puVar18[1];
          puVar18 = puVar18 + 2;
          *puVar11 = uVar9;
          puVar11[1] = uVar10;
          puVar11 = puVar11 + 2;
        } while (puVar18 != local_10b8 + 4);
        puVar18 = local_10b8 + 4;
        puVar11 = local_f1a;
        do {
          uVar9 = *puVar18;
          uVar10 = puVar18[1];
          puVar18 = puVar18 + 2;
          *puVar11 = uVar9;
          puVar11[1] = uVar10;
          puVar11 = puVar11 + 2;
        } while (puVar18 != local_10b8 + 8);
        puVar18 = local_10b8;
        local_f2e = local_f06;
        local_deb = 0x11;
        puVar11 = local_dea;
        do {
          uVar9 = *puVar18;
          uVar10 = puVar18[1];
          puVar18 = puVar18 + 2;
          *puVar11 = uVar9;
          puVar11[1] = uVar10;
          puVar11 = puVar11 + 2;
        } while (puVar18 != local_10b8 + 4);
        puVar18 = local_10b8 + 4;
        puVar11 = local_dea + 4;
        do {
          uVar9 = *puVar18;
          uVar10 = puVar18[1];
          puVar18 = puVar18 + 2;
          *puVar11 = uVar9;
          puVar11[1] = uVar10;
          puVar11 = puVar11 + 2;
        } while (puVar18 != local_10b8 + 8);
        local_dee = local_f06;
        if ((uVar21 == 0) || (uVar5 = FUN_00024ab8(&local_df2,sVar3), uVar5 == uVar21)) {
          pcVar12 = acStack_60b + 0xb;
          memcpy(pcVar12,auStack_f02,0x100);
          iVar4 = DAT_0002642c;
          pbVar19 = abStack_ef6;
          do {
            pbVar15 = pbVar19;
            pbVar19 = pbVar15 + 1;
          } while (*pbVar15 != 0);
          pbVar19 = abStack_ef6;
          pcVar17 = local_1040;
          while (pbVar19 < pbVar15) {
            pbVar6 = pbVar19 + 1;
            uVar21 = (uint)*pbVar19;
            if (uVar21 == 0) break;
            uVar5 = uVar21 & 0xc0;
            if ((*pbVar19 & 0xc0) != 0) goto LAB_00025d48;
            if ((char *)0xff < pcVar17 + (uVar21 - (int)local_1040) + 1) {
              FUN_00037f88(6,DAT_00026444 + 0x26384,uVar21,0x100);
              goto LAB_00025d50;
            }
            pbVar19 = pbVar6 + uVar21;
            if (pbVar15 < pbVar19) goto LAB_00025d48;
            do {
              pcVar17[uVar5] = *pbVar6;
              uVar5 = uVar5 + 1;
              pbVar6 = pbVar6 + 1;
            } while ((int)uVar5 < (int)uVar21);
            pcVar16 = pcVar17 + uVar21;
            pcVar17 = pcVar17 + uVar21 + 1;
            *pcVar16 = '.';
          }
          pcVar16 = local_1040;
          if (pcVar17 != local_1040) {
            pcVar16 = pcVar17 + -1;
          }
          *pcVar16 = '\0';
          FUN_00037f88(6,DAT_00026428 + 0x26048,local_1040);
          puVar11 = (undefined4 *)(iVar4 + 0x26060);
          do {
            if ((char *)*puVar11 == (char *)0x0) goto LAB_00025d50;
            iVar4 = strcmp(local_1040,(char *)*puVar11);
            puVar11 = puVar11 + 1;
          } while (iVar4 != 0);
          uVar21 = (local_f06 & 0xff) << 8 | (uint)(local_f06 >> 8);
          cVar1 = acStack_60b[uVar21];
          pcVar12[uVar21 - 8] = -0x40;
          if (cVar1 == '\x1c') {
            iVar4 = 6;
          }
          else {
            iVar4 = 4;
          }
          acStack_60b[uVar21 + 4] = '\f';
          if (iVar4 == 6) {
            acStack_60b[uVar21 + 5] = '\0';
            acStack_60b[uVar21 + 6] = '\x1c';
          }
          else {
            acStack_60b[uVar21 + 5] = '\0';
            acStack_60b[uVar21 + 6] = '\x01';
            iVar7 = FUN_0001933c(&local_10cc);
            if (iVar7 == 0) goto LAB_00025d50;
          }
          iVar7 = FUN_00019440(local_10b8 + 8,0);
          if (iVar7 < 0) goto LAB_00025d50;
          acStack_60b[uVar21 + 7] = '\0';
          acStack_60b[uVar21 + 8] = '\x01';
          acStack_60b[uVar21 + 9] = '\0';
          acStack_60b[uVar21 + 10] = '\0';
          acStack_60b[uVar21 + 0xb] = '\0';
          acStack_60b[uVar21 + 0xc] = '\0';
          *(undefined1 *)((int)&local_5fe + uVar21) = 0;
          if (iVar4 == 6) {
            psVar20 = &local_1088;
            *(undefined1 *)((int)&local_5fe + uVar21 + 1) = 0x10;
            iVar4 = FUN_00019440(psVar20);
            if ((iVar4 < 0) && (iVar4 = FUN_00019440(psVar20,0), iVar4 < 0)) goto LAB_00025d50;
            puVar11 = (undefined4 *)((int)&uStack_5fc + uVar21);
            do {
              uVar9 = *(undefined4 *)psVar20;
              uVar10 = *(undefined4 *)(psVar20->sa_data + 2);
              psVar20 = (sockaddr *)(psVar20->sa_data + 6);
              *puVar11 = uVar9;
              puVar11[1] = uVar10;
              puVar11 = puVar11 + 2;
            } while (psVar20 != &sStack_1078);
            puVar13 = auStack_5e4;
          }
          else {
            *(undefined1 *)((int)&local_5fe + uVar21 + 1) = 4;
            puVar13 = auStack_5f0;
            *(undefined4 *)((int)&uStack_5fc + uVar21) = local_10cc;
          }
          puVar13 = puVar13 + ((uVar21 - 8) - (int)pcVar12);
          puVar18 = local_10b8 + 4;
          local_5fe = (ushort)(((local_5fe & 0xfffff079) << 0x11) >> 0x11) | 0x8084;
          uStack_5fc._2_2_ = 0x100;
          local_5f8 = 0;
          local_9ec = CONCAT11(0x11,(undefined1)local_9ec);
          puVar11 = local_9ea;
          do {
            uVar9 = *puVar18;
            uVar10 = puVar18[1];
            puVar18 = puVar18 + 2;
            *puVar11 = uVar9;
            puVar11[1] = uVar10;
            puVar11 = puVar11 + 2;
          } while (puVar18 != local_10b8 + 8);
          puVar18 = local_10b8;
          puVar11 = local_9ea + 4;
          do {
            uVar9 = *puVar18;
            uVar10 = puVar18[1];
            puVar18 = puVar18 + 2;
            *puVar11 = uVar9;
            puVar11[1] = uVar10;
            puVar11 = puVar11 + 2;
          } while (puVar18 != local_10b8 + 4);
          local_9c4 = 0;
          local_9c8 = local_dca;
          local_9ca = local_dc8;
          local_9ee = (ushort)(((uint)(puVar13 + 8) & 0xff) << 8) |
                      (ushort)((uint)(puVar13 + 8) >> 8) & 0xff;
          local_9c6 = local_9ee;
          __memcpy_chk(auStack_9c2,pcVar12,puVar13,0x3c2);
          uVar9 = FUN_00024ab8((int)&local_9f4 + 2,puVar13 + 0x3e);
          local_9c4 = (undefined2)uVar9;
          FUN_00037f88(6,DAT_00026430 + 0x26260,uVar9);
          local_9ec = 0x4011;
          local_9f0 = 0;
          local_a00 = local_f3a;
          local_9fc = local_f36;
          local_9fa = local_f40;
          puVar18 = local_1054;
          local_9f6 = local_f3c;
          local_9f4 = DAT_00026434;
          memset(local_105c,0,0x1c);
          local_105c[0] = 0xa00;
          puVar11 = local_f2a;
          do {
            puVar14 = puVar11 + 2;
            uVar9 = puVar11[1];
            *puVar18 = *puVar11;
            puVar18[1] = uVar9;
            puVar18 = puVar18 + 2;
            puVar11 = puVar14;
          } while (puVar14 != local_f1a);
          FUN_00037f88(6,DAT_00026438 + 0x26310,*param_1);
          sVar3 = send(*param_1,&local_a00,(size_t)(puVar13 + 0x3e),0);
          if (0 < sVar3) goto LAB_00025d50;
          piVar8 = __errno_location();
          pcVar12 = strerror(*piVar8);
          iVar4 = DAT_0002643c + 0x26348;
        }
        else {
          pcVar12 = (char *)((uVar21 & 0xff) << 8 | (uint)(uVar2 >> 8));
          iVar4 = DAT_00026424 + 0x25fcc;
        }
        FUN_00037f88(6,iVar4,pcVar12);
        goto LAB_00025d50;
      }
    }
  }
LAB_00025d48:
  FUN_00037f88(6);
LAB_00025d50:
  if (local_24 != **(int **)(DAT_00026410 + 0x25d68 + DAT_000263fc)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


===== ENTRY 000283b0 =====
===== FUNCTION FUN_000283b0 @ 000283b0 =====

void FUN_000283b0(int *param_1,undefined4 param_2)

{
  byte *pbVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  char cVar5;
  ssize_t sVar6;
  char *pcVar7;
  int iVar8;
  short *psVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  cmsghdr *pcVar13;
  FILE *__stream;
  void *pvVar14;
  size_t sVar15;
  int *__s;
  undefined4 uVar16;
  uint uVar17;
  in_addr *piVar18;
  uint uVar19;
  byte *pbVar20;
  byte bVar21;
  int iVar22;
  uint *puVar23;
  int iVar24;
  int *piVar25;
  ssize_t sVar26;
  void *pvVar27;
  byte *__s_00;
  undefined4 *puVar28;
  bool bVar29;
  uint local_388;
  undefined4 local_37c;
  undefined2 local_362;
  undefined1 *local_360;
  int local_35c;
  iovec local_358;
  msghdr local_350;
  undefined4 local_334;
  undefined4 uStack_330;
  undefined4 local_32c;
  undefined4 uStack_328;
  undefined2 local_324;
  undefined1 local_322;
  undefined4 local_320;
  undefined4 uStack_31c;
  undefined2 local_318;
  undefined1 local_316;
  size_t local_314;
  int iStack_310;
  int iStack_30c;
  size_t sStack_308;
  undefined4 local_304;
  undefined1 auStack_300 [8];
  undefined1 local_2f8;
  int local_2f0;
  undefined1 auStack_2ec [16];
  int local_2dc;
  undefined1 auStack_2d8 [16];
  char acStack_2c8 [20];
  undefined1 auStack_2b4 [20];
  undefined4 local_2a0;
  in_addr local_29c;
  in_addr iStack_298;
  undefined4 uStack_294;
  undefined4 local_290;
  undefined4 uStack_28c;
  undefined4 uStack_288;
  undefined4 local_284;
  in_addr local_280;
  in_addr_t iStack_27c;
  undefined4 uStack_278;
  undefined4 local_274;
  undefined4 uStack_270;
  undefined4 uStack_26c;
  cmsghdr acStack_268 [2];
  undefined4 local_248;
  undefined1 auStack_244 [32];
  char acStack_224 [512];
  int local_24;
  
  iVar22 = DAT_00028edc + 0x283cc;
  local_24 = **(int **)(DAT_00028ee0 + 0x283d8 + DAT_00028ee4);
  piVar25 = *(int **)(iVar22 + DAT_00028ee8);
  puVar23 = (uint *)*piVar25;
  pvVar27 = *(void **)((int)puVar23 + 0x236);
  bVar29 = (*puVar23 & 0x2000) != 0;
  local_35c = 0;
  if (bVar29) {
    local_388 = param_1[3];
  }
  else {
    local_388 = 1;
  }
  *(undefined1 *)((int)puVar23 + 0x25e) = 0;
  if (bVar29) {
    local_388 = local_388 - 10;
  }
  *(undefined1 *)((int)puVar23 + 0x25f) = 0;
  if (bVar29) {
    local_388 = LZCOUNT(local_388);
  }
  *(undefined1 *)(puVar23 + 0x98) = 0;
  *(undefined1 *)((int)puVar23 + 0x261) = 0;
  if (bVar29) {
    local_388 = local_388 >> 5;
  }
  local_314 = 0;
  local_37c = 0;
  if ((((*puVar23 & 0x2000) != 0) && (iVar8 = param_1[4], iVar8 != 0)) &&
     (local_35c = *(int *)(iVar8 + 0x38), param_1[3] == 2)) {
    local_314 = *(size_t *)(iVar8 + 4);
    local_37c = *(undefined4 *)(iVar8 + 0x1c);
  }
  sVar15 = local_314;
  local_358.iov_len = (size_t)(ushort)puVar23[0x6d];
  local_350.msg_flags = 0;
  local_350.msg_iovlen = 1;
  local_350.msg_control = acStack_268;
  local_350.msg_controllen = 0x20;
  local_350.msg_name = &local_2a0;
  local_350.msg_namelen = 0x1c;
  local_350.msg_iov = &local_358;
  local_358.iov_base = pvVar27;
  sVar6 = recvmsg(*param_1,&local_350,0);
  if (((0xb < sVar6) && ((local_350.msg_flags & 0x20U) == 0)) && (-1 < *(char *)((int)pvVar27 + 2)))
  {
    if (param_1[3] == 2) {
      pcVar7 = inet_ntoa(local_29c);
      iVar8 = strcmp(pcVar7,(char *)(DAT_00028eec + 0x284e8));
      if ((iVar8 != 0) && (**(int **)(iVar22 + DAT_00028ef0) != 0)) {
        pcVar7 = (char *)(DAT_00028ef8 + 0x2851c);
        **(undefined4 **)(iVar22 + DAT_00028ef4) = 1;
        system(pcVar7);
      }
    }
    memset((void *)(*(int *)(*piVar25 + 0x236) + sVar6),0,
           (uint)*(ushort *)(*piVar25 + 0x1b4) - sVar6);
    iVar8 = param_1[3];
    local_2a0 = CONCAT22(local_2a0._2_2_,(short)iVar8);
    if (iVar8 == 2) {
      if (local_2a0._2_2_ == 0) goto LAB_00028560;
    }
    else {
      if (local_2a0._2_2_ == 0) goto LAB_00028560;
      local_29c.s_addr = 0;
    }
    if ((*(uint *)(*piVar25 + 4) & 0x20000) == 0) {
LAB_00028650:
      if (local_388 != 0) {
        if (local_350.msg_controllen < 0xc) goto LAB_00028560;
        if (param_1[3] == 2) {
          local_388 = 0;
          for (pcVar13 = local_350.msg_control; pcVar13 != (cmsghdr *)0x0;
              pcVar13 = __cmsg_nxthdr(&local_350,pcVar13)) {
            if ((pcVar13->cmsg_level == 0) && (pcVar13->cmsg_type == 8)) {
              sVar15 = pcVar13[1].cmsg_level;
              local_388 = pcVar13[1].cmsg_len;
              local_314 = sVar15;
            }
          }
        }
        else {
          local_388 = 0;
        }
        if ((param_1[3] == 10) && (0xb < local_350.msg_controllen)) {
          for (pcVar13 = local_350.msg_control; pcVar13 != (cmsghdr *)0x0;
              pcVar13 = __cmsg_nxthdr(&local_350,pcVar13)) {
            if ((pcVar13->cmsg_level == 0x29) && (pcVar13->cmsg_type == *(int *)(*piVar25 + 0x4ba)))
            {
              local_314 = pcVar13[1].cmsg_len;
              iStack_310 = pcVar13[1].cmsg_level;
              iStack_30c = pcVar13[1].cmsg_type;
              sStack_308 = pcVar13[2].cmsg_len;
              local_388 = pcVar13[2].cmsg_level;
            }
          }
        }
        iVar8 = FUN_00029070(*param_1,local_388,acStack_224);
        if (iVar8 == 0) goto LAB_00028560;
        iVar8 = FUN_00029110(param_1[3],&local_314,acStack_224,&local_35c);
        if (iVar8 == 0) {
          if ((*(uint *)(*piVar25 + 4) & 0x80) == 0) {
            FUN_00029df0();
          }
          iVar8 = FUN_00029c48(*param_1,param_1[3],&local_314,acStack_224);
          if ((iVar8 == 0) && (iVar8 = FUN_00029d7c(local_388,param_1[3],&local_314), iVar8 == 0))
          goto LAB_00028560;
        }
        if ((param_1[3] == 2) && (puVar23 = (uint *)*piVar25, (*puVar23 & 0x40000) != 0)) {
          for (psVar9 = *(short **)((int)puVar23 + 0x24a); psVar9 != (short *)0x0;
              psVar9 = *(short **)(psVar9 + 0x28)) {
            if ((*psVar9 == 2) && (*(size_t *)(psVar9 + 2) == sVar15)) goto LAB_00028a20;
          }
          if ((puVar23[1] & 0x80) == 0) {
            FUN_00029df0();
          }
LAB_00028a20:
          for (psVar9 = *(short **)(*piVar25 + 0x24a); psVar9 != (short *)0x0;
              psVar9 = *(short **)(psVar9 + 0x28)) {
            if ((*psVar9 == 2) && (*(size_t *)(psVar9 + 2) == sVar15)) {
              local_37c = *(undefined4 *)(psVar9 + 0xe);
              goto LAB_00028714;
            }
          }
          sVar15 = 0;
        }
      }
LAB_00028714:
      iVar8 = *piVar25;
      iVar24 = *(int *)(iVar8 + 0x4c2) + 1;
      *(int *)(iVar8 + 0x4c2) = iVar24;
      *(int *)(iVar8 + 0x4c6) = iVar24;
      *(undefined4 **)(iVar8 + 0x4ca) = &local_2a0;
      FUN_00046b18(1,*(undefined4 *)(iVar8 + 0x236),sVar6,&local_2a0,0);
      iVar24 = FUN_00018918(pvVar27,sVar6,*(undefined4 *)(*piVar25 + 0x23e),&local_362);
      iVar8 = 0;
      if (iVar24 != 0) {
        if (local_35c == 0) {
          iVar8 = DAT_00028f08 + 0x28784;
        }
        else {
          iVar8 = DAT_00028f14 + 0x28a60;
        }
        uVar10 = FUN_00016818(iVar8,local_362);
        if (param_1[3] == 2) {
          piVar18 = &local_29c;
          uVar16 = *(undefined4 *)(*piVar25 + 0x23e);
          uVar11 = DAT_00028f0c;
        }
        else {
          piVar18 = &iStack_298;
          uVar16 = *(undefined4 *)(*piVar25 + 0x23e);
          uVar11 = DAT_00028f10;
        }
        FUN_00016994(uVar11,uVar16,piVar18,uVar10);
        if ((local_35c == 0) && ((*(uint *)*piVar25 & 0x40000) == 0)) {
          for (uVar17 = ((uint *)*piVar25)[0x14]; uVar17 != 0; uVar17 = *(uint *)(uVar17 + 0x10)) {
            iVar8 = FUN_00041fcc(uVar17,*(undefined4 *)(*piVar25 + 0x23e),0);
            if (iVar8 != 0) {
              iVar8 = 1;
              local_35c = iVar8;
              goto LAB_000287c4;
            }
          }
        }
        iVar8 = 0;
LAB_000287c4:
        iVar24 = FUN_00044f3c(*(undefined4 *)(*piVar25 + 0x23e),local_362);
        if (iVar24 != 0) goto LAB_00028560;
      }
      iVar12 = FUN_00045b08(pvVar27,sVar6,0,&local_360,0,0);
      iVar24 = local_35c;
      if (iVar12 == 0) {
        uVar17 = 0x200;
        bVar4 = 0;
        uVar10 = 0;
      }
      else {
        uVar19 = (uint)CONCAT11(*local_360,local_360[1]);
        bVar4 = (byte)local_360[4] >> 7;
        uVar17 = (uint)*(ushort *)(*piVar25 + 0x1b4);
        if ((uVar19 <= *(ushort *)(*piVar25 + 0x1b4)) && (uVar17 = uVar19, uVar19 < 0x200)) {
          uVar17 = 0x200;
        }
        uVar10 = 1;
        local_360 = local_360 + 6;
      }
      if (local_35c == 0) {
        bVar21 = bVar4;
        if ((*(byte *)((int)pvVar27 + 3) & 0x20) != 0) {
          bVar21 = 1;
        }
        iVar8 = FUN_00019648(pvVar27,(int)pvVar27 + uVar17,sVar6,sVar15,local_37c,param_2,bVar21,
                             bVar4,uVar10);
        if (iVar8 == 0) {
          sVar26 = sVar6;
          if (**(int **)(iVar22 + DAT_00028f18) == 1) {
            local_248 = iVar24;
            local_284 = local_2a0;
            local_280.s_addr = local_29c.s_addr;
            iStack_27c = iStack_298.s_addr;
            uStack_278 = uStack_294;
            local_274 = local_290;
            uStack_270 = uStack_28c;
            uStack_26c = uStack_288;
            memset(auStack_244,0,0x1d);
            local_304 = iVar24;
            memset(auStack_300,0,0x10);
            local_2f0 = iVar24;
            memset(auStack_2ec,0,0x10);
            local_2dc = iVar24;
            memset(auStack_2d8,0,0x10);
            local_32c = *(undefined4 *)(DAT_00028f1c + 0x28bdc);
            uStack_328 = *(undefined4 *)(DAT_00028f1c + 0x28be0);
            local_324 = *(undefined2 *)(DAT_00028f1c + 0x28be4);
            local_322 = *(undefined1 *)(DAT_00028f1c + 0x28be6);
            local_320 = *(undefined4 *)(DAT_00028f1c + 0x28be7);
            uStack_31c = *(undefined4 *)(DAT_00028f1c + 0x28beb);
            local_318 = *(undefined2 *)(DAT_00028f1c + 0x28bef);
            local_316 = *(undefined1 *)(DAT_00028f1c + 0x28bf1);
            local_334 = *(undefined4 *)(DAT_00028f1c + 0x28bf2);
            uStack_330 = *(undefined4 *)(DAT_00028f1c + 0x28bf6);
            pcVar7 = inet_ntoa(local_280);
            __strcpy_chk(&local_2dc,pcVar7,0x14);
            __stream = fopen64((char *)(DAT_00028f24 + 0x28c54),(char *)(DAT_00028f20 + 0x28c50));
            if (__stream != (FILE *)0x0) {
              iVar22 = DAT_00028f28 + 0x28c70;
              do {
                pcVar7 = fgets(acStack_224,0x200,__stream);
                if (pcVar7 == (char *)0x0) goto LAB_00028cf0;
                memset(acStack_2c8,0,0x14);
                pvVar14 = memset(auStack_2b4,0,0x14);
                __isoc99_sscanf(acStack_224,iVar22,acStack_2c8,pvVar14);
                iVar8 = strcasecmp((char *)&local_2dc,acStack_2c8);
              } while (iVar8 != 0);
              __strcpy_chk(&local_2f0,pvVar14,0x14);
LAB_00028cf0:
              __s = &local_2f0;
              fclose(__stream);
              sVar15 = strlen((char *)__s);
              if (sVar15 == 0x11) {
                iVar22 = 0;
                pcVar7 = (char *)&local_304;
                while( true ) {
                  iVar22 = iVar22 + 1;
                  *pcVar7 = (char)*__s;
                  pcVar7[1] = *(char *)((int)__s + 1);
                  if (iVar22 == 6) break;
                  __s = (int *)((int)__s + 3);
                  pcVar7 = pcVar7 + 2;
                }
                __s_00 = (byte *)&local_248;
                local_2f8 = 0;
                FUN_00024b10(&local_304,__s_00);
                sVar15 = strlen((char *)__s_00);
                if ((sVar15 == 0x10) &&
                   (iVar22 = strncmp((char *)__s_00,(char *)(DAT_00028f2c + 0x28d78),0x10),
                   iVar22 != 0)) {
                  iVar22 = 0x10;
                  pbVar20 = __s_00;
                  do {
                    uVar17 = (uint)*pbVar20;
                    if ((uVar17 - 0x30 & 0xff) < 10) {
                      *pbVar20 = (byte)(uVar17 - 0x30);
                    }
                    else {
                      if (uVar17 - 0x61 < 6) {
                        cVar5 = -0x57;
                      }
                      else {
                        if (5 < uVar17 - 0x41) goto LAB_00028dec;
                        cVar5 = -0x37;
                      }
                      *pbVar20 = *pbVar20 + cVar5;
                    }
                    iVar22 = iVar22 + -1;
                    pbVar20 = pbVar20 + 1;
                  } while (iVar22 != 0);
                  iVar22 = 0;
                  pbVar20 = (byte *)&local_334;
                  do {
                    bVar2 = *__s_00;
                    iVar22 = iVar22 + 1;
                    pbVar1 = __s_00 + 1;
                    __s_00 = __s_00 + 2;
                    *pbVar20 = *pbVar1 | bVar2 << 4;
                    pbVar20 = pbVar20 + 1;
                  } while (iVar22 != 8);
                }
              }
            }
LAB_00028dec:
            *(undefined2 *)((int)pvVar27 + 10) = 0x100;
            puVar28 = (undefined4 *)((int)pvVar27 + sVar6);
            *puVar28 = local_320;
            sVar26 = sVar6 + 0x1e;
            *(undefined4 *)((int)pvVar27 + sVar6 + 4) = uStack_31c;
            *(undefined2 *)((int)pvVar27 + sVar6 + 8) = local_318;
            *(undefined1 *)((int)pvVar27 + sVar6 + 10) = local_316;
            *(undefined4 *)((int)puVar28 + 0xf) = uStack_328;
            *(undefined4 *)((int)puVar28 + 0xb) = local_32c;
            *(undefined2 *)((int)puVar28 + 0x13) = local_324;
            *(undefined1 *)((int)puVar28 + 0x15) = local_322;
            *(undefined4 *)((int)puVar28 + 0x16) = local_334;
            *(undefined4 *)((int)puVar28 + 0x1a) = uStack_330;
            uVar3 = *(ushort *)((int)pvVar27 + sVar6 + 9);
            uVar17 = ((uVar3 & 0xff) << 8 | (uint)(uVar3 >> 8)) + 0x13;
            *(ushort *)((int)pvVar27 + sVar6 + 9) =
                 (ushort)((uVar17 & 0xff) << 8) | (ushort)(uVar17 >> 8) & 0xff;
          }
          iVar22 = FUN_0002719c(*param_1,&local_2a0,&local_314,local_388,pvVar27,sVar26,param_2,0,
                                bVar21,bVar4);
          iVar8 = *piVar25;
          if (iVar22 != 0) {
            *(int *)(iVar8 + 0x1ee) = *(int *)(iVar8 + 0x1ee) + 1;
            goto LAB_00028560;
          }
        }
        else {
          if ((*(uint *)*piVar25 & 0x2000) == 0) {
            uVar17 = (((uint *)*piVar25)[1] & 0xff) >> 7;
          }
          else {
            uVar17 = 1;
          }
          FUN_000257d0(*param_1,uVar17,pvVar27,iVar8,&local_2a0,&local_314,local_388);
          iVar8 = *piVar25;
        }
        *(int *)(iVar8 + 0x1f6) = *(int *)(iVar8 + 0x1f6) + 1;
      }
      else {
        iVar22 = FUN_00042054(pvVar27,(int)pvVar27 + uVar17,sVar6,param_2,&local_2a0,iVar8,bVar4,
                              uVar10);
        if (iVar22 != 0) {
          if ((*(uint *)*piVar25 & 0x2000) == 0) {
            uVar17 = (((uint *)*piVar25)[1] & 0xff) >> 7;
          }
          else {
            uVar17 = 1;
          }
          FUN_000257d0(*param_1,uVar17,pvVar27,iVar22,&local_2a0,&local_314,local_388);
          *(int *)(*piVar25 + 0x1f2) = *(int *)(*piVar25 + 0x1f2) + 1;
        }
      }
    }
    else {
      puVar28 = *(undefined4 **)(*piVar25 + 0x4be);
      if (iVar8 == 10) {
        for (; puVar28 != (undefined4 *)0x0; puVar28 = (undefined4 *)puVar28[6]) {
          if (((puVar28[4] & 2) != 0) &&
             (iVar8 = FUN_0001bcfc(puVar28,&iStack_298,puVar28[5]), iVar8 != 0)) goto LAB_00028650;
        }
      }
      else {
        for (; puVar28 != (undefined4 *)0x0; puVar28 = (undefined4 *)puVar28[6]) {
          uVar17 = -1 << (0x20 - puVar28[5] & 0xff);
          if (((puVar28[4] & 2) == 0) &&
             (iVar8 = FUN_0001bce8(*puVar28,local_29c.s_addr,
                                   uVar17 << 0x18 | (uVar17 >> 8 & 0xff) << 0x10 |
                                   (uVar17 >> 0x10 & 0xff) << 8 | uVar17 >> 0x18), iVar8 != 0))
          goto LAB_00028650;
        }
      }
      iVar22 = DAT_00028f00;
      if (*(int *)(DAT_00028f00 + 0x28618) == 0) {
        FUN_00037f88(4,DAT_00028f04 + 0x28618);
        *(undefined4 *)(iVar22 + 0x28618) = 1;
      }
    }
  }
LAB_00028560:
  if (local_24 == **(int **)(DAT_00028efc + 0x28570 + DAT_00028ee4)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


===== ENTRY 00047904 =====
===== FUNCTION FUN_00047904 @ 00047904 =====

void FUN_00047904(int param_1,undefined4 param_2)

{
  bool bVar1;
  FILE *pFVar2;
  int iVar3;
  FILE *pFVar4;
  char *pcVar5;
  void *pvVar6;
  undefined4 uVar7;
  FILE *pFVar8;
  int *piVar9;
  int *piVar10;
  char *pcVar11;
  void *pvVar12;
  int iVar13;
  undefined4 *puVar14;
  in_addr __in;
  short local_996;
  int local_994;
  undefined1 auStack_990 [80];
  int local_940;
  in_addr local_928 [128];
  char local_728 [128];
  char local_6a8 [128];
  char *local_628;
  undefined1 auStack_624 [252];
  char local_528 [256];
  char local_428 [1028];
  int local_24;
  
  local_24 = **(int **)(DAT_00047fcc + 0x47920 + DAT_00047fd0);
  local_428[0] = '\0';
  local_428[1] = '\0';
  local_428[2] = '\0';
  local_428[3] = '\0';
  memset(local_428 + 4,0,0x3fd);
  iVar13 = DAT_00047fdc;
  local_994 = 0;
  pFVar2 = fopen64((char *)(DAT_00047fd8 + 0x4796c),(char *)(DAT_00047fd4 + 0x47964));
  iVar13 = iVar13 + 0x47978;
  if (pFVar2 == (FILE *)0x0) {
    FUN_00037f88(6,DAT_00047fe0 + 0x4798c);
    goto LAB_0004798c;
  }
  fclose(pFVar2);
  if ((((param_1 == 0) || ((*(ushort *)(param_1 + 2) & 0xf78) != 0)) ||
      (*(short *)(param_1 + 4) != 0x100)) || (*(short *)(param_1 + 6) == 0)) goto LAB_0004798c;
  iVar3 = FUN_00018918(param_1,param_2,local_428,&local_996);
  if ((iVar3 == 0) || (local_996 != 1)) goto LAB_0004798c;
  piVar10 = *(int **)(iVar13 + DAT_00047fe8);
  iVar3 = *piVar10;
  puVar14 = *(undefined4 **)(iVar13 + DAT_00047fec);
  if ((iVar3 != 0) &&
     ((iVar3 = FUN_00048be4(iVar3,auStack_990), iVar3 != -1 &&
      (piVar9 = *(int **)(iVar13 + DAT_00047ff0), local_940 != *piVar9)))) {
    pcVar11 = (char *)*piVar10;
    local_728[0] = '\0';
    local_728[1] = '\0';
    local_728[2] = '\0';
    local_728[3] = '\0';
    memset(local_728 + 4,0,0x7c);
    pFVar2 = fopen64(pcVar11,(char *)(DAT_00047ff4 + 0x47a8c));
    if (pFVar2 != (FILE *)0x0) {
      pvVar6 = (void *)*puVar14;
      while (iVar13 = DAT_00047ff8, pvVar6 != (void *)0x0) {
        pvVar12 = *(void **)((int)pvVar6 + 0x405);
        free(pvVar6);
        pvVar6 = pvVar12;
      }
      *puVar14 = 0;
      do {
        do {
          local_628 = fgets(local_728,0x80,pFVar2);
          if (local_628 == (char *)0x0) {
            memset(auStack_624,0,0xfc);
            pFVar4 = fopen64((char *)(DAT_00048000 + 0x47af8),(char *)(DAT_00047ffc + 0x47af4));
            if (pFVar4 == (FILE *)0x0) goto LAB_00047b00;
            system((char *)(DAT_00048010 + 0x47c74));
            system((char *)(DAT_00048014 + 0x47c80));
            system((char *)(DAT_00048018 + 0x47c8c));
            iVar13 = DAT_0004801c + 0x47ca0;
            goto LAB_00047ca0;
          }
          pcVar11 = strtok(local_728,(char *)(iVar13 + 0x47ab8));
        } while (pcVar11 == (char *)0x0);
        pcVar5 = (char *)FUN_0001b9c4(0x409);
        __strcpy_chk(pcVar5,pcVar11,0x401);
        pvVar6 = memset(local_928,0,0x200);
        if (*pcVar5 == '*') {
          pcVar5[0x402] = '\0';
          pcVar5[0x401] = '\x01';
          pcVar5[0x403] = '\0';
          pcVar5[0x404] = '\0';
          uVar7 = __strcpy_chk(pvVar6,pcVar5 + 1,0x200);
          __strcpy_chk(pcVar5,uVar7,0x401);
        }
        else {
          pcVar5[0x401] = '\0';
          pcVar5[0x402] = '\0';
          pcVar5[0x403] = '\0';
          pcVar5[0x404] = '\0';
        }
        FUN_00037f88(6,DAT_0004800c + 0x47c44,pcVar5,*(undefined4 *)(pcVar5 + 0x401));
        uVar7 = *puVar14;
        *puVar14 = pcVar5;
        *(undefined4 *)(pcVar5 + 0x405) = uVar7;
      } while( true );
    }
  }
  goto LAB_00047b14;
LAB_00047ca0:
  pcVar11 = fgets((char *)&local_628,0x100,pFVar4);
  iVar3 = DAT_00048020;
  if (pcVar11 == (char *)0x0) goto code_r0x00047cb8;
  bVar1 = false;
  local_528[0] = '\0';
  local_528[1] = '\0';
  local_528[2] = '\0';
  local_528[3] = '\0';
  memset(local_528 + 4,0,0xfc);
  iVar3 = __isoc99_sscanf(&local_628,iVar13,local_528);
  if (0 < iVar3) {
    local_6a8[0] = '\0';
    local_6a8[1] = '\0';
    local_6a8[2] = '\0';
    local_6a8[3] = '\0';
    memset(local_6a8 + 4,0,0x7c);
    pFVar8 = fopen64((char *)(DAT_0004802c + 0x47d54),(char *)(DAT_00048028 + 0x47d50));
    if (pFVar8 != (FILE *)0x0) {
      while (pcVar11 = fgets(local_6a8,0x7f,pFVar8), pcVar11 != (char *)0x0) {
        pcVar11 = strstr(local_6a8,local_528);
        if (pcVar11 != (char *)0x0) {
          bVar1 = true;
        }
      }
      fclose(pFVar8);
      if (bVar1) goto LAB_00047ca0;
      pFVar8 = fopen64((char *)(DAT_00048034 + 0x47dd8),(char *)(DAT_00048030 + 0x47dd4));
      bVar1 = false;
      if (pFVar8 != (FILE *)0x0) {
        while (pcVar11 = fgets(local_6a8,0x7f,pFVar8), pcVar11 != (char *)0x0) {
          pcVar11 = strstr(local_6a8,local_528);
          if (pcVar11 != (char *)0x0) {
            bVar1 = true;
          }
        }
        fclose(pFVar8);
        if (bVar1) goto LAB_00047ca0;
      }
    }
    inet_aton(local_528,local_928);
    FUN_000477d4(local_928[0].s_addr,0);
  }
  goto LAB_00047ca0;
LAB_00047ea0:
  if (local_994 <= iVar13) goto LAB_0004798c;
  __in.s_addr = local_928[iVar13].s_addr;
  local_628 = (char *)0x0;
  memset(auStack_624,0,0xfc);
  local_528[0] = '\0';
  local_528[1] = '\0';
  local_528[2] = '\0';
  local_528[3] = '\0';
  memset(local_528 + 4,0,0xfc);
  pcVar11 = inet_ntoa(__in);
  __snprintf_chk(&local_628,0x100,1,0x100,DAT_00048038 + 0x47f08,local_428,pcVar11);
  pcVar11 = (char *)(DAT_0004803c + 0x47f2c);
  pFVar2 = fopen64(pcVar11,(char *)(DAT_00048040 + 0x47f34));
  if (pFVar2 == (FILE *)0x0) {
    pFVar2 = fopen64(pcVar11,(char *)(DAT_00048044 + 0x47f58));
    if (pFVar2 != (FILE *)0x0) {
      fclose(pFVar2);
    }
LAB_00047f64:
    pFVar2 = fopen64((char *)(DAT_0004804c + 0x47f78),(char *)(DAT_00048048 + 0x47f74));
    if (pFVar2 != (FILE *)0x0) {
      __strcat_chk(&local_628,DAT_00048050 + 0x47f94,0x100);
      fputs((char *)&local_628,pFVar2);
      fclose(pFVar2);
      FUN_000477d4(__in.s_addr,1);
    }
  }
  else {
    do {
      pcVar11 = fgets(local_528,0x100,pFVar2);
      if (pcVar11 == (char *)0x0) {
        bVar1 = false;
        goto LAB_00047e8c;
      }
      pcVar11 = strstr(local_528,(char *)&local_628);
    } while (pcVar11 == (char *)0x0);
    bVar1 = true;
LAB_00047e8c:
    fclose(pFVar2);
    if (!bVar1) goto LAB_00047f64;
  }
  iVar13 = iVar13 + 1;
  goto LAB_00047ea0;
code_r0x00047cb8:
  fclose(pFVar4);
  unlink((char *)(iVar3 + 0x47ccc));
  pFVar4 = fopen64((char *)(iVar3 + 0x47ccc),(char *)(DAT_00048024 + 0x47ce0));
  if (pFVar4 != (FILE *)0x0) {
    fclose(pFVar4);
  }
LAB_00047b00:
  fclose(pFVar2);
  *piVar9 = local_940;
LAB_00047b14:
  for (pcVar11 = (char *)*puVar14; pcVar11 != (char *)0x0; pcVar11 = *(char **)(pcVar11 + 0x405)) {
    if (*(int *)(pcVar11 + 0x401) == 0) {
      pcVar5 = strstr(pcVar11,local_428);
      if (pcVar5 != (char *)0x0) {
LAB_00047b40:
        FUN_00037f88(6,DAT_00048004 + 0x47b54);
        FUN_00017c1c(&local_994,local_928,param_1,param_2);
        FUN_00037f88(6,DAT_00048008 + 0x47b7c,local_994);
        if (local_994 != 0) {
          iVar13 = 0;
          goto LAB_00047ea0;
        }
        break;
      }
    }
    else {
      pcVar5 = strstr(local_428,pcVar11);
      if ((pcVar5 != (char *)0x0) && (iVar13 = strcmp(pcVar11,pcVar5), iVar13 == 0))
      goto LAB_00047b40;
    }
  }
LAB_0004798c:
  if (local_24 != **(int **)(DAT_00047fe4 + 0x4799c + DAT_00047fd0)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

