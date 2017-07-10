// to use add snapback(); to your convertinputs() function and copy and paste the code below to the end of your arduino file....

#define SNAP_STR_AMT 6
word snap_str[SNAP_STR_AMT] = {0};
word break_snap = 0;
word iters_to_break = 3;

void snapback() {
    int current_x = ax;

    if (axm > 30 && !break_snap) {
        bool equal_directions = true;
        for (int i = 1; i < SNAP_STR_AMT; i++) {
            if (sign(snap_str[i-1]) != sign(snap_str[i])) {
                equal_directions = false;
            }
        }

        if (equal_directions) {
            if (sign(snap_str[SNAP_STR_AMT-1]) != sign(current_x) && abs(current_x) > 5) {
                break_snap = iters_to_break;
                // debugln("Broke snap");
            }
        }
    }

    if (break_snap) {
        break_snap--;
        gcc.xAxis =  neutral_x;
        // debug("b" + String(break_snap) + ":: ");
    }

    //shift array items left by 1
    for (int i = 0; i < SNAP_STR_AMT - 1; i++) {
        snap_str[i] = snap_str[i + 1];
    }
    
    snap_str[SNAP_STR_AMT - 1] = current_x;
}
