#include <main.h>

int main() 
{
    /* Create Bot Object [cnipe_bot] */
    cnipe_bot bot(BOT_TOKEN);

    /* Add Commands */
    bot.add_command({
        g_comm_test(),
        g_comm_test2()
    });

    /* Start Bot */
    bot.run();
}