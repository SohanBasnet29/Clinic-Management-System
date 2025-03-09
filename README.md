# Clinic Management System

This is a C++ based Clinic Management System designed to manage patient records, including personal details, medical history, and appointment data.

## Features
- **Admin Management:**
  - Secure admin login with multiple attempts protection.
  - Add, update, delete, and search patient records.
  - Manage patient data including symptoms, diagnosis, medicines, and past diseases.

- **Patient Management:**
  - Store and retrieve patient details such as age, gender, blood group, and contact information.
  - Record admission details and medical history.

## Technologies Used
- Programming Language: C++
- File Handling: `.dat` file for patient record storage
- Libraries: `<iostream>`, `<fstream>`, `<string.h>`, `<ctime>`

## Project Structure
- **Main File:** `clinicmanagementsystem.cpp`
- **Class:**
  - `admin`: Handles all patient data management and file handling.
- **Functions:**
  - `add_record()`: Add a new patient.
  - `delete_record()`: Remove a patient record.
  - `updatedata()`: Update patient information.
  - `search_by_id()`: Search for a patient using their ID.

## How to Run
1. Compile the program using a C++ compiler:
   ```bash
   g++ clinicmanagementsystem.cpp -o clinic_management
   ```
2. Run the executable:
   ```bash
   ./clinic_management
   ```
3. Follow the prompts for admin login and data management.

## Admin Credentials (Default)
- **Username:** `khwopa`
- **Password:** `khwopa123`


