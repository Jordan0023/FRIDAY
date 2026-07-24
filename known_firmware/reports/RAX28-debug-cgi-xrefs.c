STRING 00014f7e ParseRaDebugPageQuery HTTPserverIP ok
REF 00013cec owner=FUN_000139e4
REF 00012528 owner=FUN_00011324
STRING 00014faa ParseRaDebugPageQuery HTTPserverIP empty
REF 00014110 owner=FUN_000139e4
STRING 00014fe5 ParseRaDebugPageQuery serverPath ok
REF 00013d4c owner=FUN_000139e4
REF 000125b4 owner=FUN_00011324
STRING 00015009 ParseRaDebugPageQuery serverPath empty
REF 00014164 owner=FUN_000139e4
STRING 000153c7 var timer = setTimeout(function() {
REF 00014830 owner=FUN_000147c0
STRING 000154b1 REQUEST_METHOD
REF 00011438 owner=FUN_00011324
STRING 000154c0 CGI_ERROR> %s:%d: Can't get REQUEST_METHOD!!!

REF 00011454 owner=FUN_00011324
STRING 000154fe CGI_ERROR> %s:%d: unknow REQUEST_METHOD %s

REF 0001154c owner=FUN_00011324
STRING 00015802 function
REF 00011ee0 owner=FUN_00011324
STRING 00015a72 action_Clean_All
REF 00012ee0 owner=FUN_00011324
STRING 00015ad7 HTTPserverIP
REF 000124d4 owner=FUN_00011324
STRING 00015ae4 ParseRaDebugPageQuery HTTPserverIP fail
REF 000131a0 owner=FUN_00011324
STRING 00015b0c serverPath
REF 00012554 owner=FUN_00011324
STRING 00015b17 ParseRaDebugPageQuery serverPath fail
REF 000131dc owner=FUN_00011324
CALLER_REF target=FUN_000139e4 from=00012ab0 owner=FUN_00011324
CALLER_REF target=FUN_000139e4 from=00013424 owner=FUN_00011324
CALLER_REF target=FUN_00011324 from=_elfSectionHeaders::00000214 owner=NONE
CALLER_REF target=FUN_00011324 from=00013774 owner=entry
CALLER_REF target=FUN_000147c0 from=000133f0 owner=FUN_00011324

===== FUN_000139e4 @ 000139e4 =====

void FUN_000139e4(char *param_1,int *param_2)

{
  FILE *__stream;
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int extraout_r3;
  undefined4 *puVar8;
  undefined4 uVar9;
  
  iVar4 = DAT_000141ec;
  __stream = fopen(param_1,(char *)(DAT_000141e8 + 0x13a04));
  puVar8 = *(undefined4 **)(iVar4 + 0x13a10 + DAT_000141f0);
  iVar4 = *param_2;
  fprintf((FILE *)*puVar8,(char *)(DAT_000141f8 + 0x13a28),DAT_000141f4 + 0x13a20,0x280,iVar4);
  if (*(byte *)(param_2 + 0x12) != 0) {
    fprintf(__stream,(char *)(DAT_000141fc + 0x13a58),param_2 + 0x12,(uint)*(byte *)(param_2 + 0x12)
            ,iVar4);
  }
  iVar5 = *param_2;
  if (iVar5 == 2) {
    iVar2 = DAT_00014200 + 0x13a74;
    pcVar1 = (char *)(DAT_00014204 + 0x13a78);
LAB_00013a74:
    fprintf(__stream,pcVar1,iVar2,iVar5,iVar4);
  }
  else if (iVar5 != -1) {
    iVar2 = DAT_000142fc + 0x13f28;
    pcVar1 = (char *)(DAT_00014300 + 0x13f2c);
    goto LAB_00013a74;
  }
  iVar5 = param_2[1];
  if (iVar5 == 1) {
    iVar2 = DAT_00014208 + 0x13a98;
    pcVar1 = (char *)(DAT_0001420c + 0x13a9c);
LAB_00013a98:
    fprintf(__stream,pcVar1,iVar2,iVar5,iVar4);
  }
  else if (iVar5 == 0) {
    iVar2 = DAT_00014304 + 0x13f44;
    pcVar1 = (char *)(DAT_00014308 + 0x13f48);
    goto LAB_00013a98;
  }
  iVar5 = param_2[2];
  if (iVar5 == 0) {
    iVar2 = DAT_00014210 + 0x13abc;
    pcVar1 = (char *)(DAT_00014214 + 0x13ac0);
LAB_00013abc:
    fprintf(__stream,pcVar1,iVar2,iVar5,iVar4);
  }
  else if (iVar5 != -1) {
    iVar2 = DAT_0001430c + 0x13f60;
    pcVar1 = (char *)(DAT_00014310 + 0x13f64);
    goto LAB_00013abc;
  }
  if (param_2[3] == 1) {
    iVar5 = DAT_00014218 + 0x13ae0;
    pcVar1 = (char *)(DAT_0001421c + 0x13ae4);
LAB_00013ae0:
    fprintf(__stream,pcVar1,iVar5);
  }
  else if (param_2[3] == 0) {
    iVar5 = DAT_00014314 + 0x13f7c;
    pcVar1 = (char *)(DAT_00014318 + 0x13f80);
    goto LAB_00013ae0;
  }
  if (param_2[4] == 1) {
    fprintf(__stream,(char *)(DAT_00014224 + 0x13b0c),DAT_00014220 + 0x13b08);
    iVar5 = DAT_00014228 + 0x13b28;
    iVar2 = DAT_00014230 + 0x13b30;
    iVar4 = DAT_0001422c + 0x13b34;
    pcVar1 = (char *)(DAT_00014234 + 0x13b3c);
    uVar6 = 0x29b;
    uVar9 = 0x29b;
LAB_00013b44:
    fprintf((FILE *)*puVar8,pcVar1,iVar4,uVar6,iVar4,iVar5,uVar9,iVar2);
  }
  else if (param_2[4] != -1) {
    fprintf(__stream,(char *)(DAT_00014320 + 0x13fa0),DAT_0001431c + 0x13f9c);
    iVar5 = DAT_00014324 + 0x13fbc;
    iVar2 = DAT_0001432c + 0x13fc4;
    iVar4 = DAT_00014328 + 0x13fc8;
    pcVar1 = (char *)(DAT_00014330 + 0x13fd0);
    uVar6 = 0x29f;
    uVar9 = 0x29f;
    goto LAB_00013b44;
  }
  if (param_2[5] == 1) {
    iVar2 = DAT_00014238 + 0x13b68;
    pcVar1 = (char *)(DAT_0001423c + 0x13b6c);
    iVar5 = 1;
LAB_00013b68:
    fprintf(__stream,pcVar1,iVar2,iVar5,iVar4);
  }
  else {
    iVar5 = *param_2;
    if (iVar5 != -1) {
      iVar2 = DAT_00014334 + 0x13ff8;
      pcVar1 = (char *)(DAT_00014338 + 0x13ffc);
      goto LAB_00013b68;
    }
  }
  iVar5 = param_2[6];
  if (iVar5 == 1) {
    fprintf(__stream,(char *)(DAT_00014244 + 0x13b94),DAT_00014240 + 0x13b90,1,iVar4);
    iVar4 = DAT_00014248 + 0x13bb0;
    iVar2 = DAT_00014250 + 0x13bb8;
    iVar5 = DAT_0001424c + 0x13bbc;
    pcVar1 = (char *)(DAT_00014254 + 0x13bc4);
    uVar6 = 0x2a9;
    uVar9 = 0x2a9;
LAB_00013bcc:
    fprintf((FILE *)*puVar8,pcVar1,iVar5,uVar6,iVar5,iVar4,uVar9,iVar2);
  }
  else if (iVar5 != -1) {
    fprintf(__stream,(char *)(DAT_00014340 + 0x1401c),DAT_0001433c + 0x14018,iVar5,iVar4);
    iVar4 = DAT_00014344 + 0x14038;
    iVar2 = DAT_0001434c + 0x14040;
    iVar5 = DAT_00014348 + 0x14044;
    pcVar1 = (char *)(DAT_00014350 + 0x1404c);
    uVar6 = 0x2ad;
    uVar9 = 0x2ad;
    goto LAB_00013bcc;
  }
  iVar4 = param_2[0x20];
  fprintf((FILE *)*puVar8,(char *)(DAT_0001425c + 0x13bf8),DAT_00014258 + 0x13bec,0x2b0,iVar4);
  iVar5 = param_2[0x20];
  if (iVar5 == 1) {
    iVar2 = DAT_00014260 + 0x13c14;
    pcVar1 = (char *)(DAT_00014264 + 0x13c18);
LAB_00013c14:
    fprintf(__stream,pcVar1,iVar2,iVar5,iVar4);
  }
  else if (iVar5 != -1) {
    iVar2 = DAT_00014354 + 0x14070;
    pcVar1 = (char *)(DAT_00014358 + 0x14074);
    goto LAB_00013c14;
  }
  if (param_2[0x21] == 1) {
    iVar5 = DAT_00014268 + 0x13c38;
    pcVar1 = (char *)(DAT_0001426c + 0x13c3c);
  }
  else {
    iVar5 = DAT_0001435c + 0x14084;
    pcVar1 = (char *)(DAT_00014360 + 0x14088);
  }
  fprintf(__stream,pcVar1,iVar5,param_2[0x21],iVar4);
  if (*(byte *)(param_2 + 9) != 0) {
    fprintf(__stream,(char *)(DAT_00014270 + 0x13c60),param_2 + 9,(uint)*(byte *)(param_2 + 9),iVar4
           );
  }
  iVar5 = param_2[0x11];
  if (iVar5 == 1) {
    iVar2 = DAT_00014274 + 0x13c7c;
    pcVar1 = (char *)(DAT_00014278 + 0x13c80);
  }
  else {
    if (iVar5 == -1) goto LAB_00013c84;
    iVar2 = DAT_00014364 + 0x140a0;
    pcVar1 = (char *)(DAT_00014368 + 0x140a4);
  }
  fprintf(__stream,pcVar1,iVar2,iVar5,iVar4);
LAB_00013c84:
  if (param_2[0x22] == 0) {
    iVar4 = DAT_0001427c + 0x13ca0;
    pcVar1 = (char *)(DAT_00014280 + 0x13ca4);
  }
  else if (param_2[0x22] == 1) {
    iVar4 = DAT_0001436c + 0x140bc;
    pcVar1 = (char *)(DAT_00014370 + 0x140c0);
  }
  else {
    iVar4 = DAT_00014374 + 0x140d0;
    pcVar1 = (char *)(DAT_00014378 + 0x140d4);
  }
  fprintf(__stream,pcVar1,iVar4);
  if ((char)param_2[0x23] == '\0') {
    fprintf(__stream,(char *)(DAT_00014380 + 0x140ec),DAT_0001437c + 0x140e8);
    iVar4 = DAT_00014384 + 0x14108;
    iVar2 = DAT_0001438c + 0x14110;
    iVar5 = DAT_00014388 + 0x14114;
    pcVar1 = (char *)(DAT_00014390 + 0x1411c);
    uVar6 = 0x2eb;
    uVar9 = 0x2eb;
  }
  else {
    fprintf(__stream,(char *)(DAT_00014284 + 0x13cc8),param_2 + 0x23);
    iVar4 = DAT_00014288 + 0x13ce4;
    iVar2 = DAT_00014290 + 0x13cec;
    iVar5 = DAT_0001428c + 0x13cf0;
    pcVar1 = (char *)(DAT_00014294 + 0x13cf8);
    uVar6 = 0x2e7;
    uVar9 = 0x2e7;
  }
  fprintf((FILE *)*puVar8,pcVar1,iVar5,uVar6,iVar5,iVar4,uVar9,iVar2);
  if (*(byte *)(param_2 + 0x33) == 0) {
    fprintf(__stream,(char *)(DAT_00014398 + 0x14140),DAT_00014394 + 0x1413c,0,iVar5,iVar4,uVar9,
            iVar2);
    iVar4 = DAT_0001439c + 0x1415c;
    iVar2 = DAT_000143a4 + 0x14164;
    iVar5 = DAT_000143a0 + 0x14168;
    pcVar1 = (char *)(DAT_000143a8 + 0x14170);
    uVar6 = 0x2f3;
    uVar9 = 0x2f3;
  }
  else {
    fprintf(__stream,(char *)(DAT_00014298 + 0x13d28),param_2 + 0x33,(uint)*(byte *)(param_2 + 0x33)
            ,iVar5,iVar4,uVar9,iVar2);
    iVar4 = DAT_0001429c + 0x13d44;
    iVar2 = DAT_000142a4 + 0x13d4c;
    iVar5 = DAT_000142a0 + 0x13d50;
    pcVar1 = (char *)(DAT_000142a8 + 0x13d58);
    uVar6 = 0x2ef;
    uVar9 = 0x2ef;
  }
  fprintf((FILE *)*puVar8,pcVar1,iVar5,uVar6,iVar5,iVar4,uVar9,iVar2);
  if (param_2[0x1f] == 1) {
    fprintf(__stream,(char *)(DAT_000142b0 + 0x13d8c),DAT_000142ac + 0x13d88,1,iVar5,iVar4,uVar9,
            iVar2);
    fprintf((FILE *)*puVar8,(char *)(DAT_000142c0 + 0x13dc4),DAT_000142b8 + 0x13db4,0x2f7,
            DAT_000142b8 + 0x13db4,DAT_000142b4 + 0x13da8,0x2f7,DAT_000142bc + 0x13db0);
  }
  if (param_2[0x43] == 0) {
    iVar5 = DAT_000143ac + 0x14198;
    iVar4 = DAT_000143b4 + 0x141a0;
    iVar2 = DAT_000143b0 + 0x141a4;
    pcVar1 = (char *)(DAT_000143b8 + 0x141ac);
    uVar6 = 0x307;
    uVar9 = 0x307;
  }
  else {
    iVar5 = DAT_000142c4 + 0x13df8;
    iVar4 = DAT_000142cc + 0x13e00;
    iVar2 = DAT_000142c8 + 0x13e04;
    pcVar1 = (char *)(DAT_000142d0 + 0x13e0c);
    uVar6 = 0x2fa;
    uVar9 = 0x2fa;
  }
  fprintf((FILE *)*puVar8,pcVar1,iVar2,uVar6,iVar2,iVar5,uVar9,iVar4);
  iVar7 = param_2[0x44];
  if (iVar7 < 1) {
    iVar3 = 0;
    pcVar1 = (char *)(DAT_000143bc + 0x141c8);
  }
  else {
    iVar5 = DAT_000142d4 + 0x13e40;
    iVar2 = DAT_000142d8 + 0x13e48;
    uVar9 = 0x30b;
    iVar4 = iVar7;
    fprintf((FILE *)*puVar8,(char *)(DAT_000142dc + 0x13e54),iVar2,0x30b,iVar2,iVar5,0x30b,iVar7);
    iVar3 = param_2[0x44];
    pcVar1 = (char *)(DAT_000142e0 + 0x13e6c);
    iVar7 = extraout_r3;
  }
  fprintf(__stream,pcVar1,iVar3,iVar7,iVar2,iVar5,uVar9,iVar4);
  if (param_2[0x45] == 0) {
    pcVar1 = (char *)(DAT_000143c0 + 0x141d4);
    iVar4 = 0;
  }
  else {
    fprintf((FILE *)*puVar8,(char *)(DAT_000142ec + 0x13eb8),DAT_000142e4 + 0x13e94,0x315,
            DAT_000142e4 + 0x13e94,DAT_000142e8 + 0x13ea8,0x315,param_2[0x45]);
    iVar4 = param_2[0x45];
    pcVar1 = (char *)(DAT_000142f0 + 0x13ec8);
  }
  fprintf(__stream,pcVar1,iVar4);
  fclose(__stream);
  iVar4 = open(param_1,0);
  if (iVar4 == -1) {
    fprintf((FILE *)*puVar8,(char *)(DAT_000142f8 + 0x13f08),DAT_000142f4 + 0x13f04,0x323);
    return;
  }
  fsync(iVar4);
  close(iVar4);
  return;
}



===== FUN_00011324 @ 00011324 =====

undefined4 FUN_00011324(undefined4 param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  FILE *pFVar5;
  char *pcVar6;
  size_t sVar7;
  void *pvVar8;
  ulong uVar9;
  long lVar10;
  __pid_t _Var11;
  int iVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 *puVar16;
  int *piVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 local_4c8;
  int local_4c4;
  undefined1 auStack_4c0 [28];
  char local_4a4 [32];
  int local_484;
  undefined1 auStack_480 [96];
  int local_420;
  undefined1 auStack_41c [1020];
  
  iVar12 = DAT_000119cc + 0x11344;
  iVar18 = DAT_000119d0 + 0x11350;
  local_4c8 = 0;
  puVar16 = *(undefined4 **)(iVar12 + DAT_00011c64);
  fprintf((FILE *)*puVar16,(char *)(DAT_000119d4 + 0x11368),iVar18,0x115);
  puVar14 = *(undefined4 **)(iVar12 + DAT_000119d8);
  iVar2 = cmsMsg_initWithFlags(10,0,puVar14);
  if (iVar2 != 0) {
    fprintf((FILE *)*puVar16,(char *)(DAT_000119dc + 0x113ac),iVar18,0x118,iVar2);
    cmsLog_cleanup();
    return 0xffffffff;
  }
  cmsLog_initWithName(10,*param_2);
  cmsLog_setLevel(3);
  iVar3 = cmsMdm_initWithAcc(10,0x200,*puVar14,&local_4c8);
  iVar2 = DAT_000119e4;
  if (iVar3 != 0) {
    fprintf((FILE *)*puVar16,(char *)(DAT_000119e0 + 0x11410),iVar18,0x121,iVar3);
    cmsMsg_cleanup(puVar14);
    return 0xffffffff;
  }
  puVar14 = (undefined4 *)(DAT_000119e4 + 0x11428);
  *(undefined4 *)(DAT_000119e4 + 0x1142c) = 0;
  *(undefined4 *)(iVar2 + 0x11430) = 0;
  *(undefined4 *)(iVar2 + 0x1149c) = 0;
  *(undefined1 *)(iVar2 + 0x1156f) = 0;
  pcVar4 = getenv((char *)(DAT_000119e8 + 0x11440));
  if (pcVar4 == (char *)0x0) {
    uVar13 = 0x43;
    pcVar4 = (char *)(DAT_000119ec + 0x1145c);
    goto LAB_00011458;
  }
  iVar2 = strcmp(pcVar4,(char *)(DAT_000119f0 + 0x1146c));
  if (iVar2 == 0) {
    uVar13 = 1;
  }
  else {
    iVar2 = strcmp(pcVar4,(char *)(DAT_000119f4 + 0x11488));
    if (iVar2 == 0) {
      uVar13 = 3;
    }
    else {
      iVar2 = strcmp(pcVar4,(char *)(DAT_000119f8 + 0x114a4));
      if (iVar2 == 0) {
        uVar13 = 2;
      }
      else {
        iVar2 = strcmp(pcVar4,(char *)(DAT_000119fc + 0x114c0));
        if (iVar2 != 0) {
          fprintf((FILE *)*puVar16,(char *)(DAT_00011a14 + 0x11554),iVar18,0x50,pcVar4);
          uVar13 = 0x195;
          goto LAB_00011558;
        }
        uVar13 = 4;
      }
    }
  }
  iVar2 = DAT_00011a00;
  *puVar14 = uVar13;
  pcVar4 = getenv((char *)(iVar2 + 0x114dc));
  iVar2 = DAT_00011a04;
  if (pcVar4 == (char *)0x0) {
    *(undefined1 *)(DAT_00011a20 + 0x1166a) = 0;
  }
  else {
    strncpy((char *)(DAT_00011a04 + 0x115d6),pcVar4,100);
    *(undefined1 *)(iVar2 + 0x1163a) = 0;
  }
  pcVar4 = getenv((char *)(DAT_00011a08 + 0x1150c));
  if (pcVar4 == (char *)0x0) {
    fprintf((FILE *)*puVar16,(char *)(DAT_00011a10 + 0x11530),DAT_00011a0c + 0x1152c,0x60);
    uVar13 = 0x1f7;
    goto LAB_00011558;
  }
  pcVar6 = strchr(pcVar4,0x3f);
  iVar18 = DAT_00011a50;
  iVar2 = DAT_00011a44;
  if (pcVar6 == (char *)0x0) {
    strncpy((char *)(DAT_00011a50 + 0x11704),pcVar4,100);
    *(undefined1 *)(iVar18 + 0x11768) = 0;
    *(undefined4 *)(iVar18 + 0x116fc) = 0;
  }
  else {
    uVar19 = (int)pcVar6 - (int)pcVar4;
    if (uVar19 < 100) {
      iVar2 = DAT_00011a24 + uVar19;
      memcpy((void *)(DAT_00011a24 + 0x115c8),pcVar4,uVar19);
      *(undefined1 *)(iVar2 + 0x115c8) = 0;
    }
    else {
      memcpy((void *)(DAT_00011a44 + 0x116c4),pcVar4,100);
      *(undefined1 *)(iVar2 + 0x11728) = 0;
    }
    sVar7 = strlen(pcVar6 + 1);
    pvVar8 = malloc(sVar7 + 1);
    *(void **)(DAT_00011a28 + 0x115f8) = pvVar8;
    if (pvVar8 == (void *)0x0) {
      uVar13 = 0x76;
      iVar18 = DAT_00011a48 + 0x116e0;
      pcVar4 = (char *)(DAT_00011a4c + 0x116e4);
      goto LAB_00011458;
    }
    memcpy(pvVar8,pcVar6 + 1,sVar7);
    *(undefined1 *)((int)pvVar8 + sVar7) = 0;
  }
  iVar2 = DAT_00011a2c;
  if (*(int *)(DAT_00011a2c + 0x11620) == 1) {
    *(undefined4 *)(DAT_00011a2c + 0x11628) = 0;
LAB_00011860:
    pcVar4 = getenv((char *)(DAT_00011a80 + 0x1186c));
    iVar2 = DAT_00011a84;
    if (pcVar4 == (char *)0x0) {
      uVar13 = 0xd9;
      iVar18 = DAT_00011aac + 0x119c8;
      pcVar4 = (char *)((int)&DAT_000119cc + DAT_00011ab0);
    }
    else {
      strncpy((char *)(DAT_00011a84 + 0x11900),pcVar4,0x32);
      iVar18 = DAT_00011a88;
      *(undefined1 *)(iVar2 + 0x11932) = 0;
      pcVar4 = getenv((char *)(iVar18 + 0x1189c));
      if (pcVar4 != (char *)0x0) {
        strncpy((char *)(iVar2 + 0x11933),pcVar4,0x32);
        iVar18 = DAT_00011ab4;
        *(undefined1 *)(iVar2 + 0x11965) = 0;
        pcVar4 = getenv((char *)(iVar18 + 0x11d70));
        if (pcVar4 == (char *)0x0) {
          uVar1 = 0;
        }
        else {
          lVar10 = atol(pcVar4);
          uVar1 = (undefined2)lVar10;
        }
        iVar2 = DAT_00011ab8;
        *(undefined2 *)(DAT_00011ab8 + 0x11e6e) = uVar1;
        pcVar4 = getenv((char *)(DAT_00011abc + 0x11d9c));
        if (pcVar4 == (char *)0x0) {
          *(undefined2 *)(iVar2 + 0x11e70) = 0;
        }
        else {
          lVar10 = atol(pcVar4);
          *(short *)(iVar2 + 0x11e70) = (short)lVar10;
        }
        iVar2 = DAT_00011acc;
        iVar15 = DAT_00011ac0 + 0x11dc0;
        fprintf((FILE *)*puVar16,(char *)(DAT_00011ac8 + 0x11dd4),iVar15,0x12f,
                DAT_00011ac4 + 0x11dc8);
        iVar18 = iVar2 + 0x11df0;
        fprintf((FILE *)*puVar16,(char *)(DAT_00011ad0 + 0x11dfc),iVar15,0x131,iVar18);
        iVar3 = *(int *)(iVar2 + 0x11dec);
        if (iVar3 != 0) {
          fprintf((FILE *)*puVar16,(char *)(DAT_00011ad4 + 0x11e28),iVar15,0x134,iVar3);
          pFVar5 = fopen((char *)(DAT_00011adc + 0x11e40),(char *)(DAT_00011ad8 + 0x11e3c));
          fputs(*(char **)(iVar2 + 0x11dec),pFVar5);
          fclose(pFVar5);
          iVar18 = iVar3;
        }
        iVar2 = *(int *)(DAT_00011ae0 + 0x11e68);
        if (iVar2 != 0) {
          fprintf((FILE *)*puVar16,(char *)(DAT_00011ae8 + 0x11e88),DAT_00011ae4 + 0x11e80,0x13a,
                  iVar2);
          iVar18 = iVar2;
        }
        iVar2 = DAT_00011aec;
        piVar17 = (int *)(DAT_00011aec + 0x11e98);
        iVar3 = *piVar17;
        if (iVar3 == 2) {
          pcVar4 = strstr((char *)(DAT_00011aec + 0x11ea4),(char *)(DAT_00011af0 + 0x11eb0));
          if (pcVar4 != (char *)0x0) {
            local_4a4[0] = '\0';
            local_4a4[1] = '\0';
            local_4a4[2] = '\0';
            local_4a4[3] = '\0';
            memset(local_4a4 + 4,0,0x1c);
            iVar18 = FUN_00013844(*(undefined4 *)(iVar2 + 0x11ea0),DAT_00011af4 + 0x11ee8,local_4a4,
                                  0x20);
            if (iVar18 == 0) {
              uVar13 = *(undefined4 *)(iVar2 + 0x11ea0);
              local_484 = iVar18;
              memset(auStack_480,0,0x1c);
              iVar3 = DAT_00011af8;
              local_420 = iVar18;
              memset(auStack_41c,0,0x1c);
              iVar3 = iVar3 + 0x11f40;
              uVar21 = 0x38f;
              iVar20 = DAT_00011afc + 0x11fc5;
              iVar18 = iVar20;
              fprintf((FILE *)*puVar16,(char *)(DAT_00011b00 + 0x11f58),iVar3,0x38f,iVar3,iVar20,
                      0x38f);
              fprintf((FILE *)*puVar16,(char *)(DAT_00011b04 + 0x11f7c),iVar3,0x390,
                      *(undefined4 *)(iVar2 + 0x1204c));
              *(undefined4 *)(iVar2 + 0x1204c) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x12050) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x12054) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x12058) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x1205c) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x12060) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x12064) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x1206c) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x12090) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x120d4) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x12158) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x120c8) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x120cc) = 0xffffffff;
              *(undefined4 *)(iVar2 + 0x120d0) = 0xffffffff;
              *(undefined1 *)(iVar2 + 0x12070) = 0;
              *(undefined1 *)(iVar2 + 0x120d8) = 0;
              *(undefined1 *)(iVar2 + 0x12118) = 0;
              *(undefined1 *)(iVar2 + 0x12094) = 0;
              iVar15 = FUN_00013844(uVar13,DAT_00011b08 + 0x11ff0,&local_484,0x20);
              if (iVar15 == 0) {
                iVar15 = strcmp((char *)&local_484,(char *)(DAT_00011b0c + 0x12008));
                if (iVar15 == 0) {
                  uVar21 = 0x398;
                  fprintf((FILE *)*puVar16,(char *)(DAT_00011b14 + 0x12034),iVar3,0x398,iVar3,iVar20
                          ,0x398,DAT_00011b10 + 0x12028);
                  uVar22 = 0;
                }
                else {
                  iVar15 = strcmp((char *)&local_484,(char *)(DAT_00011d2c + 0x12c74));
                  if (iVar15 != 0) goto LAB_00012048;
                  uVar21 = 0x39d;
                  fprintf((FILE *)*puVar16,(char *)(DAT_00011d34 + 0x12c9c),iVar3,0x39d,iVar3,iVar20
                          ,0x39d,DAT_00011d30 + 0x12c90);
                  uVar22 = 1;
                }
                *(undefined4 *)(iVar2 + 0x12054) = uVar22;
                iVar18 = iVar20;
              }
