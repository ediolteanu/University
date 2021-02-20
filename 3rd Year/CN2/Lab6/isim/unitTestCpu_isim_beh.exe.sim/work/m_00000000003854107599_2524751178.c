/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/student/Documents/lab06_skel_v2/test_ldi.vh";
static int ng1[] = {1, 0};
static unsigned int ng2[] = {1U, 0U};
static int ng3[] = {2, 0};
static int ng4[] = {5, 0};
static int ng5[] = {22, 0, 0, 0};
static const char *ng6 = "LDI R%2d, %3d - ID: OK";
static unsigned int ng7[] = {1U, 1U};
static const char *ng8 = "LDI R%2d, %3d - ID: FAILED";
static int ng9[] = {3, 0};
static int ng10[] = {4, 0};
static const char *ng11 = "LDI R%2d, %3d - WB: OK (R%2d = %3d)";
static const char *ng12 = "LDI R%2d, %3d - WB: FAILED => (%3d) vs (%3d)";
static const char *ng13 = "C:/Users/student/Documents/lab06_skel_v2/test_in.vh";
static int ng14[] = {51, 0, 0, 0};
static const char *ng15 = "IN R%2d, %d - ID: FAILED, check opcode_type: %d vs %d";
static int ng16[] = {51, 0};
static const char *ng17 = "IN R%2d, %d - ID: FAILED, check opcode_rd: %d vs %d";
static const char *ng18 = "IN R%2d, %d - ID: FAILED, check opcode_imd: %d vs %d";
static int ng19[] = {14, 0};
static const char *ng20 = "IN R%2d, %d - ID: FAILED - IN instruction should be in GROUP_IO_READ";
static int ng21[] = {6, 0};
static const char *ng22 = "IN R%2d, %d - ID: FAILED, signal CONTROL_IO_READ should be active for IN instruction";
static const char *ng23 = "IN R%2d, %d - ID: FAILED, check bus_addr in bus_interface_unit.v: %d vs %d";
static const char *ng24 = "IN R%2d, %d - ID: OK";
static const char *ng25 = "IN R%2d, %d - WB: FAILED, signal CONTROL_REG_RD_WRITE should be active for IN instruction";
static const char *ng26 = "IN R%2d, %d - WB: FAILED, check writeback_value : %d vs %d";
static const char *ng27 = "IN R%2d, %d - WB: OK";
static const char *ng28 = "C:/Users/student/Documents/lab06_skel_v2/test_out.vh";
static int ng29[] = {52, 0, 0, 0};
static const char *ng30 = "OUT %d, R%2d - ID: FAILED, check opcode_type: %d vs %d";
static int ng31[] = {52, 0};
static const char *ng32 = "OUT %d, R%2d - ID: FAILED, check opcode_rr: %d vs %d";
static const char *ng33 = "OUT %d, R%2d - ID: FAILED, check opcode_imd: %d vs %d";
static int ng34[] = {15, 0};
static const char *ng35 = "OUT %d, R%2d - ID: FAILED - OUT instruction should be in GROUP_IO_WRITE";
static const char *ng36 = "OUT %d, R%2d - ID: FAILED, signal CONTROL_REG_RR_READ should be active for OUT instruction";
static int ng37[] = {7, 0};
static const char *ng38 = "OUT %d, R%2d - ID: FAILED, signal CONTROL_IO_WRITE should be active for OUT instruction";
static const char *ng39 = "OUT %d, R%2d - ID: FAILED, check bus_addr in bus_interface_unit.v: %d vs %d";
static const char *ng40 = "OUT %d, R%2d - ID: OK";
static const char *ng41 = " ";
static const char *ng42 = "C:/Users/student/Documents/lab06_skel_v2/unitTest.v";
static int ng43[] = {28, 0};
static int ng44[] = {29, 0};
static const char *ng45 = "Init regs..";
static unsigned int ng46[] = {255U, 255U};
static unsigned int ng47[] = {65535U, 65535U};
static unsigned int ng48[] = {31U, 31U};
static int ng49[] = {0, 0};
static unsigned int ng50[] = {28U, 0U};
static unsigned int ng51[] = {6U, 0U};
static int ng52[] = {17, 0};
static unsigned int ng53[] = {0U, 1U};



