//#include"DxLib.h"
//#include"InputKey.h"
//
//// ===============
//// ƒOƒ[ƒoƒ‹•Ï”
//// ===============
//LPDIRECTINPUT8 g_InputInterface;
//LPDIRECTINPUTDEVICE8 g_InputKeyboardDevice;
//
//InputState g_KeyStates[256];
//
//InputState UpdateInputState(bool is_push, InputState state);
//
//InputState UpdateInputState(bool is_push, InputState state)
//{
//	if (is_push == true)
//	{
//		if (state == InputState::NoHold)
//		{
//			return InputState::Pushed;
//		}
//		else if (state == InputState::Hold || state == InputState::Pushed)
//		{
//			return InputState::Hold;
//		}
//	}
//	else
//	{
//		if (state == InputState::Hold || state == InputState::Pushed)
//		{
//			return InputState::Released;
//		}
//		else
//		{
//			return NoHold;
//		}
//	}
//
//	return InputState::Released;;
//}
//
//bool InputInit()
//{
//	HRESULT hr = DirectInput8Create(
//		GetModuleHandle(nullptr),
//		DIRECTINPUT_VERSION,
//		IID_IDirectInput8,
//		(void**)&g_InputInterface,
//		nullptr
//	);
//
//	if (FAILED(hr))
//	{
//		return false;
//	}
//
//	hr = g_InputInterface->CreateDevice(
//		GUID_SysKeyboard,
//		&g_InputKeyboardDevice,
//		nullptr);
//
//	hr = g_InputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
//	if (FAILED(hr))
//	{
//		return false;
//	}
//
//	hr = g_InputKeyboardDevice->SetCooperativeLevel(
//		FindWindow(TEXT("CreateWindow"), nullptr),
//		DISCL_BACKGROUND | DISCL_NONEXCLUSIVE);
//	if (FAILED(hr))
//	{
//		return false;
//	}
//
//	hr = g_InputKeyboardDevice->Acquire();
//	if (FAILED(hr))
//	{
//		return false;
//	}
//
//	return true;
//}
//
//void InputRelease()
//{
//	if (g_InputKeyboardDevice != nullptr)
//	{
//		g_InputKeyboardDevice->Unacquire();
//
//		g_InputKeyboardDevice->Release();
//		g_InputKeyboardDevice = nullptr;
//	}
//
//	if (g_InputInterface != nullptr)
//	{
//		g_InputInterface->Release();
//		g_InputInterface = nullptr;
//	}
//}
//
//void InputUpdate()
//{
//	BYTE KeyStates[256];
//	HRESULT hr;
//
//	hr = g_InputKeyboardDevice->GetDeviceState(
//		256,
//		KeyStates);
//	if (SUCCEEDED(hr))
//	{
//		for (int i = 0; i < 256; i++)
//		{
//			bool is_push = false;
//
//			if (KeyStates[i] & 0x80)
//			{
//				is_push = true;
//			}
//
//			g_KeyStates[i] = UpdateInputState(is_push, g_KeyStates[i]);
//		}
//	}
//}
//
//bool IsKeyHeld(int key)
//{
//	if (key < 0 || key > 256)
//	{
//		return false;
//	}
//
//	return g_KeyStates[key] == InputState::Hold ? true : false;
//}
//
//bool IsKeyPushed(int key)
//{
//	if (key < 0 || key > 256)
//	{
//		return false;
//	}
//
//	return g_KeyStates[key] == InputState::Pushed ? true : false;
//}
//
//bool IsKeyReleased(int Key)
//{
//	if (Key < 0 || Key > 256)
//	{
//		return false;
//	}
//	return g_KeyStates[Key] == InputState::Released ? true : false;
//}