LAB_00012048:
              iVar3 = DAT_00011b18 + 0x12060;
              iVar2 = FUN_00013844(uVar13,iVar3,&local_484,0x20);
              if (iVar2 == 0) {
                iVar2 = DAT_00011b20 + 0x12088;
                fprintf((FILE *)*puVar16,(char *)(DAT_00011b24 + 0x120a0),iVar2,0x3a4,iVar2,
                        DAT_00011b1c + 0x120f9,0x3a4,iVar3);
                fprintf((FILE *)*puVar16,(char *)(DAT_00011b28 + 0x120bc),iVar2,0x3a5,&local_484);
                iVar2 = strcmp((char *)&local_484,(char *)(DAT_00011b2c + 0x120d4));
                if (iVar2 == 0) {
                  *(undefined4 *)(DAT_00011b30 + 0x122ac) = 1;
                }
                else {
                  iVar2 = strcmp((char *)&local_484,(char *)(DAT_00011d38 + 0x12cc0));
                  if (iVar2 == 0) {
                    *(undefined4 *)(DAT_00011d3c + 0x12e90) = 0;
                  }
                }
                iVar18 = DAT_00011b38 + 0x1217d;
                uVar21 = 0x3bb;
                fprintf((FILE *)*puVar16,(char *)(DAT_00011b40 + 0x12128),DAT_00011b3c + 0x12114,
                        0x3bb,DAT_00011b3c + 0x12114,iVar18,0x3bb,
                        *(undefined4 *)(DAT_00011b34 + 0x122bc));
              }
              iVar3 = DAT_00011b44 + 0x12148;
              iVar2 = FUN_00013844(uVar13,iVar3,&local_484,0x20);
              if (iVar2 == 0) {
                uVar21 = 0x3bf;
                iVar18 = DAT_00011b48 + 0x121e1;
                fprintf((FILE *)*puVar16,(char *)(DAT_00011b50 + 0x12188),DAT_00011b4c + 0x1217c,
                        0x3bf,DAT_00011b4c + 0x1217c,iVar18,0x3bf,iVar3);
                *(undefined4 *)(DAT_00011b54 + 0x123cc) = 1;
              }
              iVar3 = DAT_00011b58 + 0x121b4;
              iVar2 = FUN_00013844(uVar13,iVar3,&local_484,0x20);
              if (iVar2 == 0) {
                uVar21 = 0x3c3;
                iVar2 = DAT_00011b60 + 0x121dc;
                iVar18 = DAT_00011b5c + 0x1224d;
                fprintf((FILE *)*puVar16,(char *)(DAT_00011b64 + 0x121f4),iVar2,0x3c3,iVar2,iVar18,
                        0x3c3,iVar3);
                fprintf((FILE *)*puVar16,(char *)(DAT_00011b68 + 0x12210),iVar2,0x3c4,&local_484);
                iVar2 = strcmp((char *)&local_484,(char *)(DAT_00011b6c + 0x12228));
                if (iVar2 == 0) {
                  *(undefined4 *)(DAT_00011b70 + 0x123f4) = 2;
                }
              }
              iVar2 = FUN_00013844(uVar13,DAT_00011b74 + 0x12258,&local_484,0x20);
              if (iVar2 == 0) {
                iVar2 = DAT_00011b7c + 0x12278;
                fprintf((FILE *)*puVar16,(char *)(DAT_00011b84 + 0x12298),iVar2,0x3ca,iVar2,
                        DAT_00011b78 + 0x122e9,0x3ca,DAT_00011b80 + 0x12284);
                fprintf((FILE *)*puVar16,(char *)(DAT_00011b88 + 0x122b8),iVar2,0x3cb,&local_484);
                iVar2 = strcmp((char *)&local_484,(char *)(DAT_00011b8c + 0x122d0));
                if (iVar2 == 0) {
                  *(undefined4 *)(DAT_00011b90 + 0x1251c) = 1;
                }
                else {
                  iVar2 = strcmp((char *)&local_484,(char *)(DAT_00011d40 + 0x12ce4));
                  if (iVar2 == 0) {
                    *(undefined4 *)(DAT_00011d44 + 0x12f28) = 0;
                  }
                }
                iVar18 = DAT_00011b98 + 0x12379;
                uVar21 = 0x3d3;
                fprintf((FILE *)*puVar16,(char *)(DAT_00011ba0 + 0x12324),DAT_00011b9c + 0x12310,
                        0x3d3,DAT_00011b9c + 0x12310,iVar18,0x3d3,
                        *(undefined4 *)(DAT_00011b94 + 0x1252c));
              }
              iVar2 = FUN_00013844(uVar13,DAT_00011ba4 + 0x12344,&local_484,0x20);
              if (iVar2 == 0) {
                iVar3 = DAT_00011ba8 + 0x1235c;
                iVar18 = DAT_00011bac + 0x123e1;
                fprintf((FILE *)*puVar16,(char *)(DAT_00011bb4 + 0x1237c),iVar3,0x3d8,iVar3,iVar18,
                        0x3d8,DAT_00011bb0 + 0x12370,&local_484);
                iVar2 = strcmp((char *)&local_484,(char *)(DAT_00011bb8 + 0x123a4));
                pcVar4 = (char *)(DAT_00011bc0 + 0x123bc);
                *(uint *)(DAT_00011bbc + 0x125f0) = (uint)(iVar2 == 0);
                uVar21 = 0x3e3;
                fprintf((FILE *)*puVar16,pcVar4,iVar3,0x3e3,iVar3,iVar18,0x3e3,(uint)(iVar2 == 0));
              }
              iVar2 = FUN_00013844(uVar13,DAT_00011bc4 + 0x123f8,&local_484,0x20);
              if (iVar2 == 0) {
                fprintf((FILE *)*puVar16,(char *)(DAT_00011bcc + 0x1241c),DAT_00011bc8 + 0x12414,
                        0x3ea,&local_484,iVar18,uVar21);
                iVar2 = strcmp((char *)&local_484,(char *)(DAT_00011bd0 + 0x12430));
                if (iVar2 == 0) {
                  *(undefined4 *)(DAT_00011bd4 + 0x12600) = 1;
                }
                else {
                  iVar2 = strcmp((char *)&local_484,(char *)(DAT_00011d48 + 0x12d08));
                  if (iVar2 == 0) {
                    *(undefined4 *)(DAT_00011d4c + 0x12ed0) = 0;
                  }
                }
              }
              else {
                iVar18 = DAT_00011d50 + 0x12d34;
                iVar2 = FUN_00013844(uVar13,iVar18,&local_484,0x20);
                if (iVar2 == 0) {
                  iVar15 = DAT_000135c8 + 0x12d54;
                  uVar21 = 0x3fd;
                  iVar3 = DAT_000135cc + 0x12dd9;
                  fprintf((FILE *)*puVar16,(char *)(DAT_000135d0 + 0x12d70),iVar15,0x3fd,iVar15,
                          iVar3,0x3fd,iVar18);
                  local_4c4 = iVar2;
                  memset(auStack_4c0,0,0x1c);
                  piVar17 = (int *)cmsObj_get(0x578,auStack_4c0,0,&local_4c4);
                  if (piVar17 == (int *)0x0) {
                    cmsUtl_strcpy(&local_420,*(undefined4 *)(local_4c4 + 0x1c));
                    uVar22 = 0x385;
                    pcVar4 = (char *)(DAT_000135e4 + 0x12e44);
                    piVar17 = &local_420;
                  }
                  else {
                    uVar22 = 0x380;
                    pcVar4 = (char *)(DAT_000135d4 + 0x12dcc);
                  }
                  iVar2 = DAT_000135d8;
                  fprintf((FILE *)*puVar16,pcVar4,iVar15,uVar22,piVar17,iVar3,uVar21,iVar18);
                  strcpy((char *)(iVar2 + 0x12fb0),(char *)&local_420);
                  iVar18 = strcmp((char *)&local_484,(char *)(DAT_000135dc + 0x12df4));
                  if (iVar18 == 0) {
                    *(undefined4 *)(iVar2 + 0x12fac) = 1;
                  }
                  else {
                    iVar18 = strcmp((char *)&local_484,(char *)(DAT_000135e0 + 0x12e14));
                    if (iVar18 == 0) {
                      *(undefined4 *)(iVar2 + 0x12fac) = 0;
                    }
                  }
                }
                else {
                  iVar3 = DAT_000135e8 + 0x12e60;
                  iVar18 = FUN_00013844(uVar13,iVar3,&local_484,0x20);
                  iVar2 = DAT_000135f8;
                  if (iVar18 == 0) {
                    fprintf((FILE *)*puVar16,(char *)(DAT_000135f4 + 0x12ea0),DAT_000135f0 + 0x12e94
                            ,0x406,DAT_000135f0 + 0x12e94,DAT_000135ec + 0x12ef9,0x406,iVar3);
                    pcVar4 = (char *)(DAT_000135fc + 0x12ebc);
                    *(undefined4 *)(iVar2 + 78000) = 0;
                    iVar18 = strcmp((char *)&local_484,pcVar4);
                    if (iVar18 == 0) {
                      *(undefined4 *)(iVar2 + 78000) = 1;
                    }
                  }
                  else {
                    iVar2 = FUN_00013844(uVar13,DAT_00013600 + 0x12ee8,&local_484,0x20);
                    if (iVar2 == 0) {
                      fprintf((FILE *)*puVar16,(char *)(DAT_00013610 + 0x12f24),
                              DAT_00013608 + 0x12f14,0x40e,DAT_00013608 + 0x12f14,
                              DAT_00013604 + 0x12f79,0x40e,DAT_0001360c + 0x12f18);
                      iVar2 = strcmp((char *)&local_484,(char *)(DAT_00013614 + 0x12f40));
                      if (iVar2 == 0) {
                        *(undefined4 *)(DAT_00013618 + 0x13120) = 1;
                      }
                    }
                    else {
                      iVar18 = DAT_0001361c + 0x12f74;
                      iVar2 = FUN_00013844(uVar13,iVar18,&local_484,0x20);
                      if (iVar2 == 0) {
                        iVar3 = DAT_00013620 + 0x12f98;
                        pcVar4 = (char *)(DAT_00013624 + 0x12fa0);
                        iVar2 = DAT_00013628 + 0x13025;
                        fprintf((FILE *)*puVar16,pcVar4,iVar3,0x413,iVar3,iVar2,0x413,iVar18);
                        fprintf((FILE *)*puVar16,pcVar4,iVar3,0x414,iVar3,iVar2,0x414,&local_484);
                        iVar2 = strcmp((char *)&local_484,(char *)(DAT_0001362c + 0x12ff4));
                        if (iVar2 == 0) {
                          *(undefined4 *)(DAT_00013630 + 0x131d8) = 1;
                        }
                        else {
                          iVar2 = strcmp((char *)&local_484,(char *)(DAT_00013634 + 0x13020));
                          if (iVar2 == 0) {
                            *(undefined4 *)(DAT_00013638 + 0x131fc) = 0;
                          }
                        }
                      }
                      else {
                        iVar2 = FUN_00013844(uVar13,DAT_0001363c + 0x1304c,&local_484,0x20);
                        if (iVar2 == 0) {
                          iVar18 = DAT_00013640 + 0x13064;
                          pcVar4 = (char *)(DAT_00013648 + 0x13074);
                          iVar2 = DAT_00013644 + 0x130e9;
                          fprintf((FILE *)*puVar16,pcVar4,iVar18,0x41b,iVar18,iVar2,0x41b,
                                  DAT_0001364c + 0x1307c);
                          fprintf((FILE *)*puVar16,pcVar4,iVar18,0x41c,iVar18,iVar2,0x41c,&local_484
                                 );
                          iVar2 = strcmp((char *)&local_484,(char *)(DAT_00013650 + 0x130d0));
                          if (iVar2 == 0) {
                            *(undefined4 *)(DAT_00013654 + 0x132ac) = 1;
                          }
                          else {
                            *(undefined4 *)(DAT_00013658 + 0x132bc) = 0;
                          }
                        }
                        else {
                          fprintf((FILE *)*puVar16,(char *)(DAT_00013668 + 0x13130),
                                  DAT_00013660 + 0x13120,0x424,DAT_00013660 + 0x13120,
                                  DAT_0001365c + 0x13185,0x424,DAT_00013664 + 0x13124);
                        }
                      }
                    }
                  }
                }
              }
              iVar2 = FUN_00013844(uVar13,DAT_00011bd8 + 0x12460,&local_484,0x20);
              if (iVar2 == 0) {
                fprintf((FILE *)*puVar16,(char *)(DAT_00011be4 + 0x1249c),DAT_00011be0 + 0x12490,
                        0x42c,DAT_00011be0 + 0x12490,DAT_00011bdc + 0x124f5,0x42c,&local_484);
                iVar2 = strcmp((char *)&local_484,(char *)(DAT_00011be8 + 0x124b0));
                if (iVar2 == 0) {
                  *(undefined4 *)(DAT_00011bec + 0x12700) = 0;
                }
                else {
                  iVar2 = strcmp((char *)&local_484,(char *)(DAT_0001366c + 0x13150));
                  if (iVar2 == 0) {
                    uVar21 = 1;
                    iVar2 = DAT_00013670 + 0x13168;
                  }
                  else {
                    uVar21 = 2;
                    iVar2 = DAT_00013674 + 0x1317c;
                  }
                  *(undefined4 *)(iVar2 + 0x23c) = uVar21;
                }
              }
              iVar2 = FUN_00013844(uVar13,DAT_00011bf0 + 0x124dc,&local_484,0x40);
              if (iVar2 == 0) {
                if ((char)local_484 == '\0') {
                  iVar2 = DAT_00013678 + 0x13205;
                  iVar3 = DAT_00013680 + 0x131a0;
                  iVar18 = DAT_0001367c + 0x131a4;
                  pcVar4 = (char *)(DAT_00013684 + 0x131ac);
                  uVar21 = 0x448;
                  uVar22 = 0x448;
                }
                else {
                  strcpy((char *)(DAT_00011bf4 + 0x12740),(char *)&local_484);
                  iVar2 = DAT_00011bf8 + 0x1258d;
                  iVar3 = DAT_00011c00 + 0x12528;
                  iVar18 = DAT_00011bfc + 0x1252c;
                  pcVar4 = (char *)(DAT_00011c04 + 0x12534);
                  uVar21 = 0x446;
                  uVar22 = 0x446;
                }
                fprintf((FILE *)*puVar16,pcVar4,iVar18,uVar21,iVar18,iVar2,uVar22,iVar3);
              }
              iVar2 = FUN_00013844(uVar13,DAT_00011c08 + 0x1255c,&local_484,0x40);
              if (iVar2 == 0) {
                if ((char)local_484 == '\0') {
                  iVar2 = DAT_00013688 + 0x13241;
                  iVar3 = DAT_00013690 + 0x131dc;
                  iVar18 = DAT_0001368c + 0x131e0;
                  pcVar4 = (char *)(DAT_00013694 + 0x131e8);
                  uVar21 = 0x450;
                  uVar22 = 0x450;
                }
                else {
                  snprintf((char *)(DAT_00011c0c + 0x12808),0x3f,(char *)(DAT_00011c10 + 0x1258c),
                           &local_484);
                  iVar2 = DAT_00011c14 + 0x12619;
                  iVar3 = DAT_00011c1c + 0x125b4;
                  iVar18 = DAT_00011c18 + 0x125b8;
                  pcVar4 = (char *)(DAT_00011c20 + 0x125c0);
                  uVar21 = 0x44e;
                  uVar22 = 0x44e;
                }
                fprintf((FILE *)*puVar16,pcVar4,iVar18,uVar21,iVar18,iVar2,uVar22,iVar3);
              }
              iVar2 = FUN_00013844(uVar13,DAT_00011c24 + 0x125e8,&local_484,0x20);
              if (iVar2 == 0) {
                fprintf((FILE *)*puVar16,(char *)(DAT_00011c34 + 0x12628),DAT_00011c2c + 0x12618,
                        0x455,DAT_00011c2c + 0x12618,DAT_00011c28 + 0x12679,0x455,
                        DAT_00011c30 + 0x12614);
              }
              iVar2 = FUN_00013844(uVar13,DAT_00011c38 + 0x12648,&local_484,0x20);
              if (iVar2 == 0) {
                fprintf((FILE *)*puVar16,(char *)(DAT_00011c44 + 0x12684),DAT_00011c40 + 0x12678,
                        0x464,DAT_00011c40 + 0x12678,DAT_00011c3c + 0x126dd,0x464,&local_484);
                iVar2 = atoi((char *)&local_484);
                if (iVar2 < 1) {
                  *(undefined4 *)(DAT_00013698 + 0x134c4) = 0;
                }
                else {
                  *(int *)(DAT_00011c48 + 0x12968) = iVar2;
                }
              }
              iVar2 = FUN_00013844(uVar13,DAT_00011c4c + 0x126bc,&local_484,0x20);
              if (iVar2 == 0) {
                fprintf((FILE *)*puVar16,(char *)(DAT_00011c58 + 0x126f8),DAT_00011c54 + 0x126ec,
                        0x471,DAT_00011c54 + 0x126ec,DAT_00011c50 + 0x12751,0x471,&local_484);
                iVar2 = atoi((char *)&local_484);
                if (iVar2 < 1) {
                  *(undefined4 *)(DAT_0001369c + 0x134d8) = 0;
                }
                else {
                  *(int *)(DAT_00011c5c + 0x129e0) = iVar2;
                }
              }
              iVar2 = strcmp(local_4a4,(char *)(DAT_00011c60 + 0x12728));
              puVar14 = *(undefined4 **)(iVar12 + DAT_00011c64);
              if (iVar2 == 0) {
                local_484 = iVar2;
                memset(auStack_480,0,0x3c);
                local_420 = iVar2;
                memset(auStack_41c,0,0x3c);
                iVar2 = DAT_00011c78;
                fprintf((FILE *)*puVar14,(char *)(DAT_00011c74 + 0x127a4),DAT_00011c6c + 0x1277c,
                        0x152,DAT_00011c6c + 0x1277c,DAT_00011c68 + 0x12805,0x152,
                        DAT_00011c70 + 0x12788);
                strcpy((char *)(iVar2 + 0x129b0),local_4a4);
                pFVar5 = popen((char *)(DAT_00011c80 + 0x127cc),(char *)(DAT_00011c7c + 0x127c8));
                if (pFVar5 != (FILE *)0x0) {
                  pcVar4 = fgets((char *)&local_484,0x40,pFVar5);
                  if (pcVar4 != (char *)0x0) {
                    iVar18 = strcmp((char *)&local_484,(char *)(DAT_00011c84 + 0x127fc));
                    if (iVar18 == 0) {
                      *(undefined4 *)(iVar2 + 0x12b08) = 0;
                    }
                    else {
                      iVar18 = strcmp((char *)&local_484,(char *)(DAT_00011c88 + 0x12818));
                      if (iVar18 == 0) {
                        uVar13 = 1;
                      }
                      else {
                        uVar13 = 2;
                      }
                      *(undefined4 *)(iVar2 + 0x12b08) = uVar13;
                    }
                  }
                  pclose(pFVar5);
                }
                memset(&local_484,0,0x40);
                pFVar5 = popen((char *)(DAT_00011c90 + 0x12854),(char *)(DAT_00011c8c + 0x12850));
                if (pFVar5 != (FILE *)0x0) {
                  pcVar4 = fgets((char *)&local_484,0x40,pFVar5);
                  if (pcVar4 != (char *)0x0) {
                    strncpy((char *)(DAT_00011c94 + 0x12be0),(char *)&local_484,0x40);
                  }
                  pclose(pFVar5);
                }
                memset(&local_484,0,0x40);
                memset(&local_420,0,0x40);
                if (*(int *)(DAT_00011c98 + 0x12c18) == 0) {
                  iVar2 = DAT_00011c9c + 0x128dc;
                  pcVar4 = (char *)(DAT_00011ca0 + 76000);
                }
                else if (*(int *)(DAT_00011c98 + 0x12c18) == 1) {
                  iVar2 = DAT_000136a0 + 0x1322c;
                  pcVar4 = (char *)(DAT_000136a4 + 0x13230);
                }
                else {
                  iVar2 = DAT_000136a8 + 0x13240;
                  pcVar4 = (char *)(DAT_000136ac + 0x13244);
                }
                snprintf((char *)&local_420,0x40,pcVar4,iVar2);
                pFVar5 = popen((char *)&local_420,(char *)(DAT_00011ca4 + 0x128f8));
                if (pFVar5 != (FILE *)0x0) {
                  pcVar4 = fgets((char *)&local_484,0x40,pFVar5);
                  if (pcVar4 != (char *)0x0) {
                    strncpy((char *)(DAT_00011ca8 + 0x12cc4),(char *)&local_484,0x40);
                  }
                  pclose(pFVar5);
                }
                memset(&local_484,0,0x40);
                pFVar5 = popen((char *)(DAT_00011cb0 + 0x1295c),(char *)(DAT_00011cac + 0x12958));
                if (pFVar5 != (FILE *)0x0) {
                  pcVar4 = fgets((char *)&local_484,0x40,pFVar5);
                  if (pcVar4 != (char *)0x0) {
                    iVar2 = atoi((char *)&local_484);
                    if (iVar2 < 1) {
                      *(undefined4 *)((int)&DAT_00013630 + DAT_000136b0) = 0;
                    }
                    else {
                      *(int *)(DAT_00011cb4 + 0x12d74) = iVar2;
                    }
                  }
                  pclose(pFVar5);
                }
                memset(&local_484,0,0x40);
                pFVar5 = popen((char *)(DAT_00011cbc + 0x129c4),(char *)(DAT_00011cb8 + 0x129c0));
                if (pFVar5 != (FILE *)0x0) {
                  pcVar4 = fgets((char *)&local_484,0x40,pFVar5);
                  if (pcVar4 != (char *)0x0) {
                    iVar2 = atoi((char *)&local_484);
                    if (iVar2 < 1) {
                      *(undefined4 *)((int)&DAT_00013648 + DAT_000136b4) = 0;
                    }
                    else {
                      *(int *)(DAT_00011cc0 + 0x12de0) = iVar2;
                    }
                  }
                  pclose(pFVar5);
                }
              }
              else {
                iVar2 = strcmp(local_4a4,(char *)(DAT_000136b8 + 0x1327c));
                if (iVar2 == 0) {
                  iVar12 = DAT_000136bc + 0x1329c;
                  pcVar4 = (char *)(DAT_000136c0 + 0x132a0);
                  iVar3 = DAT_000136c4 + 0x1333a;
                  fprintf((FILE *)*puVar14,pcVar4,iVar12,0x1b6,iVar12,DAT_000136c4 + 0x13335,0x1b6);
                  iVar2 = DAT_000136c8;
                  strcpy((char *)(DAT_000136c8 + 0x134d0),local_4a4);
                  iVar18 = access((char *)(DAT_000136cc + 0x132ec),0);
                  *(uint *)((int)&DAT_00013624 + iVar2) = (uint)(iVar18 == 0);
                  fprintf((FILE *)*puVar14,pcVar4,iVar12,0x35a,iVar12,iVar3,0x35a);
                }
                else {
                  iVar2 = strcmp(local_4a4,(char *)(DAT_000136d0 + 0x13328));
                  if ((((iVar2 == 0) ||
                       (iVar2 = strcmp(local_4a4,(char *)(DAT_000136d4 + 0x13340)), iVar2 == 0)) ||
                      (iVar2 = strcmp(local_4a4,(char *)(DAT_000136d8 + 0x13358)), iVar2 == 0)) ||
                     (iVar2 = strcmp(local_4a4,(char *)(DAT_000136dc + 0x13370)), iVar2 == 0)) {
                    fprintf((FILE *)*puVar14,(char *)(DAT_000136e8 + 0x133a8),DAT_000136e4 + 0x133a0
                            ,0x1c6,DAT_000136e4 + 0x133a0,DAT_000136e0 + 0x13419,0x1c6);
                    strcpy((char *)(DAT_000136ec + 0x135b8),local_4a4);
                  }
                  else {
                    iVar2 = strcmp(local_4a4,(char *)(DAT_000136f0 + 0x133d4));
                    if (iVar2 == 0) {
                      iVar2 = DAT_000136f4 + 0x133e8;
                      FUN_0001472c(iVar2);
                      FUN_000147c0(iVar2);
                      fprintf((FILE *)*puVar14,(char *)(DAT_000136fc + 0x13410),
                              DAT_000136f8 + 0x1340c,0x1cd);
                      return 0;
                    }
                  }
                }
              }
            }
            iVar2 = DAT_00011cc4 + 0x12a20;
            pcVar4 = (char *)(DAT_00011cc8 + 0x12a24);
            iVar12 = DAT_00011ccc + 0x12ab9;
            iVar18 = DAT_00011ccc + 0x12ad2;
            fprintf((FILE *)*puVar16,pcVar4,iVar2,0x1d2,iVar2,iVar12,0x1d2);
            fprintf((FILE *)*puVar16,pcVar4,iVar2,0x1d4,iVar2,iVar12,0x1d4);
            pcVar6 = (char *)(DAT_00011cd0 + 0x12a7c);
            fprintf((FILE *)*puVar16,pcVar4,iVar2,0x343,iVar2,iVar18,0x343);
            iVar18 = access(pcVar6,0);
            iVar2 = DAT_00013700;
            if (iVar18 == 0) {
              iVar2 = DAT_00011cd4 + 0x12c5c;
              iVar18 = DAT_00011cd8 + 0x12ab0;
            }
            else {
              FUN_000139e4(pcVar6,(int)&DAT_000136f0 + DAT_00013700);
              iVar2 = (int)&DAT_000135d8 + iVar2;
              iVar18 = DAT_00013704 + 0x13438;
            }
            iVar12 = DAT_00011cdc;
            FUN_000139e4(iVar18,iVar2);
            iVar18 = access((char *)(iVar12 + 0x12ac0),0);
            iVar2 = DAT_00013708;
            if (iVar18 == 0) {
              iVar2 = DAT_00011ce0 + 0x12cb0;
              iVar18 = DAT_00011ce4 + 0x12ae4;
            }
            else {
              FUN_000143c4((char *)(iVar12 + 0x12ac0),(int)&DAT_00013734 + DAT_00013708);
              iVar2 = (int)&DAT_0001361c + iVar2;
              iVar18 = DAT_0001370c + 0x1345c;
            }
            iVar12 = DAT_00011ce8;
            FUN_000143c4(iVar18,iVar2);
            iVar12 = iVar12 + 0x12afc;
            pcVar4 = (char *)(DAT_00011cec + 0x12b00);
            iVar2 = DAT_00011cf0 + 0x12bbe;
            fprintf((FILE *)*puVar16,pcVar4,iVar12,0x1d6,iVar12,DAT_00011cf0 + 0x12b95,0x1d6);
            fprintf((FILE *)*puVar16,pcVar4,iVar12,0x266,iVar12,iVar2,0x266);
            _Var11 = fork();
            if (_Var11 == 0) {
              fprintf((FILE *)*puVar16,(char *)(DAT_00011cf4 + 0x12b68),iVar12,0x26b,iVar12,iVar2,
                      0x26b);
              close(1);
              iVar2 = open((char *)(DAT_00011cf8 + 0x12b8c),2);
              dup2(iVar2,1);
              system((char *)(DAT_00011cfc + 0x12ba0));
              FUN_000144e0(DAT_00011d00 + 0x12bac);
              FUN_000144e0(DAT_00011d04 + 0x12bb8);
            }
            else if (0 < _Var11) {
              wait((void *)0x0);
            }
            fprintf((FILE *)*puVar16,(char *)(DAT_00011d10 + 0x12be8),DAT_00011d0c + 0x12be0,0x1d8,
                    DAT_00011d0c + 0x12be0,DAT_00011d08 + 0x12c59,0x1d8);
            if (*(int *)(DAT_00011d14 + 0x12e28) == 1) {
              FUN_00014668();
            }
            else {
              FUN_000145d4();
            }
            iVar18 = DAT_00011d1c + 0x12c2c;
            fprintf((FILE *)*puVar16,(char *)(DAT_00011d20 + 0x12c34),iVar18,0x1e0,iVar18,
                    DAT_00011d18 + 0x12ca5,0x1e0);
            goto LAB_00012c38;
          }
          iVar2 = DAT_00013714 + 0x13541;
          iVar3 = DAT_0001371c + 0x134c8;
          iVar12 = DAT_00013718 + 0x134cc;
          pcVar4 = (char *)(DAT_00013720 + 0x134d4);
          uVar13 = 0x1ee;
          uVar21 = 0x1ee;
        }
        else {
          if ((iVar3 == 1) &&
             (iVar2 = strcmp((char *)(DAT_00011aec + 0x11ea4),(char *)(DAT_00013710 + 0x1348c)),
             iVar2 == 0)) {
            FUN_0001472c(piVar17);
            FUN_000148a4();
            goto LAB_00012c38;
          }
          iVar2 = DAT_0001373c + 0x13601;
          iVar3 = DAT_00013744 + 0x13588;
          iVar12 = DAT_00013740 + 0x1358c;
          pcVar4 = (char *)(DAT_00013748 + 0x13594);
          uVar13 = 0x1f0;
          uVar21 = 0x1f0;
        }
        iVar15 = DAT_00013728;
        iVar18 = DAT_00013724;
        fprintf((FILE *)*puVar16,pcVar4,iVar12,uVar13,iVar12,iVar2,uVar21,iVar3);
        iVar18 = iVar18 + 0x134f4;
        pcVar6 = (char *)(DAT_00013730 + 0x13520);
        fprintf((FILE *)*puVar16,(char *)(DAT_0001372c + 0x13504),iVar18,0x1f1,iVar18,
                iVar15 + 0x13589,0x1f1);
        pcVar4 = strstr((char *)(DAT_00013734 + 0x1353c),pcVar6);
        if (pcVar4 == (char *)0x0) {
          pcVar6 = (char *)(DAT_0001374c + 0x135b4);
          pcVar4 = (char *)(DAT_00013750 + 0x135c0);
          uVar13 = 0x1f5;
          uVar21 = 0x1f5;
        }
        else {
          uVar13 = 499;
          pcVar4 = (char *)(DAT_00013738 + 0x13554);
          uVar21 = 499;
        }
        fprintf((FILE *)*puVar16,pcVar4,iVar18,uVar13,iVar18,iVar15 + 0x13589,uVar21,pcVar6);
