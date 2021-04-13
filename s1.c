
static int unused_p_id = -1;
static int unused_value = -1;

static int
dissect_s1ap_Criticality(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, FALSE, 0, NULL, 1);

  return offset;
}

static int
dissect_s1ap_ProtocolIE_ID(tvbuff_t *tvb, int offset) {
                                                            0U, 65535U, &s1ap_data->protocol_ie_id, FALSE);




  if (tree) {
    proto_item_append_text(proto_item_get_parent_nth(actx->created_item, 2), ": %s",
                           val_to_str_ext(s1ap_data->protocol_ie_id, &s1ap_ProtocolIE_ID_vals_ext, "unknown (%d)"));
  }

  return offset;
}



static int
dissect_s1ap_T_ie_field_value(tvbuff_t *tvb, int offset) {
  offset = dissect_per_open_type_pdu_new(tvb, offset,  dissect_ProtocolIEFieldValue);

  return offset;
}


static const per_sequence_t ProtocolIE_Field_sequence[] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_ID },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_Criticality },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_T_ie_field_value },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ProtocolIE_Field(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ProtocolIE_Field, ProtocolIE_Field_sequence);

  return offset;
}


static const per_sequence_t ProtocolIE_Container_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Field },
};

static int
dissect_s1ap_ProtocolIE_Container(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ProtocolIE_Container, ProtocolIE_Container_sequence_of,
                                                  0, maxProtocolIEs, FALSE);

  return offset;
}



static int
dissect_s1ap_ProtocolIE_SingleContainer(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_ProtocolIE_Field(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t ProtocolIE_ContainerList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_ProtocolIE_ContainerList(tvbuff_t *tvb, int offset) {
  static const asn1_par_def_t ProtocolIE_ContainerList_pars[] = {
    { "lowerBound", ASN1_PAR_INTEGER },
    { "upperBound", ASN1_PAR_INTEGER },
    { NULL, (asn1_par_type)0 }
  };
  asn1_stack_frame_check(actx, "ProtocolIE-ContainerList", ProtocolIE_ContainerList_pars);

  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ProtocolIE_ContainerList, ProtocolIE_ContainerList_sequence_of,
                                                  asn1_param_get_integer(actx,"lowerBound"), asn1_param_get_integer(actx,"upperBound"), FALSE);

  return offset;
}



static int
dissect_s1ap_T_extensionValue(tvbuff_t *tvb, int offset) {
  offset = dissect_per_open_type_pdu_new(tvb, offset,  dissect_ProtocolExtensionFieldExtensionValue);

  return offset;
}


static const per_sequence_t ProtocolExtensionField_sequence[] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolExtensionID },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_Criticality },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_T_extensionValue },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ProtocolExtensionField(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ProtocolExtensionField, ProtocolExtensionField_sequence);

  return offset;
}


static const per_sequence_t ProtocolExtensionContainer_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolExtensionField },
};

static int
dissect_s1ap_ProtocolExtensionContainer(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ProtocolExtensionContainer, ProtocolExtensionContainer_sequence_of,
                                                  1, maxProtocolExtensions, FALSE);

  return offset;
}



static int
dissect_s1ap_T_value(tvbuff_t *tvb, int offset) {
    offset = call_per_oid_callback(s1ap_data->obj_id, tvb, actx->pinfo, tree, offset, actx, hf_index);
  } else {
  offset = dissect_per_open_type(tvb, offset,  NULL);

  }





  return offset;
}


static const per_sequence_t PrivateIE_Field_sequence[] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_PrivateIE_ID },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_Criticality },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_T_value },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PrivateIE_Field(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PrivateIE_Field, PrivateIE_Field_sequence);

  return offset;
}


static const per_sequence_t PrivateIE_Container_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_PrivateIE_Field },
};

static int
dissect_s1ap_PrivateIE_Container(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_PrivateIE_Container, PrivateIE_Container_sequence_of,
                                                  1, maxPrivateIEs, FALSE);

  return offset;
}




static int
dissect_s1ap_PLMNidentity(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb=NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       3, 3, FALSE, &parameter_tvb);
  if(tvb_reported_length(tvb)==0)
    return offset;

  if (!parameter_tvb)
    return offset;
  dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, tree, 0, E212_NONE, FALSE);
  if (s1ap_data->supported_ta) {
    guint32 plmn = tvb_get_ntoh24(parameter_tvb, 0);
    wmem_array_append_one(s1ap_data->supported_ta->plmn, plmn);
  } else if (s1ap_data->tai) {
    s1ap_data->tai->plmn = tvb_get_ntoh24(parameter_tvb, 0);
  }


  return offset;
}



static int
dissect_s1ap_MME_Group_ID(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       2, 2, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
  }



  return offset;
}



static int
dissect_s1ap_MME_Code(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       1, 1, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
  }



  return offset;
}


static const per_sequence_t GUMMEI_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_MME_Group_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_MME_Code },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_GUMMEI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_GUMMEI, GUMMEI_sequence);

  return offset;
}



static int
dissect_s1ap_M_TMSI(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  proto_item *ti;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       4, 4, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
    ti = proto_tree_add_item(tree, hf_3gpp_tmsi, tvb, 0, 4, ENC_BIG_ENDIAN);
    proto_item_set_hidden(ti);

  }



  return offset;
}


static const per_sequence_t Additional_GUTI_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GUMMEI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_M_TMSI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_Additional_GUTI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Additional_GUTI, Additional_GUTI_sequence);

  return offset;
}



static int
dissect_s1ap_AdditionalRRMPriorityIndex(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     32, 32, FALSE, NULL, 0, NULL, NULL);

  return offset;
}


static const value_string s1ap_AerialUEsubscriptionInformation_vals[] = {
  {   0, "allowed" },
  {   1, "not-allowed" },
  { 0, NULL }
};


static int
dissect_s1ap_AerialUEsubscriptionInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_CellIdentity(tvbuff_t *tvb, int offset) {
  tvbuff_t *cell_id_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
                                     28, 28, FALSE, NULL, 0, &cell_id_tvb, NULL);

  if (cell_id_tvb) {
    guint32 cell_id = tvb_get_bits32(cell_id_tvb, 0, 28, ENC_BIG_ENDIAN);
    actx->created_item = proto_tree_add_uint(tree, hf_index, cell_id_tvb, 0, 4, cell_id);
  }


  return offset;
}


static const per_sequence_t EUTRAN_CGI_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CellIdentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EUTRAN_CGI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EUTRAN_CGI, EUTRAN_CGI_sequence);

  return offset;
}


static const per_sequence_t CellIdListforMDT_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
};

static int
dissect_s1ap_CellIdListforMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CellIdListforMDT, CellIdListforMDT_sequence_of,
                                                  1, maxnoofCellIDforMDT, FALSE);

  return offset;
}


static const per_sequence_t CellBasedMDT_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CellIdListforMDT },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellBasedMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellBasedMDT, CellBasedMDT_sequence);

  return offset;
}



static int
dissect_s1ap_TAC(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
                                       2, 2, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
    if (s1ap_data->supported_ta) {
      s1ap_data->supported_ta->tac = tvb_get_ntohs(parameter_tvb, 0);
    } else if (s1ap_data->tai) {
      s1ap_data->tai->tac = tvb_get_ntohs(parameter_tvb, 0);
    }
  }



  return offset;
}


static const per_sequence_t TAListforMDT_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TAC },
};

static int
dissect_s1ap_TAListforMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_TAListforMDT, TAListforMDT_sequence_of,
                                                  1, maxnoofTAforMDT, FALSE);

  return offset;
}


static const per_sequence_t TABasedMDT_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAListforMDT },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TABasedMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TABasedMDT, TABasedMDT_sequence);

  return offset;
}



static int
dissect_s1ap_NULL(tvbuff_t *tvb, int offset) {
  offset = dissect_per_null(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t TAI_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TAI(tvbuff_t *tvb, int offset) {
  s1ap_data->tai = wmem_new0(wmem_packet_scope(), struct s1ap_tai);
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TAI, TAI_sequence);

  if (!PINFO_FD_VISITED(actx->pinfo) && s1ap_data->s1ap_conv &&
      (s1ap_data->message_type == INITIATING_MESSAGE) &&
      (s1ap_data->procedure_code == id_initialUEMessage)) {
    guint64 key = (s1ap_data->tai->plmn << 16) | s1ap_data->tai->tac;

    if (wmem_map_lookup(s1ap_data->s1ap_conv->nbiot_ta, &key)) {
      wmem_tree_key_t tree_key[3];
      guint32 *id = wmem_new(wmem_file_scope(), guint32);

      *id = s1ap_data->enb_ue_s1ap_id;
      tree_key[0].length = 1;
      tree_key[0].key = id;
      tree_key[1].length = 1;
      tree_key[1].key = &actx->pinfo->num;
      tree_key[2].length = 0;
      tree_key[2].key = NULL;
      wmem_tree_insert32_array(s1ap_data->s1ap_conv->nbiot_enb_ue_s1ap_id, tree_key, id);
    }
  }



  return offset;
}


static const per_sequence_t TAIListforMDT_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
};

static int
dissect_s1ap_TAIListforMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_TAIListforMDT, TAIListforMDT_sequence_of,
                                                  1, maxnoofTAforMDT, FALSE);

  return offset;
}


static const per_sequence_t TAIBasedMDT_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAIListforMDT },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TAIBasedMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TAIBasedMDT, TAIBasedMDT_sequence);

  return offset;
}


static const value_string s1ap_AreaScopeOfMDT_vals[] = {
  {   0, "cellBased" },
  {   1, "tABased" },
  {   2, "pLMNWide" },
  {   3, "tAIBased" },
  { 0, NULL }
};

static const per_choice_t AreaScopeOfMDT_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CellBasedMDT },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_TABasedMDT },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_NULL },
  {   3,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_TAIBasedMDT },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_AreaScopeOfMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_AreaScopeOfMDT, AreaScopeOfMDT_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t CellIdListforQMC_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
};

static int
dissect_s1ap_CellIdListforQMC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CellIdListforQMC, CellIdListforQMC_sequence_of,
                                                  1, maxnoofCellIDforQMC, FALSE);

  return offset;
}


static const per_sequence_t CellBasedQMC_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CellIdListforQMC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellBasedQMC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellBasedQMC, CellBasedQMC_sequence);

  return offset;
}


static const per_sequence_t TAListforQMC_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TAC },
};

static int
dissect_s1ap_TAListforQMC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_TAListforQMC, TAListforQMC_sequence_of,
                                                  1, maxnoofTAforQMC, FALSE);

  return offset;
}


static const per_sequence_t TABasedQMC_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAListforQMC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TABasedQMC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TABasedQMC, TABasedQMC_sequence);

  return offset;
}


static const per_sequence_t TAIListforQMC_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
};

static int
dissect_s1ap_TAIListforQMC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_TAIListforQMC, TAIListforQMC_sequence_of,
                                                  1, maxnoofTAforQMC, FALSE);

  return offset;
}


static const per_sequence_t TAIBasedQMC_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAIListforQMC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TAIBasedQMC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TAIBasedQMC, TAIBasedQMC_sequence);

  return offset;
}


static const per_sequence_t PLMNListforQMC_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
};

static int
dissect_s1ap_PLMNListforQMC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_PLMNListforQMC, PLMNListforQMC_sequence_of,
                                                  1, maxnoofPLMNforQMC, FALSE);

  return offset;
}


static const per_sequence_t PLMNAreaBasedQMC_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNListforQMC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PLMNAreaBasedQMC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PLMNAreaBasedQMC, PLMNAreaBasedQMC_sequence);

  return offset;
}


static const value_string s1ap_AreaScopeOfQMC_vals[] = {
  {   0, "cellBased" },
  {   1, "tABased" },
  {   2, "tAIBased" },
  {   3, "pLMNAreaBased" },
  { 0, NULL }
};

static const per_choice_t AreaScopeOfQMC_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CellBasedQMC },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_TABasedQMC },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_TAIBasedQMC },
  {   3,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_PLMNAreaBasedQMC },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_AreaScopeOfQMC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_AreaScopeOfQMC, AreaScopeOfQMC_choice,
                                 NULL);

  return offset;
}


static const value_string s1ap_PriorityLevel_vals[] = {
  {   0, "spare" },
  {   1, "highest" },
  {  14, "lowest" },
  {  15, "no-priority" },
  { 0, NULL }
};


static int
dissect_s1ap_PriorityLevel(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 15U, NULL, FALSE);

  return offset;
}


static const value_string s1ap_Pre_emptionCapability_vals[] = {
  {   0, "shall-not-trigger-pre-emption" },
  {   1, "may-trigger-pre-emption" },
  { 0, NULL }
};


static int
dissect_s1ap_Pre_emptionCapability(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, FALSE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_Pre_emptionVulnerability_vals[] = {
  {   0, "not-pre-emptable" },
  {   1, "pre-emptable" },
  { 0, NULL }
};


static int
dissect_s1ap_Pre_emptionVulnerability(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, FALSE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t AllocationAndRetentionPriority_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PriorityLevel },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Pre_emptionCapability },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Pre_emptionVulnerability },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_AllocationAndRetentionPriority(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_AllocationAndRetentionPriority, AllocationAndRetentionPriority_sequence);

  return offset;
}



static int
dissect_s1ap_CELevel(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_CELevel);
    if ((s1ap_is_nbiot_ue(actx->pinfo) && (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_AUTOMATIC)) ||
        (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_NBIOT)) {
      TRY {
        dissect_lte_rrc_UEPagingCoverageInformation_NB_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
      }
      CATCH_BOUNDS_ERRORS {
        show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
      }
      ENDTRY;
    } else {
      TRY {
        dissect_lte_rrc_UEPagingCoverageInformation_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
      }
      CATCH_BOUNDS_ERRORS {
        show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
      }
      ENDTRY;
    }
  }



  return offset;
}


static const per_sequence_t CellIdentifierAndCELevelForCECapableUEs_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CELevel },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellIdentifierAndCELevelForCECapableUEs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellIdentifierAndCELevelForCECapableUEs, CellIdentifierAndCELevelForCECapableUEs_sequence);

  return offset;
}


static const per_sequence_t AssistanceDataForCECapableUEs_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CellIdentifierAndCELevelForCECapableUEs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_AssistanceDataForCECapableUEs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_AssistanceDataForCECapableUEs, AssistanceDataForCECapableUEs_sequence);

  return offset;
}


static const per_sequence_t RecommendedCellList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_RecommendedCellList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_RecommendedCellList, RecommendedCellList_sequence_of,
                                                  1, maxnoofRecommendedCells, FALSE);

  return offset;
}


static const per_sequence_t RecommendedCellsForPaging_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RecommendedCellList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_RecommendedCellsForPaging(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_RecommendedCellsForPaging, RecommendedCellsForPaging_sequence);

  return offset;
}


static const per_sequence_t AssistanceDataForRecommendedCells_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RecommendedCellsForPaging },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_AssistanceDataForRecommendedCells(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_AssistanceDataForRecommendedCells, AssistanceDataForRecommendedCells_sequence);

  return offset;
}



static int
dissect_s1ap_PagingAttemptCount(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 16U, NULL, TRUE);

  return offset;
}



static int
dissect_s1ap_IntendedNumberOfPagingAttempts(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 16U, NULL, TRUE);

  return offset;
}


static const value_string s1ap_NextPagingAreaScope_vals[] = {
  {   0, "same" },
  {   1, "changed" },
  { 0, NULL }
};


static int
dissect_s1ap_NextPagingAreaScope(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t PagingAttemptInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PagingAttemptCount },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_IntendedNumberOfPagingAttempts },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_NextPagingAreaScope },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PagingAttemptInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PagingAttemptInformation, PagingAttemptInformation_sequence);

  return offset;
}


static const per_sequence_t AssistanceDataForPaging_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_AssistanceDataForRecommendedCells },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_AssistanceDataForCECapableUEs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_PagingAttemptInformation },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_AssistanceDataForPaging(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_AssistanceDataForPaging, AssistanceDataForPaging_sequence);

  return offset;
}


static const per_sequence_t Bearers_SubjectToStatusTransferList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_Bearers_SubjectToStatusTransferList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_Bearers_SubjectToStatusTransferList, Bearers_SubjectToStatusTransferList_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}



static int
dissect_s1ap_E_RAB_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 15U, NULL, TRUE);

  return offset;
}



static int
dissect_s1ap_PDCP_SN(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 4095U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_HFN(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 1048575U, NULL, FALSE);

  return offset;
}


static const per_sequence_t COUNTvalue_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PDCP_SN },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_HFN },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_COUNTvalue(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_COUNTvalue, COUNTvalue_sequence);

  return offset;
}



static int
dissect_s1ap_ReceiveStatusofULPDCPSDUs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     4096, 4096, FALSE, NULL, 0, NULL, NULL);

  return offset;
}


static const per_sequence_t Bearers_SubjectToStatusTransfer_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_COUNTvalue },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_COUNTvalue },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ReceiveStatusofULPDCPSDUs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_Bearers_SubjectToStatusTransfer_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Bearers_SubjectToStatusTransfer_Item, Bearers_SubjectToStatusTransfer_Item_sequence);

  return offset;
}


static const per_sequence_t Bearers_SubjectToEarlyStatusTransferList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_Bearers_SubjectToEarlyStatusTransferList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_Bearers_SubjectToEarlyStatusTransferList, Bearers_SubjectToEarlyStatusTransferList_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}



static int
dissect_s1ap_PDCP_SNExtended(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 32767U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_HFNModified(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 131071U, NULL, FALSE);

  return offset;
}


static const per_sequence_t COUNTValueExtended_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PDCP_SNExtended },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_HFNModified },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_COUNTValueExtended(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_COUNTValueExtended, COUNTValueExtended_sequence);

  return offset;
}



static int
dissect_s1ap_PDCP_SNlength18(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 262143U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_HFNforPDCP_SNlength18(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 16383U, NULL, FALSE);

  return offset;
}


static const per_sequence_t COUNTvaluePDCP_SNlength18_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PDCP_SNlength18 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_HFNforPDCP_SNlength18 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_COUNTvaluePDCP_SNlength18(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_COUNTvaluePDCP_SNlength18, COUNTvaluePDCP_SNlength18_sequence);

  return offset;
}


static const value_string s1ap_DLCOUNT_PDCP_SNlength_vals[] = {
  {   0, "dLCOUNTValuePDCP-SNlength12" },
  {   1, "dLCOUNTValuePDCP-SNlength15" },
  {   2, "dLCOUNTValuePDCP-SNlength18" },
  { 0, NULL }
};

static const per_choice_t DLCOUNT_PDCP_SNlength_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_COUNTvalue },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_COUNTValueExtended },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_COUNTvaluePDCP_SNlength18 },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_DLCOUNT_PDCP_SNlength(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_DLCOUNT_PDCP_SNlength, DLCOUNT_PDCP_SNlength_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t Bearers_SubjectToEarlyStatusTransfer_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_DLCOUNT_PDCP_SNlength },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_Bearers_SubjectToEarlyStatusTransfer_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Bearers_SubjectToEarlyStatusTransfer_Item, Bearers_SubjectToEarlyStatusTransfer_Item_sequence);

  return offset;
}


static const value_string s1ap_BearerType_vals[] = {
  {   0, "non-IP" },
  { 0, NULL }
};


static int
dissect_s1ap_BearerType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_BitRate(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer_64b(tvb, offset, 
                                                            0U, G_GUINT64_CONSTANT(10000000000), NULL, FALSE);

  return offset;
}


static const value_string s1ap_BluetoothMeasConfig_vals[] = {
  {   0, "setup" },
  { 0, NULL }
};


static int
dissect_s1ap_BluetoothMeasConfig(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_BluetoothName(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       1, 248, FALSE, &parameter_tvb);

  actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, -1, ENC_UTF_8|ENC_NA);


  return offset;
}


static const per_sequence_t BluetoothMeasConfigNameList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_BluetoothName },
};

static int
dissect_s1ap_BluetoothMeasConfigNameList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_BluetoothMeasConfigNameList, BluetoothMeasConfigNameList_sequence_of,
                                                  1, maxnoofBluetoothName, FALSE);

  return offset;
}


static const value_string s1ap_T_bt_rssi_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_T_bt_rssi(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t BluetoothMeasurementConfiguration_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BluetoothMeasConfig },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_BluetoothMeasConfigNameList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_T_bt_rssi },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_BluetoothMeasurementConfiguration(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_BluetoothMeasurementConfiguration, BluetoothMeasurementConfiguration_sequence);

  return offset;
}


static const per_sequence_t BPLMNs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
};

static int
dissect_s1ap_BPLMNs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_BPLMNs, BPLMNs_sequence_of,
                                                  1, maxnoofBPLMNs, FALSE);

  return offset;
}



static int
dissect_s1ap_NumberOfBroadcasts(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 65535U, NULL, FALSE);

  return offset;
}


static const per_sequence_t CellID_Cancelled_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NumberOfBroadcasts },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellID_Cancelled_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellID_Cancelled_Item, CellID_Cancelled_Item_sequence);

  return offset;
}


static const per_sequence_t CellID_Cancelled_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CellID_Cancelled_Item },
};

static int
dissect_s1ap_CellID_Cancelled(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CellID_Cancelled, CellID_Cancelled_sequence_of,
                                                  1, maxnoofCellID, FALSE);

  return offset;
}


static const per_sequence_t CancelledCellinTAI_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NumberOfBroadcasts },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CancelledCellinTAI_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CancelledCellinTAI_Item, CancelledCellinTAI_Item_sequence);

  return offset;
}


static const per_sequence_t CancelledCellinTAI_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CancelledCellinTAI_Item },
};

static int
dissect_s1ap_CancelledCellinTAI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CancelledCellinTAI, CancelledCellinTAI_sequence_of,
                                                  1, maxnoofCellinTAI, FALSE);

  return offset;
}


static const per_sequence_t TAI_Cancelled_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CancelledCellinTAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TAI_Cancelled_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TAI_Cancelled_Item, TAI_Cancelled_Item_sequence);

  return offset;
}


static const per_sequence_t TAI_Cancelled_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI_Cancelled_Item },
};

static int
dissect_s1ap_TAI_Cancelled(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_TAI_Cancelled, TAI_Cancelled_sequence_of,
                                                  1, maxnoofTAIforWarning, FALSE);

  return offset;
}



static int
dissect_s1ap_EmergencyAreaID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       3, 3, FALSE, NULL);

  return offset;
}


static const per_sequence_t CancelledCellinEAI_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NumberOfBroadcasts },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CancelledCellinEAI_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CancelledCellinEAI_Item, CancelledCellinEAI_Item_sequence);

  return offset;
}


static const per_sequence_t CancelledCellinEAI_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CancelledCellinEAI_Item },
};

static int
dissect_s1ap_CancelledCellinEAI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CancelledCellinEAI, CancelledCellinEAI_sequence_of,
                                                  1, maxnoofCellinEAI, FALSE);

  return offset;
}


static const per_sequence_t EmergencyAreaID_Cancelled_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EmergencyAreaID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CancelledCellinEAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EmergencyAreaID_Cancelled_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EmergencyAreaID_Cancelled_Item, EmergencyAreaID_Cancelled_Item_sequence);

  return offset;
}


static const per_sequence_t EmergencyAreaID_Cancelled_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_EmergencyAreaID_Cancelled_Item },
};

static int
dissect_s1ap_EmergencyAreaID_Cancelled(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_EmergencyAreaID_Cancelled, EmergencyAreaID_Cancelled_sequence_of,
                                                  1, maxnoofEmergencyAreaID, FALSE);

  return offset;
}


static const value_string s1ap_BroadcastCancelledAreaList_vals[] = {
  {   0, "cellID-Cancelled" },
  {   1, "tAI-Cancelled" },
  {   2, "emergencyAreaID-Cancelled" },
  { 0, NULL }
};

static const per_choice_t BroadcastCancelledAreaList_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CellID_Cancelled },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_TAI_Cancelled },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_EmergencyAreaID_Cancelled },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_BroadcastCancelledAreaList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_BroadcastCancelledAreaList, BroadcastCancelledAreaList_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t CellID_Broadcast_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellID_Broadcast_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellID_Broadcast_Item, CellID_Broadcast_Item_sequence);

  return offset;
}


static const per_sequence_t CellID_Broadcast_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CellID_Broadcast_Item },
};

static int
dissect_s1ap_CellID_Broadcast(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CellID_Broadcast, CellID_Broadcast_sequence_of,
                                                  1, maxnoofCellID, FALSE);

  return offset;
}


static const per_sequence_t CompletedCellinTAI_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CompletedCellinTAI_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CompletedCellinTAI_Item, CompletedCellinTAI_Item_sequence);

  return offset;
}


static const per_sequence_t CompletedCellinTAI_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CompletedCellinTAI_Item },
};

static int
dissect_s1ap_CompletedCellinTAI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CompletedCellinTAI, CompletedCellinTAI_sequence_of,
                                                  1, maxnoofCellinTAI, FALSE);

  return offset;
}


static const per_sequence_t TAI_Broadcast_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CompletedCellinTAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TAI_Broadcast_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TAI_Broadcast_Item, TAI_Broadcast_Item_sequence);

  return offset;
}


static const per_sequence_t TAI_Broadcast_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI_Broadcast_Item },
};

static int
dissect_s1ap_TAI_Broadcast(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_TAI_Broadcast, TAI_Broadcast_sequence_of,
                                                  1, maxnoofTAIforWarning, FALSE);

  return offset;
}


static const per_sequence_t CompletedCellinEAI_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CompletedCellinEAI_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CompletedCellinEAI_Item, CompletedCellinEAI_Item_sequence);

  return offset;
}


static const per_sequence_t CompletedCellinEAI_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CompletedCellinEAI_Item },
};

static int
dissect_s1ap_CompletedCellinEAI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CompletedCellinEAI, CompletedCellinEAI_sequence_of,
                                                  1, maxnoofCellinEAI, FALSE);

  return offset;
}


static const per_sequence_t EmergencyAreaID_Broadcast_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EmergencyAreaID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CompletedCellinEAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EmergencyAreaID_Broadcast_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EmergencyAreaID_Broadcast_Item, EmergencyAreaID_Broadcast_Item_sequence);

  return offset;
}


static const per_sequence_t EmergencyAreaID_Broadcast_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_EmergencyAreaID_Broadcast_Item },
};

static int
dissect_s1ap_EmergencyAreaID_Broadcast(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_EmergencyAreaID_Broadcast, EmergencyAreaID_Broadcast_sequence_of,
                                                  1, maxnoofEmergencyAreaID, FALSE);

  return offset;
}


static const value_string s1ap_BroadcastCompletedAreaList_vals[] = {
  {   0, "cellID-Broadcast" },
  {   1, "tAI-Broadcast" },
  {   2, "emergencyAreaID-Broadcast" },
  { 0, NULL }
};

static const per_choice_t BroadcastCompletedAreaList_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CellID_Broadcast },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_TAI_Broadcast },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_EmergencyAreaID_Broadcast },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_BroadcastCompletedAreaList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_BroadcastCompletedAreaList, BroadcastCompletedAreaList_choice,
                                 NULL);

  return offset;
}


