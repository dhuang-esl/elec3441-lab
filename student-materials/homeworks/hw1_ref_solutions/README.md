# Homework 1 reference solutions

Released for review after Homework 1 grading. These are example solutions; other correct implementations are possible.

- [Reference answers](ELEC3441_Homework1_Reference_Answers.md): Part A calculations and assembly, plus Part B design explanations.
- [rv32_addi.circ](rv32_addi.circ): Stage 1, ADDI and the supplied register operations.
- [rv32_isu.circ](rv32_isu.circ): Stage 2, adds AUIPC, LW and SW.
- [rv32_all.circ](rv32_all.circ): Stage 3, adds branches, JAL and JALR.
- [uproclib.circ](uproclib.circ): shared circuit library required by all three stages. Keep it in the same folder as the processor circuits.

See the [Homework 1 handout](../../handouts/homework1.pdf) for the questions. Answer headings use the handout's Part A numbering.

## Open and test a circuit

1. Use Logisim-Evolution in the course Docker environment. Open a circuit from `/workspace/homeworks/hw1_ref_solutions/`.
2. Use the existing [test programs and memory images](../hw1/test/). Select a test supported by the stage you opened.
3. Reset the simulation before loading the chosen `.mem` image into the instruction ROM (`inst_mem`). For the LW test, also load `lw.mem` into the data RAM (`data_ram`) after resetting. Resetting afterward clears the RAM initialization.
4. Advance the clock until `halt=1`, then inspect the registers and, for stores, data RAM. Compare with the test assembly and the reference answers.

For a quick Stage 1 check, load `addi.mem`: x1 through x5 should finish at 1, 2, 3, 2 and 0xffffffff. For the Stage 3 combined jump check, load `jaljalr.mem`: x1=x2=0x0c and x4=x5=0x34 when halted. Load the named test explicitly; the circuits may open with different demonstration programs already in their ROMs.

LUI and SLLI are optional extensions and are not required of these reference stages. The `.s` files document each test; no recompilation is needed to use the supplied `.mem` images.