LAB_00012c38:
        fprintf((FILE *)*puVar16,(char *)(DAT_00011d28 + 0x12c58),DAT_00011d24 + 0x12c54,0x1f7,
                iVar18);
        return 0;
      }
      uVar13 = 0xe5;
      iVar18 = DAT_00011a8c + 0x118b8;
      pcVar4 = (char *)(DAT_00011a90 + 0x118bc);
    }
LAB_00011458:
    pFVar5 = (FILE *)*puVar16;
  }
  else {
    pcVar4 = getenv((char *)(DAT_00011a30 + 0x1163c));
    if (pcVar4 == (char *)0x0) {
      fprintf((FILE *)*puVar16,(char *)(DAT_00011a38 + 0x11660),DAT_00011a34 + 0x1165c,0x86);
      if (*(void **)(iVar2 + 0x11624) != (void *)0x0) {
        free(*(void **)(iVar2 + 0x11624));
      }
      if (*(void **)(DAT_00011a3c + 0x11680) != (void *)0x0) {
        free(*(void **)(DAT_00011a3c + 0x11680));
      }
      if (*(void **)(DAT_00011a40 + 0x11704) != (void *)0x0) {
        free(*(void **)(DAT_00011a40 + 0x11704));
      }
      uVar13 = 0x19b;
      goto LAB_00011558;
    }
    uVar9 = strtoul(pcVar4,(char **)0x0,10);
    *(ulong *)(iVar2 + 0x117cc) = uVar9;
    pcVar4 = getenv((char *)(DAT_00011a54 + 0x11728));
    if (((pcVar4 == (char *)0x0) ||
        (pcVar6 = strcasestr(pcVar4,(char *)(DAT_00011a58 + 0x1173c)), pcVar6 == (char *)0x0)) ||
       (pcVar4 = strcasestr(pcVar4,(char *)(DAT_00011a5c + 0x11754)), pcVar4 == (char *)0x0)) {
LAB_000117b4:
      iVar2 = DAT_00011a68;
      uVar19 = *(uint *)(DAT_00011a68 + 0x1196c);
      if ((uVar19 < 0x1001) && (*(int *)(DAT_00011a68 + 0x11834) == 0)) {
        pvVar8 = malloc(uVar19 + 1);
        *(void **)(iVar2 + 0x117c8) = pvVar8;
        if (pvVar8 == (void *)0x0) {
          uVar13 = 0xa2;
          iVar18 = DAT_00011a6c + 0x11804;
          pcVar4 = (char *)(DAT_00011a70 + 0x11808);
          goto LAB_00011458;
        }
        memset(pvVar8,0,uVar19 + 1);
        if (uVar19 != 0) {
          fread(pvVar8,uVar19,1,(FILE *)**(undefined4 **)(iVar12 + DAT_00011a7c));
        }
      }
      else if (*(char *)(DAT_00011a94 + 0x119aa) != '\0') {
        if (*(int *)(DAT_00011a94 + 0x1193c) == 0) {
          pcVar4 = (char *)(DAT_00011aa4 + 0x11970);
        }
        else {
          pcVar4 = (char *)(DAT_00011a98 + 0x118ec);
        }
        strcpy((char *)&local_484,pcVar4);
        pFVar5 = fopen((char *)&local_484,(char *)(DAT_00011a9c + 0x11900));
        if (pFVar5 != (FILE *)0x0) {
          for (uVar19 = *(uint *)((int)&DAT_00011ac4 + DAT_00011aa0); uVar19 != 0;
              uVar19 = uVar19 - 0x400) {
            if (uVar19 < 0x401) {
              fread(&local_420,uVar19,1,(FILE *)**(undefined4 **)(iVar12 + DAT_00011a7c));
              fwrite(&local_420,uVar19,1,pFVar5);
              break;
            }
            fread(&local_420,0x400,1,(FILE *)**(undefined4 **)(iVar12 + DAT_00011a7c));
            fwrite(&local_420,0x400,1,pFVar5);
          }
          fclose(pFVar5);
          strcpy((char *)((int)&DAT_00011aec + DAT_00011aa8 + 3),(char *)&local_484);
        }
      }
      goto LAB_00011860;
    }
    sVar7 = strlen(pcVar4);
    pvVar8 = malloc(sVar7 + 1);
    *(void **)(iVar2 + 0x11694) = pvVar8;
    pFVar5 = (FILE *)*puVar16;
    if (pvVar8 != (void *)0x0) {
      memcpy(pvVar8,pcVar4 + 9,sVar7);
      iVar2 = DAT_00011a64;
      iVar18 = DAT_00011a60 + 0x117a0;
      *(undefined1 *)((int)pvVar8 + sVar7) = 0;
      fprintf(pFVar5,(char *)(iVar2 + 0x117a8),iVar18,0x9b,pvVar8);
      goto LAB_000117b4;
    }
    uVar13 = 0x98;
    iVar18 = DAT_00011a74 + 0x11820;
    pcVar4 = (char *)(DAT_00011a78 + 0x11824);
  }
  fprintf(pFVar5,pcVar4,iVar18,uVar13);
  uVar13 = 500;
