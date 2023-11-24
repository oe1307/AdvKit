from pyadv.attack.whitebox import FgsmConfig

config_dict = {
    # --- whitebox attack ---
    "Fgsm": FgsmConfig,
    # --- blackbox attack ---
}


def set_config(setting: dict):
    return config_dict[setting["attacker"]](setting)
