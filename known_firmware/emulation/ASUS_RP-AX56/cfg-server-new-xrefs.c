STRING 00092291 [%s(%d)]:Checking length error !!!

REF 00072d48 owner=FUN_00072ab8
REF 00072d98 owner=FUN_00072ab8
REF 0001bc40 owner=cm_udpPacketHandler
REF 0001bc8c owner=cm_udpPacketHandler
REF 00053ce0 owner=FUN_00053bd4
REF 00053d2c owner=FUN_00053bd4
STRING 0009244f [%s(%d)]:error on received size(%d)

REF 0001c75c owner=FUN_0001c310
REF 0001c7b0 owner=FUN_0001c310
STRING 00099aeb [%s(%d)]:add conn diag pkt to list

REF 00053adc owner=FUN_00053938
REF 00053b2c owner=FUN_00053938
STRING 0009a8f4 [%s(%d)]:%s(%d) get master key ...

REF 000578d8 owner=FUN_0005742c
REF 00057938 owner=FUN_0005742c
STRING 0009a967 [%s(%d)]:The length of master key is %d

REF 000580fc owner=FUN_0005742c
REF 00058150 owner=FUN_0005742c
CALLER_REF target=FUN_00072ab8 from=00074250 owner=FUN_00073450
CALLER_REF target=FUN_00072ab8 from=00082f4c owner=cm_tcpPacketHandler
CALLER_REF target=cm_udpPacketHandler from=Entry Point owner=NONE
CALLER_REF target=cm_udpPacketHandler from=000b24bc owner=NONE
CALLER_REF target=cm_udpPacketHandler from=0001c97c owner=FUN_0001c310
CALLER_REF target=cm_udpPacketHandler from=0001c984 owner=FUN_0001c310
CALLER_REF target=FUN_00053bd4 from=00054084 owner=cm_connDiagPktListHandler
CALLER_REF target=FUN_0001c310 from=0008d170 owner=FUN_0008cf98
CALLER_REF target=FUN_00053938 from=0001c968 owner=FUN_0001c310
CALLER_REF target=FUN_0005742c from=00072eb4 owner=FUN_00072ab8

===== FUN_00072ab8 @ 00072ab8 =====

undefined4
FUN_00072ab8(int param_1,uint *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  ssize_t sVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar17 = DAT_000732e0 + 0x72ad4;
  if (param_2 == (uint *)0x0) {
    pcVar1 = (char *)FUN_00054250(DAT_000732e4 + 0x72ae0);
    iVar17 = strcmp(pcVar1,(char *)(DAT_000732e8 + 0x72aec));
    if (iVar17 == 0) {
      cprintf(DAT_000732f0 + 0x72b0c,DAT_000732ec + 0x72b08,0x3466);
    }
    pcVar1 = (char *)FUN_00054250(DAT_000732f4 + 0x72b18);
    iVar17 = strcmp(pcVar1,(char *)(DAT_000732f8 + 0x72b24));
    if (iVar17 == 0) {
      uVar18 = 0x3466;
      iVar11 = DAT_000732fc + 0x72b44;
      iVar17 = DAT_00073300 + 0x72b50;
      iVar12 = DAT_00073304 + 0x72b54;
LAB_0007322c:
      asusdebuglog(6,iVar17,0,1,0,iVar12,iVar11,uVar18);
    }
LAB_00073234:
    uVar18 = 1;
  }
  else {
    pcVar1 = (char *)FUN_00054250(DAT_00073308 + 0x72b70);
    iVar11 = strcmp(pcVar1,(char *)(DAT_0007330c + 0x72b7c));
    if (iVar11 == 0) {
      cprintf(DAT_00073314 + 0x72ba0,DAT_00073310 + 0x72b9c,0x346c,param_3);
    }
    pcVar1 = (char *)FUN_00054250(DAT_00073318 + 0x72bac);
    iVar11 = strcmp(pcVar1,(char *)(DAT_0007331c + 0x72bb8));
    if (iVar11 == 0) {
      asusdebuglog(6,DAT_00073324 + 0x72be8,0,1,0,DAT_00073328 + 470000,DAT_00073320 + 0x72bdc,
                   0x346c,param_3);
    }
    iVar11 = DAT_0007332c + 0x72c08;
    pcVar1 = (char *)(DAT_00073330 + 0x72c14);
    iVar12 = DAT_00073334 + 0x72c20;
    iVar13 = DAT_00073338 + 0x72c2c;
    iVar14 = DAT_0007333c + 0x72c38;
    for (iVar16 = 0; iVar16 < (int)param_3; iVar16 = iVar16 + 0xcU + uVar2) {
      if (param_3 < iVar16 + 0xcU) {
        pcVar1 = (char *)FUN_00054250(DAT_00073340 + 0x72c58);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00073344 + 0x72c64));
        if (iVar17 == 0) {
          cprintf(DAT_0007334c + 0x72c84,DAT_00073348 + 0x72c80,0x3472);
        }
        pcVar1 = (char *)FUN_00054250(DAT_00073350 + 0x72c90);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00073354 + 0x72c9c));
        if (iVar17 == 0) {
          asusdebuglog(6,DAT_0007335c + 0x72cd8,0,1,0,DAT_00073360 + 0x72ce0,DAT_00073358 + 0x72ccc,
                       0x3472);
          return 0;
        }
        break;
      }
      uVar2 = *param_2;
      uVar7 = param_2[1];
      uVar3 = param_2[2];
      if (param_3 - 0xc !=
          (uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 | uVar7 >> 0x18
          )) {
        pcVar1 = (char *)FUN_00054250(DAT_00073364 + 0x72d24);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00073368 + 0x72d30));
        if (iVar17 == 0) {
          cprintf(DAT_00073370 + 0x72d50,DAT_0007336c + 0x72d4c,0x3479);
        }
        pcVar1 = (char *)FUN_00054250(DAT_00073374 + 0x72d5c);
        iVar17 = strcmp(pcVar1,(char *)(DAT_00073378 + 0x72d68));
        if (iVar17 == 0) {
          asusdebuglog(6,DAT_00073380 + 0x72d98,0,1,0,DAT_00073384 + 0x72d9c,DAT_0007337c + 0x72d8c,
                       0x3479);
        }
LAB_0007317c:
        local_28 = 0;
        local_24 = 0;
        local_2c = 0x7000000;
        sVar6 = write(param_1,&local_2c,0xc);
        if (sVar6 == 0xc) goto LAB_00073234;
        pcVar1 = (char *)FUN_00054250(DAT_00073408 + 0x731b4);
        iVar17 = strcmp(pcVar1,(char *)(DAT_0007340c + 0x731c0));
        if (iVar17 == 0) {
          cprintf(DAT_00073414 + 0x731e0,DAT_00073410 + 0x731dc,0x34c2);
        }
        pcVar1 = (char *)FUN_00054250(DAT_00073418 + 0x731ec);
        iVar17 = strcmp(pcVar1,(char *)(DAT_0007341c + 0x731f8));
        if (iVar17 != 0) goto LAB_00073234;
        uVar18 = 0x34c2;
        iVar11 = DAT_00073420 + 0x73218;
        iVar17 = DAT_00073424 + 0x73224;
        iVar12 = DAT_00073428 + 0x73228;
        goto LAB_0007322c;
      }
      pcVar4 = (char *)FUN_00054250(iVar11);
      iVar5 = strcmp(pcVar4,pcVar1);
      uVar15 = uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
               uVar2 >> 0x18;
      if (iVar5 == 0) {
        uVar18 = FUN_0005420c(uVar15);
        cprintf(iVar13,iVar12,0x3483,uVar18);
      }
      pcVar4 = (char *)FUN_00054250(iVar14);
      iVar5 = strcmp(pcVar4,(char *)(DAT_00073388 + 0x72dfc));
      if (iVar5 == 0) {
        uVar18 = FUN_0005420c(uVar15);
        asusdebuglog(6,DAT_00073390 + 0x72e34,0,1,0,DAT_00073394 + 0x72e3c,DAT_0007338c + 0x72e28,
                     0x3483,uVar18);
      }
      iVar5 = 0;
      do {
        iVar9 = *(int *)(iVar17 + DAT_00073398);
        iVar8 = iVar5 + iVar9;
        uVar10 = *(uint *)(iVar5 + iVar9);
        if ((int)uVar10 < 1) {
          if ((int)uVar10 < 0) {
            pcVar4 = (char *)FUN_00054250(DAT_0007342c + 0x73248);
            iVar5 = strcmp(pcVar4,(char *)(DAT_00073430 + 0x73254));
            if (iVar5 == 0) {
              cprintf(DAT_00073438 + 0x73278,DAT_00073434 + 0x73274,0x348c,uVar15);
            }
            pcVar4 = (char *)FUN_00054250(DAT_0007343c + 0x73284);
            iVar5 = strcmp(pcVar4,(char *)(DAT_00073440 + 0x73290));
            if (iVar5 == 0) {
              asusdebuglog(6,DAT_00073448 + 0x732c0,0,1,0,DAT_0007344c + 0x732c8,
                           DAT_00073444 + 0x732b4,0x348c,uVar15);
            }
            goto LAB_00072ec0;
          }
          break;
        }
        iVar5 = iVar5 + 8;
      } while (uVar10 != uVar15);
      iVar5 = (**(code **)(iVar8 + 4))
                        (param_1,param_6,uVar2,uVar7,uVar3,param_7,param_2 + 3,param_4,param_5);
      if (iVar5 == 0) goto LAB_0007317c;
LAB_00072ec0:
      switch(uVar15) {
      case 7:
        pcVar1 = (char *)FUN_00054250(DAT_0007339c + 0x72fb0);
        iVar17 = strcmp(pcVar1,(char *)(DAT_000733a0 + 0x72fbc));
        if (iVar17 == 0) {
          cprintf(DAT_000733a8 + 0x72fdc,DAT_000733a4 + 0x72fd8,0x3496);
        }
        pcVar1 = (char *)FUN_00054250(DAT_000733ac + 0x72fe8);
        iVar17 = strcmp(pcVar1,(char *)(DAT_000733b0 + 0x72ff4));
        if (iVar17 == 0) {
          asusdebuglog(6,DAT_000733b8 + 0x73024,0,1,0,DAT_000733bc + 0x73028,DAT_000733b4 + 0x73018,
                       0x3496);
        }
        pcVar1 = (char *)FUN_00054250(DAT_000733c0 + 0x7303c);
        iVar17 = strcmp(pcVar1,(char *)(DAT_000733c4 + 0x73048));
        if (iVar17 == 0) {
          cprintf(DAT_000733cc + 0x73068,DAT_000733c8 + 0x73064,0x3497);
        }
        pcVar1 = (char *)FUN_00054250(DAT_000733d0 + 0x73074);
        iVar17 = strcmp(pcVar1,(char *)(DAT_000733d4 + 0x73080));
        if (iVar17 != 0) goto LAB_00073234;
        uVar18 = 0x3497;
        iVar11 = DAT_000733d8 + 0x730a0;
        iVar17 = DAT_000733dc + 0x730ac;
        iVar12 = DAT_000733e0 + 0x730b0;
        goto LAB_0007322c;
      case 8:
        break;
      case 9:
        break;
      case 10:
        goto LAB_000730b8;
      case 0xb:
        break;
      case 0xc:
        break;
      case 0xd:
        break;
      case 0xe:
        goto LAB_000730b8;
      case 0xf:
        goto LAB_000730b8;
      case 0x10:
        break;
      case 0x11:
        break;
      case 0x12:
        goto LAB_000730b8;
      case 0x13:
        break;
      case 0x14:
        goto LAB_000730b8;
      case 0x15:
        break;
      case 0x16:
        goto LAB_000730b8;
      case 0x17:
        goto LAB_000730b8;
      case 0x18:
        break;
      case 0x19:
        goto LAB_000730b8;
      case 0x1a:
        break;
      case 0x1b:
        goto LAB_000730b8;
      case 0x1c:
        break;
      case 0x1d:
        goto LAB_000730b8;
      case 0x1e:
        break;
      case 0x1f:
        break;
      case 0x20:
        break;
      case 0x21:
        goto LAB_000730b8;
      case 0x22:
        goto LAB_000730b8;
      case 0x23:
        break;
      case 0x24:
        goto LAB_000730b8;
      case 0x25:
        break;
      case 0x26:
        goto LAB_000730b8;
      case 0x27:
        break;
      case 0x28:
        break;
      case 0x29:
        break;
      case 0x2a:
        goto LAB_000730b8;
      case 0x2b:
        goto LAB_000730b8;
      case 0x2c:
        break;
      case 0x2d:
        goto LAB_000730b8;
      case 0x2e:
        break;
      case 0x2f:
        goto LAB_000730b8;
      case 0x30:
        break;
      case 0x31:
        goto LAB_000730b8;
      case 0x32:
        break;
      case 0x33:
        goto LAB_000730b8;
      case 0x34:
        break;
      case 0x35:
        goto LAB_000730b8;
      case 0x36:
        break;
      case 0x37:
        goto LAB_000730b8;
      case 0x38:
        break;
      case 0x39:
        break;
      case 0x3a:
        break;
      case 0x3b:
LAB_000730b8:
        pcVar1 = (char *)FUN_00054250(DAT_000733e4 + 0x730c4);
        iVar17 = strcmp(pcVar1,(char *)(DAT_000733e8 + 0x730d0));
        if (iVar17 == 0) {
          uVar18 = FUN_0005420c(uVar15);
          cprintf(DAT_000733f0 + 0x730fc,DAT_000733ec + 0x730f0,0x34b5,uVar18);
        }
        pcVar1 = (char *)FUN_00054250(DAT_000733f4 + 0x73108);
        iVar17 = strcmp(pcVar1,(char *)(DAT_000733f8 + 0x73114));
        if (iVar17 == 0) {
          uVar18 = FUN_0005420c(uVar15);
          asusdebuglog(6,DAT_00073400 + 0x7314c,0,1,0,DAT_00073404 + 0x73154,DAT_000733fc + 0x73140,
                       0x34b5,uVar18);
        }
        goto LAB_00073234;
      }
      uVar2 = uVar7 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
              uVar7 >> 0x18;
      param_2 = (uint *)((int)(param_2 + 3) + uVar2);
    }
    uVar18 = 0;
  }
  return uVar18;
}



