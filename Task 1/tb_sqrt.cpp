#include "verilated.h"
#include "VSqrtCalculator.h"
#include "verilated_vcd_c.h"
#include <cstdio>

vluint64_t main_time = 0;
double sc_time_stamp() {
    return main_time;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    VSqrtCalculator* UUT = new VSqrtCalculator;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    UUT->trace(tfp, 99);
    tfp->open("SqrtCalculator.vcd");

    // Apply inputs and evaluate
    for (double i = 0.0; i =< 36 ;i += 1.0) {
        UUT->x = i;
        UUT->eval();
        tfp->dump(main_time);

        printf("sqrt(%f) = %f\n", UUT->x, UUT->y);

        main_time += 500;
    }

    tfp->dump(main_time);
    tfp->close();

    delete UUT;
    delete tfp;

    return 0;
}
