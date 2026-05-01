char __fastcall LB::GetShareMyLobyyList(__int64 a1)
{
  char **v2; // rax
  __int64 v3; // r9
  int v4; // er13
  __int64 *v5; // rax
  int v6; // eax
  char *lpResponse; // rdi
  char v8; // al
  int v9; // esi
  char *v10; // rbp
  char v11; // r12
  char i; // r11
  int v13; // eax
  __int64 v14; // rcx
  __int64 v15; // rax
  char lpParams; // [rsp+20h] [rbp-158h] BYREF
  char *v18; // [rsp+188h] [rbp+10h] BYREF
  char v19; // [rsp+190h] [rbp+18h] BYREF

  lpParams = 0;
  memset();
  v2 = LB::DecodeString(&v18, byte_4000001366F6);

  //
  //    This is where the request buffer is formatted.
  //
  sprintf(&lpParams, *v2, 0x59D0CDi64, v3); // last parameter is customer e-mail

  v4 = *(_DWORD *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)AVCSteamUserV019 + 16i64))(
                    AVCSteamUserV019,
                    &v19);
  if ( LB::ShareMyLobbyResponse )
  {
    *(_DWORD *)(a1 + 64) = 0;
    free(LB::ShareMyLobbyResponse);
  }
  v5 = (__int64 *)LB::DecodeString(&v18, byte_40000013670E);

  //
  // This will send a request to LMAOBOX's backend.
  // last parameter controls the operation mode.
  // 0 - register with share my lobby yourself 
  // 1 - fetch share my lobby table
  //
  LB::ShareMyLobbyEndpoint(*v5, &LB::ShareMyLobbyResponse, (__int64)&lpParams, 1);

  LOBYTE(v6) = LB::DecodeString2(&v18);
  lpResponse = (char *)LB::ShareMyLobbyResponse;

  if ( LB::ShareMyLobbyResponse )
  {
    if ( *(_BYTE *)LB::ShareMyLobbyResponse )
    {
      //
      //  LMAOBOX uses this simple bitwise not transform for encoding & decoding.
      //
      do
      {
        v8 = *lpResponse++;
        *(lpResponse - 1) = ~v8;
      }
      while ( *lpResponse );
      lpResponse = (char *)LB::ShareMyLobbyResponse;
    }

    v9 = 0;
    v10 = lpResponse;
    v11 = 0;

    //
    // This is where parsing of the response happens.
    //
    for ( i = *lpResponse; i; i = *++lpResponse )
    {
      v13 = *(_DWORD *)(a1 + 64);
      if ( v13 >= 10 )
        break;
      if ( i == 10 )
      {
        if ( v11 )
        {
          v11 = 0;
          v9 = 0;
        }
        else
        {
          v9 = 0;
          *(_DWORD *)(a1 + 64) = v13 + 1;
        }
      }
      else if ( i == ';' )
      {
        *lpResponse = 0;
        if ( v9 )
        {
          switch ( v9 )
          {
            case 1:
              *(_DWORD *)(a1 + 40i64 * *(int *)(a1 + 64) + 84) = MEMORY[0x5FE131D8](v10);
              break;
            case 2:
              *(_DWORD *)(a1 + 40i64 * *(int *)(a1 + 64) + 88) = MEMORY[0x5FE131D8](v10);
              break;
            case 3:
              *(_QWORD *)(a1 + 40i64 * *(int *)(a1 + 64) + 96) = v10;
              break;
            case 4:
              *(_QWORD *)(a1 + 40i64 * *(int *)(a1 + 64) + 104) = v10;
              break;
          }
        }
        else
        {
          *(_DWORD *)(a1 + 8 * (5i64 * *(int *)(a1 + 64) + 10)) = strtol(v10, 0i64, 16i64);
          *v10 = 0;
          v14 = 5i64 * *(int *)(a1 + 64) + 10;
          if ( *(_DWORD *)(a1 + 8 * v14) == v4 )
          {
            *(_DWORD *)(a1 + 8 * v14) = 0;
            *(_DWORD *)(a1 + 40i64 * *(int *)(a1 + 64) + 112) = 0;
            v11 = 1;
          }
          else
          {
            v15 = *(int *)(a1 + 48);
            HIDWORD(v18) = 17825793;
            LODWORD(v18) = *(_DWORD *)(a1 + 8 * (5 * v15 + 10));
            *(_DWORD *)(a1 + 40i64 * *(int *)(a1 + 64) + 112) = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)AVCAdapterSteamFriends + 40i64))(
                                                                  AVCAdapterSteamFriends,
                                                                  v18) == 3;
          }
        }
        v10 = lpResponse + 1;
        ++v9;
      }
    }
    v6 = 22 * *(_DWORD *)(a1 + 64) + 2;
    *(_BYTE *)(a1 + 72) = 1;
    *(_DWORD *)(a1 + 16) = v6;
  }
  return v6;
}