===== cm_udpPacketHandler @ 0001baa0 =====

undefined4 cm_udpPacketHandler(uint *param_1)

{
  pthread_t __th;
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  bool bVar10;
  undefined4 uVar11;
  
  __th = pthread_self();
  pthread_detach(__th);
  if (param_1 == (uint *)0x0) {
    pcVar1 = (char *)FUN_0001ba80(DAT_0001bdac + 0x1bac8);
    iVar2 = strcmp(pcVar1,(char *)(DAT_0001bdb0 + 0x1bad4));
    if (iVar2 == 0) {
      cprintf(DAT_0001bdb8 + 0x1baf4,DAT_0001bdb4 + 0x1baf0,0x72);
    }
    pcVar1 = (char *)FUN_0001ba80(DAT_0001bdbc + 0x1bb00);
    iVar2 = strcmp(pcVar1,(char *)(DAT_0001bdc0 + 0x1bb0c));
    if (iVar2 != 0) goto LAB_0001bd98;
    uVar11 = 0x72;
    iVar7 = DAT_0001bdc4 + 0x1bb2c;
    iVar2 = DAT_0001bdc8 + 0x1bb38;
    iVar8 = DAT_0001bdcc + 0x1bb3c;
  }
  else if (param_1[0x200] < 0xc) {
    pcVar1 = (char *)FUN_0001ba80(DAT_0001bdd0 + 0x1bb5c);
    iVar2 = strcmp(pcVar1,(char *)(DAT_0001bdd4 + 0x1bb68));
    if (iVar2 == 0) {
      cprintf(DAT_0001bddc + 0x1bb88,DAT_0001bdd8 + 0x1bb84,0x7a);
    }
    pcVar1 = (char *)FUN_0001ba80(DAT_0001bde0 + 0x1bb94);
    iVar2 = strcmp(pcVar1,(char *)(DAT_0001bde4 + 0x1bba0));
    if (iVar2 != 0) goto LAB_0001bd98;
    uVar11 = 0x7a;
    iVar7 = DAT_0001bde8 + 0x1bbc0;
    iVar2 = DAT_0001bdec + 0x1bbcc;
    iVar8 = DAT_0001bdf0 + 0x1bbd0;
  }
  else {
    uVar3 = *param_1;
    uVar6 = param_1[1];
    uVar4 = param_1[2];
    if (param_1[0x200] - 0xc ==
        (uVar6 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 | uVar6 >> 0x18))
    {
      puVar9 = param_1 + 3;
      uVar5 = FUN_0001ba40(0,puVar9);
      if (uVar5 == (uVar4 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
                   uVar4 >> 0x18)) {
        uVar5 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
                uVar3 >> 0x18;
        if (uVar5 != 0) {
          bVar10 = 6 < uVar5;
          if (uVar5 != 7) {
            bVar10 = 3 < uVar5;
          }
          if (!bVar10 || (uVar5 == 7 || uVar5 == 4)) {
            FUN_00042d38(uVar3,uVar6,uVar4,puVar9,param_1 + 0x201);
          }
        }
        if (uVar5 - 5 < 2) {
          FUN_000531f4(uVar3,uVar6,uVar4,puVar9,param_1 + 0x201);
        }
        goto LAB_0001bd98;
      }
      pcVar1 = (char *)FUN_0001ba80(DAT_0001be18 + 0x1bcc4);
      iVar2 = strcmp(pcVar1,(char *)(DAT_0001be1c + 0x1bcd0));
      if (iVar2 == 0) {
        cprintf(DAT_0001be24 + 0x1bcf0,DAT_0001be20 + 0x1bcec,0x8a);
      }
      pcVar1 = (char *)FUN_0001ba80(DAT_0001be28 + 0x1bcfc);
      iVar2 = strcmp(pcVar1,(char *)(DAT_0001be2c + 0x1bd08));
      if (iVar2 != 0) goto LAB_0001bd98;
      uVar11 = 0x8a;
      iVar7 = DAT_0001be30 + 0x1bd28;
      iVar2 = DAT_0001be34 + 0x1bd34;
      iVar8 = DAT_0001be38 + 0x1bd38;
    }
    else {
      pcVar1 = (char *)FUN_0001ba80(DAT_0001bdf4 + 0x1bc1c);
      iVar2 = strcmp(pcVar1,(char *)(DAT_0001bdf8 + 0x1bc28));
      if (iVar2 == 0) {
        cprintf(DAT_0001be00 + 0x1bc48,DAT_0001bdfc + 0x1bc44,0x85);
      }
      pcVar1 = (char *)FUN_0001ba80(DAT_0001be04 + 0x1bc54);
      iVar2 = strcmp(pcVar1,(char *)(DAT_0001be08 + 0x1bc60));
      if (iVar2 != 0) goto LAB_0001bd98;
      uVar11 = 0x85;
      iVar7 = DAT_0001be0c + 0x1bc80;
      iVar2 = DAT_0001be10 + 0x1bc8c;
      iVar8 = DAT_0001be14 + 0x1bc90;
    }
  }
  asusdebuglog(6,iVar2,0,1,0,iVar8,iVar7,uVar11);
LAB_0001bd98:
  free(param_1);
  return 1;
}



===== FUN_00053bd4 @ 00053bd4 =====

void FUN_00053bd4(void)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  pthread_mutex_t *__mutex;
  int *piVar7;
  int iVar8;
  char *__s2;
  int iVar9;
  char *__s2_00;
  int iVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  
  iVar14 = DAT_00053eb0 + 0x53bec;
  __mutex = *(pthread_mutex_t **)(iVar14 + DAT_00053eb4);
  pthread_mutex_lock(__mutex);
  piVar6 = *(int **)(iVar14 + DAT_00053eb8);
  piVar7 = (int *)*piVar6;
  if (0 < piVar7[2]) {
    iVar8 = DAT_00053ebc + 0x53c2c;
    iVar15 = DAT_00053ec0 + 0x53c38;
    __s2 = (char *)(DAT_00053ec4 + 0x53c3c);
    iVar9 = DAT_00053ec8 + 0x53c48;
    __s2_00 = (char *)(DAT_00053ecc + 0x53c54);
    for (piVar7 = (int *)*piVar7; piVar7 != (int *)0x0; piVar7 = (int *)*piVar7) {
      piVar12 = (int *)piVar7[2];
      if (piVar12 != (int *)0x0) {
        if (**(int **)(iVar14 + DAT_00053ed0) != 0) break;
        iVar1 = *piVar12;
        uVar5 = piVar12[1];
        uVar2 = piVar12[2];
        if (piVar12[0x200] - 0xcU ==
            (uVar5 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
            uVar5 >> 0x18)) {
          uVar4 = FUN_0001ba40(0,piVar12 + 3);
          if (uVar4 == (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                       uVar2 >> 0x18)) {
            if (iVar1 == 0x6000000) {
              pcVar3 = (char *)FUN_00051aec(iVar8);
              iVar1 = strcmp(pcVar3,__s2);
              piVar13 = piVar12 + 0x201;
              if (iVar1 == 0) {
                cprintf(DAT_00053f20 + 0x53e30,DAT_00053f1c + 0x53e2c,0x256,piVar13);
              }
              pcVar3 = (char *)FUN_00051aec(iVar9);
              iVar1 = strcmp(pcVar3,__s2_00);
              if (iVar1 == 0) {
                asusdebuglog(6,iVar15,0,1,0,DAT_00053f28 + 0x53e74,DAT_00053f24 + 0x53e68,0x256,
                             piVar13);
              }
              FUN_000531f4(0x6000000,uVar5,uVar2,piVar12 + 3,piVar13);
            }
          }
          else {
            pcVar3 = (char *)FUN_00051aec(DAT_00053ef8 + 0x53d64);
            iVar1 = strcmp(pcVar3,(char *)(DAT_00053efc + 0x53d70));
            if (iVar1 == 0) {
              cprintf(DAT_00053f04 + 0x53d90,DAT_00053f00 + 0x53d8c,0x251);
            }
            pcVar3 = (char *)FUN_00051aec(DAT_00053f08 + 0x53d9c);
            iVar1 = strcmp(pcVar3,(char *)(DAT_00053f0c + 0x53da8));
            if (iVar1 == 0) {
              uVar16 = 0x251;
              iVar10 = DAT_00053f10 + 0x53dc8;
              iVar1 = DAT_00053f14 + 0x53dd4;
              iVar11 = DAT_00053f18 + 0x53dd8;
              goto LAB_00053ddc;
            }
          }
        }
        else {
          pcVar3 = (char *)FUN_00051aec(DAT_00053ed4 + 0x53cbc);
          iVar1 = strcmp(pcVar3,(char *)(DAT_00053ed8 + 0x53cc8));
          if (iVar1 == 0) {
            cprintf(DAT_00053ee0 + 0x53ce8,DAT_00053edc + 0x53ce4,0x24c);
          }
          pcVar3 = (char *)FUN_00051aec(DAT_00053ee4 + 0x53cf4);
          iVar1 = strcmp(pcVar3,(char *)(DAT_00053ee8 + 0x53d00));
          if (iVar1 == 0) {
            uVar16 = 0x24c;
            iVar10 = DAT_00053eec + 0x53d20;
            iVar1 = DAT_00053ef0 + 0x53d2c;
            iVar11 = DAT_00053ef4 + 0x53d30;
LAB_00053ddc:
            asusdebuglog(6,iVar1,0,1,0,iVar11,iVar10,uVar16);
          }
        }
      }
    }
    list_delete_all_node(*piVar6);
  }
  pthread_mutex_unlock(__mutex);
  return;
}



===== FUN_0001c310 @ 0001c310 =====

void FUN_0001c310(void)

