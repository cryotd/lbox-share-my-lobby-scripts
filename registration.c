char __fastcall LB::SML::PublishLobby(unsigned int a1, int a2, __int64 a3, int matchType)
{
  char **pszFormatStr; // rax
  __int64 v8; // r10
  void *v9; // r11
  void *v10; // r9
  __int64 *v11; // rax
  __int64 v13; // [rsp+40h] [rbp-148h] BYREF
  char lpParams[304]; // [rsp+50h] [rbp-138h] BYREF
  char *v15; // [rsp+1A0h] [rbp+18h] BYREF

  // key=%X&i=%X&c=%d&m=%d&u=%s&n=%s..
  pszFormatStr = LB::DecodeString(&v15, byte_400000136E16);
  v10 = &unk_400000128E30;
  if ( v9 )
    v10 = v9;
  // 0000001B84AFD9D0   key=59D0CD&i=0&c=0&m=1&u=rijin.ramesh@drof.space&n=.....¡[û8ø...  
  sprintf(lpParams, *pszFormatStr, 0x59D0CDi64, a1, a2, matchType, v8, v10);
  LB::DecodeString2(&v15);
  v11 = (__int64 *)LB::DecodeString(&v15, byte_400000136E3E);

  // use last param: 0 for publishing mode.
  LB::ShareMyLobbyEndpoint(*v11, &v13, (__int64)lpParams, 0);
  return LB::DecodeString2(&v15);
}

void __fastcall LB::Wrap::Publish::SML(char a1)
{
  __int64 v1; // rsi
  int v2; // ebx
  char v3; // di
  unsigned int v4; // er12
  __int64 v5; // r13
  __int64 v6; // rax
  char v7; // cl
  __int64 v8; // rbp
  int v9; // esi
  unsigned int *v10; // rax
  float v11; // xmm0_4
  char v12; // al
  int v14; // [rsp+78h] [rbp+10h] BYREF
  __int64 v15; // [rsp+80h] [rbp+18h]
  char v16; // [rsp+88h] [rbp+20h] BYREF

  v1 = MEMORY[0x7FFF07024B10];
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0i64;
  if ( MEMORY[0x7FFF07024B10] )
  {
    v8 = (**(__int64 (__fastcall ***)(__int64))AVCAdapterSteamFriends)(AVCAdapterSteamFriends);
    v15 = v8;
    dword_40000015D518 = 1;
    (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)(v1 + 184) + 56i64))(v1 + 184, &dword_40000015D510);
    v14 = 0;
    lstrlen(v8);
    v9 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v1 + 184) + 16i64))(v1 + 184);
    v2 = v9;
    v10 = (unsigned int *)(*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)AVCSteamUserV019 + 16i64))(
                            AVCSteamUserV019,
                            &v16);
    v4 = *v10;
    if ( v14 == *v10 )
    {
      v5 = v15;
      v3 = 1;
      v7 = 0;
    }
    else
    {
      v7 = 1;
      g_bWasSteamUserCached = 0;
    }
    dword_40000015FD80 = v14;
    dword_40000015FD7C = v9;
    dword_40000015FD78 = 0;
    dword_40000015FD74 = 1;
  }
  else
  {
    if ( g_bWasSteamUserCached )
    {
      v7 = 0;
      goto LABEL_11;
    }
    v4 = *(_DWORD *)(*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)AVCSteamUserV019 + 16i64))(
                      AVCSteamUserV019,
                      &v14);
    v6 = (**(__int64 (__fastcall ***)(__int64))AVCAdapterSteamFriends)(AVCAdapterSteamFriends);
    v2 = 1;
    v3 = 1;
    g_bWasSteamUserCached = 1;
    v7 = 0;
    v5 = v6;
  }
  byte_40000015D521 = v7;
LABEL_11:
  v11 = *(float *)&LB::ShareMyLobby::LastUpdatedTIme;
  if ( MEMORY[0x7FFF14C90A5C] < 0.0 )
  {
    v11 = 0.0;
    LB::ShareMyLobby::LastUpdatedTIme = 0;
  }
  if ( a1 || v3 || (float)(v11 + 60.0) < MEMORY[0x7FFF14C90A5C] )
  {
    v12 = v3;
    if ( !v7 )
      v12 = 1;
    LB::ShareMyLobby::LastUpdatedTIme = MEMORY[0x7FFF14C90A5C];
    if ( v12 )
      LB::SML::PublishLobby(v4, v2, v5, 1);
  }
}
