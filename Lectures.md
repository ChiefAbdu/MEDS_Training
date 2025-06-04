# Digital Design & Computer Architecture – Lecture Summaries

---

## Lecture 1: Introduction – Key Takeaways

### Course Goals
- Understand how computers work from the ground up
- Learn digital design and computer architecture principles
- Design and debug a simple microprocessor
- Think critically and systematically about computing systems

### Core Concepts Introduced

#### What is a Computer?
- Comprised of computation, communication, and storage/memory

#### The Transformation Hierarchy
- Layers: Electrons → Devices → Logic → Architecture → Language → Problem
- Emphasizes co-design across all levels

#### Computer Architecture
- Art and science of designing efficient, reliable computing systems
- Involves hardware, software, and their interface

### General-Purpose vs. Special-Purpose Systems
- CPUs: flexible and easy to program
- GPUs, FPGAs, ASICs: higher performance, less flexible

### Transistors and Logic Gates
- MOS transistors are basic building blocks
- CMOS: uses both p-type and n-type transistors
- Logic gates (NOT, NAND, AND) built from transistors

### Moore’s Law
- Transistor count doubles every ~2 years
- Enables advances in computing power and cost efficiency

### Design Principles & Tradeoffs
- Tradeoffs: flexibility vs. performance, energy, area, cost
- Teaching drives research; cross-layer optimization is key

---

## Lecture 2: Combinational Logic – Key Takeaways

### Overview
- Focus: Logic gates, Boolean algebra, canonical forms, combinational circuits

### Logic Fundamentals
- Combinational circuits: output depends only on current inputs
- Basic gates: AND, OR, NOT, NAND, NOR, XOR

### Boolean Algebra
- Rules for manipulating logic expressions
- Tools: axioms, theorems, DeMorgan’s laws
- Duality principle: each identity has a dual

### Canonical Forms
- Sum of Products (SOP): OR of minterms
- Product of Sums (POS): AND of maxterms

### Logic Simplification
- Reduces gate count, area, power, and latency
- Done using Boolean algebra or Karnaugh Maps

### Combinational Building Blocks
- Decoder, Multiplexer (MUX), Full Adder, PLA, Comparator, ALU, Tri-State Buffer

### Logical Completeness
- {AND, OR, NOT}, {NAND}, {NOR} are all functionally complete

### Moore’s Law & Transistor Scaling
- Continued miniaturization (e.g., FinFETs, EUV lithography)

---

## Lecture 3: Sequential Logic – Key Takeaways

### Combinational Logic Recap
- Core logic blocks and simplification techniques
- Tri-state buffers enable bus-based designs

### Sequential Logic
- Stores state (unlike combinational)
- Storage elements:
  - Cross-coupled inverters
  - R-S latch
  - Gated D latch
  - D Flip-Flop
- Registers = group of flip-flops

### Memory Concepts
- Memory as an addressable array of registers
- Access via decoders and multiplexers

### Finite State Machines (FSMs)
- Moore FSM: output depends on state only
- Mealy FSM: output depends on state and inputs
- Components: state register, next-state logic, output logic

### Synchronous vs. Asynchronous Systems
- Synchronous: state changes on clock edge
- Asynchronous: state changes on input events

---

## Lecture 4: Sequential Logic Design II – FSMs

### Agenda Overview
- Finish sequential logic
- Introduce labs, HDLs, and Verilog

### Sequential Logic Recap
- Circuits store information and depend on past and current inputs

### FSM Fundamentals
- Components:
  - Finite states
  - Inputs/outputs
  - Transition logic
  - Output logic

- Structure:
  - State register
  - Next-state logic
  - Output logic

### Types of FSMs
- Moore: output = f(state)
- Mealy: output = f(state, input)

### Flip-Flops & Registers
- D Flip-Flop (edge-triggered)
- Registers = multi-bit flip-flops
- Variants: enabled, resettable, settable

### FSM Example: Traffic Light Controller
- Inputs: TA, TB
- Outputs: LA, LB
- States: LA green/yellow, LB green/yellow

### FSM Design Process
1. Identify states
2. Define transitions and outputs
3. Choose encoding (binary, one-hot, output-encoded)
4. Draw state diagram/table
5. Implement with flip-flops and logic

### Moore vs. Mealy Comparison
- Moore: simpler timing, more states
- Mealy: faster output response, fewer states

---

## Lecture 5: Hardware Description Languages and Verilog II

### Agenda
- Combinational/sequential logic in Verilog
- Lab references

### HDL Motivation
- Supports structural and behavioral modeling
- Enables concurrency, simulation, synthesis

### Design Principles
- Hierarchical design (top-down and bottom-up)

### Verilog Syntax
- Define modules with I/O and internal logic
- Bit manipulations: slicing, concatenation

### HDL Styles
- Structural: gate-level instantiation
- Behavioral: high-level descriptions using `assign`, operators

### Key Constructs
- Operators: `&`, `|`, `^`, `~`, `? :`, `case`
- Constants: `8'b0101_1100`, `12'hF3A`
- Tri-state: `4'bz` (high impedance)

### Simulation vs. Synthesis
- Simulation: functional/timing correctness
- Synthesis: creates hardware netlists
- HDL code must be synthesizable

---

## Lecture 6: Timing and Verification II

### 1. Combinational Circuit Timing

#### Delay Types
- Propagation delay (tpd): max time to output
- Contamination delay (tcd): min time to output

#### Delay Factors
- Influenced by capacitance, resistance, temp, voltage

#### Paths
- Critical path: longest delay, limits clock speed
- Shortest path: may cause hold violations

#### Glitches
- Caused by unequal path delays
- May be fixable using consensus terms in K-maps

---

### 2. Sequential Circuit Timing

#### Flip-Flop Timing Constraints
- Setup time: data stable before clock edge
- Hold time: data stable after clock edge
- Clock-to-Q delays: tccq (min), tpcq (max)

#### Timing Formulas
- Setup: `Tc > tpcq + tpd + tsetup`
- Hold:  `tccq + tcd > thold`

#### Clock Skew
- Delay between clock arrival at different flip-flops
- Adjusts setup/hold constraints:
  - `Tc > tpcq + tpd + tsetup + tskew`
  - `tccq + tcd > thold + tskew`

---

### 3. Circuit Verification

#### Functional vs. Timing Verification
- Functional: does the logic work?
- Timing: does it meet timing constraints?

#### Tools
- Simulation (Vivado, Verilog testbenches)
- Circuit-level (SPICE)
- Formal (SAT solvers)

---

### 4. Functional Verification in Verilog

#### Testbench Types
- Simple: manual input/output, visual check
- Self-checking: automated assertions
- Testvector-based: file-driven testing
- Automatic: compare to golden model

#### Golden Models
- Known-correct reference model
- Used for large-scale automated validation

---

### 5. Timing Verification

#### Tools
- Reports from synthesis/place-and-route
- Show max frequency, violations

#### Strategies
- Optimize critical path
- Balance logic across flip-flop paths
- Optimize for common-case use

---
