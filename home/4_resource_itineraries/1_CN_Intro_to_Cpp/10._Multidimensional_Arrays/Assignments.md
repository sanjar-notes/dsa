# Assignments
Created Saturday 21 December 2019

The remove duplicate and compress strings algos can be done in a single scan.
**The idea: A writing head, borrowed from COA.**
For remove duplicate:
Make a left and a rigth pointer, the left will indicate the current (which has not yet been written).
Find a diffrent letter(it could be EOS), just write the *left to wr
left =right, coz we are done with the currnt letter, let's start with the different letter found(EOS case has been handled).
 Move wr by 1, for a fresh writing.
The next iteration begins, if we had reached EOS, we stop, else we continue;

For compression(in 1 go):
make a count variable.
Set left = head, right = head, wr = head;
Look for a number or change of character. add count.
If count > 2;
Just write *wr = *left, wr ++;
*wr = count+48, wr++; 
If count < 1, i.e we found an a different chararacter
*wr = *left;
	
left = right; we are done with the present  charcter let's look at the difference.
**The catch, as we have already noted down everything neatly of the previous part, so no need to think of that now. So no number checking.**
**As and when we catch EOS as difference, we do the needful for the present char+number or char. The EOS is taken care of in the while loop. No worries.**


* Lessons learnt, do the problem in a go.
* Don't process in steps, as we have to keep track of everything we did, which is painstaking and costly too. 
* Use what is efficient and working, rather than going for ideals.
* Make a special case seem a general case by including it in the condition, but after the current process.