{
  uint __n;
  char *pcVar1;
  void *__s;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  socklen_t local_844;
  pthread_t pStack_840;
  int local_83c;
  uint local_838;
  undefined4 uStack_834;
  sockaddr sStack_830;
  int local_820;
  uint uStack_81c;
  undefined4 uStack_818;
  
  memset(&local_820,0,0x800);
  iVar4 = DAT_0001ca44 + 0x1c34c;
  memset(&sStack_830,0,0x10);
  local_844 = 0x10;
  iVar5 = *(int *)(iVar4 + DAT_0001ca48);
  __n = recvfrom(*(int *)(iVar5 + 0x10),&local_820,0x7ff,0,&sStack_830,&local_844);
  if (__n == 0xffffffff) {
    pcVar1 = (char *)FUN_0001ba80(DAT_0001ca4c + 0x1c390);
    iVar4 = strcmp(pcVar1,(char *)(DAT_0001ca50 + 0x1c39c));
    if (iVar4 == 0) {
      cprintf(DAT_0001ca58 + 0x1c3bc,DAT_0001ca54 + 0x1c3b8,0xca);
    }
    pcVar1 = (char *)FUN_0001ba80(DAT_0001ca5c + 0x1c3c8);
    iVar4 = strcmp(pcVar1,(char *)(DAT_0001ca60 + 0x1c3d4));
    if (iVar4 != 0) {
      return;
    }
    uVar6 = 0xca;
    iVar5 = DAT_0001ca64 + 0x1c3f4;
    iVar4 = DAT_0001ca68 + 0x1c400;
    iVar2 = DAT_0001ca6c + 0x1c404;
  }
  else if (sStack_830.sa_data._2_4_ == *(uint *)(iVar5 + 0x18)) {
    pcVar1 = (char *)FUN_0001ba80(DAT_0001ca70 + 0x1c428);
    iVar4 = strcmp(pcVar1,(char *)(DAT_0001ca74 + 0x1c434));
    if (iVar4 == 0) {
      cprintf(DAT_0001ca7c + 0x1c454,DAT_0001ca78 + 0x1c450,0xcf);
    }
    pcVar1 = (char *)FUN_0001ba80(DAT_0001ca80 + 0x1c460);
    iVar4 = strcmp(pcVar1,(char *)(DAT_0001ca84 + 0x1c46c));
    if (iVar4 != 0) {
      return;
    }
    uVar6 = 0xcf;
    iVar5 = DAT_0001ca88 + 0x1c48c;
    iVar4 = DAT_0001ca8c + 0x1c498;
    iVar2 = DAT_0001ca90 + 0x1c49c;
  }
  else {
    pcVar1 = (char *)FUN_0001ba80(DAT_0001ca94 + 0x1c4b8);
    iVar2 = strcmp(pcVar1,(char *)(DAT_0001ca98 + 0x1c4c4));
    if (iVar2 == 0) {
      uVar3 = *(uint *)(iVar5 + 0x18);
      cprintf(DAT_0001caa0 + 0x1c4ec,DAT_0001ca9c + 0x1c4e4,0xd7,uVar3 & 0xff,uVar3 >> 8 & 0xff,
              uVar3 >> 0x10 & 0xff,uVar3 >> 0x18);
    }
    pcVar1 = (char *)FUN_0001ba80(DAT_0001caa4 + 0x1c514);
    iVar2 = strcmp(pcVar1,(char *)(DAT_0001caa8 + 0x1c520));
    if (iVar2 == 0) {
      uVar3 = *(uint *)(iVar5 + 0x18);
      asusdebuglog(6,DAT_0001cab0 + 0x1c578,0,1,0,DAT_0001cab4 + 0x1c57c,DAT_0001caac + 0x1c568,0xd7
                   ,uVar3 & 0xff,uVar3 >> 8 & 0xff,uVar3 >> 0x10 & 0xff,uVar3 >> 0x18);
    }
    pcVar1 = (char *)FUN_0001ba80(DAT_0001cab8 + 0x1c590);
    iVar5 = strcmp(pcVar1,(char *)(DAT_0001cabc + 0x1c59c));
    if (iVar5 == 0) {
      cprintf(DAT_0001cac4 + 0x1c5c4,DAT_0001cac0 + 0x1c5bc,0xdd,sStack_830.sa_data._2_4_ & 0xff,
              (uint)sStack_830.sa_data._2_4_ >> 8 & 0xff,
              (uint)sStack_830.sa_data._2_4_ >> 0x10 & 0xff,(uint)sStack_830.sa_data._2_4_ >> 0x18);
    }
    pcVar1 = (char *)FUN_0001ba80(DAT_0001cac8 + 0x1c5ec);
    iVar5 = strcmp(pcVar1,(char *)(DAT_0001cacc + 0x1c5f8));
    if (iVar5 == 0) {
      asusdebuglog(6,DAT_0001cad4 + 0x1c650,0,1,0,DAT_0001cad8 + 0x1c654,DAT_0001cad0 + 0x1c640,0xdd
                   ,sStack_830.sa_data._2_4_ & 0xff,(uint)sStack_830.sa_data._2_4_ >> 8 & 0xff,
                   (uint)sStack_830.sa_data._2_4_ >> 0x10 & 0xff,
                   (uint)sStack_830.sa_data._2_4_ >> 0x18);
    }
    uStack_834 = uStack_818;
    local_838 = uStack_81c;
    local_83c = local_820;
    pcVar1 = (char *)FUN_0001ba80(DAT_0001cadc + 0x1c670);
    iVar5 = strcmp(pcVar1,(char *)(DAT_0001cae0 + 0x1c67c));
    if (iVar5 == 0) {
      uVar3 = local_838 << 0x18 | (local_838 >> 8 & 0xff) << 0x10 | (local_838 >> 0x10 & 0xff) << 8
              | local_838 >> 0x18;
      cprintf(DAT_0001cae8 + 0x1c6b0,DAT_0001cae4 + 0x1c6a4,0xe2,uVar3,uVar3,__n,__n - 0xc);
    }
    pcVar1 = (char *)FUN_0001ba80(DAT_0001caec + 0x1c6bc);
    iVar5 = strcmp(pcVar1,(char *)(DAT_0001caf0 + 0x1c6c8));
    if (iVar5 == 0) {
      uVar3 = local_838 << 0x18 | (local_838 >> 8 & 0xff) << 0x10 | (local_838 >> 0x10 & 0xff) << 8
              | local_838 >> 0x18;
      asusdebuglog(6,DAT_0001caf8 + 0x1c710,0,1,0,DAT_0001cafc + 0x1c718,DAT_0001caf4 + 0x1c704,0xe2
                   ,uVar3,uVar3,__n,__n - 0xc);
    }
    if (__n < 0xc) {
      pcVar1 = (char *)FUN_0001ba80(DAT_0001cb00 + 0x1c734);
      iVar4 = strcmp(pcVar1,(char *)(DAT_0001cb04 + 0x1c740));
      if (iVar4 == 0) {
        cprintf(DAT_0001cb0c + 0x1c764,DAT_0001cb08 + 0x1c760,0xe5,__n);
      }
      pcVar1 = (char *)FUN_0001ba80(DAT_0001cb10 + 0x1c770);
      iVar4 = strcmp(pcVar1,(char *)(DAT_0001cb14 + 0x1c77c));
      if (iVar4 != 0) {
        return;
      }
      asusdebuglog(6,DAT_0001cb1c + 0x1c7ac,0,1,0,DAT_0001cb20 + 0x1c7b4,DAT_0001cb18 + 0x1c7a0,0xe5
                   ,__n);
      return;
    }
    if ((local_838 << 0x18 | (local_838 >> 8 & 0xff) << 0x10 | (local_838 >> 0x10 & 0xff) << 8 |
        local_838 >> 0x18) == __n - 0xc) {
      __s = malloc(0x824);
      if (__s != (void *)0x0) {
        memset(__s,0,0x824);
        memcpy(__s,&local_820,__n);
        *(uint *)((int)__s + 0x800) = __n;
        snprintf((char *)((int)__s + 0x804),0x20,(char *)(DAT_0001cb6c + 0x1c958),
                 sStack_830.sa_data._2_4_ & 0xff,(uint)sStack_830.sa_data._2_4_ >> 8 & 0xff,
                 (uint)sStack_830.sa_data._2_4_ >> 0x10 & 0xff,
                 (uint)sStack_830.sa_data._2_4_ >> 0x18);
        if (local_83c == 0x6000000) {
          FUN_00053938(__s);
          return;
        }
        iVar4 = pthread_create(&pStack_840,(pthread_attr_t *)**(undefined4 **)(iVar4 + DAT_0001cb74)
                               ,*(__start_routine **)(iVar4 + DAT_0001cb70),__s);
        if (iVar4 == 0) {
          return;
        }
        pcVar1 = (char *)FUN_0001ba80(DAT_0001cb78 + 0x1c9ac);
        iVar4 = strcmp(pcVar1,(char *)(DAT_0001cb7c + 0x1c9b8));
        if (iVar4 == 0) {
          cprintf(DAT_0001cb84 + 0x1c9d8,DAT_0001cb80 + 0x1c9d4,0x107);
        }
        pcVar1 = (char *)FUN_0001ba80(DAT_0001cb88 + 0x1c9e4);
        iVar4 = strcmp(pcVar1,(char *)(DAT_0001cb8c + 0x1c9f0));
        if (iVar4 == 0) {
          asusdebuglog(6,DAT_0001cb94 + 0x1ca20,0,1,0,DAT_0001cb98 + 0x1ca24,DAT_0001cb90 + 0x1ca14,
                       0x107);
        }
        free(__s);
        return;
      }
      pcVar1 = (char *)FUN_0001ba80(DAT_0001cb48 + 0x1c878);
      iVar4 = strcmp(pcVar1,(char *)(DAT_0001cb4c + 0x1c884));
      if (iVar4 == 0) {
        cprintf(DAT_0001cb54 + 0x1c8a4,DAT_0001cb50 + 0x1c8a0,0xf1);
      }
      pcVar1 = (char *)FUN_0001ba80(DAT_0001cb58 + 0x1c8b0);
      iVar4 = strcmp(pcVar1,(char *)(DAT_0001cb5c + 0x1c8bc));
      if (iVar4 != 0) {
        return;
      }
      uVar6 = 0xf1;
      iVar5 = DAT_0001cb60 + 0x1c8dc;
      iVar4 = DAT_0001cb64 + 0x1c8e8;
      iVar2 = DAT_0001cb68 + 0x1c8ec;
    }
    else {
      pcVar1 = (char *)FUN_0001ba80(DAT_0001cb24 + 0x1c7e0);
      iVar4 = strcmp(pcVar1,(char *)(DAT_0001cb28 + 0x1c7ec));
      if (iVar4 == 0) {
        cprintf(DAT_0001cb30 + 0x1c80c,DAT_0001cb2c + 0x1c808,0xea);
      }
      pcVar1 = (char *)FUN_0001ba80(DAT_0001cb34 + 0x1c818);
      iVar4 = strcmp(pcVar1,(char *)(DAT_0001cb38 + 0x1c824));
      if (iVar4 != 0) {
        return;
      }
      uVar6 = 0xea;
      iVar5 = DAT_0001cb3c + 0x1c844;
      iVar4 = DAT_0001cb40 + 0x1c850;
      iVar2 = DAT_0001cb44 + 0x1c854;
    }
  }
  asusdebuglog(6,iVar4,0,1,0,iVar2,iVar5,uVar6);
  return;
}



===== FUN_00053938 @ 00053938 =====

void FUN_00053938(void *param_1)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  pthread_mutex_t *__mutex;
  
  piVar3 = *(int **)(DAT_00053b5c + 0x53948 + DAT_00053b60);
  if (*piVar3 != 0) {
    __mutex = *(pthread_mutex_t **)(DAT_00053b5c + 0x53948 + DAT_00053bac);
    pthread_mutex_lock(__mutex);
    pcVar1 = (char *)FUN_00051aec(DAT_00053bb0 + 0x53ab4);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00053bb4 + 0x53ac0));
    if (iVar2 == 0) {
      cprintf(DAT_00053bbc + 0x53ae4,DAT_00053bb8 + 0x53ae0,0x21d);
    }
    pcVar1 = (char *)FUN_00051aec(DAT_00053bc0 + 0x53af0);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00053bc4 + 0x53afc));
    if (iVar2 == 0) {
      asusdebuglog(6,DAT_00053bcc + 0x53b2c,0,1,0,DAT_00053bd0 + 0x53b30,DAT_00053bc8 + 0x53b20,
                   0x21d);
    }
    listnode_add(*piVar3,param_1);
    pthread_mutex_unlock(__mutex);
    return;
  }
  pcVar1 = (char *)FUN_00051aec(DAT_00053b64 + 0x5396c);
  iVar2 = strcmp(pcVar1,(char *)(DAT_00053b68 + 0x53978));
  if (iVar2 == 0) {
    cprintf(DAT_00053b70 + 0x53998,DAT_00053b6c + 0x53994,0x212);
  }
  pcVar1 = (char *)FUN_00051aec(DAT_00053b74 + 0x539a4);
  iVar2 = strcmp(pcVar1,(char *)(DAT_00053b78 + 0x539b0));
  if (iVar2 == 0) {
    asusdebuglog(6,DAT_00053b80 + 0x539e0,0,1,0,DAT_00053b84 + 0x539e4,DAT_00053b7c + 0x539d4,0x212)
    ;
  }
  if (param_1 != (void *)0x0) {
    pcVar1 = (char *)FUN_00051aec(DAT_00053b88 + 0x53a00);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00053b8c + 0x53a0c));
    if (iVar2 == 0) {
      cprintf(DAT_00053b94 + 0x53a2c,DAT_00053b90 + 0x53a28,0x214);
    }
    pcVar1 = (char *)FUN_00051aec(DAT_00053b98 + 0x53a38);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00053b9c + 0x53a44));
    if (iVar2 == 0) {
      asusdebuglog(6,DAT_00053ba4 + 0x53a74,0,1,0,DAT_00053ba8 + 0x53a78,DAT_00053ba0 + 0x53a68,
                   0x214);
    }
    free(param_1);
    return;
  }
  return;
}



===== FUN_0005742c @ 0005742c =====

