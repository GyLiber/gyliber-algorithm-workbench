# GyLiber Algorithm Workbench Design

## Purpose

This repository is a collection of small programming practices designed to
develop reusable algorithms, interfaces, and implementation techniques.

The practices are deliberately designed so that a narrowly specified academic
problem can act as a concrete specialization and test of a more reusable
program component.

For example, a requirement to find the minimum integer in an array should
preferably exercise a minimum-selection operation that is not fundamentally
restricted to integers.

## Languages

Practices are organized by programming language.

Initial languages:

- ANSI C90
- Java
- JavaScript
- TypeScript

Each language may use its own appropriate abstraction mechanisms.

## Design Principles

1. Prefer reusable algorithms over fixed-purpose implementations.
2. Separate an algorithm from the representation of the data when practical.
3. Use narrow academic requirements as concrete tests of reusable components.
4. Keep each practice small enough to understand completely.
5. Prefer simple, correct implementations over premature sophistication.
6. Document code sufficiently for learning, recall, and later replication.
7. Record completed logical units in Git history.
8. Verify each practice before considering it complete.

## Practice Structure

Each practice should normally contain:

- source code;
- a small practice-specific README;
- build/test instructions;
- a Makefile or equivalent build mechanism where appropriate.

The practice directory should remain self-contained where practical.

## Version 1.0.0 Success Criteria

The repository reaches its initial version when:

- the repository structure is established;
- the conventions above are documented;
- the first ANSI-C90 practice is implemented;
- the implementation is reusable beyond its immediate integer example;
- the required academic problem is demonstrated as a specialization/test;
- the program builds reproducibly;
- the required tests pass;
- the practice documentation is sufficient for another programmer to build,
  run, understand, and reproduce the exercise;
- the completed work is committed to Git.

## AI Development Transparency

ChatGPT (GPT-5.6 Luna) was used as a development collaborator throughout
the creation of this repository, including design, implementation,
documentation, testing decisions, and development workflow.

The repository remains subject to human review, execution, verification,
and maintenance by its owner.