static int sp_TEST_LDI(char *t1, char *t2)
{
    char t10[8];
    char t15[8];
    char t31[16];
    char t32[8];
    char t40[8];
    char t72[8];
    char t90[8];
    char t106[8];
    char t114[8];
    char t154[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    char *t39;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    unsigned int t53;
    char *t54;
    char *t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    int t64;
    int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    char *t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    char *t79;
    char *t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    char *t84;
    char *t85;
    char *t86;
    char *t87;
    char *t88;
    char *t89;
    char *t91;
    char *t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    unsigned int t98;
    unsigned int t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    unsigned int t103;
    unsigned int t104;
    char *t105;
    char *t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    char *t113;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    char *t118;
    char *t119;
    char *t120;
    unsigned int t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    unsigned int t127;
    char *t128;
    char *t129;
    unsigned int t130;
    unsigned int t131;
    unsigned int t132;
    unsigned int t133;
    unsigned int t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    int t138;
    int t139;
    unsigned int t140;
    unsigned int t141;
    unsigned int t142;
    unsigned int t143;
    unsigned int t144;
    unsigned int t145;
    char *t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    char *t152;
    char *t153;
    char *t155;
    char *t156;
    char *t157;
    unsigned int t158;
    unsigned int t159;
    unsigned int t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    char *t165;
    unsigned int t166;
    unsigned int t167;
    unsigned int t168;
    unsigned int t169;
    unsigned int t170;
    char *t171;
    char *t172;

LAB0:    t0 = 1;
    xsi_set_current_line(4, ng0);

LAB2:    xsi_set_current_line(5, ng0);
    t3 = (t1 + 19992);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t6 = *((char **)t5);

LAB3:    t5 = ((char*)((ng1)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t5, 32);
    if (t7 == 1)
        goto LAB4;

LAB5:    t3 = ((char*)((ng3)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB6;

LAB7:    t3 = ((char*)((ng9)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB8;

LAB9:    t3 = ((char*)((ng10)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB10;

LAB11:    t3 = ((char*)((ng4)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB12;

LAB13:
LAB14:    t0 = 0;

LAB1:    return t0;
LAB4:    xsi_set_current_line(6, ng0);
    t8 = ((char*)((ng2)));
    t9 = (t1 + 7544);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 1);
    goto LAB14;

LAB6:    xsi_set_current_line(8, ng0);
    t4 = (t1 + 20032);
    t5 = *((char **)t4);
    t8 = ((((char*)(t5))) + 40U);
    t9 = *((char **)t8);
    t8 = (t1 + 20072);
    t11 = *((char **)t8);
    t12 = ((((char*)(t11))) + 72U);
    t13 = *((char **)t12);
    t14 = ((char*)((ng4)));
    xsi_vlog_generic_get_index_select_value(t10, 1, t9, t13, 2, t14, 32, 1);
    memset(t15, 0, 8);
    t16 = (t10 + 4);
    t17 = *((unsigned int *)t16);
    t18 = (~(t17));
    t19 = *((unsigned int *)t10);
    t20 = (t19 & t18);
    t21 = (t20 & 1U);
    if (t21 != 0)
        goto LAB15;

LAB16:    if (*((unsigned int *)t16) != 0)
        goto LAB17;

LAB18:    t23 = (t15 + 4);
    t24 = *((unsigned int *)t15);
    t25 = *((unsigned int *)t23);
    t26 = (t24 || t25);
    if (t26 > 0)
        goto LAB19;

LAB20:    memcpy(t40, t15, 8);

LAB21:    memset(t72, 0, 8);
    t73 = (t40 + 4);
    t74 = *((unsigned int *)t73);
    t75 = (~(t74));
    t76 = *((unsigned int *)t40);
    t77 = (t76 & t75);
    t78 = (t77 & 1U);
    if (t78 != 0)
        goto LAB29;

LAB30:    if (*((unsigned int *)t73) != 0)
        goto LAB31;

LAB32:    t80 = (t72 + 4);
    t81 = *((unsigned int *)t72);
    t82 = *((unsigned int *)t80);
    t83 = (t81 || t82);
    if (t83 > 0)
        goto LAB33;

LAB34:    memcpy(t114, t72, 8);

LAB35:    t146 = (t114 + 4);
    t147 = *((unsigned int *)t146);
    t148 = (~(t147));
    t149 = *((unsigned int *)t114);
    t150 = (t149 & t148);
    t151 = (t150 != 0);
    if (t151 > 0)
        goto LAB47;

LAB48:    xsi_set_current_line(16, ng0);

LAB51:    xsi_set_current_line(17, ng0);
    t3 = ((char*)((ng7)));
    t4 = (t1 + 7544);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(18, ng0);
    t3 = (t1 + 20232);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 20264);
    t9 = *((char **)t5);
    t11 = ((((char*)(t9))) + 40U);
    t12 = *((char **)t11);
    t11 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng8, 3, t11, (char)118, t8, 5, (char)118, t12, 12);

LAB49:    goto LAB14;

LAB8:    xsi_set_current_line(20, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 7544);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB14;

LAB10:    xsi_set_current_line(21, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 7544);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB14;

LAB12:    xsi_set_current_line(23, ng0);
    t4 = (t1 + 20304);
    t5 = *((char **)t4);
    t8 = ((((char*)(t5))) + 56U);
    t9 = *((char **)t8);
    t11 = (t1 + 7864);
    t12 = (t11 + 56U);
    t13 = *((char **)t12);
    memset(t10, 0, 8);
    t14 = (t9 + 4);
    t16 = (t13 + 4);
    t17 = *((unsigned int *)t9);
    t18 = *((unsigned int *)t13);
    t19 = (t17 ^ t18);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t16);
    t24 = (t20 ^ t21);
    t25 = (t19 | t24);
    t26 = *((unsigned int *)t14);
    t34 = *((unsigned int *)t16);
    t35 = (t26 | t34);
    t36 = (~(t35));
    t37 = (t25 & t36);
    if (t37 != 0)
        goto LAB55;

LAB52:    if (t35 != 0)
        goto LAB54;

LAB53:    *((unsigned int *)t10) = 1;

LAB55:    memset(t15, 0, 8);
    t23 = (t10 + 4);
    t38 = *((unsigned int *)t23);
    t41 = (~(t38));
    t42 = *((unsigned int *)t10);
    t43 = (t42 & t41);
    t47 = (t43 & 1U);
    if (t47 != 0)
        goto LAB56;

LAB57:    if (*((unsigned int *)t23) != 0)
        goto LAB58;

LAB59:    t28 = (t15 + 4);
    t48 = *((unsigned int *)t15);
    t49 = *((unsigned int *)t28);
    t50 = (t48 || t49);
    if (t50 > 0)
        goto LAB60;

LAB61:    memcpy(t72, t15, 8);

LAB62:    memset(t90, 0, 8);
    t87 = (t72 + 4);
    t97 = *((unsigned int *)t87);
    t98 = (~(t97));
    t99 = *((unsigned int *)t72);
    t100 = (t99 & t98);
    t101 = (t100 & 1U);
    if (t101 != 0)
        goto LAB70;

LAB71:    if (*((unsigned int *)t87) != 0)
        goto LAB72;

LAB73:    t89 = (t90 + 4);
    t102 = *((unsigned int *)t90);
    t103 = *((unsigned int *)t89);
    t104 = (t102 || t103);
    if (t104 > 0)
        goto LAB74;

LAB75:    memcpy(t154, t90, 8);

LAB76:    t165 = (t154 + 4);
    t166 = *((unsigned int *)t165);
    t167 = (~(t166));
    t168 = *((unsigned int *)t154);
    t169 = (t168 & t167);
    t170 = (t169 != 0);
    if (t170 > 0)
        goto LAB88;

LAB89:    xsi_set_current_line(35, ng0);

LAB92:    xsi_set_current_line(36, ng0);
    t3 = ((char*)((ng7)));
    t4 = (t1 + 7544);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(37, ng0);
    t3 = (t1 + 7704);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 7864);
    t9 = (t8 + 56U);
    t11 = *((char **)t9);
    t12 = (t1 + 20512);
    t13 = *((char **)t12);
    t14 = ((((char*)(t13))) + 56U);
    t16 = *((char **)t14);
    t22 = (t1 + 7864);
    t23 = (t22 + 56U);
    t27 = *((char **)t23);
    t28 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng12, 5, t28, (char)119, t5, 32, (char)119, t11, 32, (char)118, t16, 8, (char)119, t27, 32);

LAB90:    goto LAB14;

LAB15:    *((unsigned int *)t15) = 1;
    goto LAB18;

LAB17:    t22 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB18;

LAB19:    t27 = (t1 + 20104);
    t28 = *((char **)t27);
    t29 = ((((char*)(t28))) + 40U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng5)));
    xsi_vlog_unsigned_equal(t31, 51, t30, 51, t29, 32);
    memset(t32, 0, 8);
    t33 = (t31 + 4);
    t34 = *((unsigned int *)t33);
    t35 = (~(t34));
    t36 = *((unsigned int *)t31);
    t37 = (t36 & t35);
    t38 = (t37 & 1U);
    if (t38 != 0)
        goto LAB22;

LAB23:    if (*((unsigned int *)t33) != 0)
        goto LAB24;

LAB25:    t41 = *((unsigned int *)t15);
    t42 = *((unsigned int *)t32);
    t43 = (t41 & t42);
    *((unsigned int *)t40) = t43;
    t44 = (t15 + 4);
    t45 = (t32 + 4);
    t46 = (t40 + 4);
    t47 = *((unsigned int *)t44);
    t48 = *((unsigned int *)t45);
    t49 = (t47 | t48);
    *((unsigned int *)t46) = t49;
    t50 = *((unsigned int *)t46);
    t51 = (t50 != 0);
    if (t51 == 1)
        goto LAB26;

LAB27:
LAB28:    goto LAB21;

LAB22:    *((unsigned int *)t32) = 1;
    goto LAB25;

LAB24:    t39 = (t32 + 4);
    *((unsigned int *)t32) = 1;
    *((unsigned int *)t39) = 1;
    goto LAB25;

LAB26:    t52 = *((unsigned int *)t40);
    t53 = *((unsigned int *)t46);
    *((unsigned int *)t40) = (t52 | t53);
    t54 = (t15 + 4);
    t55 = (t32 + 4);
    t56 = *((unsigned int *)t15);
    t57 = (~(t56));
    t58 = *((unsigned int *)t54);
    t59 = (~(t58));
    t60 = *((unsigned int *)t32);
    t61 = (~(t60));
    t62 = *((unsigned int *)t55);
    t63 = (~(t62));
    t64 = (t57 & t59);
    t65 = (t61 & t63);
    t66 = (~(t64));
    t67 = (~(t65));
    t68 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t68 & t66);
    t69 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t69 & t67);
    t70 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t70 & t66);
    t71 = *((unsigned int *)t40);
    *((unsigned int *)t40) = (t71 & t67);
    goto LAB28;

LAB29:    *((unsigned int *)t72) = 1;
    goto LAB32;

LAB31:    t79 = (t72 + 4);
    *((unsigned int *)t72) = 1;
    *((unsigned int *)t79) = 1;
    goto LAB32;

LAB33:    t84 = (t1 + 20136);
    t85 = *((char **)t84);
    t86 = ((((char*)(t85))) + 40U);
    t87 = *((char **)t86);
    t86 = (t1 + 7864);
    t88 = (t86 + 56U);
    t89 = *((char **)t88);
    memset(t90, 0, 8);
    t91 = (t87 + 4);
    t92 = (t89 + 4);
    t93 = *((unsigned int *)t87);
    t94 = *((unsigned int *)t89);
    t95 = (t93 ^ t94);
    t96 = *((unsigned int *)t91);
    t97 = *((unsigned int *)t92);
    t98 = (t96 ^ t97);
    t99 = (t95 | t98);
    t100 = *((unsigned int *)t91);
    t101 = *((unsigned int *)t92);
    t102 = (t100 | t101);
    t103 = (~(t102));
    t104 = (t99 & t103);
    if (t104 != 0)
        goto LAB39;

LAB36:    if (t102 != 0)
        goto LAB38;

LAB37:    *((unsigned int *)t90) = 1;

LAB39:    memset(t106, 0, 8);
    t107 = (t90 + 4);
    t108 = *((unsigned int *)t107);
    t109 = (~(t108));
    t110 = *((unsigned int *)t90);
    t111 = (t110 & t109);
    t112 = (t111 & 1U);
    if (t112 != 0)
        goto LAB40;

LAB41:    if (*((unsigned int *)t107) != 0)
        goto LAB42;

LAB43:    t115 = *((unsigned int *)t72);
    t116 = *((unsigned int *)t106);
    t117 = (t115 & t116);
    *((unsigned int *)t114) = t117;
    t118 = (t72 + 4);
    t119 = (t106 + 4);
    t120 = (t114 + 4);
    t121 = *((unsigned int *)t118);
    t122 = *((unsigned int *)t119);
    t123 = (t121 | t122);
    *((unsigned int *)t120) = t123;
    t124 = *((unsigned int *)t120);
    t125 = (t124 != 0);
    if (t125 == 1)
        goto LAB44;

LAB45:
LAB46:    goto LAB35;

LAB38:    t105 = (t90 + 4);
    *((unsigned int *)t90) = 1;
    *((unsigned int *)t105) = 1;
    goto LAB39;

LAB40:    *((unsigned int *)t106) = 1;
    goto LAB43;

LAB42:    t113 = (t106 + 4);
    *((unsigned int *)t106) = 1;
    *((unsigned int *)t113) = 1;
    goto LAB43;

LAB44:    t126 = *((unsigned int *)t114);
    t127 = *((unsigned int *)t120);
    *((unsigned int *)t114) = (t126 | t127);
    t128 = (t72 + 4);
    t129 = (t106 + 4);
    t130 = *((unsigned int *)t72);
    t131 = (~(t130));
    t132 = *((unsigned int *)t128);
    t133 = (~(t132));
    t134 = *((unsigned int *)t106);
    t135 = (~(t134));
    t136 = *((unsigned int *)t129);
    t137 = (~(t136));
    t138 = (t131 & t133);
    t139 = (t135 & t137);
    t140 = (~(t138));
    t141 = (~(t139));
    t142 = *((unsigned int *)t120);
    *((unsigned int *)t120) = (t142 & t140);
    t143 = *((unsigned int *)t120);
    *((unsigned int *)t120) = (t143 & t141);
    t144 = *((unsigned int *)t114);
    *((unsigned int *)t114) = (t144 & t140);
    t145 = *((unsigned int *)t114);
    *((unsigned int *)t114) = (t145 & t141);
    goto LAB46;

