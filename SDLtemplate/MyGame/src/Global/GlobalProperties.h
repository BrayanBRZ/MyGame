#ifndef GLOBALPROPERTIES_H
#define GLOBALPROPERTIES_H

// Constantes de resolução // 640 x 360 : 854 x 480 : 1024 x 576 : 1280 x 720 : 1366 X 768
inline constexpr int SCREEN_WIDTH = 1024;
inline constexpr int SCREEN_HEIGHT = 576;
inline constexpr int DEFAULT_SCREEN_WIDTH = 640;
inline constexpr int DEFAULT_SCREEN_HEIGHT = 360;

// Definição de escala padrão
inline constexpr float DEFAULT_SCALE = 4;

// Funções para calcular a escala
constexpr float customRound(float value)
{ return (value >= 0.0f) ? (float)((int)(value + 0.5f)) : (float)((int)(value - 0.5f)); }

inline constexpr float calculateWidthScale(int screenWidth)
{ return customRound(DEFAULT_SCALE * ((float)(screenWidth) / DEFAULT_SCREEN_WIDTH) / 2.0f); }

inline constexpr float calculateHeightScale(int screenHeight)
{ return customRound(DEFAULT_SCALE * ((float)(screenHeight) / DEFAULT_SCREEN_HEIGHT) / 2.0f); }

// Constantes para conversão de unidades
inline constexpr float SCALE_WIDTH = calculateWidthScale(SCREEN_WIDTH);
inline constexpr float SCALE_HEIGHT = calculateHeightScale(SCREEN_HEIGHT);
inline constexpr int DEFAULT_UNIT_TO_PIXELS = 16;

// Constantes de física padrão
inline constexpr float DEFAULT_MASS = 1.0f;
inline constexpr float DEFAULT_FRICTION = 0.8f;

// Constantes de direção
inline constexpr int UPWARD = -1;
inline constexpr int DOWNWARD = 1;
inline constexpr int RIGHTWARD = 1;
inline constexpr int LEFTWARD = -1;

#endif // GLOBALPROPERTIES_H