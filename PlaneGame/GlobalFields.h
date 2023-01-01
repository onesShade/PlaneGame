#pragma once
#include "FpsCounter.h"
#include <string>
#include <math.h> 
#include "BulletManager.h"

class FpsCounter;
class BulletManager;




static FpsCounter* mainFpsCounter;

static float planeOffSet = 0.8f;

static int windowWidth = 1280;
static int windowHeight = 720;


const int TileSize = 32;

static float texturesScale = 2.f;

const std::string texturesSheetPath = "./Resources/PlanesNWater.png";


class GlobalFields
{
protected:
	GlobalFields()
	{

	}
public:


};