LAB47:    xsi_set_current_line(11, ng0);

LAB50:    xsi_set_current_line(12, ng0);
    t152 = ((char*)((ng2)));
    t153 = (t1 + 7544);
    xsi_vlogvar_assign_value(t153, t152, 0, 0, 1);
    xsi_set_current_line(13, ng0);
    t3 = (t1 + 20168);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 20200);
    t9 = *((char **)t5);
    t11 = ((((char*)(t9))) + 40U);
    t12 = *((char **)t11);
    t11 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng6, 3, t11, (char)118, t8, 5, (char)118, t12, 12);
    goto LAB49;

LAB54:    t22 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t22) = 1;
    goto LAB55;

LAB56:    *((unsigned int *)t15) = 1;
    goto LAB59;

LAB58:    t27 = (t15 + 4);
    *((unsigned int *)t15) = 1;
    *((unsigned int *)t27) = 1;
    goto LAB59;

LAB60:    t29 = (t1 + 20336);
    t30 = *((char **)t29);
    t33 = ((((char*)(t30))) + 40U);
    t39 = *((char **)t33);
    t33 = (t1 + 20368);
    t44 = *((char **)t33);
    t45 = ((((char*)(t44))) + 72U);
    t46 = *((char **)t45);
    t54 = ((char*)((ng4)));
    xsi_vlog_generic_get_index_select_value(t32, 1, t39, t46, 2, t54, 32, 1);
    memset(t40, 0, 8);
    t55 = (t32 + 4);
    t51 = *((unsigned int *)t55);
    t52 = (~(t51));
    t53 = *((unsigned int *)t32);
    t56 = (t53 & t52);
    t57 = (t56 & 1U);
    if (t57 != 0)
        goto LAB63;

LAB64:    if (*((unsigned int *)t55) != 0)
        goto LAB65;

LAB66:    t58 = *((unsigned int *)t15);
    t59 = *((unsigned int *)t40);
    t60 = (t58 & t59);
    *((unsigned int *)t72) = t60;
    t79 = (t15 + 4);
    t80 = (t40 + 4);
    t84 = (t72 + 4);
    t61 = *((unsigned int *)t79);
    t62 = *((unsigned int *)t80);
    t63 = (t61 | t62);
    *((unsigned int *)t84) = t63;
    t66 = *((unsigned int *)t84);
    t67 = (t66 != 0);
    if (t67 == 1)
        goto LAB67;

LAB68:
LAB69:    goto LAB62;

LAB63:    *((unsigned int *)t40) = 1;
    goto LAB66;

LAB65:    t73 = (t40 + 4);
    *((unsigned int *)t40) = 1;
    *((unsigned int *)t73) = 1;
    goto LAB66;

LAB67:    t68 = *((unsigned int *)t72);
    t69 = *((unsigned int *)t84);
    *((unsigned int *)t72) = (t68 | t69);
    t85 = (t15 + 4);
    t86 = (t40 + 4);
    t70 = *((unsigned int *)t15);
    t71 = (~(t70));
    t74 = *((unsigned int *)t85);
    t75 = (~(t74));
    t76 = *((unsigned int *)t40);
    t77 = (~(t76));
    t78 = *((unsigned int *)t86);
    t81 = (~(t78));
    t64 = (t71 & t75);
    t65 = (t77 & t81);
    t82 = (~(t64));
    t83 = (~(t65));
    t93 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t93 & t82);
    t94 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t94 & t83);
    t95 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t95 & t82);
    t96 = *((unsigned int *)t72);
    *((unsigned int *)t72) = (t96 & t83);
    goto LAB69;

LAB70:    *((unsigned int *)t90) = 1;
    goto LAB73;

LAB72:    t88 = (t90 + 4);
    *((unsigned int *)t90) = 1;
    *((unsigned int *)t88) = 1;
    goto LAB73;

LAB74:    t91 = (t1 + 20392);
    t92 = *((char **)t91);
    t105 = ((((char*)(t92))) + 40U);
    t107 = *((char **)t105);
    t105 = (t1 + 7704);
    t113 = (t105 + 56U);
    t118 = *((char **)t113);
    memset(t106, 0, 8);
    t119 = (t107 + 4);
    t120 = (t118 + 4);
    t108 = *((unsigned int *)t107);
    t109 = *((unsigned int *)t118);
    t110 = (t108 ^ t109);
    t111 = *((unsigned int *)t119);
    t112 = *((unsigned int *)t120);
    t115 = (t111 ^ t112);
    t116 = (t110 | t115);
    t117 = *((unsigned int *)t119);
    t121 = *((unsigned int *)t120);
    t122 = (t117 | t121);
    t123 = (~(t122));
    t124 = (t116 & t123);
    if (t124 != 0)
        goto LAB80;

LAB77:    if (t122 != 0)
        goto LAB79;

LAB78:    *((unsigned int *)t106) = 1;

LAB80:    memset(t114, 0, 8);
    t129 = (t106 + 4);
    t125 = *((unsigned int *)t129);
    t126 = (~(t125));
    t127 = *((unsigned int *)t106);
    t130 = (t127 & t126);
    t131 = (t130 & 1U);
    if (t131 != 0)
        goto LAB81;

LAB82:    if (*((unsigned int *)t129) != 0)
        goto LAB83;

LAB84:    t132 = *((unsigned int *)t90);
    t133 = *((unsigned int *)t114);
    t134 = (t132 & t133);
    *((unsigned int *)t154) = t134;
    t152 = (t90 + 4);
    t153 = (t114 + 4);
    t155 = (t154 + 4);
    t135 = *((unsigned int *)t152);
    t136 = *((unsigned int *)t153);
    t137 = (t135 | t136);
    *((unsigned int *)t155) = t137;
    t140 = *((unsigned int *)t155);
    t141 = (t140 != 0);
    if (t141 == 1)
        goto LAB85;

LAB86:
LAB87:    goto LAB76;

LAB79:    t128 = (t106 + 4);
    *((unsigned int *)t106) = 1;
    *((unsigned int *)t128) = 1;
    goto LAB80;

LAB81:    *((unsigned int *)t114) = 1;
    goto LAB84;

LAB83:    t146 = (t114 + 4);
    *((unsigned int *)t114) = 1;
    *((unsigned int *)t146) = 1;
    goto LAB84;

LAB85:    t142 = *((unsigned int *)t154);
    t143 = *((unsigned int *)t155);
    *((unsigned int *)t154) = (t142 | t143);
    t156 = (t90 + 4);
    t157 = (t114 + 4);
    t144 = *((unsigned int *)t90);
    t145 = (~(t144));
    t147 = *((unsigned int *)t156);
    t148 = (~(t147));
    t149 = *((unsigned int *)t114);
    t150 = (~(t149));
    t151 = *((unsigned int *)t157);
    t158 = (~(t151));
    t138 = (t145 & t148);
    t139 = (t150 & t158);
    t159 = (~(t138));
    t160 = (~(t139));
    t161 = *((unsigned int *)t155);
    *((unsigned int *)t155) = (t161 & t159);
    t162 = *((unsigned int *)t155);
    *((unsigned int *)t155) = (t162 & t160);
    t163 = *((unsigned int *)t154);
    *((unsigned int *)t154) = (t163 & t159);
    t164 = *((unsigned int *)t154);
    *((unsigned int *)t154) = (t164 & t160);
    goto LAB87;

LAB88:    xsi_set_current_line(26, ng0);

LAB91:    xsi_set_current_line(27, ng0);
    t171 = ((char*)((ng2)));
    t172 = (t1 + 7544);
    xsi_vlogvar_assign_value(t172, t171, 0, 0, 1);
    xsi_set_current_line(28, ng0);
    t3 = (t1 + 20416);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 20448);
    t9 = *((char **)t5);
    t11 = ((((char*)(t9))) + 40U);
    t12 = *((char **)t11);
    t11 = (t1 + 20472);
    t13 = *((char **)t11);
    t14 = ((((char*)(t13))) + 40U);
    t16 = *((char **)t14);
    t14 = (t1 + 7864);
    t22 = (t14 + 56U);
    t23 = *((char **)t22);
    t27 = (t1 + 848);
    xsi_vlogfile_write(1, 0, 0, ng11, 5, t27, (char)118, t8, 5, (char)118, t12, 12, (char)118, t16, 5, (char)119, t23, 32);
    goto LAB90;

}

