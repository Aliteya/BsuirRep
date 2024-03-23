from model.model_base import ModelBase
from view.view_interf import Interface

class ControllerBase:
    def __init__(self,base: ModelBase, gui: Interface):
        self.model = base
        self.gui = gui
        self.gui.view_loading(self.model)

    def insert_entry(self):
        self.gui.visual_start()

    def search(self):
        self.gui.search_delete_gui(self.model)
        
        
        