const value_string s1ap_CauseRadioNetwork_vals[] = {
  {   0, "unspecified" },
  {   1, "tx2relocoverall-expiry" },
  {   2, "successful-handover" },
  {   3, "release-due-to-eutran-generated-reason" },
  {   4, "handover-cancelled" },
  {   5, "partial-handover" },
  {   6, "ho-failure-in-target-EPC-eNB-or-target-system" },
  {   7, "ho-target-not-allowed" },
  {   8, "tS1relocoverall-expiry" },
  {   9, "tS1relocprep-expiry" },
  {  10, "cell-not-available" },
  {  11, "unknown-targetID" },
  {  12, "no-radio-resources-available-in-target-cell" },
  {  13, "unknown-mme-ue-s1ap-id" },
  {  14, "unknown-enb-ue-s1ap-id" },
  {  15, "unknown-pair-ue-s1ap-id" },
  {  16, "handover-desirable-for-radio-reason" },
  {  17, "time-critical-handover" },
  {  18, "resource-optimisation-handover" },
  {  19, "reduce-load-in-serving-cell" },
  {  20, "user-inactivity" },
  {  21, "radio-connection-with-ue-lost" },
  {  22, "load-balancing-tau-required" },
  {  23, "cs-fallback-triggered" },
  {  24, "ue-not-available-for-ps-service" },
  {  25, "radio-resources-not-available" },
  {  26, "failure-in-radio-interface-procedure" },
  {  27, "invalid-qos-combination" },
  {  28, "interrat-redirection" },
  {  29, "interaction-with-other-procedure" },
  {  30, "unknown-E-RAB-ID" },
  {  31, "multiple-E-RAB-ID-instances" },
  {  32, "encryption-and-or-integrity-protection-algorithms-not-supported" },
  {  33, "s1-intra-system-handover-triggered" },
  {  34, "s1-inter-system-handover-triggered" },
  {  35, "x2-handover-triggered" },
  {  36, "redirection-towards-1xRTT" },
  {  37, "not-supported-QCI-value" },
  {  38, "invalid-CSG-Id" },
  {  39, "release-due-to-pre-emption" },
  {  40, "n26-interface-not-available" },
  { 0, NULL }
};

static value_string_ext s1ap_CauseRadioNetwork_vals_ext = VALUE_STRING_EXT_INIT(s1ap_CauseRadioNetwork_vals);


static int
dissect_s1ap_CauseRadioNetwork(tvbuff_t *tvb, int offset) {
  guint32 value;
  offset = dissect_per_enumerated(tvb, offset, 36, &value, TRUE, 5, NULL, 1);

  col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [RadioNetwork-cause=%s]", val_to_str_const(value, s1ap_CauseRadioNetwork_vals, "Unknown"));



  return offset;
}


const value_string s1ap_CauseTransport_vals[] = {
  {   0, "transport-resource-unavailable" },
  {   1, "unspecified" },
  { 0, NULL }
};


static int
dissect_s1ap_CauseTransport(tvbuff_t *tvb, int offset) {
  guint32 value;
  offset = dissect_per_enumerated(tvb, offset, 2, &value, TRUE, 0, NULL, 1);

  col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [Transport-cause=%s]", val_to_str_const(value, s1ap_CauseTransport_vals, "Unknown"));



  return offset;
}


const value_string s1ap_CauseNas_vals[] = {
  {   0, "normal-release" },
  {   1, "authentication-failure" },
  {   2, "detach" },
  {   3, "unspecified" },
  {   4, "csg-subscription-expiry" },
  { 0, NULL }
};


static int
dissect_s1ap_CauseNas(tvbuff_t *tvb, int offset) {
  guint32 value;
  offset = dissect_per_enumerated(tvb, offset, 4, &value, TRUE, 1, NULL, 1);

  col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [NAS-cause=%s]", val_to_str_const(value, s1ap_CauseNas_vals, "Unknown"));



  return offset;
}


const value_string s1ap_CauseProtocol_vals[] = {
  {   0, "transfer-syntax-error" },
  {   1, "abstract-syntax-error-reject" },
  {   2, "abstract-syntax-error-ignore-and-notify" },
  {   3, "message-not-compatible-with-receiver-state" },
  {   4, "semantic-error" },
  {   5, "abstract-syntax-error-falsely-constructed-message" },
  {   6, "unspecified" },
  { 0, NULL }
};


static int
dissect_s1ap_CauseProtocol(tvbuff_t *tvb, int offset) {
  guint32 value;
  offset = dissect_per_enumerated(tvb, offset, 7, &value, TRUE, 0, NULL, 1);

  col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [Protocol-cause=%s]", val_to_str_const(value, s1ap_CauseProtocol_vals, "Unknown"));



  return offset;
}


const value_string s1ap_CauseMisc_vals[] = {
  {   0, "control-processing-overload" },
  {   1, "not-enough-user-plane-processing-resources" },
  {   2, "hardware-failure" },
  {   3, "om-intervention" },
  {   4, "unspecified" },
  {   5, "unknown-PLMN" },
  { 0, NULL }
};


static int
dissect_s1ap_CauseMisc(tvbuff_t *tvb, int offset) {
  guint32 value;
  offset = dissect_per_enumerated(tvb, offset, 6, &value, TRUE, 0, NULL, 1);

  col_append_fstr(actx->pinfo->cinfo, COL_INFO, " [Misc-cause=%s]", val_to_str_const(value, s1ap_CauseMisc_vals, "Unknown"));



  return offset;
}


const value_string s1ap_Cause_vals[] = {
  {   0, "radioNetwork" },
  {   1, "transport" },
  {   2, "nas" },
  {   3, "protocol" },
  {   4, "misc" },
  { 0, NULL }
};

static const per_choice_t Cause_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CauseRadioNetwork },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CauseTransport },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CauseNas },
  {   3,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CauseProtocol },
  {   4,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CauseMisc },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_Cause(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_Cause, Cause_choice,
                                 NULL);

  return offset;
}


static const value_string s1ap_CellAccessMode_vals[] = {
  {   0, "hybrid" },
  { 0, NULL }
};


static int
dissect_s1ap_CellAccessMode(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_CE_mode_B_SupportIndicator_vals[] = {
  {   0, "supported" },
  { 0, NULL }
};


static int
dissect_s1ap_CE_mode_B_SupportIndicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_Cdma2000PDU(tvbuff_t *tvb, int offset) {

  tvbuff_t *parameter_tvb;
  proto_tree *subtree;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

if (gcsna_handle) {
        subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_Cdma2000PDU);
        call_dissector(gcsna_handle, parameter_tvb, actx->pinfo, subtree);
}




  return offset;
}


static const value_string s1ap_Cdma2000RATType_vals[] = {
  {   0, "hRPD" },
  {   1, "onexRTT" },
  { 0, NULL }
};


static int
dissect_s1ap_Cdma2000RATType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_Cdma2000SectorID(tvbuff_t *tvb, int offset) {
/* 9.2.1.25
 * This IE is set to CDMA2000 Reference Cell ID
 * corresponding to the HRPD/1xRTT sector under
 * the HRPD AN/1xBS to which the eNB has initiated the UE
 * to handover to. The CDMA2000 Reference Cell
 * ID is statically configured in the eNB.
 */
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_Cdma2000SectorID);
  dissect_a21_ie_common(parameter_tvb, actx->pinfo, NULL/* Top tree not needed */, subtree, 0,  0 /* message_type not needed */);



  return offset;
}


static const value_string s1ap_Cdma2000HOStatus_vals[] = {
  {   0, "hOSuccess" },
  {   1, "hOFailure" },
  { 0, NULL }
};


static int
dissect_s1ap_Cdma2000HOStatus(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_Cdma2000HORequiredIndication_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_Cdma2000HORequiredIndication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_Cdma2000OneXMEID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, NULL);

  return offset;
}



static int
dissect_s1ap_Cdma2000OneXMSI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, NULL);

  return offset;
}



static int
dissect_s1ap_Cdma2000OneXPilot(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, NULL);

  return offset;
}


static const per_sequence_t Cdma2000OneXSRVCCInfo_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Cdma2000OneXMEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Cdma2000OneXMSI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Cdma2000OneXPilot },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_Cdma2000OneXSRVCCInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Cdma2000OneXSRVCCInfo, Cdma2000OneXSRVCCInfo_sequence);

  return offset;
}



static int
dissect_s1ap_Cdma2000OneXRAND(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, NULL);

  return offset;
}


static const value_string s1ap_Cell_Size_vals[] = {
  {   0, "verysmall" },
  {   1, "small" },
  {   2, "medium" },
  {   3, "large" },
  { 0, NULL }
};


static int
dissect_s1ap_Cell_Size(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 4, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t CellType_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Cell_Size },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellType, CellType_sequence);

  return offset;
}



static int
dissect_s1ap_LAC(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       2, 2, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
  }



  return offset;
}



static int
dissect_s1ap_CI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       2, 2, FALSE, NULL);

  return offset;
}



static int
dissect_s1ap_RAC(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       1, 1, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 1, ENC_BIG_ENDIAN);
  }



  return offset;
}


static const per_sequence_t CGI_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_LAC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_RAC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CGI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CGI, CGI_sequence);

  return offset;
}


static const value_string s1ap_CNDomain_vals[] = {
  {   0, "ps" },
  {   1, "cs" },
  { 0, NULL }
};


static int
dissect_s1ap_CNDomain(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, FALSE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_CNType_vals[] = {
  {   0, "fiveGCForbidden" },
  {   1, "epc-Forbiddden" },
  { 0, NULL }
};


static int
dissect_s1ap_CNType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 1, NULL, 1);

  return offset;
}


static const per_sequence_t CNTypeRestrictions_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CNType },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CNTypeRestrictions_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CNTypeRestrictions_Item, CNTypeRestrictions_Item_sequence);

  return offset;
}


static const per_sequence_t CNTypeRestrictions_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CNTypeRestrictions_Item },
};

static int
dissect_s1ap_CNTypeRestrictions(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CNTypeRestrictions, CNTypeRestrictions_sequence_of,
                                                  1, maxnoofEPLMNsPlusOne, FALSE);

  return offset;
}


static const value_string s1ap_ConcurrentWarningMessageIndicator_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_ConcurrentWarningMessageIndicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, FALSE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_En_gNB_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     22, 32, TRUE, NULL, 0, NULL, NULL);

  return offset;
}


static const per_sequence_t SupportedTAs_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BPLMNs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SupportedTAs_Item(tvbuff_t *tvb, int offset) {
  if (!PINFO_FD_VISITED(actx->pinfo) &&
      (s1ap_data->message_type == INITIATING_MESSAGE) &&
      ((s1ap_data->procedure_code == id_S1Setup) ||
       (s1ap_data->procedure_code == id_ENBConfigurationUpdate))) {
    s1ap_data->supported_ta = wmem_new0(wmem_packet_scope(), struct s1ap_supported_ta);
    s1ap_data->supported_ta->plmn = wmem_array_new(wmem_packet_scope(), sizeof(guint32));
  }


  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SupportedTAs_Item, SupportedTAs_Item_sequence);

  s1ap_data->supported_ta = NULL;


  return offset;
}


static const per_sequence_t SupportedTAs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_SupportedTAs_Item },
};

static int
dissect_s1ap_SupportedTAs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_SupportedTAs, SupportedTAs_sequence_of,
                                                  1, maxnoofTACs, FALSE);

  return offset;
}


static const per_sequence_t ConnectedengNBItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_En_gNB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_SupportedTAs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ConnectedengNBItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ConnectedengNBItem, ConnectedengNBItem_sequence);

  return offset;
}


static const per_sequence_t ConnectedengNBList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ConnectedengNBItem },
};

static int
dissect_s1ap_ConnectedengNBList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ConnectedengNBList, ConnectedengNBList_sequence_of,
                                                  1, maxnoofConnectedengNBs, FALSE);

  return offset;
}



static int
dissect_s1ap_GNB_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     22, 32, FALSE, NULL, 0, NULL, NULL);

  return offset;
}


static const value_string s1ap_GNB_Identity_vals[] = {
  {   0, "gNB-ID" },
  { 0, NULL }
};

static const per_choice_t GNB_Identity_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_GNB_ID },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_GNB_Identity(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_GNB_Identity, GNB_Identity_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t Global_GNB_ID_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GNB_Identity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_Global_GNB_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Global_GNB_ID, Global_GNB_ID_sequence);

  return offset;
}


static const per_sequence_t GNB_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Global_GNB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_GNB(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_GNB, GNB_sequence);

  return offset;
}



static int
dissect_s1ap_BIT_STRING_SIZE_20(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     20, 20, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_BIT_STRING_SIZE_28(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     28, 28, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_BIT_STRING_SIZE_18(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     18, 18, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_BIT_STRING_SIZE_21(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     21, 21, FALSE, NULL, 0, NULL, NULL);

  return offset;
}


static const value_string s1ap_ENB_ID_vals[] = {
  {   0, "macroENB-ID" },
  {   1, "homeENB-ID" },
  {   2, "short-macroENB-ID" },
  {   3, "long-macroENB-ID" },
  { 0, NULL }
};

static const per_choice_t ENB_ID_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_BIT_STRING_SIZE_20 },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_BIT_STRING_SIZE_28 },
  {   2,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_BIT_STRING_SIZE_18 },
  {   3,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_BIT_STRING_SIZE_21 },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_ENB_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_ENB_ID, ENB_ID_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t Global_ENB_ID_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ENB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

int
dissect_s1ap_Global_ENB_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Global_ENB_ID, Global_ENB_ID_sequence);

  return offset;
}


static const per_sequence_t NG_eNB_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Global_ENB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_NG_eNB(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_NG_eNB, NG_eNB_sequence);

  return offset;
}


static const value_string s1ap_Global_RAN_NODE_ID_vals[] = {
  {   0, "gNB" },
  {   1, "ng-eNB" },
  { 0, NULL }
};

static const per_choice_t Global_RAN_NODE_ID_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_GNB },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_NG_eNB },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_Global_RAN_NODE_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_Global_RAN_NODE_ID, Global_RAN_NODE_ID_choice,
                                 NULL);

  return offset;
}



static int
dissect_s1ap_RAN_UE_NGAP_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 4294967295U, NULL, FALSE);

  return offset;
}


static const per_sequence_t ContextatSource_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Global_RAN_NODE_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RAN_UE_NGAP_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ContextatSource(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ContextatSource, ContextatSource_sequence);

  return offset;
}



static int
dissect_s1ap_Correlation_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       4, 4, FALSE, NULL);

  return offset;
}


static const value_string s1ap_CSFallbackIndicator_vals[] = {
  {   0, "cs-fallback-required" },
  {   1, "cs-fallback-high-priority" },
  { 0, NULL }
};


static int
dissect_s1ap_CSFallbackIndicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 1, NULL, 1);

  return offset;
}


static const value_string s1ap_AdditionalCSFallbackIndicator_vals[] = {
  {   0, "no-restriction" },
  {   1, "restriction" },
  { 0, NULL }
};


static int
dissect_s1ap_AdditionalCSFallbackIndicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_CSG_Id(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     27, 27, FALSE, NULL, 0, NULL, NULL);

  return offset;
}


static const per_sequence_t CSG_IdList_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CSG_Id },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CSG_IdList_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CSG_IdList_Item, CSG_IdList_Item_sequence);

  return offset;
}


static const per_sequence_t CSG_IdList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CSG_IdList_Item },
};

static int
dissect_s1ap_CSG_IdList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CSG_IdList, CSG_IdList_sequence_of,
                                                  1, maxnoofCSGs, FALSE);

  return offset;
}


static const value_string s1ap_CSGMembershipStatus_vals[] = {
  {   0, "member" },
  {   1, "not-member" },
  { 0, NULL }
};


static int
dissect_s1ap_CSGMembershipStatus(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, FALSE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_Coverage_Level_vals[] = {
  {   0, "extendedcoverage" },
  { 0, NULL }
};


static int
dissect_s1ap_Coverage_Level(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_TypeOfError_vals[] = {
  {   0, "not-understood" },
  {   1, "missing" },
  { 0, NULL }
};


static int
dissect_s1ap_TypeOfError(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t CriticalityDiagnostics_IE_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Criticality },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TypeOfError },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CriticalityDiagnostics_IE_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CriticalityDiagnostics_IE_Item, CriticalityDiagnostics_IE_Item_sequence);

  return offset;
}


static const per_sequence_t CriticalityDiagnostics_IE_List_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CriticalityDiagnostics_IE_Item },
};

static int
dissect_s1ap_CriticalityDiagnostics_IE_List(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CriticalityDiagnostics_IE_List, CriticalityDiagnostics_IE_List_sequence_of,
                                                  1, maxnoofErrors, FALSE);

  return offset;
}


static const per_sequence_t CriticalityDiagnostics_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProcedureCode },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_TriggeringMessage },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_Criticality },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_CriticalityDiagnostics_IE_List },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CriticalityDiagnostics(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CriticalityDiagnostics, CriticalityDiagnostics_sequence);

  return offset;
}


static const value_string s1ap_T_dAPSIndicator_vals[] = {
  {   0, "dAPS-HO-required" },
  { 0, NULL }
};


static int
dissect_s1ap_T_dAPSIndicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t DAPSRequestInfo_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_T_dAPSIndicator },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_DAPSRequestInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_DAPSRequestInfo, DAPSRequestInfo_sequence);

  return offset;
}


static const per_sequence_t DAPSResponseInfoList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_DAPSResponseInfoList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_DAPSResponseInfoList, DAPSResponseInfoList_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const value_string s1ap_T_dapsresponseindicator_vals[] = {
  {   0, "dAPS-HO-accepted" },
  {   1, "dAPS-HO-not-accepted" },
  { 0, NULL }
};


static int
dissect_s1ap_T_dapsresponseindicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t DAPSResponseInfo_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_T_dapsresponseindicator },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_DAPSResponseInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_DAPSResponseInfo, DAPSResponseInfo_sequence);

  return offset;
}


static const per_sequence_t DAPSResponseInfoItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_DAPSResponseInfo },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_DAPSResponseInfoItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_DAPSResponseInfoItem, DAPSResponseInfoItem_sequence);

  return offset;
}



static int
dissect_s1ap_DataCodingScheme(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, 
                                     8, 8, FALSE, NULL, 0, &parameter_tvb, NULL);

  if (parameter_tvb) {

    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_DataCodingScheme);
    s1ap_data->data_coding_scheme = dissect_cbs_data_coding_scheme(parameter_tvb, actx->pinfo, subtree, 0);
  }



  return offset;
}



static int
dissect_s1ap_DataSize(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 4095U, NULL, TRUE);

  return offset;
}



static int
dissect_s1ap_DCN_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 65535U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_RelativeMMECapacity(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 255U, NULL, FALSE);

  return offset;
}


static const per_sequence_t ServedDCNsItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_DCN_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RelativeMMECapacity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ServedDCNsItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ServedDCNsItem, ServedDCNsItem_sequence);

  return offset;
}


static const per_sequence_t ServedDCNs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ServedDCNsItem },
};

static int
dissect_s1ap_ServedDCNs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ServedDCNs, ServedDCNs_sequence_of,
                                                  0, maxnoofDCNs, FALSE);

  return offset;
}



static int
dissect_s1ap_DL_NAS_MAC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     16, 16, FALSE, NULL, 0, NULL, NULL);

  return offset;
}


static const per_sequence_t DL_CP_SecurityInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_DL_NAS_MAC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_DL_CP_SecurityInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_DL_CP_SecurityInformation, DL_CP_SecurityInformation_sequence);

  return offset;
}


static const value_string s1ap_DL_Forwarding_vals[] = {
  {   0, "dL-Forwarding-proposed" },
  { 0, NULL }
};


static int
dissect_s1ap_DL_Forwarding(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_Direct_Forwarding_Path_Availability_vals[] = {
  {   0, "directPathAvailable" },
  { 0, NULL }
};


static int
dissect_s1ap_Direct_Forwarding_Path_Availability(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_Data_Forwarding_Not_Possible_vals[] = {
  {   0, "data-Forwarding-not-Possible" },
  { 0, NULL }
};


static int
dissect_s1ap_Data_Forwarding_Not_Possible(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_DLNASPDUDeliveryAckRequest_vals[] = {
  {   0, "requested" },
  { 0, NULL }
};


static int
dissect_s1ap_DLNASPDUDeliveryAckRequest(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_EARFCN(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, maxEARFCN, NULL, TRUE);

  return offset;
}


static const per_sequence_t ECGIList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
};

static int
dissect_s1ap_ECGIList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ECGIList, ECGIList_sequence_of,
                                                  1, maxnoofCellID, FALSE);

  return offset;
}


static const per_sequence_t PWSfailedECGIList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
};

static int
dissect_s1ap_PWSfailedECGIList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_PWSfailedECGIList, PWSfailedECGIList_sequence_of,
                                                  1, maxnoofCellsineNB, FALSE);

  return offset;
}


static const value_string s1ap_EDT_Session_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_EDT_Session(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t EmergencyAreaIDList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_EmergencyAreaID },
};

static int
dissect_s1ap_EmergencyAreaIDList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_EmergencyAreaIDList, EmergencyAreaIDList_sequence_of,
                                                  1, maxnoofEmergencyAreaID, FALSE);

  return offset;
}


static const per_sequence_t ECGI_List_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
};

static int
dissect_s1ap_ECGI_List(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ECGI_List, ECGI_List_sequence_of,
                                                  1, maxnoofCellsineNB, FALSE);

  return offset;
}


static const per_sequence_t EmergencyAreaIDListForRestart_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_EmergencyAreaID },
};

static int
dissect_s1ap_EmergencyAreaIDListForRestart(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_EmergencyAreaIDListForRestart, EmergencyAreaIDListForRestart_sequence_of,
                                                  1, maxnoofRestartEmergencyAreaIDs, FALSE);

  return offset;
}


static const per_sequence_t ENB_EarlyStatusTransfer_TransparentContainer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Bearers_SubjectToEarlyStatusTransferList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENB_EarlyStatusTransfer_TransparentContainer(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENB_EarlyStatusTransfer_TransparentContainer, ENB_EarlyStatusTransfer_TransparentContainer_sequence);

  return offset;
}


static const per_sequence_t LAI_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_LAC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_LAI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_LAI, LAI_sequence);

  return offset;
}


static const per_sequence_t GERAN_Cell_ID_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_LAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RAC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_GERAN_Cell_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_GERAN_Cell_ID, GERAN_Cell_ID_sequence);

  return offset;
}


static const per_sequence_t Global_en_gNB_ID_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_En_gNB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_Global_en_gNB_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Global_en_gNB_ID, Global_en_gNB_ID_sequence);

  return offset;
}


static const per_sequence_t GUMMEIList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_GUMMEI },
};

static int
dissect_s1ap_GUMMEIList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_GUMMEIList, GUMMEIList_sequence_of,
                                                  1, maxnoofMMECs, FALSE);

  return offset;
}


static const per_sequence_t ENB_StatusTransfer_TransparentContainer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Bearers_SubjectToStatusTransferList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENB_StatusTransfer_TransparentContainer(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENB_StatusTransfer_TransparentContainer, ENB_StatusTransfer_TransparentContainer_sequence);

  return offset;
}



static int
dissect_s1ap_ENB_UE_S1AP_ID(tvbuff_t *tvb, int offset) {
  guint32 enb_ue_s1ap_id;
                                                            0U, 16777215U, &enb_ue_s1ap_id, FALSE);

  if (hf_index == hf_s1ap_eNB_UE_S1AP_ID) {
    proto_item *item;
    item = proto_tree_add_uint(tree, hf_s1ap_ENB_UE_S1AP_ID_PDU, tvb, offset, 0 , enb_ue_s1ap_id );
    proto_item_set_hidden(item);
  }

  s1ap_data->enb_ue_s1ap_id = (guint16)enb_ue_s1ap_id;



  return offset;
}



static int
dissect_s1ap_ENBname(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb=NULL;
  int length;
  gboolean is_ascii;

  offset = dissect_per_PrintableString(tvb, offset, 
                                          1, 150, TRUE);


  if (!parameter_tvb)
    return offset;

  length = tvb_reported_length(parameter_tvb);

  is_ascii = tvb_ascii_isprint(parameter_tvb, 0, length);
  if (is_ascii)
     proto_item_append_text(actx->created_item," (%s)",tvb_format_text(parameter_tvb, 0, length));



  return offset;
}



static int
dissect_s1ap_TransportLayerAddress(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb=NULL;
  proto_tree *subtree;
  gint tvb_len;

  offset = dissect_per_bit_string(tvb, offset, 
                                     1, 160, TRUE, NULL, 0, &parameter_tvb, NULL);

  if (!parameter_tvb)
    return offset;

  /* Get the length */
  tvb_len = tvb_reported_length(parameter_tvb);
  subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_TransportLayerAddress);
  if (tvb_len==4) {
    /* IPv4 */
     proto_tree_add_item(subtree, hf_s1ap_transportLayerAddressIPv4, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
  } else if (tvb_len==16) {
    /* IPv6 */
     proto_tree_add_item(subtree, hf_s1ap_transportLayerAddressIPv6, parameter_tvb, 0, 16, ENC_NA);
  } else if (tvb_len==20) {
    /* IPv4 */
     proto_tree_add_item(subtree, hf_s1ap_transportLayerAddressIPv4, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
    /* IPv6 */
     proto_tree_add_item(subtree, hf_s1ap_transportLayerAddressIPv6, parameter_tvb, 4, 16, ENC_NA);
  }



  return offset;
}


static const per_sequence_t ENBX2TLAs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
};

static int
dissect_s1ap_ENBX2TLAs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ENBX2TLAs, ENBX2TLAs_sequence_of,
                                                  1, maxnoofeNBX2TLAs, FALSE);

  return offset;
}



static int
dissect_s1ap_EncryptionAlgorithms(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, 
                                     16, 16, TRUE, NULL, 0, &parameter_tvb, NULL);

  if(parameter_tvb){
    static int * const fields[] = {
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
      NULL
    };
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_EncryptionAlgorithms);
    proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 2, fields, ENC_BIG_ENDIAN);
  }



  return offset;
}


static const per_sequence_t EN_DCSONeNBIdentification_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Global_ENB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EN_DCSONeNBIdentification(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EN_DCSONeNBIdentification, EN_DCSONeNBIdentification_sequence);

  return offset;
}


static const per_sequence_t EN_DCSONengNBIdentification_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Global_en_gNB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EN_DCSONengNBIdentification(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EN_DCSONengNBIdentification, EN_DCSONengNBIdentification_sequence);

  return offset;
}



static int
dissect_s1ap_FiveGSTAC(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       3, 3, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 3, ENC_BIG_ENDIAN);
  }



  return offset;
}


static const per_sequence_t FiveGSTAI_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_FiveGSTAC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_FiveGSTAI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_FiveGSTAI, FiveGSTAI_sequence);

  return offset;
}


static const per_sequence_t EN_DCTransferTypeRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EN_DCSONeNBIdentification },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EN_DCSONengNBIdentification },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_EN_DCSONeNBIdentification },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_TAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_FiveGSTAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EN_DCTransferTypeRequest(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EN_DCTransferTypeRequest, EN_DCTransferTypeRequest_sequence);

  return offset;
}


static const per_sequence_t EN_DCTransferTypeReply_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EN_DCSONengNBIdentification },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EN_DCSONeNBIdentification },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EN_DCTransferTypeReply(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EN_DCTransferTypeReply, EN_DCTransferTypeReply_sequence);

  return offset;
}


static const value_string s1ap_EN_DCSONTransferType_vals[] = {
  {   0, "request" },
  {   1, "reply" },
  { 0, NULL }
};

static const per_choice_t EN_DCSONTransferType_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_EN_DCTransferTypeRequest },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_EN_DCTransferTypeReply },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_EN_DCSONTransferType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_EN_DCSONTransferType, EN_DCSONTransferType_choice,
                                 NULL);

  return offset;
}


static const value_string s1ap_SONInformationRequest_vals[] = {
  {   0, "x2TNL-Configuration-Info" },
  {   1, "time-Synchronisation-Info" },
  {   2, "activate-Muting" },
  {   3, "deactivate-Muting" },
  { 0, NULL }
};


static int
dissect_s1ap_SONInformationRequest(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 3, NULL, 1);

  return offset;
}


static const per_sequence_t X2TNLConfigurationInfo_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ENBX2TLAs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_X2TNLConfigurationInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_X2TNLConfigurationInfo, X2TNLConfigurationInfo_sequence);

  return offset;
}


static const per_sequence_t SONInformationReply_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_X2TNLConfigurationInfo },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SONInformationReply(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SONInformationReply, SONInformationReply_sequence);

  return offset;
}



static int
dissect_s1ap_SONInformation_Extension(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_ProtocolIE_SingleContainer(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const value_string s1ap_SONInformation_vals[] = {
  {   0, "sONInformationRequest" },
  {   1, "sONInformationReply" },
  {   2, "sONInformation-Extension" },
  { 0, NULL }
};

static const per_choice_t SONInformation_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_SONInformationRequest },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_SONInformationReply },
  {   2,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_SONInformation_Extension },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_SONInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_SONInformation, SONInformation_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t EN_DCSONConfigurationTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EN_DCSONTransferType },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_SONInformation },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_X2TNLConfigurationInfo },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EN_DCSONConfigurationTransfer(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EN_DCSONConfigurationTransfer, EN_DCSONConfigurationTransfer_sequence);

  return offset;
}