static int sp_TEST_IN(char *t1, char *t2)
{
    char t10[8];
    char t11[16];
    char t28[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    char *t31;

LAB0:    t0 = 1;
    xsi_set_current_line(5, ng13);

LAB2:    xsi_set_current_line(6, ng13);
    t3 = (t1 + 20544);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t6 = *((char **)t5);

LAB3:    t5 = ((char*)((ng1)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t5, 32);
    if (t7 == 1)
        goto LAB4;

LAB5:    t3 = ((char*)((ng3)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB6;

LAB7:    t3 = ((char*)((ng9)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB8;

LAB9:    t3 = ((char*)((ng10)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB10;

LAB11:    t3 = ((char*)((ng4)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB12;

LAB13:
LAB14:    t0 = 0;

LAB1:    return t0;
LAB4:    xsi_set_current_line(8, ng13);
    t8 = ((char*)((ng2)));
    t9 = (t1 + 8024);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 1);
    goto LAB14;

LAB6:    xsi_set_current_line(10, ng13);
    t4 = (t1 + 20576);
    t5 = *((char **)t4);
    t8 = ((((char*)(t5))) + 40U);
    t9 = *((char **)t8);
    t8 = ((char*)((ng14)));
    xsi_vlog_unsigned_case_eq(t11, 51, t9, 51, t8, 32);
    memset(t10, 0, 8);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB18;

LAB16:    if (*((unsigned int *)t12) == 0)
        goto LAB15;

LAB17:    t18 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t18) = 1;

LAB18:    t19 = (t10 + 4);
    t20 = *((unsigned int *)t19);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB19;

LAB20:    xsi_set_current_line(17, ng13);
    t3 = (t1 + 20640);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 8344);
    t9 = (t5 + 56U);
    t12 = *((char **)t9);
    memset(t28, 0, 8);
    if (*((unsigned int *)t8) != *((unsigned int *)t12))
        goto LAB25;

LAB23:    t18 = (t8 + 4);
    t19 = (t12 + 4);
    if (*((unsigned int *)t18) != *((unsigned int *)t19))
        goto LAB25;

LAB24:    *((unsigned int *)t28) = 1;

LAB25:    memset(t10, 0, 8);
    t25 = (t28 + 4);
    t13 = *((unsigned int *)t25);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB29;

LAB27:    if (*((unsigned int *)t25) == 0)
        goto LAB26;

LAB28:    t26 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t26) = 1;

LAB29:    t27 = (t10 + 4);
    t20 = *((unsigned int *)t27);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB30;

LAB31:    xsi_set_current_line(24, ng13);
    t3 = (t1 + 20704);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 8184);
    t9 = (t5 + 56U);
    t12 = *((char **)t9);
    memset(t28, 0, 8);
    if (*((unsigned int *)t8) != *((unsigned int *)t12))
        goto LAB36;

LAB34:    t18 = (t8 + 4);
    t19 = (t12 + 4);
    if (*((unsigned int *)t18) != *((unsigned int *)t19))
        goto LAB36;

LAB35:    *((unsigned int *)t28) = 1;

LAB36:    memset(t10, 0, 8);
    t25 = (t28 + 4);
    t13 = *((unsigned int *)t25);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB40;

LAB38:    if (*((unsigned int *)t25) == 0)
        goto LAB37;

LAB39:    t26 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t26) = 1;

LAB40:    t27 = (t10 + 4);
    t20 = *((unsigned int *)t27);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB41;

LAB42:    xsi_set_current_line(31, ng13);
    t3 = (t1 + 20776);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 20816);
    t9 = *((char **)t5);
    t12 = ((((char*)(t9))) + 72U);
    t18 = *((char **)t12);
    t19 = ((char*)((ng19)));
    xsi_vlog_generic_get_index_select_value(t28, 1, t8, t18, 2, t19, 32, 1);
    memset(t10, 0, 8);
    t25 = (t28 + 4);
    t13 = *((unsigned int *)t25);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB48;

LAB46:    if (*((unsigned int *)t25) == 0)
        goto LAB45;

LAB47:    t26 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t26) = 1;

LAB48:    t27 = (t10 + 4);
    t20 = *((unsigned int *)t27);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB49;

LAB50:    xsi_set_current_line(36, ng13);
    t3 = (t1 + 20848);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 20880);
    t9 = *((char **)t5);
    t12 = ((((char*)(t9))) + 72U);
    t18 = *((char **)t12);
    t19 = ((char*)((ng21)));
    xsi_vlog_generic_get_index_select_value(t28, 1, t8, t18, 2, t19, 32, 1);
    memset(t10, 0, 8);
    t25 = (t28 + 4);
    t13 = *((unsigned int *)t25);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB56;

LAB54:    if (*((unsigned int *)t25) == 0)
        goto LAB53;

LAB55:    t26 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t26) = 1;

LAB56:    t27 = (t10 + 4);
    t20 = *((unsigned int *)t27);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB57;

LAB58:    xsi_set_current_line(41, ng13);
    t3 = (t1 + 20920);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 56U);
    t8 = *((char **)t5);
    t9 = (t1 + 8184);
    t12 = (t9 + 56U);
    t18 = *((char **)t12);
    memset(t28, 0, 8);
    if (*((unsigned int *)t8) != *((unsigned int *)t18))
        goto LAB63;

LAB61:    t19 = (t8 + 4);
    t25 = (t18 + 4);
    if (*((unsigned int *)t19) != *((unsigned int *)t25))
        goto LAB63;

LAB62:    *((unsigned int *)t28) = 1;

LAB63:    memset(t10, 0, 8);
    t26 = (t28 + 4);
    t13 = *((unsigned int *)t26);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB67;

LAB65:    if (*((unsigned int *)t26) == 0)
        goto LAB64;

LAB66:    t27 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t27) = 1;

LAB67:    t29 = (t10 + 4);
    t20 = *((unsigned int *)t29);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB68;

LAB69:    xsi_set_current_line(48, ng13);

LAB72:    xsi_set_current_line(49, ng13);
    t3 = ((char*)((ng2)));
    t4 = (t1 + 8024);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(50, ng13);
    t3 = (t1 + 8344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8184);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng24, 3, t18, (char)119, t5, 32, (char)119, t12, 32);

LAB70:
LAB59:
LAB51:
LAB43:
LAB32:
LAB21:    goto LAB14;

LAB8:    xsi_set_current_line(53, ng13);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 8024);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB14;

LAB10:    xsi_set_current_line(55, ng13);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 8024);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB14;

LAB12:    xsi_set_current_line(57, ng13);
    t4 = (t1 + 20992);
    t5 = *((char **)t4);
    t8 = ((((char*)(t5))) + 40U);
    t9 = *((char **)t8);
    t8 = (t1 + 21024);
    t12 = *((char **)t8);
    t18 = ((((char*)(t12))) + 72U);
    t19 = *((char **)t18);
    t25 = ((char*)((ng4)));
    xsi_vlog_generic_get_index_select_value(t28, 1, t9, t19, 2, t25, 32, 1);
    memset(t10, 0, 8);
    t26 = (t28 + 4);
    t13 = *((unsigned int *)t26);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB76;

LAB74:    if (*((unsigned int *)t26) == 0)
        goto LAB73;

LAB75:    t27 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t27) = 1;

LAB76:    t29 = (t10 + 4);
    t20 = *((unsigned int *)t29);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB77;

LAB78:    xsi_set_current_line(62, ng13);
    t3 = (t1 + 21064);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 56U);
    t8 = *((char **)t5);
    t9 = (t1 + 21096);
    t12 = *((char **)t9);
    t18 = ((((char*)(t12))) + 40U);
    t19 = *((char **)t18);
    memset(t28, 0, 8);
    if (*((unsigned int *)t8) != *((unsigned int *)t19))
        goto LAB83;

LAB81:    t18 = (t8 + 4);
    t25 = (t19 + 4);
    if (*((unsigned int *)t18) != *((unsigned int *)t25))
        goto LAB83;

LAB82:    *((unsigned int *)t28) = 1;

LAB83:    memset(t10, 0, 8);
    t26 = (t28 + 4);
    t13 = *((unsigned int *)t26);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB87;

LAB85:    if (*((unsigned int *)t26) == 0)
        goto LAB84;

LAB86:    t27 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t27) = 1;

LAB87:    t29 = (t10 + 4);
    t20 = *((unsigned int *)t29);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB88;

LAB89:    xsi_set_current_line(69, ng13);

LAB92:    xsi_set_current_line(70, ng13);
    t3 = ((char*)((ng2)));
    t4 = (t1 + 8024);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(71, ng13);
    t3 = (t1 + 8344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8184);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng27, 3, t18, (char)119, t5, 32, (char)119, t12, 32);

LAB90:
LAB79:    goto LAB14;

LAB15:    *((unsigned int *)t10) = 1;
    goto LAB18;

LAB19:    xsi_set_current_line(10, ng13);

LAB22:    xsi_set_current_line(11, ng13);
    t25 = ((char*)((ng7)));
    t26 = (t1 + 8024);
    xsi_vlogvar_assign_value(t26, t25, 0, 0, 1);
    xsi_set_current_line(12, ng13);
    t3 = (t1 + 8344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8184);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = ((char*)((ng16)));
    t19 = (t1 + 20608);
    t25 = *((char **)t19);
    t26 = ((((char*)(t25))) + 40U);
    t27 = *((char **)t26);
    t26 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng15, 5, t26, (char)119, t5, 32, (char)119, t12, 32, (char)119, t18, 32, (char)118, t27, 51);
    goto LAB21;

LAB26:    *((unsigned int *)t10) = 1;
    goto LAB29;

LAB30:    xsi_set_current_line(17, ng13);

LAB33:    xsi_set_current_line(18, ng13);
    t29 = ((char*)((ng7)));
    t30 = (t1 + 8024);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 1);
    xsi_set_current_line(19, ng13);
    t3 = (t1 + 8344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8184);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 8344);
    t19 = (t18 + 56U);
    t25 = *((char **)t19);
    t26 = (t1 + 20672);
    t27 = *((char **)t26);
    t29 = ((((char*)(t27))) + 40U);
    t30 = *((char **)t29);
    t29 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng17, 5, t29, (char)119, t5, 32, (char)119, t12, 32, (char)119, t25, 32, (char)118, t30, 5);
    goto LAB32;

