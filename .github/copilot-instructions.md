# Copilot Instructions for School Management CLI

This project is a C++ command-line application for managing students. It is structured as a single-file CLI with all logic in `main.cpp` and a helper file `print.cpp` (if present). The project is simple and does not use external libraries or frameworks.

## Project Structure

- `main.cpp`: Contains all core logic, including menu handling, student data management, and user interaction.
- `print.cpp`: (If present) Used for output helper functions like `printTitle`.
- `build.sh`: (If present) Used to build the project from the command line.
- `README.md`: Project overview (in Bahasa Indonesia).

## Key Patterns & Conventions

- **Student Data**: Managed in-memory using a `std::vector<Student>`. Each `Student` has an `id` and `name`.
- **Menus**: Main and sub-menus are printed and handled via dedicated functions. User input is validated against allowed menu options.
- **Function Naming**: Functions use `camelCase` (e.g., `printMainMenu`, `insertNewStudent`).
- **No External Dependencies**: Only standard C++ libraries are used.
- **No Persistent Storage**: All data is lost when the program exits.

## Build & Run

- To build (if `build.sh` exists):
  ```sh
  ./build.sh
  ```
- Or compile manually:
  ```sh
  g++ -std=c++17 main.cpp -o main
  ./main
  ```

## Extending Functionality

- Add new menu options by updating the menu print and input functions, and extending the `switch` statements.
- To add new student fields, update the `Student` class and all related input/output logic.

## Example: Adding a New Menu Option

1. Update `printMainMenu()` and `getUserSelectMainMenu()`.
2. Add a new `case` in the main `switch` in `main()`.
3. Implement the new feature as a function.

## Notes

- All user input is via `std::cin` and output via `std::cout`.
- The code is intended for educational purposes and is kept simple for clarity.

---

If you add new files or major features, update this file to document new conventions or workflows.
