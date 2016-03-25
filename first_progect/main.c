#include <windows.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
//#include "port.h"

int main()
{
    setlocale(LC_ALL,"rus");
    HANDLE Port = CreateFile("\\\\.\\COM3", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    DWORD numbytes, numbytes_ok;
    char command;
    char com[10];

    numbytes = sizeof(command);
    //BOOL SetupComm(Port, DWORD dwInQueue, DWORD dwOutQueue);
    COMMTIMEOUTS CommTimeOuts;

    CommTimeOuts.ReadIntervalTimeout = 5;
    CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
    CommTimeOuts.ReadTotalTimeoutConstant = 0;
    CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
    CommTimeOuts.WriteTotalTimeoutConstant = 0;

    SetCommTimeouts(Port, &CommTimeOuts);

    //CommTimeOuts.ReadIntervalTimeout= 10;
    //CommTimeOuts.ReadTotalTimeoutMultiplier = 1;
    // �������� ���� ���� � ����� ������ ������� ��� ���������� ������
    // ���� �� �������� 110 ���
    //CommTimeOuts.ReadTotalTimeoutConstant = 100;
    // ������������ � ������ ������ ��� ����� �������� �������
    //CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
    //CommTimeOuts.WriteTotalTimeoutConstant = 0;
    //SetCommTimeouts(handle, &CommTimeOuts);

    if (Port != INVALID_HANDLE_VALUE)
    {
        while(1)
        {
                command = getch();

                com[0] = command;
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }



    }
    else
    {
        MessageBox(NULL, "        ���������� ������� ���������������� ����", "Error", MB_OK);
        ExitProcess(1);
    }

    PurgeComm(Port, PURGE_RXCLEAR);
    PurgeComm(Port, PURGE_TXCLEAR);

    CloseHandle(Port);

    return EXIT_SUCCESS;
}
