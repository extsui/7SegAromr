#ifndef LOOP_H_INCLUDED
#define LOOP_H_INCLUDED

void Loop_init(void);

void Loop_main(void);

/**
 * 1ms周期ハンドラ
 */
void Loop_1msCyclicHandler(void);

#endif /* LOOP_H_INCLUDED */