undefined4
FUN_0005742c(int param_1,int param_2,uint param_3,uint param_4,uint param_5,undefined4 *param_6,
            undefined4 param_7)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *__s;
  ssize_t sVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  size_t sVar12;
  uint uVar13;
  uint uVar14;
  size_t __n;
  undefined4 uVar15;
  uint local_103c;
  int local_1038;
  uint local_1034;
  uint local_1030;
  int local_102c;
  uint uStack_1028;
  uint uStack_1024;
  int aiStack_1020 [11];
  undefined4 auStack_ff4 [1011];
  
  memset(&local_102c,0,0x1002);
  local_103c = 0;
  uVar13 = param_4 << 0x18 | (param_4 >> 8 & 0xff) << 0x10 | (param_4 >> 0x10 & 0xff) << 8 |
           param_4 >> 0x18;
  pcVar1 = (char *)FUN_00054250(DAT_000582a4 + 0x574ac);
  iVar2 = strcmp(pcVar1,(char *)(DAT_000582a8 + 0x574b8));
  if (iVar2 == 0) {
    cprintf(DAT_000582b0 + 0x574e0,DAT_000582ac + 0x574dc,0x2b3a,
            param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 | (param_3 >> 0x10 & 0xff) << 8 |
            param_3 >> 0x18,uVar13);
  }
  pcVar1 = (char *)FUN_00054250(DAT_000582b4 + 0x574ec);
  iVar2 = strcmp(pcVar1,(char *)(DAT_000582b8 + 0x574f8));
  if (iVar2 == 0) {
    asusdebuglog(6,DAT_000582c0 + 0x57530,0,1,0,DAT_000582c4 + 0x57538,DAT_000582bc + 0x57524,0x2b3a
                 ,param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 | (param_3 >> 0x10 & 0xff) << 8 |
                  param_3 >> 0x18,uVar13);
  }
  pcVar1 = (char *)FUN_00054250(DAT_000582c8 + 0x5754c);
  iVar2 = strcmp(pcVar1,(char *)(DAT_000582cc + 0x57558));
  if (iVar2 == 0) {
    cprintf(DAT_000582d4 + 0x57578,DAT_000582d0 + 0x57574,0x2b3b);
  }
  pcVar1 = (char *)FUN_00054250(DAT_000582d8 + 0x57584);
  iVar2 = strcmp(pcVar1,(char *)(DAT_000582dc + 0x57590));
  if (iVar2 == 0) {
    asusdebuglog(6,DAT_000582e4 + 0x575c0,0,1,0,DAT_000582e8 + 0x575c4,DAT_000582e0 + 0x575b4,0x2b3b
                );
  }
  if ((uVar13 == 0) ||
     (uVar14 = param_5 << 0x18 | (param_5 >> 8 & 0xff) << 0x10 | (param_5 >> 0x10 & 0xff) << 8 |
               param_5 >> 0x18, uVar14 == 0)) {
    pcVar1 = (char *)FUN_00054250(DAT_000582ec + 0x575ec);
    iVar2 = strcmp(pcVar1,(char *)(DAT_000582f0 + 0x575f8));
    if (iVar2 == 0) {
      cprintf(DAT_000582f8 + 0x57618,DAT_000582f4 + 0x57614,0x2b3f);
    }
    pcVar1 = (char *)FUN_00054250(DAT_000582fc + 0x57624);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00058300 + 0x57630));
    if (iVar2 == 0) {
      uVar15 = 0x2b3f;
      iVar9 = DAT_00058304 + 0x5765c;
      iVar2 = DAT_00058308 + 0x57668;
      iVar10 = DAT_0005830c + 0x57670;
      goto LAB_00058dac;
    }
  }
  else {
    uVar3 = FUN_0001ba40(0,param_7,uVar13);
    if (uVar3 == uVar14) {
      memset(&local_102c,0,0x1002);
      uVar13 = rsa_decrypt(param_7,uVar13,*(undefined4 *)(param_2 + 0x4c),
                           *(undefined4 *)(param_2 + 0x50),&local_102c,0x1002,0);
      if (uVar13 == 0) {
        pcVar1 = (char *)FUN_00054250(DAT_00058334 + 0x57788);
        iVar2 = strcmp(pcVar1,(char *)(DAT_00058338 + 0x57794));
        if (iVar2 == 0) {
          cprintf(DAT_00058340 + 0x577b4,DAT_0005833c + 0x577b0,0x2b4d);
        }
        pcVar1 = (char *)FUN_00054250(DAT_00058344 + 0x577c0);
        iVar2 = strcmp(pcVar1,(char *)(DAT_00058348 + 0x577cc));
        if (iVar2 == 0) {
          uVar15 = 0x2b4d;
          iVar9 = DAT_0005834c + 0x577f0;
          iVar2 = DAT_00058350 + 0x577fc;
          iVar10 = DAT_00058354 + 0x57804;
          goto LAB_00058dac;
        }
      }
      else {
        pcVar1 = (char *)FUN_00054250(DAT_00058358 + 0x57818);
        iVar2 = strcmp(pcVar1,(char *)(DAT_0005835c + 0x57824));
        if (iVar2 == 0) {
          cprintf(DAT_00058364 + 0x57844,DAT_00058360 + 0x57840,0x2b51);
        }
        pcVar1 = (char *)FUN_00054250(DAT_00058368 + 0x57850);
        iVar2 = strcmp(pcVar1,(char *)(DAT_0005836c + 0x5785c));
        if (iVar2 == 0) {
          asusdebuglog(6,DAT_00058374 + 0x5788c,0,1,0,DAT_00058378 + 0x57890,DAT_00058370 + 0x57880,
                       0x2b51);
        }
        pcVar1 = (char *)FUN_00054250(DAT_0005837c + 0x578a4);
        iVar2 = strcmp(pcVar1,(char *)(DAT_00058380 + 0x578b0));
        if (iVar2 == 0) {
          uVar15 = FUN_0005420c(param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 |
                                (param_3 >> 0x10 & 0xff) << 8 | param_3 >> 0x18);
          cprintf(DAT_00058388 + 0x578e0,DAT_00058384 + 0x578d4,0x2b52,uVar15,param_1);
        }
        pcVar1 = (char *)FUN_00054250(DAT_0005838c + 0x578ec);
        iVar2 = strcmp(pcVar1,(char *)(DAT_00058390 + 0x578f8));
        if (iVar2 == 0) {
          uVar15 = FUN_0005420c(param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 |
                                (param_3 >> 0x10 & 0xff) << 8 | param_3 >> 0x18);
          asusdebuglog(6,DAT_00058398 + 0x57930,0,1,0,DAT_0005839c + 0x57938,DAT_00058394 + 0x57924,
                       0x2b52,uVar15,param_1);
        }
        if (uVar13 < 0xc) {
          pcVar1 = (char *)FUN_00054250(DAT_000583a0 + 0x57960);
          iVar2 = strcmp(pcVar1,(char *)(DAT_000583a4 + 0x5796c));
          if (iVar2 == 0) {
            cprintf(DAT_000583ac + 0x5798c,DAT_000583a8 + 0x57988,0x2b55);
          }
          pcVar1 = (char *)FUN_00054250(DAT_000583b0 + 0x57998);
          iVar2 = strcmp(pcVar1,(char *)(DAT_000583b4 + 0x579a4));
          if (iVar2 == 0) {
            uVar15 = 0x2b55;
            iVar9 = DAT_000583b8 + 0x579c8;
            iVar2 = DAT_000583bc + 0x579d4;
            iVar10 = DAT_000583c0 + 0x579dc;
            goto LAB_00058dac;
          }
        }
        else {
          local_1038 = local_102c;
          local_1034 = uStack_1028;
          local_1030 = uStack_1024;
          uVar14 = uStack_1028 << 0x18 | (uStack_1028 >> 8 & 0xff) << 0x10 |
                   (uStack_1028 >> 0x10 & 0xff) << 8 | uStack_1028 >> 0x18;
          if ((uVar14 == 0) ||
             (uVar3 = uStack_1024 << 0x18 | (uStack_1024 >> 8 & 0xff) << 0x10 |
                      (uStack_1024 >> 0x10 & 0xff) << 8 | uStack_1024 >> 0x18, uVar3 == 0)) {
            pcVar1 = (char *)FUN_00054250(DAT_000583c4 + 0x57a20);
            iVar2 = strcmp(pcVar1,(char *)(DAT_000583c8 + 0x57a2c));
            if (iVar2 == 0) {
              cprintf(DAT_000583d0 + 0x57a4c,DAT_000583cc + 0x57a48,0x2b5e);
            }
            pcVar1 = (char *)FUN_00054250(DAT_000583d4 + 0x57a58);
            iVar2 = strcmp(pcVar1,(char *)(DAT_000583d8 + 0x57a64));
            if (iVar2 == 0) {
              uVar15 = 0x2b5e;
              iVar9 = DAT_000583dc + 0x57a88;
              iVar2 = DAT_000583e0 + 0x57a94;
              iVar10 = DAT_000583e4 + 0x57a9c;
              goto LAB_00058dac;
            }
          }
          else if (local_102c == 0x1000000) {
            if (uVar13 - 0xc < uVar14) {
              pcVar1 = (char *)FUN_00054250(DAT_0005840c + 0x57b5c);
              iVar2 = strcmp(pcVar1,(char *)(DAT_00058410 + 0x57b68));
              if (iVar2 == 0) {
                cprintf(DAT_00058418 + 0x57b88,DAT_00058414 + 0x57b84,0x2b6c);
              }
              pcVar1 = (char *)FUN_00054250(DAT_0005841c + 0x57b94);
              iVar2 = strcmp(pcVar1,(char *)(DAT_00058420 + 0x57ba0));
              if (iVar2 == 0) {
                uVar15 = 0x2b6c;
                iVar9 = DAT_00058424 + 0x57bc4;
                iVar2 = DAT_00058428 + 0x57bd0;
                iVar10 = DAT_0005842c + 0x57bd8;
                goto LAB_00058dac;
              }
            }
            else {
              uVar4 = FUN_0001ba40(0,aiStack_1020,uVar14);
              if (uVar4 == uVar3) {
                param_6[3] = uVar14;
                pvVar5 = malloc(uVar14);
                *param_6 = pvVar5;
                if (pvVar5 == (void *)0x0) {
                  pcVar1 = (char *)FUN_00054250(DAT_000586b8 + 0x58e70);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_000586bc + 0x58e7c));
                  if (iVar2 == 0) {
                    cprintf(DAT_000586c4 + 0x58e9c,DAT_000586c0 + 0x58e98,0x2b7a);
                  }
                  pcVar1 = (char *)FUN_00054250(DAT_000586c8 + 0x58ea8);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_000586cc + 0x58eb4));
                  if (iVar2 == 0) {
                    uVar15 = 0x2b7a;
                    iVar9 = DAT_000586d0 + 0x58ed8;
                    iVar2 = DAT_000586d4 + 0x58ee4;
                    iVar10 = DAT_000586d8 + 0x58eec;
                    goto LAB_00058dac;
                  }
                }
                else {
                  memset(pvVar5,0,uVar14);
                  memset(pvVar5,0,uVar14);
                  memcpy(pvVar5,aiStack_1020,uVar14);
                  uVar13 = (uVar13 - 0xc) - uVar14;
                  pcVar1 = (char *)FUN_00054250(DAT_00058454 + 0x57cec);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_00058458 + 0x57cfc));
                  if (iVar2 == 0) {
                    cprintf(DAT_00058460 + 0x57d1c,DAT_0005845c + 0x57d18,0x2b82);
                  }
                  pcVar1 = (char *)FUN_00054250(DAT_00058464 + 0x57d28);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_00058468 + 0x57d34));
                  if (iVar2 == 0) {
                    asusdebuglog(6,DAT_00058470 + 0x57d64,0,1,0,DAT_00058474 + 0x57d68,
                                 DAT_0005846c + 0x57d58,0x2b82);
                  }
                  pcVar1 = (char *)FUN_00054250(DAT_00058478 + 0x57d7c);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_0005847c + 0x57d88));
                  if (iVar2 == 0) {
                    uVar15 = FUN_0005420c(param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 |
                                          (param_3 >> 0x10 & 0xff) << 8 | param_3 >> 0x18);
                    cprintf(DAT_00058484 + 0x57db8,DAT_00058480 + 0x57dac,0x2b84,uVar15,param_1);
                  }
                  pcVar1 = (char *)FUN_00054250(DAT_00058488 + 0x57dc4);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_0005848c + 0x57dd0));
                  if (iVar2 == 0) {
                    uVar15 = FUN_0005420c(param_3 << 0x18 | (param_3 >> 8 & 0xff) << 0x10 |
                                          (param_3 >> 0x10 & 0xff) << 8 | param_3 >> 0x18);
                    asusdebuglog(6,DAT_00058494 + 0x57e08,0,1,0,DAT_00058498 + 0x57e10,
                                 DAT_00058490 + 0x57dfc,0x2b84,uVar15,param_1);
                  }
                  if (uVar13 < 0xc) {
                    pcVar1 = (char *)FUN_00054250(DAT_0005849c + 0x57e38);
                    iVar2 = strcmp(pcVar1,(char *)(DAT_000584a0 + 0x57e44));
                    if (iVar2 == 0) {
                      cprintf(DAT_000584a8 + 0x57e64,DAT_000584a4 + 0x57e60,0x2b87);
                    }
                    pcVar1 = (char *)FUN_00054250(DAT_000584ac + 0x57e70);
                    iVar2 = strcmp(pcVar1,(char *)(DAT_000584b0 + 0x57e7c));
                    if (iVar2 == 0) {
                      uVar15 = 0x2b87;
                      iVar9 = DAT_000584b4 + 0x57ea0;
                      iVar2 = DAT_000584b8 + 0x57eac;
                      iVar10 = DAT_000584bc + 0x57eb4;
                      goto LAB_00058dac;
                    }
                  }
                  else {
                    local_1038 = *(int *)((int)aiStack_1020 + uVar14);
                    local_1034 = *(uint *)((int)aiStack_1020 + uVar14 + 4);
                    local_1030 = *(uint *)((int)aiStack_1020 + uVar14 + 8);
                    uVar3 = local_1034 << 0x18 | (local_1034 >> 8 & 0xff) << 0x10 |
                            (local_1034 >> 0x10 & 0xff) << 8 | local_1034 >> 0x18;
                    if ((uVar3 == 0) ||
                       (uVar4 = local_1030 << 0x18 | (local_1030 >> 8 & 0xff) << 0x10 |
                                (local_1030 >> 0x10 & 0xff) << 8 | local_1030 >> 0x18, uVar4 == 0))
                    {
                      pcVar1 = (char *)FUN_00054250(DAT_000584c0 + 0x57f0c);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_000584c4 + 0x57f18));
                      if (iVar2 == 0) {
                        cprintf(DAT_000584cc + 0x57f38,DAT_000584c8 + 0x57f34,0x2b8e);
                      }
                      pcVar1 = (char *)FUN_00054250(DAT_000584d0 + 0x57f44);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_000584d4 + 0x57f50));
                      if (iVar2 == 0) {
                        uVar15 = 0x2b8e;
                        iVar9 = DAT_000584d8 + 0x57f74;
                        iVar2 = DAT_000584dc + 0x57f80;
                        iVar10 = DAT_000584e0 + 0x57f88;
                        goto LAB_00058dac;
                      }
                    }
                    else if (local_1038 == 0x3000000) {
                      if (uVar13 - 0xc < uVar3) {
                        pcVar1 = (char *)FUN_00054250(DAT_00058508 + 0x58044);
                        iVar2 = strcmp(pcVar1,(char *)(DAT_0005850c + 0x58050));
                        if (iVar2 == 0) {
                          cprintf(DAT_00058514 + 0x58070,DAT_00058510 + 0x5806c,0x2b9b);
                        }
                        pcVar1 = (char *)FUN_00054250(DAT_00058518 + 0x5807c);
                        iVar2 = strcmp(pcVar1,(char *)(DAT_0005851c + 0x58088));
                        if (iVar2 == 0) {
                          uVar15 = 0x2b9b;
                          iVar9 = DAT_00058520 + 0x580ac;
                          iVar2 = DAT_00058524 + 0x580b8;
                          iVar10 = DAT_00058528 + 0x580c0;
                          goto LAB_00058dac;
                        }
                      }
                      else {
                        pcVar1 = (char *)FUN_00054250(DAT_0005852c + 0x580d4);
                        iVar2 = strcmp(pcVar1,(char *)(DAT_00058530 + 0x580e0));
                        if (iVar2 == 0) {
                          cprintf(DAT_00058538 + 0x58104,DAT_00058534 + 0x58100,0x2b9f,uVar3);
                        }
                        pcVar1 = (char *)FUN_00054250(DAT_0005853c + 0x58110);
                        iVar2 = strcmp(pcVar1,(char *)(DAT_00058540 + 0x5811c));
                        if (iVar2 == 0) {
                          asusdebuglog(6,DAT_00058548 + 0x5814c,0,1,0,DAT_0005854c + 0x58154,
                                       DAT_00058544 + 0x58140,0x2b9f,uVar3);
                        }
                        if (uVar3 == 0x20) {
                          puVar7 = (undefined4 *)((int)aiStack_1020 + uVar14 + 0xc);
                          uVar13 = FUN_0001ba40(0,puVar7,0x20);
                          if (uVar4 == uVar13) {
                            param_6[5] = 0x20;
                            puVar6 = malloc(0x20);
                            param_6[2] = puVar6;
                            if (puVar6 == (undefined4 *)0x0) {
                              pcVar1 = (char *)FUN_00054250(DAT_000586dc + 0x58f00);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_000586e0 + 0x58f0c));
                              if (iVar2 == 0) {
                                cprintf(DAT_000586e8 + 0x58f2c,DAT_000586e4 + 0x58f28,0x2bb0);
                              }
                              pcVar1 = (char *)FUN_00054250(DAT_000586ec + 0x58f38);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_000586f0 + 0x58f44));
                              if (iVar2 == 0) {
                                uVar15 = 0x2bb0;
                                iVar9 = DAT_000586f4 + 0x58f68;
                                iVar2 = DAT_000586f8 + 0x58f74;
                                iVar10 = DAT_000586fc + 0x58f7c;
                                goto LAB_00058dac;
                              }
                            }
                            else {
                              do {
                                puVar11 = puVar7 + 2;
                                uVar15 = puVar7[1];
                                *puVar6 = *puVar7;
                                puVar6[1] = uVar15;
                                puVar6 = puVar6 + 2;
                                puVar7 = puVar11;
                              } while (puVar11 != (undefined4 *)((int)auStack_ff4 + uVar14));
                              pcVar1 = (char *)FUN_00054250(DAT_00058598 + 0x58798);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_0005859c + 0x587a4));
                              if (iVar2 == 0) {
                                cprintf(DAT_000585a4 + 0x587c4,DAT_000585a0 + 0x587c0,0x2bb7);
                              }
                              pcVar1 = (char *)FUN_00054250(DAT_000585a8 + 0x587d0);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_000585ac + 0x587dc));
                              if (iVar2 == 0) {
                                asusdebuglog(6,DAT_000585b4 + 0x5880c,0,1,0,DAT_000585b8 + 0x58810,
                                             DAT_000585b0 + 0x58800,0x2bb7);
                              }
                              pcVar1 = (char *)FUN_00054250(DAT_000585bc + 0x58824);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_000585c0 + 0x58830));
                              if (iVar2 == 0) {
                                uVar15 = FUN_0005420c(param_3 << 0x18 |
                                                      (param_3 >> 8 & 0xff) << 0x10 |
                                                      (param_3 >> 0x10 & 0xff) << 8 |
                                                      param_3 >> 0x18);
                                cprintf(DAT_000585c8 + 0x58860,DAT_000585c4 + 0x58854,0x2bb9,uVar15,
                                        param_1);
                              }
                              pcVar1 = (char *)FUN_00054250(DAT_000585cc + 0x5886c);
                              iVar2 = strcmp(pcVar1,(char *)(DAT_000585d0 + 0x58878));
                              if (iVar2 == 0) {
                                uVar15 = FUN_0005420c(param_3 << 0x18 |
                                                      (param_3 >> 8 & 0xff) << 0x10 |
                                                      (param_3 >> 0x10 & 0xff) << 8 |
                                                      param_3 >> 0x18);
                                asusdebuglog(6,DAT_000585d8 + 0x588b0,0,1,0,DAT_000585dc + 0x588b8,
                                             DAT_000585d4 + 0x588a4,0x2bb9,uVar15,param_1);
                              }
                              iVar2 = gen_rand(param_6 + 4);
                              param_6[1] = iVar2;
                              if (iVar2 == 0) {
                                pcVar1 = (char *)FUN_00054250(DAT_000585e0 + 0x588ec);
                                iVar2 = strcmp(pcVar1,(char *)(DAT_000585e4 + 0x588f8));
                                if (iVar2 == 0) {
                                  cprintf(DAT_000585ec + 0x58918,DAT_000585e8 + 0x58914,0x2bbd);
                                }
                                pcVar1 = (char *)FUN_00054250(DAT_000585f0 + 0x58924);
                                iVar2 = strcmp(pcVar1,(char *)(DAT_000585f4 + 0x58930));
                                if (iVar2 == 0) {
                                  uVar15 = 0x2bbd;
                                  iVar9 = DAT_000585f8 + 0x58954;
                                  iVar2 = DAT_000585fc + 0x58960;
                                  iVar10 = DAT_00058600 + 0x58968;
                                  goto LAB_00058dac;
                                }
                              }
                              else {
                                pcVar1 = (char *)FUN_00054250(DAT_00058604 + 0x5897c);
                                iVar2 = strcmp(pcVar1,(char *)(DAT_00058608 + 0x58988));
                                if (iVar2 == 0) {
                                  cprintf(DAT_00058610 + 0x589a8,DAT_0005860c + 0x589a4,0x2bc0);
                                }
                                pcVar1 = (char *)FUN_00054250(DAT_00058614 + 0x589b4);
                                iVar2 = strcmp(pcVar1,(char *)(DAT_00058618 + 0x589c0));
                                if (iVar2 == 0) {
                                  asusdebuglog(6,DAT_00058620 + 0x589f0,0,1,0,DAT_00058624 + 0x589f4
                                               ,DAT_0005861c + 0x589e4,0x2bc0);
                                }
                                pcVar1 = (char *)FUN_00054250(DAT_00058628 + 0x58a08);
                                iVar2 = strcmp(pcVar1,(char *)(DAT_0005862c + 0x58a14));
                                if (iVar2 == 0) {
                                  uVar15 = FUN_0005420c(param_3 << 0x18 |
                                                        (param_3 >> 8 & 0xff) << 0x10 |
                                                        (param_3 >> 0x10 & 0xff) << 8 |
                                                        param_3 >> 0x18);
                                  cprintf(DAT_00058634 + 0x58a44,DAT_00058630 + 0x58a38,0x2bc1,
                                          uVar15,param_1);
                                }
                                pcVar1 = (char *)FUN_00054250(DAT_00058638 + 0x58a50);
                                iVar2 = strcmp(pcVar1,(char *)(DAT_0005863c + 0x58a5c));
                                if (iVar2 == 0) {
                                  uVar15 = FUN_0005420c(param_3 << 0x18 |
                                                        (param_3 >> 8 & 0xff) << 0x10 |
                                                        (param_3 >> 0x10 & 0xff) << 8 |
                                                        param_3 >> 0x18);
                                  asusdebuglog(6,DAT_00058644 + 0x58a94,0,1,0,DAT_00058648 + 0x58a9c
                                               ,DAT_00058640 + 0x58a88,0x2bc1,uVar15,param_1);
                                }
                                uVar13 = param_6[4];
                                sVar12 = uVar13 + param_6[5] + 0x18;
                                puVar7 = malloc(sVar12);
                                if (puVar7 == (undefined4 *)0x0) {
                                  pcVar1 = (char *)FUN_00054250(DAT_00058700 + 0x58f90);
                                  iVar2 = strcmp(pcVar1,(char *)(DAT_00058704 + 0x58f9c));
                                  if (iVar2 == 0) {
                                    cprintf(DAT_0005870c + 0x58fbc,DAT_00058708 + 0x58fb8,0x2bc5);
                                  }
                                  pcVar1 = (char *)FUN_00054250(DAT_00058710 + 0x58fc8);
                                  iVar2 = strcmp(pcVar1,(char *)(DAT_00058714 + 0x58fd4));
                                  if (iVar2 == 0) {
                                    uVar15 = 0x2bc5;
                                    iVar9 = DAT_00058718 + 0x58ff8;
                                    iVar2 = DAT_0005871c + 0x59004;
                                    iVar10 = DAT_00058720 + 0x5900c;
                                    goto LAB_00058dac;
                                  }
                                }
                                else {
                                  memset(puVar7,0,sVar12);
                                  memset(puVar7,0,sVar12);
                                  local_1030 = 0;
                                  local_1038 = 0x2000000;
                                  local_1034 = uVar13 << 0x18 | (uVar13 >> 8 & 0xff) << 0x10 |
                                               (uVar13 >> 0x10 & 0xff) << 8 | uVar13 >> 0x18;
                                  uVar13 = FUN_0001ba40(0,param_6[1],uVar13);
                                  sVar12 = param_6[4];
                                  puVar6 = puVar7 + 3;
                                  local_1030 = uVar13 << 0x18 | (uVar13 >> 8 & 0xff) << 0x10 |
                                               (uVar13 >> 0x10 & 0xff) << 8 | uVar13 >> 0x18;
                                  *puVar7 = local_1038;
                                  puVar7[1] = local_1034;
                                  puVar7[2] = local_1030;
                                  memcpy(puVar6,(void *)param_6[1],sVar12);
                                  local_1038 = 0x3000000;
                                  uVar13 = param_6[5];
                                  local_1034 = uVar13 << 0x18 | (uVar13 >> 8 & 0xff) << 0x10 |
                                               (uVar13 >> 0x10 & 0xff) << 8 | uVar13 >> 0x18;
                                  local_1030 = 0;
                                  uVar13 = FUN_0001ba40(0,param_6[2]);
                                  local_1030 = uVar13 << 0x18 | (uVar13 >> 8 & 0xff) << 0x10 |
                                               (uVar13 >> 0x10 & 0xff) << 8 | uVar13 >> 0x18;
                                  *(int *)((int)puVar6 + sVar12) = local_1038;
                                  __n = param_6[5];
                                  *(uint *)((int)puVar6 + sVar12 + 4) = local_1034;
                                  *(uint *)((int)puVar6 + sVar12 + 8) = local_1030;
                                  memcpy((void *)((int)puVar6 + sVar12 + 0xc),(void *)param_6[2],__n
                                        );
                                  pvVar5 = (void *)aes_encrypt(*param_6,puVar7,
                                                               __n + param_6[4] + 0x18,&local_103c);
                                  uVar13 = local_103c;
                                  if (pvVar5 == (void *)0x0) {
                                    free(puVar7);
                                    pcVar1 = (char *)FUN_00054250(DAT_0005864c + 0x58bec);
                                    iVar2 = strcmp(pcVar1,(char *)(DAT_00058650 + 0x58bf8));
                                    if (iVar2 == 0) {
                                      cprintf(DAT_00058658 + 0x58c18,DAT_00058654 + 0x58c14,0x2be2);
                                    }
                                    pcVar1 = (char *)FUN_00054250(DAT_0005865c + 0x58c24);
                                    iVar2 = strcmp(pcVar1,(char *)(DAT_00058660 + 0x58c30));
                                    if (iVar2 == 0) {
                                      uVar15 = 0x2be2;
                                      iVar9 = DAT_00058664 + 0x58c54;
                                      iVar2 = DAT_00058668 + 0x58c60;
                                      iVar10 = DAT_0005866c + 0x58c68;
                                      goto LAB_00058dac;
                                    }
                                  }
                                  else {
                                    sVar12 = local_103c + 0xc;
                                    __s = malloc(sVar12);
                                    if (__s == (int *)0x0) {
                                      free(pvVar5);
                                      free(puVar7);
                                      pcVar1 = (char *)FUN_00054250(DAT_00058724 + 0x59030);
                                      iVar2 = strcmp(pcVar1,(char *)(DAT_00058728 + 0x5903c));
                                      if (iVar2 == 0) {
                                        cprintf(DAT_00058730 + 0x5905c,DAT_0005872c + 0x59058,0x2beb
                                               );
                                      }
                                      pcVar1 = (char *)FUN_00054250(DAT_00058734 + 0x59068);
                                      iVar2 = strcmp(pcVar1,(char *)(DAT_00058738 + 0x59074));
                                      if (iVar2 == 0) {
                                        uVar15 = 0x2beb;
                                        iVar9 = DAT_0005873c + 0x59098;
                                        iVar2 = DAT_00058740 + 0x590a4;
                                        iVar10 = DAT_00058744 + 0x590ac;
                                        goto LAB_00058dac;
                                      }
                                    }
                                    else {
                                      memset(__s,0,sVar12);
                                      local_1030 = 0;
                                      local_1038 = 0x4000000;
                                      local_1034 = uVar13 << 0x18 | (uVar13 >> 8 & 0xff) << 0x10 |
                                                   (uVar13 >> 0x10 & 0xff) << 8 | uVar13 >> 0x18;
                                      uVar14 = FUN_0001ba40(0,pvVar5,uVar13);
                                      uVar13 = local_103c;
                                      local_1030 = uVar14 << 0x18 | (uVar14 >> 8 & 0xff) << 0x10 |
                                                   (uVar14 >> 0x10 & 0xff) << 8 | uVar14 >> 0x18;
                                      *__s = local_1038;
                                      __s[1] = local_1034;
                                      __s[2] = local_1030;
                                      memcpy(__s + 3,pvVar5,local_103c);
                                      sVar8 = write(param_1,__s,uVar13 + 0xc);
                                      if (sVar8 == local_103c + 0xc) {
                                        free(__s);
                                        free(puVar7);
                                        free(pvVar5);
                                        pcVar1 = (char *)FUN_00054250(DAT_00058694 + 0x58ddc);
                                        iVar2 = strcmp(pcVar1,(char *)(DAT_00058698 + 0x58de8));
                                        if (iVar2 == 0) {
                                          cprintf(DAT_000586a0 + 0x58e08,DAT_0005869c + 0x58e04,
                                                  0x2c01);
                                        }
                                        pcVar1 = (char *)FUN_00054250(DAT_000586a4 + 0x58e14);
                                        iVar2 = strcmp(pcVar1,(char *)(DAT_000586a8 + 0x58e20));
                                        if (iVar2 == 0) {
                                          asusdebuglog(6,DAT_000586b0 + 0x58e50,0,1,0,
                                                       DAT_000586b4 + 0x58e54,DAT_000586ac + 0x58e44
                                                       ,0x2c01);
                                        }
                                        return 1;
                                      }
                                      free(pvVar5);
                                      free(__s);
                                      free(puVar7);
                                      pcVar1 = (char *)FUN_00054250(DAT_00058670 + 0x58d2c);
                                      iVar2 = strcmp(pcVar1,(char *)(DAT_00058674 + 0x58d38));
                                      if (iVar2 == 0) {
                                        cprintf(DAT_0005867c + 0x58d58,DAT_00058678 + 0x58d54,0x2bfa
                                               );
                                      }
                                      pcVar1 = (char *)FUN_00054250(DAT_00058680 + 0x58d64);
                                      iVar2 = strcmp(pcVar1,(char *)(DAT_00058684 + 0x58d70));
                                      if (iVar2 == 0) {
                                        uVar15 = 0x2bfa;
                                        iVar9 = DAT_00058688 + 0x58d94;
                                        iVar2 = DAT_0005868c + 0x58da0;
                                        iVar10 = DAT_00058690 + 0x58da8;
LAB_00058dac:
                                        asusdebuglog(6,iVar2,0,1,0,iVar10,iVar9,uVar15);
                                        return 0;
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                          else {
                            pcVar1 = (char *)FUN_00054250(DAT_00058574 + 0x58220);
                            iVar2 = strcmp(pcVar1,(char *)(DAT_00058578 + 0x5822c));
                            if (iVar2 == 0) {
                              cprintf(DAT_00058580 + 0x5824c,DAT_0005857c + 0x58248,0x2ba8);
                            }
                            pcVar1 = (char *)FUN_00054250(DAT_00058584 + 0x58258);
                            iVar2 = strcmp(pcVar1,(char *)(DAT_00058588 + 0x58264));
                            if (iVar2 == 0) {
                              uVar15 = 0x2ba8;
                              iVar9 = DAT_0005858c + 0x58288;
                              iVar2 = DAT_00058590 + 0x58294;
                              iVar10 = DAT_00058594 + 0x5829c;
                              goto LAB_00058dac;
                            }
                          }
                        }
                        else {
                          pcVar1 = (char *)FUN_00054250(DAT_00058550 + 0x58170);
                          iVar2 = strcmp(pcVar1,(char *)(DAT_00058554 + 0x5817c));
                          if (iVar2 == 0) {
                            cprintf(DAT_0005855c + 0x5819c,DAT_00058558 + 0x58198,0x2ba2);
                          }
                          pcVar1 = (char *)FUN_00054250(DAT_00058560 + 0x581a8);
                          iVar2 = strcmp(pcVar1,(char *)(DAT_00058564 + 0x581b4));
                          if (iVar2 == 0) {
                            uVar15 = 0x2ba2;
                            iVar9 = DAT_00058568 + 0x581d8;
                            iVar2 = DAT_0005856c + 0x581e4;
                            iVar10 = DAT_00058570 + 0x581ec;
                            goto LAB_00058dac;
                          }
                        }
                      }
                    }
                    else {
                      pcVar1 = (char *)FUN_00054250(DAT_000584e4 + 0x57fa8);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_000584e8 + 0x57fb4));
                      if (iVar2 == 0) {
                        cprintf(DAT_000584f0 + 0x57fd4,DAT_000584ec + 0x57fd0,0x2b95);
                      }
                      pcVar1 = (char *)FUN_00054250(DAT_000584f4 + 0x57fe0);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_000584f8 + 0x57fec));
                      if (iVar2 == 0) {
                        uVar15 = 0x2b95;
                        iVar9 = DAT_000584fc + 0x58010;
                        iVar2 = DAT_00058500 + 0x5801c;
                        iVar10 = DAT_00058504 + 0x58024;
                        goto LAB_00058dac;
                      }
                    }
                  }
                }
              }
              else {
                pcVar1 = (char *)FUN_00054250(DAT_00058430 + 0x57c10);
                iVar2 = strcmp(pcVar1,(char *)(DAT_00058434 + 0x57c1c));
                if (iVar2 == 0) {
                  cprintf(DAT_0005843c + 0x57c3c,DAT_00058438 + 0x57c38,0x2b72);
                }
                pcVar1 = (char *)FUN_00054250(DAT_00058440 + 0x57c48);
                iVar2 = strcmp(pcVar1,(char *)(DAT_00058444 + 0x57c54));
                if (iVar2 == 0) {
                  uVar15 = 0x2b72;
                  iVar9 = DAT_00058448 + 0x57c78;
                  iVar2 = DAT_0005844c + 0x57c84;
                  iVar10 = DAT_00058450 + 0x57c8c;
                  goto LAB_00058dac;
                }
              }
            }
          }
          else {
            pcVar1 = (char *)FUN_00054250(DAT_000583e8 + 0x57abc);
            iVar2 = strcmp(pcVar1,(char *)(DAT_000583ec + 0x57ac8));
            if (iVar2 == 0) {
              cprintf(DAT_000583f4 + 0x57ae8,DAT_000583f0 + 0x57ae4,0x2b66);
            }
            pcVar1 = (char *)FUN_00054250(DAT_000583f8 + 0x57af4);
            iVar2 = strcmp(pcVar1,(char *)(DAT_000583fc + 0x57b00));
            if (iVar2 == 0) {
              uVar15 = 0x2b66;
              iVar9 = DAT_00058400 + 0x57b24;
              iVar2 = DAT_00058404 + 0x57b30;
              iVar10 = DAT_00058408 + 0x57b38;
              goto LAB_00058dac;
            }
          }
        }
      }
    }
    else {
      pcVar1 = (char *)FUN_00054250(DAT_00058310 + 0x576a4);
      iVar2 = strcmp(pcVar1,(char *)(DAT_00058314 + 0x576b0));
      if (iVar2 == 0) {
        cprintf(DAT_0005831c + 0x576d0,DAT_00058318 + 0x576cc,0x2b45);
      }
      pcVar1 = (char *)FUN_00054250(DAT_00058320 + 0x576dc);
      iVar2 = strcmp(pcVar1,(char *)(DAT_00058324 + 0x576e8));
      if (iVar2 == 0) {
        uVar15 = 0x2b45;
        iVar9 = DAT_00058328 + 0x5770c;
        iVar2 = DAT_0005832c + 0x57718;
        iVar10 = DAT_00058330 + 0x57720;
        goto LAB_00058dac;
      }
    }
  }
  return 0;
}



