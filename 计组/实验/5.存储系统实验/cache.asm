#file��cache.asm
#  This program accesses an array in ways that provide data about the cache parameters.
#  ������ͨ��MARS����Cache������������ڴ���ʿ��ӻ��������ѧ�����
#  cache������cache���ܵ�Ӱ��
#  ��������Ĺ��ܿ��Բο�����C����α����
#    int array[];                            //��������λ4�ֽ�
#    for (k = 0; k < repcount; k++) {	// repcount����ѭ������
#     ��������Ԫ�أ� ���������Щ����Ԫ��ȡ���ڲ���stepsize. */
#      for (index = 0; index < arraysize; index += stepsize) {
#        if(option==0)
#          array[index] = 0;		// Option 0: �漰һ������д
#        else
#          array[index] = array[index] + 1;  // Option 1: �漰����������ʣ���д��һ��
#      }
#    }
	.data
array:	.space    2048                 # array��������ֽڿռ䣬�����޸�
	.text                          #����ο�ʼ
##############################################################################################
# ���¼Ӵ���ֵ�����û��������е��� 
main:	li	$a0, 256		# ����ʵ���ֽڴ�С (Ӧ��2���ݴη���С�ڵ���2048)
	li	$a1, 2		# step size  (Ӧ��2���ݴη�)
	li	$a2, 1		# rep count  ѭ��������Ӧ�ô���0
	li	$a3, 1		# �ô淽ʽ 0 - option 0, 1 - option 1  
##############################################################################################
	jal	accessWords	# lw/sw
	#jal	accessBytes	# lb/sb	
	li	$v0,10		# exit
	syscall
# �����мĴ���ʹ��˵��:
#  $a0 = array size����ʵ���ֽڴ�С
#  $a1 = step size ������ʲ���
#  $a2 = number of times to repeat ����ѭ�����ʴ���
#  $a3 = 0 (W) / 1 (RW)  �ô淽ʽ
#  $s0 = moving array ptr  ���黬��ָ��
#  $s1 = array limit (ptr)  ��������Ͻ�ָ��
	
accessWords:
	la	$s0, array		# ptr to array
	addu	$s1, $s0, $a0		# hardcode array limit (ptr)
	sll	$t1, $a1, 2		# multiply stepsize by 4 because WORDS
wordLoop:
	beq	$a3, $0,  wordZero
	lw	$t0, 0($s0)		# array[index/4]++
	addi	$t0, $t0, 1
	sw	$t0, 0($s0)
	j	wordCheck
wordZero:	
	sw	$0,  0($s0)		# array[index/4] = 0
wordCheck:
	addu	$s0, $s0, $t1		# increment ptr
	blt	$s0,$s1,wordLoop  # inner loop done?
	addi	$a2, $a2, -1
	bgtz	$a2, accessWords     	# outer loop done?
	jr	$ra
accessBytes:
	la	$s0, array		               # ptr to array
	addu	$s1, $s0, $a0		# hardcode array limit (ptr)
byteLoop:
	beq	$a3, $0,  byteZero
	lbu	$t0, 0($s0)		# array[index]++
	addi	$t0, $t0, 1
	sb	$t0, 0($s0)
	j	byteCheck
byteZero:	
	sb	$0,  0($s0)		# array[index] = 0
byteCheck:
	addu	$s0, $s0, $a1		# increment ptr
	blt	$s0,$s1,byteLoop	               # inner loop done?
	addi	$a2, $a2, -1
	bgtz	$a2, accessBytes	               # outer loop done?
	jr	$ra