static const value_string s1ap_EndIndication_vals[] = {
  {   0, "no-further-data" },
  {   1, "further-data-exists" },
  { 0, NULL }
};


static int
dissect_s1ap_EndIndication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_EnhancedCoverageRestricted_vals[] = {
  {   0, "restricted" },
  { 0, NULL }
};


static int
dissect_s1ap_EnhancedCoverageRestricted(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_CE_ModeBRestricted_vals[] = {
  {   0, "restricted" },
  {   1, "not-restricted" },
  { 0, NULL }
};


static int
dissect_s1ap_CE_ModeBRestricted(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t EPLMNs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
};

static int
dissect_s1ap_EPLMNs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_EPLMNs, EPLMNs_sequence_of,
                                                  1, maxnoofEPLMNs, FALSE);

  return offset;
}


static const value_string s1ap_EventType_vals[] = {
  {   0, "direct" },
  {   1, "change-of-serve-cell" },
  {   2, "stop-change-of-serve-cell" },
  { 0, NULL }
};


static int
dissect_s1ap_EventType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t E_RABInformationList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABInformationList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABInformationList, E_RABInformationList_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t E_RABInformationListItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_DL_Forwarding },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABInformationListItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABInformationListItem, E_RABInformationListItem_sequence);

  return offset;
}


static const per_sequence_t E_RABList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABList, E_RABList_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t E_RABItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Cause },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABItem, E_RABItem_sequence);

  return offset;
}



static int
dissect_s1ap_QCI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 255U, NULL, FALSE);

  return offset;
}


static const per_sequence_t GBR_QosInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_GBR_QosInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_GBR_QosInformation, GBR_QosInformation_sequence);

  return offset;
}


static const per_sequence_t E_RABLevelQoSParameters_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_QCI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_AllocationAndRetentionPriority },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_GBR_QosInformation },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABLevelQoSParameters(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABLevelQoSParameters, E_RABLevelQoSParameters_sequence);

  return offset;
}


static const per_sequence_t E_RABUsageReportList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABUsageReportList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABUsageReportList, E_RABUsageReportList_sequence_of,
                                                  1, maxnooftimeperiods, FALSE);

  return offset;
}



static int
dissect_s1ap_T_startTimestamp(tvbuff_t *tvb, int offset) {
  tvbuff_t *timestamp_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       4, 4, FALSE, &timestamp_tvb);




  if (timestamp_tvb) {
    proto_item_append_text(actx->created_item, " (%s)", tvb_ntp_fmt_ts_sec(timestamp_tvb, 0));
  }


  return offset;
}



static int
dissect_s1ap_T_endTimestamp(tvbuff_t *tvb, int offset) {
  tvbuff_t *timestamp_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       4, 4, FALSE, &timestamp_tvb);




  if (timestamp_tvb) {
    proto_item_append_text(actx->created_item, " (%s)", tvb_ntp_fmt_ts_sec(timestamp_tvb, 0));
  }


  return offset;
}



static int
dissect_s1ap_INTEGER_0_18446744073709551615(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer_64b(tvb, offset, 
                                                            0U, G_GUINT64_CONSTANT(18446744073709551615), NULL, FALSE);

  return offset;
}


static const per_sequence_t E_RABUsageReportItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_T_startTimestamp },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_T_endTimestamp },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_INTEGER_0_18446744073709551615 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_INTEGER_0_18446744073709551615 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABUsageReportItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABUsageReportItem, E_RABUsageReportItem_sequence);

  return offset;
}


static const value_string s1ap_Ethernet_Type_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_Ethernet_Type(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_EUTRANRoundTripDelayEstimationInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 2047U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_ExpectedActivityPeriod(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 181U, NULL, TRUE);

  return offset;
}



static int
dissect_s1ap_ExpectedIdlePeriod(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 181U, NULL, TRUE);

  return offset;
}


static const value_string s1ap_SourceOfUEActivityBehaviourInformation_vals[] = {
  {   0, "subscription-information" },
  {   1, "statistics" },
  { 0, NULL }
};


static int
dissect_s1ap_SourceOfUEActivityBehaviourInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t ExpectedUEActivityBehaviour_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ExpectedActivityPeriod },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ExpectedIdlePeriod },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_SourceOfUEActivityBehaviourInformation },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ExpectedUEActivityBehaviour(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ExpectedUEActivityBehaviour, ExpectedUEActivityBehaviour_sequence);

  return offset;
}


static const value_string s1ap_ExpectedHOInterval_vals[] = {
  {   0, "sec15" },
  {   1, "sec30" },
  {   2, "sec60" },
  {   3, "sec90" },
  {   4, "sec120" },
  {   5, "sec180" },
  {   6, "long-time" },
  { 0, NULL }
};


static int
dissect_s1ap_ExpectedHOInterval(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 7, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t ExpectedUEBehaviour_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ExpectedUEActivityBehaviour },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ExpectedHOInterval },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ExpectedUEBehaviour(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ExpectedUEBehaviour, ExpectedUEBehaviour_sequence);

  return offset;
}



static int
dissect_s1ap_ExtendedBitRate(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer_64b(tvb, offset, 
                                                            10000000001U, G_GUINT64_CONSTANT(4000000000000), NULL, TRUE);

  return offset;
}



static int
dissect_s1ap_ExtendedRNC_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            4096U, 65535U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_ExtendedRepetitionPeriod(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            4096U, 131071U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_Extended_UEIdentityIndexValue(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     14, 14, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_FiveQI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 255U, NULL, TRUE);

  return offset;
}


static const value_string s1ap_ForbiddenInterRATs_vals[] = {
  {   0, "all" },
  {   1, "geran" },
  {   2, "utran" },
  {   3, "cdma2000" },
  {   4, "geranandutran" },
  {   5, "cdma2000andutran" },
  { 0, NULL }
};


static int
dissect_s1ap_ForbiddenInterRATs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 4, NULL, TRUE, 2, NULL, 1);

  return offset;
}


static const per_sequence_t ForbiddenTACs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TAC },
};

static int
dissect_s1ap_ForbiddenTACs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ForbiddenTACs, ForbiddenTACs_sequence_of,
                                                  1, maxnoofForbTACs, FALSE);

  return offset;
}


static const per_sequence_t ForbiddenTAs_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ForbiddenTACs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ForbiddenTAs_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ForbiddenTAs_Item, ForbiddenTAs_Item_sequence);

  return offset;
}


static const per_sequence_t ForbiddenTAs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ForbiddenTAs_Item },
};

static int
dissect_s1ap_ForbiddenTAs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ForbiddenTAs, ForbiddenTAs_sequence_of,
                                                  1, maxnoofEPLMNsPlusOne, FALSE);

  return offset;
}


static const per_sequence_t ForbiddenLACs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_LAC },
};

static int
dissect_s1ap_ForbiddenLACs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ForbiddenLACs, ForbiddenLACs_sequence_of,
                                                  1, maxnoofForbLACs, FALSE);

  return offset;
}


static const per_sequence_t ForbiddenLAs_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ForbiddenLACs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ForbiddenLAs_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ForbiddenLAs_Item, ForbiddenLAs_Item_sequence);

  return offset;
}


static const per_sequence_t ForbiddenLAs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ForbiddenLAs_Item },
};

static int
dissect_s1ap_ForbiddenLAs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ForbiddenLAs, ForbiddenLAs_sequence_of,
                                                  1, maxnoofEPLMNsPlusOne, FALSE);

  return offset;
}



static int
dissect_s1ap_GTP_TEID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       4, 4, FALSE, NULL);

  return offset;
}


static const value_string s1ap_GUMMEIType_vals[] = {
  {   0, "native" },
  {   1, "mapped" },
  {   2, "mappedFrom5G" },
  { 0, NULL }
};


static int
dissect_s1ap_GUMMEIType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 1, NULL, 1);

  return offset;
}


static const value_string s1ap_GWContextReleaseIndication_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_GWContextReleaseIndication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_HandoverFlag_vals[] = {
  {   0, "handoverPreparation" },
  { 0, NULL }
};


static int
dissect_s1ap_HandoverFlag(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t HandoverRestrictionList_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_EPLMNs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ForbiddenTAs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ForbiddenLAs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ForbiddenInterRATs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverRestrictionList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverRestrictionList, HandoverRestrictionList_sequence);

  return offset;
}


static const value_string s1ap_HandoverType_vals[] = {
  { intralte, "intralte" },
  { ltetoutran, "ltetoutran" },
  { ltetogeran, "ltetogeran" },
  { utrantolte, "utrantolte" },
  { gerantolte, "gerantolte" },
  { eps_to_5gs, "eps-to-5gs" },
  { fivegs_to_eps, "fivegs-to-eps" },
  { 0, NULL }
};


static int
dissect_s1ap_HandoverType(tvbuff_t *tvb, int offset) {
                                     5, &s1ap_data->handover_type_value, TRUE, 2, NULL);




  return offset;
}



static int
dissect_s1ap_Masked_IMEISV(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     64, 64, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_MeasurementsToActivate(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, 
                                     8, 8, FALSE, NULL, 0, &parameter_tvb, NULL);

  if(parameter_tvb){
    static int * const fields[] = {
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
      NULL
    };
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_MeasurementsToActivate);
    proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
  }



  return offset;
}


static const value_string s1ap_M1ReportingTrigger_vals[] = {
  {   0, "periodic" },
  {   1, "a2eventtriggered" },
  {   2, "a2eventtriggered-periodic" },
  { 0, NULL }
};


static int
dissect_s1ap_M1ReportingTrigger(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 1, NULL, 1);

  return offset;
}



static int
dissect_s1ap_Threshold_RSRP(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 97U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_Threshold_RSRQ(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 34U, NULL, FALSE);

  return offset;
}


static const value_string s1ap_MeasurementThresholdA2_vals[] = {
  {   0, "threshold-RSRP" },
  {   1, "threshold-RSRQ" },
  { 0, NULL }
};

static const per_choice_t MeasurementThresholdA2_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_Threshold_RSRP },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_Threshold_RSRQ },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_MeasurementThresholdA2(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_MeasurementThresholdA2, MeasurementThresholdA2_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t M1ThresholdEventA2_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_MeasurementThresholdA2 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_M1ThresholdEventA2(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_M1ThresholdEventA2, M1ThresholdEventA2_sequence);

  return offset;
}


static const value_string s1ap_ReportIntervalMDT_vals[] = {
  {   0, "ms120" },
  {   1, "ms240" },
  {   2, "ms480" },
  {   3, "ms640" },
  {   4, "ms1024" },
  {   5, "ms2048" },
  {   6, "ms5120" },
  {   7, "ms10240" },
  {   8, "min1" },
  {   9, "min6" },
  {  10, "min12" },
  {  11, "min30" },
  {  12, "min60" },
  { 0, NULL }
};


static int
dissect_s1ap_ReportIntervalMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 13, NULL, FALSE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_ReportAmountMDT_vals[] = {
  {   0, "r1" },
  {   1, "r2" },
  {   2, "r4" },
  {   3, "r8" },
  {   4, "r16" },
  {   5, "r32" },
  {   6, "r64" },
  {   7, "rinfinity" },
  { 0, NULL }
};


static int
dissect_s1ap_ReportAmountMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 8, NULL, FALSE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t M1PeriodicReporting_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ReportIntervalMDT },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ReportAmountMDT },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_M1PeriodicReporting(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_M1PeriodicReporting, M1PeriodicReporting_sequence);

  return offset;
}


static const per_sequence_t ImmediateMDT_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_MeasurementsToActivate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_M1ReportingTrigger },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_M1ThresholdEventA2 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_M1PeriodicReporting },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ImmediateMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ImmediateMDT, ImmediateMDT_sequence);

  return offset;
}



static int
dissect_s1ap_IMSI(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  offset = dissect_per_octet_string(tvb, offset, 
                                       3, 8, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_IMSI);
    dissect_e212_imsi(parameter_tvb, actx->pinfo, subtree, 0, tvb_reported_length(parameter_tvb), FALSE);
  }



  return offset;
}


static const per_sequence_t RecommendedENBList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_RecommendedENBList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_RecommendedENBList, RecommendedENBList_sequence_of,
                                                  1, maxnoofRecommendedENBs, FALSE);

  return offset;
}


static const per_sequence_t RecommendedENBsForPaging_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RecommendedENBList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_RecommendedENBsForPaging(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_RecommendedENBsForPaging, RecommendedENBsForPaging_sequence);

  return offset;
}


static const per_sequence_t InformationOnRecommendedCellsAndENBsForPaging_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RecommendedCellsForPaging },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RecommendedENBsForPaging },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_InformationOnRecommendedCellsAndENBsForPaging(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_InformationOnRecommendedCellsAndENBsForPaging, InformationOnRecommendedCellsAndENBsForPaging_sequence);

  return offset;
}



static int
dissect_s1ap_IntegrityProtectionAlgorithms(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, 
                                     16, 16, TRUE, NULL, 0, &parameter_tvb, NULL);

  if(parameter_tvb){
    static int * const fields[] = {
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
      NULL
    };
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_IntegrityProtectionAlgorithms);
    proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 2, fields, ENC_BIG_ENDIAN);
  }



  return offset;
}



static int
dissect_s1ap_InterfacesToTrace(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, 
                                     8, 8, FALSE, NULL, 0, &parameter_tvb, NULL);

  if(parameter_tvb){
    static int * const fields[] = {
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
      NULL
    };
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_InterfacesToTrace);
    proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
  }



  return offset;
}



static int
dissect_s1ap_INTEGER_0_127(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 127U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_INTEGER_1_100(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 100U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_INTEGER_1_1024(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 1024U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_INTEGER_0_maxNARFCN(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, maxNARFCN, NULL, FALSE);

  return offset;
}


static const value_string s1ap_T_subcarrierSpacingSSB_vals[] = {
  {   0, "kHz15" },
  {   1, "kHz30" },
  {   2, "kHz60" },
  {   3, "kHz120" },
  {   4, "kHz240" },
  { 0, NULL }
};


static int
dissect_s1ap_T_subcarrierSpacingSSB(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 5, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_INTEGER_1_maxRS_IndexCellQual(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, maxRS_IndexCellQual, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_T_sMTC(tvbuff_t *tvb, int offset) {
  tvbuff_t *ssb_mtc_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &ssb_mtc_tvb);

  if (ssb_mtc_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_sMTC);
    dissect_lte_rrc_MTC_SSB_NR_r15_PDU(ssb_mtc_tvb, actx->pinfo, subtree, NULL);
  }



  return offset;
}



static int
dissect_s1ap_T_threshRS_Index_r15(tvbuff_t *tvb, int offset) {
  tvbuff_t *threshold_list_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &threshold_list_tvb);

  if (threshold_list_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_threshRS_Index_r15);
    dissect_lte_rrc_ThresholdListNR_r15_PDU(threshold_list_tvb, actx->pinfo, subtree, NULL);
  }



  return offset;
}



static int
dissect_s1ap_T_sSBToMeasure(tvbuff_t *tvb, int offset) {
  tvbuff_t *ssb_to_meas_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &ssb_to_meas_tvb);

  if (ssb_to_meas_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_sSBToMeasure);
    dissect_lte_rrc_SSB_ToMeasure_r15_PDU(ssb_to_meas_tvb, actx->pinfo, subtree, NULL);
  }



  return offset;
}



static int
dissect_s1ap_T_sSRSSIMeasurement(tvbuff_t *tvb, int offset) {
  tvbuff_t *ss_rssi_meas_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &ss_rssi_meas_tvb);

  if (ss_rssi_meas_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_sSRSSIMeasurement);
    dissect_lte_rrc_SS_RSSI_Measurement_r15_PDU(ss_rssi_meas_tvb, actx->pinfo, subtree, NULL);
  }



  return offset;
}



static int
dissect_s1ap_T_quantityConfigNR_R15(tvbuff_t *tvb, int offset) {
  tvbuff_t *quantity_config_nr_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &quantity_config_nr_tvb);

  if (quantity_config_nr_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_quantityConfigNR_R15);
    dissect_lte_rrc_QuantityConfigNR_r15_PDU(quantity_config_nr_tvb, actx->pinfo, subtree, NULL);
  }



  return offset;
}



static int
dissect_s1ap_T_blackCellsToAddModList(tvbuff_t *tvb, int offset) {
  tvbuff_t *black_cells_list_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &black_cells_list_tvb);

  if (black_cells_list_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_blackCellsToAddModList);
    dissect_lte_rrc_CellsToAddModListNR_r15_PDU(black_cells_list_tvb, actx->pinfo, subtree, NULL);
  }



  return offset;
}


static const per_sequence_t InterSystemMeasurementItem_sequence[] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_INTEGER_1_1024 },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_INTEGER_0_maxNARFCN },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_T_subcarrierSpacingSSB },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_1_maxRS_IndexCellQual },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_OPTIONAL    , dissect_s1ap_T_sMTC },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_OPTIONAL    , dissect_s1ap_T_threshRS_Index_r15 },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_OPTIONAL    , dissect_s1ap_T_sSBToMeasure },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_OPTIONAL    , dissect_s1ap_T_sSRSSIMeasurement },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_OPTIONAL    , dissect_s1ap_T_quantityConfigNR_R15 },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_OPTIONAL    , dissect_s1ap_T_blackCellsToAddModList },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_InterSystemMeasurementItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_InterSystemMeasurementItem, InterSystemMeasurementItem_sequence);

  return offset;
}


static const per_sequence_t InterSystemMeasurementList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_InterSystemMeasurementItem },
};

static int
dissect_s1ap_InterSystemMeasurementList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_InterSystemMeasurementList, InterSystemMeasurementList_sequence_of,
                                                  1, maxnooffrequencies, FALSE);

  return offset;
}


static const per_sequence_t InterSystemMeasurementParameters_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_INTEGER_1_100 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_InterSystemMeasurementList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_InterSystemMeasurementParameters(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_InterSystemMeasurementParameters, InterSystemMeasurementParameters_sequence);

  return offset;
}


static const per_sequence_t IntersystemMeasurementConfiguration_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_0_127 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_0_127 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_0_127 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_InterSystemMeasurementParameters },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_IntersystemMeasurementConfiguration(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_IntersystemMeasurementConfiguration, IntersystemMeasurementConfiguration_sequence);

  return offset;
}



static int
dissect_s1ap_IntersystemSONConfigurationTransfer(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_IntersystemSONConfigurationTransfer);
    dissect_ngap_SONConfigurationTransfer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
  }



  return offset;
}


static const value_string s1ap_IMSvoiceEPSfallbackfrom5G_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_IMSvoiceEPSfallbackfrom5G(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_IAB_Authorized_vals[] = {
  {   0, "authorized" },
  {   1, "not-authorized" },
  { 0, NULL }
};


static int
dissect_s1ap_IAB_Authorized(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_IAB_Node_Indication_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_IAB_Node_Indication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_IAB_Supported_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_IAB_Supported(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_KillAllWarningMessages_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_KillAllWarningMessages(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, FALSE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_Time_UE_StayedInCell(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 4095U, NULL, FALSE);

  return offset;
}


static const per_sequence_t LastVisitedEUTRANCellInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CellType },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Time_UE_StayedInCell },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_LastVisitedEUTRANCellInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_LastVisitedEUTRANCellInformation, LastVisitedEUTRANCellInformation_sequence);

  return offset;
}



static int
dissect_s1ap_LastVisitedUTRANCellInformation(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_LastVisitedUTRANCellInformation);
    TRY {
      dissect_ranap_LastVisitedUTRANCell_Item_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
    }
    CATCH_BOUNDS_ERRORS {
      show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
    }
    ENDTRY;
  }



  return offset;
}


static const value_string s1ap_LastVisitedGERANCellInformation_vals[] = {
  {   0, "undefined" },
  { 0, NULL }
};

static const per_choice_t LastVisitedGERANCellInformation_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_NULL },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_LastVisitedGERANCellInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_LastVisitedGERANCellInformation, LastVisitedGERANCellInformation_choice,
                                 NULL);

  return offset;
}



static int
dissect_s1ap_LastVisitedNGRANCellInformation(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_LastVisitedNGRANCellInformation);
    TRY {
      dissect_ngap_LastVisitedNGRANCellInformation_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
    }
    CATCH_BOUNDS_ERRORS {
      show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
    }
    ENDTRY;
  }



  return offset;
}


static const value_string s1ap_LastVisitedCell_Item_vals[] = {
  {   0, "e-UTRAN-Cell" },
  {   1, "uTRAN-Cell" },
  {   2, "gERAN-Cell" },
  {   3, "nG-RAN-Cell" },
  { 0, NULL }
};

static const per_choice_t LastVisitedCell_Item_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_LastVisitedEUTRANCellInformation },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_LastVisitedUTRANCellInformation },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_LastVisitedGERANCellInformation },
  {   3,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_LastVisitedNGRANCellInformation },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_LastVisitedCell_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_LastVisitedCell_Item, LastVisitedCell_Item_choice,
                                 NULL);

  return offset;
}



static int
dissect_s1ap_LPPa_PDU(tvbuff_t *tvb, int offset) {

  tvbuff_t *parameter_tvb=NULL;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);


  if ((tvb_reported_length(parameter_tvb)>0)&&(lppa_handle))
    call_dissector(lppa_handle, parameter_tvb, actx->pinfo, tree);



  return offset;
}



static int
dissect_s1ap_LHN_ID(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       32, 256, FALSE, &parameter_tvb);

  actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, -1, ENC_UTF_8|ENC_NA);


  return offset;
}


static const value_string s1ap_Links_to_log_vals[] = {
  {   0, "uplink" },
  {   1, "downlink" },
  {   2, "both-uplink-and-downlink" },
  { 0, NULL }
};


static int
dissect_s1ap_Links_to_log(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_T_pattern_period_vals[] = {
  {   0, "ms1280" },
  {   1, "ms2560" },
  {   2, "ms5120" },
  {   3, "ms10240" },
  { 0, NULL }
};


static int
dissect_s1ap_T_pattern_period(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 4, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_INTEGER_0_10239_(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 10239U, NULL, TRUE);

  return offset;
}


static const per_sequence_t ListeningSubframePattern_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_T_pattern_period },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_INTEGER_0_10239_ },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ListeningSubframePattern(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ListeningSubframePattern, ListeningSubframePattern_sequence);

  return offset;
}


static const value_string s1ap_LoggingInterval_vals[] = {
  {   0, "ms128" },
  {   1, "ms256" },
  {   2, "ms512" },
  {   3, "ms1024" },
  {   4, "ms2048" },
  {   5, "ms3072" },
  {   6, "ms4096" },
  {   7, "ms6144" },
  { 0, NULL }
};


static int
dissect_s1ap_LoggingInterval(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 8, NULL, FALSE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_LoggingDuration_vals[] = {
  {   0, "m10" },
  {   1, "m20" },
  {   2, "m40" },
  {   3, "m60" },
  {   4, "m90" },
  {   5, "m120" },
  { 0, NULL }
};


static int
dissect_s1ap_LoggingDuration(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 6, NULL, FALSE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t LoggedMDT_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_LoggingInterval },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_LoggingDuration },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_LoggedMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_LoggedMDT, LoggedMDT_sequence);

  return offset;
}



static int
dissect_s1ap_INTEGER_0_255(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 255U, NULL, FALSE);

  return offset;
}


static const per_sequence_t MBSFN_ResultToLogInfo_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_0_255 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EARFCN },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MBSFN_ResultToLogInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MBSFN_ResultToLogInfo, MBSFN_ResultToLogInfo_sequence);

  return offset;
}


static const per_sequence_t MBSFN_ResultToLog_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_MBSFN_ResultToLogInfo },
};

static int
dissect_s1ap_MBSFN_ResultToLog(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_MBSFN_ResultToLog, MBSFN_ResultToLog_sequence_of,
                                                  1, maxnoofMBSFNAreaMDT, FALSE);

  return offset;
}


static const per_sequence_t LoggedMBSFNMDT_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_LoggingInterval },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_LoggingDuration },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_MBSFN_ResultToLog },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_LoggedMBSFNMDT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_LoggedMBSFNMDT, LoggedMBSFNMDT_sequence);

  return offset;
}


static const value_string s1ap_LTE_M_Indication_vals[] = {
  {   0, "lte-m" },
  { 0, NULL }
};


static int
dissect_s1ap_LTE_M_Indication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_M3period_vals[] = {
  {   0, "ms100" },
  {   1, "ms1000" },
  {   2, "ms10000" },
  {   3, "ms1024" },
  {   4, "ms1280" },
  {   5, "ms2048" },
  {   6, "ms2560" },
  {   7, "ms5120" },
  {   8, "ms10240" },
  {   9, "min1" },
  { 0, NULL }
};


static int
dissect_s1ap_M3period(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 7, NULL, 1);

  return offset;
}


static const per_sequence_t M3Configuration_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_M3period },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_M3Configuration(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_M3Configuration, M3Configuration_sequence);

  return offset;
}


static const value_string s1ap_M4period_vals[] = {
  {   0, "ms1024" },
  {   1, "ms2048" },
  {   2, "ms5120" },
  {   3, "ms10240" },
  {   4, "min1" },
  { 0, NULL }
};


static int
dissect_s1ap_M4period(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 5, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t M4Configuration_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_M4period },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Links_to_log },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_M4Configuration(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_M4Configuration, M4Configuration_sequence);

  return offset;
}


static const value_string s1ap_M5period_vals[] = {
  {   0, "ms1024" },
  {   1, "ms2048" },
  {   2, "ms5120" },
  {   3, "ms10240" },
  {   4, "min1" },
  { 0, NULL }
};


static int
dissect_s1ap_M5period(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 5, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t M5Configuration_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_M5period },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Links_to_log },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_M5Configuration(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_M5Configuration, M5Configuration_sequence);

  return offset;
}


static const value_string s1ap_M6report_Interval_vals[] = {
  {   0, "ms1024" },
  {   1, "ms2048" },
  {   2, "ms5120" },
  {   3, "ms10240" },
  { 0, NULL }
};


static int
dissect_s1ap_M6report_Interval(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 4, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_M6delay_threshold_vals[] = {
  {   0, "ms30" },
  {   1, "ms40" },
  {   2, "ms50" },
  {   3, "ms60" },
  {   4, "ms70" },
  {   5, "ms80" },
  {   6, "ms90" },
  {   7, "ms100" },
  {   8, "ms150" },
  {   9, "ms300" },
  {  10, "ms500" },
  {  11, "ms750" },
  { 0, NULL }
};


static int
dissect_s1ap_M6delay_threshold(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 12, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t M6Configuration_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_M6report_Interval },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_M6delay_threshold },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Links_to_log },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_M6Configuration(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_M6Configuration, M6Configuration_sequence);

  return offset;
}



static int
dissect_s1ap_M7period(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 60U, NULL, TRUE);

  return offset;
}


static const per_sequence_t M7Configuration_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_M7period },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Links_to_log },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_M7Configuration(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_M7Configuration, M7Configuration_sequence);

  return offset;
}


static const value_string s1ap_MDT_Activation_vals[] = {
  {   0, "immediate-MDT-only" },
  {   1, "immediate-MDT-and-Trace" },
  {   2, "logged-MDT-only" },
  {   3, "logged-MBSFN-MDT" },
  { 0, NULL }
};


static int
dissect_s1ap_MDT_Activation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 1, NULL, 1);

  return offset;
}



static int
dissect_s1ap_MDT_Location_Info(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, 
                                     8, 8, FALSE, NULL, 0, &parameter_tvb, NULL);

  if(parameter_tvb){
    static int * const fields[] = {
     &unused_p_id
     &unused_p_id
     &unused_p_id
      NULL
    };
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_MDT_Location_Info);
    proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
  }



  return offset;
}