===== FUN_00073450 @ 00073450 =====

undefined4 FUN_00073450(int param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  uint __fd;
  uint uVar4;
  int *piVar5;
  size_t sVar6;
  void *__buf;
  ssize_t sVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  size_t local_40c4;
  int local_40c0 [2];
  timeval local_40b8;
  undefined1 local_40b0 [16];
  fd_set local_40a0;
  char acStack_4020 [16384];
  
  iVar9 = DAT_000743f0 + 0x73470;
  local_40c4 = 0;
  local_40b8.tv_usec = 0;
  uVar10 = **(uint **)(iVar9 + DAT_000743f4);
  local_40b8.tv_sec = 2;
  memset(acStack_4020,0,0x4000);
  pcVar1 = (char *)FUN_00054250(DAT_000743f8 + 0x734ac);
  iVar2 = strcmp(pcVar1,(char *)(DAT_000743fc + 0x734b8));
  if (iVar2 == 0) {
    cprintf(DAT_00074404 + 0x734d8,DAT_00074400 + 0x734d4,0x1f27);
  }
  pcVar1 = (char *)FUN_00054250(DAT_00074408 + 0x734e4);
  iVar2 = strcmp(pcVar1,(char *)(DAT_0007440c + 0x734f0));
  if (iVar2 == 0) {
    asusdebuglog(6,DAT_00074414 + 0x73520,0,1,0,DAT_00074418 + 0x73524,DAT_00074410 + 0x73514,0x1f27
                );
  }
  iVar2 = FUN_000543a0(param_1,1);
  if (iVar2 == 0) {
    pcVar1 = (char *)FUN_00054250(DAT_0007441c + 0x73550);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00074420 + 0x7355c));
    if (iVar2 == 0) {
      cprintf(DAT_00074428 + 0x7357c,DAT_00074424 + 0x73578,0x1f2a);
    }
    pcVar1 = (char *)FUN_00054250(DAT_0007442c + 0x73588);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00074430 + 0x73594));
    if (iVar2 != 0) goto LAB_00074274;
    uVar11 = 0x1f2a;
    iVar9 = DAT_00074434 + 0x735b4;
    iVar2 = DAT_00074438 + 0x735c0;
    iVar8 = DAT_0007443c + 0x735c4;
  }
  else {
    pcVar1 = (char *)(param_1 + 0x18);
    FUN_00018924(pcVar1);
    memset((sockaddr *)local_40b0,0,0x10);
    local_40b0._2_2_ = (ushort)((uVar10 & 0xff) << 8) | (ushort)(uVar10 >> 8) & 0xff;
    local_40b0._0_2_ = 2;
    iVar8 = inet_aton(pcVar1,(in_addr *)(local_40b0 + 4));
    if (iVar8 == 0) {
      pcVar3 = (char *)FUN_00054250(DAT_00074440 + 0x73620);
      iVar2 = strcmp(pcVar3,(char *)(DAT_00074444 + 0x7362c));
      if (iVar2 == 0) {
        cprintf(DAT_0007444c + 0x73650,DAT_00074448 + 0x7364c,0x1f36,pcVar1);
      }
      pcVar3 = (char *)FUN_00054250(DAT_00074450 + 0x7365c);
      iVar2 = strcmp(pcVar3,(char *)(DAT_00074454 + 0x73668));
      if (iVar2 == 0) {
        asusdebuglog(6,DAT_0007445c + 0x73698,0,1,0,DAT_00074460 + 0x736a0,DAT_00074458 + 0x7368c,
                     0x1f36,pcVar1);
      }
      goto LAB_00074274;
    }
    __fd = socket(2,1,0);
    if (-1 < (int)__fd) {
      uVar4 = fcntl(__fd,3);
      if ((int)uVar4 < 0) {
        pcVar1 = (char *)FUN_00054250(DAT_00074488 + 0x73774);
        iVar2 = strcmp(pcVar1,(char *)(DAT_0007448c + 0x73780));
        if (iVar2 == 0) {
          cprintf(DAT_00074494 + 0x737a0,DAT_00074490 + 0x7379c,0x1f42);
        }
        pcVar1 = (char *)FUN_00054250(DAT_00074498 + 0x737ac);
        iVar2 = strcmp(pcVar1,(char *)(DAT_0007449c + 0x737b8));
        if (iVar2 == 0) {
          uVar11 = 0x1f42;
          iVar9 = DAT_000744a0 + 0x737d8;
          iVar2 = DAT_000744a4 + 0x737e4;
          iVar8 = DAT_000744a8 + 0x737e8;
          goto LAB_00073fec;
        }
      }
      else {
        iVar8 = fcntl(__fd,4,uVar4 | 0x800);
        if (iVar8 < 0) {
          pcVar1 = (char *)FUN_00054250(DAT_000744ac + 0x73818);
          iVar2 = strcmp(pcVar1,(char *)(DAT_000744b0 + 0x73824));
          if (iVar2 == 0) {
            cprintf(DAT_000744b8 + 0x73844,DAT_000744b4 + 0x73840,0x1f49);
          }
          pcVar1 = (char *)FUN_00054250(DAT_000744bc + 0x73850);
          iVar2 = strcmp(pcVar1,(char *)(DAT_000744c0 + 0x7385c));
          if (iVar2 == 0) {
            uVar11 = 0x1f49;
            iVar9 = DAT_000744c4 + 0x7387c;
            iVar2 = DAT_000744c8 + 0x73888;
            iVar8 = DAT_000744cc + 0x7388c;
            goto LAB_00073fec;
          }
        }
        else {
          iVar8 = connect(__fd,(sockaddr *)local_40b0,0x10);
          if (iVar8 < 0) {
            piVar5 = __errno_location();
            if (*piVar5 == 0x73) {
              iVar8 = 0;
              do {
                local_40a0.fds_bits[iVar8] = 0;
                iVar8 = iVar8 + 1;
              } while (iVar8 != 0x20);
              local_40a0.fds_bits[(int)__fd >> 5] =
                   local_40a0.fds_bits[(int)__fd >> 5] | 1 << (__fd & 0x1f);
              iVar8 = select(__fd + 1,(fd_set *)0x0,&local_40a0,(fd_set *)0x0,&local_40b8);
              if (1 < iVar8 + 1U) goto LAB_00073a2c;
              pcVar1 = (char *)FUN_00054250(DAT_000744d0 + 0x73928);
              iVar2 = strcmp(pcVar1,(char *)(DAT_000744d4 + 0x73934));
              if (iVar2 == 0) {
                cprintf(DAT_000744dc + 0x73954,DAT_000744d8 + 0x73950,0x1f56);
              }
              pcVar1 = (char *)FUN_00054250(DAT_000744e0 + 0x73960);
              iVar2 = strcmp(pcVar1,(char *)(DAT_000744e4 + 0x7396c));
              if (iVar2 == 0) {
                uVar11 = 0x1f56;
                iVar9 = DAT_000744e8 + 0x7398c;
                iVar2 = DAT_000744ec + 0x73998;
                iVar8 = DAT_000744f0 + 0x7399c;
                goto LAB_00073fec;
              }
            }
            else {
              pcVar1 = (char *)FUN_00054250(DAT_000744f4 + 0x739b0);
              iVar2 = strcmp(pcVar1,(char *)(DAT_000744f8 + 0x739bc));
              if (iVar2 == 0) {
                cprintf(DAT_00074500 + 0x739dc,DAT_000744fc + 0x739d8,0x1f5c);
              }
              pcVar1 = (char *)FUN_00054250(DAT_00074504 + 0x739e8);
              iVar2 = strcmp(pcVar1,(char *)(DAT_00074508 + 0x739f4));
              if (iVar2 == 0) {
                uVar11 = 0x1f5c;
                iVar9 = DAT_0007450c + 0x73a14;
                iVar2 = DAT_00074510 + 0x73a20;
                iVar8 = DAT_00074514 + 0x73a24;
                goto LAB_00073fec;
              }
            }
          }
          else {
LAB_00073a2c:
            local_40c0[0] = 0;
            local_40c0[1] = 4;
            iVar8 = getsockopt(__fd,1,4,local_40c0,(socklen_t *)(local_40c0 + 1));
            if (iVar8 == -1) {
              pcVar1 = (char *)FUN_00054250(DAT_00074518 + 0x73a70);
              iVar2 = strcmp(pcVar1,(char *)(DAT_0007451c + 0x73a7c));
              if (iVar2 == 0) {
                piVar5 = __errno_location();
                pcVar1 = strerror(*piVar5);
                cprintf(DAT_00074524 + 0x73aac,DAT_00074520 + 0x73aa0,0x1f65,pcVar1);
              }
              pcVar1 = (char *)FUN_00054250(DAT_00074528 + 0x73ab8);
              iVar2 = strcmp(pcVar1,(char *)(DAT_0007452c + 0x73ac4));
              if (iVar2 == 0) {
                piVar5 = __errno_location();
                pcVar1 = strerror(*piVar5);
                asusdebuglog(6,DAT_00074534 + 0x73b00,0,1,0,DAT_00074538 + 0x73b08,
                             DAT_00074530 + 0x73af4,0x1f65,pcVar1);
              }
            }
            else if (local_40c0[0] == 0) {
              iVar8 = fcntl(__fd,4,uVar4 & 0xfffff7ff);
              if (iVar8 < 0) {
                pcVar1 = (char *)FUN_00054250(DAT_00074560 + 0x73bd8);
                iVar2 = strcmp(pcVar1,(char *)(DAT_00074564 + 0x73be4));
                if (iVar2 == 0) {
                  cprintf(DAT_0007456c + 0x73c04,DAT_00074568 + 0x73c00,0x1f71);
                }
                pcVar1 = (char *)FUN_00054250(DAT_00074570 + 0x73c10);
                iVar2 = strcmp(pcVar1,(char *)(DAT_00074574 + 0x73c1c));
                if (iVar2 == 0) {
                  uVar11 = 0x1f71;
                  iVar9 = DAT_00074578 + 0x73c3c;
                  iVar2 = DAT_0007457c + 0x73c48;
                  iVar8 = DAT_00074580 + 0x73c4c;
                  goto LAB_00073fec;
                }
              }
              else {
                pcVar3 = (char *)FUN_00054250(DAT_00074584 + 0x73c60);
                iVar8 = strcmp(pcVar3,(char *)(DAT_00074588 + 0x73c6c));
                if (iVar8 == 0) {
                  cprintf(DAT_00074590 + 0x73c94,DAT_0007458c + 0x73c90,0x1f75,pcVar1,uVar10);
                }
                pcVar3 = (char *)FUN_00054250(DAT_00074594 + 0x73ca0);
                iVar8 = strcmp(pcVar3,(char *)(DAT_00074598 + 0x73cac));
                if (iVar8 == 0) {
                  asusdebuglog(6,DAT_000745a0 + 0x73cdc,0,1,0,DAT_000745a4 + 0x73ce4,
                               DAT_0007459c + 0x73cd0,0x1f75,pcVar1,uVar10);
                }
                iVar8 = setsockopt(__fd,1,0x14,&local_40b8,8);
                if (iVar8 < 0) {
                  pcVar1 = (char *)FUN_00054250(DAT_000745a8 + 0x73d20);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_000745ac + 0x73d2c));
                  if (iVar2 == 0) {
                    cprintf(DAT_000745b4 + 0x73d4c,DAT_000745b0 + 0x73d48,0x1f78);
                  }
                  pcVar1 = (char *)FUN_00054250(DAT_000745b8 + 0x73d58);
                  iVar2 = strcmp(pcVar1,(char *)(DAT_000745bc + 0x73d64));
                  if (iVar2 == 0) {
                    uVar11 = 0x1f78;
                    iVar9 = DAT_000745c0 + 0x73d84;
                    iVar2 = DAT_000745c4 + 0x73d90;
                    iVar8 = DAT_000745c8 + 0x73d94;
                    goto LAB_00073fec;
                  }
                }
                else {
                  pcVar3 = (char *)FUN_00054250(DAT_000745cc + 0x73da8);
                  iVar8 = strcmp(pcVar3,(char *)(DAT_000745d0 + 0x73db4));
                  if (iVar8 == 0) {
                    cprintf(DAT_000745d8 + 0x73dd8,DAT_000745d4 + 0x73dd4,0x1f7c,param_2);
                  }
                  pcVar3 = (char *)FUN_00054250(DAT_000745dc + 0x73de4);
                  iVar8 = strcmp(pcVar3,(char *)(DAT_000745e0 + 0x73df0));
                  if (iVar8 == 0) {
                    asusdebuglog(6,DAT_000745e8 + 0x73e20,0,1,0,DAT_000745ec + 0x73e28,
                                 DAT_000745e4 + 0x73e14,0x1f7c,param_2);
                  }
                  memset(acStack_4020,0,0x4000);
                  if (param_3 == 0) {
                    iVar8 = json_object_new_object();
                  }
                  else {
                    json_object_to_json_string(param_3);
                    iVar8 = json_tokener_parse();
                  }
                  if (iVar8 == 0) {
                    pcVar1 = (char *)FUN_00054250(DAT_000745f0 + 0x73e78);
                    iVar2 = strcmp(pcVar1,(char *)(DAT_000745f4 + 0x73e84));
                    if (iVar2 == 0) {
                      cprintf(DAT_000745fc + 0x73ea4,DAT_000745f8 + 0x73ea0,0x1f86);
                    }
                    pcVar1 = (char *)FUN_00054250(DAT_00074600 + 0x73eb0);
                    iVar2 = strcmp(pcVar1,(char *)(DAT_00074604 + 0x73ebc));
                    if (iVar2 == 0) {
                      uVar11 = 0x1f86;
                      iVar9 = DAT_00074608 + 0x73edc;
                      iVar2 = DAT_0007460c + 0x73ee8;
                      iVar8 = DAT_00074610 + 0x73eec;
                      goto LAB_00073fec;
                    }
                  }
                  else {
                    uVar11 = json_object_new_int(param_2);
                    json_object_object_add(iVar8,DAT_00074614 + 0x73f08,uVar11);
                    uVar11 = json_object_to_json_string_ext(iVar8,0);
                    snprintf(acStack_4020,0x3ff0,(char *)(DAT_00074618 + 0x73f2c),uVar11);
                    json_object_put(iVar8);
                    sVar6 = strlen(acStack_4020);
                    __buf = (void *)FUN_0001cbbc(iVar2,0xd,acStack_4020,sVar6 + 1,&local_40c4);
                    if (__buf == (void *)0x0) {
                      pcVar1 = (char *)FUN_00054250(DAT_0007461c + 0x73f74);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_00074620 + 0x73f80));
                      if (iVar2 == 0) {
                        cprintf(DAT_00074628 + 0x73fa0,DAT_00074624 + 0x73f9c,0x1f91);
                      }
                      pcVar1 = (char *)FUN_00054250(DAT_0007462c + 0x73fac);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_00074630 + 0x73fb8));
                      if (iVar2 == 0) {
                        uVar11 = 0x1f91;
                        iVar9 = DAT_00074634 + 0x73fd8;
                        iVar2 = DAT_00074638 + 0x73fe4;
                        iVar8 = DAT_0007463c + 0x73fe8;
                        goto LAB_00073fec;
                      }
                    }
                    else {
                      sVar7 = send(__fd,__buf,local_40c4,0);
                      if (0 < sVar7) {
                        pcVar3 = (char *)FUN_00054250(DAT_00074664 + 0x740b8);
                        iVar2 = strcmp(pcVar3,(char *)(DAT_00074668 + 0x740c4));
                        if (iVar2 == 0) {
                          cprintf(DAT_00074670 + 0x740ec,DAT_0007466c + 0x740e8,0x1f9c,param_2,
                                  pcVar1);
                        }
                        pcVar3 = (char *)FUN_00054250(DAT_00074674 + 0x740f8);
                        iVar2 = strcmp(pcVar3,(char *)(DAT_00074678 + 0x74104));
                        if (iVar2 == 0) {
                          asusdebuglog(6,DAT_00074680 + 0x74134,0,1,0,DAT_00074684 + 0x7413c,
                                       DAT_0007467c + 0x74128,0x1f9c,param_2,pcVar1);
                        }
                        asusdebuglog(6,DAT_0007468c + 0x7417c,0,1,0,DAT_00074688 + 0x74164,param_2,
                                     pcVar1);
                        free(__buf);
                        do {
                          sVar7 = recv(__fd,acStack_4020,0x4000,0);
                          if (sVar7 < 1) {
                            pcVar1 = (char *)FUN_00054250(DAT_00074690 + 0x741ac);
                            iVar2 = strcmp(pcVar1,(char *)(DAT_00074694 + 0x741b8));
                            if (iVar2 == 0) {
                              cprintf(DAT_0007469c + 0x741d8,DAT_00074698 + 0x741d4,0x1fa4);
                            }
                            pcVar1 = (char *)FUN_00054250(DAT_000746a0 + 0x741e4);
                            iVar2 = strcmp(pcVar1,(char *)(DAT_000746a4 + 0x741f0));
                            if (iVar2 == 0) {
                              asusdebuglog(6,DAT_000746ac + 0x74220,0,1,0,DAT_000746b0 + 0x74224,
                                           DAT_000746a8 + 0x74214,0x1fa4);
                            }
                            break;
                          }
                          iVar2 = FUN_00072ab8(__fd,acStack_4020,sVar7,0,0,
                                               *(undefined4 *)(iVar9 + DAT_000746b4),0);
                        } while (iVar2 != 1);
                        close(__fd);
                        return 1;
                      }
                      pcVar1 = (char *)FUN_00054250(DAT_00074640 + 0x74020);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_00074644 + 0x7402c));
                      if (iVar2 == 0) {
                        cprintf(DAT_0007464c + 0x7404c,DAT_00074648 + 0x74048,0x1f97);
                      }
                      pcVar1 = (char *)FUN_00054250(DAT_00074650 + 0x74058);
                      iVar2 = strcmp(pcVar1,(char *)(DAT_00074654 + 0x74064));
                      if (iVar2 == 0) {
                        asusdebuglog(6,DAT_0007465c + 0x74094,0,1,0,DAT_00074660 + 0x74098,
                                     DAT_00074658 + 0x74088,0x1f97);
                      }
                      free(__buf);
                    }
                  }
                }
              }
            }
            else {
              pcVar1 = (char *)FUN_00054250(DAT_0007453c + 0x73b34);
              iVar2 = strcmp(pcVar1,(char *)(DAT_00074540 + 0x73b40));
              if (iVar2 == 0) {
                cprintf(DAT_00074548 + 0x73b60,DAT_00074544 + 0x73b5c,0x1f6a);
              }
              pcVar1 = (char *)FUN_00054250(DAT_0007454c + 0x73b6c);
              iVar2 = strcmp(pcVar1,(char *)(DAT_00074550 + 0x73b78));
              if (iVar2 == 0) {
                uVar11 = 0x1f6a;
                iVar9 = DAT_00074554 + 0x73b98;
                iVar2 = DAT_00074558 + 0x73ba4;
                iVar8 = DAT_0007455c + 0x73ba8;
LAB_00073fec:
                asusdebuglog(6,iVar2,0,1,0,iVar8,iVar9,uVar11);
              }
            }
          }
        }
      }
      close(__fd);
      goto LAB_00074274;
    }
    pcVar1 = (char *)FUN_00054250(DAT_00074464 + 0x736d0);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00074468 + 0x736dc));
    if (iVar2 == 0) {
      cprintf(DAT_00074470 + 0x736fc,DAT_0007446c + 0x736f8,0x1f3c);
    }
    pcVar1 = (char *)FUN_00054250(DAT_00074474 + 0x73708);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00074478 + 0x73714));
    if (iVar2 != 0) goto LAB_00074274;
    uVar11 = 0x1f3c;
    iVar9 = DAT_0007447c + 0x73734;
    iVar2 = DAT_00074480 + 0x73740;
    iVar8 = DAT_00074484 + 0x73744;
  }
  asusdebuglog(6,iVar2,0,1,0,iVar8,iVar9,uVar11);