LAB37:    *((unsigned int *)t10) = 1;
    goto LAB40;

LAB41:    xsi_set_current_line(24, ng13);

LAB44:    xsi_set_current_line(25, ng13);
    t29 = ((char*)((ng7)));
    t30 = (t1 + 8024);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 1);
    xsi_set_current_line(26, ng13);
    t3 = (t1 + 8344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8184);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 8184);
    t19 = (t18 + 56U);
    t25 = *((char **)t19);
    t26 = (t1 + 20736);
    t27 = *((char **)t26);
    t29 = ((((char*)(t27))) + 40U);
    t30 = *((char **)t29);
    t29 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng18, 5, t29, (char)119, t5, 32, (char)119, t12, 32, (char)119, t25, 32, (char)118, t30, 12);
    goto LAB43;

LAB45:    *((unsigned int *)t10) = 1;
    goto LAB48;

LAB49:    xsi_set_current_line(31, ng13);

LAB52:    xsi_set_current_line(32, ng13);
    t29 = ((char*)((ng7)));
    t30 = (t1 + 8024);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 1);
    xsi_set_current_line(33, ng13);
    t3 = (t1 + 8344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8184);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng20, 3, t18, (char)119, t5, 32, (char)119, t12, 32);
    goto LAB51;

LAB53:    *((unsigned int *)t10) = 1;
    goto LAB56;

LAB57:    xsi_set_current_line(36, ng13);

LAB60:    xsi_set_current_line(37, ng13);
    t29 = ((char*)((ng7)));
    t30 = (t1 + 8024);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 1);
    xsi_set_current_line(38, ng13);
    t3 = (t1 + 8344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8184);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng22, 3, t18, (char)119, t5, 32, (char)119, t12, 32);
    goto LAB59;

LAB64:    *((unsigned int *)t10) = 1;
    goto LAB67;

LAB68:    xsi_set_current_line(41, ng13);

LAB71:    xsi_set_current_line(42, ng13);
    t30 = ((char*)((ng7)));
    t31 = (t1 + 8024);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 1);
    xsi_set_current_line(43, ng13);
    t3 = (t1 + 8344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8184);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 8184);
    t19 = (t18 + 56U);
    t25 = *((char **)t19);
    t26 = (t1 + 20960);
    t27 = *((char **)t26);
    t29 = ((((char*)(t27))) + 56U);
    t30 = *((char **)t29);
    t31 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng23, 5, t31, (char)119, t5, 32, (char)119, t12, 32, (char)119, t25, 32, (char)118, t30, 16);
    goto LAB70;

LAB73:    *((unsigned int *)t10) = 1;
    goto LAB76;

LAB77:    xsi_set_current_line(57, ng13);

LAB80:    xsi_set_current_line(58, ng13);
    t30 = ((char*)((ng7)));
    t31 = (t1 + 8024);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 1);
    xsi_set_current_line(59, ng13);
    t3 = (t1 + 8344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8184);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng25, 3, t18, (char)119, t5, 32, (char)119, t12, 32);
    goto LAB79;

LAB84:    *((unsigned int *)t10) = 1;
    goto LAB87;

LAB88:    xsi_set_current_line(62, ng13);

LAB91:    xsi_set_current_line(63, ng13);
    t30 = ((char*)((ng7)));
    t31 = (t1 + 8024);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 1);
    xsi_set_current_line(64, ng13);
    t3 = (t1 + 8344);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8184);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 21128);
    t19 = *((char **)t18);
    t25 = ((((char*)(t19))) + 40U);
    t26 = *((char **)t25);
    t25 = (t1 + 21168);
    t27 = *((char **)t25);
    t29 = ((((char*)(t27))) + 56U);
    t30 = *((char **)t29);
    t31 = (t1 + 1280);
    xsi_vlogfile_write(1, 0, 0, ng26, 5, t31, (char)119, t5, 32, (char)119, t12, 32, (char)118, t26, 8, (char)118, t30, 8);
    goto LAB90;

}

static int sp_TEST_OUT(char *t1, char *t2)
{
    char t10[8];
    char t11[16];
    char t28[8];
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;
    char *t29;
    char *t30;
    char *t31;

LAB0:    t0 = 1;
    xsi_set_current_line(5, ng28);

LAB2:    xsi_set_current_line(6, ng28);
    t3 = (t1 + 21200);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t6 = *((char **)t5);

LAB3:    t5 = ((char*)((ng1)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t5, 32);
    if (t7 == 1)
        goto LAB4;

LAB5:    t3 = ((char*)((ng3)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB6;

LAB7:    t3 = ((char*)((ng9)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB8;

LAB9:    t3 = ((char*)((ng10)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB10;

LAB11:    t3 = ((char*)((ng4)));
    t7 = xsi_vlog_unsigned_case_compare(t6, 3, t3, 32);
    if (t7 == 1)
        goto LAB12;

LAB13:
LAB14:    t0 = 0;

LAB1:    return t0;
LAB4:    xsi_set_current_line(7, ng28);
    t8 = ((char*)((ng2)));
    t9 = (t1 + 8664);
    xsi_vlogvar_assign_value(t9, t8, 0, 0, 1);
    goto LAB14;

LAB6:    xsi_set_current_line(9, ng28);
    t4 = (t1 + 21232);
    t5 = *((char **)t4);
    t8 = ((((char*)(t5))) + 40U);
    t9 = *((char **)t8);
    t8 = ((char*)((ng29)));
    xsi_vlog_unsigned_case_eq(t11, 51, t9, 51, t8, 32);
    memset(t10, 0, 8);
    t12 = (t11 + 4);
    t13 = *((unsigned int *)t12);
    t14 = (~(t13));
    t15 = *((unsigned int *)t11);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB18;

LAB16:    if (*((unsigned int *)t12) == 0)
        goto LAB15;

LAB17:    t18 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t18) = 1;

LAB18:    t19 = (t10 + 4);
    t20 = *((unsigned int *)t19);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB19;

LAB20:    xsi_set_current_line(16, ng28);
    t3 = (t1 + 21296);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 8984);
    t9 = (t5 + 56U);
    t12 = *((char **)t9);
    memset(t28, 0, 8);
    if (*((unsigned int *)t8) != *((unsigned int *)t12))
        goto LAB25;

LAB23:    t18 = (t8 + 4);
    t19 = (t12 + 4);
    if (*((unsigned int *)t18) != *((unsigned int *)t19))
        goto LAB25;

LAB24:    *((unsigned int *)t28) = 1;

LAB25:    memset(t10, 0, 8);
    t25 = (t28 + 4);
    t13 = *((unsigned int *)t25);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB29;

LAB27:    if (*((unsigned int *)t25) == 0)
        goto LAB26;

LAB28:    t26 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t26) = 1;

LAB29:    t27 = (t10 + 4);
    t20 = *((unsigned int *)t27);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB30;

LAB31:    xsi_set_current_line(23, ng28);
    t3 = (t1 + 21360);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 8824);
    t9 = (t5 + 56U);
    t12 = *((char **)t9);
    memset(t28, 0, 8);
    if (*((unsigned int *)t8) != *((unsigned int *)t12))
        goto LAB36;

LAB34:    t18 = (t8 + 4);
    t19 = (t12 + 4);
    if (*((unsigned int *)t18) != *((unsigned int *)t19))
        goto LAB36;

LAB35:    *((unsigned int *)t28) = 1;

LAB36:    memset(t10, 0, 8);
    t25 = (t28 + 4);
    t13 = *((unsigned int *)t25);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB40;

LAB38:    if (*((unsigned int *)t25) == 0)
        goto LAB37;

LAB39:    t26 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t26) = 1;

LAB40:    t27 = (t10 + 4);
    t20 = *((unsigned int *)t27);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB41;

LAB42:    xsi_set_current_line(30, ng28);
    t3 = (t1 + 21432);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 21472);
    t9 = *((char **)t5);
    t12 = ((((char*)(t9))) + 72U);
    t18 = *((char **)t12);
    t19 = ((char*)((ng34)));
    xsi_vlog_generic_get_index_select_value(t28, 1, t8, t18, 2, t19, 32, 1);
    memset(t10, 0, 8);
    t25 = (t28 + 4);
    t13 = *((unsigned int *)t25);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB48;

LAB46:    if (*((unsigned int *)t25) == 0)
        goto LAB45;

LAB47:    t26 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t26) = 1;

LAB48:    t27 = (t10 + 4);
    t20 = *((unsigned int *)t27);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB49;

LAB50:    xsi_set_current_line(35, ng28);
    t3 = (t1 + 21528);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 21560);
    t9 = *((char **)t5);
    t12 = ((((char*)(t9))) + 72U);
    t18 = *((char **)t12);
    t19 = ((char*)((ng3)));
    xsi_vlog_generic_get_index_select_value(t28, 1, t8, t18, 2, t19, 32, 1);
    memset(t10, 0, 8);
    t25 = (t28 + 4);
    t13 = *((unsigned int *)t25);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB56;

LAB54:    if (*((unsigned int *)t25) == 0)
        goto LAB53;

LAB55:    t26 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t26) = 1;

LAB56:    t27 = (t10 + 4);
    t20 = *((unsigned int *)t27);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB57;

