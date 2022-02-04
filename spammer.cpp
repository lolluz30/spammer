#include <windows.h>
#include <winable.h>
#include <cstdio>
#include <iostream>
#include <conio.h>
#include <stdio.h>

unsigned int GeneraKbInput(int tasto)

{
        KEYBDINPUT kb_input = {0};
        INPUT g_input = {0};
        unsigned int err=0;

        //Tasto premuto
        kb_input.wVk = tasto;
        g_input.type = INPUT_KEYBOARD  ; //0x00000001
        g_input.ki = kb_input;
        err = SendInput(1,&g_input,sizeof(g_input));
        if (!err)
            return 0;

        //reset
        ZeroMemory(&kb_input, sizeof(KEYBDINPUT));
        ZeroMemory(&g_input, sizeof(INPUT));

        //tasto rilasciato
        kb_input.wVk = tasto;
        kb_input.dwFlags = KEYEVENTF_KEYUP; //equivale a 0x2;
        g_input.type = INPUT_KEYBOARD  ; //0x00000001
        g_input.ki = kb_input;
        err = SendInput(1,&g_input,sizeof(g_input));
        if (!err)
            return 0;
        return 1;
}

int main()
// INIZIO DEGLI INPUT if(!GeneraKbInput(0x5b)); //tasto WINDOWS if(!GeneraKbInput(0x0D)); //tasto ENTER if(!GeneraKbInput(0x20)); //tasto SPACE if(!GeneraKbInput(0xBE)); // tasto " . "    Sleep (500);
{
    Sleep (100);
  int n;
  int i;
printf("dopo aver inserito i numeri, cambia subito la finestra su dove vuoi spammare\n\n");
printf("quanti numeri vuoi spammare:");
    scanf("%d", &n);
        for(i=0;i<n;i++){
	if(!GeneraKbInput('A'));
	if(!GeneraKbInput(0x0D));
	Sleep (100);
	}
    return 0;
}
