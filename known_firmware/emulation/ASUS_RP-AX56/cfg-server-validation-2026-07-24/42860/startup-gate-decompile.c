STRING 0008a2c1 [%s(%d)]:not support CAP

REF 00014858 owner=FUN_0001480c
REF 000148a4 owner=FUN_0001480c
STRING 0008a2db [%s(%d)]:auth check failed, exit

REF 000148ec owner=FUN_0001480c
REF 00014938 owner=FUN_0001480c
STRING 0008a2fd [%s(%d)]:auth check success

REF 0001497c owner=FUN_0001480c
REF 000149cc owner=FUN_0001480c
CALLER_REF target=FUN_0001480c from=_elfSectionHeaders::000001ec owner=NONE
CALLER_REF target=FUN_0001480c from=00014b18 owner=entry

===== FUN_0001480c @ 0001480c =====

undefined4 FUN_0001480c(void)

{
  uint uVar1;
  char *pcVar2;
  __pid_t _Var3;
  int iVar4;
  int iVar5;
  void *__s;
  int iVar6;
  pthread_attr_t *__attr;
  undefined4 uVar7;
  
  uVar1 = getAmasSupportMode();
  iVar6 = DAT_00014a74 + 0x14824;
  if ((uVar1 & 1) == 0) {
    pcVar2 = (char *)FUN_00049808(DAT_00014a78 + 0x14834);
    iVar6 = strcmp(pcVar2,(char *)(DAT_00014a7c + 0x14840));
    if (iVar6 == 0) {
      cprintf(DAT_00014a84 + 0x14860,DAT_00014a80 + 0x1485c,0x363b);
    }
    pcVar2 = (char *)FUN_00049808(DAT_00014a88 + 0x1486c);
    iVar6 = strcmp(pcVar2,(char *)(DAT_00014a8c + 0x14878));
    if (iVar6 == 0) {
      uVar7 = 0x363b;
      iVar4 = DAT_00014a90 + 0x14898;
      iVar6 = DAT_00014a94 + 0x148a4;
      iVar5 = DAT_00014a98 + 0x148a8;
LAB_00014940:
      asusdebuglog(6,iVar6,0,1,0,iVar5,iVar4,uVar7);
    }
  }
  else {
    iVar4 = FUN_0001bc48();
    if (iVar4 == 0) {
      pcVar2 = (char *)FUN_00049808(DAT_00014a9c + 0x148c8);
      iVar6 = strcmp(pcVar2,(char *)(DAT_00014aa0 + 0x148d4));
      if (iVar6 == 0) {
        cprintf(DAT_00014aa8 + 0x148f4,DAT_00014aa4 + 0x148f0,0x3645);
      }
      pcVar2 = (char *)FUN_00049808(DAT_00014aac + 0x14900);
      iVar6 = strcmp(pcVar2,(char *)(DAT_00014ab0 + 0x1490c));
      if (iVar6 == 0) {
        uVar7 = 0x3645;
        iVar4 = DAT_00014ab4 + 0x1492c;
        iVar6 = DAT_00014ab8 + 0x14938;
        iVar5 = DAT_00014abc + 0x1493c;
        goto LAB_00014940;
      }
    }
    else {
      pcVar2 = (char *)FUN_00049808(DAT_00014ac0 + 0x14958);
      iVar4 = strcmp(pcVar2,(char *)(DAT_00014ac4 + 0x14964));
      if (iVar4 == 0) {
        cprintf(DAT_00014acc + 0x14984,DAT_00014ac8 + 0x14980,0x3649);
      }
      pcVar2 = (char *)FUN_00049808(DAT_00014ad0 + 0x14990);
      iVar4 = strcmp(pcVar2,(char *)(DAT_00014ad4 + 0x1499c));
      if (iVar4 == 0) {
        asusdebuglog(6,DAT_00014adc + 0x149cc,0,1,0,DAT_00014ae0 + 0x149d0,DAT_00014ad8 + 0x149c0,
                     0x3649);
      }
      __s = *(void **)(iVar6 + DAT_00014ae4);
      memset(__s,0,0x8c);
      kill_pidfile_s(DAT_00014ae8 + 0x14a04,0xf);
      sleep(1);
      _Var3 = fork();
      if (-1 < _Var3) {
        if (_Var3 == 0) {
          __attr = *(pthread_attr_t **)(iVar6 + DAT_00014aec);
          **(undefined4 **)(iVar6 + DAT_00014af0) = __attr;
          pthread_attr_init(__attr);
          pthread_attr_setstacksize(__attr,0x40000);
          FUN_0007b8b4(__s);
          puts((char *)(DAT_00014af4 + 0x14a68));
          return 0;
        }
        iVar6 = 0;
        goto LAB_00014a28;
      }
    }
  }
  iVar6 = -1;
LAB_00014a28:
                    /* WARNING: Subroutine does not return */
  exit(iVar6);
}



===== entry @ 00014af8 =====

void processEntry entry(undefined4 param_1,undefined4 param_2)

{
  __libc_start_main(DAT_00014b2c,param_2,&stack0x00000004,DAT_00014b30,DAT_00014b28,param_1);
                    /* WARNING: Subroutine does not return */
  abort();
}


