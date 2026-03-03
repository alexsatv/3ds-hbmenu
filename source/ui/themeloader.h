#pragma once
#include <3ds.h>

typedef struct
{
	u32 topBgColor;
	u32 botTextColor;
	u32 topTextColor;
	u32 overlaysBgColor;
	u32 topOverlaysBgColor;
	u32 menuEntryColor;
	u32 starredMenuEntryColor;
	u32 topStrokeWaveColor;
	u32 botStrokeWaveColor;	
	u32 waveGradientStartColor;
	u32 waveGradientEndColor;
	u32 scrollBarColor;
	u32 logoColor;
	u32 bubbleColor;
} themeInfo_s;

void parseThemeFile(char* jsonString, themeInfo_s* themeInfo);
char* readJSONFile(void);

/* Result shortcutCreate(shortcut_s* d, const char* path);
void shortcutFree(shortcut_s* d); */
