==================================
Test - Lab 
==================================

.. contents::
    :local:
    :depth: 2

Lab - 1
========

សរសេរកម្មវិធីអនុវត្តន៍កិច្ចការខាងក្រោម៖

#. បញ្ចូលarrayមួយមានចំនួនN ជាចំនួនគត់ (0 < N < 10 ) បញចូលពីkeyboard។
   បង្ហាញចំនួនទាំងនោះលើscreen នូវចំនួនទើបតែបានបញ្ចូលនេះ។
#. បញ្ចលលេខ x (x > 0) ណាមួយពីkeyboard។

    #. ប្រសិនបើ x <= N: គណនាផលបូកជាមធ្យម នៃចំនួនxលេខតម្បូង។
    #. ប្រសិនបើ x > N: គណនាផលបូកសរុបនៃចំនួនទាំងនោះ?

បង្ហាញចំនួនទាំងនោះលើscreen។ (ត្រូវត្រួតពិនិត្យលក្ខខណ្ឌinput) 

Solution
~~~~~~~~

.. literalinclude:: code/test-lab/lab1.c
    :language: C

Output
~~~~~~~
.. code-block:: text

    Enter value of N = 5

    Enter element of array A[5]
    A[1]: 2
    A[2]: 3
    A[3]: 4
    A[4]: 5
    A[5]: 5
    Array of A is : 2	3	4	5	5	
    Enter value of x = 8
    Sum of array A is : 19


Lab - 2
========

សរសេរកម្មវិធីអនុវត្តន៍កិច្ចការខាងក្រោម៖

#. បញ្ចូលarrayមួយ ជាលេខចំនួនគត់ណាក៏ដោយពីkeyboard។
   ការបញ្ចូលត្រូវបានបញ្ឈប់នៅពេលដែលចំនួនធាតុមាន៧ ឫបញ្ចូលលេខ០
   ដែលលេខ០មិនមែនជាធាតុក្នុងarray។

   #. បង្ហាញចំនួនទាំងនោះលើscreenទម្រង់ជាសេរី។
   #. តម្រៀបវាជាលំដាប់កើន និង​ បង្ហាញចំនួនទាំងនោះលើscreen។

Solution
~~~~~~~~~
.. literalinclude:: code/test-lab/lab2.c
    :language: C


Output
~~~~~~~
.. code-block:: text

    A[1] : 3
    A[2] : 5
    A[3] : 1
    A[4] : 9
    A[5] : 4
    A[6] : 0

    The array A is : 3	5	1	9	4	
    Array after re-arange (increase): 1	   3	4	5	9

Lab - 3
=========

សរសេរកម្មវិធីអនុវត្តន៍កិច្ចការខាងក្រោម៖

#. បញ្ចលលេខn ជាចំនួនគត់ ពីkeyboard(0<n<10)។
#. បញ្ចូលarrayមួយមានចំនួនNធាតុ ជាចំនួនពិត។ បង្ហាញចំនួនទាំងនោះលើscreenទម្រង់ជាសេរី។
#. ស្វែងរកចំនួនធំបំផុតនៅក្នុងarrayនោះ និងរាប់ចំនួនលេខដែលធំនៅក្នុងarray។ បង្ហាញចំនួនទាំងនោះលើscreen។

Solution
~~~~~~~~~
.. literalinclude:: code/test-lab/lab3.c
    :language: C

Output
~~~~~~~
.. code-block:: text

    Enter N = 9

    Enter Array A: 
    A[1] 	: 11 
    A[2] 	: 45
    A[3] 	: 0.34
    A[4] 	: 2
    A[5] 	: -34
    A[6] 	: 9
    A[7] 	: 45
    A[8] 	: 45
    A[9] 	: 6.7
    The array of A is : 11.00	45.00	0.34	2.00	-34.00	9.00	45.00	45.00	6.70	
    The maximum of Array is 45.00
    The number equal to max are : 3