SpawnVehicle(playerID, modelID, color1, color2, showMessage)
{
	if (modelID)
	{
		if (modelID >= 400 && modelID <= 611)
		{
			if (color1 >= 0 && color1 <= 127 && color2 >= 0 && color2 <= 127)
			{
				new Float:posX;
				new Float:posY;
				new Float:posZ;
				GetPlayerPos(playerID, posX, posY, posZ);
				new vehicleID = CreateVehicleEx(modelID, posX, posY, posZ, 0.0, color1, color2, -1);
				LinkVehicleToInterior(vehicleID, GetPlayerInterior(playerID));
				SetVehicleVirtualWorld(vehicleID, GetPlayerVirtualWorld(playerID));
				PutPlayerInVehicle(playerID, vehicleID, 0);
				if (showMessage)
				{
					SendClientMessageEx(playerID, COLOR_INFO, 62);
				}
				return true;
			}
			else
			{
				if (showMessage)
				{
					SendClientMessageEx(playerID, COLOR_ERROR, 63);
				}
			}
		}
		else
		{
			if (showMessage)
			{
				SendClientMessageEx(playerID, COLOR_ERROR, 65);
			}
		}
	}
	else
	{
		if (showMessage)
		{
			SendClientMessageEx(playerID, COLOR_ERROR, 64);
		}
	}
	return false;
}