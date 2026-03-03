#include <3ds.h>
#include "jsmn.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "themeloader.h"

// static const char *JSON_STRING = "{\"botTextColor\": \"#FFFFFFFF\"}";

static int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
  if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start &&
      strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
    return 0;
  }
  return -1;
}

char* readJSONFile(void) {
    FILE* fp = fopen("hblTheme.json", "r");
    if (!fp) {
        printf("Could not open file\n");
        return NULL;
    }

    char* buffer = malloc(1024);
    if (!buffer) return NULL;

    size_t bytesRead = fread(buffer, 1, 1023, fp);
    buffer[bytesRead] = '\0'; // null-terminate

    fclose(fp);
    return buffer;
}

void parseThemeFile(char* jsonString, themeInfo_s* themeInfo) {
    int i;
    int r;
    jsmn_parser p;
    jsmntok_t t[64]; /* We expect no more than 64 JSON tokens */

    jsmn_init(&p);
    r = jsmn_parse(&p, jsonString, strlen(jsonString), t, sizeof(t) / sizeof(t[0]));
    
    if (r < 0) {
        printf("Failed to parse JSON: %d\n", r);
        return;
    }

    /* Assume the top-level element is an object */
    if (r < 1 || t[0].type != JSMN_OBJECT) {
        printf("Object expected\n");
        return;
    }

    /* Loop over all keys of the root object */
    for (i = 1; i < r; i++) {
        if (jsoneq(jsonString, &t[i], "botTextColor") == 0) {
            /* We may use strndup() to fetch string value */
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->botTextColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "topTextColor") == 0) {
            /* We may use strndup() to fetch string value */
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->topTextColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "overlaysBgColor") == 0) {
            /* We may use strndup() to fetch string value */
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->overlaysBgColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "menuEntryColor") == 0) {
            /* We may use strndup() to fetch string value */
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->menuEntryColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "starredMenuEntryColor") == 0) {
            /* We may use strndup() to fetch string value */
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->starredMenuEntryColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "topBgColor") == 0) {
            /* We may use strndup() to fetch string value */
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->topBgColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "topStrokeWaveColor") == 0) {
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->topStrokeWaveColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "botStrokeWaveColor") == 0) {
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->botStrokeWaveColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "waveGradientStartColor") == 0) {
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->waveGradientStartColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "waveGradientEndColor") == 0) {
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->waveGradientEndColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "logoColor") == 0) {
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->logoColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "bubbleColor") == 0) {
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->bubbleColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "topOverlaysBgColor") == 0) {
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->topOverlaysBgColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        } else if (jsoneq(jsonString, &t[i], "scrollBarColor") == 0) {
            int len = t[i+1].end - t[i+1].start;
            char* value = strndup(jsonString + t[i+1].start, len);
            themeInfo->scrollBarColor = (u32)strtoul(value + 1, NULL, 16);
            free(value);
            i++;
        }
        else {
            printf("Unexpected key: %.*s\n", t[i].end - t[i].start, jsonString + t[i].start);
            return;
        }
    }
}