static int
dissect_s1ap_MDTMode_Extension(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_ProtocolIE_SingleContainer(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const value_string s1ap_MDTMode_vals[] = {
  {   0, "immediateMDT" },
  {   1, "loggedMDT" },
  {   2, "mDTMode-Extension" },
  { 0, NULL }
};

static const per_choice_t MDTMode_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_ImmediateMDT },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_LoggedMDT },
  {   2,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_MDTMode_Extension },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_MDTMode(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_MDTMode, MDTMode_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t MDT_Configuration_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_MDT_Activation },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_AreaScopeOfMDT },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_MDTMode },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MDT_Configuration(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MDT_Configuration, MDT_Configuration_sequence);

  return offset;
}


static const value_string s1ap_ManagementBasedMDTAllowed_vals[] = {
  {   0, "allowed" },
  { 0, NULL }
};


static int
dissect_s1ap_ManagementBasedMDTAllowed(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t MDTPLMNList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
};

static int
dissect_s1ap_MDTPLMNList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_MDTPLMNList, MDTPLMNList_sequence_of,
                                                  1, maxnoofMDTPLMNs, FALSE);

  return offset;
}


static const value_string s1ap_PrivacyIndicator_vals[] = {
  {   0, "immediate-MDT" },
  {   1, "logged-MDT" },
  { 0, NULL }
};


static int
dissect_s1ap_PrivacyIndicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_MessageIdentifier(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, actx, tree, -1,
                                     16, 16, FALSE, NULL, 0, &parameter_tvb, NULL);

  if (parameter_tvb) {
    actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
  }



  return offset;
}



static int
dissect_s1ap_MobilityInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     32, 32, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_MMEname(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb=NULL;
  int length;
  gboolean is_ascii;

  offset = dissect_per_PrintableString(tvb, offset, 
                                          1, 150, TRUE);


  if (!parameter_tvb)
    return offset;

  length = tvb_reported_length(parameter_tvb);

  is_ascii = tvb_ascii_isprint(parameter_tvb, 0, length);
  if (is_ascii)
     proto_item_append_text(actx->created_item," (%s)",tvb_format_text(parameter_tvb, 0, length));



  return offset;
}


static const value_string s1ap_MMEPagingTarget_vals[] = {
  {   0, "global-ENB-ID" },
  {   1, "tAI" },
  { 0, NULL }
};

static const per_choice_t MMEPagingTarget_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_Global_ENB_ID },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_TAI },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_MMEPagingTarget(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_MMEPagingTarget, MMEPagingTarget_choice,
                                 NULL);

  return offset;
}


static const value_string s1ap_MMERelaySupportIndicator_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_MMERelaySupportIndicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_MME_UE_S1AP_ID(tvbuff_t *tvb, int offset) {
  guint32 mme_ue_s1ap_id;
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 4294967295U, &mme_ue_s1ap_id, FALSE);

  if (hf_index == hf_s1ap_mME_UE_S1AP_ID) {
    proto_item *item;
    item = proto_tree_add_uint(tree, hf_s1ap_MME_UE_S1AP_ID_PDU, tvb, offset, 0 , mme_ue_s1ap_id );
    proto_item_set_hidden(item);
  }



  return offset;
}



static int
dissect_s1ap_MSClassmark2(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_MSClassmark);
    de_ms_cm_2(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
  }



  return offset;
}



static int
dissect_s1ap_MSClassmark3(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_MSClassmark);
    de_ms_cm_3(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
  }



  return offset;
}


static const value_string s1ap_MutingAvailabilityIndication_vals[] = {
  {   0, "available" },
  {   1, "unavailable" },
  { 0, NULL }
};


static int
dissect_s1ap_MutingAvailabilityIndication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_T_muting_pattern_period_vals[] = {
  {   0, "ms0" },
  {   1, "ms1280" },
  {   2, "ms2560" },
  {   3, "ms5120" },
  {   4, "ms10240" },
  { 0, NULL }
};


static int
dissect_s1ap_T_muting_pattern_period(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 5, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t MutingPatternInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_T_muting_pattern_period },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_0_10239_ },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MutingPatternInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MutingPatternInformation, MutingPatternInformation_sequence);

  return offset;
}



static int
dissect_s1ap_MDT_ConfigurationNR(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_MDT_ConfigurationNR);
    dissect_ngap_MDT_Configuration_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
  }



  return offset;
}



static int
dissect_s1ap_NAS_PDU(tvbuff_t *tvb, int offset) {

tvbuff_t *parameter_tvb=NULL;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);


  if ((tvb_reported_length(parameter_tvb)>0)&&(nas_eps_handle))
    call_dissector(nas_eps_handle,parameter_tvb,actx->pinfo, tree);



  return offset;
}



static int
dissect_s1ap_NASSecurityParametersfromE_UTRAN(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_NASSecurityParameters);
    de_emm_sec_par_from_eutra(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
  }



  return offset;
}



static int
dissect_s1ap_NASSecurityParameterstoE_UTRAN(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_NASSecurityParameters);
    de_emm_sec_par_to_eutra(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
  }



  return offset;
}


static const value_string s1ap_NB_IoT_DefaultPagingDRX_vals[] = {
  {   0, "v128" },
  {   1, "v256" },
  {   2, "v512" },
  {   3, "v1024" },
  { 0, NULL }
};


static int
dissect_s1ap_NB_IoT_DefaultPagingDRX(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 4, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_NB_IoT_PagingDRX_vals[] = {
  {   0, "v32" },
  {   1, "v64" },
  {   2, "v128" },
  {   3, "v256" },
  {   4, "v512" },
  {   5, "v1024" },
  { 0, NULL }
};


static int
dissect_s1ap_NB_IoT_PagingDRX(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 6, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_NB_IoT_Paging_eDRX_Cycle_vals[] = {
  {   0, "hf2" },
  {   1, "hf4" },
  {   2, "hf6" },
  {   3, "hf8" },
  {   4, "hf10" },
  {   5, "hf12" },
  {   6, "hf14" },
  {   7, "hf16" },
  {   8, "hf32" },
  {   9, "hf64" },
  {  10, "hf128" },
  {  11, "hf256" },
  {  12, "hf512" },
  {  13, "hf1024" },
  { 0, NULL }
};


static int
dissect_s1ap_NB_IoT_Paging_eDRX_Cycle(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 14, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_NB_IoT_PagingTimeWindow_vals[] = {
  {   0, "s1" },
  {   1, "s2" },
  {   2, "s3" },
  {   3, "s4" },
  {   4, "s5" },
  {   5, "s6" },
  {   6, "s7" },
  {   7, "s8" },
  {   8, "s9" },
  {   9, "s10" },
  {  10, "s11" },
  {  11, "s12" },
  {  12, "s13" },
  {  13, "s14" },
  {  14, "s15" },
  {  15, "s16" },
  { 0, NULL }
};


static int
dissect_s1ap_NB_IoT_PagingTimeWindow(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 16, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t NB_IoT_Paging_eDRXInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NB_IoT_Paging_eDRX_Cycle },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_NB_IoT_PagingTimeWindow },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_NB_IoT_Paging_eDRXInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_NB_IoT_Paging_eDRXInformation, NB_IoT_Paging_eDRXInformation_sequence);

  return offset;
}



static int
dissect_s1ap_NB_IoT_RLF_Report_Container(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_NB_IoT_RLF_Report_Container);
    TRY {
      dissect_lte_rrc_RLF_Report_NB_r16_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
    }
    CATCH_BOUNDS_ERRORS {
      show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
    }
    ENDTRY;
  }



  return offset;
}



static int
dissect_s1ap_NB_IoT_UEIdentityIndexValue(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     12, 12, FALSE, NULL, 0, NULL, NULL);

  return offset;
}


static const value_string s1ap_NotifySourceeNB_vals[] = {
  {   0, "notifySource" },
  { 0, NULL }
};


static int
dissect_s1ap_NotifySourceeNB(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_NRCellIdentity(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     36, 36, FALSE, NULL, 0, NULL, NULL);

  return offset;
}


static const per_sequence_t NR_CGI_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NRCellIdentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_NR_CGI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_NR_CGI, NR_CGI_sequence);

  return offset;
}



static int
dissect_s1ap_NRencryptionAlgorithms(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, 
                                     16, 16, TRUE, NULL, 0, &parameter_tvb, NULL);

  if (parameter_tvb) {
    static int * const fields[] = {
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
      NULL
    };
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_NRencryptionAlgorithms);
    proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 2, fields, ENC_BIG_ENDIAN);
  }



  return offset;
}



static int
dissect_s1ap_NRintegrityProtectionAlgorithms(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, 
                                     16, 16, TRUE, NULL, 0, &parameter_tvb, NULL);

  if (parameter_tvb) {
    static int * const fields[] = {
     &unused_p_id
     &unused_p_id
     &unused_p_id
     &unused_p_id
      NULL
    };
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_NRintegrityProtectionAlgorithms);
    proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 2, fields, ENC_BIG_ENDIAN);
  }



  return offset;
}


static const value_string s1ap_NRrestrictioninEPSasSecondaryRAT_vals[] = {
  {   0, "nRrestrictedinEPSasSecondaryRAT" },
  { 0, NULL }
};


static int
dissect_s1ap_NRrestrictioninEPSasSecondaryRAT(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_NRrestrictionin5GS_vals[] = {
  {   0, "nRrestrictedin5GS" },
  { 0, NULL }
};


static int
dissect_s1ap_NRrestrictionin5GS(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t NRUESecurityCapabilities_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NRencryptionAlgorithms },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NRintegrityProtectionAlgorithms },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_NRUESecurityCapabilities(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_NRUESecurityCapabilities, NRUESecurityCapabilities_sequence);

  return offset;
}



static int
dissect_s1ap_NumberofBroadcastRequest(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 65535U, NULL, FALSE);

  return offset;
}


static const value_string s1ap_VehicleUE_vals[] = {
  {   0, "authorized" },
  {   1, "not-authorized" },
  { 0, NULL }
};


static int
dissect_s1ap_VehicleUE(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_PedestrianUE_vals[] = {
  {   0, "authorized" },
  {   1, "not-authorized" },
  { 0, NULL }
};


static int
dissect_s1ap_PedestrianUE(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t NRV2XServicesAuthorized_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_VehicleUE },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_PedestrianUE },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_NRV2XServicesAuthorized(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_NRV2XServicesAuthorized, NRV2XServicesAuthorized_sequence);

  return offset;
}


static const per_sequence_t NRUESidelinkAggregateMaximumBitrate_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_NRUESidelinkAggregateMaximumBitrate(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_NRUESidelinkAggregateMaximumBitrate, NRUESidelinkAggregateMaximumBitrate_sequence);

  return offset;
}


static const value_string s1ap_OverloadAction_vals[] = {
  {   0, "reject-non-emergency-mo-dt" },
  {   1, "reject-rrc-cr-signalling" },
  {   2, "permit-emergency-sessions-and-mobile-terminated-services-only" },
  {   3, "permit-high-priority-sessions-and-mobile-terminated-services-only" },
  {   4, "reject-delay-tolerant-access" },
  {   5, "permit-high-priority-sessions-and-exception-reporting-and-mobile-terminated-services-only" },
  {   6, "not-accept-mo-data-or-delay-tolerant-access-from-CP-CIoT" },
  { 0, NULL }
};


static int
dissect_s1ap_OverloadAction(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 4, NULL, 1);

  return offset;
}


static const value_string s1ap_OverloadResponse_vals[] = {
  {   0, "overloadAction" },
  { 0, NULL }
};

static const per_choice_t OverloadResponse_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_OverloadAction },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_OverloadResponse(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_OverloadResponse, OverloadResponse_choice,
                                 NULL);

  return offset;
}



static int
dissect_s1ap_Packet_LossRate(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 1000U, NULL, FALSE);

  return offset;
}


static const value_string s1ap_Paging_eDRX_Cycle_vals[] = {
  {   0, "hfhalf" },
  {   1, "hf1" },
  {   2, "hf2" },
  {   3, "hf4" },
  {   4, "hf6" },
  {   5, "hf8" },
  {   6, "hf10" },
  {   7, "hf12" },
  {   8, "hf14" },
  {   9, "hf16" },
  {  10, "hf32" },
  {  11, "hf64" },
  {  12, "hf128" },
  {  13, "hf256" },
  { 0, NULL }
};


static int
dissect_s1ap_Paging_eDRX_Cycle(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 14, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_PagingTimeWindow_vals[] = {
  {   0, "s1" },
  {   1, "s2" },
  {   2, "s3" },
  {   3, "s4" },
  {   4, "s5" },
  {   5, "s6" },
  {   6, "s7" },
  {   7, "s8" },
  {   8, "s9" },
  {   9, "s10" },
  {  10, "s11" },
  {  11, "s12" },
  {  12, "s13" },
  {  13, "s14" },
  {  14, "s15" },
  {  15, "s16" },
  { 0, NULL }
};


static int
dissect_s1ap_PagingTimeWindow(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 16, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t Paging_eDRXInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Paging_eDRX_Cycle },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_PagingTimeWindow },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_Paging_eDRXInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Paging_eDRXInformation, Paging_eDRXInformation_sequence);

  return offset;
}


static const value_string s1ap_PagingDRX_vals[] = {
  {   0, "v32" },
  {   1, "v64" },
  {   2, "v128" },
  {   3, "v256" },
  { 0, NULL }
};


static int
dissect_s1ap_PagingDRX(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 4, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_PagingPriority_vals[] = {
  {   0, "priolevel1" },
  {   1, "priolevel2" },
  {   2, "priolevel3" },
  {   3, "priolevel4" },
  {   4, "priolevel5" },
  {   5, "priolevel6" },
  {   6, "priolevel7" },
  {   7, "priolevel8" },
  { 0, NULL }
};


static int
dissect_s1ap_PagingPriority(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 8, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_PagingProbabilityInformation_vals[] = {
  {   0, "p00" },
  {   1, "p05" },
  {   2, "p10" },
  {   3, "p15" },
  {   4, "p20" },
  {   5, "p25" },
  {   6, "p30" },
  {   7, "p35" },
  {   8, "p40" },
  {   9, "p45" },
  {  10, "p50" },
  {  11, "p55" },
  {  12, "p60" },
  {  13, "p65" },
  {  14, "p70" },
  {  15, "p75" },
  {  16, "p80" },
  {  17, "p85" },
  {  18, "p90" },
  {  19, "p95" },
  {  20, "p100" },
  { 0, NULL }
};


static int
dissect_s1ap_PagingProbabilityInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 21, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t PC5FlowBitRates_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PC5FlowBitRates(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PC5FlowBitRates, PC5FlowBitRates_sequence);

  return offset;
}


static const value_string s1ap_Range_vals[] = {
  {   0, "m50" },
  {   1, "m80" },
  {   2, "m180" },
  {   3, "m200" },
  {   4, "m350" },
  {   5, "m400" },
  {   6, "m500" },
  {   7, "m700" },
  {   8, "m1000" },
  { 0, NULL }
};


static int
dissect_s1ap_Range(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 9, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t PC5QoSFlowItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_FiveQI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_PC5FlowBitRates },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_Range },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PC5QoSFlowItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PC5QoSFlowItem, PC5QoSFlowItem_sequence);

  return offset;
}


static const per_sequence_t PC5QoSFlowList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_PC5QoSFlowItem },
};

static int
dissect_s1ap_PC5QoSFlowList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_PC5QoSFlowList, PC5QoSFlowList_sequence_of,
                                                  1, maxnoofPC5QoSFlows, FALSE);

  return offset;
}


static const per_sequence_t PC5QoSParameters_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PC5QoSFlowList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PC5QoSParameters(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PC5QoSParameters, PC5QoSParameters_sequence);

  return offset;
}


static const value_string s1ap_PendingDataIndication_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_PendingDataIndication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_Port_Number(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       2, 2, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
  }



  return offset;
}


static const value_string s1ap_ProSeDirectDiscovery_vals[] = {
  {   0, "authorized" },
  {   1, "not-authorized" },
  { 0, NULL }
};


static int
dissect_s1ap_ProSeDirectDiscovery(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_ProSeDirectCommunication_vals[] = {
  {   0, "authorized" },
  {   1, "not-authorized" },
  { 0, NULL }
};


static int
dissect_s1ap_ProSeDirectCommunication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t ProSeAuthorized_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProSeDirectDiscovery },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProSeDirectCommunication },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ProSeAuthorized(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ProSeAuthorized, ProSeAuthorized_sequence);

  return offset;
}


static const value_string s1ap_ProSeUEtoNetworkRelaying_vals[] = {
  {   0, "authorized" },
  {   1, "not-authorized" },
  { 0, NULL }
};


static int
dissect_s1ap_ProSeUEtoNetworkRelaying(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_PS_ServiceNotAvailable_vals[] = {
  {   0, "ps-service-not-available" },
  { 0, NULL }
};


static int
dissect_s1ap_PS_ServiceNotAvailable(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t PSCellInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NR_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PSCellInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PSCellInformation, PSCellInformation_sequence);

  return offset;
}



static int
dissect_s1ap_ReceiveStatusOfULPDCPSDUsExtended(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     1, 16384, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     1, 131072, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_INTEGER_0_4095(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 4095U, NULL, FALSE);

  return offset;
}


static const per_sequence_t RecommendedCellItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_0_4095 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_RecommendedCellItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_RecommendedCellItem, RecommendedCellItem_sequence);

  return offset;
}


static const per_sequence_t RecommendedENBItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_MMEPagingTarget },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_RecommendedENBItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_RecommendedENBItem, RecommendedENBItem_sequence);

  return offset;
}


static const value_string s1ap_RelayNode_Indicator_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_RelayNode_Indicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_RAT_Type_vals[] = {
  { nbiot, "nbiot" },
  { 0, NULL }
};


static int
dissect_s1ap_RAT_Type(tvbuff_t *tvb, int offset) {
  guint32 rat_type = 0xffffffff;
                                     1, &rat_type, TRUE, 0, NULL);

  if (s1ap_data->s1ap_conv && s1ap_data->supported_ta && (rat_type == nbiot)) {
    guint64 *key;
    guint i;

    for (i = 0; i < wmem_array_get_count(s1ap_data->supported_ta->plmn); i++) {
      key = wmem_new(wmem_file_scope(), guint64);
      *key = ((*(guint32*)wmem_array_index(s1ap_data->supported_ta->plmn, i)) << 16) | s1ap_data->supported_ta->tac;
      wmem_map_insert(s1ap_data->s1ap_conv->nbiot_ta, key, GUINT_TO_POINTER(1));
    }
  }



  return offset;
}


static const value_string s1ap_ReportArea_vals[] = {
  {   0, "ecgi" },
  { 0, NULL }
};


static int
dissect_s1ap_ReportArea(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t RequestType_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EventType },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ReportArea },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_RequestType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_RequestType, RequestType_sequence);

  return offset;
}


static const value_string s1ap_RequestTypeAdditionalInfo_vals[] = {
  {   0, "includePSCell" },
  { 0, NULL }
};


static int
dissect_s1ap_RequestTypeAdditionalInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_RIMInformation(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);


  if (!parameter_tvb)
    return offset;

  subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_RIMInformation);
  if ((tvb_reported_length(parameter_tvb)>0)&&(bssgp_handle)){
    col_set_fence(actx->pinfo->cinfo, COL_INFO);
    call_dissector(bssgp_handle,parameter_tvb,actx->pinfo, subtree);
  }




  return offset;
}



static int
dissect_s1ap_RNC_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 4095U, NULL, FALSE);

  return offset;
}


static const per_sequence_t TargetRNC_ID_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_LAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_RAC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RNC_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ExtendedRNC_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TargetRNC_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TargetRNC_ID, TargetRNC_ID_sequence);

  return offset;
}



static int
dissect_s1ap_OCTET_STRING_SIZE_16(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       16, 16, FALSE, NULL);

  return offset;
}


static const value_string s1ap_RIMRoutingAddress_vals[] = {
  {   0, "gERAN-Cell-ID" },
  {   1, "targetRNC-ID" },
  {   2, "eHRPD-Sector-ID" },
  { 0, NULL }
};

static const per_choice_t RIMRoutingAddress_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_GERAN_Cell_ID },
  {   1,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_TargetRNC_ID },
  {   2,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_OCTET_STRING_SIZE_16 },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_RIMRoutingAddress(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_RIMRoutingAddress, RIMRoutingAddress_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t RIMTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RIMInformation },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_RIMRoutingAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_RIMTransfer(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_RIMTransfer, RIMTransfer_sequence);

  return offset;
}



static int
dissect_s1ap_RepetitionPeriod(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 4095U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_UE_RLF_Report_Container(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UE_RLF_Report_Container);
      TRY {
        dissect_lte_rrc_RLF_Report_r9_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
      }
      CATCH_BOUNDS_ERRORS {
        show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
      }
      ENDTRY;
  }



  return offset;
}



static int
dissect_s1ap_UE_RLF_Report_Container_for_extended_bands(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UE_RLF_Report_Container_for_extended_bands);
    TRY {
      dissect_lte_rrc_RLF_Report_v9e0_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
    }
    CATCH_BOUNDS_ERRORS {
      show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
    }
    ENDTRY;
  }



  return offset;
}


static const per_sequence_t RLFReportInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_UE_RLF_Report_Container },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_UE_RLF_Report_Container_for_extended_bands },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_RLFReportInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_RLFReportInformation, RLFReportInformation_sequence);

  return offset;
}



static int
dissect_s1ap_RRC_Container(tvbuff_t *tvb, int offset) {


  tvbuff_t *parameter_tvb;
  proto_tree *subtree;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {

    switch(s1ap_data->transparent_container_type){
      case SOURCE_TO_TARGET_TRANSPARENT_CONTAINER:
        /* 9.2.1.7 Source eNB to Target eNB Transparent Container */
        if ((s1ap_is_nbiot_ue(actx->pinfo) && (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_AUTOMATIC)) ||
            (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_NBIOT)) {
          TRY {
            dissect_lte_rrc_HandoverPreparationInformation_NB_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
          }
          CATCH_BOUNDS_ERRORS {
            show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
          }
          ENDTRY;
        } else {
          TRY {
            dissect_lte_rrc_HandoverPreparationInformation_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
          }
          CATCH_BOUNDS_ERRORS {
            show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
          }
          ENDTRY;
        }
        break;
      case TARGET_TO_SOURCE_TRANSPARENT_CONTAINER:
        /* 9.2.1.8 Target eNB to Source eNB Transparent Container */
          TRY {
            dissect_lte_rrc_HandoverCommand_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
          }
          CATCH_BOUNDS_ERRORS {
            show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
          }
          ENDTRY;
        break;
      default:
        break;
    }
  }



  return offset;
}


static const value_string s1ap_RRC_Establishment_Cause_vals[] = {
  {   0, "emergency" },
  {   1, "highPriorityAccess" },
  {   2, "mt-Access" },
  {   3, "mo-Signalling" },
  {   4, "mo-Data" },
  {   5, "delay-TolerantAccess" },
  {   6, "mo-VoiceCall" },
  {   7, "mo-ExceptionData" },
  { 0, NULL }
};


static int
dissect_s1ap_RRC_Establishment_Cause(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 5, NULL, TRUE, 3, NULL, 1);

  return offset;
}


static const per_sequence_t ECGIListForRestart_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
};

static int
dissect_s1ap_ECGIListForRestart(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ECGIListForRestart, ECGIListForRestart_sequence_of,
                                                  1, maxnoofCellsforRestart, FALSE);

  return offset;
}



static int
dissect_s1ap_Routing_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 255U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_SecurityKey(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     256, 256, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_INTEGER_0_7(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 7U, NULL, FALSE);

  return offset;
}


static const per_sequence_t SecurityContext_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_INTEGER_0_7 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_SecurityKey },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SecurityContext(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SecurityContext, SecurityContext_sequence);

  return offset;
}


static const value_string s1ap_SecondaryRATType_vals[] = {
  {   0, "nR" },
  {   1, "unlicensed" },
  { 0, NULL }
};


static int
dissect_s1ap_SecondaryRATType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 1, NULL, 1);

  return offset;
}


static const value_string s1ap_SecondaryRATDataUsageRequest_vals[] = {
  {   0, "requested" },
  { 0, NULL }
};


static int
dissect_s1ap_SecondaryRATDataUsageRequest(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t SecondaryRATDataUsageReportList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_SecondaryRATDataUsageReportList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_SecondaryRATDataUsageReportList, SecondaryRATDataUsageReportList_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t SecondaryRATDataUsageReportItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_SecondaryRATType },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RABUsageReportList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SecondaryRATDataUsageReportItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SecondaryRATDataUsageReportItem, SecondaryRATDataUsageReportItem_sequence);

  return offset;
}



static int
dissect_s1ap_SerialNumber(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, 
                                     16, 16, FALSE, NULL, 0, &parameter_tvb, NULL);

  if (parameter_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_SerialNumber);
    proto_tree_add_item(subtree, hf_s1ap_SerialNumber_gs, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_s1ap_SerialNumber_msg_code, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_s1ap_SerialNumber_upd_nb, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
  }



  return offset;
}


static const value_string s1ap_ServiceType_vals[] = {
  {   0, "qMC-for-streaming-service" },
  {   1, "qMC-for-MTSI-service" },
  { 0, NULL }
};


static int
dissect_s1ap_ServiceType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_SONInformationReport_vals[] = {
  {   0, "rLFReportInformation" },
  { 0, NULL }
};

static const per_choice_t SONInformationReport_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_RLFReportInformation },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_SONInformationReport(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_SONInformationReport, SONInformationReport_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t TargeteNB_ID_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Global_ENB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TargeteNB_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TargeteNB_ID, TargeteNB_ID_sequence);

  return offset;
}


static const per_sequence_t SourceeNB_ID_sequence[] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_Global_ENB_ID },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SourceeNB_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SourceeNB_ID, SourceeNB_ID_sequence);

  return offset;
}


static const per_sequence_t SONConfigurationTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TargeteNB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_SourceeNB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_SONInformation },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SONConfigurationTransfer(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SONConfigurationTransfer, SONConfigurationTransfer_sequence);

  return offset;
}



static int
dissect_s1ap_StratumLevel(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 3U, NULL, TRUE);

  return offset;
}


static const per_sequence_t SynchronisationInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_StratumLevel },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ListeningSubframePattern },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ECGI_List },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SynchronisationInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SynchronisationInformation, SynchronisationInformation_sequence);

  return offset;
}



static int
dissect_s1ap_Source_ToTarget_TransparentContainer(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);


  if ((g_s1ap_dissect_container)&&(parameter_tvb) && (tvb_reported_length(parameter_tvb) > 0)) {
    col_set_writable(actx->pinfo->cinfo, COL_INFO, FALSE);
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_ToTargetTransparentContainer);

    switch(s1ap_data->handover_type_value){
      /*
      HandoverType ::= ENUMERATED {
      intralte,
      ltetoutran,
      ltetogeran,
      utrantolte,
      gerantolte,
      ...
      eps_to_5gs,
      fivegs_to_eps
      } */
      case intralte:
      /* intralte
        Intra E-UTRAN handover Source eNB to Target eNB
        Transparent Container 36.413
      */
      case utrantolte:
      /* utrantolte */
      case gerantolte:
      /* gerantolte */
      case fivegs_to_eps:
      /* fivegs_to_eps */
      dissect_s1ap_SourceeNB_ToTargeteNB_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
      break;
      case ltetoutran:
      /* ltetoutran
        Source RNC to Target RNC
        Transparent Container 25.413
      */
      dissect_ranap_SourceRNC_ToTargetRNC_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
      break;
      case ltetogeran:
      /* ltetogeran
        Source BSS to Target BSS
        Transparent Container 48.018
        or
        Old BSS to New BSS information elements
        Transparent Container 48.008
      */
      if (s1ap_data->srvcc_ho_cs_only)
        bssmap_old_bss_to_new_bss_info(parameter_tvb, subtree, actx->pinfo);
      else
        de_bssgp_source_BSS_to_target_BSS_transp_cont(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
      break;
      case eps_to_5gs:
      /* eps_to_5gs */
      dissect_ngap_SourceNGRANNode_ToTargetNGRANNode_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
      break;
      default:
      break;
    }
    /* Enable writing of the column again */
    col_set_writable(actx->pinfo->cinfo, COL_INFO, TRUE);
  }



  return offset;
}