LAB_00074274:
  pcVar1 = (char *)FUN_00054250(DAT_000746b8 + 0x74280);
  iVar2 = strcmp(pcVar1,(char *)(DAT_000746bc + 0x7428c));
  param_1 = param_1 + 0x18;
  if (iVar2 == 0) {
    cprintf(DAT_000746c4 + 0x742bc,DAT_000746c0 + 0x742b8,0x1fb2,param_2,param_1);
  }
  pcVar1 = (char *)FUN_00054250(DAT_000746c8 + 0x742c8);
  iVar2 = strcmp(pcVar1,(char *)(DAT_000746cc + 0x742d4));
  if (iVar2 == 0) {
    asusdebuglog(6,DAT_000746d4 + 0x74304,0,1,0,DAT_000746d8 + 0x7430c,DAT_000746d0 + 0x742f8,0x1fb2
                 ,param_2,param_1);
  }
  asusdebuglog(6,DAT_000746e0 + 0x74338,0,1,0,DAT_000746dc + 0x74334,param_2,param_1);
  pcVar1 = (char *)FUN_00054250(DAT_000746e4 + 0x74354);
  iVar2 = strcmp(pcVar1,(char *)(DAT_000746e8 + 0x74360));
  if (iVar2 == 0) {
    cprintf(DAT_000746f0 + 0x74380,DAT_000746ec + 0x7437c,0x1fb3);
  }
  pcVar1 = (char *)FUN_00054250(DAT_000746f4 + 0x7438c);
  iVar2 = strcmp(pcVar1,(char *)(DAT_000746f8 + 0x74398));
  if (iVar2 == 0) {
    asusdebuglog(6,DAT_00074700 + 0x743d0,0,1,0,DAT_00074704 + 0x743d8,DAT_000746fc + 0x743c4,0x1fb3
                );
  }
  return 0;
}



