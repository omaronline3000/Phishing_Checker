# Phishing Email Checker

This project is a simple console-based application written in C++ that analyzes a text file containing email content and detects potential phishing terms. Each phishing term has a score, and the program calculates a total phishing score for the email.

---

## Features
1. **Phishing Word Detection**:
   - Scans the email for predefined phishing terms stored in `phishing.txt`.
   - Counts the frequency of each phishing term in the email.

2. **Score Calculation**:
   - Assigns points to each phishing term based on its severity (points are defined in `phishing.txt`).
   - Calculates the total phishing score for the email.

3. **Interactive Input**:
   - Prompts the user to ensure the email is saved in `mail.txt` before running the analysis.

---

## How to Use
**Prepare Input Files**:
   - Create a file named `phishing.txt` with phishing words and their associated points. Example format:
     ```
     password 5
     bank 10
     transfer 8
     ```
   - Save the email content to a file named `mail.txt`.
