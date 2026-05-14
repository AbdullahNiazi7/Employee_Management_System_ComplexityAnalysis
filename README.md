# Employee Management System | Complexity Analysis & Refactoring

**Course:** Software Construction & Development  
**Institution:** International Islamic University Islamabad  
**Department:** Software Engineering  
**Student:** Muhammad Abdullah Khan  `4747-FOC/BSSE/F23 (A)`  
**Instructor:** Shakir Rasheed Khan Khattak  

---

## Overview

This project presents a complete complexity analysis and refactoring of an **Employee Management System** written in C++. The system manages employees at a software company and supports core HR operations including adding, updating, and removing employees, calculating payroll, checking promotions, and generating reports.

The primary objective is to identify, measure, and reduce both **Cyclomatic Complexity** and **Cognitive Complexity** across all functions in the codebase, demonstrating how thoughtful refactoring leads to code that is easier to test, read, and maintain.

---

## Project Structure

```
├── EmployeeManagement_Original.cpp       # Original submitted code (unmodified)
├── EmployeeManagement_Improved.cpp       # Refactored code with reduced complexity
├── Complexity_Report_Abdullah_4747.docx  # Full analysis and comparison document
└── README.md
```

---

## Employees in the System

| Name | Role | Company |
|------|------|---------|
| Abdullah | Senior Developer | Codistan |
| Usman | Junior Developer | Codistan |
| Zayam | Intern → Mid-Level Developer | Codistan |
| Bilal | Team Lead | Codistan |

---

## Features

- Add, update, and remove employees
- View full employee list
- Calculate payroll with bonuses and deductions
- Generate employee performance reports
- Promotion eligibility check based on years of experience

---

## Complexity Analysis Summary

### Original Code

| Function | Cyclomatic CC | Cognitive CC |
|----------|:-------------:|:------------:|
| `addEmployee()` | 2 | 3 |
| `removeEmployee()` | 4 | 5 |
| `updateEmployee()` | 3 | 4 |
| `viewEmployees()` | 3 | 4 |
| `calculatePayroll()` | 3 | 4 |
| `generateReport()` | 3 | 4 |
| `AskForPromotion()` | 2 | 3 |
| **Total** | **20** | **27** |

### Refactored Code

| Function | Cyclomatic CC | Cognitive CC |
|----------|:-------------:|:------------:|
| `addEmployee()` | 2 | 1 |
| `removeEmployee()` | 2 | 2 |
| `updateEmployee()` | 2 | 2 |
| `viewEmployees()` | 3 | 2 |
| `calculatePayroll()` | 2 | 2 |
| `generateReport()` | 3 | 2 |
| `AskForPromotion()` | 2 | 1 |
| `findEmployeeIndex()` *(new)* | 3 | 3 |
| `shiftEmployeesLeft()` *(new)* | 2 | 1 |
| `IsEligibleForPromotion()` *(new)* | 2 | 1 |
| `CanAddEmployee()` *(new)* | 2 | 1 |
| **Total** | **25** | **18** |

> **Cognitive Complexity reduced by ~33%** from 27 down to 18.  
> No single function exceeds a Cognitive CC of 3 after refactoring.

---

## Key Refactoring Changes

- **Guard Clauses** replaced large `if-else` blocks with early returns, eliminating unnecessary nesting
- **Helper Extraction** four new single-responsibility helper functions extracted to remove duplicated logic
- **DRY Principle** the employee search loop that was copy-pasted in four methods now lives in one place: `findEmployeeIndex()`
- **Flat Structure** maximum nesting depth reduced from 3 to 1 across the entire project

---

## How to Compile and Run

```bash
g++ EmployeeManagement_Improved.cpp -o EmployeeManagement
./EmployeeManagement
```

Requires a C++11 or later compiler.

---

## Complexity Score Reference

| Score | Classification | Risk Level |
|-------|---------------|------------|
| 1 – 10 | Simple | Not much risk |
| 11 – 20 | Complex | Low risk |
| 21 – 50 | Too Complex | Medium risk — attention needed |
| > 50 | Too Complex | Cannot test — high risk |

---

*Submitted as part of the Software Construction & Development course assignment — International Islamic University Islamabad.*