static const value_string s1ap_SRVCCOperationNotPossible_vals[] = {
  {   0, "notPossible" },
  { 0, NULL }
};


static int
dissect_s1ap_SRVCCOperationNotPossible(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_SRVCCOperationPossible_vals[] = {
  {   0, "possible" },
  { 0, NULL }
};


static int
dissect_s1ap_SRVCCOperationPossible(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_SRVCCHOIndication_vals[] = {
  { pSandCS, "pSandCS" },
  { cSonly, "cSonly" },
  { 0, NULL }
};


static int
dissect_s1ap_SRVCCHOIndication(tvbuff_t *tvb, int offset) {
  guint32 srvcc_ho_ind;
                                     2, &srvcc_ho_ind, TRUE, 0, NULL);

  if (srvcc_ho_ind == cSonly)
    s1ap_data->srvcc_ho_cs_only = TRUE;



  return offset;
}


static const per_sequence_t SourceNgRanNode_ID_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Global_RAN_NODE_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_FiveGSTAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SourceNgRanNode_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SourceNgRanNode_ID, SourceNgRanNode_ID_sequence);

  return offset;
}



static int
dissect_s1ap_SourceNodeID_Extension(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_ProtocolIE_SingleContainer(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const value_string s1ap_SourceNodeID_vals[] = {
  {   0, "sourceNgRanNode-ID" },
  {   1, "sourceNodeID-Extension" },
  { 0, NULL }
};

static const per_choice_t SourceNodeID_choice[] = {
  {   0,&unused_p_id ASN1_NO_EXTENSIONS     , dissect_s1ap_SourceNgRanNode_ID },
  {   1,&unused_p_id ASN1_NO_EXTENSIONS     , dissect_s1ap_SourceNodeID_Extension },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_SourceNodeID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_SourceNodeID, SourceNodeID_choice,
                                 NULL);

  return offset;
}



static int
dissect_s1ap_SubscriberProfileIDforRFP(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 256U, NULL, FALSE);

  return offset;
}


static const per_sequence_t UE_HistoryInformation_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_LastVisitedCell_Item },
};

static int
dissect_s1ap_UE_HistoryInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_UE_HistoryInformation, UE_HistoryInformation_sequence_of,
                                                  1, maxnoofCellsinUEHistoryInfo, FALSE);

  return offset;
}


static const per_sequence_t SourceeNB_ToTargeteNB_TransparentContainer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RRC_Container },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_E_RABInformationList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_SubscriberProfileIDforRFP },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_UE_HistoryInformation },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SourceeNB_ToTargeteNB_TransparentContainer(tvbuff_t *tvb, int offset) {
  s1ap_data->transparent_container_type = SOURCE_TO_TARGET_TRANSPARENT_CONTAINER;


  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SourceeNB_ToTargeteNB_TransparentContainer, SourceeNB_ToTargeteNB_TransparentContainer_sequence);

  return offset;
}




static const per_sequence_t ServedPLMNs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_PLMNidentity },
};

static int
dissect_s1ap_ServedPLMNs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ServedPLMNs, ServedPLMNs_sequence_of,
                                                  1, maxnoofPLMNsPerMME, FALSE);

  return offset;
}


static const per_sequence_t ServedGroupIDs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_MME_Group_ID },
};

static int
dissect_s1ap_ServedGroupIDs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ServedGroupIDs, ServedGroupIDs_sequence_of,
                                                  1, maxnoofGroupIDs, FALSE);

  return offset;
}


static const per_sequence_t ServedMMECs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_MME_Code },
};

static int
dissect_s1ap_ServedMMECs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ServedMMECs, ServedMMECs_sequence_of,
                                                  1, maxnoofMMECs, FALSE);

  return offset;
}


static const per_sequence_t ServedGUMMEIsItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ServedPLMNs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ServedGroupIDs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ServedMMECs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ServedGUMMEIsItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ServedGUMMEIsItem, ServedGUMMEIsItem_sequence);

  return offset;
}


static const per_sequence_t ServedGUMMEIs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ServedGUMMEIsItem },
};

static int
dissect_s1ap_ServedGUMMEIs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ServedGUMMEIs, ServedGUMMEIs_sequence_of,
                                                  1, maxnoofRATs, FALSE);

  return offset;
}


static const value_string s1ap_T_periodicCommunicationIndicator_vals[] = {
  {   0, "periodically" },
  {   1, "ondemand" },
  { 0, NULL }
};


static int
dissect_s1ap_T_periodicCommunicationIndicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_INTEGER_1_3600_(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 3600U, NULL, TRUE);

  return offset;
}



static int
dissect_s1ap_BIT_STRING_SIZE_7(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     7, 7, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_INTEGER_0_86399_(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 86399U, NULL, TRUE);

  return offset;
}


static const per_sequence_t ScheduledCommunicationTime_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_BIT_STRING_SIZE_7 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_0_86399_ },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_0_86399_ },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ScheduledCommunicationTime(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ScheduledCommunicationTime, ScheduledCommunicationTime_sequence);

  return offset;
}


static const value_string s1ap_T_stationaryIndication_vals[] = {
  {   0, "stationary" },
  {   1, "mobile" },
  { 0, NULL }
};


static int
dissect_s1ap_T_stationaryIndication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_T_trafficProfile_vals[] = {
  {   0, "single-packet" },
  {   1, "dual-packets" },
  {   2, "multiple-packets" },
  { 0, NULL }
};


static int
dissect_s1ap_T_trafficProfile(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_T_batteryIndication_vals[] = {
  {   0, "battery-powered" },
  {   1, "battery-powered-not-rechargeable-or-replaceable" },
  {   2, "not-battery-powered" },
  { 0, NULL }
};


static int
dissect_s1ap_T_batteryIndication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t Subscription_Based_UE_DifferentiationInfo_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_T_periodicCommunicationIndicator },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_1_3600_ },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ScheduledCommunicationTime },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_T_stationaryIndication },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_T_trafficProfile },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_T_batteryIndication },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_Subscription_Based_UE_DifferentiationInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Subscription_Based_UE_DifferentiationInfo, Subscription_Based_UE_DifferentiationInfo_sequence);

  return offset;
}


static const value_string s1ap_SynchronisationStatus_vals[] = {
  {   0, "synchronous" },
  {   1, "asynchronous" },
  { 0, NULL }
};


static int
dissect_s1ap_SynchronisationStatus(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t TimeSynchronisationInfo_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_StratumLevel },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_SynchronisationStatus },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TimeSynchronisationInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TimeSynchronisationInfo, TimeSynchronisationInfo_sequence);

  return offset;
}


static const per_sequence_t S_TMSI_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_MME_Code },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_M_TMSI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_S_TMSI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_S_TMSI, S_TMSI_sequence);

  return offset;
}


static const per_sequence_t TAIListforWarning_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
};

static int
dissect_s1ap_TAIListforWarning(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_TAIListforWarning, TAIListforWarning_sequence_of,
                                                  1, maxnoofTAIforWarning, FALSE);

  return offset;
}


static const per_sequence_t TargetNgRanNode_ID_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Global_RAN_NODE_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_FiveGSTAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TargetNgRanNode_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TargetNgRanNode_ID, TargetNgRanNode_ID_sequence);

  return offset;
}


static const value_string s1ap_TargetID_vals[] = {
  {   0, "targeteNB-ID" },
  {   1, "targetRNC-ID" },
  {   2, "cGI" },
  {   3, "targetgNgRanNode-ID" },
  { 0, NULL }
};

static const per_choice_t TargetID_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_TargeteNB_ID },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_TargetRNC_ID },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CGI },
  {   3,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_TargetNgRanNode_ID },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_TargetID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_TargetID, TargetID_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t TargeteNB_ToSourceeNB_TransparentContainer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RRC_Container },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TargeteNB_ToSourceeNB_TransparentContainer(tvbuff_t *tvb, int offset) {
  s1ap_data->transparent_container_type = TARGET_TO_SOURCE_TRANSPARENT_CONTAINER;


  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TargeteNB_ToSourceeNB_TransparentContainer, TargeteNB_ToSourceeNB_TransparentContainer_sequence);

  return offset;
}



static int
dissect_s1ap_Target_ToSource_TransparentContainer(tvbuff_t *tvb, int offset) {

  tvbuff_t *parameter_tvb;
  proto_tree *subtree;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);


  if ((g_s1ap_dissect_container)&&(parameter_tvb) && (tvb_reported_length(parameter_tvb) > 0)) {

    switch(s1ap_data->handover_type_value){
    /*
      HandoverType ::= ENUMERATED {
      intralte,
      ltetoutran,
      ltetogeran,
      utrantolte,
      gerantolte,
      ...
      eps_to_5gs,
      fivegs_to_eps
      } */
      case intralte:
      /* intralte
        Intra E-UTRAN handover Target eNB to Source eNB
        Transparent Container 36.413
      */
      case utrantolte:
      /* utrantolte */
      case gerantolte:
      /* gerantolte */
      case fivegs_to_eps:
      /* fivegs_to_eps */
      dissect_s1ap_TargeteNB_ToSourceeNB_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
      break;
      case ltetoutran:
      /* ltetoutran
        Target RNC to Source RNC
        Transparent Container 25.413
      */
      dissect_ranap_TargetRNC_ToSourceRNC_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
      break;
      case ltetogeran:
      /* ltetogeran
        Target BSS to Source BSS
        Transparent Container 48.018
      */
      de_bssgp_target_BSS_to_source_BSS_transp_cont(parameter_tvb, subtree, actx->pinfo, 0, tvb_reported_length(parameter_tvb), NULL, 0);
      break;
      case eps_to_5gs:
      /* eps_to_5gs */
      dissect_ngap_TargetNGRANNode_ToSourceNGRANNode_TransparentContainer_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
      break;
      default:
      break;
    }
  }



  return offset;
}





static const value_string s1ap_TimeToWait_vals[] = {
  {   0, "v1s" },
  {   1, "v2s" },
  {   2, "v5s" },
  {   3, "v10s" },
  {   4, "v20s" },
  {   5, "v60s" },
  { 0, NULL }
};


static int
dissect_s1ap_TimeToWait(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 6, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_Time_UE_StayedInCell_EnhancedGranularity(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 40950U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_TimeSinceSecondaryNodeRelease(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       4, 4, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, 4, ENC_BIG_ENDIAN);
  }



  return offset;
}


static const per_sequence_t TransportInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TransportInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TransportInformation, TransportInformation_sequence);

  return offset;
}



static int
dissect_s1ap_E_UTRAN_Trace_ID(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       8, 8, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;
  subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_E_UTRAN_Trace_ID);
  dissect_e212_mcc_mnc(parameter_tvb, actx->pinfo, subtree, 0, E212_NONE, FALSE);
  proto_tree_add_item(subtree, hf_s1ap_E_UTRAN_Trace_ID_TraceID, parameter_tvb, 3, 3, ENC_BIG_ENDIAN);
  proto_tree_add_item(subtree, hf_s1ap_E_UTRAN_Trace_ID_TraceRecordingSessionReference, parameter_tvb, 6, 2, ENC_BIG_ENDIAN);



  return offset;
}


static const value_string s1ap_TraceDepth_vals[] = {
  {   0, "minimum" },
  {   1, "medium" },
  {   2, "maximum" },
  {   3, "minimumWithoutVendorSpecificExtension" },
  {   4, "mediumWithoutVendorSpecificExtension" },
  {   5, "maximumWithoutVendorSpecificExtension" },
  { 0, NULL }
};


static int
dissect_s1ap_TraceDepth(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 6, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t TraceActivation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_UTRAN_Trace_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_InterfacesToTrace },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TraceDepth },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TraceActivation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TraceActivation, TraceActivation_sequence);

  return offset;
}



static int
dissect_s1ap_TrafficLoadReductionIndication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 99U, NULL, FALSE);

  return offset;
}


static const per_sequence_t TunnelInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_Port_Number },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TunnelInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TunnelInformation, TunnelInformation_sequence);

  return offset;
}


static const per_sequence_t TAIListForRestart_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
};

static int
dissect_s1ap_TAIListForRestart(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_TAIListForRestart, TAIListForRestart_sequence_of,
                                                  1, maxnoofRestartTAIs, FALSE);

  return offset;
}


static const per_sequence_t UEAggregateMaximumBitrate_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEAggregateMaximumBitrate(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEAggregateMaximumBitrate, UEAggregateMaximumBitrate_sequence);

  return offset;
}



static int
dissect_s1ap_OCTET_STRING_SIZE_1_1000(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       1, 1000, FALSE, NULL);

  return offset;
}


static const per_sequence_t UEAppLayerMeasConfig_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_OCTET_STRING_SIZE_1_1000 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_AreaScopeOfQMC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEAppLayerMeasConfig(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEAppLayerMeasConfig, UEAppLayerMeasConfig_sequence);

  return offset;
}


static const value_string s1ap_UECapabilityInfoRequest_vals[] = {
  {   0, "requested" },
  { 0, NULL }
};


static int
dissect_s1ap_UECapabilityInfoRequest(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_UE_RetentionInformation_vals[] = {
  {   0, "ues-retained" },
  { 0, NULL }
};


static int
dissect_s1ap_UE_RetentionInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t UE_S1AP_ID_pair_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_MME_UE_S1AP_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ENB_UE_S1AP_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UE_S1AP_ID_pair(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UE_S1AP_ID_pair, UE_S1AP_ID_pair_sequence);

  return offset;
}


static const value_string s1ap_UE_S1AP_IDs_vals[] = {
  {   0, "uE-S1AP-ID-pair" },
  {   1, "mME-UE-S1AP-ID" },
  { 0, NULL }
};

static const per_choice_t UE_S1AP_IDs_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_UE_S1AP_ID_pair },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_MME_UE_S1AP_ID },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_UE_S1AP_IDs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_UE_S1AP_IDs, UE_S1AP_IDs_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t UE_associatedLogicalS1_ConnectionItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_MME_UE_S1AP_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ENB_UE_S1AP_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UE_associatedLogicalS1_ConnectionItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UE_associatedLogicalS1_ConnectionItem, UE_associatedLogicalS1_ConnectionItem_sequence);

  return offset;
}



static int
dissect_s1ap_UEIdentityIndexValue(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     10, 10, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_UE_HistoryInformationFromTheUE(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UE_HistoryInformationFromTheUE);
    TRY {
      dissect_lte_rrc_VisitedCellInfoList_r12_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
    }
    CATCH_BOUNDS_ERRORS {
      show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
    }
    ENDTRY;
  }



  return offset;
}


static const value_string s1ap_UEPagingID_vals[] = {
  {   0, "s-TMSI" },
  {   1, "iMSI" },
  { 0, NULL }
};

static const per_choice_t UEPagingID_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_S_TMSI },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_IMSI },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_UEPagingID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_UEPagingID, UEPagingID_choice,
                                 NULL);

  return offset;
}



static int
dissect_s1ap_UERadioCapability(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UERadioCapability);
    if (s1ap_data->protocol_ie_id == id_UERadioCapability_NR_Format) {
      handle = nr_rrc_ue_radio_access_cap_info_handle;
    } else if ((s1ap_is_nbiot_ue(actx->pinfo) && (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_AUTOMATIC)) ||
        (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_NBIOT)) {
      handle = lte_rrc_ue_radio_access_cap_info_nb_handle;
    } else {
      handle = lte_rrc_ue_radio_access_cap_info_handle;
    }
    if (handle) {
      TRY {
        call_dissector(handle, parameter_tvb, actx->pinfo, subtree);
      }
      CATCH_BOUNDS_ERRORS {
        show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
      }
      ENDTRY;
    }
  }



  return offset;
}



static int
dissect_s1ap_UERadioCapabilityForPaging(tvbuff_t *tvb, int offset) {

  tvbuff_t *parameter_tvb;
  proto_tree *subtree;

  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {
    volatile dissector_handle_t handle;
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UERadioPagingInformation);
    if ((s1ap_is_nbiot_ue(actx->pinfo) && (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_AUTOMATIC)) ||
        (g_s1ap_dissect_lte_container_as == S1AP_LTE_CONTAINER_NBIOT)) {
      handle = lte_rrc_ue_radio_paging_info_nb_handle;
    } else {
      handle = lte_rrc_ue_radio_paging_info_handle;
    }
    if (handle) {
      TRY {
        call_dissector(handle, parameter_tvb, actx->pinfo, subtree);
      }
      CATCH_BOUNDS_ERRORS {
        show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
      }
      ENDTRY;
    }
  }



  return offset;
}



static int
dissect_s1ap_UERadioCapabilityID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, NULL);

  return offset;
}


static const per_sequence_t UESecurityCapabilities_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EncryptionAlgorithms },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_IntegrityProtectionAlgorithms },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UESecurityCapabilities(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UESecurityCapabilities, UESecurityCapabilities_sequence);

  return offset;
}


static const per_sequence_t UESidelinkAggregateMaximumBitrate_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_BitRate },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UESidelinkAggregateMaximumBitrate(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UESidelinkAggregateMaximumBitrate, UESidelinkAggregateMaximumBitrate_sequence);

  return offset;
}



static int
dissect_s1ap_UE_Usage_Type(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 255U, NULL, FALSE);

  return offset;
}



static int
dissect_s1ap_UL_NAS_MAC(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     16, 16, FALSE, NULL, 0, NULL, NULL);

  return offset;
}



static int
dissect_s1ap_UL_NAS_Count(tvbuff_t *tvb, int offset) {
  offset = dissect_per_bit_string(tvb, offset, 
                                     5, 5, FALSE, NULL, 0, NULL, NULL);

  return offset;
}


static const per_sequence_t UL_CP_SecurityInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_UL_NAS_MAC },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_UL_NAS_Count },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UL_CP_SecurityInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UL_CP_SecurityInformation, UL_CP_SecurityInformation_sequence);

  return offset;
}


static const value_string s1ap_UnlicensedSpectrumRestriction_vals[] = {
  {   0, "unlicensed-restricted" },
  { 0, NULL }
};


static int
dissect_s1ap_UnlicensedSpectrumRestriction(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t UserLocationInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRAN_CGI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UserLocationInformation(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UserLocationInformation, UserLocationInformation_sequence);

  return offset;
}


static const value_string s1ap_UEUserPlaneCIoTSupportIndicator_vals[] = {
  {   0, "supported" },
  { 0, NULL }
};


static int
dissect_s1ap_UEUserPlaneCIoTSupportIndicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_UE_Application_Layer_Measurement_Capability(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_bit_string(tvb, offset, 
                                     8, 8, FALSE, NULL, 0, &parameter_tvb, NULL);

  if(parameter_tvb){
    static int * const fields[] = {
     &unused_p_id
     &unused_p_id
     &unused_p_id
      NULL
    };
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UE_Application_Layer_Measurement_Capability);
    proto_tree_add_bitmask_list(subtree, parameter_tvb, 0, 1, fields, ENC_BIG_ENDIAN);
  }



  return offset;
}


static const value_string s1ap_VoiceSupportMatchIndicator_vals[] = {
  {   0, "supported" },
  {   1, "not-supported" },
  { 0, NULL }
};


static int
dissect_s1ap_VoiceSupportMatchIndicator(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t V2XServicesAuthorized_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_VehicleUE },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_PedestrianUE },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_V2XServicesAuthorized(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_V2XServicesAuthorized, V2XServicesAuthorized_sequence);

  return offset;
}



static int
dissect_s1ap_WarningAreaCoordinates(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       1, 1024, FALSE, NULL);

  return offset;
}


static const value_string s1ap_WarningAreaList_vals[] = {
  {   0, "cellIDList" },
  {   1, "trackingAreaListforWarning" },
  {   2, "emergencyAreaIDList" },
  { 0, NULL }
};

static const per_choice_t WarningAreaList_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_ECGIList },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_TAIListforWarning },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_EmergencyAreaIDList },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_WarningAreaList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_WarningAreaList, WarningAreaList_choice,
                                 NULL);

  return offset;
}



static int
dissect_s1ap_WarningType(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       2, 2, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    proto_tree *subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_WarningType);
    proto_tree_add_item(subtree, hf_s1ap_WarningType_value, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_s1ap_WarningType_emergency_user_alert, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
    proto_tree_add_item(subtree, hf_s1ap_WarningType_popup, parameter_tvb, 0, 2, ENC_BIG_ENDIAN);
  }



  return offset;
}



static int
dissect_s1ap_WarningSecurityInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       50, 50, FALSE, NULL);

  return offset;
}



static int
dissect_s1ap_WarningMessageContents(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, 
                                       1, 9600, FALSE, &parameter_tvb);

  if (parameter_tvb) {
    dissect_s1ap_warningMessageContents(parameter_tvb, subtree, actx->pinfo, s1ap_data->data_coding_scheme, hf_s1ap_WarningMessageContents_nb_pages, hf_s1ap_WarningMessageContents_decoded_page);
  }



  return offset;
}


static const value_string s1ap_WLANMeasConfig_vals[] = {
  {   0, "setup" },
  { 0, NULL }
};


static int
dissect_s1ap_WLANMeasConfig(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}



static int
dissect_s1ap_WLANName(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb = NULL;
  offset = dissect_per_octet_string(tvb, offset, actx, tree, -1,
                                       1, 32, FALSE, &parameter_tvb);

  actx->created_item = proto_tree_add_item(tree, hf_index, parameter_tvb, 0, -1, ENC_UTF_8|ENC_NA);


  return offset;
}


static const per_sequence_t WLANMeasConfigNameList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_WLANName },
};

static int
dissect_s1ap_WLANMeasConfigNameList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_WLANMeasConfigNameList, WLANMeasConfigNameList_sequence_of,
                                                  1, maxnoofWLANName, FALSE);

  return offset;
}


static const value_string s1ap_T_wlan_rssi_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_T_wlan_rssi(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_T_wlan_rtt_vals[] = {
  {   0, "true" },
  { 0, NULL }
};


static int
dissect_s1ap_T_wlan_rtt(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t WLANMeasurementConfiguration_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_WLANMeasConfig },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_WLANMeasConfigNameList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_T_wlan_rssi },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_T_wlan_rtt },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_WLANMeasurementConfiguration(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_WLANMeasurementConfiguration, WLANMeasurementConfiguration_sequence);

  return offset;
}


static const per_sequence_t WUS_Assistance_Information_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PagingProbabilityInformation },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_WUS_Assistance_Information(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_WUS_Assistance_Information, WUS_Assistance_Information_sequence);

  return offset;
}


static const per_sequence_t ENBX2GTPTLAs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
};

static int
dissect_s1ap_ENBX2GTPTLAs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ENBX2GTPTLAs, ENBX2GTPTLAs_sequence_of,
                                                  1, maxnoofeNBX2GTPTLAs, FALSE);

  return offset;
}


static const per_sequence_t ENBX2ExtTLA_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ENBX2GTPTLAs },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENBX2ExtTLA(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENBX2ExtTLA, ENBX2ExtTLA_sequence);

  return offset;
}


static const per_sequence_t ENBX2ExtTLAs_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ENBX2ExtTLA },
};

static int
dissect_s1ap_ENBX2ExtTLAs(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ENBX2ExtTLAs, ENBX2ExtTLAs_sequence_of,
                                                  1, maxnoofeNBX2ExtTLAs, FALSE);

  return offset;
}


static const per_sequence_t ENBIndirectX2TransportLayerAddresses_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
};

static int
dissect_s1ap_ENBIndirectX2TransportLayerAddresses(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ENBIndirectX2TransportLayerAddresses, ENBIndirectX2TransportLayerAddresses_sequence_of,
                                                  1, maxnoofeNBX2TLAs, FALSE);

  return offset;
}



static int
dissect_s1ap_E_RAB_IE_ContainerList(tvbuff_t *tvb, int offset) {
  asn1_stack_frame_push(actx, "ProtocolIE-ContainerList");
  asn1_param_push_integer(actx, 1);
  asn1_param_push_integer(actx, maxnoofE_RABs);
  offset = dissect_s1ap_ProtocolIE_ContainerList(tvb, offset, actx, tree, hf_index);

  asn1_stack_frame_pop(actx, "ProtocolIE-ContainerList");


  return offset;
}


static const per_sequence_t HandoverRequired_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverRequired(tvbuff_t *tvb, int offset) {
  s1ap_data->srvcc_ho_cs_only = FALSE;
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverRequired");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverRequired, HandoverRequired_sequence);

  return offset;
}


static const per_sequence_t HandoverCommand_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverCommand(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverCommand");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverCommand, HandoverCommand_sequence);

  return offset;
}



static int
dissect_s1ap_E_RABSubjecttoDataForwardingList(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t E_RABDataForwardingItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABDataForwardingItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABDataForwardingItem, E_RABDataForwardingItem_sequence);

  return offset;
}


static const per_sequence_t HandoverPreparationFailure_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverPreparationFailure(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverPreparationFailure");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverPreparationFailure, HandoverPreparationFailure_sequence);

  return offset;
}


static const per_sequence_t HandoverRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverRequest, HandoverRequest_sequence);

  return offset;
}



static int
dissect_s1ap_E_RABToBeSetupListHOReq(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t E_RABToBeSetupItemHOReq_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RABLevelQoSParameters },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABToBeSetupItemHOReq(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABToBeSetupItemHOReq, E_RABToBeSetupItemHOReq_sequence);

  return offset;
}


static const per_sequence_t HandoverRequestAcknowledge_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverRequestAcknowledge(tvbuff_t *tvb, int offset) {

  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverRequestAcknowledge");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverRequestAcknowledge, HandoverRequestAcknowledge_sequence);

  return offset;
}



static int
dissect_s1ap_E_RABAdmittedList(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t E_RABAdmittedItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABAdmittedItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABAdmittedItem, E_RABAdmittedItem_sequence);

  return offset;
}



static int
dissect_s1ap_E_RABFailedtoSetupListHOReqAck(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t E_RABFailedToSetupItemHOReqAck_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Cause },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABFailedToSetupItemHOReqAck(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABFailedToSetupItemHOReqAck, E_RABFailedToSetupItemHOReqAck_sequence);

  return offset;
}


static const per_sequence_t HandoverFailure_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverFailure(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverFailure");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverFailure, HandoverFailure_sequence);

  return offset;
}


static const per_sequence_t HandoverNotify_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverNotify(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverNotify");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverNotify, HandoverNotify_sequence);

  return offset;
}


static const per_sequence_t PathSwitchRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PathSwitchRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PathSwitchRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PathSwitchRequest, PathSwitchRequest_sequence);

  return offset;
}



static int
dissect_s1ap_E_RABToBeSwitchedDLList(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t E_RABToBeSwitchedDLItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABToBeSwitchedDLItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABToBeSwitchedDLItem, E_RABToBeSwitchedDLItem_sequence);

  return offset;
}


static const per_sequence_t PathSwitchRequestAcknowledge_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PathSwitchRequestAcknowledge(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PathSwitchRequestAcknowledge");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PathSwitchRequestAcknowledge, PathSwitchRequestAcknowledge_sequence);

  return offset;
}



static int
dissect_s1ap_E_RABToBeSwitchedULList(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t E_RABToBeSwitchedULItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABToBeSwitchedULItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABToBeSwitchedULItem, E_RABToBeSwitchedULItem_sequence);

  return offset;
}


static const per_sequence_t PathSwitchRequestFailure_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PathSwitchRequestFailure(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PathSwitchRequestFailure");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PathSwitchRequestFailure, PathSwitchRequestFailure_sequence);

  return offset;
}


static const per_sequence_t HandoverCancel_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverCancel(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverCancel");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverCancel, HandoverCancel_sequence);

  return offset;
}


static const per_sequence_t HandoverCancelAcknowledge_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverCancelAcknowledge(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverCancelAcknowledge");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverCancelAcknowledge, HandoverCancelAcknowledge_sequence);

  return offset;
}


static const per_sequence_t HandoverSuccess_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HandoverSuccess(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "HandoverSuccess");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HandoverSuccess, HandoverSuccess_sequence);

  return offset;
}


