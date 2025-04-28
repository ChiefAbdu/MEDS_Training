iodule fulladder(
    input logic a,
    input logic b,
    input logic carryin,
    output logic sum,
    output logic carryout
);

logic xor1, and1, and2;

always(*)
begin
    xor1 = a^b;
    sum = xor1^carryin;
    and1 = a & b;
    and2 = xor1 & carryin;
    carryout = and1 | and2;
end
endmodule