LAB58:    xsi_set_current_line(40, ng28);
    t3 = (t1 + 21592);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 40U);
    t8 = *((char **)t5);
    t5 = (t1 + 21624);
    t9 = *((char **)t5);
    t12 = ((((char*)(t9))) + 72U);
    t18 = *((char **)t12);
    t19 = ((char*)((ng37)));
    xsi_vlog_generic_get_index_select_value(t28, 1, t8, t18, 2, t19, 32, 1);
    memset(t10, 0, 8);
    t25 = (t28 + 4);
    t13 = *((unsigned int *)t25);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB64;

LAB62:    if (*((unsigned int *)t25) == 0)
        goto LAB61;

LAB63:    t26 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t26) = 1;

LAB64:    t27 = (t10 + 4);
    t20 = *((unsigned int *)t27);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB65;

LAB66:    xsi_set_current_line(45, ng28);
    t3 = (t1 + 21664);
    t4 = *((char **)t3);
    t5 = ((((char*)(t4))) + 56U);
    t8 = *((char **)t5);
    t9 = (t1 + 8824);
    t12 = (t9 + 56U);
    t18 = *((char **)t12);
    memset(t28, 0, 8);
    if (*((unsigned int *)t8) != *((unsigned int *)t18))
        goto LAB71;

LAB69:    t19 = (t8 + 4);
    t25 = (t18 + 4);
    if (*((unsigned int *)t19) != *((unsigned int *)t25))
        goto LAB71;

LAB70:    *((unsigned int *)t28) = 1;

LAB71:    memset(t10, 0, 8);
    t26 = (t28 + 4);
    t13 = *((unsigned int *)t26);
    t14 = (~(t13));
    t15 = *((unsigned int *)t28);
    t16 = (t15 & t14);
    t17 = (t16 & 1U);
    if (t17 != 0)
        goto LAB75;

LAB73:    if (*((unsigned int *)t26) == 0)
        goto LAB72;

LAB74:    t27 = (t10 + 4);
    *((unsigned int *)t10) = 1;
    *((unsigned int *)t27) = 1;

LAB75:    t29 = (t10 + 4);
    t20 = *((unsigned int *)t29);
    t21 = (~(t20));
    t22 = *((unsigned int *)t10);
    t23 = (t22 & t21);
    t24 = (t23 != 0);
    if (t24 > 0)
        goto LAB76;

LAB77:    xsi_set_current_line(52, ng28);

LAB80:    xsi_set_current_line(53, ng28);
    t3 = ((char*)((ng2)));
    t4 = (t1 + 8664);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 1);
    xsi_set_current_line(54, ng28);
    t3 = (t1 + 8824);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8984);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 1712);
    xsi_vlogfile_write(0, 0, 0, ng40, 3, t18, (char)119, t5, 32, (char)119, t12, 32);
    t19 = (t1 + 1712);
    xsi_vlogfile_write(1, 0, 0, ng41, 1, t19);

LAB78:
LAB67:
LAB59:
LAB51:
LAB43:
LAB32:
LAB21:    goto LAB14;

LAB8:    xsi_set_current_line(56, ng28);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 8664);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB14;

LAB10:    xsi_set_current_line(57, ng28);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 8664);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB14;

LAB12:    xsi_set_current_line(58, ng28);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 8664);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    goto LAB14;

LAB15:    *((unsigned int *)t10) = 1;
    goto LAB18;

LAB19:    xsi_set_current_line(9, ng28);

LAB22:    xsi_set_current_line(10, ng28);
    t25 = ((char*)((ng7)));
    t26 = (t1 + 8664);
    xsi_vlogvar_assign_value(t26, t25, 0, 0, 1);
    xsi_set_current_line(11, ng28);
    t3 = (t1 + 8824);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8984);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = ((char*)((ng31)));
    t19 = (t1 + 21264);
    t25 = *((char **)t19);
    t26 = ((((char*)(t25))) + 40U);
    t27 = *((char **)t26);
    t26 = (t1 + 1712);
    xsi_vlogfile_write(1, 0, 0, ng30, 5, t26, (char)119, t5, 32, (char)119, t12, 32, (char)119, t18, 32, (char)118, t27, 51);
    goto LAB21;

LAB26:    *((unsigned int *)t10) = 1;
    goto LAB29;

LAB30:    xsi_set_current_line(16, ng28);

LAB33:    xsi_set_current_line(17, ng28);
    t29 = ((char*)((ng7)));
    t30 = (t1 + 8664);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 1);
    xsi_set_current_line(18, ng28);
    t3 = (t1 + 8824);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8984);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 8984);
    t19 = (t18 + 56U);
    t25 = *((char **)t19);
    t26 = (t1 + 21328);
    t27 = *((char **)t26);
    t29 = ((((char*)(t27))) + 40U);
    t30 = *((char **)t29);
    t29 = (t1 + 1712);
    xsi_vlogfile_write(1, 0, 0, ng32, 5, t29, (char)119, t5, 32, (char)119, t12, 32, (char)119, t25, 32, (char)118, t30, 5);
    goto LAB32;

LAB37:    *((unsigned int *)t10) = 1;
    goto LAB40;

LAB41:    xsi_set_current_line(23, ng28);

LAB44:    xsi_set_current_line(24, ng28);
    t29 = ((char*)((ng7)));
    t30 = (t1 + 8664);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 1);
    xsi_set_current_line(25, ng28);
    t3 = (t1 + 8824);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8984);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 8824);
    t19 = (t18 + 56U);
    t25 = *((char **)t19);
    t26 = (t1 + 21392);
    t27 = *((char **)t26);
    t29 = ((((char*)(t27))) + 40U);
    t30 = *((char **)t29);
    t29 = (t1 + 1712);
    xsi_vlogfile_write(1, 0, 0, ng33, 5, t29, (char)119, t5, 32, (char)119, t12, 32, (char)119, t25, 32, (char)118, t30, 12);
    goto LAB43;

LAB45:    *((unsigned int *)t10) = 1;
    goto LAB48;

LAB49:    xsi_set_current_line(30, ng28);

LAB52:    xsi_set_current_line(31, ng28);
    t29 = ((char*)((ng7)));
    t30 = (t1 + 8664);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 1);
    xsi_set_current_line(32, ng28);
    t3 = (t1 + 8824);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 21496);
    t9 = *((char **)t8);
    t12 = ((((char*)(t9))) + 40U);
    t18 = *((char **)t12);
    t12 = (t1 + 1712);
    xsi_vlogfile_write(1, 0, 0, ng35, 3, t12, (char)119, t5, 32, (char)118, t18, 5);
    goto LAB51;

LAB53:    *((unsigned int *)t10) = 1;
    goto LAB56;

LAB57:    xsi_set_current_line(35, ng28);

LAB60:    xsi_set_current_line(36, ng28);
    t29 = ((char*)((ng7)));
    t30 = (t1 + 8664);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 1);
    xsi_set_current_line(37, ng28);
    t3 = (t1 + 8824);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8984);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 1712);
    xsi_vlogfile_write(1, 0, 0, ng36, 3, t18, (char)119, t5, 32, (char)119, t12, 32);
    goto LAB59;

LAB61:    *((unsigned int *)t10) = 1;
    goto LAB64;

LAB65:    xsi_set_current_line(40, ng28);

LAB68:    xsi_set_current_line(41, ng28);
    t29 = ((char*)((ng7)));
    t30 = (t1 + 8664);
    xsi_vlogvar_assign_value(t30, t29, 0, 0, 1);
    xsi_set_current_line(42, ng28);
    t3 = (t1 + 8824);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8984);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 1712);
    xsi_vlogfile_write(1, 0, 0, ng38, 3, t18, (char)119, t5, 32, (char)119, t12, 32);
    goto LAB67;

LAB72:    *((unsigned int *)t10) = 1;
    goto LAB75;

LAB76:    xsi_set_current_line(45, ng28);

LAB79:    xsi_set_current_line(46, ng28);
    t30 = ((char*)((ng7)));
    t31 = (t1 + 8664);
    xsi_vlogvar_assign_value(t31, t30, 0, 0, 1);
    xsi_set_current_line(47, ng28);
    t3 = (t1 + 8824);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t8 = (t1 + 8984);
    t9 = (t8 + 56U);
    t12 = *((char **)t9);
    t18 = (t1 + 8824);
    t19 = (t18 + 56U);
    t25 = *((char **)t19);
    t26 = (t1 + 21704);
    t27 = *((char **)t26);
    t29 = ((((char*)(t27))) + 56U);
    t30 = *((char **)t29);
    t31 = (t1 + 1712);
    xsi_vlogfile_write(1, 0, 0, ng39, 5, t31, (char)119, t5, 32, (char)119, t12, 32, (char)119, t25, 32, (char)118, t30, 16);
    goto LAB78;

}