static const per_sequence_t ENBEarlyStatusTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENBEarlyStatusTransfer(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBEarlyStatusTransfer");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENBEarlyStatusTransfer, ENBEarlyStatusTransfer_sequence);

  return offset;
}


static const per_sequence_t MMEEarlyStatusTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MMEEarlyStatusTransfer(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEEarlyStatusTransfer");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MMEEarlyStatusTransfer, MMEEarlyStatusTransfer_sequence);

  return offset;
}


static const per_sequence_t E_RABSetupRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABSetupRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABSetupRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABSetupRequest, E_RABSetupRequest_sequence);

  return offset;
}


static const per_sequence_t E_RABToBeSetupListBearerSUReq_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABToBeSetupListBearerSUReq(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABToBeSetupListBearerSUReq, E_RABToBeSetupListBearerSUReq_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t E_RABToBeSetupItemBearerSUReq_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RABLevelQoSParameters },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NAS_PDU },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABToBeSetupItemBearerSUReq(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABToBeSetupItemBearerSUReq, E_RABToBeSetupItemBearerSUReq_sequence);

  return offset;
}


static const per_sequence_t E_RABSetupResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABSetupResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABSetupResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABSetupResponse, E_RABSetupResponse_sequence);

  return offset;
}


static const per_sequence_t E_RABSetupListBearerSURes_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABSetupListBearerSURes(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABSetupListBearerSURes, E_RABSetupListBearerSURes_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t E_RABSetupItemBearerSURes_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABSetupItemBearerSURes(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABSetupItemBearerSURes, E_RABSetupItemBearerSURes_sequence);

  return offset;
}


static const per_sequence_t E_RABModifyRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABModifyRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABModifyRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABModifyRequest, E_RABModifyRequest_sequence);

  return offset;
}


static const per_sequence_t E_RABToBeModifiedListBearerModReq_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABToBeModifiedListBearerModReq(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABToBeModifiedListBearerModReq, E_RABToBeModifiedListBearerModReq_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t E_RABToBeModifiedItemBearerModReq_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RABLevelQoSParameters },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NAS_PDU },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABToBeModifiedItemBearerModReq(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABToBeModifiedItemBearerModReq, E_RABToBeModifiedItemBearerModReq_sequence);

  return offset;
}


static const per_sequence_t E_RABModifyResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABModifyResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABModifyResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABModifyResponse, E_RABModifyResponse_sequence);

  return offset;
}


static const per_sequence_t E_RABModifyListBearerModRes_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABModifyListBearerModRes(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABModifyListBearerModRes, E_RABModifyListBearerModRes_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t E_RABModifyItemBearerModRes_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABModifyItemBearerModRes(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABModifyItemBearerModRes, E_RABModifyItemBearerModRes_sequence);

  return offset;
}


static const per_sequence_t E_RABReleaseCommand_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABReleaseCommand(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABReleaseCommand");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABReleaseCommand, E_RABReleaseCommand_sequence);

  return offset;
}


static const per_sequence_t E_RABReleaseResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABReleaseResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABReleaseResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABReleaseResponse, E_RABReleaseResponse_sequence);

  return offset;
}


static const per_sequence_t E_RABReleaseListBearerRelComp_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABReleaseListBearerRelComp(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABReleaseListBearerRelComp, E_RABReleaseListBearerRelComp_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t E_RABReleaseItemBearerRelComp_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABReleaseItemBearerRelComp(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABReleaseItemBearerRelComp, E_RABReleaseItemBearerRelComp_sequence);

  return offset;
}


static const per_sequence_t E_RABReleaseIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABReleaseIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABReleaseIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABReleaseIndication, E_RABReleaseIndication_sequence);

  return offset;
}


static const per_sequence_t InitialContextSetupRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_InitialContextSetupRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "InitialContextSetupRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_InitialContextSetupRequest, InitialContextSetupRequest_sequence);

  return offset;
}


static const per_sequence_t E_RABToBeSetupListCtxtSUReq_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABToBeSetupListCtxtSUReq(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABToBeSetupListCtxtSUReq, E_RABToBeSetupListCtxtSUReq_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t E_RABToBeSetupItemCtxtSUReq_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RABLevelQoSParameters },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_NAS_PDU },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABToBeSetupItemCtxtSUReq(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABToBeSetupItemCtxtSUReq, E_RABToBeSetupItemCtxtSUReq_sequence);

  return offset;
}


static const per_sequence_t InitialContextSetupResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_InitialContextSetupResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "InitialContextSetupResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_InitialContextSetupResponse, InitialContextSetupResponse_sequence);

  return offset;
}


static const per_sequence_t E_RABSetupListCtxtSURes_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABSetupListCtxtSURes(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABSetupListCtxtSURes, E_RABSetupListCtxtSURes_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t E_RABSetupItemCtxtSURes_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABSetupItemCtxtSURes(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABSetupItemCtxtSURes, E_RABSetupItemCtxtSURes_sequence);

  return offset;
}


static const per_sequence_t InitialContextSetupFailure_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_InitialContextSetupFailure(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "InitialContextSetupFailure");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_InitialContextSetupFailure, InitialContextSetupFailure_sequence);

  return offset;
}


static const per_sequence_t Paging_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_Paging(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Paging");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Paging, Paging_sequence);

  return offset;
}


static const per_sequence_t TAIList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_TAIList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_TAIList, TAIList_sequence_of,
                                                  1, maxnoofTAIs, FALSE);

  return offset;
}


static const per_sequence_t TAIItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TAI },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TAIItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TAIItem, TAIItem_sequence);

  return offset;
}


static const per_sequence_t UEContextReleaseRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextReleaseRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextReleaseRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextReleaseRequest, UEContextReleaseRequest_sequence);

  return offset;
}


static const per_sequence_t UEContextReleaseCommand_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextReleaseCommand(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextReleaseCommand");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextReleaseCommand, UEContextReleaseCommand_sequence);

  return offset;
}


static const per_sequence_t UEContextReleaseComplete_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextReleaseComplete(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextReleaseComplete");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextReleaseComplete, UEContextReleaseComplete_sequence);

  return offset;
}


static const per_sequence_t UEContextModificationRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextModificationRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextModificationRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextModificationRequest, UEContextModificationRequest_sequence);

  return offset;
}


static const per_sequence_t UEContextModificationResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextModificationResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextModificationResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextModificationResponse, UEContextModificationResponse_sequence);

  return offset;
}


static const per_sequence_t UEContextModificationFailure_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextModificationFailure(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextModificationFailure");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextModificationFailure, UEContextModificationFailure_sequence);

  return offset;
}


static const per_sequence_t UERadioCapabilityMatchRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UERadioCapabilityMatchRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UERadioCapabilityMatchRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UERadioCapabilityMatchRequest, UERadioCapabilityMatchRequest_sequence);

  return offset;
}


static const per_sequence_t UERadioCapabilityMatchResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UERadioCapabilityMatchResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UERadioCapabilityMatchResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UERadioCapabilityMatchResponse, UERadioCapabilityMatchResponse_sequence);

  return offset;
}


static const per_sequence_t DownlinkNASTransport_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_DownlinkNASTransport(tvbuff_t *tvb, int offset) {
  /* Set the direction of the message */
  actx->pinfo->link_dir=P2P_DIR_DL;

  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "DownlinkNASTransport");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_DownlinkNASTransport, DownlinkNASTransport_sequence);

  return offset;
}


static const per_sequence_t InitialUEMessage_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_InitialUEMessage(tvbuff_t *tvb, int offset) {
  /* Set the direction of the message */
  actx->pinfo->link_dir=P2P_DIR_UL;

  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "InitialUEMessage");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_InitialUEMessage, InitialUEMessage_sequence);

  return offset;
}


static const per_sequence_t UplinkNASTransport_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UplinkNASTransport(tvbuff_t *tvb, int offset) {
  /* Set the direction of the message */
  actx->pinfo->link_dir=P2P_DIR_UL;

  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UplinkNASTransport");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UplinkNASTransport, UplinkNASTransport_sequence);

  return offset;
}


static const per_sequence_t NASNonDeliveryIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_NASNonDeliveryIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "NASNonDeliveryIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_NASNonDeliveryIndication, NASNonDeliveryIndication_sequence);

  return offset;
}


static const per_sequence_t RerouteNASRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_RerouteNASRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "RerouteNASRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_RerouteNASRequest, RerouteNASRequest_sequence);

  return offset;
}



static int
dissect_s1ap_S1_Message(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_S1_Message);
  col_set_fence(actx->pinfo->cinfo, COL_INFO);
  call_dissector(s1ap_handle, parameter_tvb, actx->pinfo, subtree);



  return offset;
}


static const per_sequence_t NASDeliveryIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_NASDeliveryIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "NASDeliveryIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_NASDeliveryIndication, NASDeliveryIndication_sequence);

  return offset;
}


static const per_sequence_t Reset_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_Reset(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "Reset");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_Reset, Reset_sequence);

  return offset;
}


static const value_string s1ap_ResetAll_vals[] = {
  {   0, "reset-all" },
  { 0, NULL }
};


static int
dissect_s1ap_ResetAll(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t UE_associatedLogicalS1_ConnectionListRes_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_UE_associatedLogicalS1_ConnectionListRes(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_UE_associatedLogicalS1_ConnectionListRes, UE_associatedLogicalS1_ConnectionListRes_sequence_of,
                                                  1, maxnoofIndividualS1ConnectionsToReset, FALSE);

  return offset;
}


static const value_string s1ap_ResetType_vals[] = {
  {   0, "s1-Interface" },
  {   1, "partOfS1-Interface" },
  { 0, NULL }
};

static const per_choice_t ResetType_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_ResetAll },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_UE_associatedLogicalS1_ConnectionListRes },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_ResetType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_ResetType, ResetType_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t ResetAcknowledge_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ResetAcknowledge(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ResetAcknowledge");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ResetAcknowledge, ResetAcknowledge_sequence);

  return offset;
}


static const per_sequence_t UE_associatedLogicalS1_ConnectionListResAck_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_UE_associatedLogicalS1_ConnectionListResAck(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_UE_associatedLogicalS1_ConnectionListResAck, UE_associatedLogicalS1_ConnectionListResAck_sequence_of,
                                                  1, maxnoofIndividualS1ConnectionsToReset, FALSE);

  return offset;
}


static const per_sequence_t ErrorIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ErrorIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ErrorIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ErrorIndication, ErrorIndication_sequence);

  return offset;
}


static const per_sequence_t S1SetupRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_S1SetupRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "S1SetupRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_S1SetupRequest, S1SetupRequest_sequence);

  return offset;
}


static const per_sequence_t S1SetupResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_S1SetupResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "S1SetupResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_S1SetupResponse, S1SetupResponse_sequence);

  return offset;
}


static const per_sequence_t S1SetupFailure_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_S1SetupFailure(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "S1SetupFailure");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_S1SetupFailure, S1SetupFailure_sequence);

  return offset;
}


static const per_sequence_t ENBConfigurationUpdate_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENBConfigurationUpdate(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationUpdate");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENBConfigurationUpdate, ENBConfigurationUpdate_sequence);

  return offset;
}


static const per_sequence_t ENBConfigurationUpdateAcknowledge_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENBConfigurationUpdateAcknowledge(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationUpdateAcknowledge");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENBConfigurationUpdateAcknowledge, ENBConfigurationUpdateAcknowledge_sequence);

  return offset;
}


static const per_sequence_t ENBConfigurationUpdateFailure_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENBConfigurationUpdateFailure(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationUpdateFailure");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENBConfigurationUpdateFailure, ENBConfigurationUpdateFailure_sequence);

  return offset;
}


static const per_sequence_t MMEConfigurationUpdate_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MMEConfigurationUpdate(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEConfigurationUpdate");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MMEConfigurationUpdate, MMEConfigurationUpdate_sequence);

  return offset;
}


static const per_sequence_t MMEConfigurationUpdateAcknowledge_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MMEConfigurationUpdateAcknowledge(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEConfigurationUpdateAcknowledge");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MMEConfigurationUpdateAcknowledge, MMEConfigurationUpdateAcknowledge_sequence);

  return offset;
}


static const per_sequence_t MMEConfigurationUpdateFailure_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MMEConfigurationUpdateFailure(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEConfigurationUpdateFailure");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MMEConfigurationUpdateFailure, MMEConfigurationUpdateFailure_sequence);

  return offset;
}


static const per_sequence_t DownlinkS1cdma2000tunnelling_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_DownlinkS1cdma2000tunnelling(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "DownlinkS1cdma2000tunnelling");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_DownlinkS1cdma2000tunnelling, DownlinkS1cdma2000tunnelling_sequence);

  return offset;
}


static const per_sequence_t UplinkS1cdma2000tunnelling_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UplinkS1cdma2000tunnelling(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UplinkS1cdma2000tunnelling");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UplinkS1cdma2000tunnelling, UplinkS1cdma2000tunnelling_sequence);

  return offset;
}


static const per_sequence_t UECapabilityInfoIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UECapabilityInfoIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UECapabilityInfoIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UECapabilityInfoIndication, UECapabilityInfoIndication_sequence);

  return offset;
}


static const per_sequence_t ENBStatusTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENBStatusTransfer(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBStatusTransfer");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENBStatusTransfer, ENBStatusTransfer_sequence);

  return offset;
}


static const per_sequence_t MMEStatusTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MMEStatusTransfer(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEStatusTransfer");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MMEStatusTransfer, MMEStatusTransfer_sequence);

  return offset;
}


static const per_sequence_t TraceStart_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TraceStart(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "TraceStart");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TraceStart, TraceStart_sequence);

  return offset;
}


static const per_sequence_t TraceFailureIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TraceFailureIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "TraceFailureIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TraceFailureIndication, TraceFailureIndication_sequence);

  return offset;
}


static const per_sequence_t DeactivateTrace_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_DeactivateTrace(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "DeactivateTrace");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_DeactivateTrace, DeactivateTrace_sequence);

  return offset;
}


static const per_sequence_t CellTrafficTrace_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellTrafficTrace(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "CellTrafficTrace");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellTrafficTrace, CellTrafficTrace_sequence);

  return offset;
}


static const per_sequence_t LocationReportingControl_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_LocationReportingControl(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "LocationReportingControl");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_LocationReportingControl, LocationReportingControl_sequence);

  return offset;
}


static const per_sequence_t LocationReportingFailureIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_LocationReportingFailureIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "LocationReportingFailureIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_LocationReportingFailureIndication, LocationReportingFailureIndication_sequence);

  return offset;
}


static const per_sequence_t LocationReport_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_LocationReport(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "LocationReport");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_LocationReport, LocationReport_sequence);

  return offset;
}


static const per_sequence_t OverloadStart_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_OverloadStart(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "OverloadStart");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_OverloadStart, OverloadStart_sequence);

  return offset;
}


static const per_sequence_t OverloadStop_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_OverloadStop(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "OverloadStop");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_OverloadStop, OverloadStop_sequence);

  return offset;
}


static const per_sequence_t WriteReplaceWarningRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_WriteReplaceWarningRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "WriteReplaceWarningRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_WriteReplaceWarningRequest, WriteReplaceWarningRequest_sequence);

  return offset;
}


static const per_sequence_t WriteReplaceWarningResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_WriteReplaceWarningResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "WriteReplaceWarningResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_WriteReplaceWarningResponse, WriteReplaceWarningResponse_sequence);

  return offset;
}


static const per_sequence_t ENBDirectInformationTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENBDirectInformationTransfer(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBDirectInformationTransfer");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENBDirectInformationTransfer, ENBDirectInformationTransfer_sequence);

  return offset;
}


static const value_string s1ap_Inter_SystemInformationTransferType_vals[] = {
  {   0, "rIMTransfer" },
  { 0, NULL }
};

static const per_choice_t Inter_SystemInformationTransferType_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_RIMTransfer },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_Inter_SystemInformationTransferType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_Inter_SystemInformationTransferType, Inter_SystemInformationTransferType_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t MMEDirectInformationTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MMEDirectInformationTransfer(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEDirectInformationTransfer");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MMEDirectInformationTransfer, MMEDirectInformationTransfer_sequence);

  return offset;
}


static const per_sequence_t ENBConfigurationTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENBConfigurationTransfer(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBConfigurationTransfer");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENBConfigurationTransfer, ENBConfigurationTransfer_sequence);

  return offset;
}


static const per_sequence_t MMEConfigurationTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MMEConfigurationTransfer(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMEConfigurationTransfer");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MMEConfigurationTransfer, MMEConfigurationTransfer_sequence);

  return offset;
}


static const per_sequence_t PrivateMessage_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_PrivateIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PrivateMessage(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PrivateMessage");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PrivateMessage, PrivateMessage_sequence);

  return offset;
}


static const per_sequence_t KillRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_KillRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "KillRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_KillRequest, KillRequest_sequence);

  return offset;
}


static const per_sequence_t KillResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_KillResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "KillResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_KillResponse, KillResponse_sequence);

  return offset;
}


static const per_sequence_t PWSRestartIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PWSRestartIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PWSRestartIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PWSRestartIndication, PWSRestartIndication_sequence);

  return offset;
}


static const per_sequence_t PWSFailureIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_PWSFailureIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "PWSFailureIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_PWSFailureIndication, PWSFailureIndication_sequence);

  return offset;
}


static const per_sequence_t DownlinkUEAssociatedLPPaTransport_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_DownlinkUEAssociatedLPPaTransport(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "DownlinkUEAssociatedLPPaTransport");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_DownlinkUEAssociatedLPPaTransport, DownlinkUEAssociatedLPPaTransport_sequence);

  return offset;
}


static const per_sequence_t UplinkUEAssociatedLPPaTransport_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UplinkUEAssociatedLPPaTransport(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UplinkUEAssociatedLPPaTransport");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UplinkUEAssociatedLPPaTransport, UplinkUEAssociatedLPPaTransport_sequence);

  return offset;
}


static const per_sequence_t DownlinkNonUEAssociatedLPPaTransport_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_DownlinkNonUEAssociatedLPPaTransport(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "DownlinkNonUEAssociatedLPPaTransport");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_DownlinkNonUEAssociatedLPPaTransport, DownlinkNonUEAssociatedLPPaTransport_sequence);

  return offset;
}


static const per_sequence_t UplinkNonUEAssociatedLPPaTransport_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UplinkNonUEAssociatedLPPaTransport(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UplinkNonUEAssociatedLPPaTransport");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UplinkNonUEAssociatedLPPaTransport, UplinkNonUEAssociatedLPPaTransport_sequence);

  return offset;
}


static const per_sequence_t E_RABModificationIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABModificationIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABModificationIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABModificationIndication, E_RABModificationIndication_sequence);

  return offset;
}



static int
dissect_s1ap_E_RABToBeModifiedListBearerModInd(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t E_RABToBeModifiedItemBearerModInd_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABToBeModifiedItemBearerModInd(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABToBeModifiedItemBearerModInd, E_RABToBeModifiedItemBearerModInd_sequence);

  return offset;
}



static int
dissect_s1ap_E_RABNotToBeModifiedListBearerModInd(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t E_RABNotToBeModifiedItemBearerModInd_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_TransportLayerAddress },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_GTP_TEID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABNotToBeModifiedItemBearerModInd(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABNotToBeModifiedItemBearerModInd, E_RABNotToBeModifiedItemBearerModInd_sequence);

  return offset;
}


static const per_sequence_t CSGMembershipInfo_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CSGMembershipStatus },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CSG_Id },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_CellAccessMode },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_PLMNidentity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CSGMembershipInfo(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CSGMembershipInfo, CSGMembershipInfo_sequence);

  return offset;
}


static const per_sequence_t E_RABModificationConfirm_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABModificationConfirm(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "E-RABModificationConfirm");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABModificationConfirm, E_RABModificationConfirm_sequence);

  return offset;
}


static const per_sequence_t E_RABModifyListBearerModConf_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_SingleContainer },
};

static int
dissect_s1ap_E_RABModifyListBearerModConf(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_E_RABModifyListBearerModConf, E_RABModifyListBearerModConf_sequence_of,
                                                  1, maxnoofE_RABs, FALSE);

  return offset;
}


static const per_sequence_t E_RABModifyItemBearerModConf_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABModifyItemBearerModConf(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABModifyItemBearerModConf, E_RABModifyItemBearerModConf_sequence);

  return offset;
}


static const per_sequence_t UEContextModificationIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextModificationIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextModificationIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextModificationIndication, UEContextModificationIndication_sequence);

  return offset;
}


static const per_sequence_t UEContextModificationConfirm_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextModificationConfirm(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextModificationConfirm");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextModificationConfirm, UEContextModificationConfirm_sequence);

  return offset;
}


static const per_sequence_t UEContextSuspendRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextSuspendRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextSuspendRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextSuspendRequest, UEContextSuspendRequest_sequence);

  return offset;
}


static const per_sequence_t UEContextSuspendResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextSuspendResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextSuspendResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextSuspendResponse, UEContextSuspendResponse_sequence);

  return offset;
}


static const per_sequence_t UEContextResumeRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextResumeRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextResumeRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextResumeRequest, UEContextResumeRequest_sequence);

  return offset;
}



static int
dissect_s1ap_E_RABFailedToResumeListResumeReq(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t E_RABFailedToResumeItemResumeReq_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Cause },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABFailedToResumeItemResumeReq(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABFailedToResumeItemResumeReq, E_RABFailedToResumeItemResumeReq_sequence);

  return offset;
}


static const per_sequence_t UEContextResumeResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextResumeResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextResumeResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextResumeResponse, UEContextResumeResponse_sequence);

  return offset;
}



static int
dissect_s1ap_E_RABFailedToResumeListResumeRes(tvbuff_t *tvb, int offset) {
  offset = dissect_s1ap_E_RAB_IE_ContainerList(tvb, offset, actx, tree, hf_index);

  return offset;
}


static const per_sequence_t E_RABFailedToResumeItemResumeRes_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_E_RAB_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_Cause },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_ProtocolExtensionContainer },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_E_RABFailedToResumeItemResumeRes(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_E_RABFailedToResumeItemResumeRes, E_RABFailedToResumeItemResumeRes_sequence);

  return offset;
}


static const per_sequence_t UEContextResumeFailure_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEContextResumeFailure(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEContextResumeFailure");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEContextResumeFailure, UEContextResumeFailure_sequence);

  return offset;
}


static const per_sequence_t ConnectionEstablishmentIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ConnectionEstablishmentIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ConnectionEstablishmentIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ConnectionEstablishmentIndication, ConnectionEstablishmentIndication_sequence);

  return offset;
}


static const per_sequence_t RetrieveUEInformation_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_RetrieveUEInformation(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "RetrieveUEInformation");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_RetrieveUEInformation, RetrieveUEInformation_sequence);

  return offset;
}


static const per_sequence_t UEInformationTransfer_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UEInformationTransfer(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UEInformationTransfer");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UEInformationTransfer, UEInformationTransfer_sequence);

  return offset;
}


static const per_sequence_t ENBCPRelocationIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ENBCPRelocationIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "ENBCPRelocationIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ENBCPRelocationIndication, ENBCPRelocationIndication_sequence);

  return offset;
}


static const per_sequence_t MMECPRelocationIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MMECPRelocationIndication(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "MMECPRelocationIndication");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MMECPRelocationIndication, MMECPRelocationIndication_sequence);

  return offset;
}


static const per_sequence_t SecondaryRATDataUsageReport_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SecondaryRATDataUsageReport(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "SecondaryRATDataUsageReport");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SecondaryRATDataUsageReport, SecondaryRATDataUsageReport_sequence);

  return offset;
}


static const per_sequence_t UERadioCapabilityIDMappingRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UERadioCapabilityIDMappingRequest(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UERadioCapabilityIDMappingRequest");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UERadioCapabilityIDMappingRequest, UERadioCapabilityIDMappingRequest_sequence);

  return offset;
}


static const per_sequence_t UERadioCapabilityIDMappingResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ProtocolIE_Container },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UERadioCapabilityIDMappingResponse(tvbuff_t *tvb, int offset) {
  col_append_sep_str(actx->pinfo->cinfo, COL_INFO, NULL, "UERadioCapabilityIDMappingResponse");

  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UERadioCapabilityIDMappingResponse, UERadioCapabilityIDMappingResponse_sequence);

  return offset;
}



static int
dissect_s1ap_InitiatingMessage_value(tvbuff_t *tvb, int offset) {

  offset = dissect_per_open_type_pdu_new(tvb, offset,  dissect_InitiatingMessageValue);

  return offset;
}


static const per_sequence_t InitiatingMessage_sequence[] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProcedureCode },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_Criticality },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_InitiatingMessage_value },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_InitiatingMessage(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_InitiatingMessage, InitiatingMessage_sequence);

  return offset;
}



static int
dissect_s1ap_SuccessfulOutcome_value(tvbuff_t *tvb, int offset) {

  offset = dissect_per_open_type_pdu_new(tvb, offset,  dissect_SuccessfulOutcomeValue);

  return offset;
}


static const per_sequence_t SuccessfulOutcome_sequence[] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProcedureCode },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_Criticality },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_SuccessfulOutcome_value },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_SuccessfulOutcome(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_SuccessfulOutcome, SuccessfulOutcome_sequence);

  return offset;
}



static int
dissect_s1ap_UnsuccessfulOutcome_value(tvbuff_t *tvb, int offset) {




  offset = dissect_per_open_type_pdu_new(tvb, offset,  dissect_UnsuccessfulOutcomeValue);

  return offset;
}


static const per_sequence_t UnsuccessfulOutcome_sequence[] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ProcedureCode },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_Criticality },
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_UnsuccessfulOutcome_value },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_UnsuccessfulOutcome(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_UnsuccessfulOutcome, UnsuccessfulOutcome_sequence);

  return offset;
}


static const value_string s1ap_S1AP_PDU_vals[] = {
  {   0, "initiatingMessage" },
  {   1, "successfulOutcome" },
  {   2, "unsuccessfulOutcome" },
  { 0, NULL }
};

static const per_choice_t S1AP_PDU_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_InitiatingMessage },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_SuccessfulOutcome },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_UnsuccessfulOutcome },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_S1AP_PDU(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_S1AP_PDU, S1AP_PDU_choice,
                                 NULL);

  return offset;
}


static const value_string s1ap_SONtransferApplicationIdentity_vals[] = {
  {   0, "cell-load-reporting" },
  {   1, "multi-cell-load-reporting" },
  {   2, "event-triggered-cell-load-reporting" },
  {   3, "ho-reporting" },
  {   4, "eutran-cell-activation" },
  {   5, "energy-savings-indication" },
  {   6, "failure-event-reporting" },
  { 0, NULL }
};


static int
dissect_s1ap_SONtransferApplicationIdentity(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 6, NULL, 1);

  return offset;
}



static int
dissect_s1ap_OCTET_STRING(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, NULL);

  return offset;
}



static int
dissect_s1ap_EHRPD_Sector_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       16, 16, FALSE, NULL);

  return offset;
}


static const value_string s1ap_IRAT_Cell_ID_vals[] = {
  {   0, "eUTRAN" },
  {   1, "uTRAN" },
  {   2, "gERAN" },
  {   3, "eHRPD" },
  { 0, NULL }
};

static const per_choice_t IRAT_Cell_ID_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_OCTET_STRING },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_OCTET_STRING },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_OCTET_STRING },
  {   3,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_EHRPD_Sector_ID },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_IRAT_Cell_ID(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_IRAT_Cell_ID, IRAT_Cell_ID_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t RequestedCellList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_IRAT_Cell_ID },
};

static int
dissect_s1ap_RequestedCellList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_RequestedCellList, RequestedCellList_sequence_of,
                                                  1, maxnoofIRATReportingCells, FALSE);

  return offset;
}


static const per_sequence_t MultiCellLoadReportingRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_RequestedCellList },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_MultiCellLoadReportingRequest(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_MultiCellLoadReportingRequest, MultiCellLoadReportingRequest_sequence);

  return offset;
}


