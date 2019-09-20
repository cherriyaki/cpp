# 5CCS2PEP - C++ coursework

Welcome back!  This is your GitHub repository for working on the first half of 5CCS2PEP, in which Andrew will be teaching C++.

# What is Practical Experiences of Programming?

A common practical experience of programming, amongst professional software developers, is the need to work with new technologies that one does not have direct prior experience of.  It's still programming, but one needs to adapt ones skills to a new setting.

This is exactly what you can expect on this module.  We put PEP at this point in your degree programme as you have a year's experience of Java (from PPA) and other programming knowledge (e.g. from DST), and are now in a good position to try something different.  I'll be teaching you C++, which is similar in many ways to Java, but has some important differences; Christian will be teaching you Scala, which is even more different.

# What will we actually be doing on this module?

Because professional programmers spend their time writing code, not so much sitting exams, *this module is assessed 100% by coursework*.  Each week in the lectures we'll go over some language features, and each week you have a lab session where you can ask the TAs questions for additional support.

There's a small amount of 'Preliminary' work due in each week, with the rest (the 'Core' work) due in after reading week (for C++) or in January (for Scala).  For best results, do more than the bare minimum each week, as that way you can make use of the support you have available during term (see the next section).

# How can I get help?

As noted above, you have a weekly lab session.  The lab TAs on this module are excellent, so make sure you use this time well -- start your work before the lab, so you already have questions to ask the TAs when you arrive.

In addition to this, we have a KEATS discussion forum where you can ask further questions about the languages you are learning, or to clarify the coursework questions.  This is the best place to ask questions, as if we give additional help or advice, all the students in the class can benefit.

The module lecturers have weekly office hours, which you are encouraged to use.  You can get detailed, individual feedback on your work this way; and it also helps us know what students have found challenging, so we can recap materials in the lectures.

Finally, there's email.  It's there, but it's often not the best solution.  Basic queries should go to the KEATS forum so the whole class can benefit from the answer; we may decline to answer such questions via email, in the interests of fairness, so post to KEATS to start with.  Additional feedback on your work is most effectively done in person -- either with the TAs in the labs, or in our office hours.  Anything else?  Go ahead and email.  (I'm not being grumpy, I just want to make sure things run smoothly for everyone.)

# Workflow for this module

## How do I use this GitHub repository?

In each directory, you'll find questions to work on.  Take a `clone` of this repository from GitHub; then to submit work, `commit` and `push` to send your work back to GitHub.  You can (and should) commit and push your work as many times as you'd like.

Whenever there is a deadline:

- A `clone` of your repository will be taken, and the appropriate work marked.  This is your *on time* mark.
- 24 hours later, another `clone` of your repository will be taken, and the appropriate work marked again.  This is your *late* mark, and will be capped at 40%.

The mark you will be awarded is then the *best* of either your on time mark, or your capped late mark.  The word best here is important -- if you push some work after the deadline, don't worry, your on-time work was cloned at the deadline, and will be marked uncapped.

Make sure you don't commit any compiled code to your GitHub repository; or if you choose to use an IDE, any large project directories created by your IDE.  You can make these on your machine, but don't `commit` or `add` them to your repository -- this isn't what git is designed for.  Source code for extra code you've written is fine, `make' files, text files, etc. -- good.  Compiled code or auto-generated project directories -- bad.

## How we mark your code

Each question gives you a specification for some code, and some basic test cases.  To mark your work, we will run your code with a different, larger range of test cases; each of these has a mark attached that is used to then give the mark to your work.  Your feedback for the work will be an test report detailing each of the test cases used, whether the test passed or failed, and/or other diagnostic information.  For additional feedback, you're welcome to discuss the work with the lab TAs, or in office hours.

With reference to the module title -- we mark work using test cases, because writing code that fulfils a given specification, and passes some given test cases, is an important practical experience of programming.  Also important is writing test cases -- you're encouraged to write your own to be additionally confident in your code, as whilst the test cases we have given you are helpful, they're not exhaustive.

We won't be marking whether your code has comments or is correctly indented, but you are encouraged to keep good habits.  As noted above ('How do I use this GitHub repository?') don't add compiled code or large project directories to your GitHub repository; your mark for a given assignment may be multiplied by 0.9 where such files are added and are excessive in size.  The following are examples of what *may* be added to your repository:

- The source code for additional test cases you've written yourself
- Simple 'make' files (e.g. if you write a Makefile or CMakeLists.txt file)
- A text file containing a to-do list, or other working notes
- A `.gitignore` file or `.gitattributes` file

The following are examples of what may not be added:

- Compiled code -- `.class` files (for the Warmup exercises), compiled executable files, `.o` or `.obj` files, debugging symbols (e.g. `.ipch` files)
- `.idea` directories
- `foo.dSYM` directories, as created by XCode for the executable `foo`
- `.DS_Store` files
- `CMakeCache.txt`, `CMakeFiles`, etc. as created when CMake compiles a project
- `.vs` directories, as made by VSCode

If you're not sure what you can add, ask in the KEATS forum.

Otherwise, watch out for where questions impose conditions on the code you write (e.g. that you must not add extra `#include` statements), as you'll only get the marks if you meet these conditions. 

