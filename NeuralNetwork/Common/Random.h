#ifndef AIENGINE_RANDOM_H
#define AIENGINE_RANDOM_H
float randomRange(float a, float b)
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float difference = b - a;
    float value = random * difference;
    return a + value;
}
#endif //AIENGINE_RANDOM_H