static const value_string s1ap_NumberOfMeasurementReportingLevels_vals[] = {
  {   0, "rl2" },
  {   1, "rl3" },
  {   2, "rl4" },
  {   3, "rl5" },
  {   4, "rl10" },
  { 0, NULL }
};


static int
dissect_s1ap_NumberOfMeasurementReportingLevels(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 5, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t EventTriggeredCellLoadReportingRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NumberOfMeasurementReportingLevels },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EventTriggeredCellLoadReportingRequest(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EventTriggeredCellLoadReportingRequest, EventTriggeredCellLoadReportingRequest_sequence);

  return offset;
}


static const value_string s1ap_HoType_vals[] = {
  {   0, "ltetoutran" },
  {   1, "ltetogeran" },
  { 0, NULL }
};


static int
dissect_s1ap_HoType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_HoReportType_vals[] = {
  {   0, "unnecessaryhotoanotherrat" },
  {   1, "earlyirathandover" },
  { 0, NULL }
};


static int
dissect_s1ap_HoReportType(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 1, NULL, 1);

  return offset;
}


static const per_sequence_t CandidateCellList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_IRAT_Cell_ID },
};

static int
dissect_s1ap_CandidateCellList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CandidateCellList, CandidateCellList_sequence_of,
                                                  1, maxnoofcandidateCells, FALSE);

  return offset;
}



static int
dissect_s1ap_INTEGER_0_503(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 503U, NULL, FALSE);

  return offset;
}


static const per_sequence_t CandidatePCI_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_INTEGER_0_503 },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_OCTET_STRING },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CandidatePCI(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CandidatePCI, CandidatePCI_sequence);

  return offset;
}


static const per_sequence_t CandidatePCIList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CandidatePCI },
};

static int
dissect_s1ap_CandidatePCIList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CandidatePCIList, CandidatePCIList_sequence_of,
                                                  1, maxnoofcandidateCells, FALSE);

  return offset;
}


static const per_sequence_t HOReport_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_HoType },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_HoReportType },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_IRAT_Cell_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_IRAT_Cell_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CandidateCellList },
  {&unused_p_id ASN1_NOT_EXTENSION_ROOT, ASN1_OPTIONAL    , dissect_s1ap_CandidatePCIList },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_HOReport(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_HOReport, HOReport_sequence);

  return offset;
}


static const per_sequence_t CellsToActivateList_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_OCTET_STRING },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellsToActivateList_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellsToActivateList_Item, CellsToActivateList_Item_sequence);

  return offset;
}


static const per_sequence_t CellsToActivateList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_CellsToActivateList_Item },
};

static int
dissect_s1ap_CellsToActivateList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_CellsToActivateList, CellsToActivateList_sequence_of,
                                                  1, maxnoofCellineNB, FALSE);

  return offset;
}



static int
dissect_s1ap_INTEGER_1_60(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 60U, NULL, FALSE);

  return offset;
}


static const per_sequence_t CellActivationRequest_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CellsToActivateList },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_INTEGER_1_60 },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellActivationRequest(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellActivationRequest, CellActivationRequest_sequence);

  return offset;
}


static const value_string s1ap_NotifyFlag_vals[] = {
  {   0, "activated" },
  {   1, "deactivated" },
  { 0, NULL }
};


static int
dissect_s1ap_NotifyFlag(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 2, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t NotificationCellList_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_OCTET_STRING },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NotifyFlag },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_NotificationCellList_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_NotificationCellList_Item, NotificationCellList_Item_sequence);

  return offset;
}


static const per_sequence_t NotificationCellList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_NotificationCellList_Item },
};

static int
dissect_s1ap_NotificationCellList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_NotificationCellList, NotificationCellList_sequence_of,
                                                  1, maxnoofCellineNB, FALSE);

  return offset;
}


static const per_sequence_t CellStateIndication_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_NotificationCellList },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellStateIndication(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellStateIndication, CellStateIndication_sequence);

  return offset;
}



static int
dissect_s1ap_T_uERLFReportContainer(tvbuff_t *tvb, int offset) {
  tvbuff_t *parameter_tvb;
  proto_tree *subtree;
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, &parameter_tvb);

  if (!parameter_tvb)
    return offset;

  if (g_s1ap_dissect_container) {
    subtree = proto_item_add_subtree(actx->created_item, ett_s1ap_UE_RLF_Report_Container);
    TRY {
      dissect_lte_rrc_RLF_Report_r9_PDU(parameter_tvb, actx->pinfo, subtree, NULL);
    }
    CATCH_BOUNDS_ERRORS {
      show_exception(parameter_tvb, actx->pinfo, subtree, EXCEPT_CODE, GET_MESSAGE);
    }
    ENDTRY;
  }



  return offset;
}


static const per_sequence_t TooEarlyInterRATHOReportReportFromEUTRAN_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_T_uERLFReportContainer },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_MobilityInformation },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_TooEarlyInterRATHOReportReportFromEUTRAN(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_TooEarlyInterRATHOReportReportFromEUTRAN, TooEarlyInterRATHOReportReportFromEUTRAN_sequence);

  return offset;
}


static const value_string s1ap_FailureEventReport_vals[] = {
  {   0, "tooEarlyInterRATHOReportFromEUTRAN" },
  { 0, NULL }
};

static const per_choice_t FailureEventReport_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_TooEarlyInterRATHOReportReportFromEUTRAN },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_FailureEventReport(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_FailureEventReport, FailureEventReport_choice,
                                 NULL);

  return offset;
}


const value_string s1ap_SONtransferRequestContainer_vals[] = {
  {   0, "cellLoadReporting" },
  {   1, "multiCellLoadReporting" },
  {   2, "eventTriggeredCellLoadReporting" },
  {   3, "hOReporting" },
  {   4, "eutranCellActivation" },
  {   5, "energySavingsIndication" },
  {   6, "failureEventReporting" },
  { 0, NULL }
};

static const per_choice_t SONtransferRequestContainer_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_NULL },
  {   1,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_MultiCellLoadReportingRequest },
  {   2,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_EventTriggeredCellLoadReportingRequest },
  {   3,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_HOReport },
  {   4,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_CellActivationRequest },
  {   5,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_CellStateIndication },
  {   6,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_FailureEventReport },
  { 0, NULL, 0, NULL }
};

int
dissect_s1ap_SONtransferRequestContainer(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_SONtransferRequestContainer, SONtransferRequestContainer_choice,
                                 NULL);

  return offset;
}



static int
dissect_s1ap_CompositeAvailableCapacityGroup(tvbuff_t *tvb, int offset) {
  offset = dissect_per_octet_string(tvb, offset, 
                                       NO_BOUND, NO_BOUND, FALSE, NULL);

  return offset;
}


static const per_sequence_t EUTRANcellLoadReportingResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CompositeAvailableCapacityGroup },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EUTRANcellLoadReportingResponse(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EUTRANcellLoadReportingResponse, EUTRANcellLoadReportingResponse_sequence);

  return offset;
}



static int
dissect_s1ap_EHRPDSectorCapacityClassValue(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            1U, 100U, NULL, TRUE);

  return offset;
}



static int
dissect_s1ap_EHRPDCapacityValue(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_integer(tvb, offset, 
                                                            0U, 100U, NULL, FALSE);

  return offset;
}


static const per_sequence_t EHRPDCompositeAvailableCapacity_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EHRPDSectorCapacityClassValue },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EHRPDCapacityValue },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EHRPDCompositeAvailableCapacity(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EHRPDCompositeAvailableCapacity, EHRPDCompositeAvailableCapacity_sequence);

  return offset;
}


static const per_sequence_t EHRPDSectorLoadReportingResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EHRPDCompositeAvailableCapacity },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EHRPDCompositeAvailableCapacity },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EHRPDSectorLoadReportingResponse(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EHRPDSectorLoadReportingResponse, EHRPDSectorLoadReportingResponse_sequence);

  return offset;
}


static const value_string s1ap_CellLoadReportingResponse_vals[] = {
  {   0, "eUTRAN" },
  {   1, "uTRAN" },
  {   2, "gERAN" },
  {   3, "eHRPD" },
  { 0, NULL }
};

static const per_choice_t CellLoadReportingResponse_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_EUTRANcellLoadReportingResponse },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_OCTET_STRING },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_OCTET_STRING },
  {   3,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_EHRPDSectorLoadReportingResponse },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_CellLoadReportingResponse(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_CellLoadReportingResponse, CellLoadReportingResponse_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t EUTRANResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_OCTET_STRING },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EUTRANcellLoadReportingResponse },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EUTRANResponse(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EUTRANResponse, EUTRANResponse_sequence);

  return offset;
}


static const per_sequence_t EHRPDMultiSectorLoadReportingResponseItem_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EHRPD_Sector_ID },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_EHRPDSectorLoadReportingResponse },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EHRPDMultiSectorLoadReportingResponseItem(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EHRPDMultiSectorLoadReportingResponseItem, EHRPDMultiSectorLoadReportingResponseItem_sequence);

  return offset;
}


static const value_string s1ap_MultiCellLoadReportingResponse_Item_vals[] = {
  {   0, "eUTRANResponse" },
  {   1, "uTRANResponse" },
  {   2, "gERANResponse" },
  {   3, "eHRPD" },
  { 0, NULL }
};

static const per_choice_t MultiCellLoadReportingResponse_Item_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_EUTRANResponse },
  {   1,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_OCTET_STRING },
  {   2,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_OCTET_STRING },
  {   3,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_EHRPDMultiSectorLoadReportingResponseItem },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_MultiCellLoadReportingResponse_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_MultiCellLoadReportingResponse_Item, MultiCellLoadReportingResponse_Item_choice,
                                 NULL);

  return offset;
}


static const per_sequence_t MultiCellLoadReportingResponse_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_MultiCellLoadReportingResponse_Item },
};

static int
dissect_s1ap_MultiCellLoadReportingResponse(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_MultiCellLoadReportingResponse, MultiCellLoadReportingResponse_sequence_of,
                                                  1, maxnoofIRATReportingCells, FALSE);

  return offset;
}


static const value_string s1ap_OverloadFlag_vals[] = {
  {   0, "overload" },
  { 0, NULL }
};


static int
dissect_s1ap_OverloadFlag(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 1, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const per_sequence_t EventTriggeredCellLoadReportingResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_CellLoadReportingResponse },
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_OPTIONAL    , dissect_s1ap_OverloadFlag },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_EventTriggeredCellLoadReportingResponse(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_EventTriggeredCellLoadReportingResponse, EventTriggeredCellLoadReportingResponse_sequence);

  return offset;
}


static const per_sequence_t ActivatedCellsList_Item_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_OCTET_STRING },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_ActivatedCellsList_Item(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_ActivatedCellsList_Item, ActivatedCellsList_Item_sequence);

  return offset;
}


static const per_sequence_t ActivatedCellsList_sequence_of[1] = {
  {&unused_p_id ASN1_NO_EXTENSIONS     , ASN1_NOT_OPTIONAL, dissect_s1ap_ActivatedCellsList_Item },
};

static int
dissect_s1ap_ActivatedCellsList(tvbuff_t *tvb, int offset) {
  offset = dissect_per_constrained_sequence_of(tvb, offset, 
                                                  ett_s1ap_ActivatedCellsList, ActivatedCellsList_sequence_of,
                                                  0, maxnoofCellineNB, FALSE);

  return offset;
}


static const per_sequence_t CellActivationResponse_sequence[] = {
  {&unused_p_id ASN1_EXTENSION_ROOT    , ASN1_NOT_OPTIONAL, dissect_s1ap_ActivatedCellsList },
  { NULL, 0, 0, NULL }
};

static int
dissect_s1ap_CellActivationResponse(tvbuff_t *tvb, int offset) {
  offset = dissect_per_sequence(tvb, offset, 
                                   ett_s1ap_CellActivationResponse, CellActivationResponse_sequence);

  return offset;
}


const value_string s1ap_SONtransferResponseContainer_vals[] = {
  {   0, "cellLoadReporting" },
  {   1, "multiCellLoadReporting" },
  {   2, "eventTriggeredCellLoadReporting" },
  {   3, "hOReporting" },
  {   4, "eutranCellActivation" },
  {   5, "energySavingsIndication" },
  {   6, "failureEventReporting" },
  { 0, NULL }
};

static const per_choice_t SONtransferResponseContainer_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CellLoadReportingResponse },
  {   1,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_MultiCellLoadReportingResponse },
  {   2,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_EventTriggeredCellLoadReportingResponse },
  {   3,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_NULL },
  {   4,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_CellActivationResponse },
  {   5,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_NULL },
  {   6,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_NULL },
  { 0, NULL, 0, NULL }
};

int
dissect_s1ap_SONtransferResponseContainer(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_SONtransferResponseContainer, SONtransferResponseContainer_choice,
                                 NULL);

  return offset;
}


static const value_string s1ap_CellLoadReportingCause_vals[] = {
  {   0, "application-container-syntax-error" },
  {   1, "inconsistent-reporting-cell-identifier" },
  {   2, "unspecified" },
  { 0, NULL }
};


