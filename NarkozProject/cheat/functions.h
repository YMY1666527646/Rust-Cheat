#include "../cheat/cheat.h"
#include "../offsets.h"
#include "../settings.h"

//


std::mutex mtx;

UINT64 GetHeldItem(UINT64 LocalPlayer)
{
	const auto base_player = LocalPlayer;
	const auto active_item_id = Read<UINT64>(base_player + oActiveUID);
	const auto player_inventory = Read<UINT64>(base_player + oPlayerInventory);
	const auto inventory_belt = Read<UINT64>(player_inventory + oContainerBelt);
	const auto belt_contents_list = Read<UINT64>(inventory_belt + oBeltContentList);
	const auto belt_contents_sz = Read<uint32_t>(belt_contents_list + 0x14);
	const auto belt_contents = Read<UINT64>(belt_contents_list + 0x10);

	for (auto i = 0u; i <= 6; i++)
	{
		if (belt_contents != 0)
		{
			const auto current_item = Read<UINT64>(belt_contents + (0x20 + (i * 8)));
			if (!current_item) continue;
			if (active_item_id == Read<uint32_t>(current_item + 0x28)) return current_item;
		}
	}
}
int get_item_id(uintptr_t item)
{
	return Read<UINT64>(item + 0x18);
}
std::wstring get_item_name(uintptr_t item)
{
	auto unk = Read<UINT64>(item + 0x20);
	unk = Read<UINT64>(unk + 0x20);
	return read_wstring(unk + 0x14, 14);
}
bool is_weapon(uintptr_t helditem)
{
	auto ItemName = get_item_name(helditem);
	if (ItemName.find(L"rifle") != std::string::npos) return true;
	if (ItemName.find(L"pistol") != std::string::npos) return true;
	if (ItemName.find(L"bow") != std::string::npos) return true;
	if (ItemName.find(L"lmg") != std::string::npos) return true;
	if (ItemName.find(L"shotgun") != std::string::npos) return true;
	if (ItemName.find(L"smg") != std::string::npos) return true;
	else return false;
}

bool admin_flag() {

	mtx.lock();
	auto _local_player = Player2;
	mtx.unlock();

	if (!_local_player) {
		return false;
	}
	auto player_flags = Read<uintptr_t>(_local_player + oPlayerFlags);
	if (!player_flags) {
		return false;
	}
	if (admin_flag_checkboxx == true) {
		player_flags |= 4;
		write<uintptr_t>(_local_player + oPlayerFlags, player_flags);
		return true;
	}
}
bool spiderman() {
	auto _local_player = Player2;
	if (spiderman_checkboxx) {
		auto base_movement = Read<uintptr_t>(Player2 + oPlayerMovement);
		if (!base_movement) {
			return false;
		}
		write<float>(base_movement + oGroundAngle, 0.f);
		write<float>(base_movement + oGroundAngleNew, 0.f);
		return true;
	}
}
bool gravity() {
	auto _local_player = Player2;
	if (gravity_checkboxx == true) {
		auto base_movement = Read<uintptr_t>(Player2 + oPlayerMovement);
		if (!base_movement) {
			return false;
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			write<float>(base_movement + oGravityMultiplier, gravity_distancee / 2);
		}
		else
		{
			write<float>(base_movement + oGravityMultiplier, 2.f);
		}
	}
}




bool no_recoil() {

	const auto current_item = GetHeldItem(Player2);
	bool isWeapon = is_weapon(current_item);

	if (isWeapon) {
		auto base_projectile = Read<uintptr_t>(current_item + oHeld);
		auto recoil_prop = Read<uintptr_t>(base_projectile + oRecoilProperties);

		if (no_recoil_checkbox) {
			if (!std::count(Recoil::Automatics.begin(), Recoil::Automatics.end(), current_item)) {
				Recoil::Automatics.push_back(current_item);
				write<float>(recoil_prop + oRecoilYawMin, 0);
				write<float>(recoil_prop + oRecoilYawMax, 0);
				write<float>(recoil_prop + oRecoilPitchMin, 0);
				write<float>(recoil_prop + oRecoilPitchMax, 0);
			}
		}
		if (full_automatic_checkbox) {
			if (!std::count(Recoil::Weapons.begin(), Recoil::Weapons.end(), current_item)) {
				Recoil::Weapons.push_back(current_item);
				return write<bool>(base_projectile + oAutomatic, full_automatic_checkbox);
			}
		}
		if (nospread_checkbox) {
			if (!std::count(Recoil::Spreads.begin(), Recoil::Spreads.end(), current_item)) {
				
			}
		}
		if (super_eoka_checkbox) {
		
		}
		if (fast_bow_checkbox) {
		
		}

		if (Fast_Compound_Checkbox) {
	
		}
	}
}



bool walkOnWater() {
	auto _local_player = Player2;
	if (walkonwater_checkboxx == true) {
		auto base_movement = Read<uintptr_t>(Player2 + oPlayerMovement);
		if (!base_movement) {
			return false;
		}
		if (GetAsyncKeyState(VK_CAPITAL))
		{
			write<float>(base_movement + oGroundAngle, 0.f);//groundAngle
			write<float>(base_movement + oGroundAngleNew, 0.f);//groundAngleNew
			write<float>(base_movement + oGravityMultiplier, 0.f);//gravityMultiplier
		}
		else
		{
			write<float>(base_movement + oGravityMultiplier, 2.5f);//gravityMultiplier
		}
	}
}

float saatfloat = 12.f;
bool change_time() {
	if (change_time_checkbox == TRUE) {
		if (!TodCycle) {
			return false;
		}
		write<float>(TodCycle + 0x10, saatfloat);
	}
}


float eluzunlugu = 90.f;
bool FovChanger() {
	if (FOV_CHECK == TRUE) {
		uint64_t fov = Read<UINT64>(get_module_base_address("GameAssembly.dll") + 51460336); // #define oFovConVarGraphics 0x32A2460; // "Signature": "ConVar_Graphics_c*" // DONE
		uint64_t instance = Read<UINT64>(fov + 0xB8);

		write<float>(instance + 0X18, eluzunlugu);

		return false;

	}

}

void FatBullet() {
	if (fat_bullet_checkbox) {
		const auto current_item = GetHeldItem(Player2);
		DWORD64 Held = Read<DWORD64>(current_item + oHeld);
		DWORD64 List = Read<DWORD64>(Held + 0x358);
		int size = Read<DWORD64>(List + 0x18);
		List = Read<DWORD64>(List + 0x10);
		{
			for (int i = 0; i < size; ++i)
			{
				UINT64 Item = Read<UINT64>(List + 0x20 + (i * 0x8));
				write<float>(Item + 0x2C, -1.f);
			}
		}
	}
}
/*/*
	if (fat_bullet_checkbox) {
		const auto current_item = GetHeldItem(Player2);
		DWORD64 Held = Read<DWORD64>(current_item + oHeld);
		DWORD64 List = Read<DWORD64>(Held + 0x358);
		int size = Read<DWORD64>(List + 0x18);
		List = Read<DWORD64>(List + 0x10);
		{
			for (int i = 0; i < size; ++i)
			{
				UINT64 Item = Read<UINT64>(List + 0x20 + (i * 0x8));
				write<float>(Item + 0x2C, 1.0f);
	/*/