===== cm_tcpPacketHandler @ 00082bb8 =====

/* WARNING: Type propagation algorithm not settling */

undefined4 cm_tcpPacketHandler(int *param_1)

{
  pthread_t __th;
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int __fd;
  undefined4 uVar5;
  socklen_t local_4094 [3];
  undefined1 auStack_4088 [16];
  void *local_4078;
  void *local_4074;
  void *local_4070;
  char acStack_4060 [32];
  char local_4040 [32];
  undefined1 auStack_4020 [16384];
  
  iVar2 = DAT_00082fc0;
  __th = pthread_self();
  pthread_detach(__th);
  local_4094[2] = 0;
  __fd = *param_1;
  local_4094[1] = 3;
  memset(acStack_4060,0,0x20);
  memset(local_4040,0,0x20);
  memset(auStack_4020,0,0x4000);
  memset(&local_4078,0,0x18);
  local_4094[0] = 0x10;
  getpeername(__fd,(sockaddr *)auStack_4088,local_4094);
  pcVar1 = inet_ntoa((in_addr)auStack_4088._4_4_);
  snprintf(acStack_4060,0x20,(char *)(DAT_00082fc4 + 0x82c70),pcVar1);
  FUN_0005aeb4(acStack_4060,local_4040);
  if (local_4040[0] == '\0') {
    pcVar1 = (char *)FUN_00054250(DAT_00082fc8 + 0x82c9c);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00082fcc + 0x82ca8));
    if (iVar2 == 0) {
      cprintf(DAT_00082fd4 + 0x82cc8,DAT_00082fd0 + 0x82cc4,0x34f1);
    }
    pcVar1 = (char *)FUN_00054250(DAT_00082fd8 + 0x82cd4);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00082fdc + 0x82ce0));
    if (iVar2 == 0) {
      uVar5 = 0x34f1;
      iVar3 = DAT_00082fe0 + 0x82d00;
      iVar2 = DAT_00082fe4 + 0x82d0c;
      iVar4 = DAT_00082fe8 + 0x82d10;
LAB_00082f1c:
      asusdebuglog(6,iVar2,0,1,0,iVar4,iVar3,uVar5);
    }
  }
  else {
    pcVar1 = (char *)FUN_00054250(DAT_00082fec + 0x82d24);
    iVar3 = strcmp(pcVar1,(char *)(DAT_00082ff0 + 0x82d30));
    if (iVar3 == 0) {
      cprintf(DAT_00082ff8 + 0x82d58,DAT_00082ff4 + 0x82d54,0x34f5,__fd,acStack_4060,local_4040);
    }
    pcVar1 = (char *)FUN_00054250(DAT_00082ffc + 0x82d64);
    iVar3 = strcmp(pcVar1,(char *)(DAT_00083000 + 0x82d70));
    if (iVar3 == 0) {
      asusdebuglog(6,DAT_00083008 + 0x82db0,0,1,0,DAT_0008300c + 0x82db8,DAT_00083004 + 0x82da4,
                   0x34f5,__fd,acStack_4060,local_4040);
    }
    iVar3 = setsockopt(__fd,1,0x14,local_4094 + 1,8);
    if (iVar3 < 0) {
      pcVar1 = (char *)FUN_00054250(DAT_00083010 + 0x82df0);
      iVar3 = strcmp(pcVar1,(char *)(DAT_00083014 + 0x82dfc));
      if (iVar3 == 0) {
        cprintf(DAT_0008301c + 0x82e1c,DAT_00083018 + 0x82e18,0x34f8);
      }
      pcVar1 = (char *)FUN_00054250(DAT_00083020 + 0x82e28);
      iVar3 = strcmp(pcVar1,(char *)(DAT_00083024 + 0x82e34));
      if (iVar3 == 0) {
        asusdebuglog(6,DAT_0008302c + 0x82e64,0,1,0,DAT_00083030 + 0x82e68,DAT_00083028 + 0x82e58,
                     0x34f8);
      }
    }
    do {
      memset(auStack_4020,0,0x4000);
      iVar3 = FUN_000202ec(__fd,auStack_4020,0x4000);
      if (iVar3 < 1) {
        pcVar1 = (char *)FUN_00054250(DAT_00083034 + 0x82ea4);
        iVar2 = strcmp(pcVar1,(char *)(DAT_00083038 + 0x82eb0));
        if (iVar2 == 0) {
          cprintf(DAT_00083040 + 0x82ed0,DAT_0008303c + 0x82ecc,0x34ff);
        }
        pcVar1 = (char *)FUN_00054250(DAT_00083044 + 0x82edc);
        iVar2 = strcmp(pcVar1,(char *)(DAT_00083048 + 0x82ee8));
        if (iVar2 == 0) {
          uVar5 = 0x34ff;
          iVar3 = DAT_0008304c + 0x82f08;
          iVar2 = DAT_00083050 + 0x82f14;
          iVar4 = DAT_00083054 + 0x82f18;
          goto LAB_00082f1c;
        }
        break;
      }
      iVar3 = FUN_00072ab8(__fd,auStack_4020,iVar3,acStack_4060,local_4040,
                           *(undefined4 *)(iVar2 + 0x82c6c + DAT_00083058),&local_4078);
    } while (iVar3 != 1);
  }
  if (local_4078 != (void *)0x0) {
    free(local_4078);
    local_4078 = (void *)0x0;
  }
  if (local_4074 != (void *)0x0) {
    free(local_4074);
    local_4074 = (void *)0x0;
  }
  if (local_4070 != (void *)0x0) {
    free(local_4070);
    local_4070 = (void *)0x0;
  }
  close(__fd);
  free(param_1);
  return 1;
}



