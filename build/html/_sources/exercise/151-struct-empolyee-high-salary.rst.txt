==================================
១៥១. រកប្រាក់ខែច្រើនបំផុតរបស់បុគ្គលិក
==================================

.. contents::
    :local:
    :depth: 1


លំហាត់ទី១៥១
============

សរសេរកម្មវិធីC ដើម្បីបញ្ចលពត័មានបុគ្គលិក(employee number, name, salary) និងបង្ហាញអ្នក
ដែលមានប្រាក់ខែខ្ពស់បំផុត ដោយប្រើប្រាស់structure។

Source
~~~~~~~
.. literalinclude:: code/ex151.c
    :language: C

Output
~~~~~~~
.. code-block:: text

    /*How many employee info
    you want to accepth : 
    Enter limit: 2

    ---------------------------------
    Enter details for 2 employees: 
    ---------------------------------
    Employee Number: 1
    Name           : Dara
    Salary         : 3900
    -----------------------------
    Employee Number: 2
    Name           : Sana   
    Salary         : 3400
    -----------------------------
    Highest salary employee details: 
    -------------------------------
    EMP_NO      NAME    SALARY

    1	Dara	3900