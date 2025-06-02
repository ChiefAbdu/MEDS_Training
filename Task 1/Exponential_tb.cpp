#include "verilated.h"
#include "VExponential.h"
#include "verilated_vcd_c.h"
#include "stdio.h"
#include "random"
#include "ctime"

vluint64_t main_time = 0;
double sc_main_timestamp(){
    return main_time;
}

int main(int argc, char** argv){
    VExponential* UUT = new VExponential;
    VerilatedVcdC* tpf = new VerilatedVcdC;
    Verilated::traceEverOn(true);
    UUT->trace(tpf, 99);
    tpf->open("Exponential.vcd");
    for (double i = 0.0; i < 20; i++){
        UUT->x =  i;
        UUT->eval();
        tpf->dump(main_time);
        printf("exp(%f) = %f\n", UUT->x, UUT->y);
        main_time += 500;
    }
    tpf->dump(main_time);
    tpf->close();
    delete UUT;
    delete tpf;
    return 0;
}