===== cm_connDiagPktListHandler @ 00053f2c =====

undefined4 cm_connDiagPktListHandler(void)

{
  pthread_t __th;
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  __th = pthread_self();
  iVar3 = DAT_0005413c;
  pthread_detach(__th);
  iVar3 = iVar3 + 0x53f48;
  if (**(int **)(iVar3 + DAT_00054140) == 0) {
    pcVar1 = (char *)FUN_00051aec(DAT_00054144 + 0x53f60);
    iVar3 = strcmp(pcVar1,(char *)(DAT_00054148 + 0x53f6c));
    if (iVar3 == 0) {
      cprintf(DAT_00054150 + 0x53f8c,DAT_0005414c + 0x53f88,0x277);
    }
    pcVar1 = (char *)FUN_00051aec(DAT_00054154 + 0x53f98);
    iVar3 = strcmp(pcVar1,(char *)(DAT_00054158 + 0x53fa4));
    if (iVar3 == 0) {
      asusdebuglog(6,DAT_00054160 + 0x53fd4,0,1,0,DAT_00054164 + 0x53fd8,DAT_0005415c + 0x53fc8,
                   0x277);
    }
  }
  else {
    pcVar1 = (char *)FUN_00051aec(DAT_00054168 + 0x53ff0);
    iVar2 = strcmp(pcVar1,(char *)(DAT_0005416c + 0x53ffc));
    if (iVar2 == 0) {
      cprintf(DAT_00054174 + 0x5401c,DAT_00054170 + 0x54018,0x27f);
    }
    pcVar1 = (char *)FUN_00051aec(DAT_00054178 + 0x54028);
    iVar2 = strcmp(pcVar1,(char *)(DAT_0005417c + 0x54034));
    if (iVar2 == 0) {
      asusdebuglog(6,DAT_00054184 + 0x54064,0,1,0,DAT_00054188 + 0x54068,DAT_00054180 + 0x54058,
                   0x27f);
    }
    while (**(int **)(iVar3 + DAT_0005418c) == 0) {
      FUN_00053bd4();
      usleep(1000);
    }
    pcVar1 = (char *)FUN_00051aec(DAT_00054190 + 0x540a0);
    iVar2 = strcmp(pcVar1,(char *)(DAT_00054194 + 0x540ac));
    if (iVar2 == 0) {
      cprintf(DAT_0005419c + 0x540cc,DAT_00054198 + 0x540c8,0x286);
    }
    pcVar1 = (char *)FUN_00051aec(DAT_000541a0 + 0x540d8);
    iVar2 = strcmp(pcVar1,(char *)(DAT_000541a4 + 0x540e4));
    if (iVar2 == 0) {
      asusdebuglog(6,DAT_000541ac + 0x54114,0,1,0,DAT_000541b0 + 0x54118,DAT_000541a8 + 0x54108,
                   0x286);
    }
    **(undefined4 **)(iVar3 + DAT_000541b4) = 1;
  }
  return 1;
}



===== FUN_0008cf98 @ 0008cf98 =====

void FUN_0008cf98(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  fd_set local_98;
  
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = 1;
    iVar3 = *(int *)(param_1 + 0xc);
    if (*(int *)(param_1 + 0xc) < *(int *)(param_1 + 0x10)) {
      iVar3 = *(int *)(param_1 + 0x10);
    }
    iVar5 = *(int *)(param_1 + 0x14);
    if (*(int *)(param_1 + 0x14) < iVar3) {
      iVar5 = iVar3;
    }
    while( true ) {
      iVar3 = 0;
      do {
        local_98.fds_bits[iVar3] = 0;
        iVar3 = iVar3 + 1;
      } while (iVar3 != 0x20);
      uVar1 = *(uint *)(param_1 + 0xc);
      uVar2 = uVar1 + 0x1f;
      if (-1 < (int)uVar1) {
        uVar2 = uVar1;
      }
      uVar1 = uVar1 & 0x8000001f;
      bVar6 = (int)uVar1 < 0;
      if (bVar6) {
        uVar1 = ~(~((uVar1 - 1) * 0x8000000) >> 0x1b);
      }
      if (bVar6) {
        uVar1 = uVar1 + 1;
      }
      uVar4 = *(uint *)(param_1 + 0x10);
      local_98.fds_bits[(int)uVar2 >> 5] = local_98.fds_bits[(int)uVar2 >> 5] | 1 << (uVar1 & 0xff);
      uVar2 = uVar4 + 0x1f;
      if (-1 < (int)uVar4) {
        uVar2 = uVar4;
      }
      uVar4 = uVar4 & 0x8000001f;
      if ((int)uVar4 < 0) {
        uVar4 = ~(~((uVar4 - 1) * 0x8000000) >> 0x1b) + 1;
      }
      uVar1 = *(uint *)(param_1 + 0x14);
      local_98.fds_bits[(int)uVar2 >> 5] = local_98.fds_bits[(int)uVar2 >> 5] | 1 << (uVar4 & 0xff);
      uVar2 = uVar1 + 0x1f;
      if (-1 < (int)uVar1) {
        uVar2 = uVar1;
      }
      uVar1 = uVar1 & 0x8000001f;
      bVar6 = (int)uVar1 < 0;
      if (bVar6) {
        uVar1 = ~(~((uVar1 - 1) * 0x8000000) >> 0x1b);
      }
      if (bVar6) {
        uVar1 = uVar1 + 1;
      }
      local_98.fds_bits[(int)uVar2 >> 5] = local_98.fds_bits[(int)uVar2 >> 5] | 1 << (uVar1 & 0xff);
      iVar3 = select(iVar5 + 1,&local_98,(fd_set *)0x0,(fd_set *)0x0,(timeval *)0x0);
      if (iVar3 < 0) break;
      uVar1 = *(uint *)(param_1 + 0xc);
      uVar2 = uVar1 + 0x1f;
      if (-1 < (int)uVar1) {
        uVar2 = uVar1;
      }
      uVar1 = uVar1 & 0x8000001f;
      bVar6 = (int)uVar1 < 0;
      if (bVar6) {
        uVar1 = ~(~((uVar1 - 1) * 0x8000000) >> 0x1b);
      }
      if (bVar6) {
        uVar1 = uVar1 + 1;
      }
      if ((local_98.fds_bits[(int)uVar2 >> 5] & 1 << (uVar1 & 0xff)) != 0) {
        FUN_0008cbdc(param_1);
      }
      uVar1 = *(uint *)(param_1 + 0x10);
      uVar2 = uVar1 + 0x1f;
      if (-1 < (int)uVar1) {
        uVar2 = uVar1;
      }
      uVar1 = uVar1 & 0x8000001f;
      bVar6 = (int)uVar1 < 0;
      if (bVar6) {
        uVar1 = ~(~((uVar1 - 1) * 0x8000000) >> 0x1b);
      }
      if (bVar6) {
        uVar1 = uVar1 + 1;
      }
      if ((local_98.fds_bits[(int)uVar2 >> 5] & 1 << (uVar1 & 0xff)) != 0) {
        FUN_0001c310();
      }
      uVar1 = *(uint *)(param_1 + 0x14);
      uVar2 = uVar1 + 0x1f;
      if (-1 < (int)uVar1) {
        uVar2 = uVar1;
      }
      uVar1 = uVar1 & 0x8000001f;
      bVar6 = (int)uVar1 < 0;
      if (bVar6) {
        uVar1 = uVar1 - 1;
      }
      if (bVar6) {
        uVar1 = ~(~(uVar1 << 0x1b) >> 0x1b) + 1;
      }
      if ((local_98.fds_bits[(int)uVar2 >> 5] & 1 << (uVar1 & 0xff)) != 0) {
        FUN_000244b8();
      }
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  return;
}