static void Cont_26_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 10064U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(26, ng42);
    t2 = (t0 + 21736);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15200);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 1023U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 9);
    t18 = (t0 + 14848);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Cont_27_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 10312U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(27, ng42);
    t2 = (t0 + 21768);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15264);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 7U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 2);
    t18 = (t0 + 14864);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_29_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 10560U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(29, ng42);
    t2 = (t0 + 21792);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15328);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 7U);
    t18 = (t0 + 14880);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_30_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 10808U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(30, ng42);
    t2 = (t0 + 21816);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15392);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 7U);
    t18 = (t0 + 14896);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_31_4(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 11056U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng42);
    t2 = (t0 + 21840);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15456);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 7U);
    t18 = (t0 + 14912);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_33_5(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 11304U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(33, ng42);
    t2 = (t0 + 21864);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15520);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 31U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 4U);
    t18 = (t0 + 14928);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_34_6(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 11552U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(34, ng42);
    t2 = (t0 + 21888);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15584);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 31U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 4U);
    t18 = (t0 + 14944);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_35_7(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 11800U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(35, ng42);
    t2 = (t0 + 21920);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15648);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 127U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 6U);
    t18 = (t0 + 14960);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_36_8(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 12048U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(36, ng42);
    t2 = (t0 + 21944);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15712);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 127U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 6U);
    t18 = (t0 + 14976);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_37_9(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 12296U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(37, ng42);
    t2 = (t0 + 21968);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15776);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 7U);
    t18 = (t0 + 14992);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_39_10(char *t0)
{
    char t3[8];
    char t7[8];
    char t21[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    unsigned int t36;
    unsigned int t37;
    char *t38;
    unsigned int t39;
    unsigned int t40;
    char *t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;

LAB0:    t1 = (t0 + 12544U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(39, ng42);
    t2 = (t0 + 22000);
    t4 = *((char **)t2);
    t5 = ((((char*)(t4))) + 56U);
    t6 = *((char **)t5);
    t8 = (t0 + 22032);
    t9 = *((char **)t8);
    t10 = ((((char*)(t9))) + 72U);
    t11 = *((char **)t10);
    t12 = (t0 + 22064);
    t13 = *((char **)t12);
    t14 = ((((char*)(t13))) + 64U);
    t15 = *((char **)t14);
    t16 = ((char*)((ng43)));
    xsi_vlog_generic_get_array_select_value(t7, 8, t6, t11, t15, 2, 1, t16, 32, 1);
    t17 = (t0 + 22096);
    t18 = *((char **)t17);
    t19 = ((((char*)(t18))) + 56U);
    t20 = *((char **)t19);
    t22 = (t0 + 22128);
    t23 = *((char **)t22);
    t24 = ((((char*)(t23))) + 72U);
    t25 = *((char **)t24);
    t26 = (t0 + 22160);
    t27 = *((char **)t26);
    t28 = ((((char*)(t27))) + 64U);
    t29 = *((char **)t28);
    t30 = ((char*)((ng44)));
    xsi_vlog_generic_get_array_select_value(t21, 8, t20, t25, t29, 2, 1, t30, 32, 1);
    xsi_vlogtype_concat(t3, 16, 16, 2U, t21, 8, t7, 8);
    t31 = (t0 + 15840);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memset(t35, 0, 8);
    t36 = 127U;
    t37 = t36;
    t38 = (t3 + 4);
    t39 = *((unsigned int *)t3);
    t36 = (t36 & t39);
    t40 = *((unsigned int *)t38);
    t37 = (t37 & t40);
    t41 = (t35 + 4);
    t42 = *((unsigned int *)t35);
    *((unsigned int *)t35) = (t42 | t36);
    t43 = *((unsigned int *)t41);
    *((unsigned int *)t41) = (t43 | t37);
    xsi_driver_vfirst_trans(t31, 0, 6U);
    t44 = (t0 + 15008);
    *((int *)t44) = 1;

LAB1:    return;
}

static void NetDecl_41_11(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 12792U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(41, ng42);
    t2 = (t0 + 22192);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15904);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 4095U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 11U);
    t18 = (t0 + 15024);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_42_12(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 13040U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(42, ng42);
    t2 = (t0 + 22224);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 15968);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    xsi_vlog_bit_copy(t9, 0, t5, 0, 51);
    xsi_driver_vfirst_trans(t4, 0, 50U);
    t10 = (t0 + 15040);
    *((int *)t10) = 1;

LAB1:    return;
}

static void NetDecl_43_13(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 13288U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(43, ng42);
    t2 = (t0 + 22264);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 16032);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 65535U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 15U);
    t18 = (t0 + 15056);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_44_14(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 13536U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(44, ng42);
    t2 = (t0 + 22296);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 16096);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 7U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 2U);
    t18 = (t0 + 15072);
    *((int *)t18) = 1;

LAB1:    return;
}

static void NetDecl_45_15(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;

LAB0:    t1 = (t0 + 13784U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(45, ng42);
    t2 = (t0 + 22336);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 16160);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memset(t10, 0, 8);
    t11 = 255U;
    t12 = t11;
    t13 = (t5 + 4);
    t14 = *((unsigned int *)t5);
    t11 = (t11 & t14);
    t15 = *((unsigned int *)t13);
    t12 = (t12 & t15);
    t16 = (t10 + 4);
    t17 = *((unsigned int *)t10);
    *((unsigned int *)t10) = (t17 | t11);
    t18 = *((unsigned int *)t16);
    *((unsigned int *)t16) = (t18 | t12);
    xsi_driver_vfirst_trans(t6, 0, 7U);
    t19 = (t0 + 15088);
    *((int *)t19) = 1;

LAB1:    return;
}

