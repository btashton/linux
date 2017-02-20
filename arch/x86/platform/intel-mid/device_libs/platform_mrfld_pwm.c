#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/pinctrl/machine.h>
#include <linux/pinctrl/pinconf-generic.h>

static unsigned long pwm_config[] = {
	PIN_CONF_PACKED(PIN_CONFIG_BIAS_DISABLE, 0),
};

static struct pinctrl_map pwm_mapping[] __initdata = {
	PIN_MAP_MUX_GROUP_DEFAULT("0000:00:17.0", "pinctrl-merrifield", "pwm0_grp", "pwm0"),
	PIN_MAP_MUX_GROUP_DEFAULT("0000:00:17.0", "pinctrl-merrifield", "pwm1_grp", "pwm1"),
	PIN_MAP_MUX_GROUP_DEFAULT("0000:00:17.0", "pinctrl-merrifield", "pwm2_grp", "pwm2"),
	PIN_MAP_MUX_GROUP_DEFAULT("0000:00:17.0", "pinctrl-merrifield", "pwm3_grp", "pwm3"),
	PIN_MAP_CONFIGS_PIN_DEFAULT("0000:00:17.0", "pinctrl-merrifield", "GP12_PWM0", pwm_config),
	PIN_MAP_CONFIGS_PIN_DEFAULT("0000:00:17.0", "pinctrl-merrifield", "GP13_PWM1", pwm_config),
	PIN_MAP_CONFIGS_PIN_DEFAULT("0000:00:17.0", "pinctrl-merrifield", "GP182_PWM2", pwm_config),
	PIN_MAP_CONFIGS_PIN_DEFAULT("0000:00:17.0", "pinctrl-merrifield", "GP183_PWM3", pwm_config),
};

static int __init mrfld_pwm_init(void)
{
	return pinctrl_register_mappings(pwm_mapping, ARRAY_SIZE(pwm_mapping));
}

arch_initcall(mrfld_pwm_init);