LAB_00011558:
  fprintf((FILE *)*puVar16,(char *)(DAT_00011a1c + 0x11574),DAT_00011a18 + 0x1156c,299,uVar13);
  return 0xffffffff;
}



===== FUN_000147c0 @ 000147c0 =====

void FUN_000147c0(void)

{
  undefined4 in_r3;
  
  fprintf((FILE *)**(undefined4 **)(DAT_00014870 + 0x147d4 + DAT_00014874),
          (char *)(DAT_00014880 + 0x14808),DAT_00014878 + 0x147e0,0x4bc,DAT_00014878 + 0x147e0,
          DAT_0001487c + 0x14851,0x4bc,in_r3);
  printf((char *)(DAT_00014884 + 0x14814));
  printf((char *)(DAT_00014888 + 84000));
  printf((char *)(DAT_0001488c + 0x1482c));
  printf((char *)(DAT_00014890 + 0x14838));
  printf((char *)(DAT_00014894 + 0x14844));
  printf((char *)(DAT_00014898 + 0x14850));
  printf((char *)(DAT_0001489c + 0x1485c));
  printf((char *)(DAT_000148a0 + 0x14868));
  return;
}



===== entry @ 00013754 =====

void processEntry entry(undefined4 param_1,undefined4 param_2)

{
  __libc_start_main(DAT_00013788,param_2,&stack0x00000004,DAT_0001378c,DAT_00013784,param_1);
                    /* WARNING: Subroutine does not return */
  abort();
}