# Schedule of C++ coursework

There are five assignments on the C++ part of the module:

- Preliminary 1.  This is worth 3 marks (3% of the module), and is due at 4pm on the 2nd of October.
- Preliminary 2.  This is worth 3 marks (3% of the module), and is due at 4pm on the 9th of October.
- Preliminary 3.  This is worth 3 marks (3% of the module), and is due at 4pm on the 16th of October.
- Preliminary 4.  This is worth 3 marks (3% of the module), and is due at 4pm on the 23rd of October.
- Core.  This is worth 33 marks (33% of the module), and is due at 4pm on the 6th of November (in the week after reading week).

This GitHub repository contains all of these assignments.  Here's what in each directory:

- `Warmup`: in this directory are some Java questions.  These don't count towards your module mark, but allow you to get used to working with GitHub in the first lab.
- `Part1`: This directory contains Preliminary 1, and some Core work.  You can start this after the first lecture.
- `Part2`: This directory contains Preliminary 2, and some Core work.  You can start this after the second lecture; or if you're ambitious, after the first lecture.
- `Part3`: This directory contains Preliminary 3, and some Core work.  You can start this after the third lecture.
- `Part4`: This directory contains Preliminary 4, and some Core work.  You can start this after the fourth lecture.
- `Part5`: This directory contains only Core work. You can start some of this after the fourth lecture, but the fifth lecture covers inheritance, which is needed in the later parts.

Even though the Core work is all due in after reading week, you're heavily advised to do some of it each week and not leave it all 'til the deadline.

Note there is no prescribed C++ IDE.  I'll be using a text editor, a command-line compiler (g++), and where appropriate a debugger (GDB) and a tool for checking for memory errors (valgrind).  All of these are installed on the lab machines.  If you're happier using an IDE, you're welcome to do so.

# Lessons learnt from previous years

We've taught this module for a number of years now.  Here are hints for you based on the experiences of students in previous years:

## 1) Don't cheat

In this module, everything should be your own work -- no plagiarism (e.g. copy-pasting from websites), no collusion (e.g. working with or sharing code with another student).  By pushing work to GitHub, you are submitting work for assessment, and making a statement that the submission is your own work.

We have effective tools in place for detecting plagiarism and collusion, so if you're thinking of copying code, don't think you can get away with it by e.g. renaming a few variables.  Any plagiarism or collusion we find will be dealt with under the College procedures.

## 2) Actually use git

GitHub has a built in text editor, which allows you to edit files in your GitHub repository without following the clone, commit, push workflow I mention above.  *This is a really bad idea.*  Use git, and get used to using git.  That way you can compile and run your code on your machine.

As a cheat-sheat for git at the command line:

- `git clone <url>`  will clone (i.e. copy to your machine) the given GitHub repository
- `git commit -a` will commit all the files you've modified since you last made a commit, i.e. save a copy of your work to the version history on your machine
- `git push` will push this work back to GitHub.

There are GUI tools and other interfaces for GitHub, but at least in this module, you won't be using the fancier features of git that support teamwork, so the above three commands will do most of what you need.

## 3) Don't forget to push

`git commit -a` stores all modified files in the git version history (repository) on your machine.  `git push` sends anything you've committed to GitHub.  If you don't push, you haven't submitted your work, and I can't mark it.

## 4) Commit and push regularly

Every time you've done a small part of an assignment and you're happy with it, commit and push.  That way, GitHub has taken a backup of your work.  If you then screw up your code, you can go back to the version in GitHub.  If you drop your laptop in the Thames, you at least have a version on GitHub, to clone onto another machine and keep working on.  One day, you'll have a major data loss, and wish you'd taken backups.

## 5) Don't change your GitHub username part way through term

We need to know which GitHub is yours so you get the marks.  If you change your GitHub username we don't know which is your work, so you get a zero.  I don't mind if you have another GitHub username that you use for other purposes, but keep the same one for PEP.

## 6) The coursework covers the full range of marks

On each module you take at King's, the marks awarded to the class will cover the full range.  This ensures academic standards are maintained, and hence the value of your degree.  If a module is 100% exam, the exam will contain questions of varying difficulty, including some challenging questions that only the most able students can answer (or can answer well).  This module is 100% coursework, so the same applies here -- the coursework has challenging questions, and the overall marks cover the full range.

I mention this as this may be different to your expectations from other modules.  For instance, for modules that are 15% coursework and 85% exam, sometimes the coursework is relatively easier than the exam; e.g. a student might get 90% in the coursework and 65% in the exam.  This is okay -- it just means the exam has the challenging questions needed to ensure the overall marks cover the full range.  But remember, in PEP, we don't have an exam: all the challenge for the module is in the coursework.  Hence, your coursework marks might be lower than you'd expect from a 15%-coursework-modules, but it doesn't mean you're doing badly (or that we're being unfair).

