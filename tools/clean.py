# -*- encoding: utf-8 -*-
'''
@create_time: 2020/12/03 11:16:10
@author: lichunyu
'''


def clean_map(df, head:list=None, source:str='', target:str='', map_dict:dict=None, is_dict=False,
              inplace=True, other_replace:str='', other_replace_function=''):
    """
    df 替换
    @param other_replace_function: options(delete, replace) -delete : 没在map_dict/source & target中的则删除该行
                                    - replace: 需要other_replace参数, 没在map_dict/source & target中的则替换成other_replace
    """
    if not head:
        raise Exception('non head')
    if isinstance(head, str):
        head = [head]
    if not isinstance(head, list):
        raise Exception('head type error')
    if is_dict is False and map_dict:
        raise Exception('if wanna use param map_dict, please set is_dict to True')
    if inplace is not True:
        raise Exception('inplace还没开发')
    if is_dict is True and map_dict:
        for h in head:
            for s, t in map_dict:
                df.loc[df[h]==s] = t
    elif is_dict is False and source and target:
        for h in head:
            df.loc[df[h]==source] = target
    else:
        raise Exception('param error')


def generate_ngrams(text, n_gram=1, stop_words=None):
    token = [token for token in text.lower().split(' ') if token != '' if token not in stop_words]
    ngrams = zip(*[token[i:] for i in range(n_gram)])
    return [' '.join(ngram) for ngram in ngrams]