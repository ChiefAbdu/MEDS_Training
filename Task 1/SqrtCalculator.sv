`timescale 1ns/10ps

function real sqrt_real(input real x);
    automatic real low, high, mid;
    automatic real epsilon = 1e-10;
    automatic int i;

    begin
        if (x <= 0.0)
            return 0.0;

        // Set initial bounds
        low  = 0.0;
        high = (x < 1.0) ? 1.0 : x;

        // Perform binary search
        for (i = 0; i < 100; i++) begin
            mid = (low + high) / 2.0;
            if ((mid * mid - x) > epsilon)
                high = mid;
            else if ((x - mid * mid) > epsilon)
                low = mid;
            else
                break;  // Close enough
        end

        return mid;
    end
endfunction

module SqrtCalculator(
    input  real x,
    output real y
);
    always_comb begin
        y = sqrt_real(x);
    end
endmodule
