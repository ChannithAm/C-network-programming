======================================
១៥០. បញ្ចូល និងបង្ហាញពត័មានបុគ្គលិក
======================================

.. contents::
    :local:
    :depth: 1

លំហាត់ទី១៥០
============
សរសេរកម្មវិធីភាសាC ក្នុងនោះ ត្រូវបញ្ចូលពត័មានពីបុគ្គលិក​ និងបង្ហាញពត័មានបុគ្គលិកនៅលើscreen
ដោយប្រើstucture។ ពត័មានដូចជា id, name, designation, department, salary។

Source
~~~~~~~
.. literalinclude:: code/ex150.c
    :language: C

Output
~~~~~~~
.. code-block:: text

    Enter employee details: 
    -----------------------------------
    Enter employee-id: 2313
    Enter name  :Channith
    Enter designation : Manager
    Enter department: Production
    Enter salary        : 30000
    ---------------------------------
    Employee details:
    ---------------------------------
    Name        : Channith
    Designation : Manager
    Department  : Production
    Salary      : 30000
