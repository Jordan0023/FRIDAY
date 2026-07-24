
===== ADDRESS 00010da8 FUNCTION NONE =====

===== ADDRESS 00010df4 FUNCTION NONE =====

===== ADDRESS 00011eec FUNCTION FUN_00011dd4 =====

undefined4 FUN_00011dd4(char *param_1,char *param_2,uint param_3,char *param_4)

{
  __sighandler_t __handler;
  __sighandler_t __handler_00;
  __sighandler_t __handler_01;
  __pid_t _Var1;
  int iVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  undefined4 local_1a8;
  char *local_1a0 [100];
  
  iVar5 = DAT_00012084 + 0x11df8;
  __handler = signal(3,(__sighandler_t)0x1);
  __handler_00 = signal(2,(__sighandler_t)0x1);
  __handler_01 = signal(0x11,(__sighandler_t)0x0);
  _Var1 = vfork();
  if (_Var1 < 0) {
    signal(3,__handler);
    signal(2,__handler_00);
    signal(0x11,__handler_01);
    return 0xffffffff;
  }
  if (_Var1 != 0) {
    signal(3,(__sighandler_t)0x1);
    signal(2,(__sighandler_t)0x1);
    _Var1 = wait4(_Var1,&local_1a8,0,(rusage *)0x0);
    if (_Var1 == -1) {
      local_1a8 = 0xffffffff;
    }
    signal(3,__handler);
    signal(2,__handler_00);
    signal(0x11,__handler_01);
    return local_1a8;
  }
  memset(local_1a0,0,400);
  signal(3,(__sighandler_t)0x0);
  signal(2,(__sighandler_t)0x0);
  signal(0x11,(__sighandler_t)0x0);
  iVar2 = 0;
  piVar3 = (int *)register0x00000054;
  while( true ) {
    local_1a0[0] = param_4;
    if ((char *)*piVar3 == (char *)0x0) break;
    iVar2 = iVar2 + 1;
    if (iVar2 == 100) {
      puts((char *)(DAT_0001208c + 0x11f18));
      break;
    }
    local_1a0[iVar2] = (char *)*piVar3;
    piVar3 = piVar3 + 1;
  }
  if (param_1 == (char *)0x0) {
LAB_00011ecc:
    if (param_2 != (char *)0x0) {
      if ((param_3 & 2) == 0) {
        unlink(param_2);
      }
      iVar2 = open(param_2,(param_3 & 2) << 9 | 0x41,0x1b6);
      if (iVar2 < 0) {
        piVar3 = __errno_location();
        pcVar4 = strerror(*piVar3);
        iVar5 = DAT_00012094 + 0x12000;
        goto LAB_00011f70;
      }
      if ((param_3 & 3) != 0) {
        dup2(iVar2,2);
      }
      close(iVar2);
    }
    execve(param_4,local_1a0,(char **)**(undefined4 **)(iVar5 + DAT_00012088));
  }
  else {
    if ((param_3 & 2) == 0) {
      unlink(param_1);
    }
    iVar2 = open(param_1,(param_3 & 2) << 9 | 0x41,0x1b6);
    if (-1 < iVar2) {
      dup2(iVar2,1);
      if ((param_3 & 1) != 0) {
        dup2(iVar2,2);
      }
      close(iVar2);
      goto LAB_00011ecc;
    }
    piVar3 = __errno_location();
    pcVar4 = strerror(*piVar3);
    iVar5 = DAT_00012090 + 0x11f70;
LAB_00011f70:
    __printf_chk(1,iVar5,param_1,pcVar4);
  }
                    /* WARNING: Subroutine does not return */
  _exit(0x7f);
}

