/* Minimal EX2800 message-bus shim for isolated mini_httpd testing.
 *
 * The real firmware registers each process with a system-wide configuration
 * daemon over /var/pid sockets. That daemon is unavailable in user-mode
 * emulation. These stubs keep request parsing and HTTP route handling in the
 * original binary while replacing only the missing inter-process bus.
 */

int MSG_RegModule(void) { return 0; }
int MSG_UnregModule(void) { return 0; }
int MSG_AllModStartOK(void) { return 1; }
int MSG_SendMessage(void) { return 0; }
int MSG_ReceiveMessage(void) { return -1; }
int MSG_CreateMessage(void) { return 0; }
int MSG_ReleaseMessage(void) { return 0; }