static int
dissect_s1ap_CellLoadReportingCause(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_HOReportingCause_vals[] = {
  {   0, "application-container-syntax-error" },
  {   1, "inconsistent-reporting-cell-identifier" },
  {   2, "unspecified" },
  { 0, NULL }
};


static int
dissect_s1ap_HOReportingCause(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_CellActivationCause_vals[] = {
  {   0, "application-container-syntax-error" },
  {   1, "inconsistent-reporting-cell-identifier" },
  {   2, "unspecified" },
  { 0, NULL }
};


static int
dissect_s1ap_CellActivationCause(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_CellStateIndicationCause_vals[] = {
  {   0, "application-container-syntax-error" },
  {   1, "inconsistent-reporting-cell-identifier" },
  {   2, "unspecified" },
  { 0, NULL }
};


static int
dissect_s1ap_CellStateIndicationCause(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_FailureEventReportingCause_vals[] = {
  {   0, "application-container-syntax-error" },
  {   1, "inconsistent-reporting-cell-identifier" },
  {   2, "unspecified" },
  { 0, NULL }
};


static int
dissect_s1ap_FailureEventReportingCause(tvbuff_t *tvb, int offset) {
  offset = dissect_per_enumerated(tvb, offset, 3, NULL, TRUE, 0, NULL, 1);

  return offset;
}


static const value_string s1ap_SONtransferCause_vals[] = {
  {   0, "cellLoadReporting" },
  {   1, "multiCellLoadReporting" },
  {   2, "eventTriggeredCellLoadReporting" },
  {   3, "hOReporting" },
  {   4, "eutranCellActivation" },
  {   5, "energySavingsIndication" },
  {   6, "failureEventReporting" },
  { 0, NULL }
};

static const per_choice_t SONtransferCause_choice[] = {
  {   0,&unused_p_id ASN1_EXTENSION_ROOT    , dissect_s1ap_CellLoadReportingCause },
  {   1,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_CellLoadReportingCause },
  {   2,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_CellLoadReportingCause },
  {   3,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_HOReportingCause },
  {   4,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_CellActivationCause },
  {   5,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_CellStateIndicationCause },
  {   6,&unused_p_id ASN1_NOT_EXTENSION_ROOT, dissect_s1ap_FailureEventReportingCause },
  { 0, NULL, 0, NULL }
};

static int
dissect_s1ap_SONtransferCause(tvbuff_t *tvb, int offset) {
  offset = dissect_per_choice(tvb, offset, 
                                 ett_s1ap_SONtransferCause, SONtransferCause_choice,
                                 NULL);

  return offset;
}



/*--- PDUs ---*/

static int dissect_Additional_GUTI_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Additional_GUTI(tvb, offset, &asn1_ctx, tree, hf_s1ap_Additional_GUTI_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_AdditionalRRMPriorityIndex_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_AdditionalRRMPriorityIndex(tvb, offset, &asn1_ctx, tree, hf_s1ap_AdditionalRRMPriorityIndex_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_AerialUEsubscriptionInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_AerialUEsubscriptionInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_AerialUEsubscriptionInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_AssistanceDataForPaging_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_AssistanceDataForPaging(tvb, offset, &asn1_ctx, tree, hf_s1ap_AssistanceDataForPaging_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Bearers_SubjectToStatusTransfer_Item_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Bearers_SubjectToStatusTransfer_Item(tvb, offset, &asn1_ctx, tree, hf_s1ap_Bearers_SubjectToStatusTransfer_Item_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Bearers_SubjectToEarlyStatusTransfer_Item_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Bearers_SubjectToEarlyStatusTransfer_Item(tvb, offset, &asn1_ctx, tree, hf_s1ap_Bearers_SubjectToEarlyStatusTransfer_Item_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_BearerType_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_BearerType(tvb, offset, &asn1_ctx, tree, hf_s1ap_BearerType_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_BluetoothMeasurementConfiguration_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_BluetoothMeasurementConfiguration(tvb, offset, &asn1_ctx, tree, hf_s1ap_BluetoothMeasurementConfiguration_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_BroadcastCancelledAreaList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_BroadcastCancelledAreaList(tvb, offset, &asn1_ctx, tree, hf_s1ap_BroadcastCancelledAreaList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_BroadcastCompletedAreaList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_BroadcastCompletedAreaList(tvb, offset, &asn1_ctx, tree, hf_s1ap_BroadcastCompletedAreaList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Cause_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Cause(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cause_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CellAccessMode_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CellAccessMode(tvb, offset, &asn1_ctx, tree, hf_s1ap_CellAccessMode_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CellIdentifierAndCELevelForCECapableUEs_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CellIdentifierAndCELevelForCECapableUEs(tvb, offset, &asn1_ctx, tree, hf_s1ap_CellIdentifierAndCELevelForCECapableUEs_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CE_mode_B_SupportIndicator_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CE_mode_B_SupportIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_CE_mode_B_SupportIndicator_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Cdma2000PDU_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Cdma2000PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000PDU_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Cdma2000RATType_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Cdma2000RATType(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000RATType_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Cdma2000SectorID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Cdma2000SectorID(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000SectorID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Cdma2000HOStatus_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Cdma2000HOStatus(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000HOStatus_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Cdma2000HORequiredIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Cdma2000HORequiredIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000HORequiredIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Cdma2000OneXSRVCCInfo_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Cdma2000OneXSRVCCInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000OneXSRVCCInfo_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Cdma2000OneXRAND_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Cdma2000OneXRAND(tvb, offset, &asn1_ctx, tree, hf_s1ap_Cdma2000OneXRAND_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CNDomain_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CNDomain(tvb, offset, &asn1_ctx, tree, hf_s1ap_CNDomain_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CNTypeRestrictions_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CNTypeRestrictions(tvb, offset, &asn1_ctx, tree, hf_s1ap_CNTypeRestrictions_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ConcurrentWarningMessageIndicator_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ConcurrentWarningMessageIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_ConcurrentWarningMessageIndicator_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ConnectedengNBList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ConnectedengNBList(tvb, offset, &asn1_ctx, tree, hf_s1ap_ConnectedengNBList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ContextatSource_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ContextatSource(tvb, offset, &asn1_ctx, tree, hf_s1ap_ContextatSource_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Correlation_ID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Correlation_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_Correlation_ID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CSFallbackIndicator_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CSFallbackIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSFallbackIndicator_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_AdditionalCSFallbackIndicator_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_AdditionalCSFallbackIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_AdditionalCSFallbackIndicator_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CSG_Id_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CSG_Id(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSG_Id_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CSG_IdList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CSG_IdList(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSG_IdList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CSGMembershipStatus_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CSGMembershipStatus(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSGMembershipStatus_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_COUNTValueExtended_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_COUNTValueExtended(tvb, offset, &asn1_ctx, tree, hf_s1ap_COUNTValueExtended_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_COUNTvaluePDCP_SNlength18_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_COUNTvaluePDCP_SNlength18(tvb, offset, &asn1_ctx, tree, hf_s1ap_COUNTvaluePDCP_SNlength18_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Coverage_Level_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Coverage_Level(tvb, offset, &asn1_ctx, tree, hf_s1ap_Coverage_Level_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CriticalityDiagnostics_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CriticalityDiagnostics(tvb, offset, &asn1_ctx, tree, hf_s1ap_CriticalityDiagnostics_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DAPSRequestInfo_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DAPSRequestInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_DAPSRequestInfo_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DAPSResponseInfoList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DAPSResponseInfoList(tvb, offset, &asn1_ctx, tree, hf_s1ap_DAPSResponseInfoList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DAPSResponseInfoItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DAPSResponseInfoItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_DAPSResponseInfoItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DataCodingScheme_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DataCodingScheme(tvb, offset, &asn1_ctx, tree, hf_s1ap_DataCodingScheme_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DataSize_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DataSize(tvb, offset, &asn1_ctx, tree, hf_s1ap_DataSize_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DCN_ID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DCN_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_DCN_ID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ServedDCNs_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ServedDCNs(tvb, offset, &asn1_ctx, tree, hf_s1ap_ServedDCNs_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DL_CP_SecurityInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DL_CP_SecurityInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_DL_CP_SecurityInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Direct_Forwarding_Path_Availability_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Direct_Forwarding_Path_Availability(tvb, offset, &asn1_ctx, tree, hf_s1ap_Direct_Forwarding_Path_Availability_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Data_Forwarding_Not_Possible_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Data_Forwarding_Not_Possible(tvb, offset, &asn1_ctx, tree, hf_s1ap_Data_Forwarding_Not_Possible_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DLNASPDUDeliveryAckRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DLNASPDUDeliveryAckRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_DLNASPDUDeliveryAckRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PWSfailedECGIList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PWSfailedECGIList(tvb, offset, &asn1_ctx, tree, hf_s1ap_PWSfailedECGIList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_EDT_Session_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_EDT_Session(tvb, offset, &asn1_ctx, tree, hf_s1ap_EDT_Session_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_EmergencyAreaIDListForRestart_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_EmergencyAreaIDListForRestart(tvb, offset, &asn1_ctx, tree, hf_s1ap_EmergencyAreaIDListForRestart_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENB_EarlyStatusTransfer_TransparentContainer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENB_EarlyStatusTransfer_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENB_EarlyStatusTransfer_TransparentContainer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_Global_ENB_ID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Global_ENB_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_Global_ENB_ID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_GUMMEIList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_GUMMEIList(tvb, offset, &asn1_ctx, tree, hf_s1ap_GUMMEIList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_ENB_StatusTransfer_TransparentContainer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENB_StatusTransfer_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_ENB_StatusTransfer_TransparentContainer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENB_UE_S1AP_ID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENB_UE_S1AP_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENB_UE_S1AP_ID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBname_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBname(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBname_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_EN_DCSONConfigurationTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_EN_DCSONConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_EN_DCSONConfigurationTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_EndIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_EndIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_EndIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_EnhancedCoverageRestricted_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_EnhancedCoverageRestricted(tvb, offset, &asn1_ctx, tree, hf_s1ap_EnhancedCoverageRestricted_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CE_ModeBRestricted_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CE_ModeBRestricted(tvb, offset, &asn1_ctx, tree, hf_s1ap_CE_ModeBRestricted_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABInformationListItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABInformationListItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABInformationListItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABLevelQoSParameters_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABLevelQoSParameters(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABLevelQoSParameters_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABUsageReportItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABUsageReportItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABUsageReportItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Ethernet_Type_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Ethernet_Type(tvb, offset, &asn1_ctx, tree, hf_s1ap_Ethernet_Type_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_EUTRAN_CGI_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_EUTRAN_CGI(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_EUTRAN_CGI_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_EUTRANRoundTripDelayEstimationInfo_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_EUTRANRoundTripDelayEstimationInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_EUTRANRoundTripDelayEstimationInfo_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ExpectedUEBehaviour_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ExpectedUEBehaviour(tvb, offset, &asn1_ctx, tree, hf_s1ap_ExpectedUEBehaviour_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ExtendedBitRate_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ExtendedBitRate(tvb, offset, &asn1_ctx, tree, hf_s1ap_ExtendedBitRate_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ExtendedRepetitionPeriod_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ExtendedRepetitionPeriod(tvb, offset, &asn1_ctx, tree, hf_s1ap_ExtendedRepetitionPeriod_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Extended_UEIdentityIndexValue_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Extended_UEIdentityIndexValue(tvb, offset, &asn1_ctx, tree, hf_s1ap_Extended_UEIdentityIndexValue_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_GUMMEI_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_GUMMEI(tvb, offset, &asn1_ctx, tree, hf_s1ap_GUMMEI_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_GUMMEIType_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_GUMMEIType(tvb, offset, &asn1_ctx, tree, hf_s1ap_GUMMEIType_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_GWContextReleaseIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_GWContextReleaseIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_GWContextReleaseIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverFlag_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverFlag(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverFlag_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_HandoverRestrictionList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverRestrictionList(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_HandoverRestrictionList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverType_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverType(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverType_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Masked_IMEISV_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Masked_IMEISV(tvb, offset, &asn1_ctx, tree, hf_s1ap_Masked_IMEISV_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_ImmediateMDT_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ImmediateMDT(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_ImmediateMDT_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_InformationOnRecommendedCellsAndENBsForPaging_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_InformationOnRecommendedCellsAndENBsForPaging(tvb, offset, &asn1_ctx, tree, hf_s1ap_InformationOnRecommendedCellsAndENBsForPaging_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_IntersystemMeasurementConfiguration_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_IntersystemMeasurementConfiguration(tvb, offset, &asn1_ctx, tree, hf_s1ap_IntersystemMeasurementConfiguration_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_IntersystemSONConfigurationTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_IntersystemSONConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_IntersystemSONConfigurationTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_IMSvoiceEPSfallbackfrom5G_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_IMSvoiceEPSfallbackfrom5G(tvb, offset, &asn1_ctx, tree, hf_s1ap_IMSvoiceEPSfallbackfrom5G_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_IAB_Authorized_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_IAB_Authorized(tvb, offset, &asn1_ctx, tree, hf_s1ap_IAB_Authorized_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_IAB_Node_Indication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_IAB_Node_Indication(tvb, offset, &asn1_ctx, tree, hf_s1ap_IAB_Node_Indication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_IAB_Supported_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_IAB_Supported(tvb, offset, &asn1_ctx, tree, hf_s1ap_IAB_Supported_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_KillAllWarningMessages_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_KillAllWarningMessages(tvb, offset, &asn1_ctx, tree, hf_s1ap_KillAllWarningMessages_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_LAI_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_LAI(tvb, offset, &asn1_ctx, tree, hf_s1ap_LAI_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_LastVisitedEUTRANCellInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_LastVisitedEUTRANCellInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_LastVisitedEUTRANCellInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_LastVisitedGERANCellInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_LastVisitedGERANCellInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_LastVisitedGERANCellInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_LPPa_PDU_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_LPPa_PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_LPPa_PDU_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_LHN_ID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_LHN_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_LHN_ID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_LoggedMBSFNMDT_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_LoggedMBSFNMDT(tvb, offset, &asn1_ctx, tree, hf_s1ap_LoggedMBSFNMDT_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_LTE_M_Indication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_LTE_M_Indication(tvb, offset, &asn1_ctx, tree, hf_s1ap_LTE_M_Indication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_M3Configuration_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_M3Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M3Configuration_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_M4Configuration_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_M4Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M4Configuration_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_M5Configuration_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_M5Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M5Configuration_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_M6Configuration_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_M6Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M6Configuration_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_M7Configuration_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_M7Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_M7Configuration_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MDT_Location_Info_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MDT_Location_Info(tvb, offset, &asn1_ctx, tree, hf_s1ap_MDT_Location_Info_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MDT_Configuration_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MDT_Configuration(tvb, offset, &asn1_ctx, tree, hf_s1ap_MDT_Configuration_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ManagementBasedMDTAllowed_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ManagementBasedMDTAllowed(tvb, offset, &asn1_ctx, tree, hf_s1ap_ManagementBasedMDTAllowed_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MDTPLMNList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MDTPLMNList(tvb, offset, &asn1_ctx, tree, hf_s1ap_MDTPLMNList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PrivacyIndicator_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PrivacyIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_PrivacyIndicator_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_MDTMode_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MDTMode(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_MDTMode_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MessageIdentifier_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MessageIdentifier(tvb, offset, &asn1_ctx, tree, hf_s1ap_MessageIdentifier_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MobilityInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MobilityInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_MobilityInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MMEname_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MMEname(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEname_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MMERelaySupportIndicator_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MMERelaySupportIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMERelaySupportIndicator_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MME_Group_ID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MME_Group_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_MME_Group_ID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MME_UE_S1AP_ID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MME_UE_S1AP_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_MME_UE_S1AP_ID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MSClassmark2_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MSClassmark2(tvb, offset, &asn1_ctx, tree, hf_s1ap_MSClassmark2_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MSClassmark3_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MSClassmark3(tvb, offset, &asn1_ctx, tree, hf_s1ap_MSClassmark3_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MutingAvailabilityIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MutingAvailabilityIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_MutingAvailabilityIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MutingPatternInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MutingPatternInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_MutingPatternInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MDT_ConfigurationNR_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MDT_ConfigurationNR(tvb, offset, &asn1_ctx, tree, hf_s1ap_MDT_ConfigurationNR_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NAS_PDU_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NAS_PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_NAS_PDU_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NASSecurityParametersfromE_UTRAN_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NASSecurityParametersfromE_UTRAN(tvb, offset, &asn1_ctx, tree, hf_s1ap_NASSecurityParametersfromE_UTRAN_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NASSecurityParameterstoE_UTRAN_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NASSecurityParameterstoE_UTRAN(tvb, offset, &asn1_ctx, tree, hf_s1ap_NASSecurityParameterstoE_UTRAN_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NB_IoT_DefaultPagingDRX_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NB_IoT_DefaultPagingDRX(tvb, offset, &asn1_ctx, tree, hf_s1ap_NB_IoT_DefaultPagingDRX_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NB_IoT_PagingDRX_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NB_IoT_PagingDRX(tvb, offset, &asn1_ctx, tree, hf_s1ap_NB_IoT_PagingDRX_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NB_IoT_Paging_eDRXInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NB_IoT_Paging_eDRXInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_NB_IoT_Paging_eDRXInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NB_IoT_RLF_Report_Container_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NB_IoT_RLF_Report_Container(tvb, offset, &asn1_ctx, tree, hf_s1ap_NB_IoT_RLF_Report_Container_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NB_IoT_UEIdentityIndexValue_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NB_IoT_UEIdentityIndexValue(tvb, offset, &asn1_ctx, tree, hf_s1ap_NB_IoT_UEIdentityIndexValue_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NotifySourceeNB_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NotifySourceeNB(tvb, offset, &asn1_ctx, tree, hf_s1ap_NotifySourceeNB_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NRrestrictioninEPSasSecondaryRAT_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NRrestrictioninEPSasSecondaryRAT(tvb, offset, &asn1_ctx, tree, hf_s1ap_NRrestrictioninEPSasSecondaryRAT_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NRrestrictionin5GS_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NRrestrictionin5GS(tvb, offset, &asn1_ctx, tree, hf_s1ap_NRrestrictionin5GS_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NRUESecurityCapabilities_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NRUESecurityCapabilities(tvb, offset, &asn1_ctx, tree, hf_s1ap_NRUESecurityCapabilities_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NumberofBroadcastRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NumberofBroadcastRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_NumberofBroadcastRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NRV2XServicesAuthorized_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NRV2XServicesAuthorized(tvb, offset, &asn1_ctx, tree, hf_s1ap_NRV2XServicesAuthorized_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NRUESidelinkAggregateMaximumBitrate_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NRUESidelinkAggregateMaximumBitrate(tvb, offset, &asn1_ctx, tree, hf_s1ap_NRUESidelinkAggregateMaximumBitrate_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_OverloadResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_OverloadResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_OverloadResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Packet_LossRate_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Packet_LossRate(tvb, offset, &asn1_ctx, tree, hf_s1ap_Packet_LossRate_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Paging_eDRXInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Paging_eDRXInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_Paging_eDRXInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PagingDRX_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PagingDRX(tvb, offset, &asn1_ctx, tree, hf_s1ap_PagingDRX_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PagingPriority_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PagingPriority(tvb, offset, &asn1_ctx, tree, hf_s1ap_PagingPriority_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PC5QoSParameters_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PC5QoSParameters(tvb, offset, &asn1_ctx, tree, hf_s1ap_PC5QoSParameters_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PendingDataIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PendingDataIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_PendingDataIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PLMNidentity_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PLMNidentity(tvb, offset, &asn1_ctx, tree, hf_s1ap_PLMNidentity_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ProSeAuthorized_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ProSeAuthorized(tvb, offset, &asn1_ctx, tree, hf_s1ap_ProSeAuthorized_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ProSeUEtoNetworkRelaying_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ProSeUEtoNetworkRelaying(tvb, offset, &asn1_ctx, tree, hf_s1ap_ProSeUEtoNetworkRelaying_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PS_ServiceNotAvailable_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PS_ServiceNotAvailable(tvb, offset, &asn1_ctx, tree, hf_s1ap_PS_ServiceNotAvailable_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PSCellInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PSCellInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_PSCellInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ReceiveStatusOfULPDCPSDUsExtended_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ReceiveStatusOfULPDCPSDUsExtended(tvb, offset, &asn1_ctx, tree, hf_s1ap_ReceiveStatusOfULPDCPSDUsExtended_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18(tvb, offset, &asn1_ctx, tree, hf_s1ap_ReceiveStatusOfULPDCPSDUsPDCP_SNlength18_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RecommendedCellItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RecommendedCellItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_RecommendedCellItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RecommendedENBItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RecommendedENBItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_RecommendedENBItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RelativeMMECapacity_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RelativeMMECapacity(tvb, offset, &asn1_ctx, tree, hf_s1ap_RelativeMMECapacity_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RelayNode_Indicator_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RelayNode_Indicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_RelayNode_Indicator_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RAT_Type_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RAT_Type(tvb, offset, &asn1_ctx, tree, hf_s1ap_RAT_Type_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RequestType_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RequestType(tvb, offset, &asn1_ctx, tree, hf_s1ap_RequestType_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RequestTypeAdditionalInfo_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RequestTypeAdditionalInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_RequestTypeAdditionalInfo_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RepetitionPeriod_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RepetitionPeriod(tvb, offset, &asn1_ctx, tree, hf_s1ap_RepetitionPeriod_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RRC_Establishment_Cause_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RRC_Establishment_Cause(tvb, offset, &asn1_ctx, tree, hf_s1ap_RRC_Establishment_Cause_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ECGIListForRestart_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ECGIListForRestart(tvb, offset, &asn1_ctx, tree, hf_s1ap_ECGIListForRestart_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Routing_ID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Routing_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_Routing_ID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SecurityKey_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SecurityKey(tvb, offset, &asn1_ctx, tree, hf_s1ap_SecurityKey_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SecurityContext_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SecurityContext(tvb, offset, &asn1_ctx, tree, hf_s1ap_SecurityContext_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SecondaryRATDataUsageRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SecondaryRATDataUsageRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_SecondaryRATDataUsageRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SecondaryRATDataUsageReportList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SecondaryRATDataUsageReportList(tvb, offset, &asn1_ctx, tree, hf_s1ap_SecondaryRATDataUsageReportList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SecondaryRATDataUsageReportItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SecondaryRATDataUsageReportItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_SecondaryRATDataUsageReportItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SerialNumber_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SerialNumber(tvb, offset, &asn1_ctx, tree, hf_s1ap_SerialNumber_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ServiceType_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ServiceType(tvb, offset, &asn1_ctx, tree, hf_s1ap_ServiceType_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SONInformationReport_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SONInformationReport(tvb, offset, &asn1_ctx, tree, hf_s1ap_SONInformationReport_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SONConfigurationTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SONConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_SONConfigurationTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SynchronisationInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SynchronisationInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_SynchronisationInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Source_ToTarget_TransparentContainer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Source_ToTarget_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_Source_ToTarget_TransparentContainer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SRVCCOperationNotPossible_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SRVCCOperationNotPossible(tvb, offset, &asn1_ctx, tree, hf_s1ap_SRVCCOperationNotPossible_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SRVCCOperationPossible_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SRVCCOperationPossible(tvb, offset, &asn1_ctx, tree, hf_s1ap_SRVCCOperationPossible_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SRVCCHOIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SRVCCHOIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_SRVCCHOIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SourceNodeID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SourceNodeID(tvb, offset, &asn1_ctx, tree, hf_s1ap_SourceNodeID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_SourceeNB_ToTargeteNB_TransparentContainer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SourceeNB_ToTargeteNB_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SourceeNB_ToTargeteNB_TransparentContainer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ServedGUMMEIs_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ServedGUMMEIs(tvb, offset, &asn1_ctx, tree, hf_s1ap_ServedGUMMEIs_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ServedPLMNs_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ServedPLMNs(tvb, offset, &asn1_ctx, tree, hf_s1ap_ServedPLMNs_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SubscriberProfileIDforRFP_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SubscriberProfileIDforRFP(tvb, offset, &asn1_ctx, tree, hf_s1ap_SubscriberProfileIDforRFP_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Subscription_Based_UE_DifferentiationInfo_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Subscription_Based_UE_DifferentiationInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_Subscription_Based_UE_DifferentiationInfo_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SupportedTAs_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SupportedTAs(tvb, offset, &asn1_ctx, tree, hf_s1ap_SupportedTAs_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TimeSynchronisationInfo_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TimeSynchronisationInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_TimeSynchronisationInfo_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_S_TMSI_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_S_TMSI(tvb, offset, &asn1_ctx, tree, hf_s1ap_S_TMSI_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TAI_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TAI(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAI_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TargetID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TargetID(tvb, offset, &asn1_ctx, tree, hf_s1ap_TargetID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_TargeteNB_ToSourceeNB_TransparentContainer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TargeteNB_ToSourceeNB_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_TargeteNB_ToSourceeNB_TransparentContainer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Target_ToSource_TransparentContainer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Target_ToSource_TransparentContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_Target_ToSource_TransparentContainer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TimeToWait_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TimeToWait(tvb, offset, &asn1_ctx, tree, hf_s1ap_TimeToWait_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Time_UE_StayedInCell_EnhancedGranularity_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Time_UE_StayedInCell_EnhancedGranularity(tvb, offset, &asn1_ctx, tree, hf_s1ap_Time_UE_StayedInCell_EnhancedGranularity_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TimeSinceSecondaryNodeRelease_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TimeSinceSecondaryNodeRelease(tvb, offset, &asn1_ctx, tree, hf_s1ap_TimeSinceSecondaryNodeRelease_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TransportInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TransportInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_TransportInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TransportLayerAddress_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TransportLayerAddress(tvb, offset, &asn1_ctx, tree, hf_s1ap_TransportLayerAddress_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TraceActivation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TraceActivation(tvb, offset, &asn1_ctx, tree, hf_s1ap_TraceActivation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_UTRAN_Trace_ID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_UTRAN_Trace_ID(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_UTRAN_Trace_ID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TrafficLoadReductionIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TrafficLoadReductionIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_TrafficLoadReductionIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TunnelInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TunnelInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_TunnelInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TAIListForRestart_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TAIListForRestart(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAIListForRestart_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEAggregateMaximumBitrate_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEAggregateMaximumBitrate(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEAggregateMaximumBitrate_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEAppLayerMeasConfig_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEAppLayerMeasConfig(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEAppLayerMeasConfig_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UECapabilityInfoRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UECapabilityInfoRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UECapabilityInfoRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UE_RetentionInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UE_RetentionInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_RetentionInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UE_S1AP_IDs_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UE_S1AP_IDs(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_S1AP_IDs_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UE_associatedLogicalS1_ConnectionItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UE_associatedLogicalS1_ConnectionItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_associatedLogicalS1_ConnectionItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEIdentityIndexValue_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEIdentityIndexValue(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEIdentityIndexValue_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_UE_HistoryInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UE_HistoryInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_UE_HistoryInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UE_HistoryInformationFromTheUE_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UE_HistoryInformationFromTheUE(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_HistoryInformationFromTheUE_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEPagingID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEPagingID(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEPagingID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UERadioCapability_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UERadioCapability(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapability_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UERadioCapabilityForPaging_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UERadioCapabilityForPaging(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityForPaging_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UERadioCapabilityID_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UERadioCapabilityID(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityID_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UESecurityCapabilities_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UESecurityCapabilities(tvb, offset, &asn1_ctx, tree, hf_s1ap_UESecurityCapabilities_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UESidelinkAggregateMaximumBitrate_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UESidelinkAggregateMaximumBitrate(tvb, offset, &asn1_ctx, tree, hf_s1ap_UESidelinkAggregateMaximumBitrate_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UE_Usage_Type_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UE_Usage_Type(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_Usage_Type_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UL_CP_SecurityInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UL_CP_SecurityInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_UL_CP_SecurityInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UnlicensedSpectrumRestriction_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UnlicensedSpectrumRestriction(tvb, offset, &asn1_ctx, tree, hf_s1ap_UnlicensedSpectrumRestriction_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UserLocationInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UserLocationInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_UserLocationInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEUserPlaneCIoTSupportIndicator_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEUserPlaneCIoTSupportIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEUserPlaneCIoTSupportIndicator_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UE_Application_Layer_Measurement_Capability_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UE_Application_Layer_Measurement_Capability(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_Application_Layer_Measurement_Capability_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_VoiceSupportMatchIndicator_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_VoiceSupportMatchIndicator(tvb, offset, &asn1_ctx, tree, hf_s1ap_VoiceSupportMatchIndicator_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_V2XServicesAuthorized_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_V2XServicesAuthorized(tvb, offset, &asn1_ctx, tree, hf_s1ap_V2XServicesAuthorized_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_WarningAreaCoordinates_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_WarningAreaCoordinates(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningAreaCoordinates_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_WarningAreaList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_WarningAreaList(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningAreaList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_WarningType_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_WarningType(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningType_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_WarningSecurityInfo_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_WarningSecurityInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningSecurityInfo_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_WarningMessageContents_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_WarningMessageContents(tvb, offset, &asn1_ctx, tree, hf_s1ap_WarningMessageContents_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_WLANMeasurementConfiguration_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_WLANMeasurementConfiguration(tvb, offset, &asn1_ctx, tree, hf_s1ap_WLANMeasurementConfiguration_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_WUS_Assistance_Information_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_WUS_Assistance_Information(tvb, offset, &asn1_ctx, tree, hf_s1ap_WUS_Assistance_Information_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_X2TNLConfigurationInfo_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_X2TNLConfigurationInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_X2TNLConfigurationInfo_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBX2ExtTLAs_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBX2ExtTLAs(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBX2ExtTLAs_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBIndirectX2TransportLayerAddresses_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBIndirectX2TransportLayerAddresses(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBIndirectX2TransportLayerAddresses_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverRequired_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverRequired(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRequired_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverCommand_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverCommand(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverCommand_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABSubjecttoDataForwardingList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABSubjecttoDataForwardingList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSubjecttoDataForwardingList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABDataForwardingItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABDataForwardingItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABDataForwardingItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverPreparationFailure_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverPreparationFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverPreparationFailure_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeSetupListHOReq_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeSetupListHOReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupListHOReq_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeSetupItemHOReq_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeSetupItemHOReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupItemHOReq_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverRequestAcknowledge_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverRequestAcknowledge_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABAdmittedList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABAdmittedList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABAdmittedList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABAdmittedItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABAdmittedItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABAdmittedItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABFailedtoSetupListHOReqAck_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABFailedtoSetupListHOReqAck(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedtoSetupListHOReqAck_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABFailedToSetupItemHOReqAck_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABFailedToSetupItemHOReqAck(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToSetupItemHOReqAck_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverFailure_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverFailure_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverNotify_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverNotify(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverNotify_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PathSwitchRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PathSwitchRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_PathSwitchRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeSwitchedDLList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeSwitchedDLList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedDLList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeSwitchedDLItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeSwitchedDLItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedDLItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PathSwitchRequestAcknowledge_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PathSwitchRequestAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_PathSwitchRequestAcknowledge_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeSwitchedULList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeSwitchedULList(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedULList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeSwitchedULItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeSwitchedULItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSwitchedULItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PathSwitchRequestFailure_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PathSwitchRequestFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_PathSwitchRequestFailure_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverCancel_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverCancel(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverCancel_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverCancelAcknowledge_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverCancelAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverCancelAcknowledge_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_HandoverSuccess_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_HandoverSuccess(tvb, offset, &asn1_ctx, tree, hf_s1ap_HandoverSuccess_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBEarlyStatusTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBEarlyStatusTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBEarlyStatusTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MMEEarlyStatusTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MMEEarlyStatusTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEEarlyStatusTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABSetupRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABSetupRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeSetupListBearerSUReq_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeSetupListBearerSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupListBearerSUReq_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeSetupItemBearerSUReq_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeSetupItemBearerSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupItemBearerSUReq_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABSetupResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABSetupResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABSetupListBearerSURes_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABSetupListBearerSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupListBearerSURes_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABSetupItemBearerSURes_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABSetupItemBearerSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupItemBearerSURes_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABModifyRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABModifyRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeModifiedListBearerModReq_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeModifiedListBearerModReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeModifiedListBearerModReq_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeModifiedItemBearerModReq_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeModifiedItemBearerModReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeModifiedItemBearerModReq_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABModifyResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABModifyResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABModifyListBearerModRes_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABModifyListBearerModRes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyListBearerModRes_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABModifyItemBearerModRes_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABModifyItemBearerModRes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyItemBearerModRes_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABReleaseCommand_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABReleaseCommand(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseCommand_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABReleaseResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABReleaseResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABReleaseListBearerRelComp_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABReleaseListBearerRelComp(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseListBearerRelComp_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABReleaseItemBearerRelComp_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABReleaseItemBearerRelComp(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseItemBearerRelComp_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABReleaseIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABReleaseIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABReleaseIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_InitialContextSetupRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_InitialContextSetupRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialContextSetupRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeSetupListCtxtSUReq_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeSetupListCtxtSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupListCtxtSUReq_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeSetupItemCtxtSUReq_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeSetupItemCtxtSUReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeSetupItemCtxtSUReq_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_InitialContextSetupResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_InitialContextSetupResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialContextSetupResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABSetupListCtxtSURes_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABSetupListCtxtSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupListCtxtSURes_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABSetupItemCtxtSURes_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABSetupItemCtxtSURes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABSetupItemCtxtSURes_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_InitialContextSetupFailure_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_InitialContextSetupFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialContextSetupFailure_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Paging_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Paging(tvb, offset, &asn1_ctx, tree, hf_s1ap_Paging_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TAIList_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TAIList(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAIList_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TAIItem_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TAIItem(tvb, offset, &asn1_ctx, tree, hf_s1ap_TAIItem_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextReleaseRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextReleaseRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextReleaseRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextReleaseCommand_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextReleaseCommand(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextReleaseCommand_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextReleaseComplete_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextReleaseComplete(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextReleaseComplete_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextModificationRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextModificationRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextModificationResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextModificationResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextModificationFailure_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextModificationFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationFailure_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UERadioCapabilityMatchRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UERadioCapabilityMatchRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityMatchRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UERadioCapabilityMatchResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UERadioCapabilityMatchResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityMatchResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DownlinkNASTransport_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DownlinkNASTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkNASTransport_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_InitialUEMessage_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_InitialUEMessage(tvb, offset, &asn1_ctx, tree, hf_s1ap_InitialUEMessage_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UplinkNASTransport_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UplinkNASTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkNASTransport_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NASNonDeliveryIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NASNonDeliveryIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_NASNonDeliveryIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RerouteNASRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RerouteNASRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_RerouteNASRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_S1_Message_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_S1_Message(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1_Message_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_NASDeliveryIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_NASDeliveryIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_NASDeliveryIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Reset_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Reset(tvb, offset, &asn1_ctx, tree, hf_s1ap_Reset_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ResetType_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ResetType(tvb, offset, &asn1_ctx, tree, hf_s1ap_ResetType_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ResetAcknowledge_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ResetAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_ResetAcknowledge_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UE_associatedLogicalS1_ConnectionListResAck_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UE_associatedLogicalS1_ConnectionListResAck(tvb, offset, &asn1_ctx, tree, hf_s1ap_UE_associatedLogicalS1_ConnectionListResAck_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ErrorIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ErrorIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_ErrorIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_S1SetupRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_S1SetupRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1SetupRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_S1SetupResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_S1SetupResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1SetupResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_S1SetupFailure_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_S1SetupFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1SetupFailure_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBConfigurationUpdate_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationUpdate_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationUpdateAcknowledge_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBConfigurationUpdateFailure_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationUpdateFailure_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MMEConfigurationUpdate_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MMEConfigurationUpdate(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationUpdate_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MMEConfigurationUpdateAcknowledge_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MMEConfigurationUpdateAcknowledge(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationUpdateAcknowledge_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MMEConfigurationUpdateFailure_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MMEConfigurationUpdateFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationUpdateFailure_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DownlinkS1cdma2000tunnelling_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DownlinkS1cdma2000tunnelling(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkS1cdma2000tunnelling_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UplinkS1cdma2000tunnelling_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UplinkS1cdma2000tunnelling(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkS1cdma2000tunnelling_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UECapabilityInfoIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UECapabilityInfoIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_UECapabilityInfoIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBStatusTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBStatusTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBStatusTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MMEStatusTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MMEStatusTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEStatusTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TraceStart_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TraceStart(tvb, offset, &asn1_ctx, tree, hf_s1ap_TraceStart_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_TraceFailureIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_TraceFailureIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_TraceFailureIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DeactivateTrace_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DeactivateTrace(tvb, offset, &asn1_ctx, tree, hf_s1ap_DeactivateTrace_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CellTrafficTrace_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CellTrafficTrace(tvb, offset, &asn1_ctx, tree, hf_s1ap_CellTrafficTrace_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_LocationReportingControl_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_LocationReportingControl(tvb, offset, &asn1_ctx, tree, hf_s1ap_LocationReportingControl_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_LocationReportingFailureIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_LocationReportingFailureIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_LocationReportingFailureIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_LocationReport_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_LocationReport(tvb, offset, &asn1_ctx, tree, hf_s1ap_LocationReport_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_OverloadStart_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_OverloadStart(tvb, offset, &asn1_ctx, tree, hf_s1ap_OverloadStart_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_OverloadStop_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_OverloadStop(tvb, offset, &asn1_ctx, tree, hf_s1ap_OverloadStop_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_WriteReplaceWarningRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_WriteReplaceWarningRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_WriteReplaceWarningRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_WriteReplaceWarningResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_WriteReplaceWarningResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_WriteReplaceWarningResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBDirectInformationTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBDirectInformationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBDirectInformationTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_Inter_SystemInformationTransferType_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_Inter_SystemInformationTransferType(tvb, offset, &asn1_ctx, tree, hf_s1ap_Inter_SystemInformationTransferType_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MMEDirectInformationTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MMEDirectInformationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEDirectInformationTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBConfigurationTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBConfigurationTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MMEConfigurationTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MMEConfigurationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMEConfigurationTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PrivateMessage_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PrivateMessage(tvb, offset, &asn1_ctx, tree, hf_s1ap_PrivateMessage_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_KillRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_KillRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_KillRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_KillResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_KillResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_KillResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PWSRestartIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PWSRestartIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_PWSRestartIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_PWSFailureIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_PWSFailureIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_PWSFailureIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DownlinkUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DownlinkUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkUEAssociatedLPPaTransport_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UplinkUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UplinkUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkUEAssociatedLPPaTransport_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_DownlinkNonUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_DownlinkNonUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_DownlinkNonUEAssociatedLPPaTransport_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UplinkNonUEAssociatedLPPaTransport_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UplinkNonUEAssociatedLPPaTransport(tvb, offset, &asn1_ctx, tree, hf_s1ap_UplinkNonUEAssociatedLPPaTransport_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABModificationIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABModificationIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModificationIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeModifiedListBearerModInd_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeModifiedListBearerModInd(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeModifiedListBearerModInd_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABToBeModifiedItemBearerModInd_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABToBeModifiedItemBearerModInd(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABToBeModifiedItemBearerModInd_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABNotToBeModifiedListBearerModInd_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABNotToBeModifiedListBearerModInd(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABNotToBeModifiedListBearerModInd_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABNotToBeModifiedItemBearerModInd_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABNotToBeModifiedItemBearerModInd(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABNotToBeModifiedItemBearerModInd_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_CSGMembershipInfo_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_CSGMembershipInfo(tvb, offset, &asn1_ctx, tree, hf_s1ap_CSGMembershipInfo_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABModificationConfirm_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABModificationConfirm(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModificationConfirm_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABModifyListBearerModConf_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABModifyListBearerModConf(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyListBearerModConf_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABModifyItemBearerModConf_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABModifyItemBearerModConf(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABModifyItemBearerModConf_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextModificationIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextModificationIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextModificationConfirm_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextModificationConfirm(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextModificationConfirm_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextSuspendRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextSuspendRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextSuspendRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextSuspendResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextSuspendResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextSuspendResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextResumeRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextResumeRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextResumeRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABFailedToResumeListResumeReq_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABFailedToResumeListResumeReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToResumeListResumeReq_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABFailedToResumeItemResumeReq_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABFailedToResumeItemResumeReq(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToResumeItemResumeReq_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextResumeResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextResumeResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextResumeResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABFailedToResumeListResumeRes_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABFailedToResumeListResumeRes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToResumeListResumeRes_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_E_RABFailedToResumeItemResumeRes_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_E_RABFailedToResumeItemResumeRes(tvb, offset, &asn1_ctx, tree, hf_s1ap_E_RABFailedToResumeItemResumeRes_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEContextResumeFailure_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEContextResumeFailure(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEContextResumeFailure_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ConnectionEstablishmentIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ConnectionEstablishmentIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_ConnectionEstablishmentIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_RetrieveUEInformation_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_RetrieveUEInformation(tvb, offset, &asn1_ctx, tree, hf_s1ap_RetrieveUEInformation_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UEInformationTransfer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UEInformationTransfer(tvb, offset, &asn1_ctx, tree, hf_s1ap_UEInformationTransfer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_ENBCPRelocationIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_ENBCPRelocationIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_ENBCPRelocationIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_MMECPRelocationIndication_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_MMECPRelocationIndication(tvb, offset, &asn1_ctx, tree, hf_s1ap_MMECPRelocationIndication_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_SecondaryRATDataUsageReport_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SecondaryRATDataUsageReport(tvb, offset, &asn1_ctx, tree, hf_s1ap_SecondaryRATDataUsageReport_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UERadioCapabilityIDMappingRequest_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UERadioCapabilityIDMappingRequest(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityIDMappingRequest_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_UERadioCapabilityIDMappingResponse_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_UERadioCapabilityIDMappingResponse(tvb, offset, &asn1_ctx, tree, hf_s1ap_UERadioCapabilityIDMappingResponse_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
static int dissect_S1AP_PDU_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_S1AP_PDU(tvb, offset, &asn1_ctx, tree, hf_s1ap_S1AP_PDU_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_SONtransferApplicationIdentity_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SONtransferApplicationIdentity(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferApplicationIdentity_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_SONtransferRequestContainer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SONtransferRequestContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferRequestContainer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_SONtransferResponseContainer_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SONtransferResponseContainer(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferResponseContainer_PDU);
  offset += 7; offset >>= 3;
  return offset;
}
int dissect_s1ap_SONtransferCause_PDU(tvbuff_t *tvb) {
  int offset = 0;
  offset = dissect_s1ap_SONtransferCause(tvb, offset, &asn1_ctx, tree, hf_s1ap_s1ap_SONtransferCause_PDU);
  offset += 7; offset >>= 3;
  return offset;
}