static void NetDecl_46_16(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;

LAB0:    t1 = (t0 + 14032U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(46, ng42);
    t2 = (t0 + 22368);
    t3 = *((char **)t2);
    t4 = ((((char*)(t3))) + 40U);
    t5 = *((char **)t4);
    t4 = (t0 + 16224);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memset(t9, 0, 8);
    t10 = 255U;
    t11 = t10;
    t12 = (t5 + 4);
    t13 = *((unsigned int *)t5);
    t10 = (t10 & t13);
    t14 = *((unsigned int *)t12);
    t11 = (t11 & t14);
    t15 = (t9 + 4);
    t16 = *((unsigned int *)t9);
    *((unsigned int *)t9) = (t16 | t10);
    t17 = *((unsigned int *)t15);
    *((unsigned int *)t15) = (t17 | t11);
    xsi_driver_vfirst_trans(t4, 0, 7U);
    t18 = (t0 + 15104);
    *((int *)t18) = 1;

LAB1:    return;
}

static void Initial_59_17(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(59, ng42);

LAB2:    xsi_set_current_line(60, ng42);
    xsi_vlogfile_write(1, 0, 0, ng45, 1, t0);
    xsi_set_current_line(61, ng42);
    t1 = ((char*)((ng46)));
    t2 = (t0 + 5944);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(62, ng42);
    t1 = ((char*)((ng46)));
    t2 = (t0 + 6104);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(63, ng42);
    t1 = ((char*)((ng46)));
    t2 = (t0 + 6264);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(64, ng42);
    t1 = ((char*)((ng46)));
    t2 = (t0 + 6424);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(66, ng42);
    t1 = ((char*)((ng47)));
    t2 = (t0 + 6584);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(67, ng42);
    t1 = ((char*)((ng48)));
    t2 = (t0 + 6744);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(68, ng42);
    t1 = ((char*)((ng48)));
    t2 = (t0 + 6904);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(69, ng42);
    t1 = ((char*)((ng48)));
    t2 = (t0 + 7064);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(70, ng42);
    t1 = ((char*)((ng46)));
    t2 = (t0 + 7224);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 32);
    xsi_set_current_line(71, ng42);
    t1 = ((char*)((ng49)));
    t2 = (t0 + 5624);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_75_18(char *t0)
{
    char t26[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t31;
    unsigned int t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    char *t48;
    char *t49;
    char *t50;
    char *t51;

LAB0:    t1 = (t0 + 14528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(75, ng42);
    t2 = (t0 + 15120);
    *((int *)t2) = 1;
    t3 = (t0 + 14560);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(75, ng42);

LAB5:    xsi_set_current_line(76, ng42);
    t4 = (t0 + 2664U);
    t5 = *((char **)t4);

LAB6:    t4 = ((char*)((ng49)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 10, t4, 32);
    if (t6 == 1)
        goto LAB7;

LAB8:    t2 = ((char*)((ng1)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 10, t2, 32);
    if (t6 == 1)
        goto LAB9;

LAB10:    t2 = ((char*)((ng3)));
    t6 = xsi_vlog_unsigned_case_compare(t5, 10, t2, 32);
    if (t6 == 1)
        goto LAB11;

LAB12:
LAB14:
LAB13:    xsi_set_current_line(113, ng42);
    t2 = ((char*)((ng53)));
    t3 = (t0 + 5624);
    xsi_vlogvar_wait_assign_value(t3, t2, 0, 0, 1, 0LL);

LAB15:    xsi_set_current_line(115, ng42);
    t2 = (t0 + 2664U);
    t3 = *((char **)t2);
    t2 = (t0 + 5784);
    xsi_vlogvar_assign_value(t2, t3, 0, 0, 10);
    goto LAB2;

LAB7:    xsi_set_current_line(78, ng42);

LAB16:    xsi_set_current_line(80, ng42);
    t7 = ((char*)((ng50)));
    t8 = (t0 + 7064);
    xsi_vlogvar_assign_value(t8, t7, 0, 0, 32);
    xsi_set_current_line(81, ng42);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 7224);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(82, ng42);
    t2 = (t0 + 7064);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t7 = (t0 + 7224);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 14336);
    t11 = (t0 + 848);
    t12 = xsi_create_subprogram_invocation(t10, 0, t0, t11, 0, 0);
    t13 = (t0 + 7704);
    xsi_vlogvar_assign_value(t13, t4, 0, 0, 32);
    t14 = (t0 + 7864);
    xsi_vlogvar_assign_value(t14, t9, 0, 0, 32);

LAB17:    t15 = (t0 + 14432);
    t16 = *((char **)t15);
    t17 = (t16 + 80U);
    t18 = *((char **)t17);
    t19 = (t18 + 272U);
    t20 = *((char **)t19);
    t21 = (t20 + 0U);
    t22 = *((char **)t21);
    t6 = ((int  (*)(char *, char *))t22)(t0, t16);
    if (t6 != 0)
        goto LAB19;

LAB18:    t16 = (t0 + 14432);
    t23 = *((char **)t16);
    t16 = (t0 + 7544);
    t24 = (t16 + 56U);
    t25 = *((char **)t24);
    memcpy(t26, t25, 8);
    t27 = (t0 + 848);
    t28 = (t0 + 14336);
    t29 = 0;
    xsi_delete_subprogram_invocation(t27, t23, t0, t28, t29);
    t30 = (t0 + 5624);
    xsi_vlogvar_assign_value(t30, t26, 0, 0, 1);
    xsi_set_current_line(84, ng42);
    t2 = (t0 + 2824U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t26, 0, 8);
    t4 = (t3 + 4);
    t7 = (t2 + 4);
    t31 = *((unsigned int *)t3);
    t32 = *((unsigned int *)t2);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t4);
    t35 = *((unsigned int *)t7);
    t36 = (t34 ^ t35);
    t37 = (t33 | t36);
    t38 = *((unsigned int *)t4);
    t39 = *((unsigned int *)t7);
    t40 = (t38 | t39);
    t41 = (~(t40));
    t42 = (t37 & t41);
    if (t42 != 0)
        goto LAB23;

LAB20:    if (t40 != 0)
        goto LAB22;

LAB21:    *((unsigned int *)t26) = 1;

LAB23:    t9 = (t26 + 4);
    t43 = *((unsigned int *)t9);
    t44 = (~(t43));
    t45 = *((unsigned int *)t26);
    t46 = (t45 & t44);
    t47 = (t46 != 0);
    if (t47 > 0)
        goto LAB24;

LAB25:
LAB26:    goto LAB15;

LAB9:    xsi_set_current_line(90, ng42);

LAB28:    xsi_set_current_line(92, ng42);
    t3 = ((char*)((ng51)));
    t4 = (t0 + 6744);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(93, ng42);
    t2 = ((char*)((ng50)));
    t3 = (t0 + 6904);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(94, ng42);
    t2 = (t0 + 6744);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t7 = (t0 + 6904);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 6264);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t0 + 14336);
    t14 = (t0 + 1712);
    t15 = xsi_create_subprogram_invocation(t13, 0, t0, t14, 0, 0);
    t16 = (t0 + 8824);
    xsi_vlogvar_assign_value(t16, t4, 0, 0, 32);
    t17 = (t0 + 8984);
    xsi_vlogvar_assign_value(t17, t9, 0, 0, 32);
    t18 = (t0 + 9144);
    xsi_vlogvar_assign_value(t18, t12, 0, 0, 32);

LAB29:    t19 = (t0 + 14432);
    t20 = *((char **)t19);
    t21 = (t20 + 80U);
    t22 = *((char **)t21);
    t23 = (t22 + 272U);
    t24 = *((char **)t23);
    t25 = (t24 + 0U);
    t27 = *((char **)t25);
    t6 = ((int  (*)(char *, char *))t27)(t0, t20);
    if (t6 != 0)
        goto LAB31;

LAB30:    t20 = (t0 + 14432);
    t28 = *((char **)t20);
    t20 = (t0 + 8664);
    t29 = (t20 + 56U);
    t30 = *((char **)t29);
    memcpy(t26, t30, 8);
    t48 = (t0 + 1712);
    t49 = (t0 + 14336);
    t50 = 0;
    xsi_delete_subprogram_invocation(t48, t28, t0, t49, t50);
    t51 = (t0 + 5624);
    xsi_vlogvar_assign_value(t51, t26, 0, 0, 1);
    goto LAB15;

LAB11:    xsi_set_current_line(99, ng42);

LAB32:    xsi_set_current_line(101, ng42);
    t3 = ((char*)((ng52)));
    t4 = (t0 + 7064);
    xsi_vlogvar_assign_value(t4, t3, 0, 0, 32);
    xsi_set_current_line(102, ng42);
    t2 = ((char*)((ng51)));
    t3 = (t0 + 6744);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(103, ng42);
    t2 = ((char*)((ng9)));
    t3 = (t0 + 7224);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);
    xsi_set_current_line(104, ng42);
    t2 = (t0 + 6744);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t7 = (t0 + 7064);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t0 + 7224);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t0 + 14336);
    t14 = (t0 + 1280);
    t15 = xsi_create_subprogram_invocation(t13, 0, t0, t14, 0, 0);
    t16 = (t0 + 8184);
    xsi_vlogvar_assign_value(t16, t4, 0, 0, 32);
    t17 = (t0 + 8344);
    xsi_vlogvar_assign_value(t17, t9, 0, 0, 32);
    t18 = (t0 + 8504);
    xsi_vlogvar_assign_value(t18, t12, 0, 0, 32);

LAB33:    t19 = (t0 + 14432);
    t20 = *((char **)t19);
    t21 = (t20 + 80U);
    t22 = *((char **)t21);
    t23 = (t22 + 272U);
    t24 = *((char **)t23);
    t25 = (t24 + 0U);
    t27 = *((char **)t25);
    t6 = ((int  (*)(char *, char *))t27)(t0, t20);
    if (t6 != 0)
        goto LAB35;

LAB34:    t20 = (t0 + 14432);
    t28 = *((char **)t20);
    t20 = (t0 + 8024);
    t29 = (t20 + 56U);
    t30 = *((char **)t29);
    memcpy(t26, t30, 8);
    t48 = (t0 + 1280);
    t49 = (t0 + 14336);
    t50 = 0;
    xsi_delete_subprogram_invocation(t48, t28, t0, t49, t50);
    t51 = (t0 + 5624);
    xsi_vlogvar_assign_value(t51, t26, 0, 0, 1);
    xsi_set_current_line(107, ng42);
    t2 = (t0 + 2824U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t26, 0, 8);
    t4 = (t3 + 4);
    t7 = (t2 + 4);
    t31 = *((unsigned int *)t3);
    t32 = *((unsigned int *)t2);
    t33 = (t31 ^ t32);
    t34 = *((unsigned int *)t4);
    t35 = *((unsigned int *)t7);
    t36 = (t34 ^ t35);
    t37 = (t33 | t36);
    t38 = *((unsigned int *)t4);
    t39 = *((unsigned int *)t7);
    t40 = (t38 | t39);
    t41 = (~(t40));
    t42 = (t37 & t41);
    if (t42 != 0)
        goto LAB39;

LAB36:    if (t40 != 0)
        goto LAB38;

LAB37:    *((unsigned int *)t26) = 1;

LAB39:    t9 = (t26 + 4);
    t43 = *((unsigned int *)t9);
    t44 = (~(t43));
    t45 = *((unsigned int *)t26);
    t46 = (t45 & t44);
    t47 = (t46 != 0);
    if (t47 > 0)
        goto LAB40;

LAB41:
LAB42:    goto LAB15;

LAB19:    t15 = (t0 + 14528U);
    *((char **)t15) = &&LAB17;
    goto LAB1;

LAB22:    t8 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB23;

LAB24:    xsi_set_current_line(84, ng42);

LAB27:    xsi_set_current_line(85, ng42);
    t10 = (t0 + 7224);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t0 + 6264);
    xsi_vlogvar_assign_value(t13, t12, 0, 0, 32);
    goto LAB26;

LAB31:    t19 = (t0 + 14528U);
    *((char **)t19) = &&LAB29;
    goto LAB1;

LAB35:    t19 = (t0 + 14528U);
    *((char **)t19) = &&LAB33;
    goto LAB1;

LAB38:    t8 = (t26 + 4);
    *((unsigned int *)t26) = 1;
    *((unsigned int *)t8) = 1;
    goto LAB39;

LAB40:    xsi_set_current_line(107, ng42);

LAB43:    xsi_set_current_line(108, ng42);
    t10 = (t0 + 7224);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t0 + 6424);
    xsi_vlogvar_assign_value(t13, t12, 0, 0, 32);
    goto LAB42;

}


extern void work_m_00000000003854107599_2524751178_init()
{
	static char *pe[] = {(void *)Cont_26_0,(void *)Cont_27_1,(void *)NetDecl_29_2,(void *)NetDecl_30_3,(void *)NetDecl_31_4,(void *)NetDecl_33_5,(void *)NetDecl_34_6,(void *)NetDecl_35_7,(void *)NetDecl_36_8,(void *)NetDecl_37_9,(void *)NetDecl_39_10,(void *)NetDecl_41_11,(void *)NetDecl_42_12,(void *)NetDecl_43_13,(void *)NetDecl_44_14,(void *)NetDecl_45_15,(void *)NetDecl_46_16,(void *)Initial_59_17,(void *)Always_75_18};
	static char *se[] = {(void *)sp_TEST_LDI,(void *)sp_TEST_IN,(void *)sp_TEST_OUT};
	xsi_register_didat("work_m_00000000003854107599_2524751178", "isim/unitTestCpu_isim_beh.exe.sim/work/m_00000000003854107599_2